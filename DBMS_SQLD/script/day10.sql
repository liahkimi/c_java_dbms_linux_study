/*
 * TCL
 */

SELECT * FROM test1;

INSERT INTO test1
VALUES(100, 'Z');

-- 행 삽입 이전으로 돌아간다
ROLLBACK;

------------------------------------
INSERT INTO test1
VALUES(99, 'A');

INSERT INTO test1
VALUES(99, 'B');

SELECT * FROM test1;
-- 이전 COMMIT 지점까지 돌아간다
ROLLBACK;
------------------------------------

INSERT INTO test1
VALUES(1, '가');

SELECT * FROM test1;
COMMIT;
-- INSERT 쿼리를 COMMIT 하였으므로 ROLLBACK을 실행해도
-- 삽입전으로 돌아가지 않는다
ROLLBACK;

------------------------------------
----- 트랜잭션 시작
SELECT * FROM test1;

INSERT INTO test1
VALUES(1, '가');
----- 트랙잭션 끝
COMMIT;

---- 트랜잭션 시작
INSERT INTO test1
VALUES(78, 'Z');

DELETE FROM test1
WHERE col1 = 77;

SELECT * FROM test1;
ROLLBACK;
---- 트랜잭션 끝

-- 남아있는 데이터는 무엇일까?
SELECT * FROM test1;


/*
 * 여러가지 함수
 */

--	1. LOWER : 문자의 소문자 반환
--	2. UPPER : 문자의 대문자 반환
--	3. CONCAT : 문자1과 문자2를 연결한다(|| 연산자와 동일)
--	4. SUBSTR : 문자에서 M위치부터 N개의 문자길이만큼 자른다. N생략시 마지막문자까지
--	5. LENGTH : 문자의 글자 개수를 정수값으로 반환한다
--	6. TRIM : 문자의 왼쪽, 오른쪽 공백 제거

SELECT LOWER('APPLE'),
	UPPER('apple'),
	CONCAT('a', 'b'),
	SUBSTR('apple', 1, 3),
	LENGTH('apple'),
	TRIM('      apple       '),
	'      apple       '
FROM DUAL;

-- 숫자

--	1. ABS : 절대값
--	2. CEIL : 올림
--	3. FLOOR : 내림
--	4. ROUND : 반올림
--	5. TRUNC : 소수 m자리에서 잘라서 버림

SELECT ABS(-17),
	CEIL(0.3),
	FLOOR(2.7),
	ROUND(2.7),
	TRUNC(2.19, 1)
FROM DUAL;
	

-- 형변환 함수
SELECT TO_NUMBER('100')
FROM DUAL;

-- invalid number
--SELECT TO_NUMBER('가나다')
--FROM DUAL;

SELECT TO_CHAR(17.3),
	TO_CHAR(13),
	TO_CHAR(SYSDATE),
	TO_CHAR(SYSDATE, 'YYYY'),
	TO_CHAR(SYSDATE, 'YYYY-MM-DD'),
	TO_CHAR(SYSDATE, 'HH24-MI-SS'),
	TO_CHAR(SYSDATE, 'YYYY"년" MM"월" DD"일"')
FROM DUAL;

-- 숫자에 콤마 찍기
-- 형식 지정시 0 또는 9를 사용하며
-- 9를 쓰면 값이 없을 때 공백이 들어간다.
-- 0을 쓰면 0이 들어간다.
-- FM을 형식 가장 왼쪽에 넣어주면 불필요한 공백을 없애준다.
SELECT 
	TO_CHAR(123456789, '9,999,999,999,999,999'),
	TO_CHAR(123456789, '0,000,000,000,000,000' ),
	TO_CHAR(123456789, 'FM9,999,999,999,999,999'),
	TO_CHAR(123456789, '999,999')
FROM DUAL;

SELECT TO_DATE('2023', 'YYYY'),
	TO_DATE('01', 'MM'),
	TO_DATE('01', 'DD'),
	TO_DATE('2023-01-05', 'YYYY-MM-DD')	
FROM DUAL;

/*
 * 집합 연산자
 */

SELECT * FROM test1;
SELECT * FROM test2;

SELECT * 
FROM test1 INNER JOIN test2
ON test1.col1 = test2.col1;

-- UNION 중복 제거
SELECT *
FROM test1
UNION 
SELECT * 
FROM test2;

-- UNION ALL 중복 포함
SELECT *
FROM test1
UNION ALL
SELECT * 
FROM test2;

-- INTERSECT 교집합(중복제거)
SELECT *
FROM test1
INTERSECT 
SELECT *
FROM test2;

/*
 * 윈도우함수
 */

SELECT employee_id 
	,salary
	,department_id 
	,RANK () OVER (ORDER BY salary DESC) AS "전체 사원 급여 순위"
	,RANK () OVER (PARTITION BY department_id ORDER BY SALARY DESC) AS "부서 급여 순위"
FROM employees;

-- 145번 사원의 순위를 확인해보자
-- 전체 사원에서는 4위, 부서에서는 1위

-- 부서의 1위
SELECT employee_id, salary
FROM employees
WHERE department_id = 80
ORDER BY salary DESC;

-- 전체 사원의 4위
SELECT employee_id, salary
FROM employees 
ORDER BY salary DESC;

SELECT employee_id, 
	AVG(salary) OVER(PARTITION BY department_id) AS "부서 급여 평균",
	AVG(salary) OVER() AS "전체 급여 평균"
FROM employees;


/*
 * 계층형 쿼리
 * 순방향 : 부모 -> 자식. 부모부터 시작. 부모에 PRIOR. PRIOR PK = FK
 * 역방향 : 자식 -> 부모. 자식부터 시작. 자식에 PRIOR. PK = PRIOR FK
 * 
 * 자식의 매니저번호(FK)
 * 부모의 사원번호(PK)
 */


-- 순방향
-- 제일 직급이 높은 사원부터 낮은 사원순으로 이동(부모 -> 자식)
-- PRIOR PK : PRIOR 사원번호 

SELECT employee_id, manager_id
FROM employees
START WITH manager_id IS NULL -- MANAGER_ID가 NULL인 노드부터 시작(부모부터 시작)
CONNECT BY manager_id = PRIOR employee_id; -- 자식컬럼(manager_id) = PRIOR 부모컬럼(employee_id)

DROP TABLE db_com;

CREATE TABLE db_com(
	name VARCHAR2(1000) PRIMARY KEY					-- pk
	,manager VARCHAR2(1000) REFERENCES db_com(name)	-- fk
);


BEGIN 
INSERT INTO db_com
VALUES('부장', NULL);

INSERT INTO db_com
VALUES('차장1', '부장');

INSERT INTO db_com
VALUES('차장2', '부장');

INSERT INTO db_com
VALUES('과장1', '차장1');

INSERT INTO db_com
VALUES('과장2', '차장1');

INSERT INTO db_com
VALUES('과장3', '차장2');

INSERT INTO db_com
VALUES('대리1', '과장1');

INSERT INTO db_com
VALUES('대리2', '과장2');

INSERT INTO db_com
VALUES('대리3', '과장3');

INSERT INTO db_com
VALUES('대리4', '과장3');

INSERT INTO db_com
VALUES('사원1', '대리1');

INSERT INTO db_com
VALUES('사원2', '대리2');

INSERT INTO db_com
VALUES('사원3', '대리3');

INSERT INTO db_com
VALUES('사원4', '대리3');

INSERT INTO db_com
VALUES('사원5', '대리4');
END;

SELECT * FROM db_com;

-- 사원4의 담당 차장은 누구인가?
-- 사원부터 부장까지 -> 자식에서 부모까지(역방향) -> 자식(FK)에 PRIOR
SELECT name, manager
FROM db_com
START WITH name = '사원4' -- 사원4 노드부터 시작하여
CONNECT BY name = PRIOR manager; -- PRIOR FK -> 역방향

-- 부장부터 사원까지 -> 부모에서 자식까지(순방향) -> 부모(PK)에 PRIOR
SELECT lpad ('>>', LEVEL - 1, '>>') || name, manager
FROM db_com
START WITH manager IS NULL -- manager가 null인 노드부터 시작(부장부터 시작) -> 부모부터 시작
CONNECT BY manager = PRIOR name; -- PRIOR PK -> 순방향

-- LPAD()
-- LPAD(값, 총 문자길이, 채울 문자)
SELECT LPAD('A', 3, '*')
	,LPAD('A', 10, '*')
	,RPAD('A', 10, '*')
FROM dual;






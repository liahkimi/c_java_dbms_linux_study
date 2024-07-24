-- 단순 CASE와 NULL(NULL값을 확인하지 못함)
-- 단순 CASE 표현식은 기준 표현식과 조건값을 = 연산자를 통해 비교한다
SELECT employee_id, commission_pct
	,CASE commission_pct
		WHEN NULL THEN 'N'
		ELSE 'Y'
	END AS "커미션 존재 여부"
FROM employees;

-- 검색 CASE와 NULL
SELECT employee_id, commission_pct
	,CASE 
		WHEN commission_pct IS NULL THEN 'N'
		ELSE 'Y'
	END AS "커미션 존재 여부"
FROM employees;

-- 집계함수와 CASE
/*
 * 이름이 Peter, Michael, John인 사원의 수를 각각 구하기
 */

SELECT count(CASE first_name WHEN 'Peter' THEN first_name END) AS "Peter"
	,count(CASE first_name WHEN 'Michael' THEN first_name END) AS "Micheal"
	,count(CASE first_name WHEN 'John' THEN first_name END) AS "John"
FROM employees;

/*
 * 급여가 10000 초과이면 상위, 6000 ~ 10000 이면 중위, 6000 미만이면 하위로 등급을 매길때
 * 각 등급의 사원의 수를 구하기
 */

SELECT count(CASE WHEN salary > 10000 THEN salary end) AS 상위
	,count(CASE WHEN salary BETWEEN 6000 AND 10000 THEN salary end) AS 중위
	,count(CASE WHEN salary < 6000 THEN salary end) AS 하위
FROM employees;



/*
 * 조인
 */

-- test1 테이블 생성
CREATE TABLE test1(
	col1 number,
	col2 varchar2(1000)
);

-- test2 테이블 생성
CREATE TABLE test2( 
	col1 number,
	col3 varchar2(1000)
);


-- test1, test2 테이블에 데이터 삽입
BEGIN 

INSERT INTO test1
VALUES (1, 'A');

INSERT INTO test1
VALUES (2, 'B');

INSERT INTO test1
VALUES (3, 'C');

INSERT INTO test2
VALUES (1, '가');

INSERT INTO test2
VALUES (5, '나');

INSERT INTO test2
VALUES (1, '다');

END;

/* test1 테이블						test2 테이블
 * col1		col3					col1		col3
 * =============					================
 * 1		A						1			가
 * 2		B						5			나
 * 3		C						1			다
 */

SELECT * FROM test1;
SELECT * FROM test2;

/*
 * INNER JOIN
 * 등가 조인
 */

-- test1.col1의 값과 test2.col1의 값이 일치하는 행들을 연결한다
SELECT *
FROM test1
INNER JOIN test2
ON test1.col1 = test2.col1;

/*
 * INNER JOIN
 * 비등가 조인
 */

-- test1.col1의 값이 test2.col1의 값보다 큰 행들을 연결한다
SELECT * 
FROM test1 
INNER JOIN test2
ON test1.col1 > test2.col1;

-- test1.col1의 값이 test2.col1의 값보다 작은 행들을 연결한다
SELECT * 
FROM test1
INNER JOIN test2
ON test1.col1 < test2.col1;

/*
 * 내추럴 조인 
 * 조인의 조건을 기재하지 않아도 등가조인이 실행된다 
 * 동일한 이름을 갖는 모든컬럼들에 대해 등가 조인
 */

-- 내추럴 조인에서는 공통 컬럼은 별칭을 사용할수 없다
SELECT col1, col2, col3
FROM test1 NATURAL JOIN test2;

-- 등가조인에서는 공통 컬럼을 구분하기 위해 별칭을 사용
SELECT test1.col1, col2, col3
FROM test1 INNER JOIN test2
ON test1.col1 = test2.col1;


/*
 * LEFT OUTER JOIN
 * test1.col1 = test2.col1 의 조인조건을 만족하는 행들과
 * test1 테이블의 조인조건을 만족하지 않는 행들을 모두 가져온다
 * test1 테이블의 조인조건 만족하는 행 + test2 테이블의 조인조건 만족하는 행
 * test1 테이블의 조인조건 만족하지 않는 행 + test2 테이블의 null로 채워진 행
 */

SELECT *
FROM test1
LEFT OUTER JOIN test2
ON test1.col1 = test2.col1;

-- RIGHT OUTER JOIN 
SELECT * 
FROM test1
RIGHT OUTER JOIN test2
ON test1.col1 = test2.col1;

-- FULL OUTER JOIN
SELECT *
FROM test1 
FULL OUTER JOIN test2
ON test1.col1 = test2.col1;

-- CROSS JOIN
SELECT * 
FROM test1 
CROSS JOIN test2;

/*
 * 등가조인
 */

-- emp 테이블에서 사원번호로 dept 테이블의 지역검색
-- 조인을 사용할 때 테이블간 관계를 먼저 확인해야한다
SELECT * FROM employees;
SELECT * FROM departments;

-- 오라클 등가 조인
SELECT * 
FROM departments, employees
WHERE departments.department_id = employees.department_id;

-- 테이블명을 그대로 사용하면 너무 기니까 별칭을 이용
SELECT * 
FROM departments d, employees e
WHERE d.department_id = e.department_id;

-- department_id 컬럼은 두 테이블에도 모두 있기때문에 어떤 테이블인지 알려줘야 한다
-- first_name 컬럼은 employees 테이블에만 존재하므로 테이블 없이도 사용 가능
SELECT d.department_id, first_name 
FROM departments d, employees e
WHERE d.department_id = e.department_id;

-- 안시 등가 조인
SELECT * 
FROM departments d 
INNER JOIN employees e
ON d.department_id = e.employee_id;

-- INNER 키워드 생략 가능
SELECT * 
FROM departments d 
JOIN employees e
ON d.department_id = e.employee_id;

/* 
 * 실습.
 * 직원들의 부서명, 이름 조회하기
 */

SELECT d.department_name as 부서명, e.first_name AS 사원명
FROM departments d
JOIN employees e
ON d.department_id = e.department_id
ORDER BY d.department_name;

/*
 * 실습.
 * 급여가 10000 이상인 사원들의 부서명, 부서번호, 이름, 급여 출력하기
 */

SELECT d.department_id 
	,d.department_name
	,e.first_name
	,e.salary
FROM departments d
JOIN employees e
ON d.department_id = e.department_id
WHERE salary >= 10000
ORDER BY e.salary;


/*
 * 실습.
 * 부서번호, 부서명, 도시명, 상세주소 조회하기
 */

-- 부서번호, 부서명, 도시명, 상세 주소
SELECT d.department_id
	,d.department_name
	,l.city
	,l.street_address
FROM locations l
INNER JOIN departments d
ON l.location_id = d.location_id
ORDER BY d.department_id;

-- 지역번호당 부서가 몇개 존재하는지 조회
SELECT l.location_id, count(department_id)
FROM locations l
INNER JOIN departments d
ON l.location_id = d.location_id
GROUP BY l.location_id;

SELECT count(*) FROM departments  
WHERE location_id = 1700;


/*
 * 비등가 조인
 */

DROP TABLE salgrade;

-- 급여 등급 테이블 생성
CREATE TABLE salgrade(
	grade NUMBER
	,losal NUMBER
	,hisal number);

-- 급여 등급 테이블에 데이터 삽입 
BEGIN
INSERT INTO salgrade VALUES (1, 500, 3000);
INSERT INTO salgrade VALUES (2, 3001, 5000);
INSERT INTO salgrade VALUES (3, 5001, 7000);
INSERT INTO salgrade VALUES (4, 7001, 9000);
INSERT INTO salgrade VALUES (5, 9001, 20000);
END;

SELECT * FROM salgrade;

-- 사원들의 급여 등급 조회
-- s.losal <= e.salary <= s.hisal 조건을 만족하는 행들끼리 조인
SELECT e.employee_id, e.salary, s.grade 
FROM salgrade s JOIN employees e
ON e.salary BETWEEN s.losal AND s.hisal
ORDER BY s.grade;

-- 사원들의 급여 등급별 사원 수 조회
SELECT s.grade, count(*) AS "사원 수"
FROM salgrade s JOIN employees e 
ON e.salary BETWEEN s.losal AND s.hisal
GROUP BY s.grade;

-- 연도별 급여등급 별 입사자수 조회
SELECT extract(YEAR FROM e.hire_date) AS 입사연도 
	,s.grade AS "급여 등급"
	,count(*) AS 입사자수
FROM salgrade s JOIN employees e 
ON e.salary BETWEEN s.losal AND s.hisal
GROUP BY s.grade, extract(YEAR FROM e.hire_date)
ORDER BY 입사연도, "급여 등급";


/*
 * 내추럴 조인
 */

SELECT * 
FROM employees e NATURAL JOIN departments d;

-- department_id, manager_id 컬럼이 조인 조건으로 사용된다
-- 조인 컬럼은 1번씩만 표시한다
-- 조인 컬럼은 컬럼명만 기재 가능(d. 불가 departments. 불가)
SELECT department_id, manager_id, e.first_name, e.last_name
FROM departments d NATURAL JOIN employees e;

-- 불가  
--SELECT departments.department_id, manager_id, e.first_name, e.last_name
--FROM departments d NATURAL JOIN employees e;

-- 아래와 같은 결과
SELECT *
FROM departments d INNER JOIN employees e 
ON d.department_id = e.department_id AND d.manager_id = e.manager_id;

/*
 * USING(원하는 컬럼만 등가조인)
 * SELECT * 사용시 기준 컬럼이 먼저 출력된다
 * 같은 이름의 컬럼을 하나로 처리한다
 * 조인 컬럼에 별칭 사용 불가
 */

SELECT * 
FROM departments d JOIN employees e
USING(department_id);

SELECT e.employee_id, department_id, d.department_name
FROM departments d JOIN employees e
USING(department_id);


-- 여러개의 테이블 등가 조인
-- employees, departments, locations
-- 안시조인
SELECT *
FROM employees e JOIN departments d
ON e.department_id = d.department_id 
JOIN locations l ON l.location_id = d.location_id;

-- 오라클조인
SELECT *
FROM employees e, departments d, locations l
WHERE e.department_id = d.department_id AND d.location_id = l.location_id;

-- 지역별, 부서별, 사원의 수 조회하기
SELECT l.location_id, d.department_id, count(*)
FROM locations l JOIN departments d ON l.location_id = d.location_id
JOIN employees e ON d.department_id = e.department_id
GROUP BY l.location_id, d.department_id;


/*
 * LEFT OUTER 조인
 */

-- 안시
SELECT * 
FROM departments d -- 기준 테이블
LEFT OUTER JOIN employees e 
ON e.department_id = d.department_id;

-- 오라클 
-- (+) 연산자 반대편이 기준 테이블
SELECT * 
FROM departments d, employees e
WHERE d.department_id  = e.department_id(+);

-- 안시
SELECT * FROM locations l
LEFT OUTER JOIN departments d
ON l.location_id = d.location_id;

-- 오라클
SELECT * FROM locations l, departments d
WHERE l.location_id(+) = d.location_id;

/*
 * RIGHT OUTER 조인
 */

-- 안시
SELECT * FROM departments d  
RIGHT OUTER JOIN employees e -- 기준테이블
ON e.department_id = d.department_id;

-- 오라클
-- (+) 연산자 반대편이 기준 테이블
SELECT * FROM departments d, employees e
WHERE d.department_id(+) = e.department_id;

-- 안시
SELECT * FROM locations l
RIGHT OUTER JOIN departments d
ON l.location_id = d.location_id;

-- 오라클
SELECT * FROM locations l, departments d
WHERE l.location_id(+) = d.location_id;

/*
 * FULL OUTER 조인(LEFT + RIGHT OUTER JOIN 의 합집합)
 */

SELECT * FROM departments d
FULL OUTER JOIN employees e
ON d.department_id = e.department_id
ORDER BY d.department_id;

/*
 * CROSS 조인(카테시안의 곱)
 */

-- 110개
SELECT count(*) FROM employees;
-- 27개
SELECT count(*) FROM departments;

-- 2970(110 x 27) : 모든 경우의수
SELECT count(*)
FROM departments d CROSS JOIN employees e;

/*
 * 셀프조인
 */

SELECT e1.employee_id AS 사번, 
	e1.first_name AS "사원 이름", 
	e2.employee_id AS "매니저 사번",
	e2.first_name AS "매니저 이름"
FROM employees e1
JOIN employees e2 ON e2.employee_id = e1.manager_id;

-- 매니저보다 급여가 높은 사원의 사번, 사원급여, 매니저사번, 매니저 급여 조회
SELECT e1.employee_id AS 사번
	,e1.salary AS "사원 급여"
	,e2.employee_id AS "매니저 사번"
	,e2.salary AS "매니저 급여"
FROM employees e1
JOIN employees e2 ON e2.employee_id = e1.manager_id
WHERE e1.salary > e2.salary;





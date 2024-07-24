--주석 단축키 : ctrl + /,  스크립트 파일 만들기 : ctrl + ]

/*
 * 범위 주석 : ctrl + shift + /
 */

-- select : SQL문은(쿼리문) 대소문자를 구분하지 않는다
-- employees 테이블에서 모든 행의 employee_id 컬럼을 조회한다
SELECT employee_id FROM employees;
SELECT EMPLOYEE_ID FROM EMPLOYEES;

-- employees 테이블에서 모든 행의 salay 컬럼을 조회한다
SELECT salary FROM employees;

-- 컬럼을 작성한 순서대로 조회결과가 보여진다
SELECT employee_id, salary FROM employees;
SELECT salary, employee_id FROM employees;

-- 모든 컬럼을 조회할때는 *(애스터리스크)를 사용할수 있다
SELECT * FROM employees;

/*
 * DISTINCT : 중복되는 값을 제외하고 조회하기
 */

SELECT job_id FROM employees;

-- job_id 값이 중복되는 행들을 제외하고 조회한다
SELECT DISTINCT job_id FROM employees;

-- department_id 값이 중복되는 행들을 제외하고 조회한다
SELECT DISTINCT department_id FROM employees;

SELECT DISTINCT employee_id FROM employees;

-- 여러개의 컬럼명과 distinct 키워드 사용시
-- 여러개의 컬럼값이 모두 중복되어야 중복으로 판단한다
SELECT DISTINCT job_id, salary FROM employees;

SELECT DISTINCT department_id, job_id FROM employees;

-- 문법 오류!
--SELECT employee_id, DISTINCT job_id FROM employees;

/* 
 * Alias(별칭)
 */

SELECT first_name AS "이름", 
	last_name AS "성"
FROM employees;

SELECT first_name 이름,
	last_name 성
FROM employees;

SELECT employee_id 사원 번호
FROM employees;

-- 별칭에 특수문자, 공백을 넣고싶다면 "" 큰 따옴표 안에 작성한다
SELECT employee_id "사원 번호"
FROM employees;

-- 쉼표 개수에 주의해야 한다!
--SELECT employee_id, first_name,
--FROM employees;

SELECT employee_id first_name FROM employees;

-- 애스터리스크(*)와 일반 컬럼은 같이 사용할수 없다
--SELECT *, employee_id
--FROM employees;

-- 테이블에 별칭을 붙이면 애스터리스크와 일반컬럼을 같이 사용할수 있다
SELECT e.*, e.employee_id
FROM employees e;


SELECT * FROM employees;

/*
 * ORDER BY : 정렬 기준 컬럼을 통해 오름차순, 내림차순 정렬해서 조회하기
 */

-- ASC 키워드는 생략해도 기본정렬이므로 오름차순 정렬된다
-- salary 컬럼의 값을 기준으로 오름차순 정렬해서 조회하기
-- salary가 작은 값부터 큰값으로 정렬(오름차순)
SELECT first_name, salary 
FROM employees
ORDER BY salary;

-- salary가 높은 값에서 작은값 순서로 정렬(내림차순 정렬)
SELECT first_name, salary
FROM employees
ORDER BY salary DESC;

-- 문자 오름차순 정렬(알파벳 순서대로 A -> Z)
SELECT employee_id, first_name
FROM employees
ORDER BY first_name;

-- 문자 내림차순 정렬(알파벳 역순으로 Z -> A)
SELECT employee_id, first_name
FROM employees
ORDER BY first_name DESC;

-- 날짜 오름차순 정렬(현재를 기준으로 오래된 날짜부터)
SELECT hire_date 
FROM employees
ORDER BY hire_date ASC;

-- 날짜 내림차순 정렬(현재를 기준으로 최신 날짜부터)
SELECT hire_date
FROM employees
ORDER BY hire_date DESC;

-- ORDER BY에서 여러개의 컬럼을 사용할때
-- 이전 컬럼의 값이 중복일때 재정렬의 기준으로 다음컬럼을 사용한다
-- employees 테이블에서 department_id 오름차순, 
-- employee_id 오름차순으로 정렬해서 조회한다
-- 즉, 부서번호가 같은 사원들은 사원번호 오름차순으로 재정렬해서 조회
SELECT department_id, employee_id
FROM employees
ORDER BY department_id, employee_id;

-- 부서번호가 같은 사원들은 사원번호 내림차순으로 재정렬해서 조회
SELECT department_id, employee_id
FROM employees
ORDER BY department_id, employee_id DESC;

-- 정렬 기준 컬럼을 반드시 조회할 필요는 없다
-- salary를 오름차순 정렬해서 department_id 컬럼을 조회한다
SELECT department_id
FROM employees
ORDER BY salary;

-- 컬럼에 부여된 별칭은 order by에서 사용 가능하다
SELECT first_name AS "이름",
	salary AS "급여"
FROM employees
ORDER BY "급여" DESC;

-- 컬럼의 순서를 정렬 기준으로 사용하기
-- 모든 컬럼에서 2번째 있는 컬럼을 기준으로 오름차순 정렬하여 조회하기
SELECT * 
FROM employees
ORDER BY 2;

-- 조회하는 3개의 컬럼중에서 2번째 컬럼을 기준으로 오름차순 정렬하여 조회하기
SELECT employee_id, salary, department_id
FROM employees
ORDER BY 2;

-- 별칭과 컬럼 순서를 모두 정렬 기준으로 사용하기
-- department_id 오름차순으로 정렬하고, 같은 department_id는
-- 급여(salary) 내림차순으로 정렬하여 조회하기 
SELECT department_id, job_id, salary AS "급여"
FROM employees
ORDER BY 1, "급여" DESC;


/*
 * 자료형
 */

-- DUAL : 다른 테이블을 참조할 필요 없이 값을 확인할때 사용하는 가상테이블
-- 오라클에서 사용이 가능하다

-- 숫자
SELECT 10, 10.7 FROM dual;

-- 문자
-- 작은 따옴표 안에 작성하고 작은따옴표는 항상 짝(쌍)으로 작성한다
SELECT 'h', 'hello' FROM dual;

SELECT 1, '1' FROM dual;

-- 날짜
-- 문자로 인식한다
SELECT '2023-02-14' FROM dual;
-- 날짜로 인식한다(DATE)
SELECT DATE '2023-02-14' FROM dual;
-- 날짜로 인식한다(TIMESTAMP)
SELECT timestamp '2023-02-14 00:00:00' FROM dual;

-- SYSDATE : 현재 날짜와 시간을 가지고 오는 키워드 
SELECT sysdate FROM dual;

/*
 * 단항 연산자
 */

SELECT +salary AS "양수", -salary AS "음수", salary
FROM employees;


/*
 * 산술 연산자
 */

-- 숫자와 숫자
SELECT salary + 10 AS "덧셈",
	salary - 10 AS "뺄셈",
	salary * 10,
	salary / 10
FROM employees;

-- 문자와 숫자(오류 발생!)
--SELECT 'A' + 30 FROM dual;

-- 날짜와 숫자
-- 일 단위로 연산이 진행된다
SELECT sysdate AS "현재날짜",
	sysdate + 1, -- 1일후
	sysdate - 1 -- 1일전
FROM dual;

-- sysdate + 1(1일)
SELECT sysdate AS "현재날짜",
	sysdate - 0.5 AS "12시간 전",
	sysdate - 1/24 AS "1시간 전",
	sysdate - 30/60/24 AS "30분 전"
FROM dual;

-- 날짜와 날짜
-- 근속일수 구하기
SELECT employee_id,
	hire_date,
	sysdate - hire_date
FROM employees;

-- trunc() 함수 : 소수점 버림 함수
SELECT employee_id,
	trunc(sysdate - hire_date)
FROM employees;

/*
 * 실습1. 개똥이의 생년월일은 2010년 12월 31일 입니다
 * 개똥이는 현재 날짜를 기준으로 태어난지 몇일 되었을까요?(정수)
 */

/*
 * 실습2. 현재 날짜와 시간으로부터 1일전, 1시간전, 1분전, 1초전 구하기
 */

/*
 * 실습3. 현재 날짜를 기준으로 근속일수가 높은 사원순으로 정렬하여 조회하기
 * 만약 근속일수가 동일할 경우, 사원번호가 작은 사람부터 정렬한다
 */















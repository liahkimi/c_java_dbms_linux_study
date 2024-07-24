/*
 * 실습. 아래의 쿼리를 IN 연산자를 사용하여 수정하기
 */


-- employees 테이블의
-- department_id 가 80번이 아니다 그리고
-- department_id 가 50번이 아니다 그리고
-- department_id 가 90번이 아닌 사원들의 employee_id와 department_id 컬럼을 조회한다
-- 부서번호가 80번, 50번, 90번이 아닌 사원들의 정보를 조회하기
SELECT employee_id, department_id
FROM employees
WHERE department_id <> 80 AND department_id <> 50 AND department_id <> 90;

SELECT employee_id, department_id
FROM employees
WHERE department_id NOT IN (80, 50, 90);


/*
 * 실습. 
 * 90, 80, 50번 부서 사원중에서 급여가 6000 이상인 사원의 부서번호, 급여 조회하기
 * 급여가 높은 사원부터 정렬하기
 */

-- 90, 80, 50번 부서 사원만 조회하기
SELECT department_id, salary
FROM employees
WHERE department_id IN (90, 80, 50) AND salary >= 6000
ORDER BY 2 DESC;


/*
 * LIKE 연산자
 */

SELECT first_name
FROM employees
WHERE first_name = 'David';

-- first_name 이 M으로 시작하는 사원을 조회하기
SELECT first_name
FROM employees
WHERE first_name LIKE 'M%';

-- first_name 이 a로 끝나는 사원 조회하기
SELECT first_name
FROM employees
WHERE first_name LIKE '%a';

-- first_name이 Al으로 시작하는 사원 조회하기
SELECT first_name
FROM employees
WHERE first_name LIKE 'Al%';

-- first_name 중간에 ma가 들어가는 사원 조회하기
SELECT first_name
FROM employees
WHERE first_name LIKE '%ma%';

-- first_name 중간에 e, n 글자가 들어가는 사원 조회하기
SELECT first_name
FROM employees
WHERE first_name LIKE '%e%n%';

-- - : 자리지정(문자의 개수 지정)
SELECT first_name
FROM employees
WHERE first_name LIKE '_____';

-- first_name이 S로 시작하고 5글자인 사원 조회하기
SELECT first_name
FROM employees
WHERE first_name LIKE 'S____';

-- NOT LIKE
SELECT first_name
FROM employees
WHERE first_name NOT LIKE 'A%'
ORDER BY first_name;

/*
 * 실습. job_id가 CLERK로 끝나는 사원의 사원번호와 직무(job_id)조회하기
 */

SELECT employee_id, job_id
FROM employees
WHERE job_id LIKE '%CLERK';

/*
 * 실습. 이름이 S로 시작하고, 성은 B로 시작하는 4글자인 사원의
 * 이름과 성을 조회하기(이름은 글자수 상관없음)
 */

SELECT first_name, last_name
FROM employees
WHERE first_name LIKE 'S%' AND last_name LIKE 'B___';

/*
 * IS NULL, IS NOT NULL 연산자
 */

SELECT 1 + NULL, 1 * NULL, NULL / 3
FROM dual;

-- commission_pct : null값이 존재하는 컬럼(커미션 비율)
SELECT commission_pct
FROM employees;

-- NULL은 산술 연산의 결과가 NULL이다
SELECT commission_pct * 1000
FROM employees;

-- NULL은 날짜와 산술 연산해도 결과가 NULL이다
SELECT hire_date + NULL
FROM employees;

-- 오라클은 '' 빈문자를 NULL로 자동 처리한다
SELECT 0, NULL, ''
FROM dual;

-- 오라클은 NULL을 제일 큰값으로 정렬한다
SELECT commission_pct
FROM employees
ORDER BY 1 DESC;

-- 비교연산자는 NULL을 판별하지 못한다
SELECT commission_pct
FROM employees
WHERE commission_pct <> NULL;

SELECT commission_pct
FROM employees
WHERE commission_pct = NULL;

SELECT commission_pct
FROM employees
WHERE commission_pct IS NULL;

SELECT commission_pct
FROM employees
WHERE commission_pct IS NOT NULL;

-- AND : 두개의 조건식이 모두 참이면 참
-- 참이랑 unknown -> unknown

SELECT salary, commission_pct
FROM employees
WHERE salary >= 5000 AND commission_pct = NULL;

-- OR : 두개의 조건식 중에 하나라도 참이면 참
-- 참이랑 unknown -> 참
-- salary >= 5000 이상인 사원을 조회한다
SELECT salary, commission_pct
FROM employees
WHERE salary >= 5000 or commission_pct = NULL;

-- BWETEEN a AND b 
SELECT commission_pct
FROM employees
WHERE commission_pct BETWEEN 0.3 AND NULL;

-- IN 
SELECT commission_pct
FROM employees
WHERE commission_pct IN (NULL, 0.1);


/*
 * NULL 관련 함수
 */

-- NVL(표현식, 기본값) : NULL이면 기본값으로, NULL이 아니면 표현식으로
SELECT commission_pct,
	nvl(commission_pct, 0)
FROM employees;

-- NVL2(표현식, 값1, 값2) : 표현식이 NULL이 아니면 값1, NULL이면 값2
SELECT commission_pct,
	nvl2(commission_pct, 'y', 'n')
FROM employees;

-- 기본값과 표현식의 자료형이 일치해야 한다
--SELECT commission_pct,
--	nvl(commission_pct, 'N')
--FROM employees;

-- 2개의 값의 자료형이 일치해야 한다
--SELECT commission_pct,
--	nvl2(commission_pct, 2, 'B')
--FROM employees;

-- NULLIF(표현식, 값1) : 표현식과 값1이 일치하면 NULL, 일치하지 않으면
-- 표현식의 값으로 사용
SELECT department_id, nullif(department_id, 90)
FROM employees;

-- COALESCE(값1, 값2, 값3) : NULL이 아닌 최초의 값으로 사용
SELECT coalesce(NULL, 1, 3)
FROM dual;

SELECT coalesce(commission_pct, 0)
FROM employees;

SELECT coalesce(commission_pct, salary)
FROM employees;


/*
 * 실습.
 * 커미션 비율이 존재하고, 급여가 5000 이상인 사원들의
 * 사원번호, 급여, 커미션 비율 조회하기
 * 급여가 높은 순으로 정렬한다
 */

SELECT employee_id
	,salary
	,commission_pct
FROM employees
WHERE commission_pct IS NOT NULL AND salary >= 5000
ORDER BY salary DESC;


/*
 * 실습.
 * 이달 매출이 3000 발생했을때 사원들의 사원번호, 커미션비율, 인센티브 금액구하기
 * 인센티브 금액 = 매출액 x 커미션 비율
 * 커미션 비율이 존재하지 않는 사원은 인센티브 금액이 0원이다
 * NVL, NVL2, COALESCE 함수를 사용한다
 * 조회 결과는 인센티브 금액이 큰 사원부터 정렬한다
 */

SELECT employee_id
	,commission_pct
	,nvl(commission_pct * 3000, 0) 
	,nvl(commission_pct, 0) * 3000
	,nvl2(commission_pct, commission_pct * 3000, 0)
	,coalesce(commission_pct*3000, 0)
FROM employees
ORDER BY 3 DESC;


/*
 * 집계함수
 */

-- COUNT(*)
-- employees 테이블의 모든 행의 개수를 구한다
SELECT count(*)
FROM employees;

-- COUNT(컬럼명)
-- employees 테이블의 employee_id 컬럼의 NULL을 제외한 
-- 행의 개수를 구한다
SELECT count(employee_id)
FROM employees;

-- employee 테이블에서 commission_pct 컬럼의 NULL을 제외한
-- 행의 개수를 구한다
SELECT count(commission_pct)
FROM employees;

-- employees 테이블에서 중복을 제외한 department_id 컬럼의
-- NULL을 제외한 행의 개수를 구한다
SELECT count(DISTINCT department_id)
FROM employees;

-- 부서번호가 80번인 사원들의 수를 구한다
SELECT count(*)
FROM employees
WHERE department_id = 80;

-- 집계함수는 일반컬럼과 같이 조회하지 못한다
--SELECT first_name, count(employee_id)
--FROM employees;

-- SUM() : NULL을 제외한 행들의 합계 
SELECT sum(salary)
FROM employees;

-- 7.8 -> NULL을 제외한 합계(where절에서 제외하는것과 동일)
SELECT sum(commission_pct)
FROM employees;

-- 7.8
SELECT sum(commission_pct)
FROM employees
WHERE commission_pct IS NOT NULL;

-- AVG() : NULL을 제외한 행들의 평균
SELECT avg(salary)
FROM employees;

-- MAX() : NULL을 제외한 행들의 최대값
-- MIN() : NULL을 제외한 행들의 최소값

SELECT max(salary), min(salary)
FROM employees;

-- 문자와 집계함수
SELECT max(first_name), min(first_name)
FROM employees;

-- 날짜와 집계함수
-- max() : 가장 최신 날짜, min() : 가장 오래된 날짜
SELECT max(hire_date), min(hire_date)
FROM employees;

/*
 * 실습.
 * 급여가 5000 이상 8000 이하인 사원들 중에서
 * 급여가 제일 적은 사원의 급여 구하기
 */

SELECT min(salary)
FROM employees
WHERE salary BETWEEN 5000 AND 8000;


/*
 * 실습.
 * 부서번호가 80, 50, 30번에 해당하는 사원들의 평균 급여 구하기
 */

SELECT avg(salary)
FROM employees
WHERE department_id IN (80, 50, 30);


/*
 * 실습 및 과제.
 * 2005년도 입사자의 최고 급여와 최저 급여 구하기
 * 
 */











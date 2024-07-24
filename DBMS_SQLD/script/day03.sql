/*
 * 실습1. 개똥이의 생년월일은 2010년 12월 31일 입니다
 * 개똥이는 현재 날짜를 기준으로 태어난지 몇일 되었을까요?(정수)
 */

SELECT trunc(sysdate - DATE '2010-12-31')
FROM dual;


/*
 * 실습2. 현재 날짜와 시간으로부터 1일전, 1시간전, 1분전, 1초전 구하기
 */

SELECT sysdate,
	sysdate - 1 AS "1일 전",
	sysdate - 1/24 AS "1시간 전",
	sysdate - 1/60/24 AS "1분 전",
	sysdate - 1/60/60/24 AS "1초 전"
FROM dual;

-- interval 리터럴
SELECT sysdate
	,sysdate - INTERVAL '1' DAY AS "1일 전"
	,sysdate - INTERVAL '1' HOUR AS "1시간 전"
	,sysdate - INTERVAL '1' MINUTE AS "1분 전"
	,sysdate - INTERVAL '1' SECOND AS "1초 전"
FROM dual;

/*
 * 실습3. 현재 날짜를 기준으로 근속일수가 높은 사원순으로 정렬하여 조회하기
 * 만약 근속일수가 동일할 경우, 사원번호가 작은 사람부터 정렬한다
 */

-- 근속일수와 사원번호
SELECT employee_id AS "사원 번호",
	trunc(sysdate - hire_date) AS "근속일수"
FROM employees
ORDER BY 2 DESC;

-- 근속일수와 모든 컬럼
SELECT trunc(sysdate - hire_date) AS "근속일수", e.*
FROM employees e
ORDER BY "근속일수" DESC, employee_id;

-- 날짜 + 날짜 -> 불가. 에러가 발생한다
-- 날짜 - 날짜 연산만 가능하다(뺄셈)
--SELECT sysdate + DATE '2010-10-31'
--FROM dual;

-- 문자 + 문자 : 문자는 산술 연산이 불가하다
--SELECT 'A' / 'B'
--FROM dual;

/*
 * 연결 연산자(||)
 */

SELECT 'A' || 'B'
FROM dual;

-- 문자 || 문자
SELECT first_name || last_name AS full_name,
	first_name || ' '|| last_name
FROM employees;

-- 숫자 || 문자
-- 숫자를 문자를 자동 형변환 한후에 문자를 연결한다
SELECT salary || '원'
FROM employees;

-- 날짜 || 문자
-- 날짜를 문자로 자동 형변환 한후에 문자와 연결한다
SELECT '입사일 :' || hire_date
FROM employees;

-- NULL과 산술 연산자
-- NULL : 값이 존재하지 않음을 표현하는 값
-- NULL은 산술 연산의 결과가 NULL이다
SELECT null + 10, NULL - 10, NULL * 10, NULL / 10
FROM dual;

-- 산술 연산자와 연결 연산자의 우선순위가 동일하다(왼쪽에서 오른쪽으로 실행)
SELECT 20 + 30 || '원' -- 50 || '원'
	,'원' || 20 + 30	  -- '원20' + 30
FROM dual;

/*
 * 관계연산자(비교연산자)
 */

-- 급여가 10000 이상인 사원만 모든 컬럼을 조회하기
-- employees 테이블의 107명의 모든 사원을 한명씩 가져와서
-- salary 컬럼의 값을 10000과 대소비교를 진행한다(>=)
-- 만약 해당 사원의 salary 컬럼의 값이 10000보다 크거나 같으면 TRUE,
-- 아니라면 FALSE의 결과를 얻게되고 그 값이 TRUE가 나온 사원만 조회한다

SELECT *
FROM employees
WHERE salary >= 10000;

-- 급여가 10000인 사원만 조회하기
SELECT *
FROM employees
WHERE salary = 10000;

-- 급여가 10000이 아닌 사원만 조회하기
SELECT *
FROM employees
WHERE salary <> 10000;

/*
 * 실습1. 이름(first_name)이 David 인 사원의 이름, 성, 급여 조회하기
 */

SELECT first_name
	,last_name
	,salary
FROM employees
WHERE first_name = 'David';

/*
 * 실습2. 부서번호가 80번인 사원들의 부서번호, 급여 조회하기
 */

SELECT department_id, salary
FROM employees
WHERE department_id = 80;

-- 실습2 번에서 구한 부서번호가 80번인 사원들의 정보를
-- 급여가 큰 순서대로 정렬해서 조회하기

-- 작성순서 : select > from > where > order by
-- 실행순서 : from > where > select > order by

SELECT department_id, salary
FROM employees
WHERE department_id = 80
ORDER BY salary DESC;

-- order by 는 select 다음에 실행되므로 별칭이 사용가능하다
SELECT department_id, salary AS 급여
FROM employees
WHERE department_id = 80
ORDER BY 급여 DESC;

-- where은 select 이전에 실행되므로 별칭을 사용할수 없다
--SELECT department_id AS 부서번호, salary
--FROM employees
--WHERE 부서번호 = 80
--ORDER BY salary DESC;

/*
 * 논리 연산자
 */

-- 급여가 10000 이상이고, 부서번호가 80번인 사원의 부서번호, 급여 조회하기
SELECT department_id, salary
FROM employees
WHERE salary >= 10000 AND department_id = 80;

-- 급여가 10000 이상이거나 부서번호가 80번인 사원의 부서번호, 급여 조회하기
SELECT department_id, salary
FROM employees
WHERE salary >= 10000 OR department_id = 80;

-- 부서번호가 80번이거나 60번인 사원들의 사원번호, 부서번호 조회하기
SELECT employee_id, department_id
FROM employees
WHERE department_id = 80 OR department_id = 60;

-- 현실 세계에서는 표기가 가능하지만, 문법적으로 틀려 에러 발생
--SELECT salary
--FROM employees
--WHERE 5000 <= salary <= 10000;

-- 부서번호가 80이 아닌 사원들의 사원번호, 부서번호 조회하기
SELECT employee_id, department_id
FROM employees
WHERE department_id <> 80;

SELECT employee_id, department_id
FROM employees
WHERE NOT department_id = 80;

/*
 * 실습1.
 * 급여가 5000 이상, 8000 이하인 사원들의 사원번호, 급여 조회하기
 * 급여가 큰 순서대로 정렬한다(5000 <= salary <= 8000)
 */

-- salary >= 5000 , salary <= 8000

SELECT employee_id, salary
FROM employees
WHERE salary >= 5000 AND salary <= 8000
ORDER BY salary desc;


/*
 * 실습2.
 * job_id(직무)가 'IT_PROG', 'FI_MGR', 'ST_MAN' 중에 하나와
 * 일치하는 사원의 사원번호, 직무(job_id) 조회하기
 */

-- job_id = 'IT_PROG', job_id ='FI_MGR', job_id = 'ST_MAN'
SELECT employee_id, job_id
FROM employees
WHERE job_id = 'IT_PROG' OR job_id = 'FI_MGR' OR job_id = 'ST_MAN';

/*
 * BETWEEN 연산자
 */

-- 급여가 5000 이상이고, 8000이하인 사원조회하기
SELECT employee_id, salary
FROM employees
WHERE salary BETWEEN 5000 AND 8000;

-- BTWEEN 연산자는 두개의 값이 포함된다(이상, 이하)
SELECT employee_id, salary
FROM employees
WHERE salary > 5000 AND salary < 8000
ORDER BY salary desc;

-- 8000 <= salary <= 5000
-- 두개의 값의 대소관계 비교가 진행되므로 작은값-> 큰값 순서로 작성한다
SELECT employee_id, salary
FROM employees
WHERE salary BETWEEN 8000 AND 5000;

-- 날짜
-- 2003년 1월 1일 ~ 2004년 1월 1일 사이에 입사한 사원 조회하기
SELECT employee_id, hire_date
FROM employees
WHERE hire_date BETWEEN DATE '2003-01-01' AND DATE '2004-01-01';

-- 날짜도 대소관계 비교가 진행되므로 옛날날짜 -> 최신날짜 순서로 작성한다
SELECT employee_id, hire_date
FROM employees
WHERE hire_date BETWEEN DATE '2004-01-01' AND DATE '2003-01-01';

-- to_date() 함수 : 문자 -> 날짜
SELECT employee_id, hire_date
FROM employees
WHERE hire_date BETWEEN to_date('2003-01-01') AND to_date('2004-01-01');


/*
 * IN 연산자
 */

SELECT employee_id, job_id
FROM employees
WHERE job_id = 'IT_PROG' OR job_id = 'FI_MGR' OR job_id = 'ST_MAN';

SELECT employee_id, job_id
FROM employees
WHERE job_id IN ('IT_PROG', 'FI_MGR','ST_MAN');

-- 여러개의 컬럼과 IN
-- 1. 부서번호가 80이고, job_id(직무)가 'SA_MAN'인 사원
-- 2. 부서번호가 50이고, job_id(직무)가 'ST_MAN'인 사원
-- 1번과 2번 조건중에 둘중에 한개라도 만족하는 사원을 조회하기

SELECT employee_id
	,department_id
	,job_id
FROM employees
WHERE (department_id, job_id) IN ((80, 'SA_MAN'), (50, 'ST_MAN'));

/*
 * NOT 연산자
 */

-- 부서번호가 80, 60, 50번이 아닌 사원 조회하기
SELECT employee_id, department_id
FROM employees
WHERE department_id NOT IN (80, 60, 50);

-- 급여가 5000보다 작거나, 10000보다 큰 사원 조회하기
SELECT employee_id, salary
FROM employees
WHERE salary NOT BETWEEN 5000 AND 10000;


-- 문자와 BETWEEN
-- 'A', 'A'가 들어가는 2글자, 'A'가 들어가는 3글자...
-- 이름이 'C' 한글자인 사람까지만 포함되기 때문에 C가 들어가는 이름들이
-- 조회되지 않는다
SELECT first_name
FROM employees
WHERE first_name BETWEEN 'A' AND 'C'
ORDER BY first_name;












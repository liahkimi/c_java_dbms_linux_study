
/*
 * 실습 및 과제.
 * 2005년도 입사자의 최고 급여와 최저 급여 구하기
 * 2005년 1월 1일 00:00:00 ~ 2005년 12월 31일 23:59:59
 */

-- 1초를 계산해서 뺀다
SELECT max(salary), min(salary)
FROM employees
WHERE hire_date BETWEEN to_date('2005-01-01') AND to_date('2006-01-01') - 1/24/60/60;

-- to_date 에서 날짜의 형식을 알려주어야 한다(format)
SELECT to_date('2005-01-01')
	,to_date('2006-01-01')
	,to_date('2006-01-01') - 1/24/60/60
	,to_date('2005-12-31 23:59:59', 'yyyy-mm-dd hh24:mi:ss')
	,to_date('2006-01-01') - INTERVAL '1' SECOND 
FROM dual;

-- extract() : 날짜에서 지정한 요소를 숫자로 가져온다
-- extract(날짜요소 from 날짜데이터)
SELECT extract(YEAR FROM hire_date)
	,extract(MONTH FROM hire_date)
	,extract(DAY FROM hire_date)
FROM employees;

-- hire_date 컬럼은 date 타입이므로 시간을 가져올수 없다
-- extract() 함수는 시간 데이터를 가져올때는 timestamp 타입만 가능하다
--SELECT extract(HOUR FROM hire_date)
--	,extract(MINUTE FROM hire_date)
--	,extract(SECOND FROM hire_date)
--FROM employees;

SELECT extract(HOUR FROM to_timestamp(hire_date))
FROM employees;

-- sysdate : 현재 날짜와 시간을 date 타입으로 가져온다
-- systimestamp : 현재 날짜와 시간을 timestamp 타입으로 가져온다

SELECT extract(HOUR FROM systimestamp)
FROM dual;

-- to_char() : 날짜 데이터를 문자 데이터로 형변환한다
-- yyyy(년), mm(월), dd(일), hh24(24시간), hh(12시간), am(am, pm 여부), mi(분), ss(초)
SELECT to_char(sysdate, 'yyyy')
	,to_char(sysdate, 'yy')
	,to_char(sysdate, 'mm')
	,to_char(sysdate, 'dd')
FROM dual;

/*
 * 부서별로 사원들의 평균, 최저, 최고 급여를 조회한다
 */

SELECT DISTINCT department_id
FROM employees;

/*
 * GROUP BY
 */

-- avg() 집계함수의 대상이 107명 사원 전체의 그룹이다
SELECT avg(salary)
FROM employees;

-- 그룹 기준이 아닌 일반컬럼은 조회할수 없다
-- 집계함수는 해당 그룹당 하나의 결과를 가져오면 되기때문에 다른 컬럼도 사용 가능
SELECT department_id
	,avg(salary)
	,max(salary)
	,min(salary)
	,count(*)
FROM employees
GROUP BY department_id;

/*
 * 집계함수와 GROUP BY
 * GROUP BY 사용전 : 집계함수의 대상 -> 테이블 전체 데이터(1개의 그룹)
 * GROUP BY 사용후 : 집계함수의 대상 -> 데이블들의 각각의 소그룹(여러개의 그룹)
 * 집계 그룹의 기준이 변경된다
 */

-- 직무별 사원들의 평균, 최고, 최저 급여 구하기
SELECT job_id
	,avg(salary)
	,max(salary)
	,min(salary)
FROM employees
GROUP BY job_id;

-- 입사연도별 사원들의 정보 구하기
SELECT extract(YEAR FROM hire_date)
	,count(*)
	,max(salary)
	,min(salary)
	,avg(salary)
FROM employees
GROUP BY extract(YEAR FROM hire_date);

/*
 * 실습. 부서별 직무의 개수 조회하기
 * 직무 : job_id
 * 단, 중복 직무는 개수에 포함하지 않는다
 */

SELECT department_id, count(DISTINCT job_id)
FROM employees
GROUP BY department_id;

-- GROUP BY 기준 컬럼 여러개
-- 부서별 그룹 > 해당 부서의 직무별 그룹
SELECT department_id, job_id
FROM employees
GROUP BY department_id, job_id
ORDER BY 1;

SELECT department_id
	,job_id
	,count(*)
	,max(salary)
	,min(salary)
FROM employees
GROUP BY department_id, job_id;

/*
 * GROUP BY 와 WHERE
 */

-- FROM > WHERE > GROUP BY > SELECT > ORDER BY

-- 매니저 사번이 100인 사원들의 부서번호와 부서별 인원수 구하기
-- 매니저 사번(manager_id)이 100인 사원들 -> WHERE
-- 사원들의 부서번호와 부서별 인원수 -> GROUP BY
SELECT department_id, count(*)
FROM employees
WHERE manager_id = 100
GROUP BY department_id;

/*
 * HAVING
 */

-- 최대 급여가 10000 이상인 부서만 최대급여 조회하기
-- 여러개의 그룹중에서 having절을 만족하는 그룹만 조회한다
SELECT department_id, max(salary)
FROM employees
GROUP BY department_id
HAVING max(salary) >= 10000;

-- 전체 사원에서 부서번호가 80인 사원들만 그룹화한다
SELECT department_id
FROM employees
WHERE department_id = 80
GROUP BY department_id;

-- 전체 사원을 그룹화 하고 부서번호가 80인 그룹만 조회한다
SELECT department_id
FROM employees
GROUP BY department_id
HAVING department_id = 80;

-- GROUP BY 기준컬럼이 아닌 일반컬럼은 having에서 사용이 불가하다
--SELECT department_id
--FROM employees
--GROUP BY department_id
--HAVING salary >= 10000;

/*
 * 실습.
 * 부서별 2006년 입사자 수와 평균 급여 구하기
 * 2006년 입사자들의 부서별 입사자수와 평균 급여 구하기
 */

-- where절
SELECT department_id, count(*), avg(salary)
FROM employees
WHERE extract(YEAR FROM hire_date) = 2006
GROUP BY department_id;

-- having절
SELECT department_id
	,extract(YEAR FROM hire_date)
	,count(*)
	,avg(salary)
FROM employees
GROUP BY department_id, extract(YEAR FROM hire_date)
HAVING EXTRACT(YEAR FROM hire_date) = 2006;


/*
 * 실습.
 * 사원의 수가 5명 이상인 부서의 최저, 최고급여와 사원의 수 구하기
 * 사원의 수 : count()
 * where 절 : 집계함수 사용 불가
 * having 절 : 집계함수 사용 가능 
 */

SELECT department_id, min(salary), max(salary), count(*)
FROM employees
GROUP BY department_id
HAVING count(*) >= 5;


/*
 * 실습.
 * 직무별 커미션 비율이 존재하는 사원의 수 구하기
 * 커미션 비율이 존재한다 -> commission_pct 컬럼의 값이 NULL이 아니다
 * 그룹화 기준 컬럼이 아닌 일반컬럼의 값을 조건으로 사용해야 하므로 where에서 사용
 */

SELECT job_id, count(*)
FROM employees
WHERE commission_pct IS NOT NULL
GROUP BY job_id;

/*
 * 단순 CASE 표현식
 */

-- 부서번호가 60번이면 'IT부서', 부서번호가 80번이면 '영업부서'
-- department_id = 60 , department_id = 80
SELECT employee_id
	,CASE department_id 
		WHEN 60 THEN 'IT부서'
		WHEN 80 THEN '영업부서'
	END AS 부서
FROM employees;

-- 부서번호가 60번도 80번도 아니면 '미정'
SELECT employee_id
	,CASE department_id 
		WHEN 60 THEN 'IT부서'
		WHEN 80 THEN '영업부서'
		ELSE '미정'
	END AS 부서
FROM employees;

-- 부서번호가 60번이면 급여 + 1000, 부서번호가 80번이면 급여 + 500 한 금액을
-- 변동 급여로 사용한다. 두 번호에 해당하지 않으면 기존 급여로 사용한다

SELECT employee_id
	,salary
	,CASE department_id
		WHEN 60 THEN salary + 1000
		WHEN 80 THEN salary + 500
		ELSE salary
	END AS "변동 급여"
FROM employees;

-- CASE 표현식도 하나의 값으로 평가되므로 함수안에서 사용 가능하다!
SELECT sum(CASE department_id
			WHEN 60 THEN salary + 1000
			WHEN 80 THEN salary + 500
			ELSE salary
			END) AS "변동 급여 총 합계"
		,sum(salary)
FROM employees;

-- 오라클의 DECODE() 함수
SELECT employee_id
	,department_id
	,decode(department_id, 60, 'IT부서', 80, '영업부서', '미정')
FROM employees;

/*
 * 검색 CASE 표현식
 */

-- 급여가 10000 이상이면 상위
-- 급여가 6000 이상이면 중위
-- 급여가 1000 이상이면 하위

SELECT employee_id, salary
	,CASE
		WHEN salary >= 10000 THEN '상위'
		WHEN salary >= 6000 THEN '중위'
		WHEN salary >= 1000 THEN '하위'
	END
FROM employees;
	
SELECT employee_id, salary
	,CASE
		WHEN salary >= 1000 THEN '하위'
		WHEN salary >= 6000 THEN '중위'
		WHEN salary >= 10000 THEN '상위'
	END
FROM employees;






























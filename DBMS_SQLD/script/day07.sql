
/*
 * 인라인뷰
 * 인라인 뷰를 통해 가져온 가상의 테이블과 조인하여 사용
 */

-- 부서번호 60인 사원의 사원번호, 이름, 부서정보 조회하기
SELECT *
FROM departments d
INNER JOIN(SELECT employee_id, department_id, first_name
			FROM employees 
			WHERE department_id = 60) e
ON d.department_id = e.department_id;

-- 부서명, 부서 최고급여, 최저급여, 소속 사원의 수 조회하기
SELECT d.department_name, e.*
FROM departments d
INNER JOIN (SELECT department_id, count(*), max(salary), min(salary)
			FROM employees
			GROUP BY department_id)	e
ON d.department_id = e.department_id;

-- rownum : 쿼리 선택 결과에 붙여진 가상 순번
SELECT rownum, employee_id
FROM employees;

-- 부서번호가 80번인 행들의 rownum 조회하기
-- department_id = 80 조건을 만족하는 행들을 추출
-- 1번부터 번호를 부여하고 행 하나당 1씩 증가시킨다
SELECT rownum, employee_id
FROM employees
WHERE department_id = 80;

-- 행을 하나씩 추출하고 rownum을 1번부터 부여
SELECT rownum, employee_id
FROM employees;

-- 행을 하나씩 추출하고 rownum을 1번부터 부여
-- where절을 만족하는 행들만 조회
SELECT rownum, employee_id
FROM employees
WHERE rownum <= 5;

-- 부서번호가 80번인 행들중에서 rownum이 1~5인 행들을 조회하기
SELECT rownum,
	employee_id,
	first_name
FROM employees
WHERE department_id = 80 AND rownum <= 5;

-- ORDER BY 전에 순번을 붙이기 때문에
-- ORDER BY를 사용할 경우 순서가 변경된다
SELECT rownum,
	employee_id,
	first_name
FROM employees
ORDER BY employee_id;

-- 급여 상위 5위를 조회하기
-- 결과 : 24,000 > 17,000 > 5,000 > 4,000 > 3,000
SELECT rownum,
	employee_id,
	salary
FROM employees
WHERE rownum <= 5
ORDER BY salary DESC;

-- 데이터가 잘 조회되었는지 확인한다
-- 24,000 > 17,000 > 17,000 > 14,000, 13,500
-- 실제 데이터와 일치 하지 않는다
SELECT salary 
FROM employees 
ORDER BY salary DESC;

-- 급여 내림차순으로 먼저 전체 데이터를 정렬하고(인라인뷰)
-- 이 정렬된 쿼리 결과에 rownum을 부여해 1~5번 행들을 조회한다
SELECT rownum, employee_id, salary 
FROM (SELECT * FROM employees ORDER BY salary DESC) 
WHERE rownum <= 5; -- 인라인뷰의 rownum이 아닌 메인쿼리의 rownum

-- 서브쿼리의 rownum과 메인쿼리의 rownum
SELECT rownum -- 메인쿼리의 rownum
	,e.employee_id
	,e.rn -- 인라인뷰의 rownum
FROM (SELECT rownum AS rn, employee_id FROM employees ORDER BY salary DESC) e
WHERE rownum <= 3;

SELECT rownum -- 메인쿼리의 rownum
	,e.employee_id
	,e.rn -- 인라인뷰의 rownum
FROM (SELECT rownum AS rn, employee_id FROM employees ORDER BY salary) e
WHERE rownum <= 3;


-- rownum으로 조회시 인라인뷰(서브쿼리)의 rownum이 아닌 메인쿼리의 rownum을 사용하게 된다
-- 인라인뷰의 rownum에 별칭을 붙여 조회한다
-- SELECT rownum, e.employee_id, e.rownum
-- FROM (SELECT rownum, employee_id FROM employees ORDER BY salary DESC) e
-- WHERE e.rownum <= 3;

-- 행을 하나 추출하고 rownum을 1번 부여 -> where절을 만족하므로 조회
SELECT rownum, employee_id
FROM employees
WHERE rownum = 1;

-- 행을 하나 추출하고 rownum을 1번 부여 -> where절을 만족하지 않으므로 조회 x
-- 행을 한개 더 추출하고 rownum을 1번 부여 -> 이전 행이 조회 대상에 포함되지 않아 rownum이 2로 증가하지 않는다
-- 행을 아무리 가져와도 붙이는 rownum은 항상 1번이고(이전행이 조회 대상에 포함되지 않아 증가하지 않음) 조건을 만족할수 없어 조회불가
SELECT rownum, employee_id
FROM employees
WHERE rownum = 2;

-- 2번 순번의 행을 가져오기 위해서 인라인뷰 사용
SELECT e.rn, e.employee_id
FROM (SELECT rownum AS rn, employee_id FROM employees) e
WHERE e.rn = 2;

-- 페이징 처리
-- 전체 사원을 10명씩 가져오기
-- 1~10번 
SELECT rownum, employee_id
FROM employees 
WHERE rownum BETWEEN 1 AND 10;

-- 11~20번
-- 데이터가 조회되지 않는다
SELECT rownum, employee_id
FROM employees 
WHERE rownum BETWEEN 11 AND 20;

-- 11~20번 사원을 가져오기 위해 인라인뷰 사용
SELECT e.rn, e.employee_id
FROM (SELECT rownum AS rn, employee_id FROM employees) e
WHERE e.rn BETWEEN 11 AND 20;

/*
 * 급여 5~10위 까지 직원의 사원번호, 급여, 부서명 조회하기
 */

-- 급여가 높은 순으로 직원들 정렬
SELECT e.employee_id, e.salary, d.department_name
FROM employees e INNER JOIN departments d
ON e.department_id = d.department_id
ORDER BY e.salary DESC;

-- 급여순으로 순번을 사용하기 위해 인라인뷰
SELECT rownum, e2.*
FROM (SELECT e.employee_id 
	,e.salary
	,d.department_name
	FROM employees e INNER JOIN departments d
	ON e.department_id = d.department_id
	ORDER BY e.salary DESC) e2 
WHERE rownum <= 5;

-- 5위부터 10위까지 이므로 BETWEEN 사용
-- rownum은 1부터 시작해야 한다 
SELECT rownum, e2.*
FROM (SELECT e.employee_id
	,e.salary
	,d.department_name
	FROM employees e INNER JOIN departments d
	ON e.department_id = d.department_id
	ORDER BY e.salary DESC) e2
WHERE rownum BETWEEN 5 AND 10;

-- BETWEEN을 사용하기 위해 인라인뷰 한번 더 사용
SELECT *
FROM (
	SELECT rownum AS rn, employee_id, salary, department_name 
	FROM (SELECT e.employee_id, 
			e.salary, 
			d.department_name
			FROM employees e INNER JOIN departments d
			ON e.department_id = d.department_id
			ORDER BY e.salary DESC))
WHERE rn BETWEEN 5 AND 10;

-- ROW_NUMBER()
-- 급여 내림차순으로 정렬후에 순서를 붙이기
SELECT ROW_NUMBER() OVER(ORDER BY salary DESC) AS rn
	,employee_id
	,salary
FROM employees e;

SELECT e.*, d.department_name
FROM departments d 
INNER JOIN (SELECT ROW_NUMBER() OVER(ORDER BY salary DESC) AS rn
		,employee_id
		,salary
		,department_id 
	FROM employees) e
ON d.department_id = e.department_id
WHERE e.rn BETWEEN 5 AND 10;

SELECT *
FROM (
    SELECT e.employee_id, e.salary, d.department_name
        ,ROW_NUMBER() OVER (ORDER BY e.salary DESC) AS salary_rank
    FROM employees e 
    INNER JOIN departments d ON e.department_id = d.department_id
) e2
WHERE e2.salary_rank BETWEEN 5 AND 10;


/*
 * 스칼라 서브쿼리
 */

-- 전체 사원의 급여 정보와, 평균 급여 조회하기

-- 집계함수와 일반 컬럼을 같이 사용할수 없다
--SELECT employee_id,
--	salary,
--	avg(salary)
--FROM employees;

SELECT employee_id, salary
	,(SELECT avg(salary) FROM employees) AS 평균급여
FROM employees;

-- 각 사원들의 급여와 평균 급여의 차액 구하기
SELECT employee_id, salary
	,(SELECT avg(salary) FROM employees) - salary AS 차액
FROM employees;

-- 부서별 평균급여, 최고급여, 최저급여, 전체 평균 급여
SELECT department_id
	,avg(salary)
	,MAX(salary)
	,MIN(salary)
	,(SELECT avg(salary) FROM employees) AS "전체 평균급여"
FROM employees
GROUP BY department_id;

-- 서브쿼리는 메인쿼리의 컬럼을 사용할수 있다
-- 조인을 하지 않아도 부서명 정보를 조회할수 있다
SELECT e.employee_id, e.salary, e.department_id
	,(SELECT department_name 
	FROM departments d
	WHERE e.department_id = d.department_id) AS 부서명
FROM employees e;
	
-- 사원의 사원번호, 급여과 해당 사원보다 급여가 높은 사원의 수를 구하기
SELECT e1.employee_id, e1.salary
	,(SELECT count(*) FROM employees WHERE salary > e1.salary) AS "상위 급여자수"
FROM employees e1

-- 서브쿼리의 컬럼의 값을 WHERE절에서 사용불가(실행순서)
--SELECT e1.employee_id,
--	e1.salary,
--	(SELECT salary FROM employees WHERE employee_id = 100) AS "기준급여"
--FROM employees e1
--WHERE salary = "기준급여";


/*
 * 서브쿼리
 */

-- 124번 사원의 급여는 5,800
SELECT salary FROM employees WHERE employee_id = 124;

-- 124번 사원보다 급여가 높은 사원들의 사원번호, 급여 조회하기
SELECT employee_id, salary
FROM employees 
WHERE salary > (SELECT salary FROM employees WHERE employee_id = 124)
ORDER BY salary;

-- 124번 사원의 부서번호는 50번
SELECT department_id 
FROM employees 
WHERE employee_id = 124;

-- 124번 사원과 동일부서인 사원의 정보 조회하기
SELECT employee_id, department_id
FROM employees
WHERE department_id = (SELECT department_id FROM employees WHERE employee_id = 124);


-- 평균 급여 6394.69...
SELECT avg(salary) FROM employees;

-- 평균급여 보다 급여가 높은 직원 구하기
SELECT employee_id,
	salary
FROM employees 
WHERE salary > (SELECT avg(salary) FROM employees)
ORDER BY salary;

-- 부서별 전체 평균급여보다 급여가 높은 사원의 수 구하기
SELECT department_id, count(*)
FROM employees
WHERE salary > (SELECT avg(salary) FROM employees)
GROUP BY department_id;

-- 입사연도 별 평균 급여 구하기
SELECT extract(YEAR FROM hire_date) 입사연도
	,avg(salary) AS "입사연도별 평균급여"
FROM employees
GROUP BY extract(YEAR FROM hire_date)
ORDER BY 입사연도;

-- 입사연도별 평균급여보다 급여가 높은 사원 구하기
SELECT e1.employee_id, e1.salary
FROM employees e1
WHERE e1.salary > 
(SELECT avg(salary) FROM employees
WHERE extract(YEAR FROM e1.hire_date) = extract(YEAR FROM hire_date));

-- 다중행 서브쿼리
-- 지역번호가 1700번에 해당하는 부서번호 구하기
-- 21개
SELECT location_id, department_id
FROM departments 
WHERE location_id = 1700;

-- 부서의 지역번호가 1700번에 해당하는 사원 구하기					
SELECT department_id, employee_id
FROM employees 
WHERE department_id IN (SELECT department_id FROM departments WHERE location_id = 1700)
ORDER BY department_id;

-- 100번 부서의 사원들의 급여 조회하기
/*
 * 	6900
 *	7700
 *	7800
 *	8200
 *	9000
 *	12008
 */

SELECT employee_id, department_id, salary
FROM employees
WHERE department_id = 100
ORDER BY salary;

-- ANY : 여러개중 1개
-- 급여가 100번 부서의 사원들의 급여중 1개보다 크다면
SELECT employee_id, salary
FROM employees
WHERE salary > ANY(SELECT salary FROM employees WHERE department_id = 100)
ORDER BY salary;

-- 여러개중 최소값과 동일
SELECT employee_id, salary
FROM employees
WHERE salary > (SELECT MIN(salary) FROM employees WHERE department_id = 100)
ORDER BY salary;

-- ALL : 여러개 모두
-- 급여가 100번 부서의 사원들의 모든 급여보다 크다면
SELECT employee_id, salary
FROM employees
WHERE salary > ALL(SELECT salary FROM employees WHERE department_id = 100)
ORDER BY salary;

-- 여러개중 최대값과 동일
SELECT employee_id, salary
FROM employees
WHERE salary > (SELECT MAX(salary) FROM employees WHERE department_id = 100)
ORDER BY salary;


-- EXISTS : 서브 쿼리 조건에 만족한다면 
-- 메인 > 서브
SELECT e.department_id, e.employee_id
FROM employees e
WHERE EXISTS (SELECT d.department_id 
	FROM departments d
	WHERE d.location_id = 1700 AND d.department_id = e.department_id)
ORDER BY e.department_id;

-- IN
-- 서브 > 메인
SELECT department_id, 
	employee_id
FROM employees 
WHERE department_id IN (SELECT department_id FROM departments WHERE location_id = 1700)
ORDER BY department_id;
 
-- HAVING
-- 부서의 평균 급여가 전체 사원의 평균 급여보다 높은 부서 조회하기
SELECT department_id
	,avg(salary) AS "부서 평균급여"
FROM employees 
GROUP BY department_id
HAVING avg(salary) > (SELECT avg(salary) FROM employees);

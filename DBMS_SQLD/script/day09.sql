
/*
 * 조합키
 * 여러개의 컬럼을 조합하여 pk(기본키)로 사용하는것 
 */

DROP TABLE tbl_flower;

CREATE TABLE tbl_flower(
	flower_name varchar2(1000)
	,flower_color varchar2(1000)
	,flower_price number
	,CONSTRAINT flower_pk PRIMARY KEY(flower_name, flower_color)
);


INSERT INTO tbl_flower
VALUES('장미', '빨강', 1000);

INSERT INTO tbl_flower
VALUES('장미', '노랑', 1000);

INSERT INTO tbl_flower
VALUES('튤립', '노랑', 1000);

INSERT INTO tbl_flower
VALUES('장미', '노랑', 2000); -- 오류, 조합키 2개의 컬럼이 모두 일치함.

SELECT * FROM tbl_flower;


/*
 * 뷰(VIEW)
 */


-- 뷰 생성
CREATE VIEW v_emp_dept AS
	SELECT e.employee_id
		,e.department_id
		,d.department_name
	FROM employees e 
	INNER JOIN departments d 
	ON d.department_id = e.department_id;

-- 뷰 조회
SELECT * FROM v_emp_dept;

-- 뷰 덮어쓰기
CREATE OR REPLACE VIEW v_emp_dept AS 
	SELECT e.employee_id
		,e.department_id
		,d.department_name
	FROM employees e
	INNER JOIN departments d
	ON d.department_id = e.department_id
	ORDER BY 2;

-- 수정된 뷰 조회
SELECT * FROM v_emp_dept;

-- 뷰 삭제
DROP VIEW v_emp_dept;









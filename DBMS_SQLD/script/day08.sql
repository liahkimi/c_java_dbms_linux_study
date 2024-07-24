
/*
 * DML
 */

DROP TABLE tbl_user;

CREATE TABLE tbl_user(
	name varchar2(1000) -- 유저 이름
	,age NUMBER			-- 유저 나이
	,birth_date DATE	-- 유저 생년월일
	,point NUMBER		-- 유저 포인트 금액
);

SELECT * FROM tbl_user;

/*
 * INSERT : 데이터 삽입(행 추가)
 */

-- 모든 컬럼에 값을 채워서 삽입
INSERT INTO tbl_user
VALUES ('박철수', 20, '2003-04-06', 30);

-- 컬럼의 자료형, 순서와 동일해야 한다
-- SQL Error [1722] [42000]: ORA-01722: invalid number
--INSERT INTO tbl_user
--VALUES (21, '나훈아', '2004-09-10', 0);

INSERT INTO tbl_user
VALUES ('나훈아', 21, '2004-09-10', 20);

INSERT INTO tbl_user
VALUES ('김짱구', 21, SYSDATE, 20);

-- 특정 컬럼에만 값을 채워서 삽인 (지정하지 않은 컬럼에는 NULL 값이 들어간다)
-- 지정하지 않은 포인트 컬럼에는 null이 들어간다
INSERT INTO tbl_user(
	name			-- 이름
	,age			-- 나이
	,birth_date)	-- 생년월일
VALUES ('김영희', 30, '1993-05-03');

-- 컬럼명을 지정할때는 순서가 바뀌어도 상관 없음
INSERT INTO tbl_user(
	age
	,name 
	,birth_date)
VALUES (30, '정길동', '1995-10-18');


/*
 * UPDATE 데이터 수정
 */

SELECT * FROM tbl_user;

-- 조건문을 사용하지 않으면 모든 데이터가 수정된다
-- 모든 행의 age 컬럼의 값이 30으로 변경된다!
UPDATE tbl_user 
SET age = 30;

-- 이름이 '정길동'인 행만 나이를 45로 변경한다
UPDATE tbl_user 
SET age = 45
WHERE name = '정길동';

-- 포인트 금액이 입력이 안된 유저는 0으로 변경한다
UPDATE tbl_user 
SET point = 0
WHERE point IS NULL;

-- 모든 멤버의 나이를 1 증가
UPDATE tbl_user 
SET age = age + 1;

-- 오늘 날짜가 생일인 멤버 조회하기
SELECT *
FROM tbl_user
WHERE to_char(birth_date, 'mmdd') = to_char(sysdate, 'mmdd');

SELECT *
FROM tbl_user
WHERE extract(MONTH FROM birth_date) = EXTRACT(MONTH FROM SYSDATE) 
AND EXTRACT(DAY FROM birth_date) = EXTRACT(DAY FROM SYSDATE);

-- 오늘이 생일인 멤버는 포인트 50 증가
-- 짱구의 포인트 50 증가
UPDATE tbl_user
SET point = point + 50
WHERE TO_CHAR(birth_date, 'MMDD') = TO_CHAR(SYSDATE ,'MMDD');

-- 서브쿼리 사용 가능
-- 정길동의 포인트를 박철수 만큼 변경한다
UPDATE tbl_user
SET point = (SELECT point FROM tbl_user WHERE name = '박철수')
WHERE name = '정길동';

-- 서브쿼리 사용 가능
-- 나이가 제일 많은 멤버에게 포인트 100 증가
SELECT * FROM tbl_user;

UPDATE tbl_user
SET point = point + 100
WHERE age = (SELECT MAX(age) FROM tbl_user);

-- delete 데이터 삭제
SELECT * FROM tbl_user;

-- 나이가 45인 행들만 삭제
DELETE FROM tbl_user
WHERE age = 45;

-- 조건문을 사용하지 않으면 모든 데이터가 삭제된다
DELETE FROM tbl_user;


/*
 * DDL
 * 외래키가 존재하지 않는 테이블
 */

/*
	테이블명 : TBL_USER
	USER_ID : VARCHAR2(1000) PRIMARY KEY
	USER_PASSWORD : VARCHAR2(1000) NOT NULL
	USER_AGE : NUMBER CHECK(USER_AGE ≥ 0)
	USER_EMAIL : VARCHAR2(1000) UNIQUE
	USER_POINT : NUMBER DEFAULT 0
*/

-- 기존 테이블 삭제
DROP TABLE tbl_user;

-- 테이블 생성
CREATE TABLE tbl_user(
	user_id varchar2(1000) 
	,user_pw varchar2(1000) 
	,user_age NUMBER
	,user_email varchar2(1000)
	,user_point varchar2(1000)
);

SELECT * FROM tbl_user;

-- 테이블명 수정
ALTER TABLE tbl_user RENAME TO tbl_shop_user;
SELECT * FROM tbl_shop_user;

ALTER TABLE tbl_shop_user RENAME TO tbl_user;

-- 컬럼 추가
-- user_gender 컬럼 추가
ALTER TABLE tbl_user ADD(user_gender char(2));

-- 컬럼명 수정
-- user_pw 컬럼을 user_password 컬럼명으로 변경
ALTER TABLE tbl_user RENAME COLUMN user_pw TO user_password;

-- 컬럼 삭제
SELECT * FROM tbl_user;
-- user_gender 컬럼 삭제
ALTER TABLE tbl_user DROP COLUMN user_gender;

-- 컬럼 타입 수정
-- USER_POINT 컬럼을 NUMBER로 수정
ALTER TABLE tbl_user MODIFY(user_point NUMBER);

/*
 * 제약조건 생성
 */

-- PRIMARY KEY 제약조건 생성
ALTER TABLE tbl_user ADD CONSTRAINT user_id_pk PRIMARY KEY (user_id);

-- CHECK 제약조건 생성
ALTER TABLE tbl_user ADD CONSTRAINT user_age_ck CHECK(user_age >= 0);

-- UNIQUE 제약조건 생성
ALTER TABLE tbl_user ADD CONSTRAINT user_email_uk UNIQUE(user_email);

-- NOT NULL과 DEFAULT는 컬럼을 수정하면서 제약조건을 변경한다
-- NOT NULL 제약조건 생성
ALTER TABLE tbl_user MODIFY user_password NOT NULL;

-- DEFAULT 제약조건 생성
ALTER TABLE tbl_user MODIFY user_point DEFAULT 0;

/*
 * 제약조건 조회
 * 1. 테이블 클릭 > Constraints 탭 클릭 
 * 2. 조회 쿼리 실행(테이블명을 대문자로 작성해야 한다)
 */

-- CONSTAINT_TYPE : 제약조건의 타입
-- C: check, not null, P: primary key, U : unique key R : foreign key
SELECT * FROM user_constraints
WHERE table_name = 'TBL_USER';

SELECT * FROM user_constraints
WHERE table_name = 'DEPARTMENTS';

-- 제약조건 삭제
ALTER TABLE tbl_user DROP CONSTRAINT user_age_ck;

-- 테이블 삭제
DROP TABLE tbl_user;


/*
 * 제약조건을 함께 작성하여 테이블 생성
 * 1. 컬럼옆에 명시한다(컬럼레벨) 
 * 2. 컬럼아래에 따로 모아 작성한다(테이블레벨)
 */

CREATE TABLE tbl_user(
	user_id varchar2(1000) CONSTRAINT user_id_pk PRIMARY KEY -- 컬럼레벨. 제약조건의 이름을 직접 작성
	,user_password varchar2(1000) NOT NULL -- 컬럼레벨. 제약조건의 이름을 오라클이 자동 부여
	,user_age NUMBER CONSTRAINT user_age_ck check(user_age >= 0) -- 컬럼레벨
	,user_email varchar2(1000)
	,user_point varchar2(1000) DEFAULT 0
	,CONSTRAINT user_email unique(user_email) -- 테이블 레벨
);

SELECT * FROM user_constraints
WHERE table_name = 'TBL_USER';


-- primary key
INSERT INTO tbl_user
values('hong', 'hong123', 30, 'hong@hong.com', 20);

-- pk는 중복이나, 빈값이 저장될수 없다
--INSERT INTO tbl_user
--values('hong', 'kim123', 20, 'kim@kim.com', 10);

--INSERT INTO tbl_user
--values(null, 'kim123', 20, 'kim@kim.com', 10);

-- not null 
-- 빈값이 저장될수 없다
--INSERT INTO tbl_user
--values('kim', NULL, 30, 'kim@kim.com', 20);

-- check
-- 조건에 일치하는 값만 저장될수 있다
--INSERT INTO tbl_user
--values('kim', 'kim123', -100, 'kim@kim.com', 20);

-- unique
-- 중복될수 없다
--INSERT INTO tbl_user
--values('kim', 'kim123', 20, 'hong@hong.com', 20);

-- null 값은 허용된다
INSERT INTO tbl_user
values('kim', 'kim123', 20, null, 20);

-- null 값은 중복으로 판단하지 않는다
INSERT INTO tbl_user
values('ki', 'ki123', 20, null, 20);

-- default
-- 값을 전달하지 않으면 기본값이 저장된다
INSERT INTO tbl_user(
	user_id
	,user_password
	,user_age
)
values('park', 'park123', 25);

/*
 * TRUNCATE
 */

-- tbl_user 테이블의 모든행을 삭제한다
TRUNCATE TABLE tbl_user;


/*
 * 외래키가 존재하는 테이블
 * 
		TBL_GUARDIAN
		=====================================================
		GUARDIAN_NUMBER(PK)		NUMBER
		GUARDIAN_NAME			VARCHAR2(1000) NOT NULL
		GUARDIAN_ADDRESS		VARCHAR2(1000) NOT NULL
		GUARDIAN_PHONE_NUMBER		VARCHAR2(1000) NOT NULL
		
		TBL_PET
		======================================================
		PET_NUMBER(PK)			NUMBER
		PET_NAME 			VARCHAR2(1000)	NOT NULL
		PET_AGE				NUMBER		NOT NULL
		PET_SPECIES			VARCHAR2(1000)	NOT NULL
		GUARDIAN_NUMBER(FK)		NUMBER
 */


-- TBL_GRUARDIAN 테이블 생성
DROP TABLE tbl_guardian;

CREATE TABLE tbl_guardian(
	GUARDIAN_NUMBER NUMBER							-- 보호자 번호
	,GUARDIAN_NAME VARCHAR2(1000) NOT NULL 			-- 보호자 이름
	,GUARDIAN_ADDRESS VARCHAR2(1000) NOT NULL		-- 보호자 주소
	,GUARDIAN_PHONE_NUMBER VARCHAR2(1000) NOT NULL	-- 보호자 핸드폰 번호
	,CONSTRAINT guardian_pk PRIMARY key(guardian_number) -- pk(기본키) 
)

SELECT * FROM tbl_guardian;

-- TBL_PET 테이블 생성
DROP TABLE tbl_pet;

CREATE TABLE tbl_pet(
	PET_NUMBER NUMBER
	,PET_NAME VARCHAR2(1000) NOT NULL
	,PET_AGE NUMBER NOT NULL
	,PET_SPECIES VARCHAR2(1000)	NOT NULL
	,GUARDIAN_NUMBER NUMBER
	,CONSTRAINT pet_pk PRIMARY KEY(pet_number) -- pk
	,CONSTRAINT pet_fk FOREIGN KEY(guardian_number) REFERENCES tbl_guardian(guardian_number) -- fk

)

SELECT * FROM tbl_pet;

-- 보호자 테이블에 데이터 삽입
INSERT INTO tbl_guardian
VALUES(1, '홍길동', '서울시 강남구', '010-1234-5678');

SELECT * FROM tbl_guardian;

-- 보호자 번호를 매번 지정하지 않기 위해 시퀀스 사용
DROP SEQUENCE guardian_seq;
-- 시퀀스 생성
CREATE SEQUENCE guardian_seq;

-- CURRVAL : 시퀀스의 현재값
-- NEXTVAL이 1번 실행되어야 현재값을 확인할수 있다
SELECT guardian_seq.currval FROM dual;

-- NEXTVAL > CURRVAL
-- NEXTVAL : 시퀀스의 다음값
SELECT guardian_seq.nextval FROM dual;

-- 시퀀스를 사용하여 데이터 저장
-- 현재 시퀀스의 값 : 1. 이미 존재하는 pk 이므로 1을 증가시켜서 사용해야 하는 값으로 수정
SELECT guardian_seq.nextval FROM dual;

-- 시퀀스는 증가한 값을 0으로 초기화 할수 없기때문에
-- 삭제했다가 다시 만들어줘야 한다(시퀀스를 삭제해도 시퀀스 값을 사용한 데이터는 유지됨)
DROP SEQUENCE guardian_seq;

INSERT INTO tbl_guardian(
	guardian_number
	,guardian_name
	,guardian_address
	,guardian_phone_number
)values(guardian_seq.nextval, '김영희', '서울시 강서구', '010-1111-2222');

INSERT INTO tbl_guardian(
	guardian_number
	,guardian_name
	,guardian_address
	,guardian_phone_number
)values(guardian_seq.nextval, '나훈아', '서울시 마포구', '010-2222-3333');

SELECT * FROM tbl_guardian;

-- 반려동물 시퀀스 생성
DROP SEQUENCE pet_seq;
CREATE SEQUENCE pet_seq;

INSERT INTO tbl_pet(
	pet_number
	,pet_name
	,pet_age
	,pet_species
	,guardian_number
)VALUES (pet_seq.nextval, '나비', 3, '고양이', 1);

-- 존재하지 않는 보호자 정보는 추가될수 없다(참조 무결성)
--INSERT INTO tbl_pet(
--	pet_number
--	,pet_name
--	,pet_age
--	,pet_species
--	,guardian_number
--)VALUES (pet_seq.nextval, '나비', 3, '고양이', 10);

INSERT INTO tbl_pet(
	pet_number
	,pet_name
	,pet_age
	,pet_species
	,guardian_number
)VALUES (pet_seq.nextval, '까망이', 4, '개', 3);

INSERT INTO tbl_pet(
	pet_number
	,pet_name
	,pet_age
	,pet_species
	,guardian_number
)VALUES (pet_seq.nextval, '복순이', 2, '개', 2);

SELECT * FROM tbl_pet;
SELECT * FROM tbl_guardian;

-- 보호자 삭제
-- FK가 존재하기 때문에 삭제 불가
-- 반려동물 테이블에서 먼저 삭제 후 보호자 테이블에서 삭제를 진행해야 한다
--DELETE FROM tbl_guardian WHERE guardian_number = 2;

-- 보호자 번호가 2번인 반려동물 삭제
DELETE FROM tbl_pet WHERE guardian_number = 2;
-- 보호자 번호가 2번인 보호자 삭제
DELETE FROM tbl_guardian WHERE guardian_number = 2;

-- 보호자 테이블에서 데이터가 삭제되면 동물 테이블 또한 데이터를 항상 삭제해야 한다
-- 자동 삭제되도록 지정해보자
-- 기존 FK 제약조건 삭제
ALTER TABLE tbl_pet DROP CONSTRAINT pet_fk;

-- 보호자 삭제시, 반려동물도 삭제가 되도록 제약조건 수정
ALTER TABLE tbl_pet 
ADD CONSTRAINT pet_fk 
FOREIGN KEY (guardian_number) 
REFERENCES tbl_guardian(guardian_number) ON DELETE CASCADE;

-- 보호자 번호가 3번인 보호자 삭제
DELETE FROM tbl_guardian WHERE guardian_number = 3;
SELECT * FROM tbl_guardian;

-- FK로 연결되어 있는 반려동물 데이터(까망이)도 자동 삭제된다
SELECT * FROM tbl_pet;

-- 제약조건을 CASCADE를 사용했지만 TRUNCATE에는 적용되지 않는다
--TRUNCATE TABLE TBL_GUARDIAN;

-- 참조 테이블이 있어 테이블이 삭제되지 않는다
--DROP TABLE tbl_guardian;

-- 테이블 삭제(제약조건도 같이 삭제됨)
DROP TABLE tbl_guardian CASCADE CONSTRAINT;

-- TBL_PET의 FK 제약조건이 삭제됨
SELECT * FROM user_constaints
WHERE table_name = 'TBL_PET';

-- FK로 사용했던 컬럼이 삭제되지는 않는다
SELECT * FROM tbl_pet;

-- 그러나 제약조건이 사라져 참조 무결성이 사라지게 된다
UPDATE tbl_pet
SET guardian_number = 100
WHERE pet_number = 1;
















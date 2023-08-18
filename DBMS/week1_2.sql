CREATE TABLE DEPARTMENT(
    Deptno INT,
    Deptname VARCHAR(20),
    Location VARCHAR(20),
    Designation VARCHAR(20)
);

INSERT INTO DEPARTMENT(Deptno,Deptname,Location,Designation) 
VALUES (1,"CSE","Old Block","Professor");

COMMIT;

SELECT * FROM DEPARTMENT;

ALTER TABLE DEPARTMENT MODIFY COLUMN Deptno INT NOT NULL,
MODIFY Deptname VARCHAR(20) NOT NULL,
MODIFY Location VARCHAR(20) NOT NULL,
MODIFY Designation VARCHAR(20) NOT NULL;

ALTER TABLE DEPARTMENT
ADD CONSTRAINT unique_columns_constraint UNIQUE (Deptname, Location, Designation);

INSERT INTO DEPARTMENT(Deptno,Deptname,Location,Designation) VALUES (1,"CSE","Old Block","Professor"),
(NULL,"ECE","Old Block","Head");

ALTER TABLE DEPARTMENT ADD COLUMN EXPERIENCE VARCHAR(20) NOT NULL DEFAULT '2 YEARS';

SELECT * FROM DEPARTMENT;

INSERT INTO DEPARTMENT(Deptno,Deptname,Location,Designation) VALUES (2,"ECE","Old Block","Head"),
(1,"CSE","Old Block","Head");

SELECT * FROM DEPARTMENT;

INSERT INTO DEPARTMENT(Deptno,Deptname,Location,Designation) VALUES (2,"ECE","New Block","Head"),(9,"Civil","Old Block","DEAN");

SELECT Deptno, Deptname, SUM(EXPERIENCE) AS TotalExperience
FROM DEPARTMENT GROUP BY Deptno, Deptname;

UPDATE DEPARTMENT SET Location="Research Block" WHERE Deptno=9;

SELECT * FROM DEPARTMENT;

ALTER TABLE DEPARTMENT DROP COLUMN Deptno;

SELECT * FROM DEPARTMENT;
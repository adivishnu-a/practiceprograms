CREATE TABLE Department (
    Deptno NUMBER,
    Deptname VARCHAR2(20),
    Location VARCHAR2(20),
    Designation VARCHAR2(20)
);

INSERT INTO Department (Deptno, Deptname, Location, Designation)
VALUES (1, 'HR', 'Guntur', 'Manager');
INSERT INTO Department (Deptno, Deptname, Location, Designation)
VALUES (2, 'IT', 'Vijayawada', 'Engineer');
COMMIT;

ALTER TABLE Department
ADD CONSTRAINT UQ_Deptno UNIQUE (Deptno);

ALTER TABLE Department
MODIFY (Deptno NOT NULL, Deptname NOT NULL, Location NOT NULL);

INSERT INTO Department (Deptno, Deptname, Location, Designation)
VALUES (1, 'Finance', 'Hyderabad', 'Accountant');

INSERT INTO Department (Deptno, Deptname, Location)
VALUES (3, 'Marketing', NULL);

ALTER TABLE Department
ADD DesignationNew VARCHAR2(20);

UPDATE Department
SET DesignationNew = Designation;

SELECT Deptno, Deptname, Location, Designation
FROM Department;

UPDATE Department
SET Designation = 'Manager'
WHERE Deptno = 2;

UPDATE Department
SET Designation = NULL;

SELECT Deptno, Deptname, Location, Designation
FROM Department;

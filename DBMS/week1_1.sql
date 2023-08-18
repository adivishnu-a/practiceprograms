CREATE TABLE Employee (
    EmployeeID INT,
    Ename VARCHAR(20),
    Job VARCHAR(20),
    Mgr INT,
    Sal DECIMAL(10, 2),
    Commission DECIMAL(10, 2)
);

INSERT INTO Employee (EmployeeID, Ename, Job, Mgr, Sal, Commission)
VALUES (1, 'Adi', 'Manager', NULL, 5000000, NULL);

INSERT INTO Employee (EmployeeID, Ename, Job, Mgr, Sal, Commission)
VALUES (2, 'Bhargav', 'Assistant', 1, 3000000, NULL);

INSERT INTO Employee (EmployeeID, Ename, Job, Mgr, Sal, Commission)
VALUES (3, 'Charan', 'Clerk', 2, 400000, NULL);

ROLLBACK;

ALTER TABLE Employee
ADD PRIMARY KEY (EmployeeID);

ALTER TABLE Employee
MODIFY EmployeeID INT NOT NULL,
       Ename VARCHAR(20) NOT NULL,
       Job VARCHAR(20) NOT NULL,
       Sal DECIMAL(10, 2) NOT NULL;

INSERT INTO Employee (EmployeeID, Ename, Job, Sal)
VALUES (4, 'Dhanush', NULL, 250000);

INSERT INTO Employee (EmployeeID, Ename, Job, Sal)
VALUES (5, 'Fahad', 'Manager', NULL);

ALTER TABLE Employee
ADD CommissionNew DECIMAL(10, 2);

UPDATE Employee
SET CommissionNew = Commission;

ALTER TABLE Employee
DROP COLUMN Commission;

ALTER TABLE Employee
CHANGE COLUMN EmployeeID Empno INT;

DELETE FROM Employee
WHERE Empno = 1;

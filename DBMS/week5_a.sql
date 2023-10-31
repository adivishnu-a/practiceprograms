SET FOREIGN_KEY_CHECKS = 0; 
START TRANSACTION; 
INSERT INTO DEPARTMENT (Dname, Dnumber, Mgrssn, Mgr_start_date) 
VALUES ('New Department', 100, 'ManagerSSN', '2023-10-10'); 
INSERT INTO EMPLOYEE (Fname, Minit, Lname, Ssn, Bdate, Address, Sex, Salary, Dno) 
VALUES ('ARSHAD', 'A', 'SHAIK', '111-12-1111', '1990-01-01', '123 Main St', 'M', 60000, 100); 
COMMIT; 
SET FOREIGN_KEY_CHECKS = 1;
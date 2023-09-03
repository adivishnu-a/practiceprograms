CREATE TABLE Employees1 ( 
 EmployeeID INT NOT NULL PRIMARY KEY, 
 EmployeeName VARCHAR(50) NOT NULL, 
 DepartmentID INT NOT NULL, 
 JobTitle VARCHAR(50) NOT NULL, 
 Salary INT NOT NULL 
); 
INSERT INTO employees1 (EmployeeID,Employeename,DepartmentID,JobTitle,Salary) 
VALUES (101,'Adi',10,'Manager',20000), 
 (201,'Chiru', 20,'Reporter',5800), 
 (301,'Ritika',20,'Reporter',10050), 
 (401,'Anjali',50,'Reader',5500), 
 (501,'Narasimha',20, 'Reader',4900), 
 (601,'Prasanna',55,'Clerk', 2000), 
 (701,'Jawad',95,'Analyst', 7000); 
select *from employees1;

SELECT COUNT(*) AS TotalEmployees 
FROM Employees1 
WHERE DepartmentID = 20; 

SELECT MIN(Salary) AS MinimumSalary 
FROM Employees1 
WHERE JobTitle = 'CLERK'; 

SELECT MIN(Salary) AS MinimumSalary, 
 MAX(Salary) AS MaximumSalary, 
 ROUND(AVG(Salary), 2) AS AverageSalary 
FROM Employees1; 

SELECT JobTitle, 
 MIN(Salary) AS MinimumSalary, 
 MAX(Salary) AS MaximumSalary 
FROM Employees1 
GROUP BY JobTitle;

SELECT EmployeeName 
FROM Employees1 
ORDER BY EmployeeName DESC; 

SELECT EmployeeID, EmployeeName 
FROM Employees1 
ORDER BY EmployeeID ASC;
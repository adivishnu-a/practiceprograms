CREATE TABLE employee_data ( 
 eid INT PRIMARY KEY, 
 emp_name VARCHAR(50), 
 salary DECIMAL(10, 2), 
 deptno VARCHAR(10), 
 manager_id INT 
); 
INSERT INTO employee_data (eid, emp_name, salary, deptno, manager_id) VALUES 
 (1, 'Adi', 50000.00, '01', NULL), 
 (2, 'Chiru', 60000.00, '02', 1), 
 (3, 'Ritika', 75000.00, '01', NULL), 
 (4, 'Anjali', 55000.00, '02', 1), 
 (5, 'Jawad', 80000.00, '03', 3), 
 (6, 'Prasanna', 45000.00, '01', NULL), 
 (7, 'Narasimha', 70000.00, '03', 3), 
 (8, 'Varshita', 62000.00, '02', 1), 
 (9, 'Deepika', 57000.00, '02', 1), 
 (10, 'Srinivas', 48000.00, '03', 3); 
 
SELECT * FROM employee_data; 

SELECT CONCAT(SUBSTRING(emp_name, 1, 2), SUBSTRING(emp_name, 7)) AS combined_string 
FROM employee_data; 

SELECT emp_name, salary, salary * 1.15 AS increased_salary 
FROM employee_data;

SELECT manager_id, MIN(salary) AS lowest_salary 
FROM employee_data 
GROUP BY manager_id;

SELECT deptno, AVG(salary) AS avg_salary 
FROM employee_data 
GROUP BY deptno;

SELECT deptno, AVG(salary) AS avg_salary 
FROM employee_data 
GROUP BY deptno 
HAVING COUNT(*) > 2;

SELECT eid, AVG(salary) AS avg_salary 
FROM employee_data 
WHERE deptno = '03' 
GROUP BY eid; 
SELECT eid, AVG(salary) AS avg_salary 
FROM employee_data 
WHERE deptno = '05' 
GROUP BY eid;
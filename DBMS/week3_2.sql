CREATE TABLE employees ( 
 id INT AUTO_INCREMENT PRIMARY KEY, 
 name VARCHAR(255), 
 job_title VARCHAR(255), 
 department_id INT, 
 salary DECIMAL(10,2), 
 date_of_birth DATE 
); 
INSERT INTO employees (name, job_title, department_id,date_of_birth, salary) 
VALUES ('Adi', 'Chairman',10, '2004-01-31',2000000), 
 ('Chiru', 'Director',20, '2003-08-22', 1500000), 
 ('Jawad', 'President',20, '2003-09-20', 1500000), 
 ('Narasimha', 'Board Member',30, '2003-09-01', 1400000),
 ('Prasanna Kumar', 'Board Member',30, '2003-09-01', 1300000), 
 ('Srinivas', 'Manager',30, '2004-05-27', 1200000),
 ('Varshita', 'Manager',30, '2004-09-07', 804000);
select * from employees;

SELECT job_title, AVG(salary) AS avg_salary 
FROM employees 
GROUP BY job_title;

SELECT job_title, AVG(salary) AS avg_salary 
FROM employees 
WHERE job_title != 'Manager' 
GROUP BY job_title;

SELECT department_id, AVG(salary) AS avg_salary 
FROM employees 
GROUP BY department_id 
HAVING COUNT(*) > 1; 
SELECT department_id, AVG(salary) AS avg_salary 
FROM employees 
GROUP BY department_id 
HAVING COUNT(*) > 3;

SELECT e1.* 
FROM employees e1 
JOIN (SELECT MIN(salary) AS min_salary FROM employees WHERE department_id = 30) e2 
ON e1.salary > e2.min_salary; 

SELECT name, salary, SIGN(salary - 5000) AS sign_of_difference 
FROM employees;

SELECT name, DATEDIFF(CURDATE(), date_of_birth) AS days_since_birth 
FROM employees;

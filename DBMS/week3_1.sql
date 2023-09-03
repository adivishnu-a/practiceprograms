create table emp( 
empno int not null, 
ename varchar(20), 
deptno int not null, 
sal int not null 
); 
alter table emp 
add primary key (empno); 
create table dept( 
deptno int not null, 
dname varchar(20) not null 
); 
alter table dept 
add primary key(deptno); 

INSERT INTO dept (deptno, dname) 
VALUES 
 (10, 'Accounting'), 
 (20, 'Research'), 
 (30, 'Sales'), 
 (40, 'Marketing'); 
select *from dept; 

INSERT INTO emp (empno, ename, deptno, sal) 
VALUES 
 (1, 'Chiru', 10, 5000), 
 (2, 'Adi', 20, 5500), 
 (3, 'Bob Brown', 20, 6000), 
 (4, 'Anjali', 30, 4800), 
 (5, 'Charlie Davis', 30, 5200), 
 (6, 'David Wilson', 10, 5100), 
 (7, 'Ritika', 40, 4900), 
 (8, 'Srinivas', 40, 5300), 
 (9, 'Varshita', 20, 5800), 
 (10, 'Prasanna', 30, 4700); 
select *from emp; 

SELECT ename, AVG(sal) AS avg_salary 
FROM emp 
WHERE deptno = 10 
GROUP BY ename; 

SELECT e.*, d.dname 
FROM emp e 
INNER JOIN dept d ON e.deptno = d.deptno 
WHERE (e.deptno, e.sal) IN ( 
 SELECT deptno, MIN(sal) 
 FROM emp 
 GROUP BY deptno 
);

SELECT deptno, COUNT(*) AS num_employees 
FROM emp 
GROUP BY deptno;

SELECT d.dname AS department_name, COUNT(e.empno) AS num_employees
FROM dept d
LEFT JOIN emp e ON d.deptno = e.deptno
GROUP BY d.dname, d.deptno;

SELECT * 
FROM emp 
WHERE ename LIKE 'B%' OR ename LIKE 'C%'; 

SELECT ename 
FROM emp 
WHERE sal >= 5000; 

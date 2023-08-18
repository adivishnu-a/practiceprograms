create table employee(
empno int,
ename varchar(20),
job varchar(20),
mgr int,
sal int
);

select * from employee;

INSERT INTO employee(empno,ename,job,mgr,sal)
values(1,'Adi','Manager',12,1000000),
(2,'Bhargav','Clerk',34,200000),
(3,'Satya','Assistant',56,300000);

rollback;

ALTER TABLE employee
ADD PRIMARY KEY (empno);

ALTER TABLE employee
modify column empno varchar(20) not null,
modify column ename varchar(20) not null,
modify column job varchar(20) not null,
modify column mgr int not null,
modify column sal int not null;

INSERT INTO employee(empno,ename,job,mgr,sal)
values(4,null,'Abdul',78,400000);

alter table employee
add column commission int;

SET SQL_SAFE_UPDATES = 0;

update employee set commission = 1000 where empno =1;
update employee set commission = 2000 where empno =2;
update employee set commission = 3000 where empno =3;
update employee set job = 'Chairman' where empno =1;
update employee set job = 'President' where empno =2;
update employee set job = 'Director' where empno =3;

alter table employee
rename column empno to empid;

delete from employee where empid=1;
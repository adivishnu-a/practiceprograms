create table sailor(
sid int,
sname varchar(20),
rating int,
age int);
begin;

insert into sailor 
values(1,'Adi',8,19),
(2,'Chiru',6,20),
(3,'Jawad',9,21);
commit;
select*from sailor;

savepoint after_insertion;
insert into sailor
values(4,'Srinivas',6,18);
commit;
select * from sailor;

alter table sailor add primary key(sid),modify sid int not null;

alter table sailor add column age_new int;

insert into sailor(sid,sname,rating,age,age_new)
values(5,'Mahesh',9,14,30),
(6,'Narasimha',7,19,28);

delete from sailor 
where rating>8;

update Sailor set Age=20 where Sid>5;

insert into Sailor 
values(7,null,10,null,22),(8,"Sivamani",null,23,null);

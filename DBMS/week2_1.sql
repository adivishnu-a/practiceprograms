create table branchtable(
branch_name int,
branch_city varchar(20),
asserts varchar(20)
);
describe branchtable;

alter table branchtable add primary key(branch_name);
create table feetable(
fee_id int,
student_name varchar(20)
);
alter table feetable add foreign key(fee_id) references branchtable(branch_name);
select *from branchtable;
describe branchtable;

alter table branchtable modify asserts varchar(50);

alter table branchtable add phone_number varchar(20);
alter table branchtable drop column phone_number;

insert into branchtable(branch_name,branch_city,asserts)
values(1,'Guntur','Welcome'),(2,'Vijayawada','Novotel');

set sql_safe_updates=0;
update branchtable set branch_name=4 where asserts="Novotel";
describe branchtable;

alter table branchtable drop column branch_city,drop column asserts;

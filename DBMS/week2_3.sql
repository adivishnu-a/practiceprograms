create table reverse_table(
boat_id int,
sid varchar(20),
day varchar(20)
);
describe reverse_table;

create table reverse_table1(
fees_id int primary key,
student_name varchar(20) not null
);
select*from reverse_table;
alter table reverse_table
add primary key(boat_id);
alter table reverse_table1
add foreign key(fees_id)references reverse_table(boat_id);

insert into reverse_table
(boat_id,sid,day)
values
(1,'Adi','Monday'),
(2,'Chiru','Tuesday'),
(3,'Mahesh','Wdnesday');

alter table reverse_table
add column time int;

alter table reverse_table modify day date;

alter table reverse_table
drop column time;

delete from reverse_table
where boat_id=3;
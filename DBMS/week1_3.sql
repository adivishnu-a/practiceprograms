CREATE TABLE Customer (
    Cust_id NUMBER,
    Cust_name VARCHAR2(20),
    Cust_street VARCHAR2(20),
    Cust_city VARCHAR2(20)
);

ALTER TABLE Customer
ADD CONSTRAINT PK_Customer PRIMARY KEY (Cust_id);

INSERT INTO Customer (Cust_id, Cust_name, Cust_street, Cust_city)
VALUES (1, 'Aditya', '123 Street', 'Bangalore');
INSERT INTO Customer (Cust_id, Cust_name, Cust_street, Cust_city)
VALUES (2, 'Bhargav', '456 Street', 'Hyderabad');

ALTER TABLE Customer
ADD Salary DECIMAL(10, 2);

ALTER TABLE Customer
MODIFY Cust_street VARCHAR2(50);

ALTER TABLE Customer
DROP COLUMN Salary;

DELETE FROM Customer
WHERE Cust_city = 'Hyderabad';

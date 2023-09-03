CREATE TABLE vendors ( 
 vendor_id INT PRIMARY KEY, 
 vendor_name VARCHAR(50), 
 vendor_type VARCHAR(20) 
); 
INSERT INTO vendors (vendor_id, vendor_name, vendor_type) VALUES 
 (1, 'Vendor A', 'Local'), 
 (2, 'Vendor B', 'Non Local'), 
 (3, 'Vendor C', 'Local'), 
 (4, 'Vendor D', 'Non Local'); 
CREATE TABLE products ( 
 product_id INT PRIMARY KEY, 
 product_name VARCHAR(50), 
 product_type VARCHAR(20), 
 vendor_id INT, 
 order_date DATE, 
 cost DECIMAL(10, 2), 
 FOREIGN KEY (vendor_id) REFERENCES vendors(vendor_id) 
); 
INSERT INTO products (product_id, product_name, product_type, vendor_id, order_date, cost) 
VALUES 
 (1, 'Part 1', 'Assembled', 1, '2023-01-15', 100.00), 
 (2, 'Part 2', 'Sub', 2, '2023-02-20', 50.00), 
 (3, 'Part 3', 'Assembled', 1, '2023-03-10', 150.00), 
 (4, 'Part 4', 'Sub', 3, '2023-04-05', 60.00), 
 (5, 'Part 5', 'Sub', 2, '2023-05-08', 70.00), 
 (6, 'Part 6', 'Assembled', 4, '2023-06-20', 120.00), 
 (7, 'Part 7', 'Sub', 1, '2023-07-25', 80.00), 
 (8, 'Part 8', 'Assembled', 2, '2023-08-10', 180.00); 
SELECT * FROM vendors; 
SELECT * FROM products;

SELECT DISTINCT v.vendor_name 
FROM vendors v 
JOIN products p ON v.vendor_id = p.vendor_id 
WHERE p.order_date >= DATE_SUB(NOW(), INTERVAL 6 MONTH); 

SELECT v.* 
FROM vendors v 
JOIN products p ON v.vendor_id = p.vendor_id 
WHERE p.product_type IN ('Assembled', 'Sub') 
GROUP BY v.vendor_id 
HAVING COUNT(DISTINCT p.product_type) = 2;

SELECT v.vendor_type, p.product_name 
FROM vendors v 
JOIN products p ON v.vendor_id = p.vendor_id 
WHERE p.product_type = 'Sub' 
ORDER BY v.vendor_type; 

SELECT * 
FROM vendors 
ORDER BY vendor_name ASC;

SELECT ps.product_name 
FROM products ps 
WHERE ps.product_type = 'Sub' AND ps.cost > (SELECT MAX(pa.cost) FROM products pa WHERE 
pa.product_type = 'Assembled');

SELECT p.product_name 
FROM products p 
WHERE p.product_type = 'Assembled' 
ORDER BY p.cost DESC 
LIMIT 1 OFFSET 1;

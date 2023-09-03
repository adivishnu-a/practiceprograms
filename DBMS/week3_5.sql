CREATE TABLE Sailors ( 
 sid INT NOT NULL PRIMARY KEY, 
 sname VARCHAR(50) NOT NULL, 
 age INT NOT NULL, 
 rating INT NOT NULL 
); 
INSERT INTO Sailors VALUES 
 (624,'Adi',20,9), 
 (499,'Chiru',21,9), 
 (538,'Ritika',25,8), 
 (526,'Srinu',19,6), 
 (540,'Varshita',21,4), 
 (539,'Deepika',27,6), 
 (324,'Harry',16,8), 
 (508,'Maruthi',25,4), 
 (400,'Mahesh',17,10); 
CREATE TABLE Boats ( 
 bid INT NOT NULL PRIMARY KEY, 
 bname VARCHAR(50) NOT NULL, 
 color VARCHAR(50) NOT NULL 
); 
INSERT INTO Boats (bid, bname, color) VALUES 
 (101, 'INTERLAKE', 'red'), 
 (102, 'SURFSIDE', 'blue'), 
 (103, 'BAYLINER', 'green'), 
 (104, 'KAYAK', 'red'); 
CREATE TABLE Reserves ( 
 sid INT NOT NULL, 
 bid INT NOT NULL, 
 reservation_date DATE, 
 FOREIGN KEY (sid) REFERENCES Sailors(sid), 
 FOREIGN KEY (bid) REFERENCES Boats(bid) 
); 
INSERT INTO Reserves VALUES 
 (624, 101, '2023-08-25'), 
 (499, 101, '2023-08-26'), 
 (538, 102, '2023-08-27'), 
 (526, 101, '2023-08-28'), 
 (540, 103, '2023-08-29'), 
 (539, 101, '2023-08-30'), 
 (324, 104, '2023-08-31'), 
 (508, 102, '2023-09-01'), 
 (400, 103, '2023-09-02'); 
 select * from Boats; 
 select * from Reserves; 
 select * from Sailors; 

 SELECT s.sid, s.sname 
FROM Sailors s 
WHERE (SELECT COUNT(DISTINCT b.bid) 
 FROM Boats b WHERE b.bname = 'INTERLAKE') = 
 (SELECT COUNT(DISTINCT r.bid) 
 FROM Reserves r WHERE r.sid = s.sid AND r.bid IN 
 (SELECT b.bid FROM Boats b WHERE b.bname = 'INTERLAKE')); 

 SELECT s.sname, r.bid, r.reservation_date 
FROM Sailors s 
JOIN Reserves r ON s.sid = r.sid;  

SELECT age 
FROM Sailors 
WHERE sname LIKE 'H%y' AND LENGTH(sname) >= 3; 

SELECT DISTINCT s.sname 
FROM Sailors s 
JOIN Reserves r ON s.sid = r.sid 
JOIN Boats b ON r.bid = b.bid 
WHERE b.color = 'red' 
ORDER BY s.sname;

SELECT rating, MIN(age) AS youngest_age 
FROM Sailors 
GROUP BY rating; 
SELECT s.sName
FROM Suppliers s
JOIN Catalog c ON s.sid = c.sid
GROUP BY s.sName
HAVING COUNT(c.pid) >= 2;
-- SQL queries for generating reports
SELECT members.mname AS MemberName, COUNT(transactions.tid) AS BooksBorrowed
FROM members
LEFT JOIN transactions ON members.mid = transactions.mid
GROUP BY members.mname;
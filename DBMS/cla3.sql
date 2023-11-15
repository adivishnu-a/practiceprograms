SELECT
    ord_date,
    salesperson_id,
    COUNT(*) AS order_count
FROM
    orders
GROUP BY
    ord_date,
    salesperson_id;

SELECT TRUNCATE(P.PRICE / 10000, 0) * 10000 AS PRICE_GROUP, COUNT(*) AS PRODUCTS
FROM PRODUCT P
GROUP BY PRICE_GROUP
ORDER BY PRICE_GROUP ASC;
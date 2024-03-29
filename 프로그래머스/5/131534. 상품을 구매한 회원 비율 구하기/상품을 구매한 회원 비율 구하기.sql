SELECT EXTRACT(YEAR FROM O.SALES_DATE) AS YEAR, 
       EXTRACT(MONTH FROM O.SALES_DATE) AS MONTH, 
       COUNT(DISTINCT O.USER_ID) AS PURCHASED_USERS, 
       ROUND(COUNT(DISTINCT O.USER_ID) / 
             (SELECT COUNT(USER_ID)
              FROM USER_INFO U
              WHERE EXTRACT(YEAR FROM U.JOINED) = '2021'), 1) AS PURCHASED_RATIO
FROM ONLINE_SALE O
INNER JOIN USER_INFO U ON O.USER_ID = U.USER_ID
WHERE EXTRACT(YEAR FROM U.JOINED) = '2021'
GROUP BY EXTRACT(YEAR FROM O.SALES_DATE), EXTRACT(MONTH FROM O.SALES_DATE)
ORDER BY YEAR, MONTH;
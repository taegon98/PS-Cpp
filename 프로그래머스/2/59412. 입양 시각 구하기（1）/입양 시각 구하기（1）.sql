SELECT HOUR(A.DATETIME) AS HOUR, COUNT(*) AS COUNT
FROM ANIMAL_OUTS A
WHERE HOUR(A.DATETIME) BETWEEN 9 AND 19
GROUP BY HOUR
ORDER BY HOUR ASC;
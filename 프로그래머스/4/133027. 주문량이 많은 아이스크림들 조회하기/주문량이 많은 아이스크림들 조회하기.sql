SELECT FLAVOR
FROM (
    SELECT J.FLAVOR, SUM(J.TOTAL_ORDER + F.TOTAL_ORDER) AS TOTAL
    FROM JULY J
    INNER JOIN FIRST_HALF F ON J.FLAVOR = F.FLAVOR
    GROUP BY J.FLAVOR
    ORDER BY TOTAL DESC
)
WHERE ROWNUM <= 3;
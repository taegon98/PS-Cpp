SELECT COUNT(*) AS FISH_COUNT
FROM FISH_INFO AS F
WHERE DATE_FORMAT(F.TIME, '%Y') = 2021


SELECT D.ID, D.EMAIL, D.FIRST_NAME, D.LAST_NAME
FROM DEVELOPER_INFOS AS D
WHERE D.SKILL_1 = 'Python' OR D.SKILL_2 = 'Python' OR D.SKILL_3 = 'Python'
ORDER BY D.ID ASC;
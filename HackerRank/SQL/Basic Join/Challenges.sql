
SELECT H.HACKER_ID, H.NAME, T.CNT
FROM HACKERS AS H,
(
    SELECT H1.HACKER_ID,
    COUNT(C1.CHALLENGE_ID) AS CNT
    FROM HACKERS AS H1 JOIN CHALLENGES AS C1
    WHERE H1.HACKER_ID = C1.HACKER_ID
    GROUP BY H1.HACKER_ID
)AS T,
(
    SELECT T2.CNT,COUNT(*) AS COUNTER1 
    FROM 
    (
        SELECT COUNT(C1.CHALLENGE_ID) AS CNT
        FROM HACKERS AS H1 JOIN CHALLENGES AS C1
        WHERE H1.HACKER_ID = C1.HACKER_ID
        GROUP BY H1.HACKER_ID
    )AS T2 
    GROUP BY CNT
) AS T3,
(
    SELECT MAX(T2.CNT) AS MAXEP
    FROM 
    (
        SELECT COUNT(C1.CHALLENGE_ID) AS CNT
        FROM HACKERS AS H1 JOIN CHALLENGES AS C1
        WHERE H1.HACKER_ID = C1.HACKER_ID
        GROUP BY H1.HACKER_ID
    )AS T2 
)AS T4
WHERE T.HACKER_ID = H.HACKER_ID AND T3.CNT=T.CNT AND (T.CNT>=T4.MAXEP OR T3.COUNTER1=1)
ORDER BY T.CNT DESC, H.HACKER_ID;

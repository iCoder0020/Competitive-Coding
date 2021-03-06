-- ID: iCoder0020
-- PROG: Ollivander's Inventory
-- LANG: SQL                

SELECT W.ID, WP.AGE, T1.MIN_COINS, W.POWER
FROM WANDS AS W JOIN WANDS_PROPERTY AS WP ,
(
	SELECT W1.CODE, W1.POWER, MIN(W1.COINS_NEEDED) AS MIN_COINS 
	FROM WANDS AS W1 

	GROUP BY W1.CODE, W1.POWER
)AS T1
WHERE W.CODE = WP.CODE AND WP.IS_EVIL = 0 AND W.CODE = T1.CODE AND W.POWER = T1.POWER
ORDER BY W.POWER DESC, WP.AGE DESC;

(SELECT * FROM (SELECT * FROM WANDS_PROPERTY WHERE IS_EVIL=0) AS T1 LEFT JOIN WANDS ON T1.CODE = WANDS.CODE )
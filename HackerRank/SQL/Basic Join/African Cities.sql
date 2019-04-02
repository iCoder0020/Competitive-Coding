-- ID: iCoder0020
-- PROG: African Cities
-- LANG: SQL                

SELECT SUM(CITY.POPULATION) 
FROM CITY JOIN COUNTRY
WHERE CITY.COUNTRYCODE = COUNTRY.CODE AND COUNTRY.CONTINENT = 'ASIA'
GROUP BY COUNTRY.CONTINENT;
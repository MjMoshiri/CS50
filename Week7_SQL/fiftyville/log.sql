



--getting the reprot
SELECT * FROM crime_scene_reports
WHERE year =2020 and day = 28 and month = 7 and street ='Chamberlin Street';

--getting the interviews
SELECT * FROM interviews
WHERE year =2020 and day = 28 and month = 7;

--base on the Eugene's interview finding all the people who had a withdraw that day.
SELECT * FROM people
WHERE id IN (SELECT person_id FROM bank_accounts
WHERE account_number IN (
SELECT account_number FROM atm_transactions
WHERE  atm_location = 'Fifer Street'
and year =2020 and day = 28 and month = 7 and transaction_type = 'withdraw'));

--getting the tomorrow earliest flights passengers base on Raymond's interview
SELECT *FROM people WHERE passport_number in (
SELECT passport_number FROM passengers WHERE flight_id =(
SELECT id FROM flights WHERE origin_airport_id = (
SELECT id FROM airports WHERE city = 'Fiftyville')
and year = 2020 and day = 29 and month = 7
ORDER BY hour limit 1))  ;

-- make a suspects table for investigating more easily which is the people who where in the tomorrow earliest flight and also had a withdraw earlier this day
CREATE TABLE suspects AS
SELECT * FROM people
WHERE id IN (SELECT person_id FROM bank_accounts
WHERE account_number IN (
SELECT account_number FROM atm_transactions
WHERE  atm_location = 'Fifer Street'
and year =2020 and day = 28 and month = 7 and transaction_type = 'withdraw'))
INTERSECT
SELECT *FROM people WHERE passport_number in (
SELECT passport_number FROM passengers WHERE flight_id =(
SELECT id FROM flights WHERE origin_airport_id = (
SELECT id FROM airports WHERE city = 'Fiftyville')
and year = 2020 and day = 29 and month = 7
ORDER BY hour limit 1));

--fnding the suspects that are recorded by courthouse_security
SELECT name FROM courthouse_security_logs
JOIN suspects ON suspects.license_plate = courthouse_security_logs.license_plate
WHERE year =2020 and  day = 28 and  month =7 and hour =10 and minute >15 and minute <26;


--getting the disired calls
SELECT suspects.name FROM phone_calls
JOIN suspects ON caller = suspects.phone_number
WHERE caller IN (SELECT phone_number FROM suspects)
AND year= 2020 and day =28 and month = 7 and duration < 60 ;

--intersecting part together to find the thief
SELECT name FROM courthouse_security_logs
JOIN suspects ON suspects.license_plate = courthouse_security_logs.license_plate
WHERE year =2020 and  day = 28 and  month =7 and hour =10 and minute >15 and minute <26
INTERSECT
SELECT suspects.name FROM phone_calls
JOIN suspects ON caller = suspects.phone_number
WHERE caller IN (SELECT phone_number FROM suspects)
AND year= 2020 and day =28 and month = 7 and duration < 60 ;

-- finding the partner
SELECT name from people WHERE phone_number IN (
SELECT receiver FROM phone_calls
JOIN suspects ON caller = suspects.phone_number
WHERE name ='Ernest'
AND year= 2020 and day =28 and month = 7 and duration < 60) ;


--finding the destination
SELECT city FROM flights
JOIN airports ON airports.id = destination_airport_id
WHERE origin_airport_id = (
SELECT airports.id FROM airports WHERE city = 'Fiftyville')
and year = 2020 and day = 29 and month = 7
ORDER BY hour limit 1;

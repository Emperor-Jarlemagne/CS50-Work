-- Keep a log of any SQL queries you execute as you solve the mystery.
-- First Query to establish what the crime was (Duck Stolen at 10.15AM)
SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = 'Humphrey Street';
--Interviews with witnesses (Thief left bakery w/in 10 minutes, Early morning ATM withdrawal, Thief left fiftyville next day early, phone call with accomplice)
SELECT transcript FROM interviews WHERE month = 7 AND day = 28;
--Try and see who called their friend about plane tickets (also unhelpful)
SELECT id, caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28;
-- Identify all callers with calls that morning under a minute(Sofia, Kelsey, Bruce, Kathyrn, Kelsey, Taylor, Diana, Carina, Kenny, Benista)
SELECT name, phone_calls.duration FROM people
    JOIN phone_calls ON people.phone_number = phone_calls.caller
    WHERE year = 2021 AND month = 7 AND day = 28 AND duration <= 60;
--Try and see who took money out that morning on Leggett Street
SELECT account_number, amount FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';
--Identify Names of People who took out withdrawls on Leggett St that morning (Bruce, Diana, Brooke, Kenny, Iman, Luca, Taylor, Benista)
SELECT name FROM people
    JOIN bank_accounts ON people.id = bank_accounts.person_id
    JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
    WHERE year = 2021 AND month = 7 AND day = 28 and atm_location = 'Leggett Street' AND transaction_type = 'withdraw';
--Cross Reference names of ATM withdrawals and phone calls under a minute = Bruce, Diana, Taylor, Kenny, Benista
-- See who entered cafe at that time (unhelpful)
SELECT activity FROM bakery_security_logs WHERE year = 2021 AND month = 7 and DAY = 28 AND hour = 10;
-- License Plates of cars that left w/in ten minutes of crime (Vanessa, Bruce, Barry, Luca, Sofia, Iman, Diana, Kelsey)
SELECT name FROM people
    JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
    WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25;
--Cross Reference names again: Bruce, Diana
--Find first flight out of fiftyville next day (Earliest Flight is LaGuardia - New York @ 8.20)
SELECT flights.id, full_name, city, flights.hour, flights.minute FROM airports
    JOIN flights ON airports.id = flights.destination_airport_id
    WHERE year = 2021 AND month = 7 AND day = 29;
--Find passengers on New York Flight (Flight_id 36: Doris, Sofia, Bruce, Edward, Kelsey, Taylor, Kenny, Luca)
SELECT passengers.flight_id, name, passengers.passport_number FROM people
    JOIN passengers ON people.passport_number = passengers.passport_number
    JOIN flights ON passengers.flight_id = flights.id
    WHERE year = 2021 AND month = 7 AND day = 29;
-- Cross Reference names again: BRUCE! Bruce is the thief
--Find out who Bruce was talking on the phone to (id: 233 Bruce: (367) 555-5533 - Duration: 45s Receiver: (375) 555-8161)
SELECT id, caller, receiver FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration = 45;
--Identify Receiver - Robin! Robin is the Accomplice
SELECT name FROM people WHERE phone_number = '(375) 555-8161';

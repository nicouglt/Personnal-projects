# Snack dispenser

### A Dispenser for dogs that distributes a defined amount of food two times a day (morning and afternoon)


# How it works
This dispenser works with a RTC module (DS3231) and a stepper motor (NEMA 17). we also have some other components like S-M drivers and voltage converters
### Features <br>
  + Dispense a defined amount of dog food two times a day (8:00 AM and 6:00PM by default)
  + Dispense dog food while the user push the button
  + Set the new time of distribution when the user push the button two times (before 12:00 AM the morning distribution time will be replaced, after 14:00PM, the afternoon distribution time will be replaced)

### Components <br>
  + Arduino UNO R3
  + Stepper motor NEMA 17
  + Driver for Stepper motor A4988
  + Real-Time Clock Module DS3231
  + LM2596 DCDC Adapter (convert voltage from 12V to 5V)
  + 1x LED
  + 1x push button
  + 1x 100µF capacitor
  + 1x 1kOhm resistance
  + a lot of jumpers

### Connections

# Fire_System_Embedded_Proj
This project serves to detect elevated temperature and smoke, determining whether to activate the fan or initiate system lockdown, accessible only with the correct password. Indicators display high temperature or smoke, and a reset password button allows real-time password changes.
<br>
<br>

# System Status:
## Normal Operation:
### The features:
#### The indiecators will be off. 
#### The fan will be off.
## Heat Status:
### The features:
#### The heat indicator will be on . 
#### The the fan will be operated.
## System off:
### The features:
#### The system off indicator will be on . 
#### The fan will be operated.
#### The system not be back without the smoke decrese and also enter the system password.
<br>
<br>

# Technical Features:
## It consists of AVR (atmega32), Button, temperature sensor (LM35), Smoke sensor (MPX4115), DC-MOTOR, Two LEDs (Orange - yellow), Internal EEPROM, and Keypad.
## In case of the temperature is higher than 45°c and the smoke is less than 50, the system will be in heat mode and the yellow led and the MOTOR will run.
## In case of the temperature is higher than 45°c or less than 40°c and the smoke is higher than 50, the system will be in fire mode and the Red led and the MOTOR will run. Also, the system will shutdown and can't open again. The user is requested to write the password to open the system again.
## Internal EEPROM is used to save the password and enable to change of the password at any time.

# The project simulation:
<img src="https://github.com/msayed6789/Smart_Home_Embedd_Project/blob/main/Photos/smart%20home.PNG" width=100%>
[![Watch the video](https://github.com/msayed6789/Smart_Home_Embedd_Project/blob/main/Photos/smart%20home.PNG)]().
<br>
<br>

# To contact Developer:
## [LinkedIn](https://www.linkedin.com/in/mohamed-sayed-740b44203/)



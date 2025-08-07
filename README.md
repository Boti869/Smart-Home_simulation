# Smart Home Simulation

A C-language simulation of a smart home system with:
- Motion detection
- Gas leak detection and automated safety protocol
- Dynamic indoor temperature and window/fan management
- Automatic logging to timestamped files

## Features
- Randomized simulation of a 10-room house
- Seasonal and weather-based behavior
- Emergency response with file logging in `gas_logs/`

🌡 Temperature Control – Automatic heating and fan management.

💨 Gas Leak Detection – High/Extreme levels trigger safety protocols and create a log file.

🔦 Lighting & Motion – Lights turn on/off based on motion detection and light levels.

🌤 Outdoor Environment Simulation – Weather, wind speed, and temperature affect indoor behavior.

🪟 Smart Shades & Windows – Automatically open/tilt/close depending on sunlight and temperature.

📁 Gas Alert Logs – Generates timestamped logs in the gas_logs/ folder when a leak occurs.
|->  All rooms are put into emergency mode.
|->  A file: GAS_ALERT_year_month_day_hour-min-sec.txt is created in the gas_logs/ folder.

## TO COMPILE: 
Use GCC (MinGW/MSYS2 on Windows):
- gcc main.c helper_c_files/*.c -o smart_home  <-- compile into smart_home.exe
- smarthome.exe  <-- to run the program


 ### Licence
 This project is licensed under the MIT License – see LICENSE for details.

(basically means you can do whatever you want with it. 
-BUT YOU HAVE TO INCLUDE MY LICENCE IN IT 
I just realised that if I don't licence you *legally* can't do anything to it)

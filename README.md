# Smart Home Simulation in C
A C-based smart home simulation that monitors and reacts to the environmental aka.: temperature, gas leaks, motion detection, and outdoor conditions.
It controls heating, fans, lights, windows, and shades automatically to simulate a realistic smart home system.

Features:
🌡 Temperature Control – Automatic heating and fan management.

💨 Gas Leak Detection – High/Extreme levels trigger safety protocols and create a log file.

🔦 Lighting & Motion – Lights turn on/off based on motion detection and light levels.

🌤 Outdoor Environment Simulation – Weather, wind speed, and temperature affect indoor behavior.

🪟 Smart Shades & Windows – Automatically open/tilt/close depending on sunlight and temperature.

📁 Gas Alert Logs – Generates timestamped logs in the gas_logs/ folder when a leak occurs.
|->  All rooms are put into emergency mode.
|->  A file: GAS_ALERT_year_month_day_hour-min-sec.txt is created in the gas_logs/ folder.

TO COMPILE: 
Use GCC (MinGW/MSYS2 on Windows):
gcc main.c rooms.c outdoors.c setup.c updates.c helper.c house.c -o main.exe -Wall -g
./smarthome.exe

This project is licensed under the MIT License – see LICENSE for details.

(basically means you can do whatever you want with it. 
I just realised that if I don't licence you *legally* can't do anything to it)

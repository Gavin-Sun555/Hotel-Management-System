# Hotel Management System Beta 0.0.2 (2026-07-16)

## About

This is my first C project as a freshman student at [University of Michigan-Shanghai Jiao Tong University Joint Institute](http://umji.sjtu.edu.cn/). To be honest, the code style of this project is not good and there are some bugs and perhaps some memory leaks in this project. It is posted to record the starting point of my coding career. Future modifications may be made. Following is the original README written at that time. I transferred the original txt file into markdown to make it easier to read.

## Compiling and Quick Start


The project uses CMake, and we have provided a `Makefile` wrapper to make compiling, running, and cleaning as simple as possible.

### Option 1: Using the Makefile (Recommended / Easiest)
You can build, run, or clean the project with these commands:
* **Build**: `make`
* **Run**: `make run`
* **Clean**: `make clean`

### Option 2: Using Modern CMake Commands
If you prefer to run CMake directly without using `make`:
```bash
# Configure and build the project
cmake -B build
cmake --build build

# Run the program
./build/Hotel-Management-System
```

### Option 3: Manual Compilation with GCC
You can also compile it in a single command using GCC:
```bash
gcc -Wall -pedantic -Werror -Wno-unused-result -DNDEBUG -std=c11 -o hotel hotel-main.c hotel-mt.c hotel-db.c hotel-ll.c -lm
```

If you use an IDE like JetBrains CLion or VS Code, it can configure and compile with a single click.


## User Guide

### 1. System Initialization
Upon starting the program, it automatically initializes a fixed-size hotel database (`hotel.db`) containing single, double, family, and dorm rooms. Wait for the `SYSTEM INITIALIZED SUCCESSFULLY` message before proceeding.

### 2. Daily Operations
The program operates as a real-time interactive management system. It automatically pulls the system's real date, which is displayed on the main menu.
- **Check-outs:** At the start of the program, the system will automatically parse the database and check-out any visitors whose scheduled departure date has arrived today. You can manually re-trigger check-outs for the current day from the menu.
- **Check-ins:** You can manually check in guests by selecting the Check-In option on the menu. The system will prompt you for room type, guest names, IDs, deposits, and nights, before printing a beautiful check-in card and updating the database.

### 3. Managing Reservations
At any time from the main menu, you can modify the reservations of current guests (including dorm visitors):
- **Modify Reservation:** Choose option `3` from the main menu.
- **Enter Details:** You must provide the `Room Number` and the visitor's `ID` exactly as printed on their check-in card.
- **Update:** Enter the new total number of breakfasts and the new total number of nights. The system will automatically recalculate their total price.

### 4. Pricing Information
By default, the standard room rates are:
- **Single Room:** $60/night
- **Double Room:** $80/night
- **Family Room:** $100/night
- **Dorm Room:** $20/night per person
- **Breakfast Add-on:** $15/breakfast

These rates are fully customizable directly from the main menu by selecting Option `4. Adjust Room Rates`. The system stores customized rates in `rates.cfg`, ensuring they persist across program restarts.

### 5. Reporting and Searching
The main menu includes powerful reporting options to view real-time operations:
- **View Available Rooms (5):** Lists every unoccupied room (and available dorm beds) instantly.
- **View Checked-In Guests (6):** Lists all current occupants across the entire hotel.
- **Lookup Guest or Room (7):** Enter a name, ID, or room number to retrieve that reservation's complete details.

### 6. Database and Initialization
The system's database (`hotel.db`) persists automatically. If the file is deleted, or if you select Option `8. Factory Reset Database` from the main menu, the program will prompt you to enter the number of Single, Double, Family, and Dorm rooms you wish to construct, allowing you to dynamically adjust the total size of your hotel at any time.


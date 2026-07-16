# Hotel Management System Beta 0.0.1 (2018-07-18)

## About

This is my first C project as a freshman student at [University of Michigan-Shanghai Jiao Tong University Joint Institute](http://umji.sjtu.edu.cn/). To be honest, the code style of this project is not good and there are some bugs and perhaps some memory leaks in this project. It is posted to record the starting point of my coding career. Future modifications may be made. Following is the original README written at that time. I transferred the original txt file into markdown to make it easier to read.

## Compiling and Quick Start

### Compile on Linux and macOS

The project uses CMake, and we have provided a `Makefile` wrapper to make compiling, running, and cleaning as simple as possible.

#### Option 1: Using the Makefile (Recommended / Easiest)
You can build, run, or clean the project with these commands:
* **Build**: `make`
* **Run**: `make run`
* **Clean**: `make clean`

#### Option 2: Using Modern CMake Commands
If you prefer to run CMake directly without using `make`:
```bash
# Configure and build the project
cmake -B build
cmake --build build

# Run the program
./build/Hotel-Management-System
```

#### Option 3: Manual Compilation with GCC
You can also compile it in a single command using GCC:
```bash
gcc -Wall -pedantic -Werror -Wno-unused-result -DNDEBUG -std=c11 -o hotel hotel-main.c hotel-mt.c hotel-db.c hotel-ll.c -lm
```

If you use an IDE like JetBrains CLion or VS Code, it can configure and compile with a single click.

### Compile on Windows

On Windows, we recommend using the MinGW-w64 toolchain to compile it. JetBrains CLion or VS Code with the CMake tools extension is recommended.


## Basic Information

1. Firstly, with the function `initialMt`, I initialize the data in the database. In the current version, the size of the hotel is fixed and cannot be changed by users.
2. Then, I generate check-in visitors with random numbers and linked lists in the function `generateVisitors`. I use pointers to the structure to generate random names stored in my structure set.
3. Then with the check-in and check-out functions, visitors are able to check out. For most of the time, the check-out function works fairly well. But sometimes it may have some problems due to possible memory leaks. You may restart the program or try again. If there are still problems, please contact me.
4. The users are able to set the date and the span of dates. We can change the number of breakfasts and nights (not for dorm visitors yet). Just follow the prompts in the command line.
5. In this version, many basic functions are still not completed.
6. Though most parts of my program are lengthy — instead of using linked lists to read the data of every room, I chose to read and revise them directly. This causes my program to be extremely long. To make it more readable, comments are added for most parts. But there is no need to read them if the program runs fairly well.
7. With my functions `timeToNumber` and `numberToTime`, I am able to compare dates. This function accounts for leap years. Because I count the year from 0, the result number is fairly large. It could be changed to take 1970 as the start year, but some people may find it fun if more ancient years are supported.
8. The initial room prices are: Single $60, Double $80, Family $100, Breakfast $15.
9. The check-out used to work well before I rearranged them in the required order. But now it has various issues from time to time. I have spent plenty of time but cannot figure out where the issues are. It would be greatly appreciated if you find the mistakes.
10. Up to what I've tested, the check-in card and the receipt work fairly well.
11. Though I actually did not write this project well, I still learned a lot during the process. I learned to handle pointers better and gained a deep understanding of them. I also practiced the usage of structures. Moreover, after failing to deal with time using `<time.h>` (which is absolutely possible), I chose to use my own function to do the job of adding a day. Though it seems unnecessary, it works fairly well.
12. More information is written in comments in the program.

## Future Improvement

1. Since my choice of method made some parts of the program terrible, I will definitely change the approach for this management system in a future version.
2. Of course, the remaining functions should be completed.
3. I have downloaded Qt and have a basic understanding of how to build a GUI. I will try to do so in the next version.

## Contact and Copyright

If you have any advice or feedback, please email <yansu@umich.edu> with \[ github\_feedback \]. I will reply to emails within two business days.

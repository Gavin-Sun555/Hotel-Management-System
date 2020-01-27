# Hotel Management System Beta 0.0.1 (2018-07-18)  

## About
This is my first C course project of the course VE101 as a freshman student at Shanghai Jiao Tong University. It is a course designed for new engineers to design simple algorithms and understand the main concepts of programming. To be honest, the code style of this project is not good and there are countless bugs and perhaps some memory leaks in this project. It is posted to record the starting point of my coding career. Future modifications may be made. Following is the original readme wrote at that time. I transfer the original txt file into markdown to make it easier to read. There are many redundent descrptions, which I will fix later.
 
 
## Basic Information
1.	Firstly, with the function "Initialdata", I renew the data in the database. In the current version, the size of the hotel is fixed and cannot be changed by users.
1.	Then, I generate check-in vistors with random number and link list in the function "generatevistors". I use pointers to the structure to generate random names stored in my structure set.
1.	Then with check-in and check-out function, visitors are able to check out. For most of time, the check out function works fairly well. But sometimes it may have some problems due to possible memory leak. You may restart
the program or try more times. If there are still problems, please contact with me. 
1.	The users are able to set the date and the span of dates. And we can change the number of breakfasts and nights(not for dorm visitors yet). Just do the operation according to the command line.
1.	In this version, many basic functions are still not completed.
1.	Though most parts of my program are boring and a bit burdensome since instead of using link lists to read the data of every room, I choose to read and revise them directly. This cause my program is extremely long. To make it more readable, index is added for most parts. But no need to read them if the program runs fairly well.
1.	With my function numtotime and timetonum, I would be able to compare the time. This function has considered the situation of leap years. For the reason that I count the year from 0; the result number is fairly large. It could be changed to take 1970 as the start year but since some people may find it fun if more ancient year is supported.
1.	The initial set room price are : single60,double80,family100,breakfast15;
1.	The check-out used to work well before I arrange them in the required order. But now it has various issues from time to time. I have spent plenty of time but cannot figure out where the issues are. Hence, it would be very grateful for me if you find the mistakes;
1.	Up to what I've tested, the check-in card and the receipt are fairly well.
1.	Though I actually did not write this piece of project well, I still learned a lot during the process. I learned to handle the pointer better and have a deep understanding towards it. I also practice the usage of the structure. Moreover, after failing to deal with time with <time.h>,which is absolutely possible, I choose to use my own function to do the job of adding a day. Though it seems unnecessary, but it works fairly well.
1.	More information is written in comments in the program.

## Future Improvement
1.	Since my wrong choice of method, some parts of the program becomes very terrible. Hence, if haven more time, I will definitely change a method for this management system in the future version.
1.	Of course, the remain parts of functions should be completed.
1.	I have downloaded the QT and have a basic check on how to build a GUI. I will try to do so in the next version.

## Other Things
1.	Firstly, I thought to read the information of the room with link list.  Like the following structure. However, I think it may be easier and efficient to direct deal with the data base.
1. Double Room link list only->room(int)->vacant(int)->name1(string)->id1(string)->name2(string)->id2(string)->arrival(string)->key(int)->breakfast(int)->nights(int)->price(int)(price is breakfast\*15,key\*1,nights\*80 with random change)
1. Single Room link list only->room(int)->-vacant(int)->name(string)->id(string)->arrival(string)->key(int)->breakfast(int)->nights(int)->price(int)(price is breakfast\*15,key\*1,nights\*60 with random change)
1. Famile Room link list only->room(int)->-vacant(int)->name1(string)->id1(string)->name2(string)->id2(string)->name3(string)->id3(string)->arrival(string)->key(int)->breakfast(int)->nights(int)->price(int)(price is breakfast\*15,key\*1,nights\*100 with random change)
1. Dorm Room link list only->room(int)->-vacant(int)->deduce how many visitors and link to visitors
The structure of link list of randomly generated visitors are listed as following:
check-invistors>number(0-3) (3means dorm alone))>name(string)->id(string)(2/3times for single room/double room)->key(int)->breakfast(int)->nights(int)//->price(int)(breakfast\*15+key\*1+nights\*20)

## Contact and Copywrite
If you have any adivices or feedbacks, please email to yansu@umich.edu with \[ github_feedback \]. I will reply emails within two bussiness days. Since it is a open course project written on my own, there is no copywrites restriction on use or modify the code.

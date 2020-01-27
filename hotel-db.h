//
// Created by sy585 on 7/11/2018.
//

#ifndef PROJECT_2_HOTEL_DB_H
#define PROJECT_2_HOTEL_DB_H
#include "hotel-ll.h"
#include "hotel-mt.h"
#include "hotel-db.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void InputSingleRoom(node_t* room);//input the room number, get the information of the room
void InputDoubleRoom(node_t* room);
void InputFamilyRoom(node_t* room);
void InputDorm(node_t* room);
void CheckinSingleRoom(char* number,node_t* guest, char* time);
void CheckinDoubleRoom(char* number,node_t* guest, char* time);
void CheckinFamilyRoom(char* number,node_t* guest, char* time);
void CheckinDorm(char* number,node_t* guest,char* time);
void checkout(int time1);
long long int  timetonumber(char* time1);
char* numbertotime(long long int time1);
void checkdorm(char number, char *roomnum, int time1);
void checkoutcards(char *name, char *id, char *arrival, int room, int nights, int price, int breakfast);
#endif //PROJECT_2_HOTEL_DB_H
int Changebreakfastnights(char* number,char* id, int changebreak,int changenights);//
//For dorm ID is to check which customer is// For other room type, only need to input one of the id to avoid operated mistakes;
// change is the amount of breakfast after change.0 will return when succeed;-1will return when fail
//change is the amount of nights after change.0 will return when succeed,-1will return when fail(if you have lived for two nights but want to change to one night. It will fail of course.)
//This four functions will check out the first vistor when there are more than one vistors who have both the same name and ID//

//
// Created by sy585 on 7/14/2018.
//

#ifndef PROJECT_2_HOTEL_MG_H
#define PROJECT_2_HOTEL_MG_H

#include "hotel-ll.h"

#endif //PROJECT_2_HOTEL_MG_H

int initialMt();//initList the database for the hotel return NULL when fail and 0 when succeed.
//checkin part
void checkin(node_t *a, char *time1);

char *searchSingle();//return room number. null when full
char *searchDouble();

char *searchFamily();

char *searchDorm();//all this four functions take care of the job of searching a room for customer when he checks in//
void checkinCards(char *room, node_t *guest);//this function is designed to generate check-in cards for customers//
//the function to renew the data base are included in hotel-db//

//set(CMAKE_C_FLAGS "-Wall -Werror")

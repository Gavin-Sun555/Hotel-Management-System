//
// Created by sy585 on 7/14/2018.
//

#ifndef PROJECT_2_HOTEL_MG_H
#define PROJECT_2_HOTEL_MG_H

#include "hotel-ll.h"

int initializeDatabase(int numSingle, int numDouble, int numFamily, int numDorm); // Initialize the database for the hotel. Returns -1 on fail, 0 on success.

// Checkin part
void checkin(node_t *a, char *time1);

char *searchSingle(void);  // Return room number. NULL when full.
char *searchDouble(void);
char *searchFamily(void);
char *searchDorm(void);    // All four functions search for a room for the customer on check-in.

void checkinCards(char *room, node_t *guest); // Generate check-in cards for customers.
// The functions to update the database are in hotel-db.

#endif //PROJECT_2_HOTEL_MG_H

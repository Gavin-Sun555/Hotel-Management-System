//
// Created by sy585 on 7/11/2018.
//

#ifndef PROJECT_2_HOTEL_DB_H
#define PROJECT_2_HOTEL_DB_H

#include "hotel-ll.h"
#include "hotel-mt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkinSingleRoom(char *number, node_t *guest, char *time);

void checkinDoubleRoom(char *number, node_t *guest, char *time);

void checkinFamilyRoom(char *number, node_t *guest, char *time);

void checkinDorm(char *number, node_t *guest, char *time);

void checkout(int time1);

long long int timeToNumber(char *time1);

char *numberToTime(long long int time1);

void checkDorm(char number, char *roomNum, int time1);

void checkoutCards(char *name, char *id, char *arrival, int room, int nights, int price, int breakfast);

// For dorm, ID identifies which customer.
// For other room types, only need to input one ID to avoid operational mistakes.
// breakChange is the new breakfast count; nightsChange is the new nights count.
// Returns 0 on success, -1 on failure.
int changeBreakfastNights(char *number, char *id, int breakChange, int nightsChange);

#endif //PROJECT_2_HOTEL_DB_H

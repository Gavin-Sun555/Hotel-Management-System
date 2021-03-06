#include "hotel-ll.h"
#include "hotel-mt.h"
#include "hotel-db.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    int A, i, j, f, breakfast, nights;
    char *roomNumber = malloc(sizeof(char) * 5);
    char *id = malloc(sizeof(char) * 9);
    char *time1 = malloc(sizeof(char) * 20);
    A = initialMt();
    if (A == -1) {
        printf("OOps,The system fails to initialize, please contact your system administer for help. :(");
        return 0;
    }
    printf("-SYSTEM INITIALIZED SUCCESSFULLY\n");
    printf("Welcome to no-star hotel management system,press Enter to start demo");
    getchar();
    printf("Input the current data(the form like 04/06/1989(DATE/MONTH/YEAR)):\n");
    scanf("%s", time1);
    printf("Input the span of days:\n");
    getchar();
    int span;
    scanf("%d", &span);
    node_t *a;
    srand(time(NULL));
    for (i = 0; i < span; i++) {
        if (i != 0) {
            long long int b = timeToNumber(time1);//my method to dell with time is not sufficient with type int;
            b++;
            time1 = numberToTime(b);
            printf("Today is %s, Following is checking out lists:\n", time1);
            getchar();
            checkout((int) b);
        }
        A = rand() % 10 + 5;
        printf("Today %d groups of visitors check in:\n", A);//5-14 visitors per day;
        getchar();
        for (j = 0; j < A; j++) {
            a = generateVisitors(A + j);
            checkin(a, time1);
        }
        printf("Options to search available room(NOT AVAILABLE FOR TRIAL VERSION)\n");
        getchar();
        printf("Options to search guests(NOT AVAILABLE DUE TO SAFETY REASON)\n");
        getchar();
        printf("Options to add breakfast,change nights(NOT AVAILABLE FOR DORM)press 1 to enter/ANY OTHER NUMBER TO SKIP;)\n");
        scanf("%d", &f);
        while (f == 1) {
            printf("PLEASE ENTER THE ROOM NUMBER:\n");
            getchar();
            scanf("%s", roomNumber);
            printf("PLEASE ENTER THE ID NUMBER:\n");
            getchar();
            scanf("%s", id);
            printf("PLEASE ENTER THE AMOUNT OF BREAKFAST AFTER CHANGE :\n");
            getchar();
            scanf("%d", &breakfast);
            printf("PLEASE ENTER THE AMOUNT OF NIGHTS AFTER CHANGE :\n");
            getchar();
            scanf("%d", &nights);
            if (changeBreakfastNights(roomNumber, id, breakfast, nights) == -1) {
                printf("FAIL TO OPERATE:PLEASE DOUBLE CHECK WHETHER THE ID OF VISITORS IS CORRECT FOR THIS ROOM.\n");
            } else
                printf("CHANGED SUCCESSFULLY");
            getchar();
            printf("OPTION AGAIN;Press1/Press any number to exit:\n");
            scanf("%d", &f);
        }
        printf("press Enter to next day's demo:\n");
        getchar();
    }
    free(time1);
    free(roomNumber);
    free(id);
    freeList(&a);//return the memory of a//
}//
//set(CMAKE_C_FLAGS "-Wall -Werror")//

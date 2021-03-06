#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hotel-ll.h"
#include "hotel-mt.h"
#include "hotel-db.h"

int initialMt() {
    FILE *fp = fopen("hotel.db", "w");
    if (fp == NULL) { return -1; }
    fprintf(fp,
            "\n[room 8101]\n");//8 means nothing but lucky in China and nearly all the hotels use this method to name the room number.
    fprintf(fp, "type=dorm\n");
    fprintf(fp, "vacant=6\n");
    fprintf(fp, "visitors=0\n");
    fprintf(fp, "\n[room 8102]\n");
    fprintf(fp, "type=dorm\n");
    fprintf(fp, "vacant=6\n");
    fprintf(fp, "visitors=0\n");
    fprintf(fp, "\n[room 8103]\n");
    fprintf(fp, "type=double\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8105]\n");//in China 4 is unlucky. Hence, most hotels skip this number.
    fprintf(fp, "type=double\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8106]\n");
    fprintf(fp, "type=double\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8107]\n");
    fprintf(fp, "type=double\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8108]\n");
    fprintf(fp, "type=double\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8109]\n");
    fprintf(fp, "type=double\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8110]\n");
    fprintf(fp, "type=double\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8201]\n");
    fprintf(fp, "type=dorm\n");
    fprintf(fp, "vacant=6\n");
    fprintf(fp, "visitors=0\n");
    fprintf(fp, "\n[room 8202]\n");
    fprintf(fp, "type=dorm\n");
    fprintf(fp, "vacant=6\n");
    fprintf(fp, "visitors=0\n");
    fprintf(fp, "\n[room 8203]\n");
    fprintf(fp, "type=double\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8205]\n");
    fprintf(fp, "type=double\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8206]\n");
    fprintf(fp, "type=double\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8207]\n");
    fprintf(fp, "type=double\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8208]\n");
    fprintf(fp, "type=double\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8209]\n");
    fprintf(fp, "type=double\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8210]\n");
    fprintf(fp, "type=double\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8301]\n");
    fprintf(fp, "type=single\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8302]\n");
    fprintf(fp, "type=single\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8303]\n");
    fprintf(fp, "type=single\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8305]\n");
    fprintf(fp, "type=single\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8306]\n");
    fprintf(fp, "type=double\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8307]\n");
    fprintf(fp, "type=double\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8308]\n");
    fprintf(fp, "type=double\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8309]\n");
    fprintf(fp, "type=double\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8310]\n");
    fprintf(fp, "type=family\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8501]\n");//for the same reason, floor 4 is skipped in this hotel.
    fprintf(fp, "type=single\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8502]\n");
    fprintf(fp, "type=single\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8503]\n");
    fprintf(fp, "type=single\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8505]\n");
    fprintf(fp, "type=single\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8506]\n");
    fprintf(fp, "type=double\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8507]\n");
    fprintf(fp, "type=double\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8508]\n");
    fprintf(fp, "type=double\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp, "\n[room 8509]\n");
    fprintf(fp, "type=double\n");
    fprintf(fp, "vacant=1\n");
    fprintf(fp,
            "\n[room 8510]\n");// in China, there are rarely situation that people would choose family room. Hence only two in these hotel.
    fprintf(fp, "type=family\n");
    fprintf(fp, "vacant=1\n\n");
    fprintf(fp, "[DATABASE END]-");
    fclose(fp);
    return 0;
}

void checkin(node_t *a, char *time1) {
    int vis = *((int *) (a->ch));
    char *number;
    if (vis == 0) {
        number = searchSingle();
        if (number == NULL) {
            printf("------------------------------WARNING------------------------------\n");
            printf("Dear %s, We are sincerely sorry to inform you that single room is full.\n",
                   (char *) a->next->ch);//the hotel is full
            printf("------------------------------WARNING END------------------------------\n\n");
            free(number);
            freeList(&a);
            return;
        }
        checkinSingleRoom(number, a, time1);
        checkinCards(number, a);
    } else if (vis == 1) {
        number = searchDouble();
        if (number == NULL) {
            printf("------------------------------WARNING------------------------------\n");
            printf("Dear %s and %s, We are sincerely sorry to inform you that double room is full.\n",
                   (char *) a->next->ch, (char *) a->next->next->next->ch);//the hotel is full
            printf("------------------------------WARNING END------------------------------\n\n");
            free(number);
            freeList(&a);
            return;
        }
        checkinDoubleRoom(number, a, time1);
        checkinCards(number, a);
    } else if (vis == 2) {
        number = searchFamily();
        if (number == NULL) {
            printf("------------------------------WARNING------------------------------\n");
            printf("Dear %s, %s and %s, We are sincerely sorry to inform you that family room is full.\n",
                   (char *) a->next->ch, (char *) a->next->next->next->ch,
                   (char *) a->next->next->next->next->next->ch);//the hotel is full
            printf("------------------------------WARNING END------------------------------\n\n");
            free(number);
            freeList(&a);
            return;
        }
        checkinFamilyRoom(number, a, time1);
        checkinCards(number, a);
    } else if (vis == 3) {
        number = searchDorm();
        if (number == NULL) {
            printf("------------------------------WARNING------------------------------\n");
            printf("The Dorm is full.\n");
            printf("------------------------------WARNING END------------------------------\n\n");
            free(number);
            freeList(&a);
            return;
        }//the hotel is full
        checkinDorm(number, a, time1);
        checkinCards(number, a);
    }else{
        freeList(&a);
        return;
    }
    free(number);
    freeList(&a);
}

char *searchSingle() {
    char str[10000];
    char *room = calloc(sizeof(char), 5);//remember to return the memory!!!
    int i = 0;
    FILE *fp = fopen("hotel.db", "r");
    while (feof(fp) == 0) {//not reach the end//
        str[i] = fgetc(fp);
        i++;
    }
    char *pos = strstr(str, "single");
    while (*(pos + 14) != '1') ///the room is vacant /only data base with fixed format can work.
    {
        pos = strstr((pos + 1), "single");
        if (pos == NULL) {
            return NULL;
        }
    }
    for (i = 0; i < 4; i++)
        *(room + i) = *(pos - 11 + i);

    fclose(fp);
    return room;
}

char *searchDouble() {
    char str[10000];
    char *room = calloc(sizeof(char), 5);//remember to return the memory!!!
    int i = 0;
    FILE *fp = fopen("hotel.db", "r");
    while (feof(fp) == 0) {//not reach the end//
        str[i] = fgetc(fp);
        i++;
    }
    char *pos = strstr(str, "double");
    while (*(pos + 14) != '1') ///the room is vacant /only data base with fixed format can work.
    {
        pos = strstr((pos + 1), "double");
        if (pos == NULL) {
            return NULL;
        }
    }
    for (i = 0; i < 4; i++)
        *(room + i) = *(pos - 11 + i);
    fclose(fp);
    return room;
}

char *searchFamily() {
    char str[10000];
    char *room = calloc(sizeof(char), 5);
    int i = 0;
    FILE *fp = fopen("hotel.db", "r");
    while (feof(fp) == 0) {//not reach the end//
        str[i] = fgetc(fp);
        i++;
    }
    char *pos = strstr(str, "family");
    while (*(pos + 14) != '1') ///the room is vacant /only data base with fixed format can work.
    {
        pos = strstr((pos + 1), "family");
        if (pos == NULL) {
            return NULL;
        }
    }
    for (i = 0; i < 4; i++) {
        *(room + i) = *(pos - 11 + i);
    }//12 works well in my system. It should be 11 in my understanding.
    *(room + 4) = '\0';
    fclose(fp);
    return room;
}

char *searchDorm() {
    char str[10000];
    char *room = calloc(sizeof(char), 5);//remember to return the memory!!!
    int i = 0;
    FILE *fp = fopen("hotel.db", "r");
    while (feof(fp) == 0) {//not reach the end//
        str[i] = fgetc(fp);
        i++;
    }
    char *pos = strstr(str, "dorm");
    while (*(pos + 12) == '0') ///the room is vacant /only data base with fixed format can work.
    {
        pos = strstr((pos + 1), "dorm");
        if (pos == NULL) {
            return NULL;
        }
    }
    for (i = 0; i < 4; i++)
        *(room + i) = *(pos - 11 + i);
    fclose(fp);
    return room;
}

void checkinCards(char *room, node_t *guest) {
    int key, breakfast, price;
    printf("------------------------------Checkin Cards------------------------------\n");
    printf("WELCOME TO 'no-star hotel'\n");//The name of our hotel is called no-star hotel//
    printf("Room Number:%s\n", room);
    if ((*((int *) (guest->ch)) + 1) != 4)
        printf("Number of people:%d\n", (*((int *) (guest->ch)) + 1));
    else
        printf("Number of people:1\n");
    if (*((int *) (guest->ch)) == 0) {
        guest = guest->next;
        printf("Your name:%s\n", (char *) guest->ch);
        guest = guest->next;
        printf("Your ID:%s\n", (char *) guest->ch);
        guest = guest->next;
        key = *(int *) guest->ch;
        printf("Your Key:%d\n", key);
        guest = guest->next;
        breakfast = *(int *) guest->ch;
        printf("Your Breakfast:%d\n", breakfast);
        guest = guest->next;
        printf("Your Nights:%d\n", *(int *) guest->ch);
        price = *(int *) guest->ch * 60 + breakfast * 15;
        printf("Total price:%d\n", price);
        printf("Hope you have a nice day. If there are some problems in your room, please try to fix it by yourself first. Our staff are too busy to do that. Thanks for your understanding.\n");
        printf("------------------------------The end of Checkin Cards------------------------------\n\n");
    }//single room
    else if (*((int *) (guest->ch)) == 1) {
        guest = guest->next;
        printf("Your name1:%s\n", (char *) guest->ch);
        guest = guest->next;
        printf("Your ID1:%s\n", (char *) guest->ch);
        guest = guest->next;
        printf("Your name2:%s\n", (char *) guest->ch);
        guest = guest->next;
        printf("Your ID2:%s\n", (char *) guest->ch);
        guest = guest->next;
        key = *(int *) guest->ch;
        printf("Your Key:%d\n", key);
        guest = guest->next;
        breakfast = *(int *) guest->ch;
        printf("Your Breakfast:%d\n", breakfast);
        guest = guest->next;
        printf("Your Nights:%d\n", *(int *) guest->ch);
        price = *(int *) guest->ch * 80 + breakfast * 15;
        printf("Total price:%d\n\n", price);
        printf("Hope you have a nice day. If there are some problems in your room, please try to fix it by yourself first. Our staff are too busy to do that. Thanks for your understanding.\n");
        printf("------------------------------The end of Checkin Cards------------------------------\n\n");
    }//double room
    else if (*((int *) (guest->ch)) == 2) {
        guest = guest->next;
        printf("Your name1:%s\n", (char *) guest->ch);
        guest = guest->next;
        printf("Your ID1:%s\n", (char *) guest->ch);
        guest = guest->next;
        printf("Your name2:%s\n", (char *) guest->ch);
        guest = guest->next;
        printf("Your ID2:%s\n", (char *) guest->ch);
        guest = guest->next;
        printf("Your name3:%s\n", (char *) guest->ch);
        guest = guest->next;
        printf("Your ID3:%s\n", (char *) guest->ch);
        guest = guest->next;
        key = *(int *) guest->ch;
        printf("Your Key:%d\n", key);
        guest = guest->next;
        breakfast = *(int *) guest->ch;
        printf("Your Breakfast:%d\n", breakfast);
        guest = guest->next;
        printf("Your Nights:%d\n", *(int *) guest->ch);
        price = *(int *) guest->ch * 100 + breakfast * 15;
        printf("Total price:%d\n\n", price);
        printf("Hope you have a nice day. If there are some problems in your room, please try to fix it by yourself first. Our staff are too busy to do that. Thanks for your understanding.\n");
        printf("------------------------------The end of Checkin Cards------------------------------\n\n");
    }//Treble room
    else if (*((int *) (guest->ch)) == 3) {
        guest = guest->next;
        printf("Your name1:%s\n", (char *) guest->ch);
        guest = guest->next;
        printf("Your ID1:%s\n", (char *) guest->ch);
        guest = guest->next;
        key = *(int *) guest->ch;
        printf("Your Key1:%d\n", key);
        guest = guest->next;
        breakfast = *(int *) guest->ch;
        printf("Your Breakfast1:%d\n", breakfast);
        guest = guest->next;
        printf("Your Nights1:%d\n", *(int *) guest->ch);
        price = *(int *) guest->ch * 20 + breakfast * 15;
        printf("Total price1:%d\n\n", price);
        printf("Hope you have a nice day. If there are some problems in your room, please try to fix it by yourself first. Our staff are too busy to do that. Thanks for your understanding.\n");
        printf("------------------------------The end of Checkin Cards------------------------------\n\n");
    }//dorm
}

typedef struct visitorList {
    char *firstName;
    char *givenName;
} visitorList;

node_t *generateVisitors(int a) {
    a = a + (int) time(NULL);
    srand(a);
    int first, last;
    node_t *visitor;
    int *random_varible = malloc(sizeof(int));
    visitorList *visitorlist1 = malloc(50 * sizeof(visitorList));
    *visitorlist1 = (visitorList) {"Yan", "Sun",};
    *(visitorlist1 + 1) = (visitorList) {"Yihao", "Liu"};
    *(visitorlist1 + 2) = (visitorList) {"Aaron", "Smith"};
    *(visitorlist1 + 3) = (visitorList) {"Abe", "Jones"};
    *(visitorlist1 + 4) = (visitorList) {"Adam", "Patel"};
    *(visitorlist1 + 5) = (visitorList) {"Adan", "Davis"};
    *(visitorlist1 + 6) = (visitorList) {"Adrian", "Bell"};
    *(visitorlist1 + 7) = (visitorList) {"Agustin", "Baker"};
    *(visitorlist1 + 8) = (visitorList) {"Ahmad", "Liu"};
    *(visitorlist1 + 9) = (visitorList) {"Alan", "Thomas"};
    *(visitorlist1 + 10) = (visitorList) {"Albert", "Jones"};
    *(visitorlist1 + 11) = (visitorList) {"Aldo", "Roberts"};
    *(visitorlist1 + 12) = (visitorList) {"Alfredo", "Davis"};
    *(visitorlist1 + 13) = (visitorList) {"Ali", "Johnson"};
    *(visitorlist1 + 14) = (visitorList) {"Allan", "Gibson"};
    *(visitorlist1 + 15) = (visitorList) {"Alton", "Wells"};
    *(visitorlist1 + 16) = (visitorList) {"Andy", "Murphy"};
    *(visitorlist1 + 17) = (visitorList) {"Anibal", "Foster"};
    *(visitorlist1 + 18) = (visitorList) {"Becky", "Mills"};
    *(visitorlist1 + 19) = (visitorList) {"Bert", "Hart"};
    *(visitorlist1 + 20) = (visitorList) {"Brant", "Gill"};
    *(visitorlist1 + 21) = (visitorList) {"Brett", "White"};
    *(visitorlist1 + 22) = (visitorList) {"Chad", "Jackson"};
    *(visitorlist1 + 23) = (visitorList) {"Chang", "Green"};
    *(visitorlist1 + 24) = (visitorList) {"Chase", "Watson"};
    *(visitorlist1 + 25) = (visitorList) {"Chong", "King"};
    *(visitorlist1 + 26) = (visitorList) {"Colin", "Lee"};
    *(visitorlist1 + 27) = (visitorList) {"Colton", "Fox"};
    *(visitorlist1 + 28) = (visitorList) {"Conrad", "Hunt"};
    *(visitorlist1 + 29) = (visitorList) {"David", "Kelly"};
    *(visitorlist1 + 30) = (visitorList) {"Donald", "Trump"};
    *(visitorlist1 + 31) = (visitorList) {"Donny", "Adams"};
    *(visitorlist1 + 32) = (visitorList) {"Dylan", "Allen"};
    *(visitorlist1 + 33) = (visitorList) {"Earl", "Ross"};
    *(visitorlist1 + 34) = (visitorList) {"Eddie", "Owen"};
    *(visitorlist1 + 35) = (visitorList) {"Edmundo", "Mason"};
    *(visitorlist1 + 36) = (visitorList) {"Edward", "Knight"};
    *(visitorlist1 + 37) = (visitorList) {"Edwin", "Butler"};
    *(visitorlist1 + 38) = (visitorList) {"Elvin", "Saunders"};
    *(visitorlist1 + 39) = (visitorList) {"Gale", "Stevens"};
    *(visitorlist1 + 40) = (visitorList) {"Galen", "Webb"};
    *(visitorlist1 + 41) = (visitorList) {"Hobert", "Bradley"};
    *(visitorlist1 + 42) = (visitorList) {"Jack", "Jenkins"};
    *(visitorlist1 + 43) = (visitorList) {"Jarod", "Carter"};
    *(visitorlist1 + 44) = (visitorList) {"Jerry", "Phillips"};
    *(visitorlist1 + 45) = (visitorList) {"Juan", "Mitchell"};
    *(visitorlist1 + 46) = (visitorList) {"Jude", "Anderson"};
    *(visitorlist1 + 47) = (visitorList) {"Kim", "Walsh"};
    *(visitorlist1 + 48) = (visitorList) {"Leo", "Stone"};
    *(visitorlist1 + 49) = (visitorList) {"Loyd", "West"};
    *random_varible = rand() % 4;
    int randomNumber1 = rand();
    int randomNumber2 = rand();
    int randomNumber3 = rand();
    int randomNumber4 = rand();
    int randomNumber5 = rand();
    int randomNumber6 = rand();
    if (*random_varible == 0)//single room
    {
        visitor = initList(random_varible);
        first = (int) strlen((visitorlist1 + (randomNumber1 % 50))->firstName);
        last = (int) strlen((visitorlist1 + (randomNumber2 % 50))->givenName);
        char *full = malloc(first + last + 2);//one for space and another for the symbol at the end of the string.
        memcpy(full, ((visitorlist1 + (randomNumber1 % 50))->firstName), first);
        memcpy(full + first + 1, ((visitorlist1 + (randomNumber2 % 50))->givenName),
               last + 1); // +1 to copy the null-terminator
        *(full + first) = ' ';//REMEMBER TO RETURN THE MEMORY!!!!
        insertLastList(&visitor, full);//insert name

        char *id3 = malloc(sizeof(char) * 9);
        sprintf(id3, "%03u", rand() % 1000);
        sprintf((id3 + 3), "%03u", rand() % 1000);
        *(id3 + 6) = 'A';
        *(id3 + 7) = 'B';
        *(id3 + 8) = '\0';//mark as the end of the ID string;
        insertLastList(&visitor, id3);//insert ID
        int *key = malloc(sizeof(int));
        *key = rand() % 2 + 1;
        insertLastList(&visitor, key);//key(may ask 1-2)
        int *breakfast = malloc(sizeof(int));
        int *nights = malloc(sizeof(int));
        *nights = rand() % 9 + 1;
        *breakfast = rand() % 2 * (*nights);
        insertLastList(&visitor, breakfast);//key(may ask 0-1)
        insertLastList(&visitor, nights);//key(may ask 1-9)
    } else if (*random_varible == 1)//double room
    {
        visitor = initList(random_varible);
        first = (int) strlen((visitorlist1 + (randomNumber1 % 50))->firstName);
        last = (int) strlen((visitorlist1 + (randomNumber2 % 50))->givenName);
        char *full = malloc(first + last + 2);//one for space and another for the symbol at the end of the string.
        memcpy(full, ((visitorlist1 + (randomNumber1 % 50))->firstName), first);
        memcpy(full + first + 1, ((visitorlist1 + (randomNumber2 % 50))->givenName),
               last + 1); // +1 to copy the null-terminator
        *(full + first) = ' ';//REMEMBER TO RETURN THE MEMORY!!!!
        insertLastList(&visitor, full);//insert name

        char *id3 = malloc(sizeof(char) * 9);
        sprintf(id3, "%03u", rand() % 1000);
        sprintf((id3 + 3), "%03u", rand() % 1000);
        *(id3 + 6) = 'A';
        *(id3 + 7) = 'B';
        *(id3 + 8) = '\0';
        insertLastList(&visitor, id3);//insert ID
        first = (int) strlen((visitorlist1 + (randomNumber3 % 50))->firstName);
        last = (int) strlen((visitorlist1 + (randomNumber4 % 50))->givenName);
        char *full2 = malloc(first + last + 2);//one for space and another for the symbol at the end of the string.
        memcpy(full2, ((visitorlist1 + (randomNumber3 % 50))->firstName), first);
        memcpy(full2 + first + 1, ((visitorlist1 + (randomNumber4 % 50))->givenName),
               last + 1); // +1 to copy the null-terminator
        *(full2 + first) = ' ';//REMEMBER TO RETURN THE MEMORY!!!!

        insertLastList(&visitor, full2);//insert name2
        char *id32 = malloc(sizeof(char) * 9);
        sprintf(id32, "%03u", rand() % 1000);
        sprintf((id32 + 3), "%03u", rand() % 1000);
        *(id32 + 6) = 'A';
        *(id32 + 7) = 'B';
        *(id32 + 8) = '\0';
        insertLastList(&visitor, id32);//insert ID2

        int *key = malloc(sizeof(int));
        *key = rand() % 2 + 1;
        insertLastList(&visitor, key);//key(may ask 1-2)
        int *breakfast = malloc(sizeof(int));
        int *nights = malloc(sizeof(int));
        *nights = rand() % 9 + 1;
        *breakfast = rand() % 3 * (*nights);
        insertLastList(&visitor, breakfast);//key(may ask 0-2)
        insertLastList(&visitor, nights);//key(may ask 1-9)
    } else if (*random_varible == 2)//family room
    {
        visitor = initList(random_varible);
        first = (int) strlen((visitorlist1 + (randomNumber1 % 50))->firstName);
        last = (int) strlen((visitorlist1 + (randomNumber2 % 50))->givenName);
        char *full = malloc(first + last + 2);//one for space and another for the symbol at the end of the string.
        memcpy(full, ((visitorlist1 + (randomNumber1 % 50))->firstName), first);
        memcpy(full + first + 1, ((visitorlist1 + (randomNumber2 % 50))->givenName),
               last + 1); // +1 to copy the null-terminator
        *(full + first) = ' ';//REMEMBER TO RETURN THE MEMORY!!!!
        insertLastList(&visitor, full);//insert name

        char *id3 = malloc(sizeof(char) * 9);
        sprintf(id3, "%03u", rand() % 1000);
        sprintf((id3 + 3), "%03u", rand() % 1000);
        *(id3 + 6) = 'A';
        *(id3 + 7) = 'B';
        *(id3 + 8) = '\0';
        insertLastList(&visitor, id3);//insert ID
        first = (int) strlen((visitorlist1 + (randomNumber3 % 50))->firstName);
        last = (int) strlen((visitorlist1 + (randomNumber4 % 50))->givenName);
        char *full2 = malloc(first + last + 2);//one for space and another for the symbol at the end of the string.
        memcpy(full2, ((visitorlist1 + (randomNumber3 % 50))->firstName), first);
        memcpy(full2 + first + 1, ((visitorlist1 + (randomNumber4 % 50))->givenName),
               last + 1); // +1 to copy the null-terminator
        *(full2 + first) = ' ';//REMEMBER TO RETURN THE MEMORY!!!!
        insertLastList(&visitor, full2);//insert name2

        char *id32 = malloc(sizeof(char) * 9);
        sprintf(id32, "%03u", rand() % 1000);
        sprintf((id32 + 3), "%03u", rand() % 1000);
        *(id32 + 6) = 'A';
        *(id32 + 7) = 'B';
        *(id32 + 8) = '\0';
        insertLastList(&visitor, id32);//insert ID2
        first = (int) strlen((visitorlist1 + (randomNumber5 % 50))->firstName);
        last = (int) strlen((visitorlist1 + (randomNumber6 % 50))->givenName);
        char *full3 = malloc(first + last + 2);//one for space and another for the symbol at the end of the string.
        memcpy(full3, ((visitorlist1 + (randomNumber5 % 50))->firstName), first);
        memcpy(full3 + first + 1, ((visitorlist1 + (randomNumber6 % 50))->givenName),
               last + 1); // +1 to copy the null-terminator
        *(full3 + first) = ' ';//REMEMBER TO RETURN THE MEMORY!!!!
        insertLastList(&visitor, full3);//insert name2

        char *id33 = malloc(sizeof(char) * 9);
        sprintf(id33, "%03u", rand() % 1000);
        sprintf((id33 + 3), "%03u", rand() % 1000);
        *(id33 + 6) = 'A';
        *(id33 + 7) = 'B';
        *(id33 + 8) = '\0';
        insertLastList(&visitor, id33);//insert ID2
        int *key = malloc(sizeof(int));
        *key = rand() % 3 + 1;
        insertLastList(&visitor, key);//key(may ask 1-2)
        int *breakfast = malloc(sizeof(int));
        int *nights = malloc(sizeof(int));
        *nights = rand() % 9 + 1;
        *breakfast = (rand() % 4) * (*nights);
        insertLastList(&visitor, breakfast);//key(may ask 0-3)
        insertLastList(&visitor, nights);//key(may ask 1-9)
    } else //dorm
    {
        visitor = initList(random_varible);
        first = (int) strlen((visitorlist1 + (randomNumber5 % 50))->firstName);
        last = (int) strlen((visitorlist1 + (randomNumber6 % 50))->givenName);
        char *full = malloc(first + last + 2);//one for space and another for the symbol at the end of the string.
        memcpy(full, ((visitorlist1 + (randomNumber5 % 50))->firstName), first);
        memcpy(full + first + 1, ((visitorlist1 + (randomNumber6 % 50))->givenName),
               last + 1); // +1 to copy the null-terminator
        *(full + first) = ' ';//REMEMBER TO RETURN THE MEMORY!!!!
        insertLastList(&visitor, full);//insert name

        char *id3 = malloc(sizeof(char) * 9);
        sprintf(id3, "%03u", rand() % 1000);
        sprintf((id3 + 3), "%03u", rand() % 1000);
        *(id3 + 6) = 'A';
        *(id3 + 7) = 'B';
        *(id3 + 8) = '\0';
        insertLastList(&visitor, id3);//insert ID
        int *key = malloc(sizeof(int));
        *key = rand() % 2;
        insertLastList(&visitor, key);//key(may ask 0-1)
        int *breakfast = malloc(sizeof(int));
        int *nights = malloc(sizeof(int));
        *nights = rand() % 9 + 1;
        *breakfast = rand() % 2 * (*nights);
        insertLastList(&visitor, breakfast);//breakfast(may ask 0-1)
        insertLastList(&visitor, nights);//nights(may ask 1-9)

    }
    free(visitorlist1);
    return visitor;
}

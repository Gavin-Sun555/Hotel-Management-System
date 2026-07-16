#include "hotel-ll.h"
#include "hotel-config.h"
#include "hotel-db.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkinPrivateRoom(char *number, node_t *guest, char *time, int type) {
    char str[10000];
    long i = 0;
    int key, breakfast, nights;
    FILE *fp = fopen("hotel.db", "r");
    if (!fp) {
        printf("ERROR IN POS50");
    }
    while (feof(fp) == 0) {
        str[i] = fgetc(fp);
        i++;
    }
    char *pos = strstr(str, number);
    fclose(fp);
    
    FILE *fp1 = fopen("hotel.db", "w");
    for (i = 0; i < (pos - str + 6); i++)
        fprintf(fp1, "%c", str[i]);
        
    if (type == 0) {
        fprintf(fp1, "type=single\n");
        fprintf(fp1, "vacant=0\n");
        fprintf(fp1, "name=%s\n", (char *) guest->next->ch);
        fprintf(fp1, "id=%s\n", (char *) guest->next->next->ch);
        guest = guest->next->next;
    } else if (type == 1) {
        fprintf(fp1, "type=double\n");
        fprintf(fp1, "vacant=0\n");
        fprintf(fp1, "name1=%s\n", (char *) guest->next->ch);
        fprintf(fp1, "id1=%s\n", (char *) guest->next->next->ch);
        fprintf(fp1, "name2=%s\n", (char *) guest->next->next->next->ch);
        fprintf(fp1, "id2=%s\n", (char *) guest->next->next->next->next->ch);
        guest = guest->next->next->next->next;
    } else if (type == 2) {
        fprintf(fp1, "type=family\n");
        fprintf(fp1, "vacant=0\n");
        fprintf(fp1, "name1=%s\n", (char *) guest->next->ch);
        fprintf(fp1, "id1=%s\n", (char *) guest->next->next->ch);
        fprintf(fp1, "name2=%s\n", (char *) guest->next->next->next->ch);
        fprintf(fp1, "id2=%s\n", (char *) guest->next->next->next->next->ch);
        fprintf(fp1, "name3=%s\n", (char *) guest->next->next->next->next->next->ch);
        fprintf(fp1, "id3=%s\n", (char *) guest->next->next->next->next->next->next->ch);
        guest = guest->next->next->next->next->next->next;
    }
    
    fprintf(fp1, "arrival=%s\n", time);
    key = *(int *) guest->next->ch;
    fprintf(fp1, "key=%d\n", key);
    breakfast = *(int *) guest->next->next->ch;
    fprintf(fp1, "breakfast=%d\n", breakfast);
    nights = *(int *) guest->next->next->next->ch;
    fprintf(fp1, "nights=%d\n", nights);
    
    int rate = (type == 0) ? current_rates.single_rate : ((type == 1) ? current_rates.double_rate : current_rates.family_rate);
    fprintf(fp1, "price=%d\n\n", nights * rate + breakfast * current_rates.breakfast_rate);
    
    pos = strstr(pos + 1, "[");
    i = (pos - str);
    while (str[i - 1] != '-') {
        fprintf(fp1, "%c", str[i]);
        i++;
    }
    fclose(fp1);
}

void checkinDorm(char *number, node_t *guest, char *time) {
    char str[10000];
    long i = 0;
    int key, breakfast, nights;
    FILE *fp = fopen("hotel.db", "r");
    if (!fp) {
        printf("ERROR IN POS50");
    }
    while (feof(fp) == 0) {//not reach the end//
        str[i] = fgetc(fp);
        i++;
    }
    char *pos = strstr(str, number);//rewrite this part, finally print.
    fclose(fp);
    char *pos2 = strstr(pos, "vacant");
    char *pos3 = strstr(pos2, "[");
    char vacant_char = *(pos2 + 7);
    if (vacant_char >= '1' && vacant_char <= '6') {
        int vacant = vacant_char - '0';
        int new_vacant = vacant - 1;
        int new_visitors = 6 - new_vacant;
        
        str[pos2 - str + 7] = new_vacant + '0';
        str[pos2 - str + 17] = new_visitors + '0';
        
        FILE *fp1 = fopen("hotel.db", "w");
        for (i = 0; i < (pos3 - str); i++)
            fprintf(fp1, "%c", str[i]);//copy the part before
            
        if (vacant_char == '6') {
            fprintf(fp1, "\nname=%s\n", (char *) guest->next->ch);
        } else {
            fprintf(fp1, "name=%s\n", (char *) guest->next->ch);
        }
        fprintf(fp1, "id=%s\n", (char *) guest->next->next->ch);
        fprintf(fp1, "arrival=%s\n", time);
        key = *(int *) guest->next->next->next->ch;
        fprintf(fp1, "key=%d\n", key);
        breakfast = *(int *) guest->next->next->next->next->ch;
        fprintf(fp1, "breakfast=%d\n", breakfast);
        nights = *(int *) guest->next->next->next->next->next->ch;
        fprintf(fp1, "nights=%d\n", nights);
        fprintf(fp1, "price=%d\n\n", nights * current_rates.dorm_rate + breakfast * current_rates.breakfast_rate);
        i = pos3 - str;
        while (str[i - 1] != '-') {
            fprintf(fp1, "%c", str[i]);
            i++;
        }
        fclose(fp1);
    }
}

int changeBreakfastNights(char *number, char *id, int breakChange, int nightsChange) {
    char str[10000];
    int i = 0;
    char *id2 = malloc(sizeof(char) * 9);
    char *id3 = malloc(sizeof(char) * 9);
    char *id4 = malloc(sizeof(char) * 9);
    FILE *fp = fopen("hotel.db", "r");
    while (feof(fp) == 0) {//not reach the end//
        str[i] = fgetc(fp);
        i++;
    }
    fclose(fp);
    char *pos = strstr(str, number);
    char *pos2 = strstr(pos, "type");
    if (*(pos2 + 7) == 'n')//the type is single/
    {
        pos2 = strstr(pos, "id");
        *id2 = *(pos2 + 3);
        *(id2 + 1) = *(pos2 + 4);
        *(id2 + 2) = *(pos2 + 5);
        *(id2 + 3) = *(pos2 + 6);
        *(id2 + 4) = *(pos2 + 7);
        *(id2 + 5) = *(pos2 + 8);
        *(id2 + 6) = *(pos2 + 9);
        *(id2 + 7) = *(pos2 + 10);
        *(id2 + 8) = '\0';
        if (*id2 == *id && *(id2 + 1) == *(id + 1) && *(id2 + 2) == *(id + 2) && *(id2 + 3) == *(id + 3) &&
            *(id2 + 4) == *(id + 4) && *(id2 + 5) == *(id + 5))//
        {
            pos2 = strstr(pos, "breakfast");
            FILE *fp1 = fopen("hotel.db", "w");
            for (i = 0; i < pos2 - str + 10; i++)
                fprintf(fp1, "%c", str[i]);
            fprintf(fp1, "%d\n", breakChange);
            fprintf(fp1, "nights=%d\n", nightsChange);
            fprintf(fp1, "price=%d\n\n", nightsChange * current_rates.single_rate + breakChange * current_rates.breakfast_rate);
            pos2 = strstr(pos, "[");//to locate next room
            i = pos2 - str;
            while (str[i - 1] != '-') {
                fprintf(fp1, "%c", str[i]);
                i++;//copy the part after revising;
            }
            fclose(fp1);
            free(id2);
            free(id3);
            free(id4);
            return 0;
        } else {
            free(id2);
            free(id3);
            free(id4);
            return -1;
        }

    } else if (*(pos2 + 7) == 'u') {//the type is double
        pos2 = strstr(pos, "id1");
        *id2 = *(pos2 + 4);
        *(id2 + 1) = *(pos2 + 5);
        *(id2 + 2) = *(pos2 + 6);
        *(id2 + 3) = *(pos2 + 7);
        *(id2 + 4) = *(pos2 + 8);
        *(id2 + 5) = *(pos2 + 9);
        *(id2 + 6) = *(pos2 + 10);
        *(id2 + 7) = *(pos2 + 11);
        *(id2 + 8) = '\0';
        pos2 = strstr(pos, "id2");
        *id3 = *(pos2 + 4);
        *(id3 + 1) = *(pos2 + 5);
        *(id3 + 2) = *(pos2 + 6);
        *(id3 + 3) = *(pos2 + 7);
        *(id3 + 4) = *(pos2 + 8);
        *(id3 + 5) = *(pos2 + 9);
        *(id3 + 6) = *(pos2 + 10);
        *(id3 + 7) = *(pos2 + 11);
        *(id3 + 8) = '\0';
        if ((*id2 == *id && *(id2 + 1) == *(id + 1) && *(id2 + 2) == *(id + 2) && *(id2 + 3) == *(id + 3) &&
             *(id2 + 4) == *(id + 4) && *(id2 + 5) == *(id + 5)) ||
            (*id3 == *id && *(id3 + 1) == *(id + 1) && *(id3 + 2) == *(id + 2) && *(id3 + 3) == *(id + 3) &&
             *(id3 + 4) == *(id + 4) && *(id3 + 5) == *(id + 5))) {
            pos2 = strstr(pos, "breakfast");
            FILE *fp1 = fopen("hotel.db", "w");
            for (i = 0; i < pos2 - str + 10; i++)
                fprintf(fp1, "%c", str[i]);
            fprintf(fp1, "%d\n", breakChange);
            fprintf(fp1, "nights=%d\n", nightsChange);
            fprintf(fp1, "price=%d\n\n", nightsChange * current_rates.double_rate + breakChange * current_rates.breakfast_rate);
            pos2 = strstr(pos, "[");
            i = pos2 - str;
            while (str[i - 1] != '-') {
                fprintf(fp1, "%c", str[i]);
                i++;//copy the part after revising;
            }
            fclose(fp1);
            free(id2);
            free(id3);
            free(id4);
            return 0;
        }
    } else if (*(pos2 + 7) == 'm') {//the type is family
        pos2 = strstr(pos, "id1");
        *id2 = *(pos2 + 4);
        *(id2 + 1) = *(pos2 + 5);
        *(id2 + 2) = *(pos2 + 6);
        *(id2 + 3) = *(pos2 + 7);
        *(id2 + 4) = *(pos2 + 8);
        *(id2 + 5) = *(pos2 + 9);
        *(id2 + 6) = *(pos2 + 10);
        *(id2 + 7) = *(pos2 + 11);
        *(id2 + 8) = '\0';
        pos2 = strstr(pos, "id2");
        *id3 = *(pos2 + 4);
        *(id3 + 1) = *(pos2 + 5);
        *(id3 + 2) = *(pos2 + 6);
        *(id3 + 3) = *(pos2 + 7);
        *(id3 + 4) = *(pos2 + 8);
        *(id3 + 5) = *(pos2 + 9);
        *(id3 + 6) = *(pos2 + 10);
        *(id3 + 7) = *(pos2 + 11);
        *(id3 + 8) = '\0';
        pos2 = strstr(pos, "id3");
        *id4 = *(pos2 + 4);
        *(id4 + 1) = *(pos2 + 5);
        *(id4 + 2) = *(pos2 + 6);
        *(id4 + 3) = *(pos2 + 7);
        *(id4 + 4) = *(pos2 + 8);
        *(id4 + 5) = *(pos2 + 9);
        *(id4 + 6) = *(pos2 + 10);
        *(id4 + 7) = *(pos2 + 11);
        *(id4 + 8) = '\0';
        if ((*id2 == *id && *(id2 + 1) == *(id + 1) && *(id2 + 2) == *(id + 2) && *(id2 + 3) == *(id + 3) &&
             *(id2 + 4) == *(id + 4) && *(id2 + 5) == *(id + 5)) ||
            (*id3 == *id && *(id3 + 1) == *(id + 1) && *(id3 + 2) == *(id + 2) && *(id3 + 3) == *(id + 3) &&
             *(id3 + 4) == *(id + 4) && *(id3 + 5) == *(id + 5)) ||
            (*id4 == *id && *(id4 + 1) == *(id + 1) && *(id4 + 2) == *(id + 2) && *(id4 + 3) == *(id + 3) &&
             *(id4 + 4) == *(id + 4) && *(id4 + 5) == *(id + 5))) {
            pos2 = strstr(pos, "breakfast");
            FILE *fp1 = fopen("hotel.db", "w");
            for (i = 0; i < pos2 - str + 10; i++)
                fprintf(fp1, "%c", str[i]);
            fprintf(fp1, "%d\n", breakChange);
            fprintf(fp1, "nights=%d\n", nightsChange);
            fprintf(fp1, "price=%d\n\n", nightsChange * current_rates.family_rate + breakChange * current_rates.breakfast_rate);
            pos2 = strstr(pos, "[");
            i = pos2 - str;
            while (str[i - 1] != '-') {
                fprintf(fp1, "%c", str[i]);
                i++;//copy the part after revising;
            }
            fclose(fp1);
            free(id2);
            free(id3);
            free(id4);
            return 0;
        }
        free(id2);
        free(id3);
        free(id4);
        return -1;
    } else if (*(pos2 + 7) == 'r') {//the type is dorm
        char target_id[50];
        sprintf(target_id, "id=%s\n", id);
        char *pos3 = strstr(pos, target_id);
        char *next_room = strstr(pos + 1, "[");
        if (pos3 != NULL && (next_room == NULL || pos3 < next_room)) {
            pos2 = strstr(pos3, "breakfast");
            FILE *fp1 = fopen("hotel.db", "w");
            for (i = 0; i < pos2 - str + 10; i++)
                fprintf(fp1, "%c", str[i]);
            fprintf(fp1, "%d\n", breakChange);
            fprintf(fp1, "nights=%d\n", nightsChange);
            fprintf(fp1, "price=%d\n\n", nightsChange * 20 + breakChange * 15);
            char *pos4 = strstr(pos3, "price");
            pos4 = strstr(pos4, "\n\n");
            if (pos4 != NULL) {
                pos4 += 2;
                i = pos4 - str;
                while (str[i - 1] != '-') {
                    fprintf(fp1, "%c", str[i]);
                    i++;
                }
            }
            fclose(fp1);
            free(id2);
            free(id3);
            free(id4);
            return 0;
        }
    }
    free(id2);
    free(id3);
    free(id4);
    return -1;
}

void checkout(int time1) {//check room by room
    //int count;
    char name[45];
    char id[30];
    char pricei[5];
    char room[5];
    char breakfasti[2];
    int price;
    char str[10000];
    char time2[11];
    long i = 0;
    int changed = 1;
    while (changed) {
        changed = 0;
        i = 0;
        FILE *fp = fopen("hotel.db", "r");
        while (feof(fp) == 0) {
            str[i] = fgetc(fp);
            i++;
        }
        fclose(fp);
    char *pos = strstr(str, "room");//locate a room
    while (pos != NULL) {//when successfully locate a room
        char *pos2 = strstr(pos, "vacant");
        char number;
        number = *(pos2 + 7);
        pos2 = strstr(pos, "ype=");
        if (str[pos2 + 6 - str] == 'r') {//this means it is a dorm//
            *room = *(pos + 5);
            *(room + 1) = *(pos + 6);
            *(room + 2) = *(pos + 7);
            *(room + 3) = *(pos + 8);
            *(room + 4) = '\0';
            if (checkDorm(number, room, time1)) {
                changed = 1;
                break;
            }
        } else if (str[pos2 + 6 - str] == 'n') {//this means single room
            if (number == '0') {
                char *pos3 = strstr(pos2, "arrival");//locate time of arrival
                char *pos4 = strstr(pos3, "nights");//locate the nights
                for (i = 0; i < 10; i++) {
                    *(time2 + i) = str[pos3 - str + 8 + i];
                }
                *(time2 + 10) = '\0';
                char *A = malloc(sizeof(char) * 2);
                *A = str[pos4 + 7 - str];
                *(A + 1) = '\0';
                int a = atoi(A);
                if (time1 == (timeToNumber(time2) + a)) {//this visitor is going to check out today.
                    pos2 = strstr(pos, "name");
                    i = 0;
                    while (str[pos2 + 5 - str + i] != '\n') {
                        *(name + i) = str[pos2 + 5 - str + i];
                        i++;
                    }
                    *(name + i) = '\0';//the end of the name
                    pos2 = strstr(pos, "id");
                    i = 0;
                    while (str[pos2 + 3 - str + i] != '\n') {
                        *(id + i) = str[pos2 + 3 - str + i];
                        i++;
                    }
                    *(id + i) = '\0';
                    pos2 = strstr(pos, "price");
                    i = 0;
                    while (str[pos2 + 6 - str + i] != '\n') {
                        *(pricei + i) = str[pos2 + 6 - str + i];
                        i++;
                    }
                    *(pricei + i) = '\0';
                    price = atoi(pricei);
                    pos2 = strstr(pos, "breakfast");
                    i = 0;
                    *breakfasti = str[pos2 + 10 - str + i];
                    *(breakfasti + 1) = '\0';
                    int breakfast = atoi(breakfasti);
                    *room = *(pos + 5);
                    *(room + 1) = *(pos + 6);
                    *(room + 2) = *(pos + 7);
                    *(room + 3) = *(pos + 8);
                    *(room + 4) = '\0';
                    int roomnum = atoi(room);
                    checkoutCards(name, id, time2, roomnum, a, price, breakfast);
                    FILE *fp1 = fopen("hotel.db", "w");
                    for (i = 0; i < (pos - str + 11); i++)
                        fprintf(fp1, "%c", str[i]);//copy the part before
                    fprintf(fp1, "type=single\n");
                    fprintf(fp1, "vacant=1\n\n");
                    pos = strstr(pos + 1, "[");
                    i = (pos - str);
                    while (str[i - 1] != '-') {
                        fprintf(fp1, "%c", str[i]);
                        i++;
                    }//copy the part after
                    fclose(fp1);
                    changed = 1;
                    break;
                }
            }
        } else if (str[pos2 + 6 - str] == 'u') {//this means double room
            if (number == '0') {
                char *pos3 = strstr(pos2, "arrival");//locate time of arrival
                char *pos4 = strstr(pos3, "nights");//locate the nights
                for (i = 0; i < 10; i++) {
                    *(time2 + i) = str[pos3 - str + 8 + i];
                }
                *(time2 + 10) = '\0';
                char *A = malloc(sizeof(char) * 2);
                *A = str[pos4 + 7 - str];
                *(A + 1) = '\0';
                int a = atoi(A);
                if (time1 == (timeToNumber(time2) + a)) {//this visitor is going to check out today.
                    pos2 = strstr(pos, "name1");
                    i = 0;
                    int j = 0;
                    while (str[pos2 + 6 - str + i] != '\n') {
                        *(name + i) = str[pos2 + 6 - str + i];
                        i++;
                        j++;
                    }
                    pos2 = strstr(pos, "name2");
                    *(name + j) = ';';
                    j++;
                    i = 0;
                    while (str[pos2 + 6 - str + i] != '\n') {
                        *(name + j) = str[pos2 + 6 - str + i];
                        j++;
                        i++;
                    }
                    *(name + j) = '\0';//the end of the name
                    pos2 = strstr(pos, "id1");
                    i = 0;
                    j = 0;
                    while (str[pos2 + 4 - str + i] != '\n') {
                        *(id + i) = str[pos2 + 4 - str + i];
                        i++;
                        j++;
                    }
                    pos2 = strstr(pos, "id2");
                    *(id + j) = ';';
                    j++;
                    i = 0;
                    while (str[pos2 + 4 - str + i] != '\n') {
                        *(id + j) = str[pos2 + 4 - str + i];
                        i++;
                        j++;
                    }
                    *(id + j) = '\0';
                    pos2 = strstr(pos, "price");
                    i = 0;
                    while (str[pos2 + 6 - str + i] != '\n') {
                        *(pricei + i) = str[pos2 + 6 - str + i];
                        i++;
                    }
                    *(pricei + i) = '\0';
                    price = atoi(pricei);
                    pos2 = strstr(pos, "breakfast");
                    i = 0;
                    *breakfasti = str[pos2 + 10 - str + i];
                    *(breakfasti + 1) = '\0';
                    int breakfast = atoi(breakfasti);
                    *room = *(pos + 5);
                    *(room + 1) = *(pos + 6);
                    *(room + 2) = *(pos + 7);
                    *(room + 3) = *(pos + 8);
                    *(room + 4) = '\0';
                    int roomnum = atoi(room);
                    checkoutCards(name, id, time2, roomnum, a, price, breakfast);
                    FILE *fp1 = fopen("hotel.db", "w");
                    if (!fp1) {
                        printf("ERROR IN POS30");
                    }
                    for (i = 0; i < (pos - str + 11); i++)
                        fprintf(fp1, "%c", str[i]);//copy the part before
                    fprintf(fp1, "type=double\n");
                    fprintf(fp1, "vacant=1\n\n");
                    pos = strstr(pos + 1, "[");
                    i = (pos - str);
                    while (str[i - 1] != '-') {
                        fprintf(fp1, "%c", str[i]);
                        i++;
                    }//copy the part after
                    fclose(fp1);
                    changed = 1;
                    break;
                }
            }
        } else if (str[pos2 + 6 - str] == 'm') {//this means family room
            if (number == '0') {
                char *pos3 = strstr(pos2, "arrival");//locate time of arrival
                char *pos4 = strstr(pos3, "nights");//locate the nights
                for (i = 0; i < 10; i++) {
                    *(time2 + i) = str[pos3 - str + 8 + i];
                }
                *(time2 + 10) = '\0';
                char *A = malloc(sizeof(char) * 2);
                *A = str[pos4 + 7 - str];
                *(A + 1) = '\0';
                int a = atoi(A);
                if (time1 == (timeToNumber(time2) + a)) {//this visitor is going to check out today.
                    pos2 = strstr(pos, "name1");
                    i = 0;
                    int j = 0;
                    while (str[pos2 + 6 - str + i] != '\n') {
                        *(name + i) = str[pos2 + 6 - str + i];
                        i++;
                        j++;
                    }
                    pos2 = strstr(pos, "name2");
                    *(name + j) = ';';
                    j++;
                    i = 0;
                    while (str[pos2 + 6 - str + i] != '\n') {
                        *(name + j) = str[pos2 + 6 - str + i];
                        i++;
                        j++;
                    }
                    pos2 = strstr(pos, "name3");
                    *(name + j) = ';';
                    j++;
                    i = 0;
                    while (str[pos2 + 6 - str + i] != '\n') {
                        *(name + j) = str[pos2 + 6 - str + i];
                        i++;
                        j++;
                    }
                    *(name + j) = '\0';//the end of the name
                    pos2 = strstr(pos, "id1");
                    i = 0;
                    j = 0;
                    while (str[pos2 + 4 - str + i] != '\n') {
                        *(id + i) = str[pos2 + 4 - str + i];
                        i++;
                        j++;
                    }
                    pos2 = strstr(pos, "id2");
                    *(id + j) = ';';
                    i = 0;
                    j++;
                    while (str[pos2 + 4 - str + i] != '\n') {
                        *(id + j) = str[pos2 + 4 - str + i];
                        i++;
                        j++;
                    }
                    pos2 = strstr(pos, "id3");
                    *(id + j) = ';';
                    j++;
                    i = 0;
                    while (str[pos2 + 4 - str + i] != '\n') {
                        *(id + j) = str[pos2 + 4 - str + i];
                        i++;
                        j++;
                    }
                    *(id + j) = '\0';
                    pos2 = strstr(pos, "price");
                    i = 0;
                    while (str[pos2 + 6 - str + i] != '\n') {
                        *(pricei + i) = str[pos2 + 6 - str + i];
                        i++;
                    }
                    *(pricei + i) = '\0';
                    price = atoi(pricei);
                    pos2 = strstr(pos, "breakfast");
                    i = 0;
                    *breakfasti = str[pos2 + 10 - str + i];
                    *(breakfasti + 1) = '\0';
                    int breakfast = atoi(breakfasti);
                    *room = *(pos + 5);
                    *(room + 1) = *(pos + 6);
                    *(room + 2) = *(pos + 7);
                    *(room + 3) = *(pos + 8);
                    *(room + 4) = '\0';
                    int roomnum = atoi(room);
                    checkoutCards(name, id, time2, roomnum, a, price, breakfast);
                    FILE *fp1 = fopen("hotel.db", "w");
                    if (!fp1) {
                        printf("ERROR IN POS31");
                    }
                    for (i = 0; i < (pos - str + 11); i++)
                        fprintf(fp1, "%c", str[i]);//copy the part before
                    fprintf(fp1, "type=double\n");
                    fprintf(fp1, "vacant=1\n\n");
                    pos = strstr(pos + 1, "[");
                    i = (pos - str);
                    while (str[i - 1] != '-') {
                        fprintf(fp1, "%c", str[i]);
                        i++;
                    }//copy the part after
                    fclose(fp1);
                    changed = 1;
                    break;
                }
            }
        }
        pos = strstr(pos + 1, "room");
    }

        }
}


long long int timeToNumber(char *time1) {
    char *year = malloc(sizeof(char) * 5);
    char *month = malloc(sizeof(char) * 3);
    char *date = malloc(sizeof(char) * 3);
    *year = *(time1 + 6);
    *(year + 1) = *(time1 + 7);
    *(year + 2) = *(time1 + 8);
    *(year + 3) = *(time1 + 9);
    *(year + 4) = '\0';
    *month = *(time1 + 3);
    *(month + 1) = *(time1 + 4);
    *(month + 2) = '\0';
    *date = *time1;
    *(date + 1) = *(time1 + 1);
    *(date + 2) = '\0';
    int y = atoi(year);
    int m = atoi(month);
    int d = atoi(date);
    free(year);
    free(month);
    free(date);
    m = (m + 9) % 12;
    y = y - m / 10;
    return (365 * y + y / 4 - y / 100 + y / 400 + (m * 306 + 5) / 10 + (d - 1));
}

char *numberToTime(long long int time1) {
    long long int y, mm, ddd, mi, dd;
    y = (10000 * time1 + 14780) / 3652425;
    ddd = time1 - (365 * y + y / 4 - y / 100 + y / 400);
    while (ddd < 0) {
        y = y - 1;
        ddd = time1 - (365 * y + y / 4 - y / 100 + y / 400);
    }
    mi = (100 * ddd + 52) / 3060;
    mm = (mi + 2) % 12 + 1;
    y = y + (mi + 2) / 12;
    dd = ddd - (mi * 306 + 5) / 10 + 1;
    char *time = malloc(sizeof(char) * 11);
    sprintf(time, "%02llu", dd);
    sprintf((time + 3), "%02llu", mm);
    sprintf((time + 6), "%04llu", y);
    *(time + 2) = '/';
    *(time + 5) = '/';
    *(time + 10) = '\0';
    return time;
}

void checkoutCards(char *name, char *id, char *arrival, int room, int nights, int price,
                   int breakfast) {//if there are multiple customers,list names and ids together
    printf("\n");
    printf("  +====================================================+\n");
    printf("  |           RECEIPT  ~  NO-STAR HOTEL                |\n");
    printf("  +----------------------------------------------------+\n");
    printf("  |  Dear %-44s|\n", name);
    printf("  |  Thank you for staying with us!                    |\n");
    printf("  +----------------------------------------------------+\n");
    printf("  |  ID           : %-34s|\n", id);
    printf("  |  Room Number  : %-34d|\n", room);
    printf("  |  Arrival      : %-34s|\n", arrival);
    printf("  |  Nights       : %-34d|\n", nights);
    printf("  |  Breakfasts   : %-34d|\n", breakfast);
    printf("  +----------------------------------------------------+\n");
    printf("  |  TOTAL PRICE  : %-34d|\n", price);
    printf("  +----------------------------------------------------+\n");
    printf("  |  Payment: VISA / MasterCard / Cash                 |\n");
    printf("  |  Hotline: 54749110 | Ctrip.com | Booking.com       |\n");
    printf("  |  See you next time!                                |\n");
    printf("  +====================================================+\n\n");
}

int checkDorm(char number, char *roomNum, int time1) {// the situation when check out the dorm
    FILE *fp = fopen("hotel.db", "r");
    char str[10000];
    int i = 0, price;
    while (feof(fp) == 0) {//not reach the end//
        str[i] = fgetc(fp);
        i++;
    }
    fclose(fp);
    char *pos = strstr(str, roomNum);
    char *pos2;
    char name[45];
    char id[30];
    char pricei[5];
    char breakfasti[2];
    char time2[12];
    char A[2];

    int num_visitors = 6 - (number - '0');
    char *current_pos = pos;
    int v;
    for (v = 0; v < num_visitors; v++) {
        char *visitor_name_pos = strstr(current_pos + 1, "name");
        if (visitor_name_pos == NULL || visitor_name_pos > strstr(pos + 1, "[")) {
            break; // Sanity check, should not happen if DB is correct
        }
        
        char *pos3 = strstr(visitor_name_pos, "arrival");
        char *pos4 = strstr(visitor_name_pos, "nights");
        for (i = 0; i < 10; i++) {
            *(time2 + i) = str[pos3 - str + 8 + i];
        }
        *(time2 + 10) = '\0';
        *A = str[pos4 + 7 - str];
        *(A + 1) = '\0';
        int a = atoi(A);
        
        if (time1 == (timeToNumber(time2) + a)) { // Checkout time matches!
            i = 0;
            while (str[visitor_name_pos + 5 - str + i] != '\n') {
                *(name + i) = str[visitor_name_pos + 5 - str + i];
                i++;
            }
            *(name + i) = '\0';
            pos2 = strstr(visitor_name_pos, "id");
            i = 0;
            while (str[pos2 + 3 - str + i] != '\n') {
                *(id + i) = str[pos2 + 3 - str + i];
                i++;
            }
            *(id + i) = '\0';
            pos2 = strstr(visitor_name_pos, "price");
            i = 0;
            while (str[pos2 + 6 - str + i] != '\n') {
                *(pricei + i) = str[pos2 + 6 - str + i];
                i++;
            }
            *(pricei + i) = '\0';
            price = atoi(pricei);
            pos2 = strstr(visitor_name_pos, "breakfast");
            i = 0;
            *breakfasti = str[pos2 + 10 - str + i];
            *(breakfasti + 1) = '\0';
            int breakfast = atoi(breakfasti);
            int roomNumi = atoi(roomNum);
            checkoutCards(name, id, time2, roomNumi, a, price, breakfast);
            
            FILE *fp1 = fopen("hotel.db", "w");
            if (!fp1) {
                printf("ERROR IN POS2");
            }
            // Copy before room block
            for (i = 0; i < (pos - str + 6); i++)
                fprintf(fp1, "%c", str[i]);
                
            fprintf(fp1, "type=dorm\n");
            int vacant = (number - '0') + 1;
            fprintf(fp1, "vacant=%d\n", vacant);
            if (vacant < 6) {
                fprintf(fp1, "visitors=%d\n", 6 - vacant);
            } else {
                fprintf(fp1, "visitors=0\n\n");
            }
            
            // Find start of visitors
            char *start_of_visitors = strstr(pos, "visitors");
            start_of_visitors = strstr(start_of_visitors, "\n") + 1;
            
            // Copy earlier visitors in this room
            for (i = (start_of_visitors - str); i < (visitor_name_pos - str); i++)
                fprintf(fp1, "%c", str[i]);
                
            // Skip this visitor by finding the next visitor or next room
            char *next_visitor = strstr(visitor_name_pos + 1, "name");
            char *next_room = strstr(visitor_name_pos + 1, "[");
            char *skip_to;
            if (next_visitor != NULL && (next_room == NULL || next_visitor < next_room)) {
                skip_to = next_visitor;
            } else {
                skip_to = next_room;
            }
            
            // If we are emptying the room completely, ensure there are no trailing chars before [
            if (vacant == 6) {
                 skip_to = next_room;
            }
            
            // Copy the rest of the database
            i = skip_to - str;
            while (str[i - 1] != '-') {
                fprintf(fp1, "%c", str[i]);
                i++;
            }
            fclose(fp1);
            return 1;
        }
        current_pos = visitor_name_pos;
    }
    return 0;
}

void listAvailableRooms(void) {
    char str[10000];
    long i = 0;
    FILE *fp = fopen("hotel.db", "r");
    if (!fp) return;
    while (feof(fp) == 0) {
        str[i] = fgetc(fp);
        i++;
    }
    str[i-1] = '\0';
    fclose(fp);

    printf("\n--- AVAILABLE ROOMS ---\n");
    char *pos = strstr(str, "[room ");
    int count = 0;
    while (pos != NULL) {
        char roomNum[10] = {0};
        strncpy(roomNum, pos + 6, 4);
        
        char *typePos = strstr(pos, "type=");
        char typeStr[20] = {0};
        if (typePos) {
            int j = 0;
            typePos += 5;
            while(typePos[j] != '\n' && typePos[j] != '\0') {
                typeStr[j] = typePos[j];
                j++;
            }
        }
        
        char *vacantPos = strstr(pos, "vacant=");
        if (vacantPos) {
            int vacant = vacantPos[7] - '0';
            if (vacant > 0) {
                if (strstr(typeStr, "dorm") != NULL) {
                    printf("Room %s (Dorm) - %d beds available\n", roomNum, vacant);
                } else {
                    printf("Room %s (%s) - Available\n", roomNum, typeStr);
                }
                count++;
            }
        }
        pos = strstr(pos + 1, "[room ");
    }
    if (count == 0) printf("No rooms available.\n");
    printf("-----------------------\n");
}

void listCheckedInGuests(void) {
    char str[10000];
    long i = 0;
    FILE *fp = fopen("hotel.db", "r");
    if (!fp) return;
    while (feof(fp) == 0) {
        str[i] = fgetc(fp);
        i++;
    }
    str[i-1] = '\0';
    fclose(fp);

    printf("\n--- CHECKED-IN GUESTS ---\n");
    char *pos = strstr(str, "[room ");
    int count = 0;
    while (pos != NULL) {
        char *next_pos = strstr(pos + 1, "[room ");
        char roomBlock[2000] = {0};
        if (next_pos) {
            strncpy(roomBlock, pos, next_pos - pos);
        } else {
            strcpy(roomBlock, pos);
        }
        
        char roomNum[10] = {0};
        strncpy(roomNum, pos + 6, 4);
        
        char *vacantPos = strstr(roomBlock, "vacant=");
        if (vacantPos) {
            int vacant = vacantPos[7] - '0';
            if (strstr(roomBlock, "type=dorm")) {
                if (vacant < 6) {
                    printf("Room %s (Dorm): Occupied (%d beds)\n", roomNum, 6 - vacant);
                    char *namePos = strstr(roomBlock, "name=");
                    while(namePos) {
                        char name[50] = {0};
                        sscanf(namePos + 5, "%[^\n]", name);
                        printf("  - %s\n", name);
                        namePos = strstr(namePos + 1, "name=");
                    }
                    count++;
                }
            } else {
                if (vacant == 0) {
                    printf("Room %s:\n", roomNum);
                    char *namePos1 = strstr(roomBlock, "name1=");
                    char *namePos = strstr(roomBlock, "name=");
                    if (namePos1) {
                        char name[50] = {0};
                        sscanf(namePos1 + 6, "%[^\n]", name);
                        printf("  - %s\n", name);
                        char *namePos2 = strstr(roomBlock, "name2=");
                        if (namePos2) {
                            sscanf(namePos2 + 6, "%[^\n]", name);
                            printf("  - %s\n", name);
                        }
                        char *namePos3 = strstr(roomBlock, "name3=");
                        if (namePos3) {
                            sscanf(namePos3 + 6, "%[^\n]", name);
                            printf("  - %s\n", name);
                        }
                    } else if (namePos) {
                        char name[50] = {0};
                        sscanf(namePos + 5, "%[^\n]", name);
                        printf("  - %s\n", name);
                    }
                    count++;
                }
            }
        }
        pos = next_pos;
    }
    if (count == 0) printf("No guests checked in.\n");
    printf("-------------------------\n");
}

void searchDatabase(char *query) {
    char str[10000];
    long i = 0;
    FILE *fp = fopen("hotel.db", "r");
    if (!fp) return;
    while (feof(fp) == 0) {
        str[i] = fgetc(fp);
        i++;
    }
    str[i-1] = '\0';
    fclose(fp);

    printf("\n--- SEARCH RESULTS FOR '%s' ---\n", query);
    char *pos = strstr(str, "[room ");
    int count = 0;
    while (pos != NULL) {
        char *next_pos = strstr(pos + 1, "[room ");
        char roomBlock[2000] = {0};
        if (next_pos) {
            strncpy(roomBlock, pos, next_pos - pos);
        } else {
            strcpy(roomBlock, pos);
        }
        
        if (strstr(roomBlock, query) != NULL) {
            printf("%s\n", roomBlock);
            count++;
        }
        pos = next_pos;
    }
    if (count == 0) printf("No matching room or guest found.\n");
    printf("---------------------------------\n");
}

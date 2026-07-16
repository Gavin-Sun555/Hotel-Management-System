#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hotel-ll.h"
#include "hotel-mt.h"
#include "hotel-config.h"
#include "hotel-db.h"

int initializeDatabase(int numSingle, int numDouble, int numFamily, int numDorm) {
    FILE *fp = fopen("hotel.db", "w");
    if (fp == NULL) { return -1; }
    
    int roomNum = 100; // start at 101
    
    for(int i = 0; i < numSingle; i++) {
        roomNum++;
        fprintf(fp, "\n[room %d]\n", roomNum);
        fprintf(fp, "type=single\n");
        fprintf(fp, "vacant=1\n");
    }
    for(int i = 0; i < numDouble; i++) {
        roomNum++;
        fprintf(fp, "\n[room %d]\n", roomNum);
        fprintf(fp, "type=double\n");
        fprintf(fp, "vacant=1\n");
    }
    for(int i = 0; i < numFamily; i++) {
        roomNum++;
        fprintf(fp, "\n[room %d]\n", roomNum);
        fprintf(fp, "type=family\n");
        fprintf(fp, "vacant=1\n");
    }
    for(int i = 0; i < numDorm; i++) {
        roomNum++;
        fprintf(fp, "\n[room %d]\n", roomNum);
        fprintf(fp, "type=dorm\n");
        fprintf(fp, "vacant=6\n");
        fprintf(fp, "visitors=0\n");
    }
    fclose(fp);
    return 0;
}

void checkin(node_t *a, char *time1) {
    int vis = *((int *) (a->ch));
    char *number;
    if (vis == 0) {
        number = searchSingle();
        if (number == NULL) {
            printf("\n  [!] NOTICE: Sorry %s, all single rooms are currently full.\n\n",
                   (char *) a->next->ch);//the hotel is full
            free(number);
            freeList(&a);
            return;
        }
        checkinPrivateRoom(number, a, time1, 0);
        checkinCards(number, a);
    } else if (vis == 1) {
        number = searchDouble();
        if (number == NULL) {
            printf("\n  [!] NOTICE: Sorry %s and %s, all double rooms are currently full.\n\n",
                   (char *) a->next->ch, (char *) a->next->next->next->ch);//the hotel is full
            free(number);
            freeList(&a);
            return;
        }
        checkinPrivateRoom(number, a, time1, 1);
        checkinCards(number, a);
    } else if (vis == 2) {
        number = searchFamily();
        if (number == NULL) {
            printf("\n  [!] NOTICE: Sorry %s, %s and %s, all family rooms are currently full.\n\n",
                   (char *) a->next->ch, (char *) a->next->next->next->ch,
                   (char *) a->next->next->next->next->next->ch);//the hotel is full
            free(number);
            freeList(&a);
            return;
        }
        checkinPrivateRoom(number, a, time1, 2);
        checkinCards(number, a);
    } else if (vis == 3) {
        number = searchDorm();
        if (number == NULL) {
            printf("\n  [!] NOTICE: All dorm beds are currently full.\n\n");
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

char *searchSingle(void) {
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

char *searchDouble(void) {
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

char *searchFamily(void) {
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

char *searchDorm(void) {
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
    int type = *((int *) (guest->ch));
    printf("\n  +====================================================+\n");
    printf("  |          CHECK-IN CARD  ~  NO-STAR HOTEL           |\n");
    printf("  +----------------------------------------------------+\n");
    printf("  |  Room Number  : %-34s|\n", room);
    if (type != 3)
        printf("  |  Guests       : %-34d|\n", (type + 1));
    else
        printf("  |  Guests       : %-34d|\n", 1);
    printf("  +----------------------------------------------------+\n");
    
    node_t *curr = guest->next;
    if (type == 0 || type == 3) {
        printf("  |  Name         : %-34s|\n", (char *) curr->ch);
        curr = curr->next;
        printf("  |  ID           : %-34s|\n", (char *) curr->ch);
        curr = curr->next;
    } else if (type == 1) {
        printf("  |  Name 1       : %-34s|\n", (char *) curr->ch);
        curr = curr->next;
        printf("  |  ID 1         : %-34s|\n", (char *) curr->ch);
        curr = curr->next;
        printf("  |  Name 2       : %-34s|\n", (char *) curr->ch);
        curr = curr->next;
        printf("  |  ID 2         : %-34s|\n", (char *) curr->ch);
        curr = curr->next;
    } else if (type == 2) {
        printf("  |  Name 1       : %-34s|\n", (char *) curr->ch);
        curr = curr->next;
        printf("  |  ID 1         : %-34s|\n", (char *) curr->ch);
        curr = curr->next;
        printf("  |  Name 2       : %-34s|\n", (char *) curr->ch);
        curr = curr->next;
        printf("  |  ID 2         : %-34s|\n", (char *) curr->ch);
        curr = curr->next;
        printf("  |  Name 3       : %-34s|\n", (char *) curr->ch);
        curr = curr->next;
        printf("  |  ID 3         : %-34s|\n", (char *) curr->ch);
        curr = curr->next;
    }
    
    key = *(int *) curr->ch;
    printf("  |  Keys         : %-34d|\n", key);
    curr = curr->next;
    breakfast = *(int *) curr->ch;
    printf("  |  Breakfasts   : %-34d|\n", breakfast);
    curr = curr->next;
    int nights = *(int *) curr->ch;
    printf("  |  Nights       : %-34d|\n", nights);
    
    int rate = (type == 0) ? current_rates.single_rate : ((type == 1) ? current_rates.double_rate : ((type == 2) ? current_rates.family_rate : current_rates.dorm_rate));
    price = nights * rate + breakfast * current_rates.breakfast_rate;
    
    printf("  +----------------------------------------------------+\n");
    printf("  |  TOTAL PRICE  : %-34d|\n", price);
    printf("  +----------------------------------------------------+\n");
    printf("  |  Enjoy your stay! Contact front desk for help.     |\n");
    printf("  +====================================================+\n\n");
}


node_t *manualInputVisitor(void) {
    int *type = malloc(sizeof(int));
    printf("\n--- New Guest Check-In ---\n");
    printf("Select Room Type (0: Single, 1: Double, 2: Family, 3: Dorm): ");
    scanf("%d", type);

    node_t *guest = initList(type);
    
    int num_people = 1;
    if (*type == 1) num_people = 2;
    else if (*type == 2) num_people = 3;

    for (int i = 0; i < num_people; i++) {
        char *name = malloc(sizeof(char) * 45);
        char *id = malloc(sizeof(char) * 30);
        printf("Enter Guest %d Name (no spaces): ", i + 1);
        scanf("%s", name);
        printf("Enter Guest %d ID: ", i + 1);
        scanf("%s", id);
        insertLastList(&guest, name);
        insertLastList(&guest, id);
    }

    int *keys = malloc(sizeof(int));
    printf("Enter number of keys (deposit): ");
    scanf("%d", keys);
    insertLastList(&guest, keys);

    int *breakfast = malloc(sizeof(int));
    printf("Enter number of breakfasts: ");
    scanf("%d", breakfast);
    insertLastList(&guest, breakfast);

    int *nights = malloc(sizeof(int));
    printf("Enter number of nights: ");
    scanf("%d", nights);
    insertLastList(&guest, nights);

    return guest;
}

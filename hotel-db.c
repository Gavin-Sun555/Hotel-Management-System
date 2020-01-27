#include "hotel-ll.h"
#include "hotel-db.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void CheckinSingleRoom(char* number,node_t* guest,char* time1){
    char str[10000];
    int i=0;
    int key,breakfast,nights;
    FILE* fp=fopen("hotel.db","r");
    if(!fp){
        printf("ERROR IN POS50");}

    while (feof(fp)==0){//not reach the end//
        str[i]=fgetc(fp);
        i++;}
    char* pos=strstr(str,number);//rewrite this part, finally print.
    fclose(fp);
    FILE* fp1=fopen("hotel.db","w");
    for(i=0;i<(pos-str+6);i++)
        fprintf(fp1,"%c",str[i]);//copy the part before
    fprintf(fp1,"type=single\n");
    fprintf(fp1,"vacant=0\n");
    fprintf(fp1,"name=%s\n",(char*)guest->next->ch);
    fprintf(fp1,"id=%s\n",(char*)guest->next->next->ch);
    fprintf(fp1,"arrival=%s\n",time1);
    key=*(int*)guest->next->next->next->ch;
    fprintf(fp1,"key=%d\n",key);
    breakfast=*(int*)guest->next->next->next->next->ch;
    fprintf(fp1,"breakfast=%d\n",breakfast);
    nights=*(int*)guest->next->next->next->next->next->ch;
    fprintf(fp1,"nights=%d\n",nights);
    fprintf(fp1,"price=%d\n\n",nights*60+breakfast*15);
    pos=strstr(pos+1,"[");
    i=(pos-str);
    while(str[i-1]!='-'){
        fprintf(fp1,"%c",str[i]);
        i++;
    }//copy the part after
    fclose(fp1);
}
void CheckinDoubleRoom(char* number,node_t* guest,char* time1){
    char str[10000];
    int i=0;
    int key,breakfast,nights;
    FILE* fp=fopen("hotel.db","r");
    if(!fp){
        printf("ERROR IN POS50");}
    while (feof(fp)==0){//not reach the end//
        str[i]=fgetc(fp);
        i++;}
    char* pos=strstr(str,number);//rewrite this part, finally print.
    fclose(fp);
    FILE* fp1=fopen("hotel.db","w");
    for(i=0;i<(pos-str+6);i++)
        fprintf(fp1,"%c",str[i]);//copy the part before
    fprintf(fp1,"type=double\n");
    fprintf(fp1,"vacant=0\n");
    fprintf(fp1,"name1=%s\n",(char*)guest->next->ch);
    fprintf(fp1,"id1=%s\n",(char*)guest->next->next->ch);
    fprintf(fp1,"name2=%s\n",(char*)guest->next->next->next->ch);
    fprintf(fp1,"id2=%s\n",(char*)guest->next->next->next->next->ch);
    fprintf(fp1,"arrival=%s\n",time1);
    key=*(int*)guest->next->next->next->next->next->ch;
    fprintf(fp1,"key=%d\n",key);
    breakfast=*(int*)guest->next->next->next->next->next->next->ch;
    fprintf(fp1,"breakfast=%d\n",breakfast);
    nights=*(int*)guest->next->next->next->next->next->next->next->ch;
    fprintf(fp1,"nights=%d\n",nights);
    fprintf(fp1,"price=%d\n\n",nights*80+breakfast*15);
    pos=strstr(pos+1,"[");
    i=(pos-str);
    while(str[i-1]!='-'){
        fprintf(fp1,"%c",str[i]);
        i++;
    }//copy the part after
    fclose(fp1);
}
void CheckinFamilyRoom(char* number,node_t* guest,char* time1){
    char str[10000];
    int i=0;
    int key,breakfast,nights;
    FILE* fp=fopen("hotel.db","r");
    if(!fp){
        printf("ERROR IN POS50");}
    while (feof(fp)==0){//not reach the end//
        str[i]=fgetc(fp);
        i++;}
    char* pos=strstr(str,number);//rewrite this part, finally print.
    fclose(fp);
    FILE* fp1=fopen("hotel.db","w");
    for(i=0;i<(pos-str+6);i++)
        fprintf(fp1,"%c",str[i]);//copy the part before
    fprintf(fp1,"type=family\n");
    fprintf(fp1,"vacant=0\n");
    fprintf(fp1,"name1=%s\n",(char*)guest->next->ch);
    fprintf(fp1,"id1=%s\n",(char*)guest->next->next->ch);
    fprintf(fp1,"name2=%s\n",(char*)guest->next->next->next->ch);
    fprintf(fp1,"id2=%s\n",(char*)guest->next->next->next->next->ch);
    fprintf(fp1,"name3=%s\n",(char*)guest->next->next->next->next->next->ch);
    fprintf(fp1,"id3=%s\n",(char*)guest->next->next->next->next->next->next->ch);
    fprintf(fp1,"arrival=%s\n",time1);
    key=*(int*)guest->next->next->next->next->next->next->next->ch;
    fprintf(fp1,"key=%d\n",key);
    breakfast=*(int*)guest->next->next->next->next->next->next->next->next->ch;
    fprintf(fp1,"breakfast=%d\n",breakfast);
    nights=*(int*)guest->next->next->next->next->next->next->next->next->next->ch;
    fprintf(fp1,"nights=%d\n",nights);
    fprintf(fp1,"price=%d\n\n",nights*100+breakfast*15);
    pos=strstr(pos+1,"[");
    i=(pos-str);
    while(str[i-1]!='-'){
        fprintf(fp1,"%c",str[i]);
        i++;
    }//copy the part after
    fclose(fp1);
}
void CheckinDorm(char* number,node_t* guest, char* time1){
    char str[10000];
    int i=0;
    int key,breakfast,nights;
    FILE* fp=fopen("hotel.db","r");
    if(!fp){
        printf("ERROR IN POS50");}
    while (feof(fp)==0){//not reach the end//
        str[i]=fgetc(fp);
        i++;}
    char* pos=strstr(str,number);//rewrite this part, finally print.
    fclose(fp);
    char* pos2=strstr(pos,"vacant");
    char* pos3=strstr(pos2,"[");
    if(*(pos2+7)=='1'){//only one bed left
        str[pos2-str+7]='0';
        str[pos2-str+17]='6';
        FILE* fp1=fopen("hotel.db","w");
        for(i=0;i<(pos3-str-0.5);i++)
            fprintf(fp1,"%c",str[i]);//copy the part before
        fprintf(fp1,"name=%s\n",(char*)guest->next->ch);
        fprintf(fp1,"id=%s\n",(char*)guest->next->next->ch);
        fprintf(fp1,"arrival=%s\n",time1);
        key=*(int*)guest->next->next->next->ch;
        fprintf(fp1,"key=%d\n",key);
        breakfast=*(int*)guest->next->next->next->next->ch;
        fprintf(fp1,"breakfast=%d\n",breakfast);
        nights=*(int*)guest->next->next->next->next->next->ch;
        fprintf(fp1,"nights=%d\n",nights);
        fprintf(fp1,"price=%d\n\n",nights*20+breakfast*15);
        i=pos3-str;
        while(str[i-1]!='-'){
            fprintf(fp1,"%c",str[i]);
            i++;
        }
    fclose(fp1);}//copy the part after
    else if(*(pos2+7)=='2'){//only two bed left
        str[pos2-str+7]='1';
        str[pos2-str+17]='5';
        FILE* fp1=fopen("hotel.db","w");
        for(i=0;i<(pos3-str-0.5);i++)
            fprintf(fp1,"%c",str[i]);//copy the part before
        fprintf(fp1,"name=%s\n",(char*)guest->next->ch);
        fprintf(fp1,"id=%s\n",(char*)guest->next->next->ch);
        fprintf(fp1,"arrival=%s\n",time1);
        key=*(int*)guest->next->next->next->ch;
        fprintf(fp1,"key=%d\n",key);
        breakfast=*(int*)guest->next->next->next->next->ch;
        fprintf(fp1,"breakfast=%d\n",breakfast);
        nights=*(int*)guest->next->next->next->next->next->ch;
        fprintf(fp1,"nights=%d\n",nights);
        fprintf(fp1,"price=%d\n\n",nights*20+breakfast*15+key);
        i=pos3-str;
        while(str[i-1]!='-'){
            fprintf(fp1,"%c",str[i]);
            i++;//copy the part after revising;
        }
    fclose(fp1);}
    else if(*(pos2+7)=='3'){//only two bed left
        str[pos2-str+7]='2';
        str[pos2-str+17]='4';
        FILE* fp1=fopen("hotel.db","w");
        for(i=0;i<(pos3-str-0.5);i++)
            fprintf(fp1,"%c",str[i]);//copy the part before
        fprintf(fp1,"name=%s\n",(char*)guest->next->ch);
        fprintf(fp1,"id=%s\n",(char*)guest->next->next->ch);
        fprintf(fp1,"arrival=%s\n",time1);
        key=*(int*)guest->next->next->next->ch;
        fprintf(fp1,"key=%d\n",key);
        breakfast=*(int*)guest->next->next->next->next->ch;
        fprintf(fp1,"breakfast=%d\n",breakfast);
        nights=*(int*)guest->next->next->next->next->next->ch;
        fprintf(fp1,"nights=%d\n",nights);
        fprintf(fp1,"price=%d\n\n",nights*20+breakfast*15);
        i=pos3-str;
        while(str[i-1]!='-'){
            fprintf(fp1,"%c",str[i]);
            i++;//copy the part after revising;
        }fclose(fp1);}
    else if(*(pos2+7)=='4'){//only two bed left
        str[pos2-str+7]='3';
        str[pos2-str+17]='3';
        FILE* fp1=fopen("hotel.db","w");
        for(i=0;i<(pos3-str-0.5);i++)
            fprintf(fp1,"%c",str[i]);//copy the part before
        fprintf(fp1,"name=%s\n",(char*)guest->next->ch);
        fprintf(fp1,"id=%s\n",(char*)guest->next->next->ch);
        fprintf(fp1,"arrival=%s\n",time1);
        key=*(int*)guest->next->next->next->ch;
        fprintf(fp1,"key=%d\n",key);
        breakfast=*(int*)guest->next->next->next->next->ch;
        fprintf(fp1,"breakfast=%d\n",breakfast);
        nights=*(int*)guest->next->next->next->next->next->ch;
        fprintf(fp1,"nights=%d\n",nights);
        fprintf(fp1,"price=%d\n\n",nights*20+breakfast*15);
        i=pos3-str;
        while(str[i-1]!='-'){
            fprintf(fp1,"%c",str[i]);
            i++;//copy the part after revising;
        }fclose(fp1);}
    else if(*(pos2+7)=='5'){//only two bed left
        str[pos2-str+7]='4';
        str[pos2-str+17]='2';
        FILE* fp1=fopen("hotel.db","w");
        for(i=0;i<(pos3-str-0.5);i++)
            fprintf(fp1,"%c",str[i]);//copy the part before
        fprintf(fp1,"name=%s\n",(char*)guest->next->ch);
        fprintf(fp1,"id=%s\n",(char*)guest->next->next->ch);
        fprintf(fp1,"arrival=%s\n",time1);
        key=*(int*)guest->next->next->next->ch;
        fprintf(fp1,"key=%d\n",key);
        breakfast=*(int*)guest->next->next->next->next->ch;
        fprintf(fp1,"breakfast=%d\n",breakfast);
        nights=*(int*)guest->next->next->next->next->next->ch;
        fprintf(fp1,"nights=%d\n",nights);
        fprintf(fp1,"price=%d\n\n",nights*20+breakfast*15);
        i=pos3-str;
        while(str[i-1]!='-'){
            fprintf(fp1,"%c",str[i]);
            i++;//copy the part after revising;
        }fclose(fp1);}
    else if(*(pos2+7)=='6'){
        str[pos2-str+7]='5';
        str[pos2-str+17]='1';
        FILE* fp1=fopen("hotel.db","w");
        for(i=0;i<(pos3-str-0.5);i++)
            fprintf(fp1,"%c",str[i]);//copy the part before
        fprintf(fp1,"\nname=%s\n",(char*)guest->next->ch);
        fprintf(fp1,"id=%s\n",(char*)guest->next->next->ch);
        fprintf(fp1,"arrival=%s\n",time1);
        key=*(int*)guest->next->next->next->ch;
        fprintf(fp1,"key=%d\n",key);
        breakfast=*(int*)guest->next->next->next->next->ch;
        fprintf(fp1,"breakfast=%d\n",breakfast);
        nights=*(int*)guest->next->next->next->next->next->ch;
        fprintf(fp1,"nights=%d\n",nights);
        fprintf(fp1,"price=%d\n\n",nights*20+breakfast*15);
        i=pos3-str;
        while(str[i-1]!='-'){
            fprintf(fp1,"%c",str[i]);
            i++;//copy the part after revising;
        }fclose(fp1);}

}
int Changebreakfastnights(char* number,char* id, int breakchange, int nightschange) {
    char str[10000];
    int i = 0;
    char* id2=malloc(sizeof(char)*9);
    char* id3=malloc(sizeof(char)*9);
    char* id4=malloc(sizeof(char)*9);
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
        { pos2 = strstr(pos, "breakfast");
        FILE *fp1 = fopen("hotel.db", "w");
        for (i = 0; i < pos2 - str + 10; i++)
            fprintf(fp1, "%c", str[i]);
        fprintf(fp1, "%d\n", breakchange);
        fprintf(fp1, "nights=%d\n", nightschange);
        fprintf(fp1, "price=%d\n\n", nightschange * 60 + breakchange * 15);
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
        return 0;}

        else{
            free(id2);
            free(id3);
            free(id4);
            return -1;
        }

    }
    else if (*(pos2 + 7) == 'u'){//the type is double
        pos2=strstr(pos,"id1");
        *id2=*(pos2+4);
        *(id2+1)=*(pos2+5);
        *(id2+2)=*(pos2+6);
        *(id2+3)=*(pos2+7);
        *(id2+4)=*(pos2+8);
        *(id2+5)=*(pos2+9);
        *(id2+6)=*(pos2+10);
        *(id2+7)=*(pos2+11);
        *(id2+8)='\0';
        pos2=strstr(pos,"id2");
        *id3=*(pos2+4);
        *(id3+1)=*(pos2+5);
        *(id3+2)=*(pos2+6);
        *(id3+3)=*(pos2+7);
        *(id3+4)=*(pos2+8);
        *(id3+5)=*(pos2+9);
        *(id3+6)=*(pos2+10);
        *(id3+7)=*(pos2+11);
        *(id3+8)='\0';
        if ((*id2 == *id && *(id2 + 1) == *(id + 1) && *(id2 + 2) == *(id + 2) && *(id2 + 3) == *(id + 3) &&
            *(id2 + 4) == *(id + 4) && *(id2 + 5) == *(id + 5))||(*id3 == *id && *(id3 + 1) == *(id + 1) && *(id3 + 2) == *(id + 2) && *(id3 + 3) == *(id + 3) &&
                                                                  *(id3 + 4) == *(id + 4) && *(id3 + 5) == *(id + 5)))
        {pos2=strstr(pos,"breakfast");
            FILE* fp1=fopen("hotel.db","w");
            for(i=0;i<pos2-str+10;i++)
                fprintf(fp1,"%c",str[i]);
            fprintf(fp1,"%d\n",breakchange);
            fprintf(fp1,"nights=%d\n",nightschange);
            fprintf(fp1,"price=%d\n\n",nightschange*80+breakchange*15);
            pos2=strstr(pos,"[");
            i=pos2-str;
            while(str[i-1]!='-'){
                fprintf(fp1,"%c",str[i]);
                i++;//copy the part after revising;
            }
            fclose(fp1);
            free(id2);free(id3);free(id4);
            return 0;
        }
    }
    else if (*(pos2 + 7) == 'm'){//the type is family
        pos2=strstr(pos,"id1");
        *id2=*(pos2+4);
        *(id2+1)=*(pos2+5);
        *(id2+2)=*(pos2+6);
        *(id2+3)=*(pos2+7);
        *(id2+4)=*(pos2+8);
        *(id2+5)=*(pos2+9);
        *(id2+6)=*(pos2+10);
        *(id2+7)=*(pos2+11);
        *(id2+8)='\0';
        pos2=strstr(pos,"id2");
        *id3=*(pos2+4);
        *(id3+1)=*(pos2+5);
        *(id3+2)=*(pos2+6);
        *(id3+3)=*(pos2+7);
        *(id3+4)=*(pos2+8);
        *(id3+5)=*(pos2+9);
        *(id3+6)=*(pos2+10);
        *(id3+7)=*(pos2+11);
        *(id3+8)='\0';
        pos2=strstr(pos,"id3");
        *id4=*(pos2+4);
        *(id4+1)=*(pos2+5);
        *(id4+2)=*(pos2+6);
        *(id4+3)=*(pos2+7);
        *(id4+4)=*(pos2+8);
        *(id4+5)=*(pos2+9);
        *(id4+6)=*(pos2+10);
        *(id4+7)=*(pos2+11);
        *(id4+8)='\0';
        if((*id2 == *id && *(id2 + 1) == *(id + 1) && *(id2 + 2) == *(id + 2) && *(id2 + 3) == *(id + 3) &&
           *(id2 + 4) == *(id + 4) && *(id2 + 5) == *(id + 5))||(*id3 == *id && *(id3 + 1) == *(id + 1) && *(id3 + 2) == *(id + 2) && *(id3 + 3) == *(id + 3) &&
*(id3 + 4) == *(id + 4) && *(id3 + 5) == *(id + 5))||(*id4 == *id && *(id4 + 1) == *(id + 1) && *(id4 + 2) == *(id + 2) && *(id4 + 3) == *(id + 3) &&
                                                      *(id4 + 4) == *(id + 4) && *(id4 + 5) == *(id + 5)))
        {pos2=strstr(pos,"breakfast");
            FILE* fp1=fopen("hotel.db","w");
            for(i=0;i<pos2-str+10;i++)
                fprintf(fp1,"%c",str[i]);
            fprintf(fp1,"%d\n",breakchange);
            fprintf(fp1,"nights=%d\n",nightschange);
            fprintf(fp1,"price=%d\n\n",nightschange*100+breakchange*15);
            pos2=strstr(pos,"[");
            i=pos2-str;
            while(str[i-1]!='-'){
                fprintf(fp1,"%c",str[i]);
                i++;//copy the part after revising;
            }
            fclose(fp1);
            free(id2);free(id3);free(id4);
            return 0;
        }free(id2);free(id3);free(id4);return-1;
    }
    free(id2);free(id3);free(id4);return-1;
}

void checkout(int time1) {//check room by room
    //int count;
    char *name = malloc(sizeof(char) * 45);
    char *id = malloc(sizeof(char) * 30);//this two are long to target the situation of the family room.
    char *pricei = malloc(sizeof(char) * 5);
    char *room = malloc(sizeof(char) * 5);
    char *night = malloc(sizeof(char) * 2);// give the memory to store these data.
    char *breakfasti = malloc(sizeof(char) * 2);
    int price;//this two variable are then stored in type int
    char str[10000];
    char *time2 = calloc(sizeof(char), 11);
    int i = 0;
    FILE *fp = fopen("hotel.db", "r");
    while (feof(fp) == 0) {//not reach the end//
        str[i] = fgetc(fp);
        i++;
    }
    fclose(fp);//It is not an efficient way to read the whole data base. But it is easiest to use:)
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
            checkdorm(number, room, time1);
        } else if (str[pos2 + 6 - str] == 'n') {//this means single room
            if(number=='0'){
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
            if (time1 == (timetonumber(time2) + a)) {//this vistor is going to check out today.
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
                checkoutcards(name, id, time2, roomnum, a, price, breakfast);
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
                if (time1 == (timetonumber(time2) + a)) {//this vistor is going to check out today.
                    pos2 = strstr(pos, "name1");
                    i = 0;int j=0;
                    while (str[pos2 + 6 - str + i] != '\n') {
                        *(name + i) = str[pos2 + 6 - str + i];
                        i++;j++;
                    }
                    pos2 = strstr(pos, "name2");
                    *(name + j) = ';';
                    j++;i=0;
                    while (str[pos2 + 6 - str + i] != '\n') {
                        *(name + j) = str[pos2 + 6 - str + i];
                        j++;i++;
                    }
                    *(name + j) = '\0';//the end of the name
                    pos2 = strstr(pos, "id1");
                    i = 0;j=0;
                    while (str[pos2 + 4 - str + i] != '\n') {
                        *(id + i) = str[pos2 + 4 - str + i];
                        i++;j++;
                    }
                    pos2 = strstr(pos, "id2");
                    *(id + j) = ';';
                    j++;i=0;
                    while (str[pos2 + 4 - str + i] != '\n') {
                        *(id + j) = str[pos2 + 4 - str + i];
                        i++;j++;
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
                    checkoutcards(name, id, time2, roomnum, a, price, breakfast);
                    FILE *fp1 = fopen("hotel.db", "w");
                    if(!fp1){
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
                if (time1 == (timetonumber(time2) + a)) {//this vistor is going to check out today.
                    pos2 = strstr(pos, "name1");
                    i = 0;
                    int j=0;
                    while (str[pos2 + 6 - str + i] != '\n') {
                        *(name + i) = str[pos2 + 6 - str + i];
                        i++;
                        j++;
                    }
                    pos2 = strstr(pos, "name2");
                    *(name + j) = ';';
                    j++;i=0;
                    while (str[pos2 + 6 - str + i] != '\n') {
                        *(name + j) = str[pos2 + 6 - str + i];
                        i++;j++;
                    }
                    pos2 = strstr(pos, "name3");
                    *(name + j) = ';';
                    j++;i=0;
                    while (str[pos2 + 6 - str + i] != '\n') {
                        *(name + j) = str[pos2 + 6 - str + i];
                        i++;j++;
                    }
                    *(name + j) = '\0';//the end of the name
                    pos2 = strstr(pos, "id1");
                    i = 0;j=0;
                    while (str[pos2 + 4 - str + i] != '\n') {
                        *(id + i) = str[pos2 + 4 - str + i];
                        i++;j++;
                    }
                    pos2 = strstr(pos, "id2");
                    *(id + j) = ';';
                    i=0;j++;
                    while (str[pos2 + 4 - str + i] != '\n') {
                        *(id + j) = str[pos2 + 4 - str + i];
                        i++;j++;
                    }
                    pos2 = strstr(pos, "id3");
                    *(id + j) = ';';
                    j++;i=0;
                    while (str[pos2 + 4 - str + i] != '\n') {
                        *(id + j) = str[pos2 + 4 - str + i];
                        i++;j++;
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
                    checkoutcards(name, id, time2, roomnum, a, price, breakfast);
                    FILE *fp1 = fopen("hotel.db", "w");
                    if(!fp1){
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
                }
            }
        }
        pos = strstr(pos + 1, "room");
    }

    free(time2);
    free(id);
    free(name);
    free(night);
    free(pricei);
    free(breakfasti);
    free(room);//free the memory we have called//
}


long long int timetonumber(char *time1) {
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

char* numbertotime(long long int time1) {
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

void checkoutcards(char *name, char *id, char *arrival, int room, int nights, int price,
                   int breakfast) {//if there are multiple customers,list names and ids together
    printf("------------------------------Receipt------------------------------\n");
    printf("Dear %s, thank you for choosing 'no-star' hotel,looking forward to meet you next time!\n", name);
    printf("Your basic receipt:\n");
    printf("Your id: %s\n", id);//for multiple vistors, list them with;//
    printf("Your room number:%d\n", room);
    printf("Your arrival: %s\n", arrival);
    printf("You've spent %d nights here\n", nights);
    printf("You've eaten %d breakfast here\n", breakfast);
    printf("The total price is %d\n", price);
    printf("PLEASE PAY YOUR BILL!!! WE SUPPORT: ALIPAY/WECHAT PAY/APPLE PAY/SAMSUNG PAY\n");
    printf("-------------------------End of the Receipt-------------------------\n");
    printf("BOOKING HOTLINE: 54749110. You can also book from Ctrip.com or Booking.com!\n");
    printf("Have a nice day\n\n");
}

void checkdorm(char number, char *room1, int time1) {// the situation when check out the dorm
    FILE *fp = fopen("hotel.db", "r");
    char str[10000];
    int i, price;
    while (feof(fp) == 0) {//not reach the end//
        str[i] = fgetc(fp);
        i++;
    }
    fclose(fp);//It is not an efficient way to read the whole data base. But it is easiest to use:)
    char *pos = strstr(str, room1);
    char *posvis1;
    char *posvis2;
    char *posvis3;
    char *posvis4;
    char *posvis5;
    char *posvis6;//to locate each vistors//
    char *pos2;
    char *name = malloc(sizeof(char) * 45);
    char *id = malloc(sizeof(char) * 30);//this two are long to target the situation of the family room.
    char *pricei = malloc(sizeof(char) * 5);
    char *breakfasti = malloc(sizeof(char) * 2);
    char *time2 = calloc(sizeof(char), 12);
    char *A = malloc(sizeof(char) * 2);//this memory has been returned finally;
    if (number == '0') {//the dorm has 6 people;
        posvis1 = strstr(pos, "name");
        posvis2 = strstr(posvis1+1, "name");
        posvis3 = strstr(posvis2+1, "name");
        posvis4 = strstr(posvis3+1, "name");
        posvis5 = strstr(posvis4+1, "name");
        posvis6 = strstr(posvis5+1, "name");//locate the position of each vistors//
        int vacant = 0;
        char *pos3 = strstr(posvis1, "arrival");//locate time of arrival of vistors 1
        char *pos4 = strstr(posvis1, "nights");//locate the nights
        for (i = 0; i < 10; i++) {
            *(time2 + i) = str[pos3 - str + 8 + i];
        }//store the time
        *(time2 + 10) = '\0';//allocate the final place with \0//
        *A = str[pos4 + 7 - str];
        *(A + 1) = '\0';
        int a = atoi(A);//a is the night this vistor is going to spent
        if (time1 == (timetonumber(time2) + a)) {//this vistor is going to check out today.
            vacant++;
            i = 0;
            while (str[posvis1 + 5 - str + i] != '\n') {
                *(name + i) = str[posvis1 + 5 - str + i];
                i++;
            }
            *(name + i) = '\0';//to allocate the end of the name
            pos2 = strstr(posvis1, "id");//locate id
            i = 0;
            while (str[pos2 + 3 - str + i] != '\n') {
                *(id + i) = str[pos2 + 3 - str + i];
                i++;
            }
            *(id + i) = '\0';
            pos2 = strstr(posvis1, "price");// to locate price
            i = 0;
            while (str[pos2 + 6 - str + i] != '\n') {
                *(pricei + i) = str[pos2 + 6 - str + i];
                i++;
            }
            *(pricei + i) = '\0';
            price = atoi(pricei);
            pos2 = strstr(posvis1, "breakfast");
            i = 0;
            *breakfasti = str[pos2 + 10 - str + i];
            *(breakfasti + 1) = '\0';
            int breakfast = atoi(breakfasti);//to read breakfast
            int roomnum = atoi(room1);
            checkoutcards(name, id, time2, roomnum, a, price, breakfast);// have gathered all the information. to create the checkout cards
            FILE *fp1 = fopen("hotel.db", "w");
            if(!fp1){
                printf("ERROR IN POS2");
            }
            for (i = 0; i < (pos - str + 6); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before

            fprintf(fp1, "type=dorm\n");
            fprintf(fp1, "vacant=%d\n", vacant);
            printf("%d",vacant);
            fprintf(fp1, "vistors=%d\n\n", 6 - vacant);
            i = posvis2 - str;//to locate vistor 2//
            while (str[i - 1] != '-') {
                fprintf(fp1, "%c", str[i]);
                i++;
            }//copy after her//
            fclose(fp1);
            number = '1';
            checkdorm(number, room1, time1);
            return;
        }

        pos3 = strstr(posvis2, "arrival");//locate time of arrival of vistor2//
        pos4 = strstr(posvis2, "nights");//locate the nights
        for (i = 0; i < 10; i++) {
            *(time2 + i) = str[pos3 - str + 8 + i];
        }
        *(time2 + 10) = '\0';
        *A = str[pos4 + 7 - str];
        *(A + 1) = '\0';
        a = atoi(A);
        if (time1 == (timetonumber(time2) + a)) {//this vistor is going to check out today.
            vacant++;
            i = 0;
            while (str[posvis2 + 5 - str + i] != '\n') {
                *(name + i) = str[posvis2 + 5 - str + i];
                i++;
            }
            *(name + i) = '\0';//the end of the name
            pos2 = strstr(posvis2, "id");
            i = 0;
            while (str[pos2 + 3 - str + i] != '\n') {
                *(id + i) = str[pos2 + 3 - str + i];
                i++;
            }
            *(id + i) = '\0';
            pos2 = strstr(posvis2, "price");
            i = 0;
            while (str[pos2 + 6 - str + i] != '\n') {
                *(pricei + i) = str[pos2 + 6 - str + i];
                i++;
            }
            *(pricei + i) = '\0';
            price = atoi(pricei);
            pos2 = strstr(posvis2, "breakfast");
            i = 0;
            *breakfasti = str[pos2 + 10 - str + i];
            *(breakfasti + 1) = '\0';
            int breakfast = atoi(breakfasti);
            int roomnum = atoi(room1);
            checkoutcards(name, id, time2, roomnum, a, price, breakfast);
            FILE *fp1 = fopen("hotel.db", "w");
            if(!fp1){
                printf("ERROR IN POS1");
            }
            for (i = 0; i < (pos - str + 6); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            fprintf(fp1, "type=dorm\n");
            fprintf(fp1, "vacant=%d\n", vacant);
            fprintf(fp1, "vistors=%d\n", 6 - vacant);
            pos2 = strstr(pos, "vistors");
            pos2 = strstr(pos2, "\n");
            for (i = (pos2 - str+1); i < (posvis2 - str); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            i = posvis3 - str;
            while (str[i - 1] != '-') {
                fprintf(fp1, "%c", str[i]);
                i++;
            }//copy the part after
            fclose(fp1);
            number = '1';
            checkdorm(number, room1, time1);
            return;
        }
        pos3 = strstr(posvis3, "arrival");//locate time of arrival of vistors//
        pos4 = strstr(posvis3, "nights");//locate the nights
        for (i = 0; i < 10; i++) {
            *(time2 + i) = str[pos3 - str + 8 + i];
        }
        *(time2 + 10) = '\0';
        *A = str[pos4 + 7 - str];
        *(A + 1) = '\0';
        a = atoi(A);
        if (time1 == (timetonumber(time2) + a)) {//this vistor is going to check out today.
            vacant++;
            i = 0;
            while (str[posvis3 + 5 - str + i] != '\n') {
                *(name + i) = str[posvis3 + 5 - str + i];
                i++;
            }
            *(name + i) = '\0';//the end of the name
            pos2 = strstr(posvis3, "id");
            i = 0;
            while (str[pos2 + 3 - str + i] != '\n') {
                *(id + i) = str[pos2 + 3 - str + i];
                i++;
            }
            *(id + i) = '\0';
            pos2 = strstr(posvis3, "price");
            i = 0;
            while (str[pos2 + 6 - str + i] != '\n') {
                *(pricei + i) = str[pos2 + 6 - str + i];
                i++;
            }
            *(pricei + i) = '\0';
            price = atoi(pricei);
            pos2 = strstr(posvis3, "breakfast");
            i = 0;
            *breakfasti = str[pos2 + 10 - str + i];
            *(breakfasti + 1) = '\0';
            int breakfast = atoi(breakfasti);

            int roomnum = atoi(room1);
            checkoutcards(name, id, time2, roomnum, a, price, breakfast);
            FILE *fp1 = fopen("hotel.db", "w");
            if(!fp1){
                printf("ERROR IN POS3");
            }
            for (i = 0; i < (pos - str + 6); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            fprintf(fp1, "type=dorm\n");
            fprintf(fp1, "vacant=%d\n", vacant);
            fprintf(fp1, "vistors=%d\n", 6 - vacant);
            pos2 = strstr(pos, "vistors");
            pos2 = strstr(pos2, "\n");
            for (i =(int) (pos2 - str+1); i < (posvis3 - str); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            i = (int)(posvis4 - str);
            while (str[i - 1] != '-') {
                fprintf(fp1, "%c", str[i]);
                i++;
            }//copy the part after
            fclose(fp1);
            number = '1';
            checkdorm(number, room1, time1);//continue check under the new condition
            return;
        }
        pos3 = strstr(posvis4, "arrival");//locate time of arrival of vistors//
        pos4 = strstr(posvis4, "nights");//locate the nights
        for (i = 0; i < 10; i++) {
            *(time2 + i) = str[pos3 - str + 8 + i];
        }
        *(time2 + 10) = '\0';
        *A = str[pos4 + 7 - str];
        *(A + 1) = '\0';
        a = atoi(A);
        if (time1 == (timetonumber(time2) + a)) {//this vistor is going to check out today.
            vacant++;
            i = 0;
            while (str[posvis4 + 5 - str + i] != '\n') {
                *(name + i) = str[posvis4 + 5 - str + i];
                i++;
            }
            *(name + i) = '\0';//the end of the name
            pos2 = strstr(posvis4, "id");
            i = 0;
            while (str[pos2 + 3 - str + i] != '\n') {
                *(id + i) = str[pos2 + 3 - str + i];
                i++;
            }
            *(id + i) = '\0';
            pos2 = strstr(posvis4, "price");
            i = 0;
            while (str[pos2 + 6 - str + i] != '\n') {
                *(pricei + i) = str[pos2 + 6 - str + i];
                i++;
            }
            *(pricei + i) = '\0';
            price = (atoi(pricei));
            pos2 = strstr(posvis4, "breakfast");
            i = 0;
            *breakfasti = str[pos2 + 10 - str + i];
            *(breakfasti + 1) = '\0';
            int breakfast = atoi(breakfasti);
            int roomnum = atoi(room1);
            checkoutcards(name, id, time2, roomnum, a, price, breakfast);
            FILE *fp1 = fopen("hotel.db", "w");
            if(!fp1){
                printf("ERROR IN POS4");
            }
            for (i = 0; i < (pos - str + 6); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            fprintf(fp1, "type=dorm\n");
            fprintf(fp1, "vacant=%d\n", vacant);
            fprintf(fp1, "vistors=%d\n", 6 - vacant);
            pos2 = strstr(pos, "vistors");
            pos2 = strstr(pos2, "\n");
            for (i = (int)(pos2 - str+1); i < (posvis4 - str); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            i = (int)(posvis5 - str);
            while (str[i - 1] != '-') {
                fprintf(fp1, "%c", str[i]);
                i++;
            }//copy the part after
            fclose(fp1);
            number = '1';
            checkdorm(number, room1, time1);
            return;
        }
        pos3 = strstr(posvis5, "arrival");//locate time of arrival of vistors//
        pos4 = strstr(posvis5, "nights");//locate the nights
        for (i = 0; i < 10; i++) {
            *(time2 + i) = str[pos3 - str + 8 + i];
        }
        *(time2 + 10) = '\0';
        *A = str[pos4 + 7 - str];
        *(A + 1) = '\0';
        a = atoi(A);
        if (time1 == (timetonumber(time2) + a)) {//this vistor is going to check out today.
            vacant++;
            i = 0;
            while (str[posvis5 + 5 - str + i] != '\n') {
                *(name + i) = str[posvis5 + 5 - str + i];
                i++;
            }
            *(name + i) = '\0';//the end of the name
            pos2 = strstr(posvis5, "id");
            i = 0;
            while (str[pos2 + 3 - str + i] != '\n') {
                *(id + i) = str[pos2 + 3 - str + i];
                i++;
            }
            *(id + i) = '\0';
            pos2 = strstr(posvis5, "price");
            i = 0;
            while (str[pos2 + 6 - str + i] != '\n') {
                *(pricei + i) = str[pos2 + 6 - str + i];
                i++;
            }
            *(pricei + i) = '\0';
            price = atoi(pricei);
            pos2 = strstr(posvis5, "breakfast");
            i = 0;
            *breakfasti = str[pos2 + 10 - str + i];
            *(breakfasti + 1) = '\0';
            int breakfast = atoi(breakfasti);
            int roomnum = atoi(room1);
            checkoutcards(name, id, time2, roomnum, a, price, breakfast);
            FILE *fp1 = fopen("hotel.db", "w");
            if(!fp1){
                printf("ERROR IN POS5");
            }
            for (i = 0; i < (pos - str + 6); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            fprintf(fp1, "type=dorm\n");
            fprintf(fp1, "vacant=%d\n", vacant);
            fprintf(fp1, "vistors=%d\n", 6 - vacant);
            pos2 = strstr(pos, "vistors");
            pos2 = strstr(pos2, "\n");
            for (i = (int)(pos2 - str+1); i < (posvis5 - str); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            i = (int)(posvis6 - str);
            while (str[i - 1] != '-') {
                fprintf(fp1, "%c", str[i]);
                i++;
            }//copy the part after
            fclose(fp1);
            number = '1';
            checkdorm(number, room1, time1);
            return;
        }
        pos3 = strstr(posvis6, "arrival");//locate time of arrival of vistors//
        pos4 = strstr(posvis6, "nights");//locate the nights
        for (i = 0; i < 10; i++) {
            *(time2 + i) = str[pos3 - str + 8 + i];
        }
        *(time2 + 10) = '\0';
        *A = str[pos4 + 7 - str];
        *(A + 1) = '\0';
        a = atoi(A);
        if (time1 == (timetonumber(time2) + a)) {//this vistor is going to check out today.
            vacant++;
            i = 0;
            while (str[posvis6 + 5 - str + i] != '\n') {
                *(name + i) = str[posvis6 + 5 - str + i];
                i++;
            }
            *(name + i) = '\0';//the end of the name
            pos2 = strstr(posvis6, "id");
            i = 0;
            while (str[pos2 + 3 - str + i] != '\n') {
                *(id + i) = str[pos2 + 3 - str + i];
                i++;
            }
            *(id + i) = '\0';
            pos2 = strstr(posvis6, "price");
            i = 0;
            while (str[pos2 + 6 - str + i] != '\n') {
                *(pricei + i) = str[pos2 + 6 - str + i];
                i++;
            }
            *(pricei + i) = '\0';
            price = atoi(pricei);
            pos2 = strstr(posvis6, "breakfast");
            i = 0;
            *breakfasti = str[pos2 + 10 - str + i];
            *(breakfasti + 1) = '\0';
            int breakfast = atoi(breakfasti);
            int roomnum = atoi(room1);
            checkoutcards(name, id, time2, roomnum, a, price, breakfast);
            FILE *fp1 = fopen("hotel.db", "w");
            if(!fp1){
                printf("ERROR IN POS5");
            }
            for (i = 0; i < (pos - str + 11); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            fprintf(fp1, "type=dorm\n");
            fprintf(fp1, "vacant=%d\n", vacant);
            fprintf(fp1, "vistors=%d\n", 6 - vacant);
            pos2 = strstr(pos, "vistors");
            pos2 = strstr(pos2, "\n");
            for (i = (pos2 - str); i < (posvis6 - str); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            pos2 = strstr(pos2, "room");
            i=pos2-str;
            while (str[i - 2] != '-') {
                fprintf(fp1, "%c", str[i - 1]);
                i++;
            }//copy the part after
            fclose(fp1);
        }} else if (number == '1') {
        int vacant = 1;
        posvis1 = strstr(pos, "name");
        posvis2 = strstr(posvis1+1, "name");
        posvis3 = strstr(posvis2+1, "name");
        posvis4 = strstr(posvis3+1, "name");
        posvis5 = strstr(posvis4+1, "name");
        char *pos3 = strstr(posvis1, "arrival");//locate time of arrival of vistors 1
        char* pos4 = strstr(posvis1, "nights");//locate the nights
        for (i = 0; i < 10; i++) {
            *(time2 + i) = str[pos3 - str + 8 + i];
        }
        *(time2 + 10) = '\0';
        char *A = malloc(sizeof(char) * 2);
        *A = str[pos4 + 7 - str];
        *(A + 1) = '\0';
        int a = atoi(A);
        if (time1 == (timetonumber(time2) + a)) {//this vistor is going to check out today.
            vacant++;
            i = 0;
            while (str[posvis1 + 5 - str + i] != '\n') {
                *(name + i) = str[posvis1 + 5 - str + i];
                i++;
            }
            *(name + i) = '\0';//the end of the name
            pos2 = strstr(posvis1, "id");
            i = 0;
            while (str[pos2 + 3 - str + i] != '\n') {
                *(id + i) = str[pos2 + 3 - str + i];
                i++;
            }
            *(id + i) = '\0';
            pos2 = strstr(posvis1, "price");
            i = 0;
            while (str[pos2 + 6 - str + i] != '\n') {
                *(pricei + i) = str[pos2 + 6 - str + i];
                i++;
            }
            *(pricei + i) = '\0';
            price = atoi(pricei);
            pos2 = strstr(posvis1, "breakfast");
            i = 0;
            *breakfasti = str[pos2 + 10 - str + i];
            *(breakfasti + 1) = '\0';
            int breakfast = atoi(breakfasti);
            int roomnum = atoi(room1);
            checkoutcards(name, id, time2, roomnum, a, price, breakfast);

            FILE *fp1 = fopen("hotel.db", "w");
            if(!fp1){
                printf("ERROR IN POS6");
            }
            for (i = 0; i < (pos - str + 6); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            fprintf(fp1, "type=dorm\n");
            fprintf(fp1, "vacant=%d\n", vacant);
            fprintf(fp1, "vistors=%d\n\n", 6 - vacant);
            i = posvis2 - str;
            while (str[i - 1] != '-') {
                fprintf(fp1, "%c", str[i]);
                printf("%c",str[i]);
                i++;
            }//copy the part after
            fclose(fp1);
            number = '2';
            checkdorm(number, room1, time1);
            return;
        }

        pos3 = strstr(posvis2, "arrival");//locate time of arrival of vistors//
        pos4 = strstr(posvis2, "nights");//locate the nights
        for (i = 0; i < 10; i++) {
            *(time2 + i) = str[pos3 - str + 8 + i];
        }
        *(time2 + 10) = '\0';
        *A = str[pos4 + 7 - str];
        *(A + 1) = '\0';
        a = atoi(A);
        if (time1 == (timetonumber(time2) + a)) {//this vistor is going to check out today.
            vacant++;
            i = 0;
            while (str[posvis2 + 5 - str + i] != '\n') {
                *(name + i) = str[posvis2 + 5 - str + i];
                i++;
            }
            *(name + i) = '\0';//the end of the name
            pos2 = strstr(posvis2, "id");
            i = 0;
            while (str[pos2 + 3 - str + i] != '\n') {
                *(id + i) = str[pos2 + 3 - str + i];
                i++;
            }
            *(id + i) = '\0';
            pos2 = strstr(posvis2, "price");
            i = 0;
            while (str[pos2 + 6 - str + i] != '\n') {
                *(pricei + i) = str[pos2 + 6 - str + i];
                i++;
            }
            *(pricei + i) = '\0';
            price = atoi(pricei);
            pos2 = strstr(posvis2, "breakfast");
            i = 0;
            *breakfasti = str[pos2 + 10 - str + i];
            *(breakfasti + 1) = '\0';
            int breakfast = atoi(breakfasti);
            int roomnum = atoi(room1);
            checkoutcards(name, id, time2, roomnum, a, price, breakfast);
            FILE *fp1 = fopen("hotel.db", "w");
            if(!fp1){
                printf("ERROR IN POS7");
            }
            for (i = 0; i < (pos - str + 6); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            fprintf(fp1, "type=dorm\n");
            fprintf(fp1, "vacant=%d\n", vacant);
            fprintf(fp1, "vistors=%d\n", 6 - vacant);
            pos2 = strstr(pos, "vistors");
            pos2 = strstr(pos2, "\n");
            for (i = (pos2 - str+1); i < (posvis2 - str); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            i = posvis3 - str;
            while (str[i - 1] != '-') {
                fprintf(fp1, "%c", str[i]);
                i++;
            }//copy the part after
            fclose(fp1);
            number = '2';
            checkdorm(number, room1, time1);
            return;
        }
        pos3 = strstr(posvis3, "arrival");//locate time of arrival of vistors//
        pos4 = strstr(posvis3, "nights");//locate the nights
        for (i = 0; i < 10; i++) {
            *(time2 + i) = str[pos3 - str + 8 + i];
        }
        *(time2 + 10) = '\0';
        *A = str[pos4 + 7 - str];
        *(A + 1) = '\0';
        a = atoi(A);
        if (time1 == (timetonumber(time2) + a)) {//this vistor is going to check out today.
            vacant++;
            i = 0;
            while (str[posvis3 + 5 - str + i] != '\n') {
                *(name + i) = str[posvis3 + 5 - str + i];
                i++;
            }
            *(name + i) = '\0';//the end of the name
            pos2 = strstr(posvis3, "id");
            i = 0;
            while (str[pos2 + 3 - str + i] != '\n') {
                *(id + i) = str[pos2 + 3 - str + i];
                i++;
            }
            *(id + i) = '\0';
            pos2 = strstr(posvis3, "price");
            i = 0;
            while (str[pos2 + 6 - str + i] != '\n') {
                *(pricei + i) = str[pos2 + 6 - str + i];
                i++;
            }
            *(pricei + i) = '\0';
            price = atoi(pricei);
            pos2 = strstr(posvis3, "breakfast");
            i = 0;
            *breakfasti = str[pos2 + 10 - str + i];
            *(breakfasti + 1) = '\0';
            int breakfast = atoi(breakfasti);
            int roomnum = atoi(room1);
            checkoutcards(name, id, time2, roomnum, a, price, breakfast);
            FILE *fp1 = fopen("hotel.db", "w");
            if(!fp1){
                printf("ERROR IN POS8");
            }
            for (i = 0; i < (pos - str + 6); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            fprintf(fp1, "type=dorm\n");
            fprintf(fp1, "vacant=%d\n", vacant);
            fprintf(fp1, "vistors=%d\n", 6 - vacant);
            pos2 = strstr(pos, "vistors");
            pos2 = strstr(pos2, "\n");
            for (i = (int) (pos2 - str+1); i < (posvis3 - str); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            i = (int) (posvis4 - str);
            while (str[i - 1] != '-') {
                fprintf(fp1, "%c", str[i]);
                i++;
            }//copy the part after
            fclose(fp1);
            number = '2';
            checkdorm(number, room1, time1);
            return;
        }
        pos3 = strstr(posvis4, "arrival");//locate time of arrival of vistors//
        pos4 = strstr(posvis4, "nights");//locate the nights
        for (i = 0; i < 10; i++) {
            *(time2 + i) = str[pos3 - str + 8 + i];
        }
        *(time2 + 10) = '\0';
        *A = str[pos4 + 7 - str];
        *(A + 1) = '\0';
        a = (int) (atoi(A));
        if (time1 == (timetonumber(time2) + a)) {//this vistor is going to check out today.
            vacant++;
            i = 0;
            while (str[posvis4 + 5 - str + i] != '\n') {
                *(name + i) = str[posvis4 + 5 - str + i];
                i++;
            }
            *(name + i) = '\0';//the end of the name
            pos2 = strstr(posvis4, "id");
            i = 0;
            while (str[pos2 + 3 - str + i] != '\n') {
                *(id + i) = str[pos2 + 3 - str + i];
                i++;
            }
            *(id + i) = '\0';
            pos2 = strstr(posvis4, "price");
            i = 0;
            while (str[pos2 + 6 - str + i] != '\n') {
                *(pricei + i) = str[pos2 + 6 - str + i];
                i++;
            }
            *(pricei + i) = '\0';
            price = atoi(pricei);
            pos2 = strstr(posvis4, "breakfast");
            i = 0;
            *breakfasti = str[pos2 + 10 - str + i];
            *(breakfasti + 1) = '\0';
            int breakfast = atoi(breakfasti);
            int roomnum = atoi(room1);
            checkoutcards(name, id, time2, roomnum, a, price, breakfast);
            FILE *fp1 = fopen("hotel.db", "w");
            if(!fp1){
                printf("ERROR IN POS9");
            }
            for (i = 0; i < (pos - str + 11); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            fprintf(fp1, "type=dorm\n");
            fprintf(fp1, "vacant=%d\n", vacant);
            fprintf(fp1, "vistors=%d\n", 6 - vacant);
            pos2 = strstr(pos, "vistors");
            pos2 = strstr(pos2, "\n");
            for (i = (int) (pos2 - str+1); i < (posvis4 - str); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            i = (int) (posvis5 - str);
            while (str[i - 1] != '-') {
                fprintf(fp1, "%c", str[i]);
                i++;
            }//copy the part after
            fclose(fp1);
            number = '2';
            checkdorm(number, room1, time1);
            return;
        }
        pos3 = strstr(posvis5, "arrival");//locate time of arrival of vistors//
        pos4 = strstr(posvis5, "nights");//locate the nights
        for (i = 0; i < 10; i++) {
            *(time2 + i) = str[pos3 - str + 8 + i];
        }
        *(time2 + 10) = '\0';
        *A = str[pos4 + 7 - str];
        *(A + 1) = '\0';
        a = atoi(A);
        if (time1 == (timetonumber(time2) + a)) {//this vistor is going to check out today.
            vacant++;
            i = 0;
            while (str[posvis5 + 5 - str + i] != '\n') {
                *(name + i) = str[posvis5 + 5 - str + i];
                i++;
            }
            *(name + i) = '\0';//the end of the name
            pos2 = strstr(posvis5, "id");
            i = 0;
            while (str[pos2 + 3 - str + i] != '\n') {
                *(id + i) = str[pos2 + 3 - str + i];
                i++;
            }
            *(id + i) = '\0';
            pos2 = strstr(posvis5, "price");
            i = 0;
            while (str[pos2 + 6 - str + i] != '\n') {
                *(pricei + i) = str[pos2 + 6 - str + i];
                i++;
            }
            *(pricei + i) = '\0';
            price = atoi(pricei);
            pos2 = strstr(posvis5, "breakfast");
            i = 0;
            *breakfasti = str[pos2 + 10 - str + i];
            *(breakfasti + 1) = '\0';
            int breakfast = atoi(breakfasti);
            int roomnum = atoi(room1);
            checkoutcards(name, id, time2, roomnum, a, price, breakfast);
            FILE *fp1 = fopen("hotel.db", "w");
            if(!fp1){
                printf("ERROR IN POS10");
            }
            for (i = 0; i < (pos - str + 6); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            fprintf(fp1, "type=dorm\n");
            fprintf(fp1, "vacant=%d\n", vacant);
            fprintf(fp1, "vistors=%d\n", 6 - vacant);
            pos2 = strstr(pos, "vistors");
            pos2 = strstr(pos2, "\n");
            for (i = (pos2 - str); i < (posvis5 - str); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            pos2 = strstr(pos2, "room");
            i=pos2-str;
            while (str[i - 2] != '-') {
                fprintf(fp1, "%c", str[i - 1]);
                i++;
            }//copy the part after
            fclose(fp1);
        }

    } else if (number == '2') {
        int vacant = 2;
        posvis1 = strstr(pos, "name");
        posvis2 = strstr(posvis1+1, "name");
        posvis3 = strstr(posvis2+1, "name");
        posvis4 = strstr(posvis3+1, "name");
        char *pos3 = strstr(posvis1, "arrival");//locate time of arrival of vistors 1
        char *pos4 = strstr(posvis1, "nights");//locate the nights
        for (i = 0; i < 10; i++) {
            *(time2 + i) = str[pos3 - str + 8 + i];
        }
        *(time2 + 10) = '\0';
        char *A = malloc(sizeof(char) * 2);
        *A = str[pos4 + 7 - str];
        *(A + 1) = '\0';
        int a = atoi(A);
        if (time1 == (timetonumber(time2) + a)) {//this vistor is going to check out today.
            vacant++;
            i = 0;
            while (str[posvis1 + 5 - str + i] != '\n') {
                *(name + i) = str[posvis1 + 5 - str + i];
                i++;
            }
            *(name + i) = '\0';//the end of the name
            pos2 = strstr(posvis1, "id");
            i = 0;
            while (str[pos2 + 3 - str + i] != '\n') {
                *(id + i) = str[pos2 + 3 - str + i];
                i++;
            }
            *(id + i) = '\0';
            pos2 = strstr(posvis1, "price");
            i = 0;
            while (str[pos2 + 6 - str + i] != '\n') {
                *(pricei + i) = str[pos2 + 6 - str + i];
                i++;
            }
            *(pricei + i) = '\0';
            price = atoi(pricei);
            pos2 = strstr(posvis1, "breakfast");
            i = 0;
            *breakfasti = str[pos2 + 10 - str + i];
            *(breakfasti + 1) = '\0';
            int breakfast = atoi(breakfasti);
            int roomnum = atoi(room1);
            checkoutcards(name, id, time2, roomnum, a, price, breakfast);

            FILE *fp1 = fopen("hotel.db", "w");
            if(!fp1){
                printf("ERROR IN POS11");
            }
            for (i = 0; i < (pos - str + 6); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            fprintf(fp1, "type=dorm\n");
            fprintf(fp1, "vacant=%d\n", vacant);
            fprintf(fp1, "vistors=%d\n\n", 6 - vacant);
            i = posvis2 - str;
            while (str[i - 1] != '-') {
                fprintf(fp1, "%c", str[i]);
                i++;
            }//copy the part after
            fclose(fp1);
            number = '3';
            checkdorm(number, room1, time1);
            return;
        }
        pos3 = strstr(posvis2, "arrival");//locate time of arrival of vistors//
        pos4 = strstr(posvis2, "nights");//locate the nights
        for (i = 0; i < 10; i++) {
            *(time2 + i) = str[pos3 - str + 8 + i];
        }
        *(time2 + 10) = '\0';
        *A = str[pos4 + 7 - str];
        *(A + 1) = '\0';
        a = atoi(A);
        if (time1 == (timetonumber(time2) + a)) {//this vistor is going to check out today.
            vacant++;
            i = 0;
            while (str[posvis2 + 5 - str + i] != '\n') {
                *(name + i) = str[posvis2 + 5 - str + i];
                i++;
            }
            *(name + i) = '\0';//the end of the name
            pos2 = strstr(posvis2, "id");
            i = 0;
            while (str[pos2 + 3 - str + i] != '\n') {
                *(id + i) = str[pos2 + 3 - str + i];
                i++;
            }
            *(id + i) = '\0';
            pos2 = strstr(posvis2, "price");
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
            int roomnum = atoi(room1);
            checkoutcards(name, id, time2, roomnum, a, price, breakfast);
            FILE *fp1 = fopen("hotel.db", "w");
            if(!fp1){
                printf("ERROR IN POS12");
            }
            for (i = 0; i < (pos - str + 6); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            fprintf(fp1, "type=dorm\n");
            fprintf(fp1, "vacant=%d\n", vacant);
            fprintf(fp1, "vistors=%d\n", 6 - vacant);
            pos2 = strstr(pos, "vistors");
            pos2 = strstr(pos2, "\n");
            for (i = (pos2 - str+1); i < (posvis2 - str); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            i = posvis3 - str;
            while (str[i - 1] != '-') {
                fprintf(fp1, "%c", str[i]);
                i++;
            }//copy the part after
            fclose(fp1);
            number = '3';
            checkdorm(number, room1, time1);
            return;
        }
        pos3 = strstr(posvis3, "arrival");//locate time of arrival of vistors//
        pos4 = strstr(posvis3, "nights");//locate the nights
        for (i = 0; i < 10; i++) {
            *(time2 + i) = str[pos3 - str + 8 + i];
        }
        *(time2 + 10) = '\0';
        *A = str[pos4 + 7 - str];
        *(A + 1) = '\0';
        a = atoi(A);
        if (time1 == (timetonumber(time2) + a)) {//this vistor is going to check out today.
            vacant++;
            i = 0;
            while (str[posvis3 + 5 - str + i] != '\n') {
                *(name + i) = str[posvis3 + 5 - str + i];
                i++;
            }
            *(name + i) = '\0';//the end of the name
            pos2 = strstr(posvis3, "id");
            i = 0;
            while (str[pos2 + 3 - str + i] != '\n') {
                *(id + i) = str[pos2 + 3 - str + i];
                i++;
            }
            *(id + i) = '\0';
            pos2 = strstr(posvis3, "price");
            i = 0;
            while (str[pos2 + 6 - str + i] != '\n') {
                *(pricei + i) = str[pos2 + 6 - str + i];
                i++;
            }
            *(pricei + i) = '\0';
            price = atoi(pricei);
            pos2 = strstr(posvis3, "breakfast");
            i = 0;
            *breakfasti = str[pos2 + 10 - str + i];
            *(breakfasti + 1) = '\0';
            int breakfast = atoi(breakfasti);
            int roomnum = atoi(room1);
            checkoutcards(name, id, time2, roomnum, a, price, breakfast);
            FILE *fp1 = fopen("hotel.db", "w");
            if(!fp1){
                printf("ERROR IN POS13");
            }
            for (i = 0; i < (pos - str + 6); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            fprintf(fp1, "type=dorm\n");
            fprintf(fp1, "vacant=%d\n", vacant);
            fprintf(fp1, "vistors=%d\n", 6 - vacant);
            pos2 = strstr(pos, "vistors");
            pos2 = strstr(pos2, "\n");
            for (i = (pos2 - str+1); i < (posvis3 - str); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            i = posvis4 - str;
            while (str[i - 1] != '-') {
                fprintf(fp1, "%c", str[i]);
                i++;
            }//copy the part after
            fclose(fp1);
            number = '3';
            checkdorm(number, room1, time1);
            return;
        }
        pos3 = strstr(posvis4, "arrival");//locate time of arrival of vistors//
        pos4 = strstr(posvis4, "nights");//locate the nights
        for (i = 0; i < 10; i++) {
            *(time2 + i) = str[pos3 - str + 8 + i];
        }
        *(time2 + 10) = '\0';
        *A = str[pos4 + 7 - str];
        *(A + 1) = '\0';
        a = atoi(A);
        if (time1 == (timetonumber(time2) + a)) {//this vistor is going to check out today.
            vacant++;
            i = 0;
            while (str[posvis4 + 5 - str + i] != '\n') {
                *(name + i) = str[posvis4 + 5 - str + i];
                i++;
            }
            *(name + i) = '\0';//the end of the name
            pos2 = strstr(posvis4, "id");
            i = 0;
            while (str[pos2 + 3 - str + i] != '\n') {
                *(id + i) = str[pos2 + 3 - str + i];
                i++;
            }
            *(id + i) = '\0';
            pos2 = strstr(posvis4, "price");
            i = 0;
            while (str[pos2 + 6 - str + i] != '\n') {
                *(pricei + i) = str[pos2 + 6 - str + i];
                i++;
            }
            *(pricei + i) = '\0';
            price = atoi(pricei);
            pos2 = strstr(posvis4, "breakfast");
            i = 0;
            *breakfasti = str[pos2 + 10 - str + i];
            *(breakfasti + 1) = '\0';
            int breakfast = atoi(breakfasti);
            int roomnum = atoi(room1);
            checkoutcards(name, id, time2, roomnum, a, price, breakfast);
            FILE *fp1 = fopen("hotel.db", "w");
            if(!fp1){
                printf("ERROR IN POS14");
            }
            for (i = 0; i < (pos - str + 6); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            fprintf(fp1, "type=dorm\n");
            fprintf(fp1, "vacant=%d\n", vacant);
            fprintf(fp1, "vistors=%d\n", 6 - vacant);
            pos2 = strstr(pos, "vistors");
            pos2 = strstr(pos2, "\n");
            for (i = (pos2 - str+1); i < (posvis4 - str); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            pos2 = strstr(pos2, "room");
            i = pos2 - str;
            while (str[i - 2] != '-') {
                fprintf(fp1, "%c", str[i - 1]);
                i++;
            }//copy the part after
            fclose(fp1);
        }
    } else if (number == '3') {
        int vacant = 3;
        posvis1 = strstr(pos, "name");
        posvis2 = strstr(posvis1+1, "name");
        posvis3 = strstr(posvis2+1, "name");
        char *pos3 = strstr(posvis1, "arrival");//locate time of arrival of vistors 1
        char *pos4 = strstr(posvis2, "nights");//locate the nights
        for (i = 0; i < 10; i++) {
            *(time2 + i) = str[pos3 - str + 8 + i];
        }
        *(time2 + 10) = '\0';
        char *A = malloc(sizeof(char) * 2);
        *A = str[pos4 + 7 - str];
        *(A + 1) = '\0';
        int a = atoi(A);
        if (time1 == (timetonumber(time2) + a)) {//this vistor is going to check out today.
            vacant++;
            i = 0;
            while (str[posvis1 + 5 - str + i] != '\n') {
                *(name + i) = str[posvis1 + 5 - str + i];
                i++;
            }
            *(name + i) = '\0';//the end of the name
            pos2 = strstr(posvis1, "id");
            i = 0;
            while (str[pos2 + 3 - str + i] != '\n') {
                *(id + i) = str[pos2 + 3 - str + i];
                i++;
            }
            *(id + i) = '\0';
            pos2 = strstr(posvis1, "price");
            i = 0;
            while (str[pos2 + 6 - str + i] != '\n') {
                *(pricei + i) = str[pos2 + 6 - str + i];
                i++;
            }
            *(pricei + i) = '\0';
            price = atoi(pricei);
            pos2 = strstr(posvis1, "breakfast");
            i = 0;
            *breakfasti = str[pos2 + 10 - str + i];
            *(breakfasti + 1) = '\0';
            int breakfast = atoi(breakfasti);
            int roomnum = atoi(room1);
            checkoutcards(name, id, time2, roomnum, a, price, breakfast);

            FILE *fp1 = fopen("hotel.db", "w");
            if(!fp1){
                printf("ERROR IN POS15");
            }
            for (i = 0; i < (pos - str + 6); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            fprintf(fp1, "type=dorm\n");
            fprintf(fp1, "vacant=%d\n", vacant);
            fprintf(fp1, "vistors=%d\n\n", 6 - vacant);
            i = posvis2 - str;
            while (str[i - 1] != '-') {
                fprintf(fp1, "%c", str[i]);
                i++;
            }//copy the part after
            fclose(fp1);
            number = '4';
            checkdorm(number, room1, time1);
            return;
        }
        pos3 = strstr(posvis2, "arrival");//locate time of arrival of vistors//
        pos4 = strstr(posvis2, "nights");//locate the nights
        for (i = 0; i < 10; i++) {
            *(time2 + i) = str[pos3 - str + 8 + i];
        }
        *(time2 + 10) = '\0';
        *A = str[pos4 + 7 - str];
        *(A + 1) = '\0';
        a = atoi(A);
        if (time1 == (timetonumber(time2) + a)) {//this vistor is going to check out today.
            vacant++;
            i = 0;
            while (str[posvis2 + 5 - str + i] != '\n') {
                *(name + i) = str[posvis2 + 5 - str + i];
                i++;
            }
            *(name + i) = '\0';//the end of the name
            pos2 = strstr(posvis2, "id");
            i = 0;
            while (str[pos2 + 3 - str + i] != '\n') {
                *(id + i) = str[pos2 + 3 - str + i];
                i++;
            }
            *(id + i) = '\0';
            pos2 = strstr(posvis2, "price");
            i = 0;
            while (str[pos2 + 6 - str + i] != '\n') {
                *(pricei + i) = str[pos2 + 6 - str + i];
                i++;
            }
            *(pricei + i) = '\0';
            price = atoi(pricei);
            pos2 = strstr(posvis2, "breakfast");
            i = 0;
            *breakfasti = str[pos2 + 10 - str + i];
            *(breakfasti + 1) = '\0';
            int breakfast = atoi(breakfasti);
            int roomnum = atoi(room1);
            checkoutcards(name, id, time2, roomnum, a, price, breakfast);
            FILE *fp1 = fopen("hotel.db", "w");
            if(!fp1){
                printf("ERROR IN POS16");
            }
            for (i = 0; i < (pos - str + 6); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            fprintf(fp1, "type=dorm\n");
            fprintf(fp1, "vacant=%d\n", vacant);
            fprintf(fp1, "vistors=%d\n", 6 - vacant);
            pos2 = strstr(pos, "vistors");
            pos2 = strstr(pos2, "\n");
            for (i = (pos2 - str+1); i < (posvis2 - str); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            i = posvis3 - str;
            while (str[i - 1] != '-') {
                fprintf(fp1, "%c", str[i]);
                i++;
            }//copy the part after
            fclose(fp1);
            number = '4';
            checkdorm(number, room1, time1);
            return;
        }
        pos3 = strstr(posvis3, "arrival");//locate time of arrival of vistors//
        pos4 = strstr(posvis3, "nights");//locate the nights
        for (i = 0; i < 10; i++) {
            *(time2 + i) = str[pos3 - str + 8 + i];
        }
        *(time2 + 10) = '\0';
        *A = str[pos4 + 7 - str];
        *(A + 1) = '\0';
        a = atoi(A);
        if (time1 == (timetonumber(time2) + a)) {//this vistor is going to check out today.
            vacant++;
            i = 0;
            while (str[posvis3 + 5 - str + i] != '\n') {
                *(name + i) = str[posvis3 + 5 - str + i];
                i++;
            }
            *(name + i) = '\0';//the end of the name
            pos2 = strstr(posvis3, "id");
            i = 0;
            while (str[pos2 + 3 - str + i] != '\n') {
                *(id + i) = str[pos2 + 3 - str + i];
                i++;
            }
            *(id + i) = '\0';
            pos2 = strstr(posvis3, "price");
            i = 0;
            while (str[pos2 + 6 - str + i] != '\n') {
                *(pricei + i) = str[pos2 + 6 - str + i];
                i++;
            }
            *(pricei + i) = '\0';
            price = atoi(pricei);
            pos2 = strstr(posvis3, "breakfast");
            i = 0;
            *breakfasti = str[pos2 + 10 - str + i];
            *(breakfasti + 1) = '\0';
            int breakfast = atoi(breakfasti);
            int roomnum = atoi(room1);
            checkoutcards(name, id, time2, roomnum, a, price, breakfast);
            FILE *fp1 = fopen("hotel.db", "w");
            if(!fp1){
                printf("ERROR IN POS17");
            }
            for (i = 0; i < (pos - str + 6); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            fprintf(fp1, "type=dorm\n");
            fprintf(fp1, "vacant=%d\n", vacant);
            fprintf(fp1, "vistors=%d\n", 6 - vacant);
            pos2 = strstr(pos, "vistors");
            pos2 = strstr(pos2, "\n");
            for (i = (pos2 - str+1); i < (posvis3 - str); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            pos2 = strstr(pos2, "room");
            i = pos2 - str;
            while (str[i - 2] != '-') {
                fprintf(fp1, "%c", str[i - 1]);
                i++;
            }//copy the part after
            fclose(fp1);
        }
    } else if (number == '4') {
        int vacant = 4;
        posvis1 = strstr(pos, "name");
        posvis2 = strstr(posvis1+1, "name");
        char* pos3 = strstr(posvis1, "arrival");//locate time of arrival of vistors 1
        char* pos4 = strstr(posvis1, "nights");//locate the nights
        for (i = 0; i < 10; i++) {
            *(time2 + i) = str[pos3 - str + 8 + i];
        }
        *(time2 + 10) = '\0';
        char *A = malloc(sizeof(char) * 2);
        *A = str[pos4 + 7 - str];
        *(A + 1) = '\0';
        int a = atoi(A);
        if (time1 == (timetonumber(time2) + a)) {//this vistor is going to check out today.
            vacant++;
            i = 0;
            while (str[posvis1 + 5 - str + i] != '\n') {
                *(name + i) = str[posvis1 + 5 - str + i];
                i++;
            }
            *(name + i) = '\0';//the end of the name
            pos2 = strstr(posvis1, "id");
            i = 0;
            while (str[pos2 + 3 - str + i] != '\n') {
                *(id + i) = str[pos2 + 3 - str + i];
                i++;
            }
            *(id + i) = '\0';
            pos2 = strstr(posvis1, "price");
            i = 0;
            while (str[pos2 + 6 - str + i] != '\n') {
                *(pricei + i) = str[pos2 + 6 - str + i];
                i++;
            }
            *(pricei + i) = '\0';
            price = atoi(pricei);
            pos2 = strstr(posvis1, "breakfast");
            i = 0;
            *breakfasti = str[pos2 + 10 - str + i];
            *(breakfasti + 1) = '\0';
            int breakfast = atoi(breakfasti);
            int roomnum = atoi(room1);
            checkoutcards(name, id, time2, roomnum, a, price, breakfast);

            FILE *fp1 = fopen("hotel.db", "w");
            if(!fp1){
                printf("ERROR IN POS18");
            }
            for (i = 0; i < (pos - str + 6); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            fprintf(fp1, "type=dorm\n");
            fprintf(fp1, "vacant=%d\n", vacant);
            fprintf(fp1, "vistors=%d\n\n", 6 - vacant);
            i = posvis2 - str;
            while (str[i - 1] != '-') {
                fprintf(fp1, "%c", str[i ]);
                i++;
            }//copy the part after
            fclose(fp1);
            number = '5';
            checkdorm(number, room1, time1);
            return;}
            pos3 = strstr(posvis2, "arrival");//locate time of arrival of vistors 1
            pos4 = strstr(posvis2, "nights");//locate the nights
            for (i = 0; i < 10; i++) {
                *(time2 + i) = str[pos3 - str + 8 + i];
            }
            *(time2 + 10) = '\0';
            *A = str[pos4 + 7 - str];
            *(A + 1) = '\0';
            a = atoi(A);
            if (time1 == (timetonumber(time2) + a)) {//this vistor is going to check out today.
                vacant++;
                i = 0;
                while (str[posvis2 + 5 - str + i] != '\n') {
                    *(name + i) = str[posvis2 + 5 - str + i];
                    i++;
                }
                *(name + i) = '\0';//the end of the name
                pos2 = strstr(posvis2, "id");
                i = 0;
                while (str[pos2 + 3 - str + i] != '\n') {
                    *(id + i) = str[pos2 + 3 - str + i];
                    i++;
                }
                *(id + i) = '\0';
                pos2 = strstr(posvis2, "price");
                i = 0;
                while (str[pos2 + 6 - str + i] != '\n') {
                    *(pricei + i) = str[pos2 + 6 - str + i];
                    i++;
                }
                *(pricei + i) = '\0';
                price = atoi(pricei);
                pos2 = strstr(posvis2, "breakfast");
                i = 0;
                *breakfasti = str[pos2 + 10 - str + i];
                *(breakfasti + 1) = '\0';
                int breakfast = atoi(breakfasti);
                int roomnum = atoi(room1);
                checkoutcards(name, id, time2, roomnum, a, price, breakfast);

                FILE *fp1 = fopen("hotel.db", "w");
                if(!fp1){
                    printf("ERROR IN POS19");
                }
                for (i = 0; i < (pos - str + 6); i++)
                    fprintf(fp1, "%c", str[i]);//copy the part before
                fprintf(fp1, "type=dorm\n");
                fprintf(fp1, "vacant=%d\n", vacant);
                fprintf(fp1, "vistors=%d\n", 6 - vacant);
                pos2 = strstr(pos, "vistors");
                pos2 = strstr(pos2, "\n");
                for (i = (pos2 - str+1); i < (posvis2 - str); i++)
                    fprintf(fp1, "%c", str[i]);//copy the part before
                pos2 = strstr(pos2, "room");
                i = pos2 - str;
                while (str[i - 2] != '-') {
                    fprintf(fp1, "%c", str[i - 1]);
                    i++;
                }//copy the part after
                fclose(fp1);}

    } else if (number == '5') {
        int vacant = 5;
        posvis1 = strstr(pos, "name");
        char *pos3 = strstr(posvis1, "arrival");//locate time of arrival of vistors 1
        char *pos4 = strstr(posvis1, "nights");//locate the nights
        for (i = 0; i < 10; i++) {
            *(time2 + i) = str[pos3 - str + 8 + i];
        }
        *(time2 + 10) = '\0';
        char *A = malloc(sizeof(char) * 2);
        *A = str[pos4 + 7 - str];
        *(A + 1) = '\0';
        int a = atoi(A);
        if (time1 == (timetonumber(time2) + a)) {//this vistor is going to check out today.
            vacant++;
            i = 0;
            while (str[posvis1 + 5 - str + i] != '\n') {
                *(name + i) = str[posvis1 + 5 - str + i];
                i++;
            }
            *(name + i) = '\0';//the end of the name
            pos2 = strstr(posvis1, "id");
            i = 0;
            while (str[pos2 + 3 - str + i] != '\n') {
                *(id + i) = str[pos2 + 3 - str + i];
                i++;
            }
            *(id + i) = '\0';
            pos2 = strstr(posvis1, "price");
            i = 0;
            while (str[pos2 + 6 - str + i] != '\n') {
                *(pricei + i) = str[pos2 + 6 - str + i];
                i++;
            }
            *(pricei + i) = '\0';
            price = atoi(pricei);
            pos2 = strstr(posvis1, "breakfast");
            i = 0;
            *breakfasti = str[pos2 + 10 - str + i];
            *(breakfasti + 1) = '\0';
            int breakfast = atoi(breakfasti);
            int roomnum = atoi(room1);
            checkoutcards(name, id, time2, roomnum, a, price, breakfast);

            FILE *fp1 = fopen("hotel.db", "w");
            if(!fp1){
                printf("ERROR IN POS20");
            }
            for (i = 0; i < (pos - str + 6); i++)
                fprintf(fp1, "%c", str[i]);//copy the part before
            fprintf(fp1, "type=dorm\n");
            fprintf(fp1, "vacant=%d\n", vacant);
            fprintf(fp1, "vistors=%d\n\n", 6 - vacant);
            pos2 = strstr(pos2, "room");
            i = pos2 - str;
            while (str[i - 1] != '-') {
                fprintf(fp1, "%c", str[i]);
                i++;
            }//copy the part after
            fclose(fp1);
        }

    }
    free(name);free(id);free(pricei);free(breakfasti);free(time2);free(A); }
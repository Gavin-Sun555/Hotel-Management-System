#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hotel-ll.h"
#include "hotel-mt.h"
#include "hotel-db.h"
int Initialdata() {
    FILE *fp = fopen("hotel.db", "w");
    if(fp==NULL)
    {return -1;}
    fprintf(fp,"\n[room 8101]\n");//8 means nothing but lucky in China and nearly all the hotels use this method to name the room number.
    fprintf(fp,"type=dorm\n");
    fprintf(fp,"vacant=6\n");
    fprintf(fp,"vistors=0\n");
    fprintf(fp,"\n[room 8102]\n");
    fprintf(fp,"type=dorm\n");
    fprintf(fp,"vacant=6\n");
    fprintf(fp,"vistors=0\n");
    fprintf(fp,"\n[room 8103]\n");
    fprintf(fp,"type=double\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8105]\n");//in China 4 is unlucky. Hence, most hotels skip this number.
    fprintf(fp,"type=double\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8106]\n");
    fprintf(fp,"type=double\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8107]\n");
    fprintf(fp,"type=double\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8108]\n");
    fprintf(fp,"type=double\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8109]\n");
    fprintf(fp,"type=double\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8110]\n");
    fprintf(fp,"type=double\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8201]\n");
    fprintf(fp,"type=dorm\n");
    fprintf(fp,"vacant=6\n");
    fprintf(fp,"vistors=0\n");
    fprintf(fp,"\n[room 8202]\n");
    fprintf(fp,"type=dorm\n");
    fprintf(fp,"vacant=6\n");
    fprintf(fp,"vistors=0\n");
    fprintf(fp,"\n[room 8203]\n");
    fprintf(fp,"type=double\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8205]\n");
    fprintf(fp,"type=double\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8206]\n");
    fprintf(fp,"type=double\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8207]\n");
    fprintf(fp,"type=double\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8208]\n");
    fprintf(fp,"type=double\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8209]\n");
    fprintf(fp,"type=double\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8210]\n");
    fprintf(fp,"type=double\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8301]\n");
    fprintf(fp,"type=single\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8302]\n");
    fprintf(fp,"type=single\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8303]\n");
    fprintf(fp,"type=single\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8305]\n");
    fprintf(fp,"type=single\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8306]\n");
    fprintf(fp,"type=double\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8307]\n");
    fprintf(fp,"type=double\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8308]\n");
    fprintf(fp,"type=double\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8309]\n");
    fprintf(fp,"type=double\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8310]\n");
    fprintf(fp,"type=family\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8501]\n");//for the same reason, floor 4 is skipped in this hotel.
    fprintf(fp,"type=single\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8502]\n");
    fprintf(fp,"type=single\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8503]\n");
    fprintf(fp,"type=single\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8505]\n");
    fprintf(fp,"type=single\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8506]\n");
    fprintf(fp,"type=double\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8507]\n");
    fprintf(fp,"type=double\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8508]\n");
    fprintf(fp,"type=double\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8509]\n");
    fprintf(fp,"type=double\n");
    fprintf(fp,"vacant=1\n");
    fprintf(fp,"\n[room 8510]\n");// in China, there are rarely situation that people would choose family room. Hence only two in these hotel.
    fprintf(fp,"type=family\n");
    fprintf(fp,"vacant=1\n\n");
    fprintf(fp,"[DATABASE END]-");
    fclose(fp);
    return 0;
}
void checkin(node_t* a,char* time1){
    int vis=*((int*)(a->ch));
    char* number;
    if(vis==0) {
        number = searchsingle();
        if(number==NULL)
        { printf("------------------------------WARNING------------------------------\n");
            printf("Dear %s, We are sincerely sorry to inform you that single room is full.\n",(char*)a->next->ch);//the hotel is full
            printf("------------------------------WARNING END------------------------------\n\n");
            free(number);
            FreeList(&a);
            return;}
        CheckinSingleRoom(number,a,time1);
        Checkincards(number,a);
    }
    else if(vis==1) {
        number = searchdouble();
        if(number==NULL)
        {     printf("------------------------------WARNING------------------------------\n");
            printf("Dear %s and %s, We are sincerely sorry to inform you that double room is full.\n",(char*)a->next->ch,(char*)a->next->next->next->ch);//the hotel is full
            printf("------------------------------WARNING END------------------------------\n\n");
            free(number);
            FreeList(&a);
            return;}
        CheckinDoubleRoom(number,a,time1);
        Checkincards(number,a);
    }
    else if(vis==2) {
        number = searchfamily();
        if(number==NULL)
        { printf("------------------------------WARNING------------------------------\n");
            printf("Dear %s, %s and %s, We are sincerely sorry to inform you that family room is full.\n",(char*)a->next->ch,(char*)a->next->next->next->ch,(char*)a->next->next->next->next->next->ch);//the hotel is full
            printf("------------------------------WARNING END------------------------------\n\n");
            free(number);
            FreeList(&a);
            return;}
        CheckinFamilyRoom(number,a,time1);
        Checkincards(number,a);
    }
    else if(vis==3) {
        number = searchdorm();
        if(number==NULL)
        {
            printf("------------------------------WARNING------------------------------\n");
            printf("The Dorm is full.\n");
            printf("------------------------------WARNING END------------------------------\n\n");
            free(number);
            FreeList(&a);
            return;}//the hotel is full
        CheckinDorm(number,a,time1);
        Checkincards(number,a);
    }
    free(number);
    FreeList(&a);
}
char* searchsingle(){
    char str[10000];
    char* room=calloc(sizeof(char),5);//remember to return the memory!!!
    int i=0;
    FILE* fp=fopen("hotel.db","r");
    while (feof(fp)==0){//not reach the end//
        str[i]=fgetc(fp);
        i++;}
    char* pos=strstr(str,"single");
    while (*(pos+14)!='1') ///the room is vacant /only data base with fixed format can work.
    {pos=strstr((pos+1),"single");
        if (pos==NULL){
            return NULL;
        }
    }
    for(i=0;i<4;i++)
        *(room+i)=*(pos-11+i);

    fclose(fp);
    return room;
}
char* searchdouble(){
    char str[10000];
    char* room=calloc(sizeof(char),5);//remember to return the memory!!!
    int i=0;
    FILE* fp=fopen("hotel.db","r");
    while (feof(fp)==0){//not reach the end//
        str[i]=fgetc(fp);
        i++;}
    char* pos=strstr(str,"double");
    while (*(pos+14)!='1') ///the room is vacant /only data base with fixed format can work.
    {pos=strstr((pos+1),"double");
        if (pos==NULL){
            return NULL;
        }
    }
    for(i=0;i<4;i++)
        *(room+i)=*(pos-11+i);
    fclose(fp);
    return room;
}
char* searchfamily(){
    char str[10000];
    char* room=calloc(sizeof(char),5);
    int i=0;
    FILE* fp=fopen("hotel.db","r");
    while (feof(fp)==0){//not reach the end//
        str[i]=fgetc(fp);
        i++;}
    char* pos=strstr(str,"family");
    while (*(pos+14)!='1') ///the room is vacant /only data base with fixed format can work.
    {pos=strstr((pos+1),"family");
        if (pos==NULL){
            return NULL;
        }
    }
    for(i=0;i<4;i++){
        *(room+i)=*(pos-11+i);}//12 works well in my system. It should be 11 in my understanding.
                *(room+4)='\0';
    fclose(fp);
    return room;
}
char* searchdorm(){
    char str[10000];
    char* room=calloc(sizeof(char),5);//remember to return the memory!!!
    int i=0;
    FILE* fp=fopen("hotel.db","r");
    while (feof(fp)==0){//not reach the end//
        str[i]=fgetc(fp);
        i++;}
    char* pos=strstr(str,"dorm");
    while (*(pos+12)=='0') ///the room is vacant /only data base with fixed format can work.
    {pos=strstr((pos+1),"dorm");
        if (pos==NULL){
            return NULL;
        }
    }
    for(i=0;i<4;i++)
        *(room+i)=*(pos-11+i);
    fclose(fp);
    return room;
}
void Checkincards(char* room,node_t* guest){
    int key,breakfast,price;
    printf("------------------------------Checkin Cards------------------------------\n");
    printf("WELCOME TO 'no-star hotel'\n");//The name of our hotel is called no-star hotel//
    printf("Room Number:%s\n",room);
    if((*((int*)(guest->ch))+1)!=4)
        printf("Number of people:%d\n",(*((int*)(guest->ch))+1));
    else
        printf("Number of people:1\n");
    if (*((int*)(guest->ch))==0){
        guest=guest->next;
        printf("Your name:%s\n",(char*)guest->ch);
        guest=guest->next;
        printf("Your ID:%s\n",(char*)guest->ch);
        guest=guest->next;
        key=*(int*)guest->ch;
        printf("Your Key:%d\n",key);
        guest=guest->next;
        breakfast=*(int*)guest->ch;
        printf("Your Breakfast:%d\n",breakfast);
        guest=guest->next;
        printf("Your Nights:%d\n",*(int*)guest->ch);
        price=*(int*)guest->ch*60+breakfast*15;
        printf("Total price:%d\n",price);
        printf("Hope you have a nice day. If there are some problems in your room, please try to fix it by yourself first. Our staff are too busy to do that. Thanks for your understanding.\n");
        printf("------------------------------The end of Checkin Cards------------------------------\n\n");
    }//single room
    else if (*((int*)(guest->ch))==1){
        guest=guest->next;
        printf("Your name1:%s\n",(char*)guest->ch);
        guest=guest->next;
        printf("Your ID1:%s\n",(char*)guest->ch);
        guest=guest->next;
        printf("Your name2:%s\n",(char*)guest->ch);
        guest=guest->next;
        printf("Your ID2:%s\n",(char*)guest->ch);
        guest=guest->next;
        key=*(int*)guest->ch;
        printf("Your Key:%d\n",key);
        guest=guest->next;
        breakfast=*(int*)guest->ch;
        printf("Your Breakfast:%d\n",breakfast);
        guest=guest->next;
        printf("Your Nights:%d\n",*(int*)guest->ch);
        price=*(int*)guest->ch*80+breakfast*15;
        printf("Total price:%d\n\n",price);
        printf("Hope you have a nice day. If there are some problems in your room, please try to fix it by yourself first. Our staff are too busy to do that. Thanks for your understanding.\n");
        printf("------------------------------The end of Checkin Cards------------------------------\n\n");
    }//double room
    else if (*((int*)(guest->ch))==2){
        guest=guest->next;
        printf("Your name1:%s\n",(char*)guest->ch);
        guest=guest->next;
        printf("Your ID1:%s\n",(char*)guest->ch);
        guest=guest->next;
        printf("Your name2:%s\n",(char*)guest->ch);
        guest=guest->next;
        printf("Your ID2:%s\n",(char*)guest->ch);
        guest=guest->next;
        printf("Your name3:%s\n",(char*)guest->ch);
        guest=guest->next;
        printf("Your ID3:%s\n",(char*)guest->ch);
        guest=guest->next;
        key=*(int*)guest->ch;
        printf("Your Key:%d\n",key);
        guest=guest->next;
        breakfast=*(int*)guest->ch;
        printf("Your Breakfast:%d\n",breakfast);
        guest=guest->next;
        printf("Your Nights:%d\n",*(int*)guest->ch);
        price=*(int*)guest->ch*100+breakfast*15;
        printf("Total price:%d\n\n",price);
        printf("Hope you have a nice day. If there are some problems in your room, please try to fix it by yourself first. Our staff are too busy to do that. Thanks for your understanding.\n");
        printf("------------------------------The end of Checkin Cards------------------------------\n\n");
    }//Treble room
    else if (*((int*)(guest->ch))==3){
        guest=guest->next;
        printf("Your name1:%s\n",(char*)guest->ch);
        guest=guest->next;
        printf("Your ID1:%s\n",(char*)guest->ch);
        guest=guest->next;
        key=*(int*)guest->ch;
        printf("Your Key1:%d\n",key);
        guest=guest->next;
        breakfast=*(int*)guest->ch;
        printf("Your Breakfast1:%d\n",breakfast);
        guest=guest->next;
        printf("Your Nights1:%d\n",*(int*)guest->ch);
        price=*(int*)guest->ch*20+breakfast*15;
        printf("Total price1:%d\n\n",price);
        printf("Hope you have a nice day. If there are some problems in your room, please try to fix it by yourself first. Our staff are too busy to do that. Thanks for your understanding.\n");
        printf("------------------------------The end of Checkin Cards------------------------------\n\n");
    }//dorm
}
typedef struct _vistorlist{char* firstname;char*givenname;}visitorlist;
node_t* generatevistors(int a){
    a=a+(int)time(NULL);
    srand(a);
    int first,last;
    node_t* visitor;
    int* random_varible=malloc(sizeof(int));
    visitorlist* vistorlist1=malloc(50 * sizeof(visitorlist)) ;
    *vistorlist1=(visitorlist){"Yan", "Sun",};
    *(vistorlist1+1)=(visitorlist){"Yihao", "Liu"};
    *(vistorlist1+2)=(visitorlist){"Aaron", "Smith"};
    *(vistorlist1+3)=(visitorlist){"Abe", "Jones"};
    *(vistorlist1+4)=(visitorlist){"Adam", "Patel"};
    *(vistorlist1+5)=(visitorlist){"Adan", "Davis"};
    *(vistorlist1+6)=(visitorlist){"Adrian", "Bell"};
    *(vistorlist1+7)=(visitorlist){"Agustin", "Baker"};
    *(vistorlist1+8)=(visitorlist){"Ahmad", "Liu"};
    *(vistorlist1+9)=(visitorlist){"Alan", "Thomas"};
    *(vistorlist1+10)=(visitorlist){"Albert", "Jones"};
    *(vistorlist1+11)=(visitorlist){"Aldo", "Roberts"};
    *(vistorlist1+12)=(visitorlist){"Alfredo", "Davis"};
    *(vistorlist1+13)=(visitorlist){"Ali", "Johnson"};
    *(vistorlist1+14)=(visitorlist){"Allan", "Gibson"};
    *(vistorlist1+15)=(visitorlist){"Alton", "Wells"};
    *(vistorlist1+16)=(visitorlist){"Andy", "Murphy"};
    *(vistorlist1+17)=(visitorlist){"Anibal", "Foster"};
    *(vistorlist1+18)=(visitorlist){"Becky", "Mills"};
    *(vistorlist1+19)=(visitorlist){"Bert", "Hart"};
    *(vistorlist1+20)=(visitorlist){"Brant", "Gill"};
    *(vistorlist1+21)=(visitorlist){"Brett", "White"};
    *(vistorlist1+22)=(visitorlist){"Chad", "Jackson"};
    *(vistorlist1+23)=(visitorlist){"Chang", "Green"};
    *(vistorlist1+24)=(visitorlist){"Chase", "Watson"};
    *(vistorlist1+25)=(visitorlist){"Chong", "King"};
    *(vistorlist1+26)=(visitorlist){"Colin", "Lee"};
    *(vistorlist1+27)=(visitorlist){"Colton", "Fox"};
    *(vistorlist1+28)=(visitorlist){"Conrad", "Hunt"};
    *(vistorlist1+29)=(visitorlist){"David", "Kelly"};
    *(vistorlist1+30)=(visitorlist){"Donald", "Trump"};
    *(vistorlist1+31)=(visitorlist){"Donny", "Adams"};
    *(vistorlist1+32)=(visitorlist){"Dylan", "Allen"};
    *(vistorlist1+33)=(visitorlist){"Earl", "Ross"};
    *(vistorlist1+34)=(visitorlist){"Eddie", "Owen"};
    *(vistorlist1+35)=(visitorlist){"Edmundo", "Mason"};
    *(vistorlist1+36)=(visitorlist){"Edward", "Knight"};
    *(vistorlist1+37)=(visitorlist){"Edwin", "Butler"};
    *(vistorlist1+38)=(visitorlist){"Elvin", "Saunders"};
    *(vistorlist1+39)=(visitorlist){"Gale", "Stevens"};
    *(vistorlist1+40)=(visitorlist){"Galen", "Webb"};
    *(vistorlist1+41)=(visitorlist){"Hobert", "Bradley"};
    *(vistorlist1+42)=(visitorlist){"Jack", "Jenkins"};
    *(vistorlist1+43)=(visitorlist){"Jarod", "Carter"};
    *(vistorlist1+44)=(visitorlist){"Jerry", "Phillips"};
    *(vistorlist1+45)=(visitorlist){"Juan", "Mitchell"};
    *(vistorlist1+46)=(visitorlist){"Jude", "Anderson"};
    *(vistorlist1+47)=(visitorlist){"Kim", "Walsh"};
    *(vistorlist1+48)=(visitorlist){"Leo", "Stone"};
    *(vistorlist1+49)=(visitorlist){"Loyd", "West"};
    *random_varible=rand()%4;
    int randomnumber1=rand();
    int randomnumber2=rand();
    int randomnumber3=rand();
    int randomnumber4=rand();
    int randomnumber5=rand();
    int randomnumber6=rand();
    if(*random_varible==0)//single room
    { visitor=Initialize(random_varible);
        first=(int)strlen((vistorlist1+(randomnumber1%50))->firstname);
        last=(int)strlen((vistorlist1+(randomnumber2%50))->givenname);
        char* full=malloc(first+last+2);//one for space and another for the symbol at the end of the string.
        memcpy(full,((vistorlist1+(randomnumber1%50))->firstname), first);
        memcpy(full+first+1,((vistorlist1+(randomnumber2%50))->givenname), last+ 1); // +1 to copy the null-terminator
        *(full+first)=' ';//REMEMBER TO RETURN THE MEMORY!!!!
        InsertLastList(&visitor, full);//insert name

        char* id3=malloc(sizeof(char)*9);
        sprintf(id3,"%03u",rand()%1000);
        sprintf((id3+3),"%03u",rand()%1000);
        *(id3+6)='A';
        *(id3+7)='B';
        *(id3+8)='\0';//mark as the end of the ID string;
        InsertLastList(&visitor, id3);//insert ID
        int* key=malloc(sizeof(int));
        *key=rand()%2+1;
        InsertLastList(&visitor, key);//key(may ask 1-2)
        int* breakfast=malloc(sizeof(int));
        int* nights=malloc(sizeof(int));
        *nights=rand()%9+1;
        *breakfast=rand()%2*( *nights);
        InsertLastList(&visitor, breakfast);//key(may ask 0-1)
        InsertLastList(&visitor, nights);//key(may ask 1-9)
    }
    else if (*random_varible==1)//double room
    { visitor=Initialize(random_varible);
        first=(int)strlen((vistorlist1+(randomnumber1%50))->firstname);
        last=(int)strlen((vistorlist1+(randomnumber2%50))->givenname);
        char* full=malloc(first+last+2);//one for space and another for the symbol at the end of the string.
        memcpy(full,((vistorlist1+(randomnumber1%50))->firstname), first);
        memcpy(full+first+1,((vistorlist1+(randomnumber2%50))->givenname), last+ 1); // +1 to copy the null-terminator
        *(full+first)=' ';//REMEMBER TO RETURN THE MEMORY!!!!
        InsertLastList(&visitor, full);//insert name

        char* id3=malloc(sizeof(char)*9);
        sprintf(id3,"%03u",rand()%1000);
        sprintf((id3+3),"%03u",rand()%1000);
        *(id3+6)='A';
        *(id3+7)='B';
        *(id3+8)='\0';
        InsertLastList(&visitor, id3);//insert ID
        first=(int)strlen((vistorlist1+(randomnumber3%50))->firstname);
        last=(int)strlen((vistorlist1+(randomnumber4%50))->givenname);
        char* full2=malloc(first+last+2);//one for space and another for the symbol at the end of the string.
        memcpy(full2,((vistorlist1+(randomnumber3%50))->firstname), first);
        memcpy(full2+first+1,((vistorlist1+(randomnumber4%50))->givenname), last+ 1); // +1 to copy the null-terminator
        *(full2+first)=' ';//REMEMBER TO RETURN THE MEMORY!!!!

        InsertLastList(&visitor, full2);//insert name2
        char* id32=malloc(sizeof(char)*9);
        sprintf(id32,"%03u",rand()%1000);
        sprintf((id32+3),"%03u",rand()%1000);
        *(id32+6)='A';
        *(id32+7)='B';
        *(id32+8)='\0';
        InsertLastList(&visitor, id32);//insert ID2

        int* key=malloc(sizeof(int));
        *key=rand()%2+1;
        InsertLastList(&visitor, key);//key(may ask 1-2)
        int* breakfast=malloc(sizeof(int));
        int* nights=malloc(sizeof(int));
        *nights=rand()%9+1;
        *breakfast=rand()%3*( *nights);
        InsertLastList(&visitor, breakfast);//key(may ask 0-2)
        InsertLastList(&visitor, nights);//key(may ask 1-9)
    }
    else if (*random_varible==2)//family room
    { visitor=Initialize(random_varible);
        first=(int)strlen((vistorlist1+(randomnumber1%50))->firstname);
        last=(int)strlen((vistorlist1+(randomnumber2%50))->givenname);
        char* full=malloc(first+last+2);//one for space and another for the symbol at the end of the string.
        memcpy(full,((vistorlist1+(randomnumber1%50))->firstname), first);
        memcpy(full+first+1,((vistorlist1+(randomnumber2%50))->givenname), last+ 1); // +1 to copy the null-terminator
        *(full+first)=' ';//REMEMBER TO RETURN THE MEMORY!!!!
        InsertLastList(&visitor, full);//insert name

        char* id3=malloc(sizeof(char)*9);
        sprintf(id3,"%03u",rand()%1000);
        sprintf((id3+3),"%03u",rand()%1000);
        *(id3+6)='A';
        *(id3+7)='B';
        *(id3+8)='\0';
        InsertLastList(&visitor, id3);//insert ID
        first=(int)strlen((vistorlist1+(randomnumber3%50))->firstname);
        last=(int)strlen((vistorlist1+(randomnumber4%50))->givenname);
        char* full2=malloc(first+last+2);//one for space and another for the symbol at the end of the string.
        memcpy(full2,((vistorlist1+(randomnumber3%50))->firstname), first);
        memcpy(full2+first+1,((vistorlist1+(randomnumber4%50))->givenname), last+ 1); // +1 to copy the null-terminator
        *(full2+first)=' ';//REMEMBER TO RETURN THE MEMORY!!!!
        InsertLastList(&visitor, full2);//insert name2

        char* id32=malloc(sizeof(char)*9);
        sprintf(id32,"%03u",rand()%1000);
        sprintf((id32+3),"%03u",rand()%1000);
        *(id32+6)='A';
        *(id32+7)='B';
        *(id32+8)='\0';
        InsertLastList(&visitor, id32);//insert ID2
        first=(int)strlen((vistorlist1+(randomnumber5%50))->firstname);
        last=(int)strlen((vistorlist1+(randomnumber6%50))->givenname);
        char* full3=malloc(first+last+2);//one for space and another for the symbol at the end of the string.
        memcpy(full3,((vistorlist1+(randomnumber5%50))->firstname), first);
        memcpy(full3+first+1,((vistorlist1+(randomnumber6%50))->givenname), last+ 1); // +1 to copy the null-terminator
        *(full3+first)=' ';//REMEMBER TO RETURN THE MEMORY!!!!
        InsertLastList(&visitor, full3);//insert name2

        char* id33=malloc(sizeof(char)*9);
        sprintf(id33,"%03u",rand()%1000);
        sprintf((id33+3),"%03u",rand()%1000);
        *(id33+6)='A';
        *(id33+7)='B';
        *(id33+8)='\0';
        InsertLastList(&visitor, id33);//insert ID2
        int* key=malloc(sizeof(int));
        *key=rand()%3+1;
        InsertLastList(&visitor, key);//key(may ask 1-2)
        int* breakfast=malloc(sizeof(int));
        int* nights=malloc(sizeof(int));
        *nights=rand()%9+1;
        *breakfast=(rand()%4)*( *nights);
        InsertLastList(&visitor, breakfast);//key(may ask 0-3)
        InsertLastList(&visitor, nights);//key(may ask 1-9)
    }
    else //dorm
    { visitor=Initialize(random_varible);
        first=(int)strlen((vistorlist1+(randomnumber5%50))->firstname);
        last=(int)strlen((vistorlist1+(randomnumber6%50))->givenname);
        char* full=malloc(first+last+2);//one for space and another for the symbol at the end of the string.
        memcpy(full,((vistorlist1+(randomnumber5%50))->firstname), first);
        memcpy(full+first+1,((vistorlist1+(randomnumber6%50))->givenname), last+ 1); // +1 to copy the null-terminator
        *(full+first)=' ';//REMEMBER TO RETURN THE MEMORY!!!!
        InsertLastList(&visitor, full);//insert name

        char* id3=malloc(sizeof(char)*9);
        sprintf(id3,"%03u",rand()%1000);
        sprintf((id3+3),"%03u",rand()%1000);
        *(id3+6)='A';
        *(id3+7)='B';
        *(id3+8)='\0';
        InsertLastList(&visitor, id3);//insert ID
        int* key=malloc(sizeof(int));
        *key=rand()%2;
        InsertLastList(&visitor, key);//key(may ask 0-1)
        int* breakfast=malloc(sizeof(int));
        int* nights=malloc(sizeof(int));
        *nights=rand()%9+1;
        *breakfast=rand()%2*( *nights);
        InsertLastList(&visitor, breakfast);//breakfast(may ask 0-1)
        InsertLastList(&visitor, nights);//nights(may ask 1-9)

    }
    free(vistorlist1);
    return visitor;
}

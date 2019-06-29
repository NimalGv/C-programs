#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct input{
    int PNR;
    char start;
    char end;
    int noOfTickets;
}INPUT;
INPUT IN[]={{1, 'A', 'C', 2},
            {2, 'A', 'E', 8},
            {3, 'A', 'C', 1},
            {4, 'A', 'B', 3},
            {5, 'A', 'B', 3},
            {6, 'C', 'D', 1},
            {7, 'C', 'D', 1} };

typedef struct passengers{
    int PNR;
    char start;
    char end;
    int noOfTickets;
    char status[20];
    struct passenger *next;
}PASSENGER;

PASSENGER *passengerStart;

typedef struct hold{
    PASSENGER *contain;
    int marked;
    struct hold *next;
}HOLD;

typedef struct waitinglist{
    int SeatAvailable;
    HOLD *start;
}WL;

WL waitingList[1]={2};

typedef struct stations{
    char station;
    int seatAvailable;
    HOLD *start;
}STATIONS;

STATIONS station[5];

int getdown;
int getin;

void initializeStation(){
    for(int i=0; i<5; i++){
        station[i].seatAvailable=8;
        station[i].station='A'+i;
        station[i].start=NULL;
    }
}

int getsDown(int index){
    int seats=0;
    for(HOLD *point=station[index].start; point; point=point->next){
        if(point->contain->end==index+'A' && point->marked==0){
            seats+=point->contain->noOfTickets;
            point->marked=1;
        }
    }
    return seats;
}

int getsIn(int index){
    int seats=0;
    for(HOLD *point=station[index].start; point; point=point->next){
        if(point->contain->start==index+'A')
            seats+=point->contain->noOfTickets;
    }
    return seats;
}

int isSeatAvailable(PASSENGER *passenger){
    for(int i=(passenger->start-'A'); i<=(passenger->end-'A'); i++)
        if(!(passenger->noOfTickets <= station[i].seatAvailable + getsDown(i)-getsIn(i)))
            return 0;
    return 1;
}

int updatePassenger(PASSENGER *passenger){
    HOLD *newHold;

   if(isSeatAvailable(passenger)){
        for(int i=(passenger->start-'A'); i<=(passenger->end-'A'); i++){
          // station[i].seatAvailable=(station[i].seatAvailable+getsDown(i)-getsIn(i))-passenger->noOfTickets;
           newHold=(HOLD*)malloc(sizeof(HOLD));
           newHold->contain=passenger;
           newHold->marked=0;
           newHold->next=NULL;
           if(!station[i].start){
                station[i].start=newHold;
           }else{
                newHold->next=station[i].start;
                station[i].start=newHold;
           }
        }
        strcpy(passengerStart->status, "CONFIRMED");
        return 1;
   }
   strcpy(passengerStart->status, "WAITING LIST");
   return 0;

}

void addPassenger(int pnr, char start, char end, int noOfTickets){
    PASSENGER *newPassenger;
    newPassenger=(PASSENGER*)malloc(sizeof(PASSENGER));
    newPassenger->PNR=pnr;
    newPassenger->start=start;
    newPassenger->end=end;
    newPassenger->noOfTickets=noOfTickets;
    newPassenger->next=NULL;
    if(!passengerStart)
        passengerStart=newPassenger;
    else{
        newPassenger->next=passengerStart;
        passengerStart=newPassenger;
    }

}

int seatAvailableInWaitingList(PASSENGER* passengerStart){
    if(passengerStart->noOfTickets <= waitingList[0].SeatAvailable)
        return 1;
    return 0;
}

void addToWaitingList(){
    HOLD *newHold;
    for(int i=0; i<passengerStart->noOfTickets; i++){
        newHold=(HOLD*)malloc(sizeof(HOLD));
        newHold->contain=passengerStart;
        newHold->next=NULL;
        if(!waitingList->start){
            waitingList->start=newHold;
            waitingList->SeatAvailable-=passengerStart->noOfTickets;
        }else{
            newHold->next=waitingList->start;
            waitingList->start=newHold;
            waitingList->SeatAvailable-=passengerStart->noOfTickets;
        }
    }
}

void printWaitingList(){
    HOLD *point;
    printf("  WaitingList\n");
    for(point=waitingList->start; point; point=point->next)
        printf("%d %c %c %d ::: ", point->contain->PNR, point->contain->start, point->contain->end, point->contain->noOfTickets);
    printf("\n");
}


void printChart(){
    printf("\n  CHART\n\n");
    for(int i=0; i<5; i++){
        printf("[%c] || %d: ", station[i].station, station[i].seatAvailable);
        for(HOLD *point=station[i].start; point; point=point->next)
            printf("%d %c %c %d ::: ", point->contain->PNR, point->contain->start, point->contain->end, point->contain->noOfTickets);
        printf("\n");
    }
    printf("\n\n");

}

void printPassenger(){
    printf("\n  PASSENGERS\n\n");
    for(PASSENGER *point=passengerStart; point; printf("\n"), point=point->next)
        printf("%d || %c || %c || %d|| %s\n", point->PNR, point->start, point->end, point->noOfTickets, point->status);
}


int main(){
    int confirmed;
    initializeStation();
    for(int i=0; i<7; i++){
        addPassenger(IN[i].PNR, IN[i].start, IN[i].end, IN[i].noOfTickets);
        confirmed=updatePassenger(passengerStart);
        printf("Status: %d\n", confirmed);
        if(!confirmed){
            if(seatAvailableInWaitingList(passengerStart)){
                printf("Waiting List\n");
                addToWaitingList();
            }else{
                printf("Not Confirmed\n");
                passengerStart=passengerStart->next;
            }
        }
    }
    printPassenger();
    printChart();
    printWaitingList();
}

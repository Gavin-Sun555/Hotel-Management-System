#include "hotel-ll.h"
#include "hotel-mt.h"
#include "hotel-db.h"
#include "hotel-config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
    char roomNumber[10];
    char id[30];
    char time1[20];
    
    FILE *db_check = fopen("hotel.db", "r");
    if (db_check) {
        fclose(db_check);
    } else {
        printf("Database not found. Initiating first-time setup...\n");
        int single, double_r, family, dorm;
        printf("How many Single Rooms? "); scanf("%d", &single);
        printf("How many Double Rooms? "); scanf("%d", &double_r);
        printf("How many Family Rooms? "); scanf("%d", &family);
        printf("How many Dorm Rooms? "); scanf("%d", &dorm);
        initializeDatabase(single, double_r, family, dorm);
        printf("- DATABASE GENERATED SUCCESSFULLY\n");
    }
    
    // Get current real date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(time1, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    printf("========================================================\n");
    printf("        NO-STAR HOTEL INTERACTIVE MANAGEMENT SYSTEM     \n");
    printf("========================================================\n");
    printf("- SYSTEM INITIALIZED SUCCESSFULLY\n");
    printf("- CURRENT DATE: %s\n", time1);
    
    // Auto checkout for current date
    long long int currentDateNum = timeToNumber(time1);
    loadRates();
    checkout((int)currentDateNum);
    
    int choice = -1;
    while (choice != 0) {
        printf("\n--- Main Menu ---\n");
        printf("1. Check-In Guest(s)\n");
        printf("2. Check-Out Guest(s) (Force manual check-out / re-run daily check-outs)\n");
        printf("3. Modify Reservation (Change Breakfasts/Nights)\n");
        printf("4. Adjust Room Rates\n");
        printf("5. View Available Rooms\n");
        printf("6. View Checked-In Guests\n");
        printf("7. Lookup Guest or Room\n");
        printf("8. Factory Reset Database (Wipes Data)\n");
        printf("0. Exit System\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            node_t *guest = manualInputVisitor();
            checkin(guest, time1);
        } 
        else if (choice == 2) {
            printf("\nProcessing checkouts for %s...\n", time1);
            checkout((int)currentDateNum);
        }
        else if (choice == 3) {
            int breakfast, nights;
            printf("Enter Room Number: ");
            scanf("%s", roomNumber);
            printf("Enter Guest ID: ");
            scanf("%s", id);
            printf("Enter new total number of Breakfasts: ");
            scanf("%d", &breakfast);
            printf("Enter new total number of Nights: ");
            scanf("%d", &nights);
            
            if (changeBreakfastNights(roomNumber, id, breakfast, nights) == -1) {
                printf("FAIL TO OPERATE: Room/ID mismatch or Dorm room selected.\n");
            } else {
                printf("RESERVATION CHANGED SUCCESSFULLY.\n");
            }
        }
        else if (choice == 4) {
            printf("\n--- Current Rates ---\n");
            printf("Single Room: $%d\n", current_rates.single_rate);
            printf("Double Room: $%d\n", current_rates.double_rate);
            printf("Family Room: $%d\n", current_rates.family_rate);
            printf("Dorm Room: $%d\n", current_rates.dorm_rate);
            printf("Breakfast Add-on: $%d\n", current_rates.breakfast_rate);
            printf("\nEnter new Single Room rate: ");
            scanf("%d", &current_rates.single_rate);
            printf("Enter new Double Room rate: ");
            scanf("%d", &current_rates.double_rate);
            printf("Enter new Family Room rate: ");
            scanf("%d", &current_rates.family_rate);
            printf("Enter new Dorm Room rate: ");
            scanf("%d", &current_rates.dorm_rate);
            printf("Enter new Breakfast Add-on rate: ");
            scanf("%d", &current_rates.breakfast_rate);
            saveRates();
            printf("RATES UPDATED SUCCESSFULLY.\n");
        }
        else if (choice == 5) {
            listAvailableRooms();
        }
        else if (choice == 6) {
            listCheckedInGuests();
        }
        else if (choice == 7) {
            char query[50];
            printf("Enter Guest Name, ID, or Room Number to search: ");
            scanf("%s", query);
            searchDatabase(query);
        }
        else if (choice == 8) {
            printf("WARNING: This will erase all guests and reservations.\n");
            printf("Are you sure? (1 for Yes, 0 for No): ");
            int confirm;
            scanf("%d", &confirm);
            if (confirm == 1) {
                int single, double_r, family, dorm;
                printf("How many Single Rooms? "); scanf("%d", &single);
                printf("How many Double Rooms? "); scanf("%d", &double_r);
                printf("How many Family Rooms? "); scanf("%d", &family);
                printf("How many Dorm Rooms? "); scanf("%d", &dorm);
                initializeDatabase(single, double_r, family, dorm);
                printf("- DATABASE FACTORY RESET SUCCESSFULLY\n");
            } else {
                printf("Reset aborted.\n");
            }
        }
        else if (choice == 0) {
            printf("Exiting system...\n");
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

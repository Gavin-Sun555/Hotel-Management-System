#include "hotel-config.h"
#include <stdio.h>
#include <stdlib.h>

SystemRates current_rates = {60, 80, 100, 20, 15}; // Defaults

void loadRates(void) {
    FILE *fp = fopen("rates.cfg", "r");
    if (!fp) {
        // File doesn't exist, save the defaults
        saveRates();
        return;
    }
    
    fscanf(fp, "%d", &current_rates.single_rate);
    fscanf(fp, "%d", &current_rates.double_rate);
    fscanf(fp, "%d", &current_rates.family_rate);
    fscanf(fp, "%d", &current_rates.dorm_rate);
    fscanf(fp, "%d", &current_rates.breakfast_rate);
    fclose(fp);
}

void saveRates(void) {
    FILE *fp = fopen("rates.cfg", "w");
    if (!fp) {
        printf("Error: Could not open rates.cfg for writing.\\n");
        return;
    }
    fprintf(fp, "%d\\n", current_rates.single_rate);
    fprintf(fp, "%d\\n", current_rates.double_rate);
    fprintf(fp, "%d\\n", current_rates.family_rate);
    fprintf(fp, "%d\\n", current_rates.dorm_rate);
    fprintf(fp, "%d\\n", current_rates.breakfast_rate);
    fclose(fp);
}

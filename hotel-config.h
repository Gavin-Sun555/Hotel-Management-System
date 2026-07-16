#ifndef PROJECT_2_HOTEL_CONFIG_H
#define PROJECT_2_HOTEL_CONFIG_H

typedef struct {
    int single_rate;
    int double_rate;
    int family_rate;
    int dorm_rate;
    int breakfast_rate;
} SystemRates;

extern SystemRates current_rates;

void loadRates(void);
void saveRates(void);

#endif // PROJECT_2_HOTEL_CONFIG_H

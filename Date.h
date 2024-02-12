#ifndef DATE
#define DATE

int const monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

typedef struct{
    int day;
    int month;
    int year;
    
}Date;

int getCorrectDate(Date* d);

int checkDate(int d, int t);

void printDate(Date* d);


#endif // !DATE

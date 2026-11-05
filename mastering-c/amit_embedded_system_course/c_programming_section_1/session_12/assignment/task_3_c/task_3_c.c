#include <stdio.h>

typedef struct
{
    int hours;
    int minutes;
    int seconds;
}time;


void input_time(time*);
void calculate_time_difference(time*, time*, time*);
void print_time(time*);


int main(void)
{
    time start_t, end_t, diff_t;

    printf("Please, enter the {start time}:- \n"); input_time(&start_t);
    printf("\n\n");
    printf("Please, enter the end time:- \n"); input_time(&end_t);

    calculate_time_difference(&start_t, &end_t, &diff_t);

    printf("\n\nStart time: ");print_time(&start_t);
    printf("\nend time: ");print_time(&end_t);
    printf("\nPeriod: ");print_time(&diff_t);
    
    return 0;
}

void input_time(time* time_1)
{

    printf("Enter hours: ");   scanf(" %d", &time_1 -> hours);
    printf("Enter minutes: "); scanf(" %d", &time_1 -> minutes);
    printf("Enter seconds: "); scanf(" %d", &time_1 -> seconds);
}

void calculate_time_difference(time* time_1, time* time_2, time* diff)
{
    diff -> hours = time_2 -> hours - time_1 -> hours;
    diff -> minutes = time_2 -> minutes - time_1 -> minutes;
    diff -> seconds = time_2 -> seconds - time_1 -> seconds;
}

void print_time(time* time_t)
{
    printf("%d:%d:%d", (time_t->hours), (time_t->minutes), (time_t->seconds));
}
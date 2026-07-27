#include <iostream>
using std::cin;

double user_input_validation(double num, int integer, char choice)
{   
    if(choice == '1')
    {
        while(!(cin >> num) || (-0.0f > num || num > 100.0f))
        {
            if(!cin){printf("Illegitimate float Input, enter again: ");}
            else{printf("Your number: {%f} is out of range {0 to 100}, enter again: ", num);}
            cin.clear();
            cin.ignore(1000, '\n');
        }
        return num;
    }
    else
    {
        while(!(cin >> integer) ||( integer < 1 || integer > 100))
        {
            if(!cin){printf("Illegitimate integer Input, enter again: ");}
            else{printf("Your number: {%i} is out of range {1, 100}, enter again: ", integer);}
            cin.clear();
            cin.ignore(1000, '\n');
        }
        return (double)(integer);
    }
}

void declaration()
{
    printf("Welcome to 'Grade System'\nYou enter the number of students\nThen enter the score of each student\n\nThe program will process each student's score\nThen it outputs the student's score, corresponding grade\n\n");
    printf("Rules:\n1) The Number of students can not exceed 100\n2) The student's score can not exceed 100\n");
}

void array_filling(double arr[], unsigned const int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Enter the score for student {%i}: ", i + 1);
        arr[i] = user_input_validation(arr[i], 0, '1');
    }
}

double calculate_average(double arr[], unsigned const int n)
{
    double mean = 0;
    for(int i = 0; i < n; i ++)
    {mean += arr[i];}
    return mean/n;
}
double find_highest(double arr[], unsigned const int n , unsigned int &index)
{
    double high_score = arr[0];
    index = 0;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > high_score)
        {
            high_score = arr[i];
            index = i;
        }
    }
    return high_score;
}
double find_lowest(double arr[], unsigned const int n , unsigned int &index)
{
    double low_score = arr[0];
    index = 0;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] < low_score)
        {
            low_score = arr[i];
            index = i;
        }
    }    
    return low_score;
}

char grade_analyzer(double number)
{
    if(number >= 90.0){return 'A';}
    else if(number < 90.0 && number >= 75.0){return 'B';}
    else if(number < 75.0 && number >= 60.0){return 'C';}
    else if(number < 60.0 && number >= 50.0){return 'D';}
    else{return 'F';}
}

void pass_fail_checker(char grade, unsigned int &pass_count)
{
    if(grade == 'F'){printf("Fail "); return;}
    printf("Pass");
    pass_count ++;
}

void print_report(double arr[], unsigned const int n)
{
    unsigned int index = 0;
    printf("\n\n");
    printf("Student data table: \n");
    printf("Name:\t\tScore:\tGrade:\tStatus:\n");
    unsigned int pass_count = 0;
    for(int i = 0; i < n; i++)
    {
        char grade = grade_analyzer(arr[i]);
        printf("Student {%i}:\t", i + 1);
        printf("%.2f\t", arr[i]);
        printf("%c\t", grade);
        pass_fail_checker(grade, pass_count);
        printf("\n");
    }

    printf("\n\n");
    printf("Critical Statistics: \n\n");
    double high_score = find_highest(arr, n, index);
    printf("student {%i} has the highest score: (%.2f)\n", index + 1, high_score);
    double low_score = find_lowest(arr, n, index);
    printf("student {%i} has the lowest score: (%.2f)\n", index + 1, low_score);
    double average_score = calculate_average(arr, n);
    printf("Average Score: (%.2f)\n", average_score);
    printf("Passed students: (%i)\n", pass_count);
    printf("Failed students: (%i)\n", (n - pass_count));
    double total = (double)(n);
    printf("Pass rate: (%.3f%%)\n", ((double)(pass_count)/total)*100);
}

void grade_system()
{
    printf("\n\n");
    printf("Enter number of students: ");
    unsigned int int_size = user_input_validation(0, int_size, '2');
    unsigned const int student_count = int_size;
    double arr[student_count];

    array_filling(arr, student_count);
    print_report(arr, student_count);
}

int main()
{
    declaration();
    grade_system();
}
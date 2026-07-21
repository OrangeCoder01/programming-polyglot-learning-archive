
#include <iostream>
using std::cin;

int user_validation()
{
    int number = 0;
    while(true)
    {
        if(!(cin >> number))
        {
            printf("Invalid Input, enter input again: ");
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else{break;}
    }
    return number;
}

int max_arr()
{
    printf("Please, Enter the number of elements/numbers: ");
    int num_of_dig = -32;
    num_of_dig = user_validation();
    while(!(num_of_dig <= 10  && num_of_dig > 0))
    {
        if(!(num_of_dig <= 10  && num_of_dig > 0))
        {
            printf("Invalid input retry! \n");
            printf("Number of elements/numbers = ");
            num_of_dig = user_validation();
        }
    }


    int arr_num[num_of_dig];
    int number = 0;

    printf("Insert the values of your elements/numbers individually:\n");
    for(int i = 0; i < num_of_dig; i ++)
    {
        printf("Enter value for element {%i}: ",i);
        number = user_validation();

        while(!(number <= 0xffff && number >= -0xffff))
        {
            printf("You can not enter a value {not exceeding 65535 or lower than -65535}\n");
            printf("re-enter the value for elemenet {%i}: ",i);
            number = user_validation();      
        }
        arr_num[i] = number;
    }

    printf("Array: [");
    int max = 0;
    int min = 0;
    for(int i = 0; i <num_of_dig; i++)
    {
        if(arr_num[i] < min)
        {
            min = arr_num[i];
        }
    } 
    max = min;
    
    for(int i = 0; i < num_of_dig; i++)
    {
        printf("%i", arr_num[i]);
        if(arr_num[i] > max)
        {
            max = arr_num[i];
        }
        if(!(i == num_of_dig-1))
        {
            printf(", ");
        }
    }
    printf("] \n");

    return max;
}

int main()
{
    printf("Welcome, to #Largest Element in Array Finder#\nAll you have to do is to enter the number of elements/numbers you want to add,\nand then enter the value for each\nThen the output is printing out your input number and the largest element\n\n");
    printf("Note: Number of elements/numbers shouldn't {exceed 10 and not zero}, and max value for any element/number is {65535 in both signs}\n\n");
    printf("The largest element is %d", max_arr());
}
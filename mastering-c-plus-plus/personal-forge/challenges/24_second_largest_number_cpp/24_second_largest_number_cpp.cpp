#include <iostream>
using std::cin;

int user_input_validation()
{
    int user_input_integer = 0;
    while(!(cin >> user_input_integer))
    {
        printf("Illegitimate Input, Try again: ");
        cin.clear();
        cin.ignore(1000, '\n');
    }
    return user_input_integer;
}


int find_max(int arr[], int n)
{
    int max = arr[0];
    for(int i = 0; i < n; i++){if(arr[i] > max){max = arr[i];}}
    return max;
}
int find_min(int arr[], int n)
{
    int minimum = find_max(arr, n);
    for(int i = 0; i < n; i++){if(arr[i] < minimum){minimum = arr[i];}}
    return minimum;
}




int ask_number_of_elements()
{
    int num_of_dig = -32;
    num_of_dig = user_input_validation();
    while(!(num_of_dig <= 10  && num_of_dig > 1))
    {
        if(!(num_of_dig <= 10  && num_of_dig > 1))
        {
            printf("Invalid input retry! \n");
            printf("Number of elements/numbers = ");
            num_of_dig = user_input_validation();
        }
    }
    return num_of_dig;
}
int ask_element_value(int i)
{
    int number = user_input_validation();

    while(!(number <= 0xffff - 1 && number >= -0xffff + 1))
    {
        printf("You can not enter a value {not exceeding 65534 or lower than -65534}\n");
        printf("re-enter the value for element {%i}: ", i);
        number = user_input_validation();      
    }
    return number;
}



void second_largest_element()
{
    printf("Enter Number of elements: ");
    int n = ask_number_of_elements();
    int arr[n];

    for(int i = 0; i < n; i++)
    {
        printf("Elements (%i): ", i+1);
        arr[i] = ask_element_value(i+1);
    }

    int maximum = find_max(arr, n);
    printf("Maximum value: %i\n", maximum);

    int sec_max = find_min(arr, n);
    for(int i = 0; i < n; i++){if(arr[i] > sec_max && arr[i] != maximum){sec_max = arr[i];}}
    if(maximum == sec_max){printf("There is no second largest element!");return;}
    printf("Second Max Value: %i\n", sec_max);
}

int main()
{
    printf("Welcome to 'Find second largest number', here you enter:\n1) Number of elements\n2) The value of each element\n\n. The output is the second largest element in the array\n\n");
    printf("Rules: \n(1) You are allowed to enter up to {10} elements, but you have to enter more than {1} element\n(2) With values ranging from {-65534} to {65534}");
    printf("\n\n");
    second_largest_element();
    return 0;
}



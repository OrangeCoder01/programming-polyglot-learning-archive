#include <iostream>
using std::cin;

int user_input_validation()
{
    int user_input_integer = 0;
    while(!(cin >> user_input_integer))
    {
        printf("Not a legitimate number, input it again: \n");
        cin.clear();
        cin.ignore(1000, '\n');
    }
    return user_input_integer;
}


int find_pos_max(int arr[], int n)
{
    int pos_max = 0;
    for(int i = 0; i < n; i ++){if(arr[i] > pos_max){pos_max = arr[i];}}
    return pos_max;
}
int find_min(int arr[], int n)
{
    int min = find_pos_max(arr, n);
    for(int i = 0; i < n; i ++){if(arr[i] < min){min = arr[i];}}
    return min;
}
int find_max(int arr[], int n)
{
    int max = find_min(arr, n);
    for(int i = 0; i < n; i++){if(arr[i] > max){max = arr[i];}}
    return max;
}


int ask_number_of_elements()
{
    printf("Please, Enter the number of elements/numbers: ");
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

    while(!(number <= 0xffff && number >= -0xffff))
    {
        printf("You can not enter a value {not exceeding 65535 or lower than -65535}\n");
        printf("re-enter the value for element {%i}: ", i);
        number = user_input_validation();      
    }
    return number;
}

int count_distinct(int arr[], int size)
{
    int distinct = 0;

    for (int i = 0; i < size; i++)
    {
        bool found = false;

        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            distinct++;
        }
    }

    return distinct;
}

int ask_order(int arr[] ,int num_of_dig)
{
    int distinct_count = count_distinct(arr, num_of_dig);
    int order = 0;
    order = user_input_validation();
    while(order < 1 || order > distinct_count)
    {
        printf("Illegal input, enter the order again: ");
        order = user_input_validation();
    }
    return order;
}



int count_duplicate(int arr[], int size, int specific_number)
{
    int count = 0;
    for(int i = 0; i < size; i ++)
    {
        if(arr[i] == specific_number){count ++;}
    }
    return count;
}

void find_nth_largest_number()
{
    int duplicate_count = 0;
    int number = 0;
    int selected_number = 0;


    int num_of_dig = ask_number_of_elements();
    int arr_num[num_of_dig];
    int temp_arr[num_of_dig];


    printf("Insert the values of your elements/numbers individually:\n");
    for(int i = 0; i < num_of_dig; i ++)
    {
        printf("Enter value for element {%i}: ",(i+1));
        number = ask_element_value(i);
        arr_num[i] = number;
        temp_arr[i] = number;
    }



    printf("\nPlease input the order: ");
    int order = ask_order(arr_num,num_of_dig);

    int current_max = find_max(arr_num, num_of_dig);
    int min = find_min(arr_num, num_of_dig);



    int temp_order = order;
    if(order > 1)
    {
    while(temp_order != 1)
        {
            int rep = 0;
            for(int i = 0; i < num_of_dig; i++)
            {
                if(temp_arr[i] == current_max)
                {
                    selected_number = current_max;
                    temp_arr[i] = min - 1;
                    rep ++;
                }
            }
            int i = 0;
            while(rep > 1)
            {
                if(i == num_of_dig-1){break;}

                if(temp_arr[i] == current_max)
                {
                    temp_arr[i] = min - 1;
                    rep --;
                }
                i ++;
            }

            current_max = find_max(temp_arr, num_of_dig);
            temp_order --;
        }  
    }

    selected_number = find_max(temp_arr, num_of_dig);


   
    duplicate_count = count_duplicate(arr_num, num_of_dig, selected_number);
    if(duplicate_count > 1)
    {
        printf("\nThere are {%i} identical numbers for the order [(%i) largest number] in the array is:\n{%i}\n", duplicate_count, order, selected_number);
        return;
    }

    printf("The order [(%i)-largest-number] in the array is [", order);
    for(int i = 0; i < num_of_dig; i++)
    {
        printf("%i", arr_num[i]);
        if(!(i == (num_of_dig -1))){printf(", ");}
    }
    printf("] --> Place {%i}-largest-element: {%i}",order ,selected_number);
}


int main()
{
    printf("Welcome to 'Nth Largest element in array':\nIn this challenge, you are meant to enter the number of elemenets,\nand then the program asks you for the value of each element\nFinally the input the order ex: 1 for largest, 2 for second largest, etc...\nThe output is the number with respect to the order");
    printf("\n\n");
    printf("Rules: \n(1) You are allowed to enter up to {10} elements, but you have to enter more than {1} element\n(2) With values ranging from {-65535} to {65535}\n(3) Will notify if the n-order-largest element is a duplicate");
    printf("\n\n");
    printf("Note: Ranking includes duplicates, check out 'Dense Ranking'\n\n");

    find_nth_largest_number();
    return 0;
}

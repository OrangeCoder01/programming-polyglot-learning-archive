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

int ask_number_of_elements()
{
    int num_of_dig = -32;
    num_of_dig = user_input_validation();
    while(num_of_dig < 2 || num_of_dig > 10)
    {
        if(num_of_dig < 2 || num_of_dig > 10)
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

bool palindrome_array_compare(int arr[], int n)
{
    for(int i = 0; i < (n/2); i++){if(arr[i] != arr[n - i - 1]){return false;}}
    return true;
}

int main()
{
    printf("Welcome to 'Palindrome Array Checker' where you input:\nThe number elements of array.\nThen the elements' value.\n\nThe output is the constructed array and its reversed-placed elements.\n\n");
    printf("Rules:\n");
    printf("Rules: \n(1) You are allowed to enter up to {10} elements, but you have to enter more than {1} element\n(2) With values ranging from {-65534} to {65534}");
    printf("\n\n");
    
    int n = 0;
    printf("Enter the number of elements: ");
    n = ask_number_of_elements();
    int arr[n];

    for(int i = 0; i < n; i ++)
    {
        printf("Enter value for element {%i}: ", i+1);
        arr[i] = ask_element_value(i+1);
    }
    printf("\n\n");

    palindrome_array_compare(arr, n)?
    printf("This is a palindrome array ✅"):
    printf("This is Not a palindrome array ❌");
}
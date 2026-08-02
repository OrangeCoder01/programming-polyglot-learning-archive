#include <iostream>
using std::cin;

/*
Code expalantion:
    This is 'Bank Simulator', the user enters his/her balance and asked to perform certain transactions
    the user asked for in the menu. The program behind the scene stores transation history of the user.
*/



/*-------------------------------------------------------------------------------------------*/
unsigned static const int MAX_TRANSACTIONS = 100;
static double deposit_array[MAX_TRANSACTIONS]; // Defining array with static specifier while being in the global-scope is 
static double withdraw_array[MAX_TRANSACTIONS]; // essential for keeping it to be only processed
static char trans_array[MAX_TRANSACTIONS]; // by the current code file only, while other external code files can not access it.
static double balance = 0; // Same thing with variables.
static int number_of_transactions = 0;
static double largest_transaction = 0;
static char largest_transaction_type = 'n';
static int largest_transaction_index = 0;
/*-------------------------------------------------------------------------------------------*/








/*-------------------------------------------------------------------------------------------*/
// Data Type Converters:
int f_2_i(double input){return (int)(input);}
double i_2_f(int input){return (double)(input);}
/*-------------------------------------------------------------------------------------------*/








/*-------------------------------------------------------------------------------------------*/
// User input validation functions:
void user_input_number_validator(double &input)
{
    while(!(cin >> input))
    {
        cin.clear();
        cin.ignore(40, '\n');
        if(!(cin >> input)) printf("Invalid input %.2f, enter again: ", input);
    }
}
double user_range_validator(double input, int lower_lim, int upper_lim)
{
    user_input_number_validator(input);
    while(input > i_2_f(upper_lim) || input < i_2_f(lower_lim))
    {
        printf("your input %.2f is out of bound, enter again: ", input);
        user_input_number_validator(input);
    }
    return input;
}
/*-------------------------------------------------------------------------------------------*/










/*-------------------------------------------------------------------------------------------*/
// Functions:
void print_transaction(double dep_arr[], double w_d_arr[], char hist_trans[])
{
    int i = 0;
    int j = 0;
    int k = 0;
    while(hist_trans[k] != '\0')
    {
        if(hist_trans[k] == 'd') 
        {
            printf("Trans.[%i]. Deposit: $", k + 1);
            printf("%.2f \n", dep_arr[i]);
            i ++;
        }
        else
        {
            printf("Trans.[%i]. Withdraw: $", k + 1);
            printf("%.2f \n", w_d_arr[j]);
            j ++;
        }
        k ++;
    }
}

void depositing()
{
    static int dep_tracker = 0;
    double input = 0;

    printf("max number to deposit is around 1 million: \n");
    printf("Please, enter the amount you want to deposit: ");
    input = user_range_validator(input, 1, 0xfffff);
    balance += input;

    deposit_array[dep_tracker] = input;
    trans_array[number_of_transactions] = 'd';
    trans_array[number_of_transactions + 1] = '\0';
    
    if(input > largest_transaction)
    {
        largest_transaction = input;
        largest_transaction_index = number_of_transactions;
        largest_transaction_type = 'd';
    }
    
    number_of_transactions ++;
    dep_tracker ++;
    
}

void withdrawing()
{
    static int withdraw_tracker = 0;
    double input = 0;
    
    printf("Please, enter the amount you want to withdraw: ");
    input = user_range_validator(input, 1, f_2_i(balance));
    balance -= input;
    
    withdraw_array[withdraw_tracker] = input;
    trans_array[number_of_transactions] = 'w';
    trans_array[number_of_transactions + 1] = '\0';
    
    if(input > largest_transaction)
    {
        largest_transaction = input;
        largest_transaction_index = number_of_transactions;
        largest_transaction_type = 'w';
    }

    number_of_transactions ++;
    withdraw_tracker ++;
}

int find_number_transaction_per_type(char hist_trans[], char type)
{
    int n = 0;
    int i = 0;
    while(hist_trans[i] != '\0')
    {
        if(hist_trans[i] == type){n++;}
        i ++;
    }
    return n;
}

double summing_arr(double arr[], char type)
{
    double summed_elements = 0.0f;
    int n = find_number_transaction_per_type(trans_array, type);
    for(int i = 0; i < n; i++){summed_elements += arr[i];}
    return summed_elements;
}


/*-------------------------------------------------------------------------------------------*/







/*-------------------------------------------------------------------------------------------*/
void menu()
{
    char choice = 'N';
    int choice_i = 0;
    do
    {
        if(number_of_transactions > MAX_TRANSACTIONS - 1){printf("You have reached the maximum limit for transactions today, have a good day! exiting...");exit(-1);}
        printf("1.Deposit\n2.Withdraw\n3.Check Balance\n4.Transaction history\n5.Total deposited\n6.Total withdrawn\n7.Largest transaction\n8.Transaction count\n9.Exit\n\n");
        printf("Your choice: ");
        choice_i = f_2_i(user_range_validator(0.0f, 1, 9));
        switch(choice_i)
        {
            case 1: depositing(); break;
            case 2: withdrawing(); break;
            case 3: printf("Your current balance: {$%.2f}", balance); break;
            case 4: print_transaction(deposit_array, withdraw_array, trans_array); break;
            case 5: printf("Total deposited: {$%.2f}", summing_arr(deposit_array, 'd')); break;
            case 6: printf("Total withdwawn: {$%.2f}", summing_arr(withdraw_array, 'w')); break;
            case 7: 
            {
                if(largest_transaction == 0) {printf("Sorry, You need to do at least one transaction"); break;}
                printf("Largest Transaction: {$%.2f} at Trans.[%i], type: (", largest_transaction, largest_transaction_index + 1);
                largest_transaction_type == 'd'? printf("Deposit)\n"): printf("Withdraw)\n");
                break;
            }
            case 8: printf("There are {%i} transactions: ", number_of_transactions); break;
            case 9: break;
            default: break;
        }
        printf("\n\n\n");
    }while(choice_i != 9);
    printf("\nThank you for using the 'Bank Simulator': \n");
}
void declaration ()
{
    printf("Welcome to 'Bank Simulator':\nHere you enter your current balance.\nAnd the program performs transations and stores its history.\n\n");
}
/*-------------------------------------------------------------------------------------------*/










int main()
{
    trans_array[0] = '\0';
    
    declaration();
    printf("Please, enter your balance: ");
    user_input_number_validator(balance);
    menu();
}
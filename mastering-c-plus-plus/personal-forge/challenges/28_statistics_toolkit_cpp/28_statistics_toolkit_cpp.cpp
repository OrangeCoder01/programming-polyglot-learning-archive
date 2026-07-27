#include <iostream>
using std::cin;

// "Validation and inputing functions" section:
float user_input_validation(float num, int integer, char choice)
{   
    if(choice == '1')
    {
        while(!(cin >> num) || (-1048575.0 > num || num > 1048575.0))
        {
            if(!cin){printf("Illegitimate float Input, enter again: ");}
            else{printf("Your number: {%f} is out of range {-1048575 to 1048575}, enter again: ", num);}
            cin.clear();
            cin.ignore(1000, '\n');
        }
        return num;
    }
    else
    {
        while(!(cin >> integer) || (integer < 3))
        {
            if(!cin){printf("Illegitimate integer Input, enter again: ");}
            else{printf("The number must be more than zero, enter again: ");}
            cin.clear();
            cin.ignore(1000, '\n');
        }
        return (float)(integer);
    }
}

void input_size(unsigned int &size)
{size = (unsigned int)(user_input_validation(0, size, '2'));}


void input_array(float array[], unsigned const int size)
{
    for(int i = 0; i < size; i ++)
    {   
        printf("Enter value for element {%i}: ", (i + 1));
        array[i] = user_input_validation(array[i], 0, '1');
    }
}

void print_array(float array[], unsigned const int size)
{
    printf("[");
    for(unsigned int i = 0; i < size; i++)
    {  
         printf("%f", array[i]);
        if(i < (size - 1))
        {
            printf(", ");
        }
    }
    printf("]");
}



//Important math operations:
float float_pow(float element, int power)
{
    
    if(power == 0)
    {return 1;}
    else if(power > 0)
    {
        float value = element;
        for(int i = 1; i < power; i++)
        {value *= element;}
        return value;
    }
    else
    {
        float value = 1/element;
        for(int i = power; i < 0; i++)
        {value /= element;}
        return value;
    }
    
}
// This function is made for testing.

// float flooring(float element, int decimal_point)
// {
//     if(decimal_point == 0)
//     {return (int)(element);}
    
//     int value = (int)(element * float_pow(10.0, decimal_point));
//     float new_f_value = (float)(value) / float_pow(10.0, decimal_point);
//     return new_f_value;
// }

float float_sqrt(float under_root_num, int root)//Don't not ask me about the Time complexity O notation
{
    //Find the integer part
    int int_part = 0;
    for(int i = 0; float_pow((float)(i), root) <= under_root_num; i++)
    {
        int_part = i;
    }
    
    //Refine decimal digits one at a time
    float result = (float)(int_part);
    float decimal_step = 1.0f;
    
    int precision = 5; // how many decimal digits to refine
    for(int p = 0; p < precision; p++)
    {
        decimal_step /= 10.0f; // 0.1, then 0.01, then 0.001...
        
        for(int i = 1; i <= 9; i++)
        {
            float candidate = result + decimal_step * (float)(i);
            if(float_pow(candidate, root) <= under_root_num){result = candidate;}
            else{break;}
        }
    }
    return result;
}

// Techniques:
void bubble_sort_array(float arr[], unsigned const int n)
{
    for(int i = 0; i < n - 1; i ++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                float temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

//statistics displaying function
float find_extremes(float arr[], unsigned const int n, char choice)
{
    float max = arr[n-1];
    float min = arr[0];
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > max){max = arr[i];}
        if(arr[i] < min){min = arr[i];}
    }
    
    if(choice == '1'){return max;}
    else{return min;}
    return 5.3;//Just debugging
}

float mean(float arr[], unsigned const int n)
{
    float value = 0;
    for(int i = 0; i < n; i++){value += arr[i];}
    return (value/n);
}

float range(float maximium, float minimum)
{return maximium - minimum;}

float median(float arr[], unsigned const int n)
{
    bool is_even = n % 2 == 0; 
    if(is_even)
    {return (arr[n/2] + arr[n/2 -1])/2;}
    else
    {return arr[n/2];}
}

float mode(float arr[], unsigned const int n) 
{
    if (n == 0) return -1;

    unsigned int max_count = 1;
    unsigned int current_count = 1;
    float mode_value = arr[0];
    bool multiple_modes = false;

    for (unsigned int i = 1; i < n; i++) 
    {
        if (arr[i] == arr[i - 1]) 
        {current_count++;} 
        else 
        {
            // Check if the previous streak is the longest
            if (current_count > max_count) 
            {
                max_count = current_count;
                mode_value = arr[i - 1];
                multiple_modes = false;
            } 
            else if (current_count == max_count && max_count > 1) 
            {
                multiple_modes = true;
            }
            current_count = 1; // Reset for the next distinct number
        }
    }

    // Final check for the last element group in the array
    if (current_count > max_count) 
    {
        max_count = current_count;
        mode_value = arr[n - 1];
        multiple_modes = false;
    } 
    else if (current_count == max_count && max_count > 1) 
    {
        multiple_modes = true;
    }

    if (multiple_modes) 
    {
        printf("Cannot find a single mode; multiple numbers share the highest frequency.\n");
        return -1;
    }

    return mode_value;
}

float variance(float arr[], unsigned const int n, float mean)
{
    float var_val = 0;
    float squared_diff_arr[n];

    for(unsigned int i = 0; i < n; i ++)
    {squared_diff_arr[i] = float_pow(abs(arr[i] - mean), 2);}
    
    // Time to sum
    for(int i = 0; i < n; i++)
    {var_val += squared_diff_arr[i];}
    var_val /= n;
    return var_val;
}

float standard_deviation(float variance)
{return float_sqrt(variance, 2);}


//Annoncing the idea of the challenge:
void declaration()
{
    printf("\nWelcome to 'Statistic Tool-kit Program':\nHere, you choose to enter a set of numbers to an array,\nAnd the output is full statistic table containing:\n\n1)Minimum element:\n2)Maximum element:\n3)Mean:\n4)Mode:\n5)Median:\n6)Range:\n7)Standard deviation:\n8)Variance:");
    printf("\n\nRules:\n1)Elements can not exceed 1048575 or lower than -1048575.\n2)You must restart the program to initialize a new statisitc analysis.\n3)Number of elements must be more than 2. \n\n");
}

void stat_disp()
{
    declaration();
    printf("Please, enter number of elements in array: ");
    unsigned int size = 0;
    input_size(size);

    unsigned const int constant_size = size;

    printf("\n\n");
    printf("Fill the elements in array: \n");
    float array[constant_size];
    input_array(array, constant_size);

    float maximum = find_extremes(array, constant_size, '1');
    float minimum = find_extremes(array, constant_size, '2');
    float mean_variable = mean(array, constant_size);
    float var_val = variance(array, constant_size, mean_variable);


    printf("\n\nStatistic Displaying: \n");
    printf("Array: ");
    print_array(array, constant_size);
    printf("\n");
    printf("Sorted Array: ");
    bubble_sort_array(array, constant_size);
    print_array(array, constant_size);
    printf("\n");
    printf("Minimum: %f\n", minimum);
    printf("Maximum: %f\n", maximum);
    printf("Mean: %f\n", mean_variable);
    printf("Mode: %f\n", mode(array, constant_size));
    printf("Median: %f\n", median(array, constant_size));
    printf("Range: %f\n", range(maximum, minimum));
    printf("Variance: %f\n", var_val);
    printf("Standard deviation: %f\n", standard_deviation(var_val));
}

int main()
{
    stat_disp();

    return 0;
}

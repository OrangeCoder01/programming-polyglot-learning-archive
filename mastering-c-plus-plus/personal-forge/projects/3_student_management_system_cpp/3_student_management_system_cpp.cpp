#include <iostream>
using std::cin;

unsigned const int MAX_NAME_CAPACITY = 1000;
unsigned const int MAX_NUMBER_OF_STUDENTS = 100;

static char stud_names_matrix[MAX_NUMBER_OF_STUDENTS][MAX_NAME_CAPACITY] = {'\0'}; // Lets do some matrix, baby
static long long int stud_ids[MAX_NUMBER_OF_STUDENTS] = {-1};
static float stud_scores[MAX_NUMBER_OF_STUDENTS] = {-1.0f};
static int stud_track_indx[MAX_NUMBER_OF_STUDENTS] = {-1};

static int last_indx_tracker = 0; 
static int num_regis_studs = 0;



/*-------------------------------------------------------------------------------------------*/
// Data Type Converters:
int f_2_i(double input){return (int)(input);}
long long int f_2_lli(double input){return (long long int)(input);}
double i_2_f(int input){return (double)(input);}
/*-------------------------------------------------------------------------------------------*/



/*-------------------------------------------------------------------------------------------*/
// User input validation functions:
void user_input_number_validator(float &input)
{
    while(!(cin >> input))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        if(!(cin >> input)) printf("Invalid input %.2f, enter again: ", input);
    }
}
float user_range_validator(float input, int lower_lim, int upper_lim)
{
    user_input_number_validator(input);
    while(input > i_2_f(upper_lim) || input < i_2_f(lower_lim))
    {
        printf("your input %.2f is out of bound (%i ~ %i) , enter again: ", input, lower_lim, upper_lim);
        user_input_number_validator(input);
    }
    return input;
}
/*-------------------------------------------------------------------------------------------*/






/*-------------------------------------------------------------------------------------------*/
// Data storing functions:
void student_name_input_func()
{
    int col = 0;
    int target_row = num_regis_studs;
    cin.ignore(1000, '\n'); //Clearing the buffer
    
    printf("Enter the student's name: ");
    while(col < (MAX_NAME_CAPACITY - 1))
    {
        char ch = cin.get();
        if(ch == '\n') break;
        stud_names_matrix[target_row][col] = ch;
        col ++;
    }
    stud_names_matrix[target_row][col +1] = '\0';
}

void student_id_input_func()
{
    long long int id_input = 0;
    bool is_dup = false;
    printf("Please, enter the id (between 0 ~ 268435455 and not a duplicate) of the student: ");
    do
    {
        int i = 0;
        is_dup = false;
        id_input = f_2_lli(user_range_validator(0.0f, 0 , 0xfffffff));
        while(!is_dup && stud_ids[i] != -1)
        {
            if(stud_ids[i] == id_input) is_dup = true;
            i ++;
        }
        if(is_dup) printf("The inserted id: %lli is duplicated, enter a different id: ", id_input);
    }while(is_dup);
    stud_ids[num_regis_studs] = id_input;
}

void student_score_input_func()
{
    float score_input = 0.0f;
    printf("Please, enter the score (between 0 ~ 100): ");
    score_input = user_range_validator(0.0f, 0, 100);
    stud_scores[num_regis_studs] = score_input;
}





float find_max(float arr[])
{
    float max = 0;
    int i = 0;
    while(i < num_regis_studs)
    {
        if(arr[i] > max) max = arr[i];
        i ++;
    }
    return max;
}
float find_min(float arr[])
{
    float min = find_max(arr);
    int i = 0;
    while(i < num_regis_studs)
    {
        if(arr[i] < min) min = arr[i];
        i ++;
    }
    return min;
}

int count_number_of_characters_till_null_terminator(int target_row)
{
    int n = 0;
    while(stud_names_matrix[target_row][n] != '\0'){n ++;}
    return n;
}

void readjusting_data(int removed_data_indx) // Data Manipulation function after the student omission.
{
    int i = removed_data_indx;
    bool is_there_another_student = false;

    while(last_indx_tracker - 1 > i)
    {
        int next_name_size = 0;
        next_name_size = count_number_of_characters_till_null_terminator(i + 1);

        stud_ids[i] = stud_ids[i + 1];
        stud_scores[i] = stud_scores[i + 1];

        for(int j = 0; j <= next_name_size; j++){stud_names_matrix[i][j] = stud_names_matrix[i + 1][j];}
        i ++;
    }

    last_indx_tracker -- ;
    num_regis_studs -- ;

    stud_track_indx[last_indx_tracker] = -1;
    // if there is no student found:
    // redefining stud_idx[0] = -1

   if (num_regis_studs == 0) 
    {
        stud_ids[0] = -1;
        stud_names_matrix[0][0] = '\0';
    }
}





/*-------------------------------------------------------------------------------------------*/




/*-------------------------------------------------------------------------------------------*/
// Data printing functions:
void print_student_details(int target_name_order)
{
    printf("===================================================\n");
    printf("Student: (%i)\n\n", target_name_order + 1);
    int i = 0;
    printf("Name: ");
    while(stud_names_matrix[target_name_order][i] != '\0' && i < MAX_NAME_CAPACITY)
    {
        char ch = stud_names_matrix[target_name_order][i];
        printf("%c", ch);
        i++; 
    }
    printf("\n");
    printf("ID: %lld\n", stud_ids[target_name_order]);
    printf("Score: %.2f\n", stud_scores[target_name_order]);
    printf("===================================================\n");
}

/*-------------------------------------------------------------------------------------------*/






/*-------------------------------------------------------------------------------------------*/
// The main functions:
void add_student()
{
    stud_track_indx[last_indx_tracker] = num_regis_studs;
    student_name_input_func();
    student_id_input_func();
    student_score_input_func();
}
int search_student()
{
    if(stud_ids[0] == -1) {printf("There are no students registered, you must register at least to use this feature. \n"); return 0;}
    
    int input_id = 0;
    bool found = false;
    printf("Enter the ID. of the student you are looking for: ");
    int student_indx = 0;
    do
    {
        int i = 0;
        input_id = user_range_validator(0.0f, -1, 0xfffffff); 
        if(input_id < 0) break;
        while(i < num_regis_studs)
        {
            if(stud_ids[i] == input_id) {found = true; student_indx = i; break;}
            i ++;
        }
        if(!found) printf("The id: {%i} is not found, try again (enter -1 to exit): ", input_id);
    }while(!found);
    
    if(input_id > 0)
    {
        printf("Found the student!\n");
        print_student_details(student_indx);
        return student_indx;
    }
    return -2;
}
void find_largest_score_students()
{
    if(stud_ids[0] == -1) {printf("There are no students registered, you must register at least one to use this feature. \n"); return;}
    float max_score = 0.0f;
    max_score = find_max(stud_scores);

    int i = 0;
    printf("\nStudents with largest scores: \n");
    while(i < num_regis_studs)
    {
        if(stud_scores[i] == max_score) print_student_details(i);
        i ++;
    }
}
void find_smallest_score_students()
{
    if(stud_ids[0] == -1) {printf("There are no students registered, you must register at least one to use this feature. \n"); return;}
    float min_score = 0.0f;
    min_score = find_min(stud_scores);

    int i = 0;
    printf("\nStudents with smallest scores: \n");
    while(i < num_regis_studs)
    {
        if(stud_scores[i] == min_score) print_student_details(i);
        i ++;
    }
}
void calculate_average_student_score()
{
    if(stud_ids[0] == -1) {printf("There are no students registered, you must register at least one to use this feature. \n"); return;}
    double sum = 0;
    printf("Average Students' Score: ");
    for(int i = 0; i < num_regis_studs; i++){sum += stud_scores[i];}
    printf("%.2f \n\n", (sum / i_2_f(num_regis_studs)));
}

void display_passing_students()
{
    if(stud_ids[0] == -1) {printf("There are no students registered, you must register at least one to use this feature. \n"); return;}
    bool has_one_passsed = false;
    int i = 0;
    printf("The passing Students (who got a more than or equal 50): \n");
    while(i < num_regis_studs)
    {
        if(stud_scores[i] >= 50) 
        {
            print_student_details(i);
            has_one_passsed = true;
        }
        i ++;
    }
    if(!has_one_passsed) printf("Unfortunately, no student managed to pass!\n");
}

void remove_student()
{
    if(stud_ids[0] == -1) {printf("There are no students registered, you must register at least one to use this feature. \n"); return;}
    int removed_data_indx = 0;
    removed_data_indx = search_student();
    printf("This student is removed! \n\n");
    readjusting_data(removed_data_indx);

}


/*-------------------------------------------------------------------------------------------*/





/*-------------------------------------------------------------------------------------------*/
void declaration(){printf("Welcome to 'Student Management System':\nThe program simply manages the student details you have inserted, shows statistics and search each student by id:\n\nRules: You can register up to max. 100 students. \nAnd each student's name must have less than 1000 charcters (space included).\n\n");}
void menu(){printf("1. Add Student\n2. Display All Students\n3. Search Student\n4. Find Highest Grade\n5. Find Lowest Grade\n6. Calculate Class Average\n7. Display Passing Students\n8. Remove Student\n9. Exit\n\n");}
/*-------------------------------------------------------------------------------------------*/

void procedures(int choice_i)
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    switch(choice_i)
    {
        
        case 1: add_student(); num_regis_studs ++; break;
        case 2:   
        {
            if(stud_ids[0] == -1){printf("\nThere are no students registered, you must register at least one to use this feature. \n"); return;}
            for(int i = 0; i < num_regis_studs; i++){print_student_details(i);printf("\n");}
            break;
        }
        case 3: search_student();break;
        case 4: find_largest_score_students();break;
        case 5: find_smallest_score_students();break;
        case 6: calculate_average_student_score();break;
        case 7: display_passing_students();break;
        case 8: remove_student();break;
        case 9:     break;
        default:    break;
    }
    printf("\n\n");
    cin.ignore(1000, '\n');
}

void program()
{
    stud_track_indx[0] = 0;
    declaration();
    int choice_i = 0;
    bool can_add = false;

    do
    {
        if(num_regis_studs > MAX_NUMBER_OF_STUDENTS - 1) 
        {
            printf("You have reached the max number of student, you can not add more students.\n");
            can_add = true;
        }
        else{can_add = false;}
        
        printf("Choose from the menu: \n");
        menu();
        
        printf("Your choice: ");
        choice_i = f_2_i(user_range_validator((0.0f), (1 + (int)(can_add)), (9)));

        procedures(choice_i);

    }while(choice_i != 9);
    printf("Thank you for using the 'Student Management System' program. \n");
}

int main()
{
    program();
}
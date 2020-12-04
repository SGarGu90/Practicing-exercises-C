#include <iostream>
#include <string>
#include <iomanip> // use set() to generate empty spaces between text
#include <limits> // To request strict number in cin (not allowed letters) numeric_limits<streamsize>..

#include <math.h>
#include <sstream> // string to int 



using namespace std;


const int MAX_TOTAL_USER_ON_MEMORY = 50;
const int MENU_INDENT_WIDTH = 4;
const int MIN_AGE_ALLOWED = 0;
const int MAX_AGE_ALLOWED = 125;
const int DNI_NUMBER_LENGTH = 8;

string all_user_name[MAX_TOTAL_USER_ON_MEMORY];
int all_user_age[MAX_TOTAL_USER_ON_MEMORY];
char all_user_gender[MAX_TOTAL_USER_ON_MEMORY];
char all_user_marital_status[MAX_TOTAL_USER_ON_MEMORY];
float all_user_weight[MAX_TOTAL_USER_ON_MEMORY];
float all_user_height[MAX_TOTAL_USER_ON_MEMORY];


string generate_random_number_by_length(int random_number_length)
{
    int count_length = random_number_length;
    int pseudo_random_number;
    string random_number = "";
    int position_to_get_from_generated_number;
    // Don't use srand inside the loop, use it only once, e.g. at the start of main(). And srand() is exactly how you reset this.
    srand(time(NULL));

    do {
        // The rand() function does not generate a truly random number; it actually returns the next pseudo-random value 
        // in a sequence of values ranging from 0 to RAND_MAX. You can change the starting point in that sequence using srand().
        pseudo_random_number = rand();
        int position_to_get_from_generated_number = 2;
        // Generates dynamical position to get from pseudo generated rand number
        // It means the position from each single random number to get from each pseudo random generated number depending if even or odd number or loop
        if (pseudo_random_number % 2 || count_length % 2) position_to_get_from_generated_number += 2; // even pseudo_random_number, position to get 2 OR  even loop, plus 2 to the position
        else position_to_get_from_generated_number += 3; // odd pseudo_random_number, position to get 3 || odd loop, plus 3 to the position

        random_number += to_string(pseudo_random_number)[position_to_get_from_generated_number];
        count_length -= 1;
    } while (count_length > 0);

    return random_number;
}

string custom_rand_number_from_0_to(int random_value_range_to, bool is_included = true)
{
    string random_number = "";
    int count_length = to_string(random_value_range_to).size();
    int pseudo_random_number;
    string pseudo_random_number_str;
    char random_number_as_char;
    string random_number_to_check_as_str;
    int random_number_to_check_as_int;
    // Don't use srand inside the loop, use it only once, e.g. at the start of main(). And srand() is exactly how you reset this.
    srand(time(NULL));

    do {
        // The rand() function does not generate a truly random number; it actually returns the next pseudo-random value 
        // in a sequence of values ranging from 0 to RAND_MAX. You can change the starting point in that sequence using srand().
        pseudo_random_number = rand();
        pseudo_random_number_str = to_string(pseudo_random_number);
        int position_to_get_from_generated_number = 2;
        // Generates dynamical position to get from pseudo generated rand number
        // It means the position from each single random number to get from each pseudo random generated number depending if even or odd number or loop
        if (pseudo_random_number % 2 || count_length % 2) position_to_get_from_generated_number += 2; // even pseudo_random_number, position to get 2 OR  even loop, plus 2 to the position
        else position_to_get_from_generated_number += 3; // odd pseudo_random_number, position to get 3 || odd loop, plus 3 to the position

        random_number_as_char = pseudo_random_number_str[position_to_get_from_generated_number];
        random_number_to_check_as_str = random_number + random_number_as_char;
        random_number_to_check_as_int = stoi(random_number_to_check_as_str);


        if (is_included) {
            if (random_number_to_check_as_int >= 0 && random_number_to_check_as_int <= random_value_range_to)
            {
                random_number += random_number_as_char;
                count_length -= 1;
            }
        }
        else {
            if (random_number_to_check_as_int > 0 && random_number_to_check_as_int < random_value_range_to)
            {
                random_number += random_number_as_char;
                count_length -= 1;
            }
        }
    } while (count_length > 0);


    return random_number;
}

char get_random_letter()
{
    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int letters_length = letters.size();
    string random_letter_pos = custom_rand_number_from_0_to(letters_length);
    int from_str_to_num_pos = stoi(random_letter_pos);
    return letters[from_str_to_num_pos];
}

string calc_dni(int user_id)
{
    char dni_letter = get_random_letter();
    string dni_number = generate_random_number_by_length(DNI_NUMBER_LENGTH);

    cout << "\n>>>>> Generated DNI: '" << dni_number << " - " << dni_letter << "' for user '" << all_user_name[user_id] << "' <<<<<" << endl;
}


char request_user_gender()
{
    char gender;
    bool is_correct_gender = false;
    cout << "Gender:\n " << setw(MENU_INDENT_WIDTH) << " - (m) male\n " << setw(MENU_INDENT_WIDTH) << " - (f) female" << endl;
    do {
        cin >> gender; 
        is_correct_gender = (gender == 'm' || gender == 'f');
        if (!is_correct_gender) cout << "Gender '" << gender << "'" << " is not valid.\n " << setw(MENU_INDENT_WIDTH) << " - (m) male\n " << setw(MENU_INDENT_WIDTH) << " - (f) female" << endl;
    } while (!is_correct_gender);

    return gender;
}

int validate_gender(int user_id)
{
    string user_name = all_user_name[user_id];
    char user_gender = all_user_gender[user_id];

    cout << "\t>>>>> To validate '" << user_name << "' type a gender: <<<<<" << endl;
    char to_match_gender = request_user_gender();

    cout << "\t>>>>> Current user gender is: '" << user_gender << "' <<<<<" << endl;
    cout << "\t>>>>> Gender is ";
    if (to_match_gender == all_user_gender[user_id]) cout << "CORRECT <<<<<";
    else {
        cout << "NOT correct, set new gender for user '" << user_name << "': <<<<<" << endl;
        all_user_gender[user_id] = request_user_gender();
        cout << "\t>>>>> New gender saved sucessfully. <<<<<" << endl;
        cout << "\t>>>>> Old gender: '" << user_gender << "' <<<<<" << endl;
        cout << "\t>>>>> New gender: '" << all_user_gender[user_id] << "' <<<<<" << endl;
    }
}

bool check_if_adult(int age)
{
    if (age > 18) cout << "\t>>>>> Is adult <<<<<";
    else cout << "\t>>>>> Is young <<<<<";
}

float calc_bmi(float height, float weight)
{
    float bmi = (weight / ( int(height) ^ 2 )) / 100;
    cout << "\n\t >>>>> (BMI): ";
    if (bmi < 20) cout << "Debajo de su peso: ";
    else if (bmi >= 21 && bmi <= 25) cout << "Peso ideal: ";
    else if (bmi > 25) cout << "Sobrepeso: ";
    else cout << "It has not been possible to calculate BMI. Check 'weight' nor 'height' of user";
    cout << bmi << " (kg/m)" << endl;
}

void print_user_row(int longest_name_length, int user_pos)
{
    int MINIMUM_RIGHT_SPACING = 9; // Used name in list less than menu header "name     |", persist minimum empty spaces for right prompt style in name list
    longest_name_length = (longest_name_length > MINIMUM_RIGHT_SPACING) ? longest_name_length : MINIMUM_RIGHT_SPACING;
    int right_empty_spaces_after_user_name = (longest_name_length - all_user_name[user_pos].size());
    if (right_empty_spaces_after_user_name != 0 ) right_empty_spaces_after_user_name += 1;
    cout << "\t - (" << user_pos << ") " << all_user_name[user_pos] << setw(right_empty_spaces_after_user_name) << " ";
    cout << "|  " << all_user_age[user_pos] <<  "  |  "
            << all_user_gender[user_pos] << "  |  "
            << all_user_marital_status[user_pos] << "  |  "
            << all_user_weight[user_pos] << " (kg)  |  "
            << all_user_height[user_pos] << " (cm)" << endl;
}

int get_longest_string_in_array(string *array_of_strings)
{
    int count;
    int total_elements_in_array = sizeof(array_of_strings)/sizeof(array_of_strings[0]);
    int longest_string_value = array_of_strings[0].size();
    for (int i = 1; i < total_elements_in_array; i++) {
        if (array_of_strings[i].size() > longest_string_value) longest_string_value = array_of_strings[i].size();
    }
    return longest_string_value;
}

void print_users()
{
    int total_users = MAX_TOTAL_USER_ON_MEMORY;
    cout << endl;
    cout << "\t - (id) name     | age | gender | marital status | weight (kg) | height (cm)" << endl;
    cout << "\t------------------------------------------------------------------------" << endl;
    int longest_name_length = get_longest_string_in_array(all_user_name);
    for (int user_pos = 0; user_pos < total_users; user_pos++) {
        if (all_user_name[user_pos] == "") break;
        print_user_row(longest_name_length, user_pos);
    }
}

string get_operation_title_by_name(string operation_name)
{
    if (operation_name == "bmi") return "Body Mass Index";
    else if (operation_name == "isadult") return "Is adult?";
    else if (operation_name == "isgender") return "Validate gender";
    else if (operation_name == "newdni") return "New DNI number";
}

int cin_number_int() 
{
    int input;
    while (!(cin >> input)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entered value is not a number, please introduce number" << endl;
    }
    return input;
}

int execute(string operation_name)
{
    string operation_title = get_operation_title_by_name(operation_name);
    cout << "\n\t>>>>> Using '" << operation_title << "' operation: <<<<< \n" << endl;;
    print_users();
    cout << "_______________________________________________" << endl;
    
    int selected_user_id;
    bool is_exist_user;
    
    do {
        cout << "Select user of list by (id): ";
        selected_user_id = cin_number_int();
        string user_name = all_user_name[selected_user_id];
        is_exist_user = (user_name.size() > 0);
        if(!is_exist_user) cout << "User id '" << selected_user_id << "' does not exist, please insert valid user (id)" << endl;
    } while (!is_exist_user);
    

    if (operation_name == "bmi") cout << calc_bmi(all_user_height[selected_user_id], all_user_weight[selected_user_id]);
    else if (operation_name == "isadult") check_if_adult(all_user_age[selected_user_id]);
    else if (operation_name == "isgender") validate_gender(selected_user_id);
    else if (operation_name == "newdni") calc_dni(selected_user_id);
}

string get_operation_name_by_id(int operation_id)
{
    return (operation_id == 1) ? "bmi" : 
            (operation_id == 2) ? "isadult" : 
            (operation_id == 3) ? "isgender" : 
            (operation_id == 4) ? "newdni" : "undefined";
}

void load_menu()
{
    int TOTAL_OPERATIONS = 4;
    string operation_name;

    cout << "\nSelect operation: " << endl;
    for (int operation_id = 1; operation_id <= TOTAL_OPERATIONS; operation_id++) {
        operation_name = get_operation_name_by_id(operation_id);
        cout << setw(MENU_INDENT_WIDTH) << " "<< operation_id << ": " << get_operation_title_by_name(operation_name) << endl;
    }
    cout << setw(MENU_INDENT_WIDTH) << " " << "0: EXIT" << endl;
}

float cin_number_float() 
{
    float input;
    while (!(cin >> input)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entered value is not a number, please introduce number" << endl;
    }
    return input;
}

float request_user_height()
{
    float height;
    bool is_correct_height = false;
    cout << "Height (10 - 250) cm: ";
    do {
        height = cin_number_float();
        is_correct_height = (height > 9 && height <= 250);
        if (!is_correct_height) cout << "Height '" << height << "'" << " is not valid range.\nEnter valid range(10 - 250) cm" << endl;
    } while (!is_correct_height);
    
    return height;  
}

float request_user_weight()
{
    float weight;
    bool is_correct_weight = false;
    cout << "Weight (0.1 - 1000) kg: ";
    do {
        weight = cin_number_float();
        is_correct_weight = (weight > 0 && weight <= 1000);
        if (!is_correct_weight) cout << "Weight '" << weight << "'" << " is not valid range.\nEnter valid range(0.1 - 1000) kg" << endl;
    } while (!is_correct_weight);
    
    return weight;  
}

char request_user_marital_status()
{
    char marital_status;
    bool is_correct_marital_status = false;
    cout << "Marital status:\n " << setw(MENU_INDENT_WIDTH) << " - (s) single\n " << setw(MENU_INDENT_WIDTH) << " - (m) married\n " << setw(MENU_INDENT_WIDTH) << " - (d) divorced\n " << setw(MENU_INDENT_WIDTH) << " - (w) widowed" << endl;
    do {
        cin >> marital_status;
        is_correct_marital_status = (marital_status == 's' || marital_status == 'm' || marital_status == 'd' || marital_status == 'w');
        if (!is_correct_marital_status) cout << "Marital status '" << marital_status << "'" << " is not valid.\n " << setw(MENU_INDENT_WIDTH) << " - (s) single\n " << setw(MENU_INDENT_WIDTH) << " - (m) married\n " << setw(MENU_INDENT_WIDTH) << " - (d) divorced\n " << setw(MENU_INDENT_WIDTH) << " - (w) widowed" << endl;
    } while (!is_correct_marital_status);
    
    return marital_status;
}

int request_user_age()
{
    int age;
    bool is_correct_age = false;
    cout << "Age (1 - 125): ";
    do {
        age = cin_number_int();
        is_correct_age = (age >= 1 && age <= 125);
        if (!is_correct_age) cout << "Age '" << age << "'" << " is not valid range.\nEnter valid range(1 - 125)" << endl;
    } while (!is_correct_age);
    
    return age;
}

string request_user_name()
{
    string user_name = "-";
    cout << "Name: ";
    cin >> user_name;

    return user_name;
}

void save_users_data()
{
    int users_to_insert;
    cout << endl;
    cout << "Number users to insert: ";
    users_to_insert = cin_number_int();
    cout << endl;

    for (int user_position = 0; user_position < users_to_insert; user_position++) {
        cout << "Insert data user nº " << user_position + 1 << endl;
        all_user_name[user_position] = request_user_name();
        all_user_age[user_position] = request_user_age();
        all_user_gender[user_position] = request_user_gender();
        all_user_marital_status[user_position] = request_user_marital_status();
        all_user_weight[user_position] = request_user_weight();
        all_user_height[user_position] = request_user_height();
        cout << "------------------------------" << endl;
        cout << endl;
    }

    cout << "Users saved sucessfully" << endl;
}

int main()
{
    int selected_option_id;
    bool is_valid_operation_option;
    string operation_name;

    save_users_data();

    do {
        load_menu();
        selected_option_id = cin_number_int();
        operation_name = get_operation_name_by_id(selected_option_id);
        is_valid_operation_option = operation_name != "undefined";

        if (is_valid_operation_option) execute(operation_name);

        else cout << "Program exited correctly." << endl;
        
    } while (is_valid_operation_option);

    return 0;
}
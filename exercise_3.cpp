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



string generate_random_number_by_length(int random_number_length, int MAX_RANDOM_NUMBER_VALUE = 0)
{
    // The rand() function does not generate a truly random number; it actually returns the next pseudo-random value 
    // in a sequence of values ranging from 0 to RAND_MAX. You can change the starting point in that sequence using srand().
    // Don't use srand inside the loop, use it only once, e.g. at the start of main(). And srand() is exactly how you reset this.
    int count_length = random_number_length;
    int pseudo_random_number;
    string random_number = "";
    int position_to_get_from_generated_number;
    srand(time(NULL));

    string pseudo_random_number_as_str;
    do {
        pseudo_random_number = rand();
        pseudo_random_number_as_str = to_string(pseudo_random_number);
        // if (pseudo_random_number < 0) pseudo_random_number *= -1;
        int position_to_get_from_generated_number = 0;
        // Generates dynamical position to get from pseudo generated rand number
        // It means the position from each single random number to get from each pseudo random generated number depending if even or odd number or loop
        if (pseudo_random_number % 2 || count_length % 2) position_to_get_from_generated_number += 2; // even pseudo_random_number, position to get 2 OR  even loop, plus 2 to the position
        else position_to_get_from_generated_number += 3; // odd pseudo_random_number, position to get 3 || odd loop, plus 3 to the position

        //cout << "position_to_get_from_generated_number: " << position_to_get_from_generated_number << endl;

        //cout << "pseudo_random_number_as_str: " << pseudo_random_number_as_str << endl;
        char random_number_to_add_as_char = pseudo_random_number_as_str[position_to_get_from_generated_number];

        
        if (MAX_RANDOM_NUMBER_VALUE == 0) { // Generate number by length with no limit
            
                random_number += random_number_to_add_as_char;
                count_length -= 1;
        }
        else {
            cout << "Current random number: " << random_number << endl;
            string limit_number_as_str = to_string(MAX_RANDOM_NUMBER_VALUE);
            cout << "Required number length: " << random_number_length << endl;
            cout << "To MAX: " << MAX_RANDOM_NUMBER_VALUE << endl;
            cout << "random_number_to_add_as_char: " << random_number_to_add_as_char << endl;
            cout << "\n";

            if (random_number.size() < limit_number_as_str.size() - 1)
            {
                if (!(count_length == random_number_length && random_number_to_add_as_char == '0')) { // Avoid to areturn a number shorter than required length like "04" => 4 or "065" => 65
                    random_number += random_number_to_add_as_char;
                }
            }
            else {
                string random_number_to_check = random_number + random_number_to_add_as_char;
                int random_number_to_check_as_int = stoi(random_number_to_check);
                if (random_number_to_check_as_int <= MAX_RANDOM_NUMBER_VALUE)
                {
                    random_number += random_number_to_add_as_char;
                    count_length -= 1;
                }
                else count_length -= 1;
                
            }



            
            
            

            // string pseudo_pseudo_random_number_as_str = to_string(pseudo_random_number);
            // string pseudo_random_number_last_char_as_str = to_string(pseudo_pseudo_random_number_as_str[position_to_get_from_generated_number]);
            // int pseudo_random_number_last_char_as_int = stoi(pseudo_random_number_last_char_as_str);
            // cout << "Last character of generated number" << pseudo_random_number_last_char_as_str << endl;





            // int limit_number_length = limit_number_as_str.size();
            // int limit_number_last_char_pos = limit_number_length - 1;
            // int limit_number_to_check_char_pos = limit_number_last_char_pos - random_number.size();
            // string limit_number_to_check_as_str = std::string(1, limit_number_as_str[limit_number_to_check_char_pos]);

            // cout << "Limit number as str: " << limit_number_as_str << endl;
            // cout << "Limit number length: " << limit_number_length << endl;
            // cout << "Limit number last character pos: " << limit_number_last_char_pos << endl;
            // cout << "Limit number to check pos: " << limit_number_to_check_char_pos << endl;
            // cout << "Limit number to check number: " << limit_number_to_check_as_str << endl;


            // int random_number_to_add = stoi(std::string(1, random_number_to_add_as_char));
            // int limit_number_to_check = stoi(limit_number_to_check_as_str);
            
            // if (random_number_to_add <= limit_number_to_check) // Confirms that random number to add respect limit
            // {
            //     random_number = random_number_to_add_as_char + random_number;
            //     count_length -= 1;
            // }






            // string new_number_to_add_as_str = std::string(1, limit_number_as_str[limit_number_to_check_char_pos]);
            // int new_number_to_add_as_int = stoi(new_number_to_add_as_str);

            // cout << "Limit number: " << limit_number_as_str << endl;


            // cout << "Limit number to add: " << new_number_to_add_as_str << endl;
            
            
            // if (random_number_char_as_int <= limit_number_to_check) // Confirms that random number to add respect limit
            // {
            //     random_number = to_string(pseudo_random_number)[position_to_get_from_generated_number] + random_number;
            //     count_length -= 1;
            // }

        }
        
        // cout << "generated number " << pseudo_random_number << endl;
        // cout << "Position to get " << position_to_get_from_generated_number << endl;
        // cout << "Generated number " << random_number << endl;
    } while (count_length > 0);


    return random_number;
}

char get_random_letter()
{
    char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string random_number = generate_random_number_by_length(1);
    
    char x = letters[rand() % 26];
}

string calc_dni(int user_id)
{
    char dni_letter = get_random_letter();
    string dni_number = generate_random_number_by_length(DNI_NUMBER_LENGTH);
    cout << "Generated DNI: " << dni_number << dni_letter;
}


char request_user_gender()
{
    char gender;
    bool is_correct_gender = false;
    cout << "Gender:\n " << setw(MENU_INDENT_WIDTH) << " - (m) male\n " << setw(MENU_INDENT_WIDTH) << " - (f) female\n";
    do {
        cin >> gender; 
        is_correct_gender = (gender == 'm' || gender == 'f');
        if (!is_correct_gender) cout << "Gender '" << gender << "'" << " is not valid.\n " << setw(MENU_INDENT_WIDTH) << " - (m) male\n " << setw(MENU_INDENT_WIDTH) << " - (f) female\n";
    } while (!is_correct_gender);

    return gender;
}

int validate_gender(int user_id)
{
    string user_name = all_user_name[user_id];
    char user_gender = all_user_gender[user_id];

    cout << "To validate '" << user_name << "' type a gender: \n";
    char to_match_gender = request_user_gender();

    cout << "Current user gender is: " << user_gender << "\n";
    cout << "Checked gender is ";
    if (to_match_gender == all_user_gender[user_id]) cout << "CORRECT";
    else {
        cout << "NOT correct, set new gender for user '" << user_name << "': \n";
        all_user_gender[user_id] = request_user_gender();
        cout << "New gender saved sucessfully.\n";
        cout << "Old gender: " << user_gender << "\n";
        cout << "New gender: " << all_user_gender[user_id] << "\n";
    }
}

bool check_if_adult(int age)
{
    if (age > 18) cout << "Is adult";
    else cout << "Is young";
}

float calc_bmi(float height, float weight)
{
    float bmi = (weight / ( int(height) ^ 2 )) / 100;
    cout << "(BMI): ";
    if (bmi < 20) cout << "Debajo de su peso: ";
    else if (bmi >= 21 && bmi <= 25) cout << "Peso ideal: ";
    else if (bmi > 25) cout << "Sobrepeso: ";
    else cout << "It has not been possible to calculate BMI. Check 'weight' nor 'height' of user";
    cout << bmi << " (kg/m)\n";
}

void print_user_row(int longest_name_length, int user_pos)
{
    int MINIMUM_RIGHT_SPACING = 9; // Used name in list less than menu header "name     |", persist minimum empty spaces for right prompt style in name list
    longest_name_length = (longest_name_length > MINIMUM_RIGHT_SPACING) ? longest_name_length : MINIMUM_RIGHT_SPACING;
    int right_empty_spaces_after_user_name = (longest_name_length - all_user_name[user_pos].size());
    if (right_empty_spaces_after_user_name != 0 ) right_empty_spaces_after_user_name += 1;
    cout << " - (" << user_pos << ") " << all_user_name[user_pos] << setw(right_empty_spaces_after_user_name) << " ";
    cout << "|  " << all_user_age[user_pos] <<  "  |  "
            << all_user_gender[user_pos] << "  |  "
            << all_user_marital_status[user_pos] << "  |  "
            << all_user_weight[user_pos] << " (kg)  |  "
            << all_user_height[user_pos] << " (cm)\n";
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
    cout << "\n";
    cout << " - (id) name     | age | gender | marital status | weight (kg) | height (cm)\n";
    cout << "------------------------------------------------------------------------\n";
    int longest_name_length = get_longest_string_in_array(all_user_name);
    for (int user_pos = 0; user_pos < total_users; user_pos++) {
        if (all_user_name[user_pos] == "") break;
        print_user_row(longest_name_length, user_pos);
    }
    cout << "\n";
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
        cout << "Entered value is not a number, please introduce number\n";
    }
    return input;
}

int execute(string operation_name)
{
    string operation_title = get_operation_title_by_name(operation_name);
    cout << "\n\t>>>>> Using '" << operation_title << "' operation: <<<<< \n\n";
    print_users();
    cout << "Select user of list by (id): ";
    int selected_user_id = cin_number_int();

    if (operation_name == "bmi") cout << calc_bmi(all_user_height[selected_user_id], all_user_weight[selected_user_id]);
    else if (operation_name == "isadult") check_if_adult(all_user_age[selected_user_id]);
    else if (operation_name == "isgender") validate_gender(selected_user_id);
    else if (operation_name == "newdni") calc_dni(selected_user_id);
    cout << "_______________________________________________\n";
    print_users();
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

    cout << "\nSelect operation: \n";
    for (int operation_id = 1; operation_id <= TOTAL_OPERATIONS; operation_id++) {
        operation_name = get_operation_name_by_id(operation_id);
        cout << setw(MENU_INDENT_WIDTH) << " "<< operation_id << ": " << get_operation_title_by_name(operation_name) << "\n";
    }
    cout << setw(MENU_INDENT_WIDTH) << " " << "0: EXIT\n";
}

float cin_number_float() 
{
    float input;
    while (!(cin >> input)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entered value is not a number, please introduce number\n";
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
        if (!is_correct_height) cout << "Height '" << height << "'" << " is not valid range.\nEnter valid range(10 - 250) cm\n";
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
        if (!is_correct_weight) cout << "Weight '" << weight << "'" << " is not valid range.\nEnter valid range(0.1 - 1000) kg\n";
    } while (!is_correct_weight);
    
    return weight;  
}

char request_user_marital_status()
{
    char marital_status;
    bool is_correct_marital_status = false;
    cout << "Marital status:\n " << setw(MENU_INDENT_WIDTH) << " - (s) single\n " << setw(MENU_INDENT_WIDTH) << " - (m) married\n " << setw(MENU_INDENT_WIDTH) << " - (d) divorced\n " << setw(MENU_INDENT_WIDTH) << " - (w) widowed\n";
    do {
        cin >> marital_status;
        is_correct_marital_status = (marital_status == 's' || marital_status == 'm' || marital_status == 'd' || marital_status == 'w');
        if (!is_correct_marital_status) cout << "Marital status '" << marital_status << "'" << " is not valid.\n " << setw(MENU_INDENT_WIDTH) << " - (s) single\n " << setw(MENU_INDENT_WIDTH) << " - (m) married\n " << setw(MENU_INDENT_WIDTH) << " - (d) divorced\n " << setw(MENU_INDENT_WIDTH) << " - (w) widowed\n";
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
        if (!is_correct_age) cout << "Age '" << age << "'" << " is not valid range.\nEnter valid range(1 - 125)\n";
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
    cout << "\n";
    cout << "Number users to insert: ";
    users_to_insert = cin_number_int();
    cout << "\n";

    for (int user_position = 0; user_position < users_to_insert; user_position++) {
        cout << "Insert data user nº " << user_position + 1 << "\n";
        all_user_name[user_position] = request_user_name();
        all_user_age[user_position] = request_user_age();
        all_user_gender[user_position] = request_user_gender();
        all_user_marital_status[user_position] = request_user_marital_status();
        all_user_weight[user_position] = request_user_weight();
        all_user_height[user_position] = request_user_height();
        cout << "------------------------------\n";
        cout << "\n";
    }

    cout << "Users saved sucessfully\n";
}

int main()
{
    // int selected_option_id;
    // bool is_valid_operation_option;
    // string operation_name;

    // save_users_data();

    // do {
    //     load_menu();
    //     selected_option_id = cin_number_int();
    //     operation_name = get_operation_name_by_id(selected_option_id);
    //     is_valid_operation_option = operation_name != "undefined";

    //     if (is_valid_operation_option) execute(operation_name);

    //     else cout << "Program exited correctly.\n";
        
    // } while (is_valid_operation_option);
    string random_number = generate_random_number_by_length(2, 26);

    cout << random_number << endl;

    return 0;
}
#include <iostream>
#include <string>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

#include "helpers.cpp"

const int MAX_TOTAL_USER_ON_MEMORY = 50;
int MENU_INDENT_WIDTH = 4;
int MIN_AGE_ALLOWED = 0;
int MAX_AGE_ALLOWED = 125;

string all_user_name[MAX_TOTAL_USER_ON_MEMORY];
int all_user_age[MAX_TOTAL_USER_ON_MEMORY];
char all_user_gender[MAX_TOTAL_USER_ON_MEMORY];
char all_user_marital_status[MAX_TOTAL_USER_ON_MEMORY];
float all_user_weight[MAX_TOTAL_USER_ON_MEMORY];
float all_user_height[MAX_TOTAL_USER_ON_MEMORY];

string calc_dni(int user_id)
{
    cout << "calc_dni";
}


char request_user_gender()
{
    // char gender;
    // bool is_correct_gender = false;
    // cout << "Gender:\n " << setw(MENU_INDENT_WIDTH) << " - (m) male\n " << setw(MENU_INDENT_WIDTH) << " - (f) female\n";
    // do {
    //     cin >> gender;
    //     is_correct_gender = (gender == 'm' || gender == 'f');
    //     if (!is_correct_gender) cout << "Gender '" << gender << "'" << " is not valid.\n " << setw(MENU_INDENT_WIDTH) << " - (m) male\n " << setw(MENU_INDENT_WIDTH) << " - (f) female\n";
    // } while (!is_correct_gender);

    // return gender;
}

bool validate_gender(int user_id)
{
    cout << "Type gender to check user (" << user_id << ") " << all_user_name[user_id] << "\n";
    char to_match_gender = request_user_gender();

    cout << "Gender is ";
    if (to_match_gender == all_user_gender[user_id]) cout << "correct";
    else cout << "NOT correct, set new gender '";
    cout << "for user '" << all_user_name[user_id] << "'\n";
    
    all_user_gender[user_id] = request_user_gender();
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

int get_longest_name_length()
{
    int count;
    int longest_name = all_user_name[0].size();
    for (int i = 1; i < 50; i++) {
        if (all_user_name[i].size() > longest_name) longest_name = all_user_name[i].size();
    }
    return longest_name;
}

void list_users()
{
    int MINIMUM_RIGHT_SPACING = 9; // Used name in list less than menu header "name     |", persist minimum empty spaces for right prompt style in name list
    string user_name;
    int total_users = MAX_TOTAL_USER_ON_MEMORY;
    int longest_name_length = get_longest_name_length();
    cout << " - (id) name     | age | gender | marital status | weight (kg) | height (cm)\n";
    cout << "------------------------------------------------------------------------\n";
    int right_empty_spaces;
    for (int user_pos = 0; user_pos < total_users; user_pos++) {
        user_name = all_user_name[user_pos];
        if (all_user_name[user_pos] == "") break;
        longest_name_length = (longest_name_length > MINIMUM_RIGHT_SPACING) ? longest_name_length : MINIMUM_RIGHT_SPACING;
        right_empty_spaces = (longest_name_length - user_name.size());

        if (right_empty_spaces != 0 ) right_empty_spaces += 1;
        cout << " - (" << user_pos << ") " << all_user_name[user_pos] << setw(right_empty_spaces) << " ";
        cout << "|  " << all_user_age[user_pos] <<  "  |  "
                << all_user_gender[user_pos] << "  |  "
                << all_user_marital_status[user_pos] << "  |  "
                << all_user_weight[user_pos] << " (kg)  |  "
                << all_user_height[user_pos] << " (cm)\n";
    }
}

int select_user()
{
    int selected_user_id;
    list_users();
    cout << "\nSelect user id: \n";
    selected_user_id = cin_number_int();
    return selected_user_id;
}

string get_operation_title_by_name(string operation_name)
{
    if (operation_name == "bmi") return "Body Mass Index";
    else if (operation_name == "isadult") return "Is adult?";
    else if (operation_name == "isgender") return "Is gender ..";
    else if (operation_name == "newdni") return "New DNI number";
}

int execute(string operation_name)
{
    cout << "\n\t>>>>> '" << get_operation_title_by_name(operation_name) << "' operation <<<<< \n\n";
    int selected_user_id = select_user();

    string user_name = all_user_name[selected_user_id];
    int user_age = all_user_age[selected_user_id];
    char user_gender = all_user_gender[selected_user_id];
    float user_height = all_user_height[selected_user_id];
    float user_weight = all_user_weight[selected_user_id];

    cout << "\n'" << get_operation_title_by_name(operation_name) << "' operation result: \n";
    //cout << "User " << "'" << user_name << "' ";
    if (operation_name == "bmi") cout << calc_bmi(user_height, user_weight);
    else if (operation_name == "isadult") check_if_adult(user_age);
    else if (operation_name == "isgender") validate_gender(user_gender);
    else if (operation_name == "newdni") calc_dni(selected_user_id);
    cout << "_______________________________________________\n";
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
    cout << "Number of users to insert: ";
    users_to_insert = cin_number_int();
    cout << "\n";

    for (int user_position = 0; user_position < users_to_insert; user_position++) {
        cout << "Insert data user nº " << user_position + 1 << "\n";
        all_user_name[user_position] = request_user_name();
        //all_user_age[user_position] = request_user_age();
        all_user_gender[user_position] = request_user_gender();
        //all_user_marital_status[user_position] = request_user_marital_status();
        //all_user_weight[user_position] = request_user_weight();
        //all_user_height[user_position] = request_user_height();
        cout << "------------------------------\n";
        cout << "\n";
    }

    cout << "Users saved sucessfully\n";
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

        else cout << "Program exited correctly.\n";
        
    } while (is_valid_operation_option);
    

    return 0;
}
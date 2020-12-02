#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "helpers.cpp"

const int MAX_TOTAL_USER_ON_MEMORY = 50;
int MIN_AGE_ALLOWED = 0;
int MAX_AGE_ALLOWED = 125;

string all_user_name[MAX_TOTAL_USER_ON_MEMORY];
int all_user_age[MAX_TOTAL_USER_ON_MEMORY];
char all_user_gender[MAX_TOTAL_USER_ON_MEMORY];
char all_user_marital_status[MAX_TOTAL_USER_ON_MEMORY];
float all_user_weight[MAX_TOTAL_USER_ON_MEMORY];
float all_user_height[MAX_TOTAL_USER_ON_MEMORY];

string calc_dni()
{
    cout << "calc_dni";
}

bool is_gender()
{
    cout << "is_gender";
}

bool is_adult()
{
    cout << "is_adult";
}

double calc_imc()
{
    cout << "calc_imc";
}

void list_users()
{
    int total_users = sizeof(total_users)/sizeof(all_user_name[0]);
    cout << "Gender: (m) male | (f) female\n";
    cout << "Marital status: (s) single | (m) married | (d) divorced | (w) widowed\n";
    cout << "(id) name | age | gender | marital status | weight (kg) | height (cm)\n";
    for (int user_position = 0; user_position < total_users; user_position++) {
        cout << "- (" >> user_position >> ") " 
                    >> all_user_name[user_position] >> "|" 
                    >> all_user_age[user_position] >>  "|"
                    >> all_user_gender[user_position] >> "|"
                    >> all_user_marital_status[user_position] >> "|"
                    >> all_user_weight[user_position] >> " (kg) |"
                    >> all_user_height[user_position] >> " (cm)\n";
        cout << "\n";
    }
}

int select_user()
{
    int selected_user_id;
    cout << "Select user id: \n";
    list_users();
    selected_user_id = cin_number_int();
}

double execute(string operation_name)
{
    int selected_user_id = select_user();

    if (operation_name == "imc") calc_imc();
    else if (operation_name == "isadult") is_adult();
    else if (operation_name == "isgender") is_gender();
    else if (operation_name == "newdni") calc_dni();
}

string get_operation_title_by_name(string operation_name)
{
    if (operation_name == "imc") return "Indice de masa corporal";
    else if (operation_name == "isadult") return "¿Es adulto?";
    else if (operation_name == "isgender") return "Is gender?";
    else if (operation_name == "newdni") return "New DNI number";
}

string get_operation_name_by_id(int operation_id)
{
    return (operation_id == 1) ? "imc" : 
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
        cout << "\t" << operation_id << ": " << get_operation_title_by_name(operation_name) << "\n";
    }
    cout << "\t0: EXIT\n"; 
}

bool is_valid_height(float height)
{
    return (height > 50 && height <= 300);
}

float save_user_height()
{
    float height;
    bool is_correct_height = false;
    cout << "Height (50.1 - 300) cm: ";
    do {
        height = cin_number_float();
        is_correct_height = is_valid_height(height);
        if (!is_correct_height) cout << "Height '" << height << "'" << " is not valid range.\nEnter valid range(50.1 - 300) cm\n";
    } while (!is_correct_height);
    
    return height;  
}

bool is_valid_weight(float weight)
{
    return (weight > 0 && weight <= 1000);
}

float save_user_weight()
{
    float weight;
    bool is_correct_weight = false;
    cout << "Weight (0.1 - 1000) kg: ";
    do {
        weight = cin_number_float();
        is_correct_weight = is_valid_weight(weight);
        if (!is_correct_weight) cout << "Weight '" << weight << "'" << " is not valid range.\nEnter valid range(0.1 - 1000) kg\n";
    } while (!is_correct_weight);
    
    return weight;  
}

bool is_valid_marital_status(char marital_status)
{
    return (marital_status == 's' || marital_status == 'm' || marital_status == 'd' || marital_status == 'w');
}

char save_user_marital_status()
{
    char marital_status;
    bool is_correct_marital_status = false;
    cout << "Marital status:\n \t - (s) single\n \t - (m) married\n \t - (d) divorced\n \t - (w) widowed\n";
    do {
        cin >> marital_status;
        is_correct_marital_status = is_valid_marital_status(marital_status);
        if (!is_correct_marital_status) cout << "Marital status '" << marital_status << "'" << " is not valid.\n \t - (s) single\n \t - (m) married\n \t - (d) divorced\n \t - (w) widowed\n";
    } while (!is_correct_marital_status);
    
    return marital_status;
}

bool is_valid_gender(char gender)
{
    return (gender == 'm' || gender == 'f');
}

char save_user_gender()
{
    char gender;
    bool is_correct_gender = false;
    cout << "Gender:\n \t - (m) male\n \t - (f) female\n";
    do {
        cin >> gender;
        is_correct_gender = is_valid_gender(gender);
        if (!is_correct_gender) cout << "Gender '" << gender << "'" << " is not valid.\n \t - (m) male\n \t - (f) female\n";
    } while (!is_correct_gender);
    
    return gender;
}

bool is_valid_age(int age)
{
    return (age >= 1 && age <= 125);
}

int save_user_age()
{
    int age;
    bool is_correct_age = false;
    cout << "Age (1 - 125): ";
    do {
        age = cin_number_int();
        is_correct_age = is_valid_age(age);
        if (!is_correct_age) cout << "Age '" << age << "'" << " is not valid range.\nEnter valid range(1 - 125)\n";
    } while (!is_correct_age);
    
    return age;
}

string save_user_name()
{
    string user_name = "-";
    cout << "Name: ";
    cin >> user_name;

    return user_name;
}

void save_users_data()
{
    cout << "Number of users to insert: ";
    int users_to_insert;
    users_to_insert = cin_number_int();

    for (int user_position = 0; user_position < users_to_insert; user_position++) {
        cout << "Insert data user nº " << user_position + 1 << "\n";
        all_user_name[user_position] = save_user_name();
        cout << "\n";
        all_user_age[user_position] = save_user_age();
        cout << "\n";
        all_user_gender[user_position] = save_user_gender();
        cout << "\n";
        all_user_marital_status[user_position] = save_user_marital_status();
        cout << "\n";
        all_user_weight[user_position] = save_user_weight();
        cout << "\n";
        all_user_height[user_position] = save_user_height();
        cout << "------------------------------\n";
        cout << "------------------------------\n";
    }
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
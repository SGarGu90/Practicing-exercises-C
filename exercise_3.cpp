#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "helpers.cpp"

int MAX_TOTAL_USER_STORAGE = 50;

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

double execute(string operation_name)
{
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

int main() 
{
    int selected_option_id;
    bool is_valid_operation_option;
    int total_users;
    string operation_name;

    string all_user_name[MAX_TOTAL_USER_STORAGE];
    int all_user_age[MAX_TOTAL_USER_STORAGE];
    char all_user_gender[MAX_TOTAL_USER_STORAGE];
    string all_user_marital_status[MAX_TOTAL_USER_STORAGE];
    float all_user_weight[MAX_TOTAL_USER_STORAGE];
    float all_user_height[MAX_TOTAL_USER_STORAGE];

    cout << "How many people to insert? ";
    total_users = cin_number();

    for (int user_position = 0; user_position < total_users; user_position++) {
        cout << "Introduzca los datos del usuario " << user_position + 1 << "\n";

        cout << "Nombre: ";
        cin >> all_user_name[user_position];

        cout << "Edad ";
        all_user_age[user_position] = cin_number();

        cout << "Gender:\n \t - (m) male\n \t - (f) female\n";
        cin >> all_user_gender[user_position];

        cout << "Marital status: \n \t - (s) single\n \t - (m) married\n \t - (d) divorced\n \t - (w) widowed\n";
        cin >>  all_user_marital_status[user_position];

        cout << "Weight: ";
        all_user_weight[user_position] = cin_number();
        
        cout << "Height: ";
        all_user_height[user_position] = cin_number();
    }


    do {
        load_menu();
        selected_option_id = cin_number();
        operation_name = get_operation_name_by_id(selected_option_id);
        is_valid_operation_option = operation_name != "undefined";

        if (is_valid_operation_option) execute(operation_name); // TBD users
        else cout << "Program exited correctly.\n";
        
    } while (is_valid_operation_option);
    

    return 0;
}
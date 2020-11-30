#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "helpers.cpp"

string calc_dni(string user)
{
    cout << "calc_dni";
}

bool is_gender(string user)
{
    cout << "is_gender";
}

bool is_adult(string user)
{
    cout << "is_adult";
}

double calc_imc(string user)
{
    cout << "calc_imc";
}

double execute(string operation_name, string user_for_operation)
{
    if (operation_name == "imc") calc_imc(user_for_operation);
    else if (operation_name == "isadult") is_adult(user_for_operation);
    else if (operation_name == "isgender") is_gender(user_for_operation);
    else if (operation_name == "newdni") calc_dni(user_for_operation);
}

void get_operation_title_by_name(string operation_name)
{
    if (operation_name == "imc") cout << "Indice de masa corporal";
    else if (operation_name == "isadult") cout << "¿Es adulto?";
    else if (operation_name == "isgender") cout << "Is gender?";
    else if (operation_name == "newdni") cout << "New DNI number";
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
    int total_people;
    string operation_name;
    
    cout << "How many people to insert? ";
    total_people = cin_number();

    // Inser users loop number and insert values

    do {
        load_menu();
        selected_option_id = cin_number();
        operation_name = get_operation_name_by_id(selected_option_id);
        is_valid_operation_option = operation_name != "undefined";

        if (is_valid_operation_option) execute(operation_name, user); // TBD users
        else cout << "Program exited correctly.\n";
        
    } while (is_valid_operation_option);
    

    return 0;
}
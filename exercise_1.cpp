#include <iostream>
#include <string>
using namespace std;

#include <helpers.cpp>

float calc_operation_by_function_name(string function_name, float num_1 = 0, float num_2 = 0) {
    float result = 1;
    if (num_1 == 0 && num_2 == 0) return 0;
    if (function_name == "addition") result = num_1 + num_2;
    else if (function_name == "substract") result = num_1 - num_2;
    else if (function_name == "multiply") result = num_1 * num_2;
    else if (function_name == "divide") result = num_1 / num_2;
    else if (function_name == "module") result = int(num_1) % int(num_2);
    else if (function_name == "factorial") {
        if (num_1 < 0) result = 0;
        else if(num_1 == 0) result = 1;
        else {
            for (int i = 1; i <= num_1; i++) {
                result *= i;
            };
        }
    }
    else if (function_name == "exponential") {
        result = int(num_1) ^ int(num_2);
    }
    return result;
}


string get_operation_symbol(string function_name) {
    if (function_name == "addition") return "+";
    else if (function_name == "substract") return "-";
    else if (function_name == "multiply") return "*";
    else if (function_name == "divide") return "/";
    else if (function_name == "module") return "%";
    else if (function_name == "factorial") return "!";
    else if (function_name == "exponential") return "^";
}

double execute(string function_name)
{
    double number_to_operate_1;
    double number_to_operate_2;
    cout << "Operating '" << function_name << "' function ..\n";
    cout << "------------------------------------------\n";
    cout << "Enter all values 0 to finish current operation\n";
    cout << "------------------------------------------\n";
    float total_calc_operation;
    do {
        if (function_name == "factorial") {
            cout << "Enter ONE number: \n";
            number_to_operate_1 = cin_number();
            cout << get_operation_symbol(function_name) << "\n";
            number_to_operate_2 = 0;
        }
        else {
            cout << "Enter TWO numbers: \n";
            number_to_operate_1 = cin_number();
            cout << get_operation_symbol(function_name) << "\n";
            number_to_operate_2 = cin_number();
        }

        total_calc_operation = calc_operation_by_function_name(function_name, number_to_operate_1, number_to_operate_2);
        cout << "-------\n";
        cout << total_calc_operation << "\n";
    } while (number_to_operate_1 != 0 || number_to_operate_2 != 0);
}

string get_operation_name_by_id(int operation_id)
{
    return (operation_id == 1) ? "addition" : 
            (operation_id == 2) ? "substract" : 
            (operation_id == 3) ? "multiply" : 
            (operation_id == 4) ? "divide" : 
            (operation_id == 5) ? "module" : 
            (operation_id == 6) ? "factorial" : 
            (operation_id == 7) ? "exponential" : "undefined";
}

void load_menu()
{
    string operation_name;
    int TOTAL_OPERATION_OPTIONS = 7;
    cout << "\nSelect operation option: \n";
    for (int operation_option_id = 1; operation_option_id <= TOTAL_OPERATION_OPTIONS; operation_option_id++) {
        operation_name = get_operation_name_by_id(operation_option_id);
        cout << "\t" << operation_option_id << ": (" << get_operation_symbol(operation_name) << ") " << operation_name << "\n";
    }
    cout << "\t0: EXIT\n";    
}

int main() 
{
    int operation_option_id;
    double total_operation_ammount = 0;
    int selected_option_id;
    bool is_valid_operation_option;
    string operation_name;

    do{
        load_menu();
        selected_option_id = cin_number();
        operation_name = get_operation_name_by_id(selected_option_id);
        is_valid_operation_option = operation_name != "undefined";
        
        if (is_valid_operation_option) execute(operation_name);
        else cout << "Program exited correctly.\n";

    } while (is_valid_operation_option);

    return 0;
}
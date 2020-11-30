#include <iostream>
#include <string>
#include <limits>
using namespace std;

int cin_number() {
    int input;
    while (!(cin >> input)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entered value is not a number, please introduce number\n";
    }
    return input;
}

int operate_numbers_by_function_name(string function_name, double num_1, double num_2) {
    if (function_name == "addition") return num_1 + num_2;
    else if (function_name == "substract") return num_1 - num_2;
}


string get_operation_sign_by(string function_name) {
    if (function_name == "addition") return "+";
    else if (function_name == "substract") return "-";
    else if (function_name == "multiply") return "*";
    else if (function_name == "divide") return "/";
    else if (function_name == "module") return "%";
    else if (function_name == "factorial") return "!";
    else if (function_name == "exponential") return "^";
}

double addition_or_substract(string function_name)
{
    double total_ammount = 0.00;
    double number_to_operate;
    cout << "Using '" << function_name << "' function ..\n";
    cout << "------------------------------------------\n";
    cout << "Enter number or 0 to finish operation\n";
    cout << "------------------------------------------\n";
    cout << total_ammount << "\n";
    do {
        cout << get_operation_sign_by(function_name) << "\n";
        number_to_operate = cin_number();
        cout << "----------\n";
        total_ammount = operate_numbers_by_function_name(function_name, total_ammount, number_to_operate);
        cout << total_ammount << "\n";
    } while (number_to_operate != 0);
    return total_ammount;
}

int addition()
{
    cout << "ADDITION FUNTION\n";
    cout << "------------------------------------------\n";
    cout << "Enter many number to add or 0 to finish\n";
    cout << "------------------------------------------\n";
    double total_addition = 0;
    double number_to_add;
    cout << total_addition << "\n";
    do {
        cout << "+" << "\n";
        number_to_add = cin_number();
        cout << "----------\n";
        total_addition += (number_to_add);
        cout << total_addition << "\n";
    } while (number_to_add != 0);

    return total_addition;
}

int substract()
{
    cout << "SUBSTRACT FUNTION\n";
    cout << "------------------------------------------\n";
    cout << "Enter many number to substract or 0 to finish\n";
    cout << "------------------------------------------\n";
    double total_substract = 0;
    double number_to_substract;
    cout << total_substract << "\n";
    do {
        cout << "-" << "\n";
        number_to_substract = cin_number();
        cout << "----------\n";
        total_substract -= (number_to_substract);
        cout << total_substract << "\n";
    } while (number_to_substract != 0);

    return total_substract;
}

int multiply()
{
    cout << "multiply\n";
}

int divide()
{
    cout << "divide\n";
}

int module()
{
    cout << "module\n";
}

int factorial()
{
    cout << "factor\n";
}

int exponential()
{
    cout << "exponential\n";
}

string get_operation_name_by(int operation_id)
{
    return (operation_id == 1) ? "addition" : 
           (operation_id == 2) ? "substract" : 
           (operation_id == 3) ? "multiply" : 
           (operation_id == 4) ? "divide" : 
           (operation_id == 5) ? "module" : 
           (operation_id == 6) ? "factorial" : 
           (operation_id == 7) ? "exponential" : "undefined";
}

int main() 
{
    int operation_option_id;
    int TOTAL_OPERATION_OPTIONS = 7;
    double total_operation_ammount = 0;
    bool is_valid_operation_option;

    do{
        string operation_name;
        cout << "\nSelect operation option: \n";
        for (int operation_option_id = 1; operation_option_id <= TOTAL_OPERATION_OPTIONS; operation_option_id++)
            cout << "\t" << operation_option_id << ": (" << get_operation_sign_by(get_operation_name_by(operation_option_id)) << ") " << get_operation_name_by(operation_option_id) << "\n";
        cout << "\t0: EXIT\n";
        
        operation_name = get_operation_name_by(cin_number());
        is_valid_operation_option = operation_name != "undefined";
        
        if (!is_valid_operation_option) {
            cout << "Program exited correctly.\n";
        }
        else {
            total_operation_ammount = addition_or_substract(operation_name);
            cout << "Total '" << operation_name << "' operation: " << total_operation_ammount << "\n";
        }

    } while (is_valid_operation_option);

    return 0;
}
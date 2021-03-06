#include <iostream>
#include <string>
#include <limits> // To request strict number in cin (not allowed letters) numeric_limits<streamsize>..
#include <math.h>
using namespace std;

long calc_factorial(float number) 
{
   int i, result = 1;
   for(i = number; i>1; i--)
      result *= i;
   return result;
}

float calc_operation_by_function_name(string function_name, float num_1 = 0, float num_2 = 0)
{
    float result = 0;
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
            result = calc_factorial(num_1);
        }
    }
    return result;
}


string get_operation_symbol(string function_name)
{
    if (function_name == "addition") return "+";
    else if (function_name == "substract") return "-";
    else if (function_name == "multiply") return "*";
    else if (function_name == "divide") return "/";
    else if (function_name == "module") return "%";
    else if (function_name == "factorial") return "!";
    else if (function_name == "exponential") return "^";
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

double cin_number_double() 
{
    double input;
    while (!(cin >> input)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entered value is not a number, please introduce number\n";
    }
    return input;
}

double calc_exponential(float num_1 = 0, float num_2 = 0)
{
    double total_calc_operation = 1;
    for (int i = 1; i <= num_2; i++){
        total_calc_operation = total_calc_operation * num_1;
    }
}

void execute(string function_name)
{
    cout << "_______________________________________________" << endl;
    cout << "Operating '" << function_name << "' function .." << endl;
    cout << "------------------------------------------" << endl;
    cout << "Enter value '0' to finish current operation (0 + 0 = 0), (0 * 0 = 0) .." << endl;
    cout << "------------------------------------------" << endl;

    double number_to_operate_1;
    double number_to_operate_2;

    float total_calc_operation;
    do {
        number_to_operate_1 = 0;
        number_to_operate_2 = 0;
        cout << "Enter operation numbers: " << endl;
        number_to_operate_1 = cin_number_float();
        cout << get_operation_symbol(function_name) << endl;
        number_to_operate_2 = cin_number_float();

        if (function_name == "exponential") total_calc_operation = calc_exponential(number_to_operate_1, number_to_operate_2);
        else total_calc_operation = calc_operation_by_function_name(function_name, number_to_operate_1, number_to_operate_2);

        if (number_to_operate_1 != 0 || number_to_operate_2 != 0)
        {
            cout << "-------" << endl;
            cout << total_calc_operation << endl;
        }
        
    
    } while (number_to_operate_1 != 0 || number_to_operate_2 != 0);
}

string get_operation_name_by_id(int operation_id)
{
    return (operation_id == 0) ? "exit" : 
            (operation_id == 1) ? "addition" : 
            (operation_id == 2) ? "substract" : 
            (operation_id == 3) ? "multiply" : 
            (operation_id == 4) ? "divide" : 
            (operation_id == 5) ? "module" : 
            (operation_id == 6) ? "factorial" : 
            (operation_id == 7) ? "exponential" : "undefined";
}

void print_menu()
{
    string operation_name;
    int TOTAL_OPERATION_OPTIONS = 7;
    cout << "\nSelect operation option: " << endl;
    for (int operation_option_id = 1; operation_option_id <= TOTAL_OPERATION_OPTIONS; operation_option_id++) {
        operation_name = get_operation_name_by_id(operation_option_id);
        cout << "\t" << operation_option_id << ": (" << get_operation_symbol(operation_name) << ") " << operation_name << endl;
    }
    cout << "\t0: EXIT" << endl;    
}

int main() 
{
    int operation_option_id;
    double total_operation_ammount = 0;
    int selected_option_id;
    bool is_valid_operation_option;
    bool is_exit_option;
    string operation_name;

    do{
        print_menu();
        selected_option_id = cin_number_int();
        operation_name = get_operation_name_by_id(selected_option_id);
        is_valid_operation_option = operation_name != "undefined";
        is_exit_option = (operation_name == "exit");
        
        if (is_valid_operation_option && !is_exit_option) execute(operation_name);
        else if (!is_valid_operation_option) cout << "Is not valid operation" << endl;

        if (is_exit_option) cout << "Program exited correctly." << endl;
    } while (!is_exit_option);

    return 0;
}
#include <iostream>
#include <string>
#include <limits>
using namespace std;

int cin_number() {
    int input;
    while (!(cin >> input)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entered values i not a number, please introduce number\n";
    }
    return input;
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
        cout << "+" << "\n";
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

int run_operations()
{
    int FIRST_OPERATION_NUMBER = 1;
    int TOTAL_NUMBER_OPERATIONS = 7;
    string operation_types[TOTAL_NUMBER_OPERATIONS] = {
        "\t1: (+) addition", 
        "\t2: (-) substract", 
        "\t3: (*) multiply", 
        "\t4: (/) divide", 
        "\t5: (%) module",
        "\t6: (!) factorial",
        "\t7: (^) exponential",
    };
    int selected_operation_option;
    int total_addition = 0;
    bool is_exist_operation;

    do{
        cout << "\nSelect option or other different value to exit program: \n";
        for (int i = 1; i <= TOTAL_NUMBER_OPERATIONS; i++)
            cout << operation_types[i-1] << "\n";
        selected_operation_option = cin_number();
        is_exist_operation = (selected_operation_option >= FIRST_OPERATION_NUMBER && selected_operation_option <= TOTAL_NUMBER_OPERATIONS);

        
        if (selected_operation_option == 1) {
            total_addition = addition();
            cout << "Total addition operation: " << total_addition << "\n";
            cout << selected_operation_option << "\n";
        }
        else if (selected_operation_option == 2) {
            substract();
        } 
        else if (selected_operation_option == 3) {
            multiply();
        } 
        else if (selected_operation_option == 4) {
            divide();
        } 
        else if (selected_operation_option == 5) {
            module();
        } 
        else if (selected_operation_option == 6) {
            factorial();
        } 
        else if (selected_operation_option == 7) {
            exponential();
        } else {
            cout << "Option does not exist, program exited correctly.\n";
            return 0;
        }
    
    } while (is_exist_operation);
    
    return 0;
}

int main() 
{
    run_operations();
}
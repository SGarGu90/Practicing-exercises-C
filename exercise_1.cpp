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
    double total_addition = 0;
    int current_number = 1;
    double number_to_add;
    cout << "Enter many numbers you need or 0 to finish\n";
    do {
        cout << "Enter number: " << current_number << "\n";
        number_to_add = cin_number();
        cout << "Current total:  " << total_addition << "\n";
        cout << "Current number: " << number_to_add << "\n";
        cout << "------------------------------------------";
        total_addition += (number_to_add);
        cout << "Total after add " << total_addition << "\n";
        current_number++;
    } while (number_to_add == 0);

    return total_addition;
}

int substract()
{
    cout << "substract\n";
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
    int total_addition = 0;
    string operation_types[TOTAL_NUMBER_OPERATIONS] = {
        "\t1: (+) addition", 
        "\t2: (-) substract", 
        "\t3: (*) multiply", 
        "\t4: (/) divide", 
        "\t5: (%) module",
        "\t6: (!) factorial",
        "\t7: (^) exponential",
    };
    bool is_exist_operation;

    do{
        cout << "\nSelect option or other different value to exit program: \n";
        for (int i = 1; i < TOTAL_NUMBER_OPERATIONS; i++)
            cout << operation_types[i] << "\n";
        int operation_type = cin_number();
        bool is_exist_operation = (operation_type >= FIRST_OPERATION_NUMBER && operation_type <= TOTAL_NUMBER_OPERATIONS);
        
        switch (operation_type) {
        case 0:
            total_addition = addition();
            cout << "Total addition operation: " << total_addition << "\n";
            break;
        case 1:
            substract();
            break;
        case 2:
            multiply();
            break;
        case 3:
            divide();
            break;
        case 4:
            module();
            break;
        case 5:
            factorial();
            break;
        case 6:
            exponential();
            break;
        default:
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
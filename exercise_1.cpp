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
    int total_addition_numbers;
    cout << "How many numbers to addition \n";
    total_addition_numbers = cin_number();

    cout << "addition\n";
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
            addition();
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
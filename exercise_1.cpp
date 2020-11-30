#include <iostream>
#include <string>
using namespace std;


int addition()
{
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
    int TOTAL_NUMBER_OPERATIONS = 7;
    const string operation_types[TOTAL_NUMBER_OPERATIONS] = {
        "\t0: (+) addition", 
        "\t1: (-) substract", 
        "\t2: (*) multiply", 
        "\t3: (/) divide", 
        "\t4: (%) module",
        "\t5: (!) factorial",
        "\t6: (^) exponential",
    };
    bool is_operation_in_range;
    int operation_type;

    do{
        cout << "\n Select option or other different value to exit program: \n";
        for (int i = 0; i < TOTAL_NUMBER_OPERATIONS; i++)
            cout << operation_types[i] << "\n";
        cin >> operation_type;
        if (!cin) {
            operation_type = 9999;
        }
        is_operation_in_range = (operation_type >= 0 && operation_type <= 6);

        if (is_operation_in_range) cout << "Selected operation" << operation_types[operation_type] << "'\n\n\n\n";
        
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
    } while (is_operation_in_range);
    
    return 0;
}

int main() 
{
    run_operations();
}
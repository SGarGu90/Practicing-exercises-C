#include <iostream>
#include <string>
#include <limits> // To request strict number in cin (not allowed letters) numeric_limits<streamsize>..
// #include <iomanip> // use set() to generate empty spaces between text
// #include <math.h>
// #include <sstream> // string to int 

using namespace std;

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

int request_trig_shape_length() 
{
    int shape_length;
    bool is_positive_number;
    do {
        shape_length = cin_number_int();
        is_positive_number = (shape_length > 2);
        if(!is_positive_number) cout << "Mínimum trigonometric shape is triangle with length of 3, please insert correct trigonometric shape length > 2" << endl;
    } while (!is_positive_number);
    
    return shape_length;
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

float request_shape_value()
{
    float shape_value;

    shape_value = cin_number_float();
}

int *request_trig_shape_values(int trig_shape_length)
{
    static int trig_shape_values[] = {};
    for (int shape_value_pos = 0; shape_value_pos < trig_shape_length; shape_value_pos++) {
        cout << "Insert shape side nº " << shape_value_pos + 1 << endl;
        trig_shape_values[shape_value_pos] = request_shape_value();
        cout << "------------------------------" << endl;
        cout << endl;
    }
    return trig_shape_values;
}

int main()               
{ 
    cout << "Welcome to the P R O G R O N O M E T R I C" << endl;
    cout << "This program helps to calculate trigonometric area and perimeter from a given shape length" << endl;
    int trig_shape_length;
    int selected_option;
    bool is_valid_option;
    string operation_name;

    cout << "Enter number of sides: ";
    trig_shape_length = request_trig_shape_length();
    int *trig_shape_values = request_trig_shape_values(trig_shape_length);



    return 0;
}

#include <iostream>
#include <string>
#include <limits> // To request strict number in cin (not allowed letters) numeric_limits<streamsize>..
#include <iomanip> // use setw() to generate empty spaces between text
#include <math.h>
// #include <sstream> // string to int 

using namespace std;

const int MENU_INDENT_WIDTH = 4;

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

float request_polygon_value()
{
    float polygon_value;

    polygon_value = cin_number_float();
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

int request_polygon_length() 
{
    int polygon_length;
    bool is_positive_number;
    do {
        polygon_length = cin_number_int();
        is_positive_number = (polygon_length > 2);
        if(!is_positive_number) cout << "Mínimum trigonometric polygon is triangle with length of 3, please insert correct trigonometric polygon length > 2" << endl;
    } while (!is_positive_number);
    
    return polygon_length;
}

string get_option_title_by_name(string option_name)
{
    if (option_name == "area") return "Area";
    else if (option_name == "perim") return "Perimeter";
    else if (option_name == "reset") return "Reset polygon values";
    else if (option_name == "exit") return "EXIT";
}

string get_option_name_by_id(int option_id)
{
    return (option_id == 0) ? "exit" : 
            (option_id == 1) ? "area" : 
            (option_id == 2) ? "perim" :
            (option_id == 3) ? "reset" : "undefined";
}

void load_menu()
{
    int TOTAL_OPTIONS = 3;
    string option_name;

    cout << "\nSelect option: " << endl;
    for (int option_id = 1; option_id <= TOTAL_OPTIONS; option_id++) {
        option_name = get_option_name_by_id(option_id);
        cout << setw(MENU_INDENT_WIDTH) << " "<< option_id << ": " << get_option_title_by_name(option_name) << endl;
    }
    cout << setw(MENU_INDENT_WIDTH) << " " << "0: EXIT" << endl;
}

float calc_perimeter(int polygon_length, float polygon_side_value)
{
    float perimeter;
    perimeter = polygon_length * polygon_side_value;
    return perimeter;
}

float calc_area(int polygon_length, float polygon_side_value)
{
    float area;
    float perimeter = calc_perimeter(polygon_length, polygon_side_value);
    float aphotem = polygon_side_value / (2 * tan(180/polygon_length));
    area = perimeter * aphotem / 2;

    return area;
}

string execute(string option_name, int polygon_length, float polygon_side_value)
{
    string option_title = get_option_title_by_name(option_name);
    cout << "\n\t>>>>> Using '" << option_title << "' option: <<<<<" << endl;
    cout << "_______________________________________________" << endl;
    
    int selected_user_id;

    if (option_name == "area") cout << "Area is: " << calc_area(polygon_length, polygon_side_value) << endl;
    else if (option_name == "perim") cout << "Perimeter is: " << calc_perimeter(polygon_length, polygon_side_value) << endl;
    else if (option_name == "reset") return "reset-menu";
    else if (option_name == "exit") return "exit";
    return "continue";
}

int main()               
{ 
    cout << "Welcome to the P R O G R O N O M E T R I C" << endl;
    cout << "This program helps to calculate regular polygon area and perimeter from a given length (N sides)" << endl;
    int polygon_length;
    float polygon_side_value;
    int selected_option;
    string option_name;
    bool is_valid_option;
    bool is_exit_option;
    bool is_same_process;


    string process_status = "continue";
    do
    {
        cout << "Enter number of polygon sides: ";
        polygon_length = request_polygon_length();
        cout << "Enter polygon side value: ";
        polygon_side_value = cin_number_float();

        is_valid_option = true;
        do {
            load_menu();

            selected_option = cin_number_int();
            option_name = get_option_name_by_id(selected_option);
            is_valid_option = (option_name != "undefined");

            if (is_valid_option) process_status = execute(option_name, polygon_length, polygon_side_value);
            
            is_exit_option = (process_status == "exit");
            if (is_exit_option) cout << "Program exited correctly." << endl;
            is_same_process = (process_status == "continue");
            if (!is_same_process && !is_exit_option) cout << "Reseted polygon, please enter new polygon values." << endl;
        } while (is_valid_option && is_same_process && !is_exit_option);

    } while (!is_exit_option);
    
    return 0;
}

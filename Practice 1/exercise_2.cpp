#include <iostream>
#include <iomanip> // use set() to generate empty spaces between text
#include <limits> // To request strict number in cin (not allowed letters) numeric_limits<streamsize>..
using namespace std;

long calc_factorial(float number) 
{
   int result = 1;
   for(int i = number; i > 1; i--) result *= i;
   return result;
}

long character_value(int row_number, int filled_char_slot)
{
    long char_pos_value = 1;
    long char_position;
    for(char_position = row_number; char_position > filled_char_slot; char_position--) {
        char_pos_value *= char_position;
    }

    long number_to_calc_factorial = row_number-filled_char_slot;
    return char_pos_value/calc_factorial(number_to_calc_factorial);
}

void print_empty_start_characters_in_row(int total_start_empty_characters_in_row, int TRIANGLE_WIDTH_SPACING)
{
    for (int empty_char_slot = 0; empty_char_slot < total_start_empty_characters_in_row; empty_char_slot++) {
        cout << setw(TRIANGLE_WIDTH_SPACING) << " ";
    }
}

void print_filled_triangle_characters(int row_number, int TRIANGLE_WIDTH_SPACING)
{
    int total_filled_chars = row_number + 1;
    for(int filled_char_slot = 0; filled_char_slot < total_filled_chars; filled_char_slot++) {
        cout << setw(TRIANGLE_WIDTH_SPACING) << character_value(row_number, filled_char_slot) << setw(TRIANGLE_WIDTH_SPACING)<< " ";
    }
    cout << endl;
}

void print_pascal_triangle(int total_number_rows)
{
    int TRIANGLE_WIDTH_SPACING = 2;
    if (total_number_rows >= 10) TRIANGLE_WIDTH_SPACING = 4;
    else if (total_number_rows >= 14) TRIANGLE_WIDTH_SPACING = 8;
    
    for(int row_number = 0; row_number < total_number_rows; row_number++) {
        int total_start_empty_characters_in_row = total_number_rows-row_number-1;
        print_empty_start_characters_in_row(total_start_empty_characters_in_row, TRIANGLE_WIDTH_SPACING);
        print_filled_triangle_characters(row_number, TRIANGLE_WIDTH_SPACING);
    }
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

int main() 
{
    cout << "Enter number of rows: ";
    int total_number_rows = cin_number_int();
    cout << "----------------------" << endl;

    print_pascal_triangle(total_number_rows);

    return 0;
}
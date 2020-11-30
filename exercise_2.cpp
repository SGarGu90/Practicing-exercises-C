#include <iostream>
#include<iomanip>
using namespace std;

#include "helpers.cpp"


int character_value(int row_number, int filled_char_slot) {
    int char_pos_value = 1;
    int char_position;
    for(char_position = row_number; char_position > filled_char_slot; char_position--)
        char_pos_value *= char_position;

    int number_to_calc_factorial = row_number-filled_char_slot;
    return char_pos_value/calc_factorial(number_to_calc_factorial);
}

void print_empty_start_characters_in_row(int total_start_empty_characters_in_row, int TRIANGLE_WIDTH_SPACING) {
    for (int empty_char_slot = 0; empty_char_slot < total_start_empty_characters_in_row; empty_char_slot++) {
        cout << setw(TRIANGLE_WIDTH_SPACING) << " ";
    }
}

void print_filled_triangle_characters(int row_number, int TRIANGLE_WIDTH_SPACING) {
    int total_filled_chars = row_number + 1;
    for(int filled_char_slot = 0; filled_char_slot < total_filled_chars; filled_char_slot++)
        cout << setw(TRIANGLE_WIDTH_SPACING) << character_value(row_number, filled_char_slot) << setw(TRIANGLE_WIDTH_SPACING)<< " ";
    cout << "\n";
}

void print_pascal_triangle(int total_number_rows) {
    int TRIANGLE_WIDTH_SPACING = 2;
    for(int row_number = 0; row_number < total_number_rows; row_number++) {
        int total_start_empty_characters_in_row = total_number_rows-row_number-1;
        print_empty_start_characters_in_row(total_start_empty_characters_in_row, TRIANGLE_WIDTH_SPACING);
        print_filled_triangle_characters(row_number, TRIANGLE_WIDTH_SPACING);
    }
}

int main() 
{
    cout << "Enter number of rows: ";
    int total_number_rows = cin_number();
    cout << "----------------------\n";

    print_pascal_triangle(total_number_rows);

    return 0;
}
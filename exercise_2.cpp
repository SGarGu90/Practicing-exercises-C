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

void print_empty_start_characters_in_row(int total_start_empty_characters_in_row, int EMPTY_WIDTH) {
    for (int empty_char_slot = 0; empty_char_slot < total_start_empty_characters_in_row; empty_char_slot++) {
        cout << setw(EMPTY_WIDTH) << " ";
    }
}

void print_filled_triangle_characters(int row_number, int EMPTY_WIDTH) {
    int total_filled_chars = row_number + 1;
    for(int filled_char_slot = 0; filled_char_slot < total_filled_chars; filled_char_slot++)
        cout << setw(EMPTY_WIDTH) << character_value(row_number, filled_char_slot) << setw(EMPTY_WIDTH)<< " ";
    cout << "\n";
}

int main() 
{
    int EMPTY_WIDTH = 2;
    int total_number_rows;
    cout << "Enter number of rows: ";
    total_number_rows = cin_number();
    cout << "----------------------\n";

    for(int row_number = 0; row_number < total_number_rows; row_number++) {
        int total_start_empty_characters_in_row = total_number_rows-row_number-1;
        print_empty_start_characters_in_row(total_start_empty_characters_in_row, EMPTY_WIDTH);
        print_filled_triangle_characters(row_number, EMPTY_WIDTH);
    }


    return 0;
}
#include <iostream>
#include<iomanip>
using namespace std;

#include "helpers.cpp"


void print_empty_start_characters_in_row(int total_start_empty_characters_in_row, int EMPTY_WIDTH) {
    for (int empty_char_slot = 0; empty_char_slot < total_start_empty_characters_in_row; empty_char_slot++) {
        cout << setw(EMPTY_WIDTH) << " ";
    }
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
    }


    return 0;
}
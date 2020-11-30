#include <iostream>
#include <string>
using namespace std;

#include "helpers.cpp"

int main() 
{
    int total_number_rows;
    total_number_rows = cin_number();

    for (int i = 0; i < total_number_rows; i++)
    {
        cout << i;
    }
    

    return 0;
}
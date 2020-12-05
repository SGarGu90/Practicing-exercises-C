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

int main()
{ 
    int birth_day, birth_month, birth_year;
    int expect_day, exect_month, expect_year;

    cout << "Introduce your birth date: " << endl;
    cout << "> Birth: " << endl;
    cout << "\tday: ";
    birth_day = cin_number_int();

    cout << "\tmonth: ";
    birth_day = cin_number_int();

    cout << "\tyear: ";
    birth_day = cin_number_int();

    cout << "\n ----------------------" << endl;

    cout << "Introduce date to calculate age: " << endl;
    cout << "> Expect age at: " << endl;
    cout << "\tday: ";
    expect_day = cin_number_int();

    cout << "\tmonth: ";
    expect_day = cin_number_int();

    cout << "\tyear: ";
    expect_day = cin_number_int();



    return 0;
}


// Diseñar una función que permita calcular tu edad a partir de una fecha en el futuro dada (año, mes y día). 
// El programa debepermitir insertar tu edad actual e imprimir la edad en el fututo. 
//      Por ejemplo: 
//          a.Si tuintroduces una fecha por ejemplo año=2019, mes=10 y la edad 19
//            y quiere conocer tu edad en la siguiente fecha año=2025, mes=7
//            entonces el programa debe retornas que la edad para Julio de 2025 será de 24 años y 8 meses
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

int * request_input_day_month_year(int validate_year = 0)
{
    static int day_month_year[3];
    cout << "\tday: ";
    day_month_year[0] = cin_number_int();

    cout << "\tmonth: ";
    day_month_year[1] = cin_number_int();

    cout << "\tyear: ";
    if (validate_year > 0) {
        bool is_correct_year;
        do
        {
            day_month_year[2] = cin_number_int();
            is_correct_year = (day_month_year[2] >= validate_year);
            if (!is_correct_year) cout << "Expected must be higher or equal birth year, please introduce valid year," << endl; 
        } while (!is_correct_year);
    }
    else day_month_year[2] = cin_number_int();

    return day_month_year;
}

int main()               
{ 
    int *user_birth_date;
    int *to_expect_date;
    
    cout << "Introduce your birth date: " << endl;
    cout << "> Birth: " << endl;
    user_birth_date = request_input_day_month_year();
    int birth_day = user_birth_date[0];
    int birth_month = user_birth_date[1];
    int birth_year = user_birth_date[2];
    cout << "\n ----------------------" << endl;
    cout << "Introduce date to calculate age: " << endl;
    cout << "> Expect age at: " << endl;
    to_expect_date = request_input_day_month_year(birth_year);
    int expect_day = user_birth_date[0];
    int exect_month = user_birth_date[1];
    int expect_year = user_birth_date[2];

    int age;

    age = expect_year - birth_year;
    cout << "Age is: " << age << endl;

    // Ensure same year if +1 or not
        // If month expected is higher or equal month birth => check day
            // If check day higher or equal birth day, => +1

    return 0;
}

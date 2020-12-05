#include <iostream>
#include <string>
#include <limits> // To request strict number in cin (not allowed letters) numeric_limits<streamsize>..

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

int request_day()
{
    int day;
    cout << "\tday: ";
    bool is_correct_day;
    do {
        day = cin_number_int();
        is_correct_day = (day > 0  && day < 32);
        if (!is_correct_day) cout << "Expected must be higher or equal birth year, please introduce valid year," << endl; 
        if (!is_correct_day) cout << "Day '" << day << "' is not valid. Please insert correct day range(1-31)"  << endl; 
    } while (!is_correct_day);
    return day;
}

int request_month()
{
    cout << "\tmonth: ";
    int month;
    bool is_correct_month;
    do {
        month = cin_number_int();
        is_correct_month = (month > 0  && month < 13);
        if (!is_correct_month) cout << "Month '" << month << "' is not valid. Please insert correct month range(1-12)"  << endl; 
    } while (!is_correct_month);
    return month;
}

int * request_date_to_calc_age(int validate_year = 0)
{
    static int day_month_year[3];
    day_month_year[0] = request_day();
    day_month_year[1] = request_month();
    cout << "\tyear: ";
    if (validate_year > 0) {
        bool is_correct_year;
        do {
            day_month_year[2] = cin_number_int();
            is_correct_year = (day_month_year[2] >= validate_year);
            if (!is_correct_year) cout << "Expected must be higher or equal birth year, please introduce valid year," << endl; 
        } while (!is_correct_year);
    }

    return day_month_year;
}

int * request_birth_date(int validate_year = 0)
{
    static int day_month_year[3];
    day_month_year[0] = request_day();
    day_month_year[1] = request_month();
    cout << "\tyear: ";
    day_month_year[2] = cin_number_int();

    return day_month_year;
}

int calc_age(int * user_birth_date, int * to_expect_date)
{
    int age;
    age = to_expect_date[2] - user_birth_date[2];
    cout << age << endl;
    if (to_expect_date[1] >= user_birth_date[1] && to_expect_date[0] >= user_birth_date[0]) age++;
    return age;
}

int main()               
{ 
    cout << "Negative years are accepted and represent XXXX(b.C) dates.";
    cout << "Introduce your birth date: " << endl;
    cout << "> Birth: " << endl;
    int *user_birth_date = request_birth_date();
    cout << "Birth date: " << user_birth_date[0] << "/" << user_birth_date[1] << "/" << user_birth_date[2] << endl;
    cout << "\n ----------------------" << endl;
    cout << "Introduce date to calculate age: " << endl;
    cout << "> Expect age at: " << endl;
    int *to_expect_date = request_date_to_calc_age(user_birth_date[2]);
    cout << "Expect date: " << to_expect_date[0] << "/" << to_expect_date[1] << "/" << to_expect_date[2] << endl;

    int age = calc_age(user_birth_date, to_expect_date);

    cout << endl;
    cout << "Birth date: " << user_birth_date[0] << "/" << user_birth_date[1] << "/" << user_birth_date[2] << endl;
    cout << "Expect date: " << to_expect_date[0] << "/" << to_expect_date[1] << "/" << to_expect_date[2] << endl;
    cout << "Age is: " << age << endl;
    cout << endl;

    return 0;
}

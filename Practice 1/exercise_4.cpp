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
    static int month_year[2];
    month_year[0] = request_month();
    cout << "\tyear: ";
    if (validate_year > 0) {
        bool is_correct_year;
        do {
            month_year[1] = cin_number_int();
            is_correct_year = (month_year[1] >= validate_year);
            if (!is_correct_year) cout << "Expected must be higher or equal birth year, please introduce valid year," << endl; 
        } while (!is_correct_year);
    }

    return month_year;
}

int * request_start_date(int validate_year = 0)
{
    static int month_year[2];
    month_year[0] = request_month();
    cout << "\tyear: ";
    month_year[1] = cin_number_int();

    return month_year;
}

int calc_month_diff(int * start_user_date, int * end_user_date)
{
    int month_diff;
    if (start_user_date[0] >= end_user_date[0]) month_diff = end_user_date[0];
    else month_diff = end_user_date[0] - start_user_date[0];    

    return month_diff;
}

int calc_age_diff(int * start_user_date, int * end_user_date)
{
    int age;
    age = end_user_date[1] - start_user_date[1] -1;
    cout << age << endl;
    if (end_user_date[0] >= start_user_date[0]) age++;
    return age;
}

int main()               
{
    int age;
    int month_diff;
    int *start_user_date;
    int *end_user_date;
    int save_age_for_prompt;
    cout << "Introduce start date: " << endl;
    cout << "> Start: " << endl;
    start_user_date = request_start_date();

    cout << "\tAge: ";
    age = cin_number_int();
    save_age_for_prompt = age;
    cout << "\n ----------------------" << endl;


    cout << "Introduce end date: " << endl;
    cout << "> End: " << endl;
    end_user_date = request_date_to_calc_age(start_user_date[1]);


    age += calc_age_diff(start_user_date, end_user_date);
    month_diff = calc_month_diff(start_user_date, end_user_date);


    cout << endl;
    cout << "Start age: " << save_age_for_prompt << endl;
    cout << "Start date: " << start_user_date[0] << "/" << start_user_date[1] << endl;
    cout << "End date: " << end_user_date[0] << "/" << end_user_date[1] << endl;
    cout << "Years: " << age << endl;
    cout << "Months: " << month_diff << endl;
    cout << endl;

    return 0;
}

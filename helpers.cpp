#include <iostream>
#include <limits> // To request strict number in cin (not allowed letters) numeric_limits<streamsize>..

using namespace std;

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

long calc_factorial(float number) 
{
   int i, result = 1;
   for(i = number; i>1; i--)
      result *= i;
   return result;
}

int get_longest_string_in_array(string *array_of_strings)
{
    int count;
    int total_elements_in_array = sizeof(array_of_strings)/sizeof(array_of_strings[0]);
    int longest_string_value = array_of_strings[0].size();
    for (int i = 1; i < total_elements_in_array; i++) {
        if (array_of_strings[i].size() > longest_string_value) longest_string_value = array_of_strings[i].size();
    }
    return longest_string_value;
}

string generate_random_number_by_length(int random_number_length)
{
    int count_length = random_number_length;
    int pseudo_random_number;
    string random_number = "";
    int position_to_get_from_generated_number;
    // Don't use srand inside the loop, use it only once, e.g. at the start of main(). And srand() is exactly how you reset this.
    srand(time(NULL));

    do {
        // The rand() function does not generate a truly random number; it actually returns the next pseudo-random value 
        // in a sequence of values ranging from 0 to RAND_MAX. You can change the starting point in that sequence using srand().
        pseudo_random_number = rand();
        int position_to_get_from_generated_number = 2;
        // Generates dynamical position to get from pseudo generated rand number
        // It means the position from each single random number to get from each pseudo random generated number depending if even or odd number or loop
        if (pseudo_random_number % 2 || count_length % 2) position_to_get_from_generated_number += 2; // even pseudo_random_number, position to get 2 OR  even loop, plus 2 to the position
        else position_to_get_from_generated_number += 3; // odd pseudo_random_number, position to get 3 || odd loop, plus 3 to the position

        random_number += to_string(pseudo_random_number)[position_to_get_from_generated_number];
        count_length -= 1;
    } while (count_length > 0);

    return random_number;
}

string custom_rand_number_from_0_to(int random_value_range_to, bool is_included = true)
{
    string random_number = "";
    int count_length = to_string(random_value_range_to).size();
    int pseudo_random_number;
    string pseudo_random_number_str;
    char random_number_as_char;
    string random_number_to_check_as_str;
    int random_number_to_check_as_int;
    // Don't use srand inside the loop, use it only once, e.g. at the start of main(). And srand() is exactly how you reset this.
    srand(time(NULL));

    do {
        // The rand() function does not generate a truly random number; it actually returns the next pseudo-random value 
        // in a sequence of values ranging from 0 to RAND_MAX. You can change the starting point in that sequence using srand().
        pseudo_random_number = rand();
        pseudo_random_number_str = to_string(pseudo_random_number);
        int position_to_get_from_generated_number = 2;
        // Generates dynamical position to get from pseudo generated rand number
        // It means the position from each single random number to get from each pseudo random generated number depending if even or odd number or loop
        if (pseudo_random_number % 2 || count_length % 2) position_to_get_from_generated_number += 2; // even pseudo_random_number, position to get 2 OR  even loop, plus 2 to the position
        else position_to_get_from_generated_number += 3; // odd pseudo_random_number, position to get 3 || odd loop, plus 3 to the position

        random_number_as_char = pseudo_random_number_str[position_to_get_from_generated_number];
        random_number_to_check_as_str = random_number + random_number_as_char;
        random_number_to_check_as_int = stoi(random_number_to_check_as_str);


        if (is_included) {
            if (random_number_to_check_as_int >= 0 && random_number_to_check_as_int <= random_value_range_to)
            {
                random_number += random_number_as_char;
                count_length -= 1;
            }
        }
        else {
            if (random_number_to_check_as_int > 0 && random_number_to_check_as_int < random_value_range_to)
            {
                random_number += random_number_as_char;
                count_length -= 1;
            }
        }
    } while (count_length > 0);


    return random_number;
}


// To develop


string custom_rand_number_from_0_to(int random_value_range_to, bool is_included = true)
{
    string random_number = "";
    int count_length = to_string(random_value_range_to).size();
    string pseudo_random_number_str;
    char random_number_as_char;
    int random_number_to_check_as_int;
    // Don't use srand inside the loop, use it only once, e.g. at the start of main(). And srand() is exactly how you reset this.
    srand(time(NULL));

    do {
        // The rand() function does not generate a truly random number; it actually returns the next pseudo-random value 
        // in a sequence of values ranging from 0 to RAND_MAX. You can change the starting point in that sequence using srand().
        pseudo_random_number_str = to_string(rand());
        random_number_as_char = pseudo_random_number_str[pseudo_random_number_str.size()/2];
        random_number_to_check_as_int = stoi(random_number + random_number_as_char);

        if (is_included) {
            if (random_number_to_check_as_int >= 0 && random_number_to_check_as_int <= random_value_range_to)
            {
                random_number += random_number_as_char;
                count_length -= 1;
            }
        }
        else {
            if (random_number_to_check_as_int > 0 && random_number_to_check_as_int < random_value_range_to)
            {
                random_number += random_number_as_char;
                count_length -= 1;
            }
        }
    } while (count_length > 0);


    return random_number;
}


// Not support  minimum range more than 2 characters > 10
string custom_rand_by_range(int random_value_range_from, int random_value_range_to, bool is_included = true)
{
    // The rand() function does not generate a truly random number; it actually returns the next pseudo-random value 
    // in a sequence of values ranging from 0 to RAND_MAX. You can change the starting point in that sequence using srand().
    // Don't use srand inside the loop, use it only once, e.g. at the start of main(). And srand() is exactly how you reset this.
    int count_length = to_string(random_value_range_to).size();
    int pseudo_random_number;
    string pseudo_random_number_as_str;
    srand(time(NULL));

    int random_number_char_pos;

    string random_number = "";
    do {
        pseudo_random_number = rand();
        pseudo_random_number_as_str = to_string(pseudo_random_number);

        // // if (pseudo_random_number < 0) pseudo_random_number *= -1;
        // int position_to_get_from_generated_number = 0;
        // // Generates dynamical position to get from pseudo generated rand number
        // // It means the position from each single random number to get from each pseudo random generated number depending if even or odd number or loop
        // if (pseudo_random_number % 2 || count_length % 2) position_to_get_from_generated_number += 2; // even pseudo_random_number, position to get 2 OR  even loop, plus 2 to the position
        // else position_to_get_from_generated_number += 3; // odd pseudo_random_number, position to get 3 || odd loop, plus 3 to the position

        // char random_number_as_char = pseudo_random_number_as_str[position_to_get_from_generated_number];
        
        char random_number_as_char = pseudo_random_number_as_str[5];
        string random_number_to_check_as_str = random_number + random_number_as_char;
        int random_number_to_check_as_int = stoi(random_number_to_check_as_str);

        if (is_included) {
            if (random_number_to_check_as_int >= random_value_range_from && random_number_to_check_as_int <= random_value_range_to)
            {
                random_number += random_number_as_char;
                count_length -= 1;
            }
        }
        else {
            if (random_number_to_check_as_int > random_value_range_from && random_number_to_check_as_int < random_value_range_to)
            {
                random_number += random_number_as_char;
                count_length -= 1;
            }
        }
    } while (count_length > 0);


    return random_number;
}




// Improve function to get random number BETWEEN numbers (in range)

string custom_rand_by_range(int random_value_range_from, int random_value_range_to, bool is_included = true)
{
    string from_range_number_str = to_string(random_value_range_from);
    string to_range_number_str =  to_string(random_value_range_to);

    int count_length = to_string(random_value_range_to).size();
    int pseudo_random_number;
    string pseudo_random_number_str;
    // Don't use srand inside the loop, use it only once, e.g. at the start of main(). And srand() is exactly how you reset this.
    srand(time(NULL));


    char random_number_char;
    string random_number_to_check_str;
    int random_number_to_check_and_add_int;

    string random_number_to_check_and_add_str = "";
    

    string random_number;
    do {
        // The rand() function does not generate a truly random number; it actually returns the next pseudo-random value 
        // in a sequence of values ranging from 0 to RAND_MAX. You can change the starting point in that sequence using srand().
        pseudo_random_number = rand();
        pseudo_random_number_str = to_string(pseudo_random_number);
        random_number_char = pseudo_random_number_str[pseudo_random_number_str.size()/2];

        cout << random_number_to_check_and_add_str << endl;
        cout << "aqi " << random_number_to_check_and_add_str.size() << endl;
        
        if (from_range_number_str.size() > 1 && random_number.size() < from_range_number_str.size()) { // Ensure first loop initialization minimum range

            cout << "entro " << endl;
            int random_number_int = stoi(to_string(random_number_char));
            int number_to_check_from_input = stoi(to_string(from_range_number_str[random_number_to_check_and_add_str.size()]));
            
            if (random_number_int <= number_to_check_from_input) {
                random_number_to_check_and_add_str += random_number_char;
            }
        }
        else (random_number.size() >= from_range_number_str.size()) { // Other case, other loops or number with lenght from 0-9 to... XXX, use this line
            random_number_to_check_str = random_number + random_number_char;
        }




        cout << "----" << endl;
        


        random_number_to_check_and_add_int = stoi(random_number_to_check_and_add_str);

        if (is_included) {
            if (random_number_to_check_and_add_int >= random_value_range_from && random_number_to_check_and_add_int <= random_value_range_to)
            {
                random_number += random_number_to_check_str;
                count_length -= random_number_to_check_str.size();
            }
        }
        else {
            cout << random_number_to_check_str << endl;
            cout << random_number << endl;
            if (random_number_to_check_and_add_int > random_value_range_from && random_number_to_check_and_add_int < random_value_range_to)
            {
                random_number += random_number_to_check_str;
                count_length -= random_number_to_check_str.size();
            }
        }

    } while (count_length > 0);

    
    cout << random_number << endl;

    // return random_number;
}
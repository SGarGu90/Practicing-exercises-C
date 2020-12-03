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

int generate_random_number_by_length(int random_number_length)
{
    // The rand() function does not generate a truly random number; it actually returns the next pseudo-random value 
    // in a sequence of values ranging from 0 to RAND_MAX. You can change the starting point in that sequence using srand().
    // Don't use srand inside the loop, use it only once, e.g. at the start of main(). And srand() is exactly how you reset this.
    int count_length = random_number_length;
    int pseudo_random_number;
    string random_number = "";
    int position_to_get_from_generated_number;
    srand(time(NULL));

    do {
        pseudo_random_number = rand();
        // if (pseudo_random_number < 0) pseudo_random_number *= -1;
        int position_to_get_from_generated_number = 0;
        // Generates dynamical position to get from pseudo generated rand number
        // It means the position from each single random number to get from each pseudo random generated number depending if even or odd number or loop
        if (pseudo_random_number % 2 || count_length % 2) position_to_get_from_generated_number += 2; // even pseudo_random_number, position to get 2 OR  even loop, plus 2 to the position
        else position_to_get_from_generated_number += 3; // odd pseudo_random_number, position to get 3 || odd loop, plus 3 to the position

        // Add single random number selected to final random number
        random_number += to_string(pseudo_random_number)[position_to_get_from_generated_number];

        // cout << "generated number " << pseudo_random_number << endl;
        // cout << "Position to get " << position_to_get_from_generated_number << endl;
        // cout << "Generated number " << random_number << endl;
        count_length -= 1;
    } while (count_length > 0);


    return stoi(random_number);
}
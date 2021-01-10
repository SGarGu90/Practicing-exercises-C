#include <iostream>
#include <limits> // To request strict number in cin (not allowed letters) numeric_limits<streamsize>..
#include <vector>

using namespace std;

float cin_number_float(int insert_count_number = -1)
{
    if (insert_count_number != -1) cout << "Insert (float): " << insert_count_number + 1 << endl;
        float input;
        while (!(cin >> input)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entered value is not a number, please introduce number\n";
        }
    return input;
}

int cin_number_int(int insert_count_number = -1)
{
    if (insert_count_number != -1) cout << "Insert (int): " << insert_count_number + 1 << endl;
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

void print_vector(vector<int> vector_numbers, string text = "Input vector is: ")
{
  if (text != "") cout << text << "{ ";
  for (int num_pos = 0; num_pos < vector_numbers.size(); num_pos++) {
    if (num_pos != vector_numbers.size() - 1) cout << vector_numbers[num_pos] << ", ";
    else cout << vector_numbers[num_pos];
  }
  cout << " }" << endl;
}

auto merge_vectors_by_index(vector<int> vector_a, vector<int> vector_b, int v_pos_index = -1) {
  vector<int> result_vector;
  int result_vector_length = vector_a.size() + vector_b.size();
  int count_used_from_a = 0;
  int count_used_from_b = 0;
  int current_number_to_insert;
  bool is_vector_b_filled_in_a;

  for (int v_result_pos = 0; v_result_pos < result_vector_length; v_result_pos++) {
    is_vector_b_filled_in_a = (count_used_from_b >= vector_b.size());
    if (v_pos_index == -1) {
      if (v_result_pos < vector_a.size()) {
        current_number_to_insert = vector_a[count_used_from_a];
        count_used_from_a++;
      } else {
        current_number_to_insert = vector_b[count_used_from_b];
        count_used_from_b++;
      }
    } else {
      if (v_result_pos < v_pos_index) {
        current_number_to_insert = vector_a[count_used_from_a];
        count_used_from_a++;
      } else if (v_result_pos >= v_pos_index) {
        if (!is_vector_b_filled_in_a) {
          current_number_to_insert = vector_b[count_used_from_b];
          count_used_from_b++;
        }
        else if (is_vector_b_filled_in_a){
          current_number_to_insert = vector_a[count_used_from_a];
          count_used_from_a++;
        }
      }
    }

    result_vector.insert(result_vector.end(), current_number_to_insert);
  }
  return result_vector;
}
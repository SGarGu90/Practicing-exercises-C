#include <iostream>
#include <vector>
#include <string>
#include <limits> // To request strict number in cin (not allowed letters) numeric_limits<streamsize>..
#include<cmath>

using namespace std;

string custom_rand_number_from_0_to(int random_value_range_to, bool is_included = true)
{
  string random_number = "";
  int count_length = to_string(random_value_range_to).size();
  int pseudo_random_number;
  string pseudo_random_number_str;
  char random_number_as_char;
  string random_number_to_check_as_str;
  int random_number_to_check_as_int;

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

void populate_vector_with_customized_random_numbers_by_length(vector<int> &vector_numbers)
{
  int new_number;

  cout << "Insert vector length (N). { ...n, ...(N) }" << endl;
  int vector_length = cin_number_int();
  cout << "Result vector: {...rand[0-X], ...Rand[0-X](" << vector_length << ")}" << endl;
  cout << "\n";

  cout << "Vector values will be generated for you." << endl;
  cout << "Set new maximum value for random numbers or 0 for default (100)" << endl;
  cout << "rand[0-100]. X(100)? = ";
  int vector_max_value = cin_number_int();
  cout << endl;
  if (vector_max_value == 0) vector_max_value = 100;
  cout << "Creating vector: {...rand[0-" << vector_max_value << "], ...Rand[0-" << vector_max_value << "](" << vector_length << ")} ..." << endl;

  // Don't use srand inside the loop, use it only once, e.g. at the start of main(). And srand() is exactly how you reset this.
  srand(time(NULL));
  for (int number_pos = 0; number_pos < vector_length; number_pos++) {
    new_number = stoi(custom_rand_number_from_0_to(vector_max_value));
    vector_numbers.insert(vector_numbers.end(), new_number);
  }
}

void print_vector_numbers(vector<int> vector, string text = "Input vector is: ")
{
  if (text != "") cout << text << "{ ";
  for (int v_pos = 0; v_pos < vector.size(); v_pos++) {
    if (v_pos != vector.size() - 1) cout << vector[v_pos] << ", ";
    else cout << vector[v_pos];
  }
  cout << " }" << endl;
}

void print_vector_strings(vector<string> vector, string text = "Input vector is: ")
{
  if (text != "") cout << text << "{ ";
  for (int v_pos = 0; v_pos < vector.size(); v_pos++) {
    if (v_pos != vector.size() - 1) cout << vector[v_pos] << ", ";
    else cout << vector[v_pos];
  }
  cout << " }" << endl;
}

int find_vector_value(vector<int> vector_numbers, string filter)
{
  int value = vector_numbers[0];
  for (int v_pos = 1; v_pos < vector_numbers.size(); v_pos++) {
    if (filter == "max" && value < vector_numbers[v_pos]) value = vector_numbers[v_pos];
    else if (filter == "min" && value > vector_numbers[v_pos]) value = vector_numbers[v_pos];
  }

  return value;
}

void configure_X_axis_histogram_range_values_by_input_vector(vector<string> &x_axis_intervals, vector<int> vector_numbers)
{
  int vector_length = vector_numbers.size();
  int k_classes = round(sqrt(vector_length));

  int min_vector_value = find_vector_value(vector_numbers, "min");
  int max_vector_value = find_vector_value(vector_numbers, "max");

  string intervalAsStr;
  for (int range_interval = min_vector_value; range_interval <= (max_vector_value + k_classes); range_interval += k_classes) {
    intervalAsStr = std::to_string(range_interval) + "-" + std::to_string(range_interval + k_classes);
    x_axis_intervals.insert(x_axis_intervals.end(), intervalAsStr);
  }
}

void configure_Y_axis_frequencies(vector<int> &y_axis_frequencies, vector<string> x_axis_intervals, vector<int> vector_numbers)
{
  string intervalAsStr;

  for (int interval_v_pos = 0; interval_v_pos < x_axis_intervals.size(); interval_v_pos ++) {
    intervalAsStr = x_axis_intervals[interval_v_pos];
  }
}

int main()
{
  vector<int> vector_numbers;
  populate_vector_with_customized_random_numbers_by_length(vector_numbers);
  print_vector_numbers(vector_numbers, "Generated vector: ");

  vector<string> x_axis_intervals;
  configure_X_axis_histogram_range_values_by_input_vector(x_axis_intervals, vector_numbers);
  print_vector_strings(x_axis_intervals, "Intervals: ");

  vector<int> y_axis_frequencies;
  configure_Y_axis_frequencies(y_axis_frequencies, x_axis_intervals, vector_numbers);


  return 0;
}

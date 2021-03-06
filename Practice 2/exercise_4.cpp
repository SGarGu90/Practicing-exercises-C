#include <iostream>
#include <vector>
#include <string>
#include <limits> // To request strict number in cin (not allowed letters) numeric_limits<streamsize>..
#include<cmath>
#include <iomanip> // use set() to generate empty spaces between text
#include <algorithm>

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
  int DEFAULT_MAX_RAND_VALUE = 100;
  int new_number;

  cout << "Insert vector length (N). { ...n, ...(N) }" << endl;
  int vector_length = cin_number_int();
  cout << "Result vector: {...rand[0-X], ...Rand[0-X](" << vector_length << ")}" << endl;
  cout << "\n";

  cout << "Vector values will be generated for you." << endl;
  cout << "Set new maximum value for random numbers or 0 for default "<< "(" << DEFAULT_MAX_RAND_VALUE << ")" << endl;
  cout << "rand[0-" << DEFAULT_MAX_RAND_VALUE << "]. X(" << DEFAULT_MAX_RAND_VALUE << ")? = ";
  int vector_max_value = cin_number_int();
  cout << endl;
  if (vector_max_value == 0) vector_max_value = DEFAULT_MAX_RAND_VALUE;
  cout << "Creating vector: {...rand[0-" << vector_max_value << "], ...Rand[0-" << vector_max_value << "]}(" << vector_length << ") ..." << endl;

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


int total_sum(vector<int> vector)
{
  int total_sum;
  for (int v_pos = 0; v_pos < vector.size(); v_pos++) total_sum+=vector[v_pos];
  return total_sum;
}

double calc_mean(vector<int> vector)
{
  return (total_sum(vector) / vector.size());
}

int calc_median(vector<int> vector)
{
  int vector_length = vector.size();
  sort(vector.begin(), vector.end());
  double vector_middle_val = vector_length/2;
  return vector_length % 2 == 0 ? (vector[vector_middle_val] + vector[vector_middle_val-1]) / 2 : vector[vector_middle_val];
}

int calc_mode(vector<int> vector)
{
  int first_number = vector[0];
  int vector_length = vector.size();
  int mode = first_number;
  int count = 1;
  int counted = 1;

  for (int v_pos = 1; v_pos < vector_length; v_pos++) {
    if (vector[v_pos] == first_number) count++;
    else {
      if (count > counted) counted = count;mode = first_number;
      count = 1;
      first_number = vector[v_pos];
    }
  }
  return mode;
}

double calc_variance(vector<int> vector, double mean)
{
  double variance = 0;
  for( int n = 0; n < vector.size(); n++ ) {
    variance += (vector[n] - mean) * (vector[n] - mean);
  }
  variance = (variance / vector.size());
  return variance;
}

double calc_std_dev(double variance)
{
  return sqrt(variance);
}

int make_statistical_analysis(vector<int> vector_numbers)
{
  double mean = calc_mean(vector_numbers);
  int median = calc_median(vector_numbers);
  int mode = calc_mode(vector_numbers);
  double variance = calc_variance(vector_numbers, mean);
  double std_dev = calc_std_dev(variance);

  cout << "Mean:     " << mean << endl;
  cout << "Median:   " << median << endl;
  cout << "Mode:     " << mode << endl;
  cout << "Variance: " << variance << endl;
  cout << "std_dev:  " << std_dev << endl;
}

int main()
{
  vector<int> vector_numbers;
  populate_vector_with_customized_random_numbers_by_length(vector_numbers);
  print_vector_numbers(vector_numbers, "Generated vector: ");

  make_statistical_analysis(vector_numbers);

  return 0;
}

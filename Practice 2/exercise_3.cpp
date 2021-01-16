#include <iostream>
#include <vector>
#include <string>
#include <limits> // To request strict number in cin (not allowed letters) numeric_limits<streamsize>..
#include<cmath>
#include <iomanip> // use set() to generate empty spaces between text

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
  int DEFAULT_MAX_RAND_VALUE = 50;
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

void configure_Y_axis_frequencies(vector<int> &frequencies, vector<string> x_axis_intervals, vector<int> vector_numbers)
{
  string intervalAsStr;
  string min_interval_value;
  string max_interval_value;
  bool isProcessingMinValue;
  int interval_freq;

  for (int interval_v_pos = 0; interval_v_pos < x_axis_intervals.size(); interval_v_pos ++) {
    intervalAsStr = x_axis_intervals[interval_v_pos];
    isProcessingMinValue = true;
    min_interval_value = "";
    max_interval_value = "";
    interval_freq = 0;

    for (int str_pos = 0; str_pos < intervalAsStr.size(); str_pos++) {
      if (intervalAsStr[str_pos] == '-') isProcessingMinValue = false;
      else if (isProcessingMinValue) min_interval_value.push_back(intervalAsStr[str_pos]);
      else if (!isProcessingMinValue) max_interval_value.push_back(intervalAsStr[str_pos]);
    }

    for (int num_v_pos = 0; num_v_pos < vector_numbers.size(); num_v_pos++) {
      if (stoi(min_interval_value) <= vector_numbers[num_v_pos] && vector_numbers[num_v_pos] <= stoi(max_interval_value)) interval_freq++;
    }

    frequencies.insert(frequencies.end(), interval_freq);
  }
}

int print_Y_axis_frequencies(int current_row_n, int total_rows, int &SPACING_ADAPT_FREQ_NUMS)
{
  SPACING_ADAPT_FREQ_NUMS = 1;
  if (total_rows > 9 && current_row_n <= 9) SPACING_ADAPT_FREQ_NUMS++;
  else if (total_rows > 99 && current_row_n <= 99) SPACING_ADAPT_FREQ_NUMS++;
  else if (total_rows > 999 && current_row_n <= 999) SPACING_ADAPT_FREQ_NUMS++;
  else if (total_rows > 9999 && current_row_n <= 9999) SPACING_ADAPT_FREQ_NUMS++;
  else if (total_rows > 99999 && current_row_n <= 99999) SPACING_ADAPT_FREQ_NUMS++;
  if (current_row_n != 0) cout << current_row_n << setw(SPACING_ADAPT_FREQ_NUMS) << " " << "|";
  return SPACING_ADAPT_FREQ_NUMS;
}

void print_separator(vector<string> x_axis_intervals)
{
  for (int i = 0; i < x_axis_intervals.size()*8; i++) cout << "-";
  cout << endl;
}

void print_intervals(vector<string> x_axis_intervals, int SPACING_ADAPT_FREQ_NUMS)
{
  int WIDTH_SPACING = 2;
  int SPACING_FROM_PRINT_FREQ_NUMS = 3;
  cout << setw(SPACING_FROM_PRINT_FREQ_NUMS + SPACING_ADAPT_FREQ_NUMS) << " ";
  for (int x_axis_pos = 0; x_axis_pos < x_axis_intervals.size(); x_axis_pos++)
    cout << x_axis_intervals[x_axis_pos] << setw(WIDTH_SPACING) << " ";
  cout << endl;
}

void print_X_axis_intervals(int current_row_n, vector<string> x_axis_intervals, int SPACING_ADAPT_FREQ_NUMS)
{
  print_separator(x_axis_intervals);
  print_intervals(x_axis_intervals, SPACING_ADAPT_FREQ_NUMS);
}

void set_correct_spacing_between_cols(int char_pos, vector<string> x_axis_intervals, int current_row_n, vector<int> frequencies)
{
  int SPACING_ADAPT_FREQ_DOTS = 2;
  string currentIntervalAsStr = x_axis_intervals[char_pos];

  string current_min_interval_value;
  string current_max_interval_value;
  bool isProcessingMinValue = true;
  for (int str_pos = 0; str_pos < currentIntervalAsStr.size(); str_pos++) {
    if (currentIntervalAsStr[str_pos] == '-') isProcessingMinValue = false;
      else if (isProcessingMinValue) current_min_interval_value.push_back(currentIntervalAsStr[str_pos]);
      else if (!isProcessingMinValue) current_max_interval_value.push_back(currentIntervalAsStr[str_pos]);
  }

  bool isExistValue = false;
  isExistValue = (current_row_n <= frequencies[char_pos]);

  if (isExistValue) cout << setw(1 + current_min_interval_value.size()) << " " << "*" << setw(current_max_interval_value.size() + 1) << " ";
  else cout << setw(1 + current_min_interval_value.size()) << " " << " " << setw(current_max_interval_value.size() + 1) << " ";
}

void print_histogram_dots(int current_row_n, vector<string> x_axis_intervals, vector<int> frequencies, int SPACING_ADAPT_FREQ_NUMS)
{
  int total_chars_per_line = x_axis_intervals.size();
  int max_vector_value = find_vector_value(frequencies, "max");

  for (int char_pos = 0; char_pos < total_chars_per_line; char_pos++) {
    set_correct_spacing_between_cols(char_pos, x_axis_intervals, current_row_n, frequencies);
  }

  cout << endl;
}

void print_histogram(vector<string> x_axis_intervals, vector<int> frequencies)
{
    int total_rows = find_vector_value(frequencies, "max");
    int SPACING_ADAPT_FREQ_NUMS;

    for(int current_row_n = total_rows; current_row_n >= 0; current_row_n--) {
      bool is_last_row = (current_row_n == 0);

      print_Y_axis_frequencies(current_row_n, total_rows, SPACING_ADAPT_FREQ_NUMS);
      if (!is_last_row) print_histogram_dots(current_row_n, x_axis_intervals, frequencies, SPACING_ADAPT_FREQ_NUMS);
      if (is_last_row) print_X_axis_intervals(current_row_n, x_axis_intervals, SPACING_ADAPT_FREQ_NUMS);
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
  print_vector_numbers(y_axis_frequencies, "Frequencies: ");

  print_histogram(x_axis_intervals, y_axis_frequencies);

  return 0;
}

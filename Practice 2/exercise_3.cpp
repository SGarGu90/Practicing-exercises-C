#include <iostream>
#include <vector>
#include <string>
#include <limits> // To request strict number in cin (not allowed letters) numeric_limits<streamsize>..

using namespace std;

void print_vector(vector<int> vector_numbers, string text = "Input vector is: ")
{
  if (text != "") cout << text << "{ ";
  for (int num_pos = 0; num_pos < vector_numbers.size(); num_pos++) {
    if (num_pos != vector_numbers.size() - 1) cout << vector_numbers[num_pos] << ", ";
    else cout << vector_numbers[num_pos];
  }
  cout << " }" << endl;
}

string generate_random_number_by_length(int random_number_length)
{
    int count_length = random_number_length;
    int pseudo_random_number;
    string random_number = "";
    int position_to_get_from_generated_number;

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

void request_vector_numbers(vector<int> &vector_numbers) {
  int new_number;

  cout << "Insert vector length" << endl;
  int vector_length = cin_number_int();

  for (int number_pos = 0; number_pos < vector_length; number_pos++)
  {
    new_number = stoi(generate_random_number_by_length(1));
    vector_numbers.insert(vector_numbers.end(), new_number);
  }
}

int main()
{
  // Don't use srand inside the loop, use it only once, e.g. at the start of main(). And srand() is exactly how you reset this.
  srand(time(NULL));
  vector<int> vector_numbers;
  request_vector_numbers(vector_numbers);

  print_vector(vector_numbers, "Result vector is: ");

  return 0;
}

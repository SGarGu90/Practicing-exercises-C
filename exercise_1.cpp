#include <iostream>
#include <vector>
#include <string>
#include <limits> // To request strict number in cin (not allowed letters) numeric_limits<streamsize>..

using namespace std;

void swap_vector_numbers(vector<int> &vector_numbers, int old_pos, int new_pos)
{
  int number_to_swap = vector_numbers[old_pos];
  vector_numbers[old_pos] = vector_numbers[new_pos];
  vector_numbers[new_pos] = number_to_swap;
}

void print_vector(vector<int> vector_numbers, string text = "")
{
  if (text != "") cout << text << "{ ";
  for (int num_pos = 0; num_pos < vector_numbers.size(); num_pos++) {
    if (num_pos != vector_numbers.size() - 1) cout << vector_numbers[num_pos] << ", ";
    else cout << vector_numbers[num_pos];
  }
  cout << " }" << endl;
}

void sort_vector(vector<int> &vector_numbers, string orientation = "")
{
  bool is_sorted;
  bool is_required_swap;
  int old_pos;
  int new_pos;
  do {
    is_sorted = true;
    for (int i = 1; i < vector_numbers.size(); i++) {
      is_required_swap = (
          orientation == "ASC" && vector_numbers[i - 1] > vector_numbers[i] ||
          orientation == "DES" && vector_numbers[i - 1] < vector_numbers[i]
      );

      if (is_required_swap) {
        old_pos = i - 1;
        new_pos = i;
        swap_vector_numbers(vector_numbers, old_pos, new_pos);
        is_sorted = false;
      }
    }
  } while (!is_sorted);
}

int cin_number_int(int insert_count_number = -1)
{
  if (insert_count_number != -1) cout << "Insert number: " << insert_count_number + 1 << endl;
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
  char answer = 'y';

  cout << "Insert vector length" << endl;
  int vector_length = cin_number_int();

  for (int number_pos = 0; number_pos < vector_length; number_pos++)
  {
    new_number = cin_number_int(number_pos);
    vector_numbers.insert(vector_numbers.end(), new_number);
  }
}

int main()
{
  vector<int> vector_numbers;
  request_vector_numbers(vector_numbers);
  print_vector(vector_numbers, "Input vector is: ");

  sort_vector(vector_numbers, "ASC");
  print_vector(vector_numbers, "Vector ordered ASC is: ");

  sort_vector(vector_numbers, "DES");
  print_vector(vector_numbers, "Vector ordered DES is: ");
  return 0;
}

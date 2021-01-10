#include <iostream>
#include <vector>
#include <string>
#include <limits> // To request strict number in cin (not allowed letters) numeric_limits<streamsize>..

using namespace std;

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
  vector<int> vector_numbers_a;
  vector<int> vector_numbers_b;

  cout << "First vector config: " << endl;
  request_vector_numbers(vector_numbers_a);
  cout << "Second vector config: " << endl;
  request_vector_numbers(vector_numbers_b);



  return 0;
}
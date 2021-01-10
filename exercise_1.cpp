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

int main()
{
  vector<int> vector_numbers;
  int new_number;
  char answer = 'y';

  cout << "Insert vector length" << endl;
  int vector_length = cin_number_int();

  return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <limits> // To request strict number in cin (not allowed letters) numeric_limits<streamsize>..
#include<cmath>
#include <iomanip> // use set() to generate empty spaces between text
#include <algorithm>

using namespace std;

string cin_string()
{
  string input;
  cin >> input;
  return input;
}

string generate_password(vector<string> vector)
{
  string single_str;
  for (int str_pos = 0; str_pos < vector.size(); str_pos++) single_str+=vector[str_pos];

  bool is_exist_char_in_str;
  string password;
  for (int str_pass_pos = 0; str_pass_pos < single_str.size(); str_pass_pos++) {
    for (int str_in_vector = 0; str_in_vector < vector.size(); str_in_vector++) {
      is_exist_char_in_str = str_pass_pos < vector[str_in_vector].size();
      if (is_exist_char_in_str) password.push_back(vector[str_in_vector][str_pass_pos]);
    }
  }
  return password;
}

int main()
{
  cout << "Insert string (1): ";
  string str_input_1 = cin_string();
  cout << endl;

  cout << "Insert string (2): ";
  string str_input_2 = cin_string();
  cout << endl;

  cout << "Insert string (3): ";
  string str_input_3 = cin_string();
  cout << endl;

  string single_string = str_input_1 + str_input_2 + str_input_3;
  cout << single_string << endl;

  vector<string> input_strings_vector;
  input_strings_vector.push_back(str_input_1);
  input_strings_vector.push_back(str_input_2);
  input_strings_vector.push_back(str_input_3);

  string password = generate_password(input_strings_vector);

  cout << "Password is: " << password << endl;

  return 0;
}

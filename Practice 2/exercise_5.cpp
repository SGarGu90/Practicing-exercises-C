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

  vector<string> str_vector;
  str_vector.push_back(str_input_1);
  str_vector.push_back(str_input_2);
  str_vector.push_back(str_input_3);

  string password;
  for (int str_pos = 0; str_pos < single_string.size(); str_pos++) {
    for (int v_pos = 0; v_pos < str_vector.size(); v_pos++) {
      if (str_vector[v_pos][str_pos]) password.push_back(str_vector[v_pos][str_pos]);
    }
  }

  cout << "Password is: " << password << endl;

  return 0;
}

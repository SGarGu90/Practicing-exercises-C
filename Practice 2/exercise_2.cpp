#include <iostream>
#include <vector>
#include <string>
#include <limits> // To request strict number in cin (not allowed letters) numeric_limits<streamsize>..

using namespace std;

vector merge_vectors_by_index(vector<int> &vector_a, vector<int> &vector_b, int v_pos_index_a) {
  vector<int> result_vector;
  int result_vector_length = vector_a.size() + vector_b.size();
  int count_used_from_a = 0;
  int count_used_from_b = 0;
  int current_number_to_insert;
  bool is_vector_b_filled_in_a;

  for (int v_result_pos = 0; v_result_pos < result_vector_length; v_result_pos++) {
    is_vector_b_filled_in_a = (count_used_from_b >= vector_b.size());
    if (v_result_pos < v_pos_index_a) {
      current_number_to_insert = vector_a[count_used_from_a];
      count_used_from_a++;
    } else if (v_result_pos >= v_pos_index_a) {
      if (!is_vector_b_filled_in_a) {
        current_number_to_insert = vector_b[count_used_from_b];
        count_used_from_b++;
      }
      else if (is_vector_b_filled_in_a){
        current_number_to_insert = vector_a[count_used_from_a];
        count_used_from_a++;
      }
    }
    result_vector.insert(result_vector.end(), current_number_to_insert);
  }
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
  vector<int> vector_a;
  vector<int> vector_b;

  cout << "First vector config: " << endl;
  request_vector_numbers(vector_a);
  cout << "Second vector config: " << endl;
  request_vector_numbers(vector_b);

  cout << "Set position to insert Vector b in vector a" << endl;
  int v_pos_index_a = cin_number_int() - 1;

  vector<int> result_vector;
  result_vector = merge_vectors_by_index(vector_a, vector_b, v_pos_index_a);
  print_vector(result_vector, "Result vector is: ");

  return 0;
}

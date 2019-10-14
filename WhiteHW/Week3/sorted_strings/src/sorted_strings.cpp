#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class SortedStrings {
public:
  void AddString(const string& s) {
	  array.push_back(s);
  }
  vector<string> GetSortedStrings() {
	  sort(array.begin(), array.end());
	  return array;
  }
private:
  vector<string> array;
};

void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}

int main() {
	SortedStrings strings;
	strings.AddString("first");
	strings.AddString("third");
	strings.AddString("second");
	PrintSortedStrings(strings);

	strings.AddString("second");
	PrintSortedStrings(strings);

	return 0;
}
//Compile error: b"/tmp/submissionhzwm0gjx/sorted_strings.cpp:
//In function 'void PrintSortedStrings(SortedStrings&)'
//:\n/tmp/submissionhzwm0gjx/sorted_strings.cpp:48:6: error:
//redefinition of 'void PrintSortedStrings(SortedStrings&)'
//\n void PrintSortedStrings(SortedStrings& strings) {\n
//^~~~~~~~~~~~~~~~~~\ncompilation terminated due to -Wfatal-errors.\n"

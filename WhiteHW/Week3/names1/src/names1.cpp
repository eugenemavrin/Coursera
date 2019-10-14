
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Person {
public:
	Person(const string& first_name, const string& last_name, const int year) {
		story_first_name[year] = first_name;
		story_last_name[year] = last_name;
	}
  void ChangeFirstName(int year, const string& first_name) {
	  if (story_first_name.begin()->first <= year || story_last_name.begin()->first <= year)
		  story_first_name[year] = first_name;
  }

  void ChangeLastName(int year, const string& last_name) {
	  if (story_first_name.begin()->first <= year || story_last_name.begin()->first <= year)
		  story_last_name[year] = last_name;
  }

  string GetFullName(int year)  const{
	  return FormattedReturn(GetFloorElement(year, story_first_name), GetFloorElement(year, story_last_name));
  }
  string GetFullNameWithHistory(int year) const {
	  return FormattedReturn(GetFloorElementWithHistory(year, story_first_name), GetFloorElementWithHistory(year, story_last_name));
    }

private:
  map<int, string> story_first_name;
  map<int, string> story_last_name;

  string GetFloorElement (int n, map<int, string> array) const {
	  string s = "";
	  for (auto & elem : array) {
		  if (elem.first <= n) {
			  s = elem.second;
		  }
	  }
	  return s;
  }
  string GetFloorElementWithHistory (int n, map<int, string> array) const {
	  string s = "";
	  vector <string> story;
	  for (auto & elem : array) {
		  if (elem.first <= n) {
			  story.push_back(s);
			  s = elem.second;
		  }
	  }
	  s = s + " (";
	  bool flag = false;
	  reverse(story.begin(), story.end());
	  for (const auto& l : story) {
		  if (l != "" && count(story.begin(), story.end(), l) < 2) {
			  if (s != l + " (") {
				  s = s + l + ", ";
				  flag = true;
			  }
		  }
	  }
	  if (flag) {
		  s.erase(s.size() - 2);
		  s += ")";
	  }
	  else s.erase(s.size() - 2);
	  return s;
  }
  string FormattedReturn(string first_name, string last_name) const {
	  if (first_name == "" && last_name == "") {
		  return "No person";
	  }
	  else if (first_name == "") {
		  return last_name + " with unknown first name";
	  }
	  else if (last_name == "") {
		  return first_name + " with unknown last name";
	  }
	  else {
		  return first_name + " " + last_name;
	  }
  }

};
int main() {
  Person person("Polina", "Sergeeva", 1960);
  string s = "asda";
  person.ChangeFirstName(1950, s);

  vector<int> d = {1959, 1960};
  for (int year : d) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  d = {1965, 1967};
  for (int year : d) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}

/*
int main() {
  Person person;
  vector<int> d;
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  d = {1900, 1965, 1990};
  for (int year : d) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  d = {1969, 1970};
  for (int year : d) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  d =  {1969, 1970};
  for (int year : d) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;

  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;

  person.ChangeLastName(1960, "Sergeeva");
  d = {1960, 1967};
  for (int year : d) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;

  return 0;
}
Compile error: b'/tmp/submissionuzajw1dx/names1.cpp: In function
\'int main()\':\n/tmp/submissionuzajw1dx/names1.cpp:201:62: error: passing
\'const Person\' as \'this\' argument discards qualifiers [-fpermissive]\n
  cout << \'"\' << person_ref.GetFullNameWithHistory(year) << \'"\' << endl;\n                                                              ^\ncompilation terminated due to -Wfatal-errors.\n'



/*/

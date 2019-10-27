#include<iostream>
#include<string>
#include<vector>
#include "CalculateClock.h"
#include "VerifyClock.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;

void print_test_type(string type) {
	string test = "***     Algorithm " + type + " Tests     ***";
	cout << endl;
	cout << string(test.length(), '*') << endl;
	cout << test << endl;
	cout << string(test.length(), '*') << endl;
}
void write_test() {

}

int main(int argc, char **argv) {
	print_test_type("Calculate");
	/* ************************* */
	/* Algorithm Calculate Tests */
	/* ************************* */
	vector<vector<string>> t_one{
		{"a",  "s1", "r3", "b" },
		{"c",  "r2", "s3", ""  },
		{"r1", "d",  "s2", "e" }
	};
	CalculateClock test_one(3, t_one);
	test_one.calculate();
	test_one.print_solution();

	vector<vector<string>> t_additional{
	{"a", "s1", "s2", "b"},
	{"c", "r1", "r2", "s3"},
	{"r1", "d", "r3", "e"}
	};
	CalculateClock t_te(3, t_additional);
	t_te.calculate();
	t_te.print_solution();

	vector<vector<string>> t_two{
		{"s1", "b",  "r3", "e"  },
		{"a",  "r2", "s3", ""   },
		{"r1", "c",  "d",  "s2" }
	};
	CalculateClock test_two(3, t_two);
	test_two.calculate();
	test_two.print_solution();

	vector<vector<string>> t_three{
		{"a",  "b",  "c",  "d",  "s1", "s2", "e",  "s3", "r4", "s5", ""},
		{"r1", "r2", "f",  "g",  "h",  "s4", "r5", "",   "",   "",   ""},
		{"i",  "j",  "r6", "n",  "o",  "p",  "q",  "x",  "z",  "r8", "s9"},
		{"s6", "k",  "l",  "m",  "r7", "s8", "",   "",   "",   "" ,  ""},
		{"a",  "b",  "c",  "d",  "e",  "f",  "g",  "h",  "i",  "s7", "r9"},
	};
	CalculateClock test_three(5, t_three);
	test_three.calculate();
	test_three.print_solution();

	vector<vector<string>> t_four{
		{"a",  "b", "s1", "s2", "c", "r3", "d"},
		{"s3", "e", "r1", "f",  "",  "",   ""},
		{"r2", "g", "r3", "",   "",  "",   ""}
	};
	CalculateClock test_four(3, t_four);
	test_four.calculate();
	test_four.print_solution();

	vector<vector<string>> t_five{
		{"a", "s1", "b", "r2"},
		{"r1", "c", "s2", "d"}
	};
	CalculateClock test_five(2, t_five);
	test_five.calculate();
	test_five.print_solution();

	vector<vector<string>> t_six{
		{"s1", "a",  "s3", "",   "",  "",  ""},
		{"r1", "s2", "b",  "r3", "",  "",  ""},
		{"r2", "c",  "d",  "f",  "g", "h", "r3"}
	};
	CalculateClock test_six(3, t_six);
	test_six.calculate();
	test_six.print_solution();

	vector<vector<string>> t_seven{
		{"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "t", "u", "v", "w", "x", "y", "z"}
	};
	CalculateClock test_seven(1, t_seven);
	test_seven.calculate();
	test_seven.print_solution();

	vector<vector<string>> t_eight{
		{"r1", "b", "c", "d"},
		{"s1", "e", "f", "g"},
		{"r2", "e", "f", "g"},
		{"s2", "g", "h", ""}
	};
	CalculateClock test_eight(4, t_eight);
	test_eight.calculate();
	test_eight.print_solution();

	print_test_type("Verify");
	/* ********************** */
	/* Algorithm Verify Tests */
	/* ********************** */
	vector<vector<int>> t_nine = {
		{1, 2, 8, 9, 0},
		{1, 6, 7, 0, 0},
		{3, 4, 5, 6, 0}
	};
	VerifyClock test_nine(3, 5, t_nine);
	test_nine.verify();
	test_nine.print_solution();

	vector<vector<int>> t_ten = {
		{1, 2, 8, 9},
		{1, 6, 7, 0},
		{2, 3, 4, 5}
	};
	VerifyClock test_ten(3, 4, t_ten);
	test_ten.verify();
	test_ten.print_solution();

	vector<vector<int>> t_eleven = {
		{1, 2, 8, 9},
		{1, 6, 7, 0},
		{2, 4, 5, 6}
	};
	VerifyClock test_eleven(3, 4, t_eleven);
	test_eleven.verify();
	test_eleven.print_solution();

	vector<vector<int>> t_twelve = {
		{1, 2, 3, 4},
		{2, 3, 4, 5},
		{1, 2, 3, 4},
		{2, 3, 4, 0}
	};
	VerifyClock test_twelve(4, 4, t_twelve);
	test_twelve.verify();
	test_twelve.print_solution();

	vector<vector<int>> t_thirteen = {
		{1, 2, 3, 4, 5,  6,  7,  8, 12, 13, 0},
		{6, 7, 8, 9, 10, 11, 14, 0, 0,  0,  0},
		{1, 2, 3, 4, 5,  6,  7,  8, 9,  13, 14},
		{1, 2, 3, 4, 11, 12, 0,  0, 0,  0,  0},
		{1, 2, 3, 4, 5,  6,  7,  8, 9,  10, 15}
	};
	VerifyClock test_thirteen(5, 11, t_thirteen);
	test_thirteen.verify();
	test_thirteen.print_solution();

	vector<vector<int>> t_fourteen = {
		{1, 2, 3, 4},
		{1, 3, 4, 5},
		{3, 4, 6, 7}
	};
	VerifyClock test_fourteen(3, 4, t_fourteen);
	test_fourteen.verify();
	test_fourteen.print_solution();

	vector<vector<int>> t_fifteen = {
		{1, 2, 4, 5, 6, 9},
		{1, 2, 5, 6, 7, 8},
		{2, 3, 4, 5, 0, 7}
	};
	VerifyClock test_fifteen(3, 6, t_fifteen);
	test_fifteen.verify();
	test_fifteen.print_solution();

	// getchar();
	return 0;
}

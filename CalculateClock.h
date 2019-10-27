#pragma once
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

using std::vector;
using std::string;
using std::cout;
using std::endl;

class CalculateClock {
public:
	CalculateClock(int N, vector<vector<string>> Matrix);
	~CalculateClock();
	void calculate();
	bool terminate(vector<int> indexes);
	void print_solution();

private:
	int N;
	vector<vector<string>> Matrix;
	vector<vector<int>> result;
	vector<int> map;
};
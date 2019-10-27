#pragma once
#include<string>
#include<vector>
#include<iostream>
#include<map>

using std::map;
using std::vector;
using std::string;
using std::cout;
using std::endl;

class VerifyClock {
public:
	VerifyClock(int N, int M, vector<vector<int>> Matrix);
	~VerifyClock();


	void verify();
	void increment_letter();
	void append_send_map(int value, int i, int j);
	void append_receive_map(int value, int i, int j);
	void populate_maps();
	void validate_receives();
	void validate_values();
	void print_solution();

private:
	int N;
	int M;
	string letter;
	bool valid_input;
	vector<vector<int>> Matrix;
	vector<vector<string>> result;

	map<int, vector<vector<int>>> send_map;
	map<int, vector<vector<int>>> receive_map;
};

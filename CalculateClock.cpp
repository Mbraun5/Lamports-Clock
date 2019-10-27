#include "CalculateClock.h"

CalculateClock::CalculateClock(int N, vector<vector<string>> Matrix) {
	this->N = N;
	this->Matrix = Matrix;

	vector<vector<int>> res(Matrix.size(), vector<int>(Matrix[0].size(), 0));
	vector<int> map(10, 0);
	this->map = map;
	this->result = res;
}

CalculateClock::~CalculateClock() {}

bool CalculateClock::terminate(vector<int> indexes) {
	int length = this->Matrix[0].size();
	for (size_t i = 0; i < indexes.size(); i++) {
		if (indexes[i] < length) {
			return false;
		}
	}
	return true;
}

void CalculateClock::calculate() {
	vector<int> indexes(this->Matrix.size(), 0);
	while (!this->terminate(indexes)) {
		for (size_t i = 0; i < this->Matrix.size(); i++) {
			for (size_t j = indexes[i]; j < this->Matrix[0].size(); j++) {
				if (this->Matrix[i][j] == "");
				else if (this->Matrix[i][j][0] == 's') {
					int index = Matrix[i][j][1] - '0';
					if (j == 0)
						result[i][j] = 1;
					else
						this->result[i][j] = this->result[i][j - 1] + 1;
					this->map[index] = this->result[i][j];
				}
				else if (this->Matrix[i][j][0] == 'r') {
					int index = Matrix[i][j][1] - '0';
					if (this->map[index] == 0) 
						break;
					if (j == 0)
						this->result[i][j] = this->map[index] + 1;
					else
						this->result[i][j] = std::max(this->map[index], result[i][j - 1]) + 1;
				}
				else {
					if (j == 0) 
						result[i][j] = 1;
					else 
						result[i][j] = result[i][j - 1] + 1;
				}
				indexes[i] += 1;
			}
		}
	}
}

void CalculateClock::print_solution() {
	static int i = 0;
	i += 1;
	if (this->result[0].size() > 10) {
		int spacing = int(this->result[0].size() / 2 * 1.5);
		cout << string(spacing, ' ') << "***   TEST NUMBER: " << i << "   ***" << endl;
		cout << "INPUT" << endl;
		for (size_t i = 0; i < this->result.size(); i++) {
			for (size_t j = 0; j < this->result[0].size(); j++) {
				if (this->Matrix[i][j].size() == 1)
					cout << " " << this->Matrix[i][j] << "  ";
				else
					cout << this->Matrix[i][j] << "  ";
				if (this->Matrix[i][j] == "")
					cout << "  ";
			}
			cout << endl;
		}
		cout << endl << endl;
		cout << "OUTPUT" << endl;
		for (size_t i = 0; i < this->result.size(); i++) {
			for (size_t j = 0; j < this->result[0].size(); j++) {
				if (result[i][j] <= 9)
					cout << " " << result[i][j] << "  ";
				else
					cout << result[i][j] << "  ";
			}
			cout << endl;
		}
		cout << endl << endl << endl;
	}
	else {
		int spacing = int((this->result[0].size() * 2 + 10) / 2);
		cout << string(spacing, ' ') << "***   TEST NUMBER: " << i << "   ***" << endl;
		cout << "     INPUT" << string(spacing * 3, ' ') << "OUTPUT" << endl;
		for (size_t i = 0; i < this->result.size(); i++) {
			for (size_t j = 0; j < this->result[0].size(); j++) {
				if (this->Matrix[i][j].size() == 1)
					cout << " " << this->Matrix[i][j] << "  ";
				else
					cout << this->Matrix[i][j] << "  ";
				if (this->Matrix[i][j] == "")
					cout << "  ";
			}

			if (int(i) == this->N / 2)
				cout << "     -->     ";
			else
				cout << "             ";
			for (size_t j = 0; j < this->result[0].size(); j++) {
				if (result[i][j] <= 9)
					cout << " " << result[i][j] << "  ";
				else
					cout << result[i][j] << "  ";
			}
			cout << endl;
		}
		cout << endl << endl;
	}
}
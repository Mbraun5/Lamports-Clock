#include "VerifyClock.h"

VerifyClock::VerifyClock(int N, int M, vector<vector<int>> Matrix) {
	this->N = N;
	this->M = M;
	this->letter = "a";
	this->Matrix = Matrix;
	this->valid_input = true;
	vector<vector<string>> res(N, vector<string>(M, ""));
	this->result = res;
}

VerifyClock::~VerifyClock() {}

void VerifyClock::increment_letter() {
	if (this->letter[0] == 'z')
		this->letter[0] = 'a';
	else
		this->letter[0] += 1;
	if (this->letter[0] == 'r')
		this->letter[0] += 2;
}

void VerifyClock::append_send_map(int value, int i, int j) {
	vector<int> indices = { i, j };
	map<int, vector<vector<int>>>::iterator it = this->send_map.find(value);
	if (it == this->send_map.end()) {
		vector<vector<int>> new_list = { indices };
		this->send_map[value] = new_list;
	}
	else {
		it->second.push_back(indices);
	}
}

void VerifyClock::append_receive_map(int value, int i, int j) {
	vector<int> indices = { i, j };
	map<int, vector<vector<int>>>::iterator it = this->receive_map.find(value);
	if (it == this->receive_map.end()) {
		vector<vector<int>> new_list = { indices };
		this->receive_map[value] = new_list;
	}
	else {
		it->second.push_back(indices);
	}
}

void VerifyClock::populate_maps() {
	if (!this->valid_input) return;
	for (int i = 0; i < this->N; i++) {
		for (int j = 0; j < this->M; j++) {
			if (Matrix[i][j] == 0) {
				for (int k = j + 1; k < this->M; k++) {
					if (Matrix[i][k] != 0) {
						this->valid_input = false;
						return;
					}
				}
				this->result[i][j] = "";
				continue;
			}
			if (j == 0) {
				if (this->Matrix[i][j] == 1) {
					this->result[i][j] = this->letter;
					this->increment_letter();
					this->append_send_map(1, i, j);
				}
				else {
					this->append_receive_map(Matrix[i][j], i, j);
				}
			}
			else {
				if (this->Matrix[i][j] == this->Matrix[i][j - 1] + 1) {
					this->result[i][j] = this->letter;
					this->increment_letter();
					this->append_send_map(Matrix[i][j], i, j);
				}
				else {
					this->append_receive_map(Matrix[i][j], i, j);
				}
			}
		}
	}
}

void VerifyClock::validate_receives() {
	if (!this->valid_input) return;
	if (this->receive_map.size() > 9) {
		this->valid_input = false;
		return;
	}

	string receive = "r1";
	string send = "s1";
	for (map<int, vector<vector<int>>>::iterator it = this->receive_map.begin(); it != this->receive_map.end(); it++) {
		for (size_t i = 0; i < it->second.size(); i++) {
			map<int, vector<vector<int>>>::iterator sit = this->send_map.find(it->first - 1);
			if (sit == this->send_map.end() || sit->second.size() < 1) {
				this->valid_input = false;
				return;
			}
			else {
				int j = it->second[i][0];
				int k = it->second[i][1];
				this->result[j][k] = receive;

				int len = sit->second.size();
				j = sit->second[len - 1][0];
				k = sit->second[len - 1][1];
				this->result[j][k] = send;
				
				if (len > 1 || i == it->second.size() - 1) {
					sit->second.pop_back();
					receive[1] += 1;
					send[1] += 1;
				}
			}
		}
	}
}

void VerifyClock::validate_values() {
	for (int i = 0; i < this->N; i++) {
		for (int j = 1; j < this->M; j++) {
			if (this->Matrix[i][j - 1] >= this->Matrix[i][j] && this->Matrix[i][j] != 0) {
				this->valid_input = false;
				return;
			}
			if (this->Matrix[i][j - 1] == 0 && this->Matrix[i][j] != 0) {
				this->valid_input = false;
				return;
			}
		}
	}
}

void VerifyClock::verify() {
	this->validate_values();
	this->populate_maps();
	this->validate_receives();
}

void VerifyClock::print_solution() {
	static int i = 0;
	i += 1;
	if (!this->valid_input) {
		int spacing = int(this->result[0].size() / 2);
		cout << string(spacing, ' ') << "***   TEST NUMBER: " << i << "   ***" << endl;
		cout << "INPUT" << endl;
		for (size_t i = 0; i < this->result.size(); i++) {
			for (size_t j = 0; j < this->result[0].size(); j++) {
				if (this->Matrix[i][j] <= 9)
					cout << " " << this->Matrix[i][j] << "  ";
				else
					cout << this->Matrix[i][j] << "  ";
			}
			cout << endl;
		}
		cout << endl;
		cout << "OUTPUT" << endl;
		cout << "INCORRECT" << endl << endl;
		return;
	}
	if (this->result[0].size() > 10) {
		int spacing = int(this->result[0].size() / 2 * 1.5);
		cout << string(spacing, ' ') << "***   TEST NUMBER: " << i << "   ***" << endl;
		cout << "INPUT" << endl;
		for (size_t i = 0; i < this->result.size(); i++) {
			for (size_t j = 0; j < this->result[0].size(); j++) {
				if (this->Matrix[i][j] <= 9)
					cout << " " << this->Matrix[i][j] << "  ";
				else
					cout << this->Matrix[i][j] << "  ";
			}
			cout << endl;
		}
		cout << endl << endl;
		cout << "OUTPUT" << endl;
		for (size_t i = 0; i < this->result.size(); i++) {
			for (size_t j = 0; j < this->result[0].size(); j++) {
				if (result[i][j].size() == 1)
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
				if (this->Matrix[i][j] <= 9)
					cout << " " << this->Matrix[i][j] << "  ";
				else
					cout << this->Matrix[i][j] << "  ";
			}

			if (int(i) == this->N / 2)
				cout << "     -->     ";
			else
				cout << "             ";
			for (size_t j = 0; j < this->result[0].size(); j++) {
				if (result[i][j].size() == 1)
					cout << " " << result[i][j] << "  ";
				else
					cout << result[i][j] << "  ";
			}
			cout << endl;
		}
		cout << endl << endl;
	}
}

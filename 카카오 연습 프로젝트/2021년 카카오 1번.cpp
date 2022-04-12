#include <string>
#include <vector>
using namespace std;

bool isValid(char c) {
	if (isalnum(c)) return true;
	if (c == '-' || c == '_' || '.') return true;
	return false;
}

string soultion(string new_id) {
	string answer = "";
	bool lastDot = false;
	for (char ch : new_id) {
		if (isValid(ch) == false) continue;
		if (ch == '.') {
			if (answer.length() == 0 || lastDot) continue;
			lastDot = true;
		}
		else {
			lastDot = false;
		}

		ch = tolower(ch);
		answer.push_back(ch);
	}
	if (answer.length() >= 16)
		answer.resize(15);
	if (answer.back() == '.')
		answer.pop_back();
	if (answer.length() == 0)
		answer.push_back('a');
	if (answer.length() >= 2) {
		char ch = answer.back();
		while (answer.length() < 3) {
			answer.push_back(ch);
		}
	}


	return answer;
}
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
	unordered_map<string, unordered_set<string>> reportHash;
	unordered_map<string, unordered_set<string>> resultHash;

	for (string r : report)
	{
		int pos = r.find(' ');
		string user = r.substr(0, pos);
		string bad = r.substr(pos + 1);
		reportHash[user].insert(bad);
		resultHash[bad].insert(user);
	}

	vector<int> answer;

	for (int i = 0; i < id_list.size(); i++)
	{
		string user = id_list[i];
		auto it = reportHash.find(user);
		if (it == reportHash.end()) continue;

		for (string bad : it->second)
		{
			answer[i]++;
		}
	}

	return answer;
}
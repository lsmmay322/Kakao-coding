#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>

using namespace std;
typedef struct {
	string nickName;
	string act;
	string userId;
}id;

id ft_strtok(string str, char ch) {
	id tmp;
	vector<string> strTmp;
	int start = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ch) {
			strTmp.push_back(str.substr(start, i - start));
			start = i + 1;
		}
	}
	strTmp.push_back(str.substr(start, str.length() - start));
	tmp.act = strTmp[0];
	tmp.userId = strTmp[1];
	if (strTmp[0] != "Leave")
		tmp.nickName = strTmp[2];

	return tmp;
}

vector<string> solution(vector<string> record) {
	vector<string> answer;
	unordered_map<string, string> map;
	vector<id> tmp;

	for (int i = 0; i < record.size(); i++) {
		tmp.push_back(ft_strtok(record[i], ' '));
		if (tmp[i].act == "Enter")
			map[tmp[i].userId] = tmp[i].nickName;
		else if (tmp[i].act == "Change")
			map[tmp[i].userId] = tmp[i].nickName;
	}
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i].act == "Enter")
			answer.push_back(map[tmp[i].userId] + "님이 들어왔습니다.");
		else if(tmp[i].act == "Leave")
			answer.push_back(map[tmp[i].userId] + "님이 나갔습니다.");
	}

	return answer;
}

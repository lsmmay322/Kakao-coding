#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	int busTime = 540;
	int person = 0;
	int full;
	bool lastFull = false;
	int tmp;
	vector<int> time(timetable.size());
	for (int i = 0; i < timetable.size(); i++)
		time[i] = stoi(timetable[i].substr(0, 2)) * 60 + stoi(timetable[i].substr(3));
	sort(time.begin(), time.end());
	for (int i = 1; i <= n; i++)
	{
		for (full = 0; full < m; full++) {
			if (person < timetable.size() && time[person] <= busTime)
				person++;
			else if (person == timetable.size() || time[person] > busTime)
				break;
		}
		if (i == n && full == m && person <= timetable.size())
			lastFull = true;
		if (i != n)
			busTime += t;
	}
	if (lastFull)
		tmp = time[person - 1] - 1;
	else
		tmp = busTime;

	//시간 변경
	if (tmp / 60 < 10)
	{
		if (tmp % 60 < 10)
			answer = "0" + to_string(tmp / 60) + ":0" + to_string(tmp % 60);
		else
			answer = "0" + to_string(tmp / 60) + ":" + to_string(tmp % 60);
	}
	else
	{
		if (tmp % 60 < 10)
			answer = to_string(tmp / 60) + ":0" + to_string(tmp % 60);
		else
			answer = to_string(tmp / 60) + ":" + to_string(tmp % 60);
	}
		return answer;
}

int main()
{
	vector<string> timetable1 = { "08:00" , "08:01", "08:02", "08:03"};
	vector<string> timetable2 = {"09:10", "09:09", "08:00" };
	vector<string> timetable3 = { "09:00", "09:00", "09:00", "09:00" };
	vector<string> timetable4 = { "00:01", "00:01", "00:01", "00:01", "00:01" };
	vector<string> timetable5 = { "23:59"};
	vector<string> timetable6 = { "23:59", "23:59","23:59","23:59","23:59","23:59",
	"23:59" ,"23:59" ,"23:59" ,"23:59" ,"23:59" ,"23:59" ,"23:59" ,
	"23:59" ,"23:59" };
	cout << "1 : " << solution(1, 1, 5, timetable1) << '\n';
	cout << "2 : " << solution(2, 10, 2, timetable2) << '\n';
	cout << "3 : " << solution(2, 1, 2, timetable3) << '\n';
	cout << "4 : " << solution(1, 1, 5, timetable4) << '\n';
	cout << "5 : " << solution(1, 1, 1, timetable5) << '\n';
	cout << "5 : " << solution(10, 60, 45, timetable6) << '\n';

}

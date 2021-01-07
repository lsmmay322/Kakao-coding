#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int check_opt(string dartResult, int i)
{
	if (i == dartResult.length())
		return 1;
	else if (dartResult[i + 1] == '*' || dartResult[i + 1] == '#')
		return (dartResult[i + 1] == '*') ? 2 : -1;
	else
		return 1;
}
int solution(string dartResult) {
	int answer = 0;
	int current = 0;
	int p = 0;
	int score[3]{ 0, 0, 0 };
	char opt;
	for (int i = 0; i < dartResult.length(); i++)
	{
		if (dartResult[i] == 'S') p = 1;
		else if (dartResult[i] == 'D') p = 2;
		else if (dartResult[i] == 'T') p = 3;
		if (p)
		{
			int tmp = stoi(dartResult.substr(0, i));
			opt = check_opt(dartResult, i);
			if (opt == 2 && current)
				score[current - 1] *= 2;
			score[current] = pow(tmp, p) * opt;
			if (opt != 1) dartResult = dartResult.substr(i + 2);
			else dartResult = dartResult.substr(i + 1);
			current++;
			i = 0;
			p = 0;
		}
	}
	answer = score[0] + score[1] + score[2];
	return answer;
}

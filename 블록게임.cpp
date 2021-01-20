#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector <int>> tmp;

bool ft_isok(int r, int c)
{
	for (int i = 0; i < r; i++)
		if (tmp[i][c] != 0)
			return false;
	return true;
}

bool ft_check(int r, int c, int h, int w) {
	int emp = 0;
	int default_value = -1;

	for (int i = r; i < r + h; i++) {
		for (int j = c; j < c + w; j++) {
			if (tmp[i][j] == 0) {
				if (!ft_isok(i, j))
					return false;
				if (++emp > 2)
					return false;
			}
			else {
				if (default_value != -1 && default_value != tmp[i][j])
					return false;
				default_value = tmp[i][j];
			}
		}
	}
	for (int i = r; i < r + h; i++)
		for (int j = c; j < c + w; j++)
			tmp[i][j] = 0;
	return true;
}

int solution(vector<vector<int>> board) {
	int answer = 0;
	tmp = board;
	int cnt, n = board.size();
	bool ret;

	do {
		cnt = 0;
		ret = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i <= (n - 3) && j <= (n - 2) && ft_check(i, j, 3, 2)) {
					cnt++;
					ret = true;
					break;
				}
				else if (i <= (n - 2) && j <= (n - 3) && ft_check(i, j, 2, 3)) {
					cnt++;
					ret = true;
					break;
				}
			}
			answer += cnt;
			if (ret)
				break;
		}
	} while (cnt);

	return answer;
}

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Page {
	int index;
	double tmp_score;
	int link;
	double score;
} page;

bool ft_compare(page& a, page& b) {
	if (a.score == b.score)
		return a.index < b.index;
	return a.score > b.score;
}

int solution(string word, vector<string> pages) {
	int answer = 0;
	map<string, int> url_ind;
	vector<page> info;
	int w_size = word.length();
	transform(word.begin(), word.end(), word.begin(), ::tolower);

	for (int i = 0 ; i < pages.size(); i++)
	{
		transform(pages[i].begin(), pages[i].end(), pages[i].begin(), ::tolower);
		int left = 0;
		int right;
		int mid=0;
		string tmp = pages[i];

		for (left;;) {
			left = tmp.find("<meta", left+1);
			if (left == string::npos)
				break;
			right = tmp.find(">", left);
			mid = tmp.rfind("https://", right);
		}
		right = tmp.find("\"", mid);
		string url = tmp.substr(mid, right - mid);

		double score = 0;
		left = tmp.find("<body>", right + 1);
		int f_word = left;
		for (f_word;;) {
			f_word = tmp.find(word, f_word + 1);
			if (f_word == string::npos)
				break;
			if (!(isalpha(tmp[f_word - 1])) && !(isalpha(tmp[f_word + w_size]))) {
				score++;
				f_word += w_size;
			}
		}

		int link = 0;
		for (left;;) {
			left = tmp.find("<a href=", left + 1);
			if (left == string::npos)
				break;
			link++;
		}
		cout << url << ' ' << score << ' ' << link << '\n';

		url_ind[url] = i;
		info.push_back({i, score, link, (double)score});
	}

	for (int i = 0; i < pages.size(); i++) {
		string tmp = pages[i];
		transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
		int left = 0, right, mid;
		for (left;;) {
			left = tmp.find("<a href=", left + 1);
			if (left == string::npos)
				break;
			right = tmp.find(">", left);
			mid = tmp.rfind("https://", right);
			right = tmp.find("\"", mid);
			string link = tmp.substr(mid, right - mid);

			map<string, int>::iterator itr = url_ind.find(link);
			if (itr != url_ind.end())
				info[itr->second].score += (info[i].tmp_score / info[i].link);
		}
	}
	sort(info.begin(), info.end(), ft_compare);

	answer = info[0].index;
	return answer;
}

int main()
{
	vector <string> v = { "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>" };
	int n = solution("Muzi", v);
	cout << n;
}

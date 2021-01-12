#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

vector<string> ft_strtok(string str, char ch)
{
    vector<string> res;
    int start = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ch) {
            res.push_back(str.substr(start, i-start));  // 잘 체크하자
            start = i + 1;
        }
    }
    res.push_back(str.substr(start, str.length()));

    return res;
}
int solution(vector<string> lines) {
    int answer = 0;

    vector<pair<double, double>> time;

    for (int i = 0; i < lines.size(); i++)
    {
        vector<string> tmp = ft_strtok(lines[i], ' ');
        vector<string> temp = ft_strtok(tmp[1], ':');

        double end = stod(temp[0]) * 3600 + stod(temp[1]) * 60 + stod(temp[2]);
        double t = stod(ft_strtok(tmp[2], 's')[0]);

        time.push_back(make_pair(end - t + 0.001, end));
    }

    for (int i = 0; i < time.size(); i++) {
        double begin = time[i].second;
        double end = begin + 0.999;

        int tmp = 0;

        for (int j = i; j < time.size(); j++) {
            if (time[j].first <= end + 0.0001 && time[j].second >= begin - 0.0001)
                tmp++;
        }

        if (answer < tmp)
            answer = tmp;
    }
    return answer;
}

int main()
{
    vector<string> lines;
    lines.push_back("2016-09-15 20:59:57.421 0.351s");
    lines.push_back("2016-09-15 20:59:58.233 1.181s");
    lines.push_back("2016-09-15 20:59:58.299 0.8s");
    lines.push_back("2016-09-15 20:59:58.688 1.041s");
    lines.push_back("2016-09-15 20:59:59.591 1.412s");
    lines.push_back("2016-09-15 21:00:00.464 1.466s");
    lines.push_back("2016-09-15 21:00:00.741 1.581s");
    lines.push_back("2016-09-15 21:00:00.748 2.31s");
    lines.push_back("2016-09-15 21:00:00.966 0.381s");
    lines.push_back("2016-09-15 21:00:02.066 2.62s");
    int n = solution(lines);
    cout << n;
}

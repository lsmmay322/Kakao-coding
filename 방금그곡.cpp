#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
typedef struct{
    int start;
    int end;
    string name;
    string music;
} info;

info ft_strtok(string str, char ch)
{
    info tmp;
    vector<string> s;
    int start = 0;

    for (int i = 0 ; i < str.length() ;  i++)
    {
        if (str[i] == ch){
            s.push_back(str.substr(start, i-start));
            start = i + 1;
        }
    }
    int num = 0;
    for (int i = 0 ; i < 2 ; i++){
		for (int i = 0 ; i < s[0].length() ; i++){
        	num = stoi(s[0].substr(0,2)) * 60 + stoi(s[0].substr(3,5));
			if (i == 0)
				tmp.start = num;
			else
				tmp.end = num;
    	}
    }
	tmp.name = s[2];
	tmp.music = s[3];
	return tmp;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    vector <info> arr;
    info tmp;
    for (int i = 0; i < musicinfos.size() ; i++)
    {
        tmp = ft_strtok(musicinfos[i], ',');
        arr.push_back(tmp);
    }
	cout << arr[0].name;
	cout << arr[0].start;
	cout << arr[0].end;
    return answer;
}

int main()
{
	string m = "ABCDEFG";
	vector <string> v = {"12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"};
	string s = solution(m, v);
	return(0);
}
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
typedef struct {
    int time;
    string name;
    string music;
    bool answer;
} info;

info ft_strtok(string str, char ch)
{
    info tmp;
    vector<string> s;
    int start = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ch) {
            s.push_back(str.substr(start, i - start));
            start = i + 1;
        }
    }
    s.push_back(str.substr(start, str.length()));

    int begin = stoi(s[0].substr(0, 2)) * 60 + stoi(s[0].substr(3, 5));
    int end = stoi(s[1].substr(0, 2)) * 60 + stoi(s[1].substr(3, 5));

    tmp.time = end - begin;
    tmp.name = s[2];
    tmp.music = s[3];
    return tmp;
}

bool ft_check(info arr, vector<string> m, vector<string> music) {
    bool correct = false;
    int m_ind;
    int mus_ind;

    for (int i = 0; i < music.size(); i++)
    {
        mus_ind = i;
        m_ind = 0;
        if (music[mus_ind] == m[m_ind]) {
            for (int j = 0; j < arr.time - i; j++) {
                if (m[m_ind] == music[mus_ind]) {
                    m_ind++;
                    mus_ind++;
                }
                else {
                    mus_ind++;
                    m_ind = 0;
                }
                if (mus_ind == music.size())
                    mus_ind = 0;
                if (m_ind == m.size()) {
                    correct = true;
                    break;
                }
            }
        }
        if (correct)
            break;
    }
    arr.answer = (correct) ? true : false;
    return arr.answer;
}

vector<string> ft_musicTok(string music) {
    vector<string> tmp;
    string s = "";

    for (int i = 0; i < music.length(); i++) { //  C#D#E#F#G#A#B#
        if (music[i + 1] != '#') {
            s += music[i];
            tmp.push_back(s);
            s = "";
        }
        else if (music[i + 1] == '#') {
            s += music.substr(i, 2);
            tmp.push_back(s);
            s = "";
            i++;
        }
    }
    return tmp;
}

bool ft_compare(info a, info b) {
    return (a.time > b.time);
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    vector <info> ans_tmp;
    vector <info> arr;
    info tmp;
    for (int i = 0; i < musicinfos.size(); i++)
    {
        tmp = ft_strtok(musicinfos[i], ',');
        arr.push_back(tmp);
    }
    for (int i = 0; i < arr.size(); i++) {
        vector<string> mus_tok = ft_musicTok(arr[i].music);
        vector<string> m_tok = ft_musicTok(m);
        arr[i].answer = ft_check(arr[i], m_tok, mus_tok);
    }
    for (auto x : arr) {
        if (x.answer)
            ans_tmp.push_back(x);
    }
    stable_sort(ans_tmp.begin(), ans_tmp.end(), ft_compare);
    if (ans_tmp.empty())
        answer += "(None)";
    else
        answer = ans_tmp[0].name;
    return answer;
}

int main()
{
    string m = "CDCDF";
    vector <string> v = { "12:00,12:14,HELLO,CDCDCDF" ,"13:00,13:05,WORLD,ABCDEF"};
    string s = solution(m, v);
    cout <<  s << ' ';
    return(0);
}

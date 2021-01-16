#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef struct {
    string head;
    int num;
    string full_name;
}f_name;

bool ft_comp(f_name a, f_name b) {
    transform(a.head.begin(), a.head.end(), a.head.begin(), ::tolower);
    transform(b.head.begin(), b.head.end(), b.head.begin(), ::tolower);
    if (a.head == b.head)
        return a.num < b.num;
    return a.head < b.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<f_name> file;
    f_name tmp;
    int num;
    bool check;
    bool finish;
    for (int i = 0; i < files.size(); i++) {
        check = true;
        finish = false;
        num = 0;
        for (int j = 0; j < files[i].length(); j++) {
            if ((files[i][j] >= '0' && files[i][j] <= '9') && check) {
                tmp.head = files[i].substr(0, j);
                check = false;
            }
            if ((files[i][j] >= '0' && files[i][j] <= '9') && !check) {
                num = num * 10 + (files[i][j] - '0');
                finish = true; // finish = true가 되도 일단 tail 전에 숫자가 계속 존재하면 else if문으로 넘어가지 않는다.
            }
            else if (finish)
                break;
        }
        tmp.num = num;
        tmp.full_name = files[i];
        file.push_back(tmp);
    }
    stable_sort(file.begin(), file.end(), ft_comp);
    for (int i = 0; i < file.size(); i++)
        answer.push_back(file[i].full_name);
    return answer;
}
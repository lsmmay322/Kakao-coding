#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> arr;
    int ind;
    string tmp = "";
    for (ind = 0; ind < 26; ind++)
    {
        tmp += 'A' + ind;
        arr.emplace(tmp, ind);
        tmp = "";
    }

    for (int i = 0; i < msg.length(); i++) {
        tmp = "";
        int plus = i;
        tmp += msg[i];
        while (arr.find(tmp) != arr.end()) {
            plus++;
            tmp += msg[plus];
        }
        i = plus - 1;
        arr.emplace(tmp, ind++);
        tmp.pop_back();
        answer.push_back(arr[tmp] + 1);
    }
    return answer;
}
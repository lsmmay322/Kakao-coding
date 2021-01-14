#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> arr;
    char alp;
    string tmp = "";
    for (int i = 0 ; i < 26 ; i++)
    {
        tmp += 'A' + i;
        arr.emplace(tmp, i);
    }
        
    for (int i = 0 ; i < msg.length() ; i++){
        for (int j = i + 1 ; j < msg.length() ; j++){
            if (arr[msg.substr(i,j)])
                continue;
            else
            {
                arr.emplace(msg.substr(i, j), msg.size());
                answer.push_back(msg.find(msg.substr(i,j-1)));
                i = j - 1;
            }
        }
    }
    return answer;
}

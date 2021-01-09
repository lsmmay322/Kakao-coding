#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define CHECK(a) (a >= 'a' && a <= 'z') ? true : false

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;

    double tmp;
    vector<string> s1;
    vector<string> s2;
    vector<string> s_union;									//합집합
    vector<string> s_inter;									//교집합

    for (int i = 0; i < str1.length(); i++)
        str1[i] = tolower(str1[i]);							//소문자로 변경
    for (int i = 0; i < str2.length(); i++)
        str2[i] = tolower(str2[i]);

    for (int i = 0; i < str1.length() - 1; i++)				//문자열 분할
        if ((CHECK(str1[i]) == true) && (CHECK(str1[i + 1]) == true))
            s1.push_back(str1.substr(i, 2));
    for (int i = 0; i < str2.length() - 1; i++)
        if ((CHECK(str2[i]) == true)&& (CHECK(str2[i + 1]) == true))
            s2.push_back(str2.substr(i, 2));

    if (s1.size() == 0 && s2.size() == 0)					// 만약 합집합이 0 이면 65536 출력
    {
        answer = 65536;
        return answer;
    }

    sort(s1.begin(), s1.end());								// 벡터 정렬
    sort(s2.begin(), s2.end());


    int j = 0;
    bool pass = true;
    while (s1.size() != 0)
    {
        pass = true;
        for (int k = 0; k < s2.size(); k++)
        {
            if (s1[j] == s2[k])								//공통되는 부분이면 합집합, 교집합에 추가, 그리고 원소는 삭제
            {
                s_inter.push_back(s1[j]);
                s_union.push_back(s1[j]);
                s1.erase(s1.begin() + j);
                s2.erase(s2.begin() + k);
                j = 0;
                pass = false;
                break;
            }
        }
        if (pass)											//교집합 없으면 실행
        {
            s_union.push_back(s1[j]);
            s1.erase(s1.begin() + j);
            j = 0;
        }
    }
    for (int k = 0; k < s2.size(); k++) {					//s2벡터에서 남는 부분 합집합에 추가
        s_union.push_back(s2[k]);
    }
    tmp = (double)s_inter.size() / (double)s_union.size();

    answer = tmp * 65536;
    return answer;
}

int main()
{
    cout << solution("FRANCE", "french") << '\n';
    cout << solution("handshake", "shake hands") << '\n';
    cout << solution("aa1+aa2", "AAAA12") << '\n';
    cout << solution("E=M*C^2", "AAAA12") << '\n';

}

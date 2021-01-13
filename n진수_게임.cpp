#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string ft_base(int n, int num){
    string res = "";
	char ch;
	if (num == 0)
		return("0");
    while (num / n != 0)
    {
        if (num % n >= 10)
            ch =  'A' + (num % n - 10);
		else
			ch =  '0' + (num % n);
		num /= n;
		res = ch + res;
    }
	if (num % n >= 10)
        ch =  'A' + (num % n - 10);
	else
		ch =  '0' + (num % n);
	res = ch + res;
	return (res);
}

string solution(int n, int t, int m, int p){
    string answer = "";
    int num = 0;
    int index_man = 1;
    while (answer.length() < t){
        string n_base = ft_base(n, num);
		for (int i = 0 ; i < n_base.length() ; i++){
			if (index_man == p)
				answer.push_back(n_base.at(i));
			if (index_man == m)
				index_man = 0;
			index_man++;
		}
		num++;
		if (answer.length() == t)
			break;
    }   
    return answer;
}

int main(){
	string str;
	str = solution(2, 4, 2, 1);
	cout << str;

}
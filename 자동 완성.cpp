#include <string>
#include <vector>
#include <iostream>

using namespace std;
const int ALP = 26;

class triNode {
private:
	triNode* child[ALP];
	int count[26] = { 0, };
public:
	triNode() {							// 생성자, 처음은 주소를 NULL값으로 지정
		for (int i = 0; i < ALP; i++)
			child[i] = NULL;
	}
	~triNode() {						//소멸자, 동적할당 해제
		for (int i = 0; i < ALP; i++)
			delete child[i];
	}
	void insert(const char* str) {		//입력받은 문자열의 각각문자를 Tri구조에 학습.
		if (!*str)
			return;
		int next = *str - 'a';			// 배열의 인덱스를 가리키기 위해 integer로 변환
		count[next]++;					// 해다 문자가 입력됬으니 +1해준다.
		if (!child[next])
			child[next] = new triNode();	// 만약 노드가 NULL이라면 처음입력받은 문자이므로 다음 노드를 동적할당 해준다.
		child[next]->insert(str + 1);		// 다음 문자를 insert한다.
	}

	int find(const char* str, int n) {		// 정답을 찾기 위한 과정
		if (!(*str))
			return (n - 1);					// 문자열 끝까지 왔다면, 입력받은 변수 n-1을 반환.
		int cnt = *str - 'a';
		if (count[cnt] == 1)				// count[cnt] == 1이라는 것은 해당 문자가 전체 통틀어서 한번밖에 입력받지 못했다는 것이고, 이는 유일한 문자이므로 이 문자까지만 입력하면 자동완성이 된다.
			return n;
		return child[cnt]->find(str + 1, n + 1); // count가 2 이상이라면 다음 문자와 입력한 문자 개수 n+1을 입력하여 find로 재귀해준다.
	}
};

int solution(vector<string> words) {
	int answer = 0;
	triNode tri;

	for (int i = 0; i < words.size(); i++) {
		tri.insert(words[i].c_str());
	}
	for (int i = 0; i < words.size(); i++)
		answer += tri.find(words[i].c_str(), 1);
	return answer;
}

int main() {
	vector <string> v = { "go", "gone", "guild" };
	int n = solution(v);
	cout << n;
	return (0);
}

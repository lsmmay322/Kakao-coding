#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
	if (cacheSize == 0)
		return cities.size() * 5;

	int answer = 0;
	list<string> lru;
	list<string>::iterator itr;

	for_each(cities.begin(), cities.end(), [](string& str) {
		for (int i = 0; i < str.length(); i++) {
			str[i] = tolower(str[i]);
		}
		});
	for (int i = 0; i < cities.size(); i++)
	{
		bool miss = true;
		for (itr = lru.begin(); itr != lru.end(); itr++) {
			if (*itr == cities[i]) {
				miss = false;
				lru.erase(itr);
				lru.push_back(cities[i]);
				answer++;
				break;
			}
		}
		if (miss) {
			if (lru.size() == cacheSize)
			{
				lru.pop_front();
				lru.push_back(cities[i]);
			}
			else
				lru.push_back(cities[i]);
			answer += 5;
		}
	}
	return answer;
}

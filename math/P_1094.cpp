#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 문제주소 : https://www.acmicpc.net/problem/1094
// 메모리, 응답시간 : 2020kb, 0ms

int sum(vector<int> vec) {
	int sum = 0;
	for (int i = 0; i < int(vec.size()); i++) {
		sum += vec[i];
	}
	return sum;
}


int main() {

	int x;
	cin >> x;

	//합이 X보다 크다면, 아래와 같은 과정을 반복한다.
	vector<int> sticks(1, 64);
	while (sum(sticks) > x) {
		//가지고 있는 막대 중 길이가 가장 짧은 것을 절반으로 자른다.
		int cut1, cut2;
		cut1 = *min_element(sticks.begin(), sticks.end());

		//만약, 위에서 자른 막대의 절반 중 
		//하나를 버리고 남아있는 막대의 길이의 합이 X보다 크거나 같다면, 
		//위에서 자른 막대의 절반 중 하나를 버린다.
		*min_element(sticks.begin(), sticks.end()) = cut2;
		if (sum(sticks) >= x) {
			continue;
		}
		*min_element(sticks.begin(), sticks.end()) = cut1;
		if (sum(sticks) >= x) {
			continue;
		}

		//cut1가 짝수가 되도록 swap
		if (cut1 % 2 == 1) {
			int tmp = cut1;
			cut1 = cut2;
			cut2 = tmp;
		}

		*min_element(sticks.begin(), sticks.end()) = cut1;
		sticks.push_back(cut2);
	}

	cout << (sticks.size());

	return 0;
}
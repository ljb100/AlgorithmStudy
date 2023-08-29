#include <iostream>
std::pair<int, int>* days;
int d, k;
int a, b;

// 문제주소 : https://www.acmicpc.net/problem/2502
// 메모리, 응답시간 : 2020kb, 0ms

int main() {
	//첫째 줄에는 할머니가 넘어온 날 D 
	//그 날 호랑이에게 준 떡의 개수 K
	d = k = 0;
	std::cin >> d >> k;

	// 첫 날에 준 떡의 개수 A
	// 둘째 날에 준 떡의 개수 B
	a = b = 0;

	days = new std::pair<int, int>[d + 1];
	days[1].first = days[2].second = 1;
	days[1].second = days[2].first = 0;
	for (int i = 3; i <= d; i++) {
		days[i].first = days[i - 1].first + days[i - 2].first;
		days[i].second = days[i - 1].second + days[i - 2].second;
	}

	int countX, countY;
	countX = days[d].first;
	countY = days[d].second;

	for (int x = 1; x <= k; x++) {
		for (int y = 1; y <= k; y++) {
			int sum = countX * x + countY * y;
			if (sum == k) {
				a = x;
				b = y;
				std::cout << a << "\n" << b;
				return 0;
			}
		}
	}

	std::cout << -1 << "\n" << -1;

	return 0;
}
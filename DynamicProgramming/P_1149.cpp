#include <iostream>
#include <vector>
#include <algorithm>

// 문제주소 : https://www.acmicpc.net/problem/1149
// 메모리, 응답시간 : 2020kb, 0ms

int main() {
	//집의 수 n
	int n;
	std::cin >> n;

	int** price = new int* [n+1];
	for (int i = 0; i <= n+1; i++) price[i] = new int[3];
	
	price[0][0] = 0;
	price[0][1] = 0;
	price[0][2] = 0;

	for (int i = 1; i <= n; i++) {
		int inputR, inputG, inputB;
		std::cin >> inputR >> inputG >> inputB;

		price[i][0] = std::min(price[i - 1][1], price[i - 1][2]) + inputR;
		price[i][1] = std::min(price[i - 1][0], price[i - 1][2]) + inputG;
		price[i][2] = std::min(price[i - 1][0], price[i - 1][1]) + inputB;
	}
	int min = price[n][0];
	if (min > price[n][1]) min = price[n][1];
	if (min > price[n][2]) min = price[n][2];

	std::cout << min;
	return 0;
}
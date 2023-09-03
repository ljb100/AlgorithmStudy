#include <iostream>

// 문제주소 : https://www.acmicpc.net/problem/2293
// 메모리, 응답시간 : 2020kb, 0ms

int main() {
	//n가지 종류의 동전
	//가치의 합이 k원이 되도록 하고 싶다.
	int n, k;
	std::cin >> n >> k;

	int* coin = new int[n+1];
	int* sum = new int[10001] {0, };
	sum[0] = 1;
	
	for (int i = 1; i <= n; i++) {
		std::cin >> coin[i];
	}

	for (int i = 1; i <= n; i++) {
		for(int j = coin[i]; j <= k; j++)
			sum[j] += sum[j - coin[i]];
	}

	std::cout << sum[k];

	return 0;
}
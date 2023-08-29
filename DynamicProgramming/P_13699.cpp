#include <iostream>

// 문제주소 : https://www.acmicpc.net/problem/13699
// 메모리, 응답시간 : 2020kb, 0ms

long long* array;
int input;
long long t(int n) {
	if (n == 0) return 1;
	if (array[n] != 0) return array[n];
	for(int i = 1; i <= n; i++)
		array[n] += ( t(i-1) * t(n - i) );
	return array[n];
}

int main() {
	std::cin >> input;

	array = new long long[input+1];
	std::fill(&array[0], &array[input + 1], 0);
	std::cout << t(input);
	return 0;
}
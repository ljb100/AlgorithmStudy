#include <iostream>
#include <vector>

// 문제주소 : https://www.acmicpc.net/problem/2161
// 메모리, 응답시간 : 2020kb, 0ms

int main() {
	int n;
	std::cin >> n;

	//1번 카드가 제일 위에, 
	//N번 카드가 제일 아래인 상태로 순서대로 카드가 놓여 있다.
	std::vector<int> arr(n, 0);
	for (int i = 0; i < n; i++) 
		arr[i] = i + 1;

	//다음과 같은 동작을 카드가 한 장 남을 때까지 반복하게 된다.
	while (arr.size() != 1) {
		//버린 카드들을 순서대로 출력
		std::cout << arr[0] << " ";
		//우선, 제일 위에 있는 카드를 바닥에 버린다.
		arr.erase(arr.begin());
		//그 다음, 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮긴다.
		arr.push_back(arr[0]);
		arr.erase(arr.begin());
	}
	//마지막에 남게 되는 카드를 출력
	std::cout << arr[0];

	return 0;
}
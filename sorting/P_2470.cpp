#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

// 문제주소 : https://www.acmicpc.net/problem/2470
// 메모리, 응답시간 : 2412kb, 76ms

bool compare(int a, int b) {
	if (abs(a) < abs(b))
		return true;
	else
		return false;
}

// 1.부호 상관없이 크기 순으로 나열
// 2.순회하면서 바로 다음꺼랑 크기 비교해서 가장 작은 두놈 출력
int main() {
	int n;
	cin >> n;

	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++) cin >> arr[i];


	//절댓값 크기 순 정렬
	sort(arr.begin(), arr.end(), compare);

	//디버그용
	cout << "\n절댓값 크기순 정렬 : ";
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
	cout << "\n\n";

	//출력할 두 놈 a, b
	int a, b;
	a = b = 0;
	//최솟값 min
	int min = 2000000000;
	for (int i = 0; i < n-1; i++) {
		//지금 보고 있는 놈 바로 다음 놈이랑 합이 가장 작은 두 개 구하기
		if (min > abs(arr[i] + arr[i+1])) {
			a = arr[i];
			b = arr[i+1];
			min = abs(arr[i] + arr[i+1]);
		}
	}

	//오름차 순으로 출력
	(a < b) ? (cout << a << " " << b) : (cout << b << " " << a);

	return 0;
}
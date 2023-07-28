#include <iostream>
using namespace std;

// 문제주소 : https://www.acmicpc.net/problem/16206
// 메모리, 응답시간 : 2020kb, 136ms

int cutCake(int* cake, int index, int* cakelen, int cutCount, int m);
int isPowerOfTwo(int input);
void sort(int* cake, int cakelen);

int main() {
	int n, m;

	cin >> n >> m;

	int cakelen = n;
	//cake길이 늘리기 
	int* cake = new int[1000];
	for (int i = 0; i < cakelen; i++) {
		cin >> cake[i];
	}
	sort(cake, cakelen);

	int cutCount = 0;
	//자를 횟수가 남아있으면
	if (cutCount < m) {							//10의 배수인 것 처리
		//자를 횟수를 모두 쓸 때 까지
		while (cutCount != m) {
			bool isDone = true;
			for (int i = 0; i < cakelen; i++) {
				if (cake[i] % 10 == 0 && cake[i] > 10) {
					cutCake(&cake[0], i, &cakelen, cutCount, m);
					cutCount++;
					isDone = false;
					break;
				}
			}
			//자를 횟수가 남아있더라도 조건에 부합하는게 없으면 종료
			if (isDone == true) break;
		}
	}

	//자를 횟수가 남아있으면
	if (cutCount < m) {								//나머지 처리
		//자를 횟수를 모두 쓸 때 까지
		while (cutCount != m) {
			bool isDone = true;
			for (int i = 0; i < cakelen; i++) {
				if (cake[i] > 10) {
					cutCake(&cake[0], i, &cakelen, cutCount, m);
					cutCount++;
					isDone = false;
					break;
				}
			}
			//자를 횟수가 남아있더라도 조건에 부합하는게 없으면 종료
			if (isDone == true) break;
		}
	}

	//10인 롤케이크 세기
	int result = 0;
	for (int i = 0; i < cakelen; i++) {
		if (*(cake + i) == 10) result++;
	}

	cout << result;

	return 0;
}

int cutCake(int* cake, int index, int* cakelen, int cutCount, int m) {
	int x, y;
	x = *(cake + index);
	y = 0;
	if (x % 10 == 0 && (isPowerOfTwo(x / 10) > 0 && isPowerOfTwo(x / 10) + cutCount <= m)) {
		x /= 2;
		y = x;
		//x, y 추가
		*(cake + index) = x;
		*(cake + *cakelen) = y;
		*cakelen += 1;
		sort(cake, *cakelen);
		return 1;
	}
	else {
		for (y = 1; y <= *(cake + index); y++) {
			if (y == 10 || x - y == 10) {
				break;
			}
		}
		x = x - y;

		//x값 y값 배열에 추가
		*(cake + index) = x;
		*(cake + *cakelen) = y;
		*cakelen += 1;
		sort(cake, *cakelen);
		return 1;
	}
} //30을 먼저 계산할지 50을 먼저 할지

//1 -> return 0, power of two -> cnt, not power of two -> -1
int isPowerOfTwo(int input) {
	int cnt = 0;
	while (input != 1) {
		if (input >= 2 && input % 2 == 0) {
			input /= 2;
			cnt++;
		}
		else {
			return -1;
		}
	}

	//2^n - 1만큼 시행횟수 필요
	int result = 1;
	for (int i = 0; i < cnt; i++) {
		result *= 2;
	}
	return result - 1;

	//또는 return input/10-1
}

void sort(int* cake, int cakelen) {
	for (int i = 0; i < cakelen; i++) {
		int min = cake[i];
		for (int j = i; j < cakelen; j++) {
			if (min > cake[j]) {
				min = cake[j];
				int tmp = cake[i];
				cake[i] = cake[j];
				cake[j] = tmp;
			}
		}
	}
	/*cout << "Debug  ---  ";
	for (int i = 0; i < cakelen; i++) cout << cake[i] << " ";
	cout << "\n";*/
}
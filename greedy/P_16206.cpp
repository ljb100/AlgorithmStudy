#include <iostream>
using namespace std;

// �����ּ� : https://www.acmicpc.net/problem/16206
// �޸�, ����ð� : 2020kb, 136ms

int cutCake(int* cake, int index, int* cakelen, int cutCount, int m);
int isPowerOfTwo(int input);
void sort(int* cake, int cakelen);

int main() {
	int n, m;

	cin >> n >> m;

	int cakelen = n;
	//cake���� �ø��� 
	int* cake = new int[1000];
	for (int i = 0; i < cakelen; i++) {
		cin >> cake[i];
	}
	sort(cake, cakelen);

	int cutCount = 0;
	//�ڸ� Ƚ���� ����������
	if (cutCount < m) {							//10�� ����� �� ó��
		//�ڸ� Ƚ���� ��� �� �� ����
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
			//�ڸ� Ƚ���� �����ִ��� ���ǿ� �����ϴ°� ������ ����
			if (isDone == true) break;
		}
	}

	//�ڸ� Ƚ���� ����������
	if (cutCount < m) {								//������ ó��
		//�ڸ� Ƚ���� ��� �� �� ����
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
			//�ڸ� Ƚ���� �����ִ��� ���ǿ� �����ϴ°� ������ ����
			if (isDone == true) break;
		}
	}

	//10�� ������ũ ����
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
		//x, y �߰�
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

		//x�� y�� �迭�� �߰�
		*(cake + index) = x;
		*(cake + *cakelen) = y;
		*cakelen += 1;
		sort(cake, *cakelen);
		return 1;
	}
} //30�� ���� ������� 50�� ���� ����

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

	//2^n - 1��ŭ ����Ƚ�� �ʿ�
	int result = 1;
	for (int i = 0; i < cnt; i++) {
		result *= 2;
	}
	return result - 1;

	//�Ǵ� return input/10-1
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
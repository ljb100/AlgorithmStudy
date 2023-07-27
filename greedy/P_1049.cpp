#include <stdio.h>
#pragma warning(disable:4996)

// 문제주소 : https://www.acmicpc.net/problem/1049
// 메모리, 응답시간 : 1116kb, 0ms

int main() {
	int brokenString, brandNum;

	scanf("%d %d", &brokenString, &brandNum);

	int brand[50][2] = {'\0', };
	for (int i = 0; i < brandNum; i++) {
		scanf("%d %d", &brand[i][0], &brand[i][1]);
		getchar();
	}

	int min[2] = { 0, };
	//int* minimumPos[2] = { 0, };
	int minimumPos[2] = { 0, };
	min[0] = brand[0][0];
	min[1] = brand[0][1];
	for (int i = 0; i < brandNum; i++) {
		if (min[0] > brand[i][0]) {
			min[0] = brand[i][0];
			//minimumPos[0] = &brand[i][0];
			minimumPos[0] = i;
		}
		if (min[1] > brand[i][1]) {
			min[1] = brand[i][1];
			//minimumPos[1] = &brand[i][1];
			minimumPos[1] = i;
		}
	}
	
	bool noSix = false;
	for (int i = 0; i < brandNum; i++) {
		if (min[0] > brand[i][1] * 6) {
			min[0] = brand[i][1] * 6;
			//minimumPos[0] = &brand[i][1];
			minimumPos[0] = i;
			noSix = true;
		}
	}

	int price = 0;
	while (brokenString > 0) {
		if (!noSix) {
			if (brokenString >= 6) {
				price += brand[minimumPos[0]][0];
				brokenString -= 6;
			}
			else if (brokenString < 6) {
				if (brokenString * brand[minimumPos[1]][1] < brand[minimumPos[0]][0]) {
					price += brand[minimumPos[1]][1];
					brokenString--;
				}
				else {
					price += brand[minimumPos[0]][0];
					brokenString -= 6;
				}
			}
		}
		else {
			price += brand[minimumPos[1]][1];;
			brokenString--;
		}
	}

	printf("%d", price);

	return 0;
}
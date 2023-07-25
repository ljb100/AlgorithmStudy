#include <stdio.h>
#pragma warning(disable:4996)

// 문제주소 : https://www.acmicpc.net/problem/10162
// 메모리, 응답시간 : 1112kb, 0ms

int main() {
	int t;
	int a, b, c;
	int anum, bnum, cnum;

	anum = bnum = cnum = 0;
	a = 60 * 5;
	b = 60 * 1;
	c = 10;

	scanf("%d", &t);
	while (a <= t) {
		anum++;
		t -= a;
	}
	while (b <= t) {
		bnum++;
		t -= b;
	}
	while (c <= t) {
		cnum++;
		t -= c;
	}

	if (t > 0)
		printf("-1");
	else
		printf("%d %d %d", anum, bnum, cnum);

	return 0;
}

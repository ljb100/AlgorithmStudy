#include <stdio.h>
#pragma warning(disable:4996)

// 문제주소 : https://www.acmicpc.net/problem/1439
// 메모리, 응답시간 : 1968kb, 0ms

int flip(char _init, char* s, int slen);

int main() {
	char s[1000000] = { '\0', };

	scanf("%s", &s);
	
	int i = 0;
	int slen = 0;
	while (s[i] != '\0') {                          //find length
		slen++;
		i++;
	}

	int countA, countB;
	countA = flip('0', &s[0], slen);
	countB = flip('1', &s[0], slen);


	//smallest print between (countA, countB)
	printf("%d", (countA > countB) ? countB : countA);

	return 0;
}

int flip(char _init, char* s, int slen) {
	int count = 0;
	int i = 0;
	char init = _init;
	while (i < slen) {             
		if (s[i] != init) {
			while (s[i] != init && i < slen) {
				i++;
			}
			count++;
		}
		i++;
	}

	return count;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 문제주소 : https://www.acmicpc.net/problem/1431
// 메모리, 응답시간 : 2028kb, 4ms

int numbersum(string input) {
	int result = 0;
	for (int j = 0; j < input.length(); j++) {
		if (input[j] >= '0' && input[j] <= '9') {
			char tmp = input[j];
			result += atoi(&tmp);
		}
	}
	return result;
}

bool dictionaryOrder(string a, string b) {
	if(a == b) return false;
	for (int i = 0; a.length(); i++) {
		int anum, bnum;
		anum = a[i];
		bnum = b[i];

		if (anum == bnum) continue;
		else if (anum > bnum) return false;
		else if (anum < bnum) return true;
	}
}
int main() {
	//기타 갯수
	int n;
	cin >> n;

	vector<string> guitar(n, "");
	for (int i = 0; i < n; i++) {
		cin >> guitar[i];
	}

	//길이 순 정렬
	for (int i = 0; i < n; i++) {
		int minlen = guitar[i].length();
		for (int j = i; j < n; j++) {
			if (minlen > guitar[j].length()) {
				minlen = guitar[j].length();
				string tmp = guitar[i];
				guitar[i] = guitar[j];
				guitar[j] = tmp;
			}
		}
	}

	//숫자 합 순 정렬
	for (int i = 0; i < n; i++) {
		int minnum = numbersum(guitar[i]);
		for (int j = i; j < n; j++) {
			if (guitar[i].length() != guitar[j].length()) continue;

			int currentsum = numbersum(guitar[j]);
			if (minnum > currentsum) {
				minnum = currentsum;
				string tmp = guitar[i];
				guitar[i] = guitar[j];
				guitar[j] = tmp;
			}
		}
	}

	//사전순 정렬
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			//길이 다르면 안함
			if (guitar[i].length() != guitar[j].length()) continue;
			//숫자로 순서가능하면 안함
			else if ((numbersum(guitar[i]) != numbersum(guitar[j]))) continue;
			
			//사전순으로 guitar[j]가 더 크면 true
			if (dictionaryOrder(guitar[i], guitar[j]) == false) {
				string tmp = guitar[i];
				guitar[i] = guitar[j];
				guitar[j] = tmp;
			}
		}
	}

	//결과
	for (int i = 0; i < n; i++) cout << guitar[i] << "\n";


	return 0;
}
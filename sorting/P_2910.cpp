#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 문제주소 : https://www.acmicpc.net/problem/2910
// 메모리, 응답시간 : 2020kb, 0ms

vector<int> cal(1001, -1);
int cnt = 0;

bool isInCal(int input) {
	for (int i = 0; i < cal.size(); i++)
		if (cal[i] == input) return true;
	return false;
}

int main() {
	int n, c;
	cin >> n >> c;

	vector<int> array(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}

	vector<int> count(n, 0);
	//같은거 끼리 묶기
	for (int i = 0; i < n; i++) {
		if (isInCal(array[i])) {
			continue;
		}
		for (int j = i; j < n; j++) {
			//is in cal?
			if (isInCal(array[j])) {
				//yes //pass
				break;
			}
			else {
				//no //cnt and store in cal
				for (int k = j; k < n; k++) {
					if (array[k] == array[j]) {
						//cout << array[j] << " ";
						count[cnt]++;
					}
				}
				cal[cnt] = array[j];
				cnt++;
			}
		}
	}

	//디버그
	/*cout << "cal : ";
	for (int i = 0; i < n; i++) {
		if (cal[i] == -1)break;
		cout << cal[i] << " ";
	}
	cout << "\n";
	cout << "count :";
	for (int i = 0; i < n; i++) {
		if (cal[i] == -1)break;
		cout << count[i] << " ";
	}
	cout << "\n";*/
	//
	for (int i = 0; i < n; i++) {
		int max = *max_element(count.begin(), count.end());
		//cout << "max : " << max << "\n";
		int index = find(count.begin(), count.end(), max) - count.begin();
		for (int j = 0; j < max; j++) {
			cout << cal[index] << " ";
		}
		count[index] = 0;
	}


	return 0;
}
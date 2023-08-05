#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// 문제주소 : https://www.acmicpc.net/problem/1461
// 메모리, 응답시간 : 2024kb, 0ms

// 1 : longestPos에 가장 큰 값부터 m개 저장
// 2 : 나머지 배열의 값들을 크기가 큰 쪽에서 m개 만큼 처리
// 3 : 마지막에 longestPos의 0번째(가장큰 수)를 처리
// 4 : 결과출력 
int main() {
	//책의 개수n, 한번에 들 수 있는 개수 m
	int n, m;
	//n, m 입력받기
	cin >> n >> m;

	//책 위치 저장할 bookPos
	vector<int> bookPos(n, 0);
	//책 위치 입력받기
	for (int i = 0; i < n; i++) cin >> bookPos[i];
	//저장할 책 갯수 foundCnt
	int foundCnt = 0;
	//입력받은 값 오름차순 정렬
	sort(bookPos.begin(), bookPos.end());
	//가장 큰 값이 있는 곳을 때어내어 마지막으로 처리 
	//longestPos에 가장 큰 값부터 m개 저장
	vector<int> longestPos(m, 0);

	//longestPos구하기
	//
	// bookPos의 끝과 시작이 같다면 = 입력이 하나라면
	if (bookPos.front() == bookPos.back()) {
		//longestPos에 booksPos저장, bookPos은 비어있으므로 clear, 찾은 책 foundCnt++
		longestPos[0] = bookPos[0];
		bookPos.clear();
		foundCnt++;
	}
	// - 위치가 더 크다면
	else if (abs(bookPos.front()) > abs(bookPos.back())) {
		//한번에 가져올 수 있는 m번 만큼 수행
		for (int i = 0; i < m; i++) {
			//순회하다 0을 넘어가면 종료
			if (bookPos[0] > 0) break;
			//longestPos에 저장
			longestPos[i] = bookPos[0];
			//현재 순회한 bookPos의 위치 삭제
			bookPos.erase(bookPos.begin());
			//찾은 책 +1
			foundCnt++;
		}
	}
	// + 위치가 더 크다면 (부호가 다르지만 크기는 같을 경우에도 수행)
	else if (abs(bookPos.back()) >= abs(bookPos.front())) {
		//한번에 가져올 수 있는 책의 갯수인 m번만큼 수행
		for (int i = 0; i < m; i++) {
			if (bookPos.back() < 0) break;
			//longestPos에 저장
			longestPos[i] = bookPos.back();
			//본거 지우기
			bookPos.pop_back();
			foundCnt++;
		}
	}

	//나머지들을 큰 값들순으로 처리 (주어진 최대 횟수만큼 무조건 옮기지 않아도 됨)
	//
	//이동거리 측정할 totalStep
	int totalStep = 0;
	//모두 다 찾을 때 까지 수행
	while (foundCnt != n) {
		//하나가 남으면
		if (bookPos.front() == bookPos.back()) {
			totalStep += abs(bookPos[0] * 2);
			bookPos.clear();
			foundCnt++;
		}
		// 왼쪽이 더 크다면
		else if (abs(bookPos.front()) > abs(bookPos.back())) {
			//왼쪽에서 가장 거리가 먼 거리의 *2 (왕복해야 하니까)
			totalStep += abs((bookPos[0] * 2));
			for (int i = 0; i < m; i++) {
				//0을 넘어가거나 비어있으면 중단
				if (bookPos.empty()) break;
				else if (bookPos[0] > 0) break;
				//본거 지우기
				bookPos.erase(bookPos.begin());
				foundCnt++;
			}
		}
		// 오른쪽이 더 크다면 (부호가 다르지만 크기는 같을 경우에도 수행)
		else if (abs(bookPos.back()) >= abs(bookPos.front())) {
			//오른쪽 쪽에서 가장 거리가 먼 거리의 *2 (왕복해야 하니까)
			totalStep += (bookPos.back() * 2);
			for (int i = 0; i < m; i++) {
				//0을 넘어가거나 비어있으면 중단
				if (bookPos.empty()) break;
				else if (bookPos.back() < 0) break;
				//본거 지우기
				bookPos.pop_back();
				foundCnt++;
			}
		}
	}

	//마지막으로 가장 큰 값 처리
	totalStep += abs(longestPos[0]);

	//결과 출력
	cout << totalStep;

	return 0;
}
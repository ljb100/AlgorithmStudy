#include <iostream>
#include <vector>
using namespace std;

// 문제주소 : https://www.acmicpc.net/problem/1057
// 메모리, 응답시간 : 2412kb, 492ms

// 1 : 현재 인원 수 만큼 배열에 1부터 차례대로 순위 부여
// 2 : 김씨와 임씨는 계속 이기면서 김씨와 임씨가 아닌 대결은 아무나 승리로 하기
// 3 : 대결 결과 탈락한 사람 삭제
// 4 : 임씨와 김씨만 남겨지거나, 대결에서 김씨와 임씨가 만나면 바로 현재 라운드 출력
int main() {
	//참가자 수 n, 김지민 순위 kimnum, 임한수 순위 limnum
	int	n, kimnum, limnum;
	cin >> n >> kimnum >> limnum;

	//참가자들의 순위를 넣는 배열
	vector<int> participation(n, 0);

	//몇번째 라운드인지 카운트하는 cnt
	int cnt = 0;
	//루프 탈출을 위한 status
	bool status = true;
	//김씨와 임씨 대결하는 라운드 구하기
	//
	while (status) {

		cnt++;
		//둘만 남으면 종료
		if (participation.size() == 2) break;
		//번호 부여
		for (int i = 0; i < participation.size(); i++) {
			//kim, lim의 번호 갱신
			if (participation[i] == kimnum) kimnum = i + 1;
			else if (participation[i] == limnum) limnum = i + 1;
			//순서대로 번호 부여 1, 2, 3, 4 ....
			participation[i] = i + 1;
		}

		//대결
		//
		//1등, 3등, 5등, 7등과 같이 대결하는 2명의 왼쪽을 기준으로 순회
		for (int i = 1; i <= participation.size(); i += 2) {
			//김씨와 임씨가 마주치면 종료
			if (participation[i-1] == limnum && participation[i] == kimnum) {
				//루프 탈출을 위한 status 설정
				status = false;
				break;
			}
			else if (participation[i - 1] == kimnum && participation[i] == limnum) {
				//루프 탈출을 위한 status 설정
				status = false;
				break;
			}

			//대결하는 두 사람 중 한 사람이 김씨라면 
			if (kimnum == i || kimnum == i + 1) {
				//김씨가 아닌 쪽 -99등으로 설정 (추후 삭제 과정에서 -99등들은 배열에서 삭제)
				participation[i - 1 + (kimnum % 2)] = -99;
			}
			////대결하는 두 사람 중 한 사람이 
			else if (limnum == i || limnum == i + 1) {
				//임씨라면 임씨가 아닌 쪽 -99등으로 설정
				participation[i - 1 + (limnum % 2)] = -99;
			}
			//대결하는 두 사람에 김씨와 임씨 어느쪽도 없다면
			else {
				//왼쪽에 있는 사람 탈락
				participation[i - 1] = -99;
			}
		}
		//탈락한 사람 제거 (-99등인 사람)
		//
		//대결 도중에 배열에서 삭제해버리면 루프 범위, 인덱스 순서에서 오류발생 따라서 대결 이후에 탈락하는 사람 제거하는 과정 필요
		for (int k = 0; k < participation.size(); k++) {
			//탈락한 사람 (-99등) 이라면
			if (participation[k] == -99) {
				//탈락한 사람 삭제
				participation.erase(participation.begin() + k);
				//삭제하면 인덱스가 하니씩 당겨지기 때문에 다음 순회때에 지금 인덱스 다시 한 번 더 순회
				k -= 1;
			}
		}
	}//while 끝

	//결과 반환
	cout << cnt;

	return 0;
}
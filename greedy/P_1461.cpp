#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// �����ּ� : https://www.acmicpc.net/problem/1461
// �޸�, ����ð� : 2024kb, 0ms

// 1 : longestPos�� ���� ū ������ m�� ����
// 2 : ������ �迭�� ������ ũ�Ⱑ ū �ʿ��� m�� ��ŭ ó��
// 3 : �������� longestPos�� 0��°(����ū ��)�� ó��
// 4 : ������ 
int main() {
	//å�� ����n, �ѹ��� �� �� �ִ� ���� m
	int n, m;
	//n, m �Է¹ޱ�
	cin >> n >> m;

	//å ��ġ ������ bookPos
	vector<int> bookPos(n, 0);
	//å ��ġ �Է¹ޱ�
	for (int i = 0; i < n; i++) cin >> bookPos[i];
	//������ å ���� foundCnt
	int foundCnt = 0;
	//�Է¹��� �� �������� ����
	sort(bookPos.begin(), bookPos.end());
	//���� ū ���� �ִ� ���� ����� ���������� ó�� 
	//longestPos�� ���� ū ������ m�� ����
	vector<int> longestPos(m, 0);

	//longestPos���ϱ�
	//
	// bookPos�� ���� ������ ���ٸ� = �Է��� �ϳ����
	if (bookPos.front() == bookPos.back()) {
		//longestPos�� booksPos����, bookPos�� ��������Ƿ� clear, ã�� å foundCnt++
		longestPos[0] = bookPos[0];
		bookPos.clear();
		foundCnt++;
	}
	// - ��ġ�� �� ũ�ٸ�
	else if (abs(bookPos.front()) > abs(bookPos.back())) {
		//�ѹ��� ������ �� �ִ� m�� ��ŭ ����
		for (int i = 0; i < m; i++) {
			//��ȸ�ϴ� 0�� �Ѿ�� ����
			if (bookPos[0] > 0) break;
			//longestPos�� ����
			longestPos[i] = bookPos[0];
			//���� ��ȸ�� bookPos�� ��ġ ����
			bookPos.erase(bookPos.begin());
			//ã�� å +1
			foundCnt++;
		}
	}
	// + ��ġ�� �� ũ�ٸ� (��ȣ�� �ٸ����� ũ��� ���� ��쿡�� ����)
	else if (abs(bookPos.back()) >= abs(bookPos.front())) {
		//�ѹ��� ������ �� �ִ� å�� ������ m����ŭ ����
		for (int i = 0; i < m; i++) {
			if (bookPos.back() < 0) break;
			//longestPos�� ����
			longestPos[i] = bookPos.back();
			//���� �����
			bookPos.pop_back();
			foundCnt++;
		}
	}

	//���������� ū ��������� ó�� (�־��� �ִ� Ƚ����ŭ ������ �ű��� �ʾƵ� ��)
	//
	//�̵��Ÿ� ������ totalStep
	int totalStep = 0;
	//��� �� ã�� �� ���� ����
	while (foundCnt != n) {
		//�ϳ��� ������
		if (bookPos.front() == bookPos.back()) {
			totalStep += abs(bookPos[0] * 2);
			bookPos.clear();
			foundCnt++;
		}
		// ������ �� ũ�ٸ�
		else if (abs(bookPos.front()) > abs(bookPos.back())) {
			//���ʿ��� ���� �Ÿ��� �� �Ÿ��� *2 (�պ��ؾ� �ϴϱ�)
			totalStep += abs((bookPos[0] * 2));
			for (int i = 0; i < m; i++) {
				//0�� �Ѿ�ų� ��������� �ߴ�
				if (bookPos.empty()) break;
				else if (bookPos[0] > 0) break;
				//���� �����
				bookPos.erase(bookPos.begin());
				foundCnt++;
			}
		}
		// �������� �� ũ�ٸ� (��ȣ�� �ٸ����� ũ��� ���� ��쿡�� ����)
		else if (abs(bookPos.back()) >= abs(bookPos.front())) {
			//������ �ʿ��� ���� �Ÿ��� �� �Ÿ��� *2 (�պ��ؾ� �ϴϱ�)
			totalStep += (bookPos.back() * 2);
			for (int i = 0; i < m; i++) {
				//0�� �Ѿ�ų� ��������� �ߴ�
				if (bookPos.empty()) break;
				else if (bookPos.back() < 0) break;
				//���� �����
				bookPos.pop_back();
				foundCnt++;
			}
		}
	}

	//���������� ���� ū �� ó��
	totalStep += abs(longestPos[0]);

	//��� ���
	cout << totalStep;

	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

// �����ּ� : https://www.acmicpc.net/problem/1057
// �޸�, ����ð� : 2412kb, 492ms

// 1 : ���� �ο� �� ��ŭ �迭�� 1���� ���ʴ�� ���� �ο�
// 2 : �达�� �Ӿ��� ��� �̱�鼭 �达�� �Ӿ��� �ƴ� ����� �ƹ��� �¸��� �ϱ�
// 3 : ��� ��� Ż���� ��� ����
// 4 : �Ӿ��� �达�� �������ų�, ��ῡ�� �达�� �Ӿ��� ������ �ٷ� ���� ���� ���
int main() {
	//������ �� n, ������ ���� kimnum, ���Ѽ� ���� limnum
	int	n, kimnum, limnum;
	cin >> n >> kimnum >> limnum;

	//�����ڵ��� ������ �ִ� �迭
	vector<int> participation(n, 0);

	//���° �������� ī��Ʈ�ϴ� cnt
	int cnt = 0;
	//���� Ż���� ���� status
	bool status = true;
	//�达�� �Ӿ� ����ϴ� ���� ���ϱ�
	//
	while (status) {

		cnt++;
		//�Ѹ� ������ ����
		if (participation.size() == 2) break;
		//��ȣ �ο�
		for (int i = 0; i < participation.size(); i++) {
			//kim, lim�� ��ȣ ����
			if (participation[i] == kimnum) kimnum = i + 1;
			else if (participation[i] == limnum) limnum = i + 1;
			//������� ��ȣ �ο� 1, 2, 3, 4 ....
			participation[i] = i + 1;
		}

		//���
		//
		//1��, 3��, 5��, 7��� ���� ����ϴ� 2���� ������ �������� ��ȸ
		for (int i = 1; i <= participation.size(); i += 2) {
			//�达�� �Ӿ��� ����ġ�� ����
			if (participation[i-1] == limnum && participation[i] == kimnum) {
				//���� Ż���� ���� status ����
				status = false;
				break;
			}
			else if (participation[i - 1] == kimnum && participation[i] == limnum) {
				//���� Ż���� ���� status ����
				status = false;
				break;
			}

			//����ϴ� �� ��� �� �� ����� �达��� 
			if (kimnum == i || kimnum == i + 1) {
				//�达�� �ƴ� �� -99������ ���� (���� ���� �������� -99����� �迭���� ����)
				participation[i - 1 + (kimnum % 2)] = -99;
			}
			////����ϴ� �� ��� �� �� ����� 
			else if (limnum == i || limnum == i + 1) {
				//�Ӿ���� �Ӿ��� �ƴ� �� -99������ ����
				participation[i - 1 + (limnum % 2)] = -99;
			}
			//����ϴ� �� ����� �达�� �Ӿ� ����ʵ� ���ٸ�
			else {
				//���ʿ� �ִ� ��� Ż��
				participation[i - 1] = -99;
			}
		}
		//Ż���� ��� ���� (-99���� ���)
		//
		//��� ���߿� �迭���� �����ع����� ���� ����, �ε��� �������� �����߻� ���� ��� ���Ŀ� Ż���ϴ� ��� �����ϴ� ���� �ʿ�
		for (int k = 0; k < participation.size(); k++) {
			//Ż���� ��� (-99��) �̶��
			if (participation[k] == -99) {
				//Ż���� ��� ����
				participation.erase(participation.begin() + k);
				//�����ϸ� �ε����� �ϴϾ� ������� ������ ���� ��ȸ���� ���� �ε��� �ٽ� �� �� �� ��ȸ
				k -= 1;
			}
		}
	}//while ��

	//��� ��ȯ
	cout << cnt;

	return 0;
}
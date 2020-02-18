#include<iostream>
using namespace std;
class IDSystem {
protected:
	int cardID[50];
	int n1 = 0;
	int faceID[50];
	int n2 = 0;
public:
	IDSystem()
	{
		n1 = 0;
		n2 = 0;
	}
	~IDSystem() {}
	void inputid()
	{
		int x, y;
		cout << "¼����Чˢ��ID��" << endl;
		while (cin >> x)
			cardID[n1++] = x;
		cout << "���" << endl;
		cin.clear();
		cout << "¼����Ч����ID��" << endl;
		while (cin >> y)
			faceID[n2++] = y;
		cin.clear();
	}
	void addid()
	{
		int x, flag, i;
		cout << "ѡ��Ҫ���ӵ����������ǿ��ţ���������0����������1" << endl;
		cin >> flag;
		cout << "����Ҫ���ӵ�ID:" << endl;
		while (cin >> x) {
			if (flag == 0) {
				for (i = 0; i < n1; i++)
					if (cardID[i] == x) {
						cout << "�����ID " << x << " �Ѿ�����ЧID�У�" << endl; break;
					}
				if (n1 == i)	cardID[n1++] = x;
			}
			else {
				for (i = 0; i < n2; i++)
					if (faceID[i] == x) {
						cout << "�����ID " << x << " �Ѿ�����ЧID�У�" << endl; break;
					}
				if (n2 == i)	faceID[n2++] = x;
			}
		}
		cin.clear();
	}
	void eraseid()
	{
		int x, flag, i, j, find;

		cout << "ѡ��Ҫɾ�������������ǿ��ţ���������0����������1" << endl;
		cin >> flag;
		cout << "����Ҫɾ����ID:" << endl;
		while (cin >> x) {
			find = 0;
			if (flag == 0) {
				for (i = 0; i < n1; i++)
					if (cardID[i] == x) {
						for (j = i; j < n1; j++)
							cardID[j] = cardID[j + 1];

						n1--;
						find = 1;
						break;
					}
				if (find == 0) cout << "��Ǹ����Ҫɾ����ID " << x << " ����ϵͳ�У�" << endl;
			}
			else {
				for (i = 0; i < n2; i++)
					if (faceID[i] == x) {
						for (j = i; j < n2; j++)
							faceID[j] = faceID[j + 1];
						n2--;
						break;
					}
				if (i == n2) cout << "��Ǹ����Ҫɾ����ID" << x << "����ϵͳ�У�" << endl;
			}
		}
		cin.clear();
	}
	void clearid()
	{
		n1 = 0; n2 = 0;
	}
	void showid()
	{
		int i;
		cout << "��Ч��ID��" << endl;
		for (i = 0; i < n1; i++)
			cout << cardID[i] << '\t';
		cout << endl;
		cout << "��Ч����ID��" << endl;
		for (i = 0; i < n2; i++)
			cout << faceID[i] << '\t';
		cout << endl;
	}
};

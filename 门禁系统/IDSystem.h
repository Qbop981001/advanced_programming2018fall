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
		cout << "录入有效刷卡ID：" << endl;
		while (cin >> x)
			cardID[n1++] = x;
		cout << "完成" << endl;
		cin.clear();
		cout << "录入有效人脸ID：" << endl;
		while (cin >> y)
			faceID[n2++] = y;
		cin.clear();
	}
	void addid()
	{
		int x, flag, i;
		cout << "选择要增加的是人脸还是卡号，卡号输入0，人脸输入1" << endl;
		cin >> flag;
		cout << "输入要增加的ID:" << endl;
		while (cin >> x) {
			if (flag == 0) {
				for (i = 0; i < n1; i++)
					if (cardID[i] == x) {
						cout << "输入的ID " << x << " 已经在有效ID中！" << endl; break;
					}
				if (n1 == i)	cardID[n1++] = x;
			}
			else {
				for (i = 0; i < n2; i++)
					if (faceID[i] == x) {
						cout << "输入的ID " << x << " 已经在有效ID中！" << endl; break;
					}
				if (n2 == i)	faceID[n2++] = x;
			}
		}
		cin.clear();
	}
	void eraseid()
	{
		int x, flag, i, j, find;

		cout << "选择要删除的是人脸还是卡号，卡号输入0，人脸输入1" << endl;
		cin >> flag;
		cout << "输入要删除的ID:" << endl;
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
				if (find == 0) cout << "抱歉，你要删除的ID " << x << " 不在系统中！" << endl;
			}
			else {
				for (i = 0; i < n2; i++)
					if (faceID[i] == x) {
						for (j = i; j < n2; j++)
							faceID[j] = faceID[j + 1];
						n2--;
						break;
					}
				if (i == n2) cout << "抱歉，你要删除的ID" << x << "不在系统中！" << endl;
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
		cout << "有效卡ID：" << endl;
		for (i = 0; i < n1; i++)
			cout << cardID[i] << '\t';
		cout << endl;
		cout << "有效人脸ID：" << endl;
		for (i = 0; i < n2; i++)
			cout << faceID[i] << '\t';
		cout << endl;
	}
};

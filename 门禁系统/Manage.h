#include "person.h"
#include "IDSystem.h"

class Manage :public IDSystem
{
protected:
	student students[20];
	teacher teachers[20];
	int m1;
	int m2;
public:
	Manage() { n1 = 0; n2 = 0; m1 = 0; m2 = 0; }
	void input()
	{
		string name, identity, method1, method2, act;
		char time[20];
		int id1, id2;
		cout << "输入进出人员信息:" << endl;
		while (cin >> name) {
			cin >> identity;
			if (identity == "学生") {
				cin >> method1; cin >> id1;
			}
			else if (identity == "老师") {
				cin >> method1; cin >> id1;
				cin >> method2; cin >> id2;
			}
			cin >> time >> act;
			if (identity == "学生") {
				student stu(name, id1, time, act);
				students[m1++] = stu;
			}
			else if (identity == "老师") {
				teacher tea(name, id1, id2, time, act);
				teachers[m2++] = tea;
			}
		}
		cin.clear();
		int i, j, k;
		student t; teacher r;
		for (i = 0; i < m1; i++) {
			for (k = i, j = i + 1; j < m1; j++) if (students[j].priority < students[k].priority)	k = j;
			if (k != i) { t = students[k];	students[k] = students[i];	students[i] = t; }
		}
		for (i = 0; i < m2; i++) {
			for (k = i, j = i + 1; j < m2; j++) if (teachers[j].priority < teachers[k].priority)	k = j;
			if (k != i) { r = teachers[k];	teachers[k] = teachers[i];	teachers[i] = r; }
		}
	}
	void infooutput()
	{
		int i;
		for (i = 0; i < m1; i++)
			cout << students[i].name << ' ' << "学生 卡号 " << students[i].cardid << ' ' << students[i].entertime << ' ' << students[i].action << endl;
		for (i = 0; i < m2; i++)
			cout << teachers[i].name << ' ' << "老师 人脸 " << teachers[i].faceid << " 卡号 " << teachers[i].cardid << ' ' << teachers[i].entertime << ' ' << teachers[i].action << endl;
	}
	void resultoutput()
	{
		cout << "显示模拟结果:" << endl;
		int i, j;
		for (i = 0, j = 0; (i < m1) && (j < m2);) {
			if (students[i].priority < teachers[j].priority) { studentout(i); i++; }
			else { teacherout(j); j++; }
		}
		if (i < m1)
			for (; i < m1; i++)
				studentout(i);
		else if (j < m2)
			for (; j < m2; j++)
				teacherout(j);
	}
	void clear()
	{
		m1 = 0; m2 = 0;
	}
private:
	void studentout(int i)
	{
		int k;
		cout << students[i].status << students[i].name;
		if (students[i].action == "出") cout << ' ' << students[i].entertime << ' ' << "出系楼" << endl;
		else {
			for (k = 0; k < n1; k++)
				if (cardID[k] == students[i].cardid) { cout << ' ' << "有效刷卡" << ' ' << students[i].entertime << ' ' << "进系楼" << endl; break; }
			if (k == n1) cout << ' ' << "无效刷卡" << ' ' << students[i].entertime << ' ' << "未进系楼" << endl;
		}
	}
	void teacherout(int j)
	{
		int k;
		cout << teachers[j].status << teachers[j].name;
		if (teachers[j].action == "出") cout << ' ' << teachers[j].entertime << ' ' << "出系楼" << endl;
		else {
			for (k = 0; k < n2; k++)
				if (faceID[k] == teachers[j].faceid) { cout << ' ' << "有效人脸识别" << ' ' << teachers[j].entertime << ' ' << "进系楼" << endl; break; }
			if (k == n2) {
				cout << ' ' << "无效人脸识别";
				for (k = 0; k<n1; k++)
					if (cardID[k] == teachers[j].cardid) { cout << ' ' << "有效刷卡" << ' ' << teachers[j].entertime << ' ' << "进系楼" << endl; break; }
				if (k == n1)  cout << ' ' << "无效刷卡" << ' ' << teachers[j].entertime << ' ' << "未进系楼" << endl;
			}
		}
	}
};

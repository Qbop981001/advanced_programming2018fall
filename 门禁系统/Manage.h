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
		cout << "���������Ա��Ϣ:" << endl;
		while (cin >> name) {
			cin >> identity;
			if (identity == "ѧ��") {
				cin >> method1; cin >> id1;
			}
			else if (identity == "��ʦ") {
				cin >> method1; cin >> id1;
				cin >> method2; cin >> id2;
			}
			cin >> time >> act;
			if (identity == "ѧ��") {
				student stu(name, id1, time, act);
				students[m1++] = stu;
			}
			else if (identity == "��ʦ") {
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
			cout << students[i].name << ' ' << "ѧ�� ���� " << students[i].cardid << ' ' << students[i].entertime << ' ' << students[i].action << endl;
		for (i = 0; i < m2; i++)
			cout << teachers[i].name << ' ' << "��ʦ ���� " << teachers[i].faceid << " ���� " << teachers[i].cardid << ' ' << teachers[i].entertime << ' ' << teachers[i].action << endl;
	}
	void resultoutput()
	{
		cout << "��ʾģ����:" << endl;
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
		if (students[i].action == "��") cout << ' ' << students[i].entertime << ' ' << "��ϵ¥" << endl;
		else {
			for (k = 0; k < n1; k++)
				if (cardID[k] == students[i].cardid) { cout << ' ' << "��Чˢ��" << ' ' << students[i].entertime << ' ' << "��ϵ¥" << endl; break; }
			if (k == n1) cout << ' ' << "��Чˢ��" << ' ' << students[i].entertime << ' ' << "δ��ϵ¥" << endl;
		}
	}
	void teacherout(int j)
	{
		int k;
		cout << teachers[j].status << teachers[j].name;
		if (teachers[j].action == "��") cout << ' ' << teachers[j].entertime << ' ' << "��ϵ¥" << endl;
		else {
			for (k = 0; k < n2; k++)
				if (faceID[k] == teachers[j].faceid) { cout << ' ' << "��Ч����ʶ��" << ' ' << teachers[j].entertime << ' ' << "��ϵ¥" << endl; break; }
			if (k == n2) {
				cout << ' ' << "��Ч����ʶ��";
				for (k = 0; k<n1; k++)
					if (cardID[k] == teachers[j].cardid) { cout << ' ' << "��Чˢ��" << ' ' << teachers[j].entertime << ' ' << "��ϵ¥" << endl; break; }
				if (k == n1)  cout << ' ' << "��Чˢ��" << ' ' << teachers[j].entertime << ' ' << "δ��ϵ¥" << endl;
			}
		}
	}
};

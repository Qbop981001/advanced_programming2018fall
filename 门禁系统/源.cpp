#include "Manage.h"
int main()
{
	int select;
	int s;
	Manage manager;
	cout << "��ӭʹ���Ž�ϵͳ�� " << endl;
	
	while (true) {
		cout << "������������ѡ����Ҫ���еĲ�������0�����������Ա��Ϣ 1���������ԱȨ�� 2���˳�)" << endl;
		cin >> s;
		cin.clear();
		if (s == 0) { manager.input(); manager.infooutput(); manager.resultoutput(); manager.clear(); }
		else if (s == 1) {
			while (true) {
				cout << "����ԱȨ�ޣ�������������ѡ����Ҫ���еĲ�������0��¼�� 1������ 2��ɾ�� 3����� 4����ӡ������ЧID 5���˳���" << endl;
				cin >> select;
				if (select == 0)	manager.inputid();
				else if (select == 1) manager.addid();
				else if (select == 2) manager.eraseid();
				else if (select == 3) manager.clearid();
				else if (select == 4) manager.showid();
				else if (select == 5) break;
				else cout << "��������ִ������������룡" << endl;
			}
		}
		else break;
	}
	return 0;
}
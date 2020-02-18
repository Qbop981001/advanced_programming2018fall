#include "Manage.h"
int main()
{
	int select;
	int s;
	Manage manager;
	cout << "欢迎使用门禁系统！ " << endl;
	
	while (true) {
		cout << "下面输入数字选择你要进行的操作：（0：输入进出人员信息 1：进入管理员权限 2：退出)" << endl;
		cin >> s;
		cin.clear();
		if (s == 0) { manager.input(); manager.infooutput(); manager.resultoutput(); manager.clear(); }
		else if (s == 1) {
			while (true) {
				cout << "管理员权限：下面输入数字选择你要进行的操作：（0：录入 1：增加 2：删除 3：清空 4：打印现有有效ID 5：退出）" << endl;
				cin >> select;
				if (select == 0)	manager.inputid();
				else if (select == 1) manager.addid();
				else if (select == 2) manager.eraseid();
				else if (select == 3) manager.clearid();
				else if (select == 4) manager.showid();
				else if (select == 5) break;
				else cout << "输入的数字错误，请重新输入！" << endl;
			}
		}
		else break;
	}
	return 0;
}
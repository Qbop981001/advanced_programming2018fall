#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class person
{
public:
	string name;
	int cardid;
	char entertime[10];
	string action;

};
class student :public person
{

public:
	string status;
	int priority = 0;
	student() {}
	student(string name, int cardid, char s[], string action)
	{
		int i, k;
		k = 0;
		this->name = name;
		this->cardid = cardid;
		strcpy(entertime, s);
		this->action = action;
		status = "ѧ��";
		for (i = 0; entertime[i] != ':'; i++)
			priority = priority * 10 + (entertime[i] - '0');
		priority *= 60;
		for (i = i + 1; entertime[i] != '\0'; i++)
			k = k * 10 + (entertime[i] - '0');
		priority += k;
		priority *= 10;
		if (action == "��")priority -= 5;
		cout << priority << endl;
	}
};
class teacher :public person
{
public:
	int faceid;
	string status;
	int priority = 0;
	teacher() {}
	teacher(string name, int faceid, int cardid, char s[], string action)
	{
		int i, k;
		k = 0;
		this->name = name;
		this->cardid = cardid;
		strcpy(entertime, s);
		this->action = action;
		this->faceid = faceid;
		status = "��ʦ";
		for (i = 0; entertime[i] != ':'; i++)
			priority = priority * 10 + (entertime[i] - '0');
		priority *= 60;
		for (i = i + 1; entertime[i] != '\0'; i++)
			k = k * 10 + (entertime[i] - '0');
		priority += k;
		priority *= 10;
		if (action == "��")priority -= 5;
		priority -= 3;
		cout << priority << endl;
	}
};

#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{ 
	map<string,int> phone_book; //����һ��map�����������ڴ洢�绰���벾
  	phone_book["wang"] = 12345678; //ͨ��[]�����͹ؼ����������м���Ԫ��
  	phone_book["li"] = 87654321;
  	phone_book["zhang"] = 56781234;
	cout << "�绰���벾����Ϣ���£�\n";
  	map<string,int>::const_iterator it;  //����һ�������޸���ָ���Ԫ�صĵ�����
  	for (it=phone_book.begin(); it != phone_book.end(); it++) 
    	cout << it->first << ": " << it->second << endl; 
  	string name;
  	cout << "������Ҫ��ѯ�����������";
  	cin >> name;
  	it = phone_book.find(name); //���ҹؼ���Ϊname������Ԫ��
  	if (it == phone_book.end()) //�ж��Ƿ��ҵ�
     	cout << name << ": not found\n"; //δ�ҵ�
  	else
     	cout << it->first << ": " << it->second << endl; //�ҵ�
  	return 0;
}


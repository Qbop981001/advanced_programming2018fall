#include <iostream>
#include <list>
using namespace std;
int main()
{ 
	int m,n; //m���ڴ洢Ҫ��������n���ڴ洢С������
	cout << "������С���ĸ�����Ҫ��������";
	cin >> n >> m;
	list<int> children; 
	for (int i=0; i<n; i++) //ѭ����������Ԫ��
		children.push_back(i);
	list<int>::iterator current; //currentΪָ������Ԫ�صĵ�����
	current = children.begin(); //current��ʼ����ָ�������ĵ�һ��Ԫ��
	while (children.size() > 1) //ֻҪ����Ԫ�ظ�������1����ִ��ѭ��
	{  
		for (int count=1; count<m; count++)  //������ѭ��m-1��
		{ 
			current++; //currentָ����һ��Ԫ��
         	if (current == children.end()) //���currentָ���������ĩβ
            	current = children.begin();  //currentָ���һ��Ԫ��
       }
       //ѭ������ʱ��currentָ��Ҫ�뿪Ȧ�ӵ�С��
       current = children.erase(current);  //С���뿪Ȧ�ӣ�currentָ��
					       //��һ��Ԫ��
       if (current == children.end()) //���currentָ���������ĩβ
          current = children.begin();  //currentָ���һ��Ԫ��
   } //ѭ������ʱ��currentָ��������ʣ�µ�Ψһ��һ��Ԫ�أ���ʤ����
   //���ʤ���ߵı��
   cout << "The winner is No." << *current << "\n";
   return 0;
}


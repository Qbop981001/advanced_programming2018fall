#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
class String
{
private:
	char *str;
public:
	String(){str=NULL;}	
	String(const char *p){	str=new char[strlen(p)+1];	strcpy(str,p);}
	~String(){delete[] str; str=NULL;}
	int length(){return strlen(str);}
	char& char_at(int i) {
		if(i<0||i>strlen(str)){
			cerr<<"�����ַ�����Χ��"<<endl;
			exit(0);
		}
		return str[i]; //�����ǲ�������ʱ����ֱ�ӷ���str 
	}
	const char* getstr(){
		return str;
	} 
	String& copy(const char *p){
		delete[] str;
		str=new char[strlen(p)+1];
		strcpy(str,p);
		return *this;
	}
	String& copy(const String &s) { return copy(s.str); }//Ϊʲô���Է���s��˽�г�Ա����Ϊ
	//�������Ʊ�����������������һ����Ĳ�ͬ����ֻҪͬ��һ����Ϳ��Բ�������ͬһ����Ĳ�ͬ����
	//��ΪCExample(const CExample& RightSides) ����ĳ�Ա������������Ȩ�޷���˽�����ݳ�Ա�� 
	String& append(const char *p)
	{
		char *p1=new char[strlen(str)+strlen(p)+1];
		strcpy(p1,str);
		strcat(p1,p);
		delete[] str;
		str=p1;
		return *this;
	} 
	String& append(const String &s) {	return append(s.str);	}
	int compare(const char *p) {		return strcmp(str,p);	}
	int compare(String &s) {		return strcmp(str,s.str);	}
}; 
int main()
{
	String s1;
	String s2("abcdefg");
	s1.copy("xyz");
	s2.append(s1);

	for(int i=0; i<s2.length();i++)
	{
		if(s2.char_at(i) >= 'a' && s2.char_at(i) <= 'z')
			s2.char_at(i)=	s2.char_at(i)-'a'+'A';
	}
	if(s2.compare("ABCDEFGXYZ") == 0) 		cout<<"OK\n";
	cout << s1.getstr() <<endl<<s2.getstr()<<endl;
	return 0; 
}

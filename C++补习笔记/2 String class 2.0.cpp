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
	String(const String &s){	str=new char[strlen(s.str)+1];	strcpy(str,s.str);}
	~String(){delete[] str; str=NULL;}
	int length(){return strlen(str);}
	char& operator[](int i) {
		if(i<0||i>strlen(str)){
			cerr<<"超出字符串范围！"<<endl;
			exit(0);
		}
		return str[i]; //返回是不创建临时对象，直接返回str 
	}
	char operator[](int i)const {
		if(i<0||i>strlen(str)){
			cerr<<"超出字符串范围！"<<endl;
			exit(0);
		}
		return str[i];
	}
	operator const char*()const{
		return str;
	} 
	String& operator=(const char *p){
		delete[] str;
		str=new char[strlen(p)+1];
		strcpy(str,p);
		return *this;
	}
	String& operator=(const String &s) { 
		if(&s!=this)
			*this = s.str;
		return *this
	}
	String& operator+=(const char *p)
	{
		char *p1=new char[strlen(str)+strlen(p)+1];
		strcpy(p1,str);
		strcat(p1,p);
		delete[] str;
		str=p1;
		return *this;
	} 
	String& operator+=(const String &s) {	*this+=s.str; return *this;	}
	bool operator==(const char *p) {		return strcmp(str,p)==0;	}
	bool operator==(String &s) {		return strcmp(str,s.str)==0;	}
	friend bool operator ==(const char *p, const String &s);
	String operator+()
}; 
friend bool operator ==(const char *p, const String &s)
{
	return strcmp(p,str)==0;
}
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




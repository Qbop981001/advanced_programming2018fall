#include<iostream>
#include<cstdlib>
using namespace std;
class Vector; 
class Matrix
{
	int *p_data;
	int row,col;
public:
	Matrix(int r,int c)	{
		if(r<0 || c<0){
			cerr<<"����ߴ粻�Ϸ���"<<endl;
			exit(0);
		}
		row=r;	col=c;
		p_data = new int[row*col];
	}
	~Matrix(){
		delete []p_data;
	}
	int& element(int i,int j){
		if(i<0||i>=row||j<0||j>=col){
			cerr<<"�����±�Խ�磡"<<endl;
			exit(0);
		}
		return p_data[i*col+j];
	}
	int element(int i,int j)const{
		if(i<0||i>=row||j<0||j>=col){
			cerr<<"�����±�Խ�磡"<<endl;
			exit(0);
		}
		return p_data[i*col+j];
	}
	int dimension_row()const{return row;}
	int dimension_col()const{return col;}	
	void display()const{
		int *p=p_data;
		int i,j;
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				cout<<*p<<' '; p++;
			}
			cout<<endl;
		}
	}
	friend void multiply(const Matrix &m,const Vector &v, Vector &r);
};
class Vector
{
	int *p_data;
	int num;
public:
	Vector(int n ){
		if(n<=0){cerr<<"�����ߴ粻�Ϸ���\n";exit(0);}
		num=n;
		p_data = new int[num];
	}
	~Vector(){delete[] p_data;}
	//...
	int& element(int i){
		if(i<0||i>=num){
			cerr<<"�����±�Խ�磡"<<endl;
			exit(0);
		}
		return p_data[i];
	}	
	void display()const{
		int *p=p_data;
		int i,j;
		for(i=0;i<num;i++){
			cout<<*p<<' '; p++;
		}
		cout<<endl;
	}
	friend void multiply(const Matrix &m,const Vector &v, Vector &r);
};
void multiply(const Matrix &m,const Vector &v, Vector &r){
	if(m.col != v.num || m.row != r.num){
		cerr<<"����������ĳߴ粻ƥ�䣡"<<endl;
		exit(0);
	}
	int *p_m=m.p_data, *p_r=r.p_data,*p_v;
	for(int i=0; i<m.row; i++){
		*p_r=0;
		p_v = v.p_data;
		for(int j=0; j<m.col;j++){
			*p_r+=(*p_m)*(*p_v);
			p_m++;p_v++;
		}
		p_r++;
	}
}
int main()
{
	int row,column;
	cout<<"����������������������";
	cin>>row>>column;
	Matrix m(row,column);
	Vector v(column);
	Vector r(row);
	cout<<"���������Ԫ�أ�\n";
	int i,j;
	for(i=0; i<row; i++)
		for(j=0;j<column;j++)
			cin>>m.element(i,j);
	cout<<"����������Ԫ��:\n";
	for(i=0;i<column;i++)
		cin>> v.element(i);
	multiply(m,v,r);
	cout<<"����\n";
	m.display();
	cout<<"������:";
	v.display();
	cout<<"�ĳ˻�Ϊ��\n"; 
	r.display();
	return 0; 
	
}


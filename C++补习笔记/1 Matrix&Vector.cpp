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
			cerr<<"矩阵尺寸不合法！"<<endl;
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
			cerr<<"矩阵下标越界！"<<endl;
			exit(0);
		}
		return p_data[i*col+j];
	}
	int element(int i,int j)const{
		if(i<0||i>=row||j<0||j>=col){
			cerr<<"矩阵下标越界！"<<endl;
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
		if(n<=0){cerr<<"向量尺寸不合法！\n";exit(0);}
		num=n;
		p_data = new int[num];
	}
	~Vector(){delete[] p_data;}
	//...
	int& element(int i){
		if(i<0||i>=num){
			cerr<<"向量下标越界！"<<endl;
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
		cerr<<"矩阵和向量的尺寸不匹配！"<<endl;
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
	cout<<"请输入矩阵的行数和列数：";
	cin>>row>>column;
	Matrix m(row,column);
	Vector v(column);
	Vector r(row);
	cout<<"请输入矩阵元素：\n";
	int i,j;
	for(i=0; i<row; i++)
		for(j=0;j<column;j++)
			cin>>m.element(i,j);
	cout<<"请输入向量元素:\n";
	for(i=0;i<column;i++)
		cin>> v.element(i);
	multiply(m,v,r);
	cout<<"矩阵：\n";
	m.display();
	cout<<"与向量:";
	v.display();
	cout<<"的乘积为：\n"; 
	r.display();
	return 0; 
	
}


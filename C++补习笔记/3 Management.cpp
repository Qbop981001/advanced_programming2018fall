#include<string>
#include<iostream>
using namespace std;
class Employee
{
	int salary;
	string name;
public:
	Employee(const char *p,int n=0):name(p){
		salary=n;
	}
	void set_salary(int n) { salary = n; }
	int get_salary() const { return salary; }
	string get_name() const { return name; }
};
const int MAX_NUM_OF_EMPS=20;
class Manager: public Employee //部门经理类
{		
	Employee *group[MAX_NUM_OF_EMPS];//被管理的职员对象指针数组 
	int num_of_emps;
public:
	Manager(const char *s, int n=0): Employee(s,n) 
	{ 
		num_of_emps = 0; 
	}
	Employee *add_employee(Employee *e)
	{
		if(num_of_emps>MAX_NUM_OF_EMPS) {
			cout<<"人数已满，无法增加!"<<endl;
			return NULL;
		}
		group[num_of_emps]=e;
		num_of_emps++;
		return e;
	}
	Employee *remove_employee(Employee *e)
	{
		int i,j;
		for(i=0;i<num_of_emps;i++){
			if(e->get_name()==group[i]->get_name())
				break;
		}
		if(i==num_of_emps) {
			cout<<"没有找到！"<<endl;
			return NULL;
		}
		else{
			for(j=i+1;j<num_of_emps;j++)
				group[j-1]=group[j];
			num_of_emps--;	
			return e;
		}
	}
};
int main()
{
	Employee e1("Jack",1000),e2("Jane",2000);
Manager m("Mark",4000);
m.add_employee(&e1);
m.add_employee(&e2);
cout << m.get_salary() << endl;
return 0;
}
		


#include<iostream> 
using namespace std;
template<class T>
class Vector {
public:
	typedef T* iterator;
	iterator start; //动态数组入口，成员变量
	size_t m_size; //当前数组大小，成员变量
	size_t m_capacity; //Vector 所能容纳的最大元素数量，成员变量

	Vector(size_t c)//初始化一个容量为 c 的 Vector，需要申请空间
	{
		start=new T[m_capacity];
		m_size=c;
	}
	~Vector() //析构函数，清理空间
	{
		delete[]start;
		start=NULL;
		m_size=0;
	}

	void push_back(T e) //在尾部增加一个元素
	{
		if(m_size==m_capacity) 
		{
			cerr<<"容器已满！"<<endl; exit(0);
		}
		start[m_size]=e;
		m_size++;
	}
	size_t size()
	{
		return m_size;
	}
	iterator begin() //返回第一个元素的迭代器
	{
		return start;
	}

	iterator end()//返回最后一个元素后面一个位置的迭代器，即[begin, end)
	{
		return (start+m_size);
	} 
	//在 it 前插入一个元素，返回的迭代器指向插入元素
	iterator insert(iterator it, T e)
	{
		int i,j;
		for(i=0;i<m_size;i++){
			if((start+i)==it) break;
		}
		for(j=i;j<m_size;j++)
			start[j+1]=start[j];
		m_size++;
		start[i]=e;
		return (start+i);
	}
	//删除 it 指向的元素，返回的迭代器指向删除元素的下一个元素
	iterator erase(iterator it)
	{
		int i,j;
		for(i=0;i<m_size;i++){
			if((start+i)==it) break;
		}
		for(j=i;j<m_size-1;j++)
			start[j]=start[j+1];
		m_size--;
		return (start+i+1);
	}
	//TODO: 重载 [] 操作，返回相应元素的引用
	T& operator[](int i)
	{
		return start[i];
	}
};
int main()
{
	int array[5] = {5,4,3,1,2};
	Vector<int> v(20);
    Vector<int>::iterator it = v.begin();
    for(int i=0; i < 5; i++){
        it = v.insert(it, array[i]);
    }
    return 0;
}

/*
template<typename T>
void test(T *array, int len) {
    Vector<T> v(20);
    typename Vector<T>::iterator it = v.begin();
    for(int i=0; i < len; i++){
        it = v.insert(it, array[i]);
    }
    v.insert(v.end(), array[0]);
    it = v.begin() + 2;
    it = v.erase(it);
    it = v.erase(it);
    for(size_t i=0; i < v.size(); i++){
        cout << v[i] << endl;
    }

}

int main() {
    int mode = 0;
    cin >> mode;
    switch(mode) {
        case 1: {
           int i_array[5] = {5,4,3,1,2};
           test(i_array, 5);
           break;
        }
        case 2: {
           char c_array[10] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q'};
           test(c_array, 10);
           break;
        }
        case 3: {
           float f_array[9] = {9.99, 8.88, 7.77, 6.66, 5.55, 4.44, 3.33, 2.22, 1.11};
           test(f_array, 9);
           break;
        }
        case 4: {
           string s_array[4] = {"ddddd", "ccccc", "bbb", "aa"};
           test(s_array, 4);
           break;
        }
        case 5: {
           double d_array[9] = {0.99999, 0.99998, 0.99997, 0.99996, 0.99995, 0.99994, 0.99993, 0.99992, 0.99991};
           test(d_array, 9);
           break;
        }
    }
    return 0;
}
*/

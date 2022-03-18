#include<iostream>
using namespace std;

class MyIntArray
{
public:

	//有参构造
	MyIntArray(int size)
	{
		this->m_size = size;
		this->data = new int[m_size];
	}

	//拷贝构造
	MyIntArray(const MyIntArray& mia)
	{
		this->m_size = mia.m_size;
		this->data = new int[m_size];

		for (int i = 0; i < this->m_size; i++)
		{
			this->data[i] = mia.data[i];
		}
	}

	//析构函数
	~MyIntArray()
	{
		if (this->data != NULL)
			delete data;
	}

	//获取数组长度
	int getArraySize()
	{
		return this->m_size;
	}

	//根据下标设置值
	void setValue(int pos,int value)
	{
		this->data[pos] = value;
	}

	//根据下标返回值
	int getValue(int pos)
	{
		return this->data[pos];
	}

	//返回数组最大值
	int getMaxValue()
	{
		int max = this->data[0];
		for (int i = 1; i < m_size; i++)
		{
			if (data[i] > max)
				max = data[i];
		}

		return max;
	}

	//返回数组最小值
	int getMinValue()
	{
		int min = this->data[0];
		for (int i = 1; i < m_size; i++)
		{
			if (data[i] < min)
				min = data[i];
		}

		return min;
	}

	//按下标删除元素
	void deleteByIndex(int pos)
	{
		for (int i = pos; i < this->m_size-1; i++)		
			this->data[i] = data[i + 1];

		this->m_size--;
	}

	//打印数组元素
	void printArray()
	{
		for (int i = 0; i < this->m_size; i++)
			cout << data[i] << " ";
		cout << endl;
	}

private:
	int m_size;
	int* data ;
};

int main()
{
	MyIntArray mia1(10);

	//设置元素 从 1 到 10
	for(int i=0;i<10;i++)
		mia1.setValue(i, i+1);

	cout << "数组 mia1 的元素：" << endl;
	mia1.printArray();  //打印数组元素

	MyIntArray mia2(mia1);  //拷贝构造赋值

	cout << "数组 mia2 的元素：" << endl;
	mia2.printArray();

	mia2.deleteByIndex(4);  //删除下标为 4 的元素

	cout << "删除下标为 4 的元素后数组 mia2 的元素：" << endl;
	mia2.printArray();

	cout << "数组 mia2 的最大值为：" << endl;
	cout << mia2.getMaxValue() << endl;

	cout << "数组 mia2 的最小值为：" << endl;
	cout << mia2.getMinValue() << endl;

	cout << "数组 mia2 的长度为：" << endl;
	cout << mia2.getArraySize() << endl;

	return 0;
}
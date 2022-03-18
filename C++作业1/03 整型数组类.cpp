#include<iostream>
using namespace std;

class MyIntArray
{
public:

	//�вι���
	MyIntArray(int size)
	{
		this->m_size = size;
		this->data = new int[m_size];
	}

	//��������
	MyIntArray(const MyIntArray& mia)
	{
		this->m_size = mia.m_size;
		this->data = new int[m_size];

		for (int i = 0; i < this->m_size; i++)
		{
			this->data[i] = mia.data[i];
		}
	}

	//��������
	~MyIntArray()
	{
		if (this->data != NULL)
			delete data;
	}

	//��ȡ���鳤��
	int getArraySize()
	{
		return this->m_size;
	}

	//�����±�����ֵ
	void setValue(int pos,int value)
	{
		this->data[pos] = value;
	}

	//�����±귵��ֵ
	int getValue(int pos)
	{
		return this->data[pos];
	}

	//�����������ֵ
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

	//����������Сֵ
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

	//���±�ɾ��Ԫ��
	void deleteByIndex(int pos)
	{
		for (int i = pos; i < this->m_size-1; i++)		
			this->data[i] = data[i + 1];

		this->m_size--;
	}

	//��ӡ����Ԫ��
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

	//����Ԫ�� �� 1 �� 10
	for(int i=0;i<10;i++)
		mia1.setValue(i, i+1);

	cout << "���� mia1 ��Ԫ�أ�" << endl;
	mia1.printArray();  //��ӡ����Ԫ��

	MyIntArray mia2(mia1);  //�������츳ֵ

	cout << "���� mia2 ��Ԫ�أ�" << endl;
	mia2.printArray();

	mia2.deleteByIndex(4);  //ɾ���±�Ϊ 4 ��Ԫ��

	cout << "ɾ���±�Ϊ 4 ��Ԫ�غ����� mia2 ��Ԫ�أ�" << endl;
	mia2.printArray();

	cout << "���� mia2 �����ֵΪ��" << endl;
	cout << mia2.getMaxValue() << endl;

	cout << "���� mia2 ����СֵΪ��" << endl;
	cout << mia2.getMinValue() << endl;

	cout << "���� mia2 �ĳ���Ϊ��" << endl;
	cout << mia2.getArraySize() << endl;

	return 0;
}
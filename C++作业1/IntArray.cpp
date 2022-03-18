#include <iostream>
#include<ctime>
using namespace std;

class IntArray
{
public:
    //�޲ι���
    IntArray()    
    {
        this->size = 10;
        pArr = new int[size];

        for (int i = 0; i < 10; i++)
        {
            pArr[i] = rand() % 100;
        }
    }

    //�вι���
    IntArray(int length)
    {
        this->size = length;
        pArr = new int[length];
        for (int i = 0; i < length; i++)
        {
            pArr[i] = rand() % 100;
        }
    }

    //��������
    IntArray(IntArray& ia)
    {
        this->pArr = new int[ia.size];
        this->size = ia.size;

        for (int i = 0; i < this->size; i++)
        {
            this->pArr[i] = ia.pArr[i];
        }
    }

    //��������
    ~IntArray()
    {
        if (pArr != NULL)
            delete pArr;
    }

    //����������С����
    void sortArray()
    {
        for (int i = 0; i < this->size; i++)
        {
            for (int j = 0; j < this->size - i - 1;j++)
            {
                if (pArr[j] > pArr[j + 1])
                {
                    int temp = pArr[j];
                    pArr[j] = pArr[j + 1];
                    pArr[j + 1] = temp;
                }
            }
        }
    }

    //�������ֵ
    int getMaxNumber()
    {
        this->sortArray();
        return this->pArr[this->size - 1];
    }

    //������Сֵ
    int getMinNumber()
    {
        this->sortArray();
        return this->pArr[0];
    }

    //����ƽ��ֵ
    double getAverageNumber()
    {
        int sum = 0;
        for (int i = 0; i < this->size; i++)
        {
            sum += pArr[i];
        }

        return (sum * 1.0) / this->size;
    }

    //�����±귵������Ԫ��
    int getNumberByIndex(int i)
    {
        return pArr[i];
    }

    //�������Ԫ��
    void showArray()
    {
        for (int i = 0; i < this->size; i++)
        {
            cout << pArr[i] << " ";

        }
        cout << endl;
    }

private:
    int* pArr;
    int size;
};

int main()
{
    srand((int)time(0));
    IntArray iA1;
    IntArray iA2(8);

    iA1.sortArray();
    iA2.sortArray();

    cout << "iA1����Ԫ�أ�";
    iA1.showArray();
    cout << "���ֵ" << iA1.getMaxNumber() << endl;
    cout << "��Сֵ" << iA1.getMinNumber() << endl;
    cout << "ƽ��ֵ" << iA1.getAverageNumber() << endl;

    cout << "=========================" << endl;

    cout << "iA2����Ԫ�أ�";
    iA2.showArray();
    cout << "���ֵ" << iA2.getMaxNumber() << endl;
    cout << "��Сֵ" << iA2.getMinNumber() << endl;
    cout << "ƽ��ֵ" << iA2.getAverageNumber() << endl;



    return 0;
}
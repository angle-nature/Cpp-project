#include <iostream>
#include<ctime>
using namespace std;

class IntArray
{
public:
    //无参构造
    IntArray()    
    {
        this->size = 10;
        pArr = new int[size];

        for (int i = 0; i < 10; i++)
        {
            pArr[i] = rand() % 100;
        }
    }

    //有参构造
    IntArray(int length)
    {
        this->size = length;
        pArr = new int[length];
        for (int i = 0; i < length; i++)
        {
            pArr[i] = rand() % 100;
        }
    }

    //拷贝构造
    IntArray(IntArray& ia)
    {
        this->pArr = new int[ia.size];
        this->size = ia.size;

        for (int i = 0; i < this->size; i++)
        {
            this->pArr[i] = ia.pArr[i];
        }
    }

    //析构函数
    ~IntArray()
    {
        if (pArr != NULL)
            delete pArr;
    }

    //排序函数（从小到大）
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

    //返回最大值
    int getMaxNumber()
    {
        this->sortArray();
        return this->pArr[this->size - 1];
    }

    //返回最小值
    int getMinNumber()
    {
        this->sortArray();
        return this->pArr[0];
    }

    //返回平均值
    double getAverageNumber()
    {
        int sum = 0;
        for (int i = 0; i < this->size; i++)
        {
            sum += pArr[i];
        }

        return (sum * 1.0) / this->size;
    }

    //根据下标返回数组元素
    int getNumberByIndex(int i)
    {
        return pArr[i];
    }

    //输出数组元素
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

    cout << "iA1所有元素：";
    iA1.showArray();
    cout << "最大值" << iA1.getMaxNumber() << endl;
    cout << "最小值" << iA1.getMinNumber() << endl;
    cout << "平均值" << iA1.getAverageNumber() << endl;

    cout << "=========================" << endl;

    cout << "iA2所有元素：";
    iA2.showArray();
    cout << "最大值" << iA2.getMaxNumber() << endl;
    cout << "最小值" << iA2.getMinNumber() << endl;
    cout << "平均值" << iA2.getAverageNumber() << endl;



    return 0;
}
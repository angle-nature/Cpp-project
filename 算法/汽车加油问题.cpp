#include<iostream>
using namespace std;

#define MAXNUMBER 1001

int main()
{
	int n, k,myCount = 0;    //n：汽车每次加油可行驶距离   k：加油站个数
	cin >> n >> k;
	int constant[MAXNUMBER];
	for (int i = 0; i < k+1; i++)
		cin >> constant[i];

	int constantable = n;  //汽车剩余可行驶距离

	for (int i = 0; i < k + 1; i++)
	{
		if (n < constant[i]) //如果汽车加满油可行驶距离小于两加油站之间的距离 则无法到达
		{
			cout << "No Solution!" << endl;
			exit(0);
		}
		else if (constantable >= constant[i]) //如果剩余可行驶距离可达到下一个加油站，则继续行驶		 
			constantable -= constant[i]; //更新剩余可行驶距离
		else
		{
			myCount++; //剩余可行驶距离无法到达 则加油
			constantable =  n - constant[i]; //更新剩余可行驶距离
		}
	}
	cout << myCount << endl; //输出加油次数
	return 0;
}
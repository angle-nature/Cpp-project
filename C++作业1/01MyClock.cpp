#include<iostream>
using namespace std;

class MyClock
{
private:
	int hour;
	int minute;
	int second;
public:
	MyClock(int h,int m,int s):hour(h),minute(m),second(s){}

	void ShowTime()
	{
		cout << hour << ":" << minute << ":" << second << endl;
	}

	MyClock operator++(int) //ºóÖÃ×ÔÔö
	{
		MyClock temp = *this;
		this->second = (this->second + 1) % 60;
		if (this->second == 0)
		{
			this->minute = (minute + 1) % 60;
			if (this->minute == 0)
				this->hour = (hour + 1) % 24;
		}
		return temp;
	}

	MyClock& operator++()
	{
		this->second = (this->second + 1) % 60;
		if (this->second == 0)
		{
			this->minute = (minute + 1) % 60;
			if (this->minute == 0)
				this->hour = (hour + 1) % 24;
		}
		return *this;
	}
};

int main()
{
	MyClock myClock(23, 59, 59);
	myClock.ShowTime();
	(myClock++).ShowTime();
	(++myClock).ShowTime();
	return 0;
}

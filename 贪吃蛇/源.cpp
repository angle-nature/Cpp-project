#include<iostream>
#include<ctime>
#include<windows.h>
#include<vector>
#include <conio.h>
using namespace std;


void gotoxy(int x, int y)   //光标定位
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


//食物类
class Food
{
private:
    int m_x;
    int m_y;
public:
    void randfood()         //随机产生一个食物
    {
        srand((int)time(NULL));//利用时间添加随机数种子，需要ctime头文件
    L1:
        m_x = rand() % (85) + 2;//2~86
        m_y = rand() % (25) + 2;//2~26

        if (m_x % 2)        //如果食物的x坐标不是偶数则重新确定食物的坐标
            goto L1;

        gotoxy(m_x, m_y);   //在确认好的位置输出食物
        cout << "★";
    }
    int getFoodm_x()        //返回食物的x坐标
    {
        return m_x;
    }
    int getFoodm_y()        //返回食物的y坐标
    {
        return m_y;
    }
};

//蛇类
class Snake
{
private:
    struct Snakecoor//定义一个蛇的坐标结构体
    {
        int x;
        int y;

    };
    vector<Snakecoor> snakecoor;//将蛇坐标存入vector容器中

    //判断并改变前进方向的函数
    void degdir(Snakecoor& nexthead)   //定义新的蛇头变量
    {
        static char key = 'd';  //静态变量防止改变移动方向后重新改回来

        if (_kbhit())
        {
            char temp = _getch();//定义一个临时变量储存键盘输入的值

            switch (temp)     //如果临时变量的值为wasd中的一个，则赋值给key
            {
            default:    //default是缺省情况，只有任何条件都不匹配的情况下才会执行 必须写在前面！不然蛇无法转向
                break;
            case'w':
            case'a':
            case's':
            case'd':

                //如果temp的方向和key的方向不相反则赋值  因为两次移动方向不能相反  将蛇设置为初始向右走
                if ((key == 'w' && temp != 's') || (key == 's' && temp != 'w') || \
                    (key == 'a' && temp != 'd') || (key == 'd' && temp != 'a'))
                    key = temp;
            }

        }

        switch (key)   //根据key的值来确定蛇的移动方向
        {
        case'd':
            nexthead.x = snakecoor.front().x + 2;  //新的蛇头的头部等于容器内第一个数据(旧蛇头)x坐标+2 因为蛇头占两个坐标，移动一次加2
            nexthead.y = snakecoor.front().y;
            break;
        case 'a':
            nexthead.x = snakecoor.front().x - 2;
            nexthead.y = snakecoor.front().y;
            break;
        case 'w':
            nexthead.x = snakecoor.front().x;
            nexthead.y = snakecoor.front().y - 1;  //因为控制台的x长度是y的一半，所以用两个x做蛇头，需要的坐标是二倍
            break;
        case 's':
            nexthead.x = snakecoor.front().x;
            nexthead.y = snakecoor.front().y + 1;
        }

    }
    //游戏结束时设计一个界面输出“游戏结束”以及分数
    void finmatt(const int score)
    {
        system("cls");//清屏然后输出
        gotoxy(40, 14);
        cout << "游戏结束";
        gotoxy(40, 16);
        cout << "得分：" << score;
        gotoxy(0, 26);
        exit(0);//exit为C++的退出函数  exit(0)表示程序正常退出，非0表示非正常退出
    }
    //游戏结束
    void finishgame(const int score)
    {
        //撞墙
        if (snakecoor[0].x >= 88 || snakecoor[0].x < 0 || snakecoor[0].y >= 28 || snakecoor[0].y < 0)
            finmatt(score);

        //撞到自身
        for (int i = 1; i < snakecoor.size(); i++)
            if (snakecoor[0].x == snakecoor[i].x && snakecoor[0].y == snakecoor[i].y)
                finmatt(score);
    }

public:
    //构造初始化蛇的位置
    Snake()
    {
        Snakecoor temp; //临时结构变量用于创建蛇

        for (int i = 5; i >= 0; i--)    //反向创建初始蛇身，初始蛇头朝右
        {
            temp.x = 16 + (i << 1);     //偶数 在蛇头左移生成蛇身
            temp.y = 8;
            snakecoor.push_back(temp);//在蛇尾尾插入临时变量
        }

    }
    //蛇运动的函数
    void move(Food& food, int& score)
    {
        Snakecoor nexthead;         //新蛇头变量

        degdir(nexthead);               //判断和改变蛇前进的方向

        snakecoor.insert(snakecoor.begin(), nexthead);  //将蛇头插入容器的头部

        gotoxy(0, 0);
        cout << "得分：" << score; //每次移动都在左上角刷新得分
        gotoxy(0, 2);
        cout << "蛇的长度为：" << snakecoor.size();//长度用来测试

        finishgame(score);              //判断游戏结束，输出分数

        //吃到食物蛇的变化
        if (snakecoor[0].x == food.getFoodm_x() && snakecoor[0].y == food.getFoodm_y()) //蛇头与食物重合
        {
            gotoxy(snakecoor[0].x, snakecoor[0].y);     //吃到食物时这次蛇没有移动，所以蛇会卡顿一下
            cout << "●";                                //重新输出一下蛇头和第一节蛇身让蛇不卡顿
            gotoxy(snakecoor[1].x, snakecoor[1].y);
            cout << "■";


            score++;             //吃到食物得分+1

            food.randfood();     //如果蛇头坐标和食物坐标重合则重新产生一个食物
            return;              //直接结束本次移动
        }
        for (int i = 0; i < snakecoor.size(); i++)  //遍历容器，判断食物与蛇身是否重合并输出整条蛇
        {
            gotoxy(snakecoor[i].x, snakecoor[i].y);

            if (!i)                             //头部输出圆形否则输出方块
                cout << "●";
            else
                cout << "■";

            //如果食物刷新到了蛇身上，则重新产生一个食物
            if (snakecoor[i].x == food.getFoodm_x() && snakecoor[i].y == food.getFoodm_y())
                food.randfood();
        }


        //清除蛇尾  数据与画面是分开的
        gotoxy(snakecoor.back().x, snakecoor.back().y); //在容器尾部的地方输出空格 清除画面上的蛇尾
        cout << "  ";
        snakecoor.pop_back();                       //删除容器中最后一个数据  清除数据上的蛇尾
    }

};


void HideCursor()           //隐藏光标
{
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}


int main()
{
    system("mode con cols=88 lines=28");   //设置控制台窗口大小
    system("title 贪吃蛇");            //设置标题
    HideCursor();                          //光标隐藏

    int score = 0;              //得分变量

    Food food;                  //食物对象
    food.randfood();            //开局随机产生一个食物

    Snake snake;                //蛇对象


    while (true)
    {
        snake.move(food, score);//蛇移动

        Sleep(150);     //游戏速度
    }

    return 0;
}

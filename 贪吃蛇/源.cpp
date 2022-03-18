#include<iostream>
#include<ctime>
#include<windows.h>
#include<vector>
#include <conio.h>
using namespace std;


void gotoxy(int x, int y)   //��궨λ
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


//ʳ����
class Food
{
private:
    int m_x;
    int m_y;
public:
    void randfood()         //�������һ��ʳ��
    {
        srand((int)time(NULL));//����ʱ�������������ӣ���Ҫctimeͷ�ļ�
    L1:
        m_x = rand() % (85) + 2;//2~86
        m_y = rand() % (25) + 2;//2~26

        if (m_x % 2)        //���ʳ���x���겻��ż��������ȷ��ʳ�������
            goto L1;

        gotoxy(m_x, m_y);   //��ȷ�Ϻõ�λ�����ʳ��
        cout << "��";
    }
    int getFoodm_x()        //����ʳ���x����
    {
        return m_x;
    }
    int getFoodm_y()        //����ʳ���y����
    {
        return m_y;
    }
};

//����
class Snake
{
private:
    struct Snakecoor//����һ���ߵ�����ṹ��
    {
        int x;
        int y;

    };
    vector<Snakecoor> snakecoor;//�����������vector������

    //�жϲ��ı�ǰ������ĺ���
    void degdir(Snakecoor& nexthead)   //�����µ���ͷ����
    {
        static char key = 'd';  //��̬������ֹ�ı��ƶ���������¸Ļ���

        if (_kbhit())
        {
            char temp = _getch();//����һ����ʱ����������������ֵ

            switch (temp)     //�����ʱ������ֵΪwasd�е�һ������ֵ��key
            {
            default:    //default��ȱʡ�����ֻ���κ���������ƥ�������²Ż�ִ�� ����д��ǰ�棡��Ȼ���޷�ת��
                break;
            case'w':
            case'a':
            case's':
            case'd':

                //���temp�ķ����key�ķ����෴��ֵ  ��Ϊ�����ƶ��������෴  ��������Ϊ��ʼ������
                if ((key == 'w' && temp != 's') || (key == 's' && temp != 'w') || \
                    (key == 'a' && temp != 'd') || (key == 'd' && temp != 'a'))
                    key = temp;
            }

        }

        switch (key)   //����key��ֵ��ȷ���ߵ��ƶ�����
        {
        case'd':
            nexthead.x = snakecoor.front().x + 2;  //�µ���ͷ��ͷ�����������ڵ�һ������(����ͷ)x����+2 ��Ϊ��ͷռ�������꣬�ƶ�һ�μ�2
            nexthead.y = snakecoor.front().y;
            break;
        case 'a':
            nexthead.x = snakecoor.front().x - 2;
            nexthead.y = snakecoor.front().y;
            break;
        case 'w':
            nexthead.x = snakecoor.front().x;
            nexthead.y = snakecoor.front().y - 1;  //��Ϊ����̨��x������y��һ�룬����������x����ͷ����Ҫ�������Ƕ���
            break;
        case 's':
            nexthead.x = snakecoor.front().x;
            nexthead.y = snakecoor.front().y + 1;
        }

    }
    //��Ϸ����ʱ���һ�������������Ϸ�������Լ�����
    void finmatt(const int score)
    {
        system("cls");//����Ȼ�����
        gotoxy(40, 14);
        cout << "��Ϸ����";
        gotoxy(40, 16);
        cout << "�÷֣�" << score;
        gotoxy(0, 26);
        exit(0);//exitΪC++���˳�����  exit(0)��ʾ���������˳�����0��ʾ�������˳�
    }
    //��Ϸ����
    void finishgame(const int score)
    {
        //ײǽ
        if (snakecoor[0].x >= 88 || snakecoor[0].x < 0 || snakecoor[0].y >= 28 || snakecoor[0].y < 0)
            finmatt(score);

        //ײ������
        for (int i = 1; i < snakecoor.size(); i++)
            if (snakecoor[0].x == snakecoor[i].x && snakecoor[0].y == snakecoor[i].y)
                finmatt(score);
    }

public:
    //�����ʼ���ߵ�λ��
    Snake()
    {
        Snakecoor temp; //��ʱ�ṹ�������ڴ�����

        for (int i = 5; i >= 0; i--)    //���򴴽���ʼ������ʼ��ͷ����
        {
            temp.x = 16 + (i << 1);     //ż�� ����ͷ������������
            temp.y = 8;
            snakecoor.push_back(temp);//����ββ������ʱ����
        }

    }
    //���˶��ĺ���
    void move(Food& food, int& score)
    {
        Snakecoor nexthead;         //����ͷ����

        degdir(nexthead);               //�жϺ͸ı���ǰ���ķ���

        snakecoor.insert(snakecoor.begin(), nexthead);  //����ͷ����������ͷ��

        gotoxy(0, 0);
        cout << "�÷֣�" << score; //ÿ���ƶ��������Ͻ�ˢ�µ÷�
        gotoxy(0, 2);
        cout << "�ߵĳ���Ϊ��" << snakecoor.size();//������������

        finishgame(score);              //�ж���Ϸ�������������

        //�Ե�ʳ���ߵı仯
        if (snakecoor[0].x == food.getFoodm_x() && snakecoor[0].y == food.getFoodm_y()) //��ͷ��ʳ���غ�
        {
            gotoxy(snakecoor[0].x, snakecoor[0].y);     //�Ե�ʳ��ʱ�����û���ƶ��������߻Ῠ��һ��
            cout << "��";                                //�������һ����ͷ�͵�һ���������߲�����
            gotoxy(snakecoor[1].x, snakecoor[1].y);
            cout << "��";


            score++;             //�Ե�ʳ��÷�+1

            food.randfood();     //�����ͷ�����ʳ�������غ������²���һ��ʳ��
            return;              //ֱ�ӽ��������ƶ�
        }
        for (int i = 0; i < snakecoor.size(); i++)  //�����������ж�ʳ���������Ƿ��غϲ����������
        {
            gotoxy(snakecoor[i].x, snakecoor[i].y);

            if (!i)                             //ͷ�����Բ�η����������
                cout << "��";
            else
                cout << "��";

            //���ʳ��ˢ�µ��������ϣ������²���һ��ʳ��
            if (snakecoor[i].x == food.getFoodm_x() && snakecoor[i].y == food.getFoodm_y())
                food.randfood();
        }


        //�����β  �����뻭���Ƿֿ���
        gotoxy(snakecoor.back().x, snakecoor.back().y); //������β���ĵط�����ո� ��������ϵ���β
        cout << "  ";
        snakecoor.pop_back();                       //ɾ�����������һ������  ��������ϵ���β
    }

};


void HideCursor()           //���ع��
{
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}


int main()
{
    system("mode con cols=88 lines=28");   //���ÿ���̨���ڴ�С
    system("title ̰����");            //���ñ���
    HideCursor();                          //�������

    int score = 0;              //�÷ֱ���

    Food food;                  //ʳ�����
    food.randfood();            //�����������һ��ʳ��

    Snake snake;                //�߶���


    while (true)
    {
        snake.move(food, score);//���ƶ�

        Sleep(150);     //��Ϸ�ٶ�
    }

    return 0;
}

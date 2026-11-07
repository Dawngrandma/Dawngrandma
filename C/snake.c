#include <stdio.h>
#include <stdlib.h>
#include <conio.h>//windows特有的库，用来接收后面键盘的输入
#include <windows.h>// 需要用到 Sleep() 函数来控制速度
#include<time.h>

#define WIDTH 60
#define HEIGHT 25

int main() {
    //蛇的自动移动
    int dir=4;
    //食物随机出现的准备工作
    srand(time(NULL));
    int flag1=1;
    int flag=1;
    int n=0;
    int a=rand()%(HEIGHT-2)+1;
    int b=rand()%(WIDTH-2)+1;
    //设置蛇身体的坐标
    int y[100]={0};
    int x[100]={0};
    //给蛇头整个初始坐标
    y[0]=3;
    x[0]=3;
    //记录蛇尾的坐标
    int oldy;
    int oldx;
    char key; // 用来记录键盘按下的键
    // 游戏主循环：死循环，游戏不关就一直跑
    while (1) {
        //擦黑板
        system("cls");
        //准备地图（每次循环都要重新建一个空白地图）
        int map[HEIGHT][WIDTH] = {0};
        // 画墙
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                    map[i][j] = 1;
                }
            }
        }
        for(int i=n;i>=0;i--){
            map[y[i]][x[i]]=2;
        }
        //记录蛇尾坐标
        oldy=y[n];
        oldx=x[n];
        //食物开始时随机出现
        do{
            if(map[a][b]!=0){
                flag1=0;
                a=rand()%(HEIGHT-2)+1;
                b=rand()%(WIDTH-2)+1;
            }
            else{
                map[a][b]=3;
                flag1=1;
            }
        }while(flag1==0);
        //重新画地图
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (map[i][j] == 1) printf("#");
                else if (map[i][j] == 2) printf("O");
                else if (map[i][j] == 3) printf("*");
                else printf(" ");
            }
            printf("\n");
        } 
        //控制蛇身移动
            for(int i=n;i>0;i--){
                y[i]=y[i-1];
                x[i]=x[i-1];
            }
        //蛇自动移动
        switch(dir){
            case 1:y[0]--;break;
            case 2:y[0]++;break;
            case 3:x[0]--;break;
            case 4:x[0]++;break;
        }
        //监听键盘输入
        while(_kbhit()) { // 如果检测到按键
            key = _getch(); // 获取按下的键（不需要按回车）
            // 根据按键改变坐标
            if (key == 'w' || key == 'W' && dir!=2) dir=1; 
            if (key == 's' || key == 'S' && dir!=1) dir=2; 
            if (key == 'a' || key == 'A' && dir!=4) dir=3; 
            if (key == 'd' || key == 'D' && dir!=2) dir=4; 
        }
        //撞墙结束游戏
        if (x[0] <= 0 || x[0] >= WIDTH - 1 || y[0] <= 0 || y[0] >= HEIGHT - 1) {
            flag=0;
        }
        //蛇头碰蛇身结束
        for(int i=1;i<=n;i++){
            if(x[0]==x[i]&&y[0]==y[i]){
                flag=0;
                break;
            }
        }
        if(flag==0){
            printf("YOU ARE DIED!");
            system("pause");
            break;
        }
        if(a==y[0]&b==x[0]){
            a=rand()%(HEIGHT-2)+1;
            b=rand()%(WIDTH-2)+1;
            n++;
            y[n]=oldy;
            x[n]=oldx;
        }
        //控制游戏速度（暂停 1000 毫秒(一秒)，如果不加这个，屏幕会闪瞎眼）
        Sleep(100); 
    }
    return 0;
}
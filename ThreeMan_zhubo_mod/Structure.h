#ifndef __STRUCTURE_H__
#define __STRUCTURE_H__

#include <QLabel>
#include <string>
using namespace  std;

typedef struct{
    QLabel *label;
    string face = ""; //面板
    int num = 0;
    bool hua = false;//true 为花牌，用于判断是否是5花牛
    int color = -1;//3代表黑桃，2代表红桃，1代表梅花，0代表方块
}CARD;

typedef struct node{
    CARD data[3] = {};
    int num;// 0 代表闲家1 3代表庄家
    struct node *next;
}SEVENMAN;

//分针走一轮，时针走一格
typedef struct{
    int man = 0;//第几个玩家
    int num = 0;//第几张牌
    void increase(){
        if(++man == 7){
            num++;
            man = 0;
        }
    }
}NUMBER;

typedef struct{
    int paiXing;
    CARD biggest;
    int huaNum;
}PAIRESULT;

typedef struct{
    string face;
    bool win;
} LABELRESULT;

#endif

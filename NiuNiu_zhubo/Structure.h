#ifndef __STRUCTURE_H__
#define __STRUCTURE_H__

#include <QLabel>
#include <string>
using namespace std;

typedef struct{
    int num = 0;
    int color = -1;
    bool hua = false;
    QLabel *label;
    string face = "";
}CARD;

typedef struct node{
    int num;// 0 代表闲家1 3代表庄家
    struct node *next;
    CARD data[5] = {};
}players;

//分针走一轮，时针走一格
typedef struct{
    int man = 0;//第几个玩家
    int num = 0;//第几张牌
    void increase(){
        if(++man == 4){
            num++;
            man = 0;
        }
    }
}NUMBER;

typedef struct{
    int paiXing;
    CARD biggest;
}PAIRESULT;

typedef struct{
    string face;
    bool win;
} LABELRESULT;

#endif

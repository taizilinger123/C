#include "snakegame.h"
#include <QTime>
#include <QTimer>
#include <QMessageBox>
SnakeGame::SnakeGame(){
    this->resize(760,600);
    qsrand(QTime::currentTime().msec());
    foodLen=40;
    snake.push_back(getFood());//蛇吃了食物
    food=getFood();
    dire=D_RIGHT;
    maxLen=5;
    timer=new QTimer();
    timer->setInterval(200);
    timer->start();
    /*连接timer timeout this snakeMove*/
    connect(timer,SIGNAL(timeout()),this,SLOT(snakeMove()));
}
SnakeGame::~SnakeGame(){}
/*根据方向移动 走一个食物的大小*/
void  SnakeGame::snakeMove(){
    /*获得蛇头原来的坐标*/
    int x=snake[0]->x();
    int y=snake[0]->y();
    if(x==food->x()&&y==food->y()){
        snake.push_back(food);
        food=getFood();
    }
    /*后面的元素跟着前面的元素跑*/
    for(int i=snake.size()-1;i>0;i--){
        snake[i]->move(snake[i-1]->x(),
                       snake[i-1]->y());
    }
	/*蛇状态的其它判断?*/
    if(snake.size()>=maxLen){
        QMessageBox  msg;
        msg.setText("maxlen game over?");
        msg.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
        if(msg.exec()==QMessageBox::Yes){
            this->close();
        }else{
            maxLen=maxLen*2+1;
        }
    }
    /*是否撞墙
    if(){

    }*/
    switch(dire){
        case D_UP:
        y=y-foodLen;
        break;
        case D_DOWN:
        y=y+foodLen;
        break;
        case D_LEFT:
        x=x-foodLen;
        break;
        case D_RIGHT:
        x=x+foodLen;
        break;
    }
    /*把蛇头移动到新位置*/
    snake[0]->move(x,y);
}
/*产生新食物的函数*/
QLabel*  SnakeGame::getFood(){
    food=new QLabel(this);//this指定父窗口，不指定蛇够不着
    food->resize(foodLen,foodLen);
    /*给食物涂背景色*/
    food->setAutoFillBackground(true);
    food->setPalette(QPalette
    (QColor(qrand()%256,qrand()%256,
    qrand()%256)));//QPalette不会用，直接光标放在这个QPalette()单词上按F1会弹出说明手册查文档,退回直接按ESC就行了
    int w=this->width()-foodLen;
    int h=this->height()-foodLen;
    /*位置要随机
      位置在界面范围内
      位置必须是foodLen的整数倍*/
    food->move(((qrand()%w)/foodLen)*foodLen,
               ((qrand()%h)/foodLen)*foodLen);
    food->show();
    return food;
}
/*改变蛇移动的方向*/
void  SnakeGame::keyPressEvent(
        QKeyEvent *e){
    switch(e->key()){
        case Qt::Key_Up:
        dire=D_UP;
        break;
        case Qt::Key_Down:
        dire=D_DOWN;
        break;
        case Qt::Key_Left:
        dire=D_LEFT;
        break;
        case Qt::Key_Right:
        dire=D_RIGHT;
        break;
    }
}

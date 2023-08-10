#ifndef SNAKEGAME
#define SNAKEGAME
#include <QList>
#include <QDialog>
#include <QKeyEvent>
#include <QLabel>
enum  Direction {D_UP,D_DOWN,D_LEFT,D_RIGHT};
class SnakeGame:public QDialog{
    Q_OBJECT
    /*代表一条蛇,也代表蛇头,<QLabel*>这个是泛型，代表食物，不断产生的食物，用指针表示*/
    QList<QLabel*>  snake;
    /*代表食物*/
    QLabel         *food;
    /*蛇的移动方向*/
    Direction       dire;
    /*食物大小的控制*/
    int             foodLen;
    /*蛇的最大长度*/
    int             maxLen;
    /*定时的控制蛇的移动*/
    QTimer          *timer;
    public:
    SnakeGame();
    ~SnakeGame();
    public slots:
    /*根据方向移动 走一个食物的大小*/
    void  snakeMove();
    public:
    /*产生新食物的函数*/
    QLabel*  getFood();
    /*改变蛇移动的方向*/
    void  keyPressEvent(QKeyEvent *e);
};

#endif // SNAKEGAME


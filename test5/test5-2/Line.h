#include "Point.h"
// 类的组合
class Line
{       // Line类的定义
public: // 外部接口
    Line(Point xp1, Point xp2);
    Line(Line &l);
    double getLen() { return len; }

private:          // 私有数据成员
    Point p1, p2; // Point类的对象p1,p2
    double len;
};

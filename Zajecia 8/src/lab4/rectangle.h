#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

namespace Shapes
{
class Rectangle : public Shape
{
    // TODO:
    int x1;
    int y1;
    int x2;
    int y2;
public:
    Rectangle(int x_1, int y_1, int x_2, int y_2) {
        x1 = x_1;
        x2 = x_2;
        y1 = y_1;
        y2 = y_2;
    }

    int getX() const{
        return x1;
    }

    int getY() const{
        return y1;
    }

    int getXTo() const{
        return x2;
    }

    int getYTo() const{
        return y2;
    }

    bool isIn(int x, int y) const override{
        if( (x >= x1 && x <= x2) && (y >= y1 && y <= y2) ) {
            return true;
        }
        else {
            return false;
        }
    }

};
} // namespace Shapes

#endif // RECTANGLE_H

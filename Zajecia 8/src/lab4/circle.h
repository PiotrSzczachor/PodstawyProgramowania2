#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <cmath>

namespace Shapes
{
class Circle : public Shape
{
    // TODO:
    int x_coordinate;
    int y_coordinate;
    int r;

public:
    Circle(int x, int y, int radius) {
        r = radius;
        x_coordinate = x;
        y_coordinate = y;
    }

    int getX() const{
        return x_coordinate;
    }

    int getY() const{
        return y_coordinate;
    }

    int getRadius() const{
        return r;
    }

    bool isIn(int x, int y) const override{
        if( sqrt( (x_coordinate - x)*(x_coordinate - x) + (y_coordinate - y)*(y_coordinate - y) ) > r) {
            return false;
        } else {
            return true;
        }
    }

};
} // namespace Shapes

#endif // CIRCLE_H

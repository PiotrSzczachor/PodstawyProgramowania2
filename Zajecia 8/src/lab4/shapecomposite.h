#ifndef SHAPECOMPOSITE_H
#define SHAPECOMPOSITE_H

#include <memory>

#include "shape.h"

namespace Shapes
{
enum class ShapeOperation
{
    INTERSECTION,
    SUM,
    DIFFERENCE
};

class ShapeComposite : public Shape
{
    std::shared_ptr<Shape> shape1, shape2;
    ShapeOperation operation;

public:


    ShapeComposite(std::shared_ptr<Shape> shape_1, std::shared_ptr<Shape> shape_2, ShapeOperation operation_) {
        shape1 = shape_1;
        shape2 = shape_2;
        operation = operation_;
    }
    bool isIn(int x, int y) const override {
        if (operation == ShapeOperation::SUM) {
            if (shape1->isIn(x, y) || shape2->isIn(x, y)) {
                return true;
            }
            else {
                return false;
            }
        }
        if (operation == ShapeOperation::INTERSECTION) {
            if (shape1->isIn(x, y) && shape2->isIn(x, y)) {
                return true;
            }
            else {
                return false;
            }
        }
        if (operation == ShapeOperation::DIFFERENCE) {
            if (shape1->isIn(x, y) && !shape2->isIn(x,y)) {
                return true;
            }
            else {
                return false;
            }
        }
    }
};


} // namespace Shapes

#endif // SHAPECOMPOSITE_H

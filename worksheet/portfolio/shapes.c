
#include <stdbool.h>
#include <math.h>

#include "shapes.h"


Point makePoint(float x, float y) {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}



Line makeLine(Point p1, Point p2) {
    Line l;
    l.p[0] = p1;
    l.p[1] = p2;
    return l;
}

Triangle makeTriangle(Point p1, Point p2, Point p3) {
    Triangle t;
    t.p[0] = p1;
    t.p[1] = p2;
    t.p[2] = p3;
    return t;
}

float lineLength(Line l) {
    float dx = l.p[1].x - l.p[0].x;
    float dy = l.p[1].y - l.p[0].y;

    return sqrtf(dx * dx + dy * dy);
}

float triangleArea(Triangle t) {
    float x1 = t.p[0].x;
    float y1 = t.p[0].y;
    float x2 = t.p[1].x;
    float y2 = t.p[1].y;
    float x3 = t.p[2].x;
    float y3 = t.p[2].y;

    float area = 0.5f * fabsf(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));

    return area;
}


bool samePoint(Point p1, Point p2) {
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    float dist = sqrtf(dx * dx + dy * dy);

    if (dist < 1.0e-6f) {
        return true;
    }

    return false;
}


bool pointInLine(Point p, Line l) {
    if (samePoint(p, l.p[0]) || samePoint(p, l.p[1])) {
        return true;
    }

    return false;
}




bool pointInTriangle(Point p, Triangle t) {
    if (samePoint(p, t.p[0]) || samePoint(p, t.p[1]) || samePoint(p, t.p[2])) {
        return true;
    }

    return false;
}
#pragma once
#include "Course.h"

class OfflineCourse : public Course 
{
    double months;
    double hrsPerday;
public:
    OfflineCourse(int m = 0, double h = 0) : months(m), hrsPerday(h) {}

    double duration() const override { return months * 30 * hrsPerday; }
};
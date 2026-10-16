#pragma once
#include "Course.h"

class OnlineCourse : public Course 
{
    int weeks;
    double hoursPerWeek;

public:
    OnlineCourse(int w = 0, double h = 0) : weeks(w), hoursPerWeek(h) {}
    double duration() const override { return weeks * hoursPerWeek; }
};

#pragma once

class Course 
{
public:
    virtual double duration() const = 0;
    virtual ~Course() {}
};
#include <iostream>
#include <string>
#include "OnlineCourse.h"
#include "OfflineCourse.h"

using namespace std;

int main() 
{
    OnlineCourse online(8, 5);
    OfflineCourse offline(3, 2);

    Course* courses[2] = { &online, &offline };
    string names[2] = { "Online Course", "Offline Course" };

    for (int i = 0; i < 2; i++)
        cout << names[i] << " duration: " << courses[i]->duration() << " hours\n";
    return 0;
}
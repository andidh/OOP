#pragma once

using namespace std;

class Observer
{
public:
    Observer();
    virtual void update() = 0;
    virtual ~Observer();
};


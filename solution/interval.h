#ifndef DA_LAB8_INTERVAL_H
#define DA_LAB8_INTERVAL_H

class interval {
public:
    interval() = default;
    interval(double L, double R): start(L), finish(R) {}
    ~interval() = default;

    double start;
    double finish;
    unsigned long id=0;
};

#endif

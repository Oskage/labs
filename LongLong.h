//
// Created by Oskage on 26.09.2019.
//

#ifndef TASK_1_1_38_LONGLONG_H
#define TASK_1_1_38_LONGLONG_H

#include <iostream>
#include <sstream>
#include <bitset>

class LongLong {
private:
    long s = 0;
    unsigned long j = 0;
public:
    long getS() const;
    unsigned long getJ() const;
    LongLong() = default;
    LongLong(long, unsigned long);
    LongLong(int);
    LongLong(unsigned);
    LongLong(const LongLong&) = default;
    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& out, const LongLong&);
    friend std::istream& operator>>(std::istream& in, LongLong&);
    friend bool operator<(const LongLong &, const LongLong&);
    friend bool operator==(const LongLong &, const LongLong&);
    friend bool operator>(const LongLong &, const LongLong&);
    friend bool operator<=(const LongLong &, const LongLong&);
    friend bool operator>=(const LongLong &, const LongLong&);
    friend bool operator!=(const LongLong &, const LongLong&);
    friend LongLong operator+(const LongLong&, const LongLong&);
    friend LongLong operator-(const LongLong&);
    friend LongLong operator-(const LongLong&, const LongLong&);
    friend LongLong operator*(const LongLong&, const  LongLong&);
    friend LongLong operator/(const LongLong&, const  LongLong&);
    friend LongLong operator%(const LongLong&, const  LongLong&);
};

#endif //TASK_1_1_38_LONGLONG_H
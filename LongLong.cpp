//
// Created by Oskage on 26.09.2019.
//

#include "LongLong.h"

//
// Constructors and destructors
//

LongLong::LongLong(long _s, unsigned long _j) : s(_s), j(_j) {}

LongLong::LongLong(int _j) : j(_j) {
    bool sign = (bool((1 << 31) & _j));
    if(sign) {
        for (size_t i = 0; i < 32; ++i) {
            s ^= (1 << i);
        }
    }
}

LongLong::LongLong(unsigned _j) : j{_j} {}

//
// Get and set methods
//

long LongLong::getS() const {
    return s;
}

unsigned long LongLong::getJ() const {
    return j;
}

//
// Overload operators
//

LongLong operator+(const LongLong &lhs, const LongLong &rhs) {
    unsigned long j = 0;
    long s = 0;
    bool addone = false;
    for (size_t i = 0; i < 32; ++i) {
        bool lhsi = (bool((1ul << i) & lhs.j));
        bool rhsi = (bool((1ul << i) & rhs.j));
        if(addone) {
            if((lhsi && !rhsi) || (!lhsi && rhsi)) {
                addone = true;
            } else {
                j |= (1ul << i);
                addone = lhsi;
            }
        } else {
            if((lhsi && !rhsi) || (!lhsi && rhsi)) {
                j |= (1ul << i);
                addone = false;
            } else {
                addone = lhsi;
            }
        }
    }
    for (size_t i = 0; i < 32; ++i) {
        bool lhsi = (bool((1 << i) & lhs.s));
        bool rhsi = (bool((1 << i) & rhs.s));
        if(addone) {
            if((lhsi && !rhsi) || (!lhsi && rhsi)) {
                addone = true;
            } else {
                s |= (1 << i);
                addone = lhsi;
            }
        } else {
            if((lhsi && !rhsi) || (!lhsi && rhsi)) {
                s |= (1 << i);
                addone = false;
            } else {
                addone = lhsi;
            }
        }
    }
    return LongLong(s, j);
}

LongLong operator-(const LongLong &value) {
    long s = value.getS();
    unsigned long j = value.j;
    for (size_t i = 0; i < 32; ++i) {
        s ^= (1 << i);
        j ^= (1 << i);
    }
    return LongLong(s, j) + LongLong(0, 1);
}

LongLong operator-(const LongLong &lhs, const LongLong &rhs) {
    return lhs + (-rhs);
}

std::ostream &operator<<(std::ostream &out, const LongLong &number) {
    std::bitset<32> _s = number.s;
    std::bitset<32> _j = number.j;
    out << _s << " " << _j;
    return out;
}

std::istream &operator>>(std::istream &in, LongLong &number) {
    in >> number.s >> number.j;
    return in;
}

bool operator<(const LongLong &lhs, const LongLong &rhs) {
    bool signOflhs = (bool((1 << 31) & lhs.s));
    bool signOfrhs = (bool((1 << 31) & rhs.s));
    if(signOflhs && (!signOfrhs || rhs == 0)) {
        return true;
    } else if((!signOflhs || lhs == 0) && signOfrhs) {
        return false;
    } else {
        if(lhs.s >= rhs.s) {
            return lhs.j < rhs.j;
        } else {
            return true;
        }
    }
}

bool operator==(const LongLong &lhs, const LongLong &rhs) {
    return lhs.s == rhs.s && lhs.j == rhs.j;
}

bool operator>(const LongLong &lhs, const LongLong &rhs) {
    return !(lhs < rhs) && !(lhs == rhs);
}

bool operator<=(const LongLong &lhs, const LongLong &rhs) {
    return (lhs < rhs) || (lhs == rhs);
}

bool operator>=(const LongLong &lhs, const LongLong &rhs) {
    return !(lhs < rhs);
}

bool operator!=(const LongLong &lhs, const LongLong &rhs) {
    return !(lhs == rhs);
}

LongLong operator*(const LongLong &lhs, const LongLong &rhs) {
    LongLong res = 0;
    LongLong abs_lhs = lhs;
    LongLong abs_rhs = rhs;
    int sign = 0;
    if(abs_lhs < 0) {
        sign++;
        abs_lhs = -lhs;
    }
    if(abs_rhs < 0) {
        sign++;
        abs_rhs = -rhs;
    }
    for(LongLong i = 0; i < abs_rhs; i = i + 1) {
        res = res + abs_lhs;
    }
    if(sign == 1) {
        return -res;
    } else {
        return res;
    }
}

LongLong operator/(const LongLong &lhs, const LongLong &rhs) {
    LongLong abs_lhs = lhs;
    LongLong abs_rhs = rhs;
    int sign = 0;
    if(abs_lhs < 0) {
        sign++;
        abs_lhs = -lhs;
    }
    if(abs_rhs < 0) {
        sign++;
        abs_rhs = -rhs;
    }
    if(abs_rhs > abs_lhs)
        return 0;
    else if (abs_rhs == abs_lhs)
        return 1;
    LongLong res = 0;
    while((res + 1) * abs_rhs < abs_lhs) {
        res = res + 1;
    }
    if((res + 1) * abs_rhs == abs_lhs)
        res = res + 1;
    if(sign == 1) {
        return -res;
    } else {
        return res;
    }
}

LongLong operator%(const LongLong &lhs, const LongLong &rhs) {
    LongLong abs_lhs = lhs;
    LongLong abs_rhs = rhs;
    bool signlhs = true;
    if(abs_lhs < 0) {
        signlhs = false;
        abs_lhs = -lhs;
    }
    if(abs_rhs < 0) {
        abs_rhs = -rhs;
    }
    if (abs_rhs > abs_lhs)
        return lhs;
    else if(abs_lhs == abs_rhs)
        return 0;
    LongLong res = abs_lhs - (abs_lhs / abs_rhs) * abs_rhs;
    if(signlhs)
        return res;
    else
        return -res;
}

//
// Other methods
//

std::string LongLong::toString() const {
    std::bitset<32> _s = s;
    std::bitset<32> _j = j;
    std::stringstream out;
    out << "Senior part: " << _s << std::endl;
    out << "Junior part: " << _j;
    return out.str();
}
#ifndef TASK_8_8_22_GOOD_H
#define TASK_8_8_22_GOOD_H

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <vector>
#include <utility>

using _time = std::chrono::time_point<std::chrono::system_clock>;

class Good {
private:
    bool deleted{};
    int warehouseID{};
    int goodID{};
    std::string name{5, '-'};
    _time receiptDate{};
    int daysAtWH{};
    int count{};
    int price{};
public:
    Good() = default;
    Good(const Good&) = default;
    Good(bool _d, int _whid, int _gid, std::string _n, _time _rd, int _dwh, int _c, int _p) : deleted(_d),
        warehouseID{_whid}, goodID{_gid}, name{std::move(_n)}, receiptDate{_rd}, daysAtWH{_dwh}, count{_c}, price{_p} {};

    friend std::ostream& operator<<(std::ostream& out, const Good &good);
    friend std::istream& operator>>(std::istream& in, Good &good);

    void setDeleted(bool value);
    void setWarehouseID(int value);
    void setGoodID(int value);
    void setName(std::string value);
    void setReceiptDate(_time value);
    void setReceiptDate(std::string value);
    void setDaysAtWH(int value);
    void setCount(int value);
    void setPrice(int value);

    bool isDeleted();
    int getWarehouseID();
    int getGoodID();
    std::string getName();
    _time getReceiptDate();
    int getDaysAtWH();
    int getCount();
    int getPrice();
};


#endif //TASK_8_8_22_GOOD_H

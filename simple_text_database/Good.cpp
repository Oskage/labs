#include "Good.h"

std::chrono::system_clock::time_point stringToTimePoint(const std::string &str) {
    using namespace std;
    using namespace std::chrono;
    int yyyy, mm, dd, HH, MM, SS, fff;
    char scanf_format[] = "%4d.%2d.%2d-%2d.%2d.%2d";
    sscanf(str.c_str(), scanf_format, &yyyy, &mm, &dd, &HH, &MM, &SS);
    tm ttm = tm();
    ttm.tm_year = yyyy - 1900; // Year since 1900
    ttm.tm_mon = mm - 1; // Month since January
    ttm.tm_mday = dd; // Day of the month [1-31]
    ttm.tm_hour = HH; // Hour of the day [00-23]
    ttm.tm_min = MM;
    ttm.tm_sec = SS;
    time_t ttime_t = mktime(&ttm);
    system_clock::time_point time_point_result = std::chrono::system_clock::from_time_t(ttime_t);
    return time_point_result;
}

//
// Operators overloads
//

std::ostream &operator<<(std::ostream &out, const Good &good) {
    out << good.name << std::endl;
    out << good.goodID << " | " << good.warehouseID << " | " << good.count << " | " << good.price << " | " <<
        good.daysAtWH << std::endl;
    std::time_t date = std::chrono::system_clock::to_time_t(good.receiptDate);
    out << ctime(&date);
    return out;
}

std::istream &operator>>(std::istream &in, Good &good) {
    bool btmp;
    in >> btmp;
    good.setDeleted(btmp);

    int tmp;
    in >> tmp;
    good.setWarehouseID(tmp);

    in >> tmp;
    good.setGoodID(tmp);

    std::string stmp;
    in >> stmp;
    good.setName(stmp);

    in >> stmp;
    good.setReceiptDate(stmp);

    in >> tmp;
    good.setDaysAtWH(tmp);

    in >> tmp;
    good.setCount(tmp);

    in >> tmp;
    good.setPrice(tmp);
    return in;
}

//
// Setters
//

void Good::setWarehouseID(int value) {
    if(value < 0)
        throw std::invalid_argument("bad whid");
    warehouseID = value;
}

void Good::setGoodID(int value) {
    if(value < 0)
        throw std::invalid_argument("bad gid");
    goodID = value;
}

void Good::setName(std::string value) {
    name = std::move(value);
}

void Good::setReceiptDate(_time value) {
    receiptDate = value;
}

void Good::setReceiptDate(std::string value) {
    receiptDate = stringToTimePoint(value); // Year since 1900
}

void Good::setDaysAtWH(int value) {
    if(value < 0)
        throw std::invalid_argument("bad days at wh");
    daysAtWH = value;
}

void Good::setCount(int value) {
    if(value < 0)
        throw std::invalid_argument("bad count");
    count = value;
}

void Good::setPrice(int value) {
    if(value < 0)
        throw std::invalid_argument("bad price");
    price = value;
}

void Good::setDeleted(bool value) {
    deleted = value;
}

//
// Getters
//

int Good::getWarehouseID() { return warehouseID; }

int Good::getGoodID() { return goodID; }

std::string Good::getName() { return name; }

_time Good::getReceiptDate() { return receiptDate; }

int Good::getDaysAtWH() { return daysAtWH; }

int Good::getCount() { return count; }

int Good::getPrice() { return price; }

bool Good::isDeleted() {return deleted;}



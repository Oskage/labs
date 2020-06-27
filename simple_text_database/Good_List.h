#ifndef TASK_8_8_22_GOOD_LIST_H
#define TASK_8_8_22_GOOD_LIST_H

#include <utility>

#include "Good.h"

class Good_List {
private:
    std::vector<Good> list{};

    void addGood(Good &good, std::ofstream &fout);
    Good loadGood(std::ifstream &fin);
public:
    Good_List() = default;
    Good_List(const Good_List& other) = default;
    explicit Good_List(std::vector<Good> good_list) : list(std::move(good_list)) {};

    friend std::ostream& operator<<(std::ostream& out, const Good_List &gl);

    void load(const std::string &file_name);
    void saveBinary(const std::string &file_name);
    void saveText(const std::string &file_name);

    Good_List& pack();
    void add(const Good &good);
    void delByID(int id);
    void replaceByID(int id, const Good &good);

    std::vector<Good> findByWHID(int whid);
    std::vector<Good> findByGID(int gid);
    std::vector<Good> findByReceiptDate(_time time);
    std::vector<Good> findByDelay(int days);
    std::vector<Good> findAlive(int days);
};

#endif //TASK_8_8_22_GOOD_LIST_H

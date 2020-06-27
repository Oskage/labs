#include "Good_List.h"

//
// Operators overloads
//

std::ostream &operator<<(std::ostream &out, const Good_List &gl) {
    for(auto it = gl.list.begin(); it < gl.list.end(); it++) {
        if(it == gl.list.end() - 1) {
            out << *it;
            break;
        }
        out << *it << std::endl;
    }
    return out;
}

//
// Other methods
//

// Working with file

void Good_List::addGood(Good &good, std::ofstream &fout) {
    bool btmp = good.isDeleted();
    fout.write((char *)&btmp, sizeof(bool));

    int tmp = good.getWarehouseID();
    fout.write((char *)&tmp, sizeof(int));

    tmp = good.getGoodID();
    fout.write((char *)&tmp, sizeof(int));

    std::string stmp = good.getName();
    fout.write(stmp.c_str(), stmp.length() + 1);

    _time ttmp = good.getReceiptDate();
    fout.write((char *)&ttmp, sizeof(_time));

    tmp = good.getDaysAtWH();
    fout.write((char *)&tmp, sizeof(int));

    tmp = good.getCount();
    fout.write((char *)&tmp, sizeof(int));

    tmp = good.getPrice();
    fout.write((char *)&tmp, sizeof(int));
}

Good Good_List::loadGood(std::ifstream &fin) {
    Good good{};
    bool btmp{};
    fin.read((char *)&btmp, sizeof(bool));
    good.setDeleted(btmp);

    int tmp{};
    fin.read((char *)&tmp, sizeof(int));
    good.setWarehouseID(tmp);

    fin.read((char *)&tmp, sizeof(int));
    good.setGoodID(tmp);

    std::string stmp{};
    std::getline(fin, stmp, '\0');
    good.setName(stmp);

    _time ttmp;
    fin.read((char *)&ttmp, sizeof(_time));
    good.setReceiptDate(ttmp);

    fin.read((char *)&tmp, sizeof(int));
    good.setDaysAtWH(tmp);

    fin.read((char *)&tmp, sizeof(int));
    good.setCount(tmp);

    fin.read((char *)&tmp, sizeof(int));
    good.setPrice(tmp);
    return good;
}

void Good_List::load(const std::string &file_name) {
    std::ifstream fin{file_name, std::ios::in|std::ios::binary};
    if(fin) {
        int size{};
        fin.read((char *)&size, sizeof(int));
        for(size_t i = 0; i < size; i++) {
            list.push_back(loadGood(fin));
        }
    }
    fin.close();
}

void Good_List::saveBinary(const std::string &file_name) {
    std::ofstream fout{file_name, std::ios::out|std::ios::binary};
    int size = list.size();
    fout.write((char *)&size, sizeof(int));
    for(auto &it : list) {
        addGood(it, fout);
    }
    fout.close();
}

void Good_List::saveText(const std::string &file_name) {
    std::ofstream fout{file_name, std::ios::out};
    for(auto &it : list) {
        fout << it << std::endl;
    }
}

// Working with list of goods

Good_List& Good_List::pack() {
    for(auto it = list.begin(); it != list.end(); it++) {
        if((*it).isDeleted()) {
            list.erase(it);
            it--;
        }
    }
    return *this;
}

void Good_List::add(const Good &good) {
    list.push_back(good);
}

void Good_List::delByID(int id) {
    for(auto & it : list) {
        if(it.getGoodID() == id) {
            it.setDeleted(true);
        }
    }
}

void Good_List::replaceByID(int id, const Good &good) {
    for(auto it = list.begin(); it != list.end(); it++) {
        if((*it).getGoodID() == id) {
            list.erase(it);
            list.insert(it, good);
        }
    }
}

// FindBy logic

std::vector<Good> Good_List::findByWHID(int whid) {
    std::vector<Good> res{};
    for(auto & it : list) {
        if(it.getWarehouseID() == whid) {
            res.push_back(it);
        }
    }
    return res;
}

std::vector<Good> Good_List::findByGID(int gid) {
    std::vector<Good> res{};
    for(auto & it : list) {
        if(it.getGoodID() == gid) {
            res.push_back(it);
        }
    }
    return res;
}

std::vector<Good> Good_List::findByReceiptDate(_time time) {
    std::vector<Good> res{};
    for(auto & it : list) {
        if(it.getReceiptDate() == time) {
            res.push_back(it);
        }
    }
    return res;
}

std::vector<Good> Good_List::findByDelay(int days) {
    std::vector<Good> res{};
    for(auto & it : list) {
        if(it.getDaysAtWH() > days) {
            res.push_back(it);
        }
    }
    return res;
}

std::vector<Good> Good_List::findAlive(int days) {
    std::vector<Good> res{};
    for(auto & it : list) {
        if(it.getDaysAtWH() <= days) {
            res.push_back(it);
        }
    }
    return res;
}





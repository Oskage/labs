#include <iostream>
#include "Good_List.h"

int main() {
    Good g1 = Good{false ,23345, 935, "good1", std::chrono::system_clock::now(), 5, 7, 2440};
    Good g2 = Good{false, 2978, 95645, "good2", std::chrono::system_clock::now(), 5, 6, 2000};
    Good g3 = Good{true, 54, 92355, "good3", std::chrono::system_clock::now(), 5, 6, 2100};
    Good g4 = Good{false, 2386, 93056805, "good4", std::chrono::system_clock::now(), 5, 5, 2300};
    std::vector<Good> v1{g1, g2, g3, g4};
    Good_List gl1{v1};
    Good_List gl2{gl1};

    std::cout << gl1 << std::endl;
    std::cout << gl2 << std::endl;

    // some representation

    return 0;
}
#include <iostream>
#include <iomanip> // setw()
#include <fstream>
#include <iterator>
#include <algorithm> // generate()

#include "Experiment.h"

int main() {
    //
    // Experiment
    //
    int count_of_runs{};
    std::cout << "Count of runs at each step:" << std::endl;
    std::cin >> count_of_runs;

    int bottom{};
    std::cout << "Bottom line of value:" << std::endl;
    std::cin >> bottom;

    int step{};
    std::cout << "Step:" << std::endl;
    std::cin >> step;

    int top{};
    std::cout << "Top line of value:" << std::endl;
    std::cin >> top;

    // Prepare data for experiment
    int size_of_args = (top - bottom) / step + 1;
    auto *args = new int[size_of_args];
    for(size_t i = 0; i < size_of_args; i++) {
        args[i] = bottom + step * i;
    }
    auto mean_times = new double[size_of_args];
    auto stds = new double[size_of_args];

    experiment(args, size_of_args, count_of_runs, mean_times, stds);

    std::ofstream out{"result.txt"};
    if(out.is_open()) {
        for(int i = -1; i < size_of_args; i++) {
            if(i == -1) {
                out << std::setw(13) << "Size of input" << "|";
                out << std::setw(13) << "Mean time" << "|";
                out << std::setw(13) << "Mean std" << std::endl;
            }
            out << std::setw(13) << args[i] << "|";
            out << std::setw(13) << mean_times[i] << "|";
            out << std::setw(13) << stds[i] << std::endl;
        }
    }
    out.close();

    std::cout << "Results:" << std::endl;
    std::cout << std::setw(13) << "Size of input" << "|";
    std::cout << std::setw(13) << "Mean time" << "|";
    std::cout << std::setw(13) << "Mean std" << std::endl;
    std::cout << std::string(41, '-') << std::endl;
    for(int i = 0; i < size_of_args; i++) {
        std::cout << std::setw(13) << args[i] << "|";
        std::cout << std::setw(13) << mean_times[i] << "|";
        std::cout << std::setw(13) << stds[i] << std::endl;
    }

    delete[] args;
    delete[] mean_times;
    delete[] stds;

    //
    // Representation
    //

    // Odd-even sort

    std::cout << "Odd-even sort:" << std::endl;
    std::cout << "Before:" << std::endl;
    std::vector<int> v_int(10);
    std::generate(v_int.begin(), v_int.end(), rnd); // rnd from Experiment.h
    std::copy(v_int.begin(), v_int.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    odd_even_sort_int(v_int);
    std::cout << "After: " << std::endl;
    std::copy(v_int.begin(), v_int.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    // Cocktail_sort

    std::cout << "Cocktail sort:" << std::endl;
    std::cout << "Before:" << std::endl;
    std::generate(v_int.begin(), v_int.end(), rnd);
    std::copy(v_int.begin(), v_int.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    cocktail_sort_int(v_int);
    std::cout << "After: " << std::endl;
    std::copy(v_int.begin(), v_int.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}
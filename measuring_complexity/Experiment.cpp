#include "Experiment.h"

unsigned rnd() {
    static unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::minstd_rand0 gen(seed);
    return gen() % 1000 + 1;
}

void odd_even_sort_int(std::vector<int> &container) {
    for(size_t i = 0; i < container.size(); i++) {
        for(size_t j = (i % 2) ? 0 : 1; j + 1 < container.size(); j += 2) {
            if(container[j + 1] < container[j])
                std::swap(container[j], container[j + 1]);
        }
    }
}

void cocktail_sort_int(std::vector<int> &container) {
    bool swapped{true};
    auto begin_it = container.begin();
    auto end_it = container.end() - 1;
    auto rbegin_it = container.rbegin();
    auto rend_it = container.rend() - 1;

    while(swapped) {
        swapped = false;
        for(auto it = begin_it; it != end_it; it++) {
            if(*(it + 1) < *it) {
                std::swap(*it, *(it + 1));
                swapped = true;
            }
        }

        if(!swapped)
            break;
        swapped = false;

        rbegin_it++;
        end_it--;
        for(auto it = rbegin_it; it != rend_it; it++) {
            if(*it < *(it + 1)) {
                std::swap(*it, *(it + 1));
                swapped = true;
            }
        }

        begin_it++;
        rend_it--;
    }
}

double measure_time(int size) {
    std::vector<int> container(size);
    std::generate(container.begin(), container.end(), rnd);

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    odd_even_sort_int(container);
    std::chrono::steady_clock::time_point stop = std::chrono::steady_clock::now();

    return std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count();
}

void experiment(int *args, size_t size, size_t count_of_runs, double *mean_times, double *stds) {
    for(size_t i = 0; i < size; i++) {
        auto *times = new double[count_of_runs];
        for(size_t j = 0; j < count_of_runs; j++)
            times[j] = measure_time(args[i]);
        mean_times[i] = mean_time(times, count_of_runs);
        stds[i] = std_time(times, count_of_runs);
        delete[] times;
    }
}
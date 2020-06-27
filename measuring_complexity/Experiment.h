#ifndef LAB1_EXPERIMENT_H
#define LAB1_EXPERIMENT_H

#include <chrono>
#include <vector>
#include <random>
#include <algorithm> // generate()
#include <utility> // swap()
#include "Statistics.h"

void odd_even_sort_int(std::vector<int> &container);

void cocktail_sort_int(std::vector<int> &container);

double measure_time(int size);

void experiment(int *args, size_t size, size_t count_of_runs, double *mean_times, double *stds);

unsigned rnd();


#endif //LAB1_EXPERIMENT_H

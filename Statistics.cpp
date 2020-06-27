#include "Statistics.h"

double mean_time(const double *times, size_t size) {
    double sum{0.0};
    for(size_t i = 0; i < size; i++) {
        sum += times[i];
    }
    return sum / size;
}

double std_time(double *times, size_t size) {
    double mean = mean_time(times, size);
    double sum{0.0};
    for (size_t i = 0; i < size; ++i) {
        sum += pow((times[i] - mean), 2);
    }
    return sqrt(sum / size);
}
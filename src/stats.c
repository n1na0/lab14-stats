#include <math.h>
#include "stats.h"

double mean(const double *a, size_t n) {
    double sum = 0.0;
    const double *p = a;
    size_t i;

    for (i = 0; i < n; ++i) {
        sum += *p; /* берем значение по указателю */
        ++p;       /* сдвигаем указатель на следующий элемент */
    }
    return sum / (double)n;
}

double deviation(const double *a, double mean, size_t n) {
    double sum_sq = 0.0;
    const double *p = a;
    size_t i;

    for (i = 0; i < n; ++i) {
        double diff = *p - mean;
        sum_sq += diff * diff;
        ++p;
    }
    
    /* Защита от деления на ноль, если n == 1 */
    if (n <= 1) return 0.0;

    /* Опечатка в задачнике исправлена: корень из всей дроби */
    return sqrt(sum_sq / (double)(n - 1));
}

const double *first_outlier(const double *a, size_t n, double mean, double dev) {
    const double *p = a;
    size_t i;

    for (i = 0; i < n; ++i) {
        /* Отклонение берем по модулю */
        if (fabs(*p - mean) > dev) {
            return p; /* Нашли! Возвращаем адрес этого элемента */
        }
        ++p;
    }
    return NULL; /* Прошли весь массив, промахов нет */
}
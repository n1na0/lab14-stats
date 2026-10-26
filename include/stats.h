#ifndef STATS_H_INCLUDED
#define STATS_H_INCLUDED

#include <stddef.h> /* для size_t */

/*
 * Вычисление среднего арифметического.
 * a - массив, n - количество элементов (n > 0).
 */
double mean(const double *a, size_t n);

/*
 * Вычисление среднеквадратичного отклонения (несмещенная оценка).
 * Формула: sqrt( 1/(n-1) * sum( (x_i - mean)^2 ) ).
 * a - массив, mean - уже вычисленное среднее, n - количество (n > 1).
 */
double deviation(const double *a, double mean, size_t n);

/*
 * Поиск первого "промаха" (выброса).
 * Возвращает указатель на первый элемент массива a, который 
 * отклоняется от среднего mean больше, чем на dev.
 * Если такого нет - возвращает NULL.
 */
const double *first_outlier(const double *a, size_t n, double mean, double dev);

#endif /* STATS_H_INCLUDED */
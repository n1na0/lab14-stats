#include <stdio.h>
#include "stats.h"

int main(void) {
    /* Тестовые данные */
    double data[] = { 10.0, 12.0, 11.0, 10.5, 11.5, 50.0, 9.5, 10.0, 11.0 };
    size_t n = sizeof(data) / sizeof(data[0]);

    printf("Анализ данных (n = %zu):\n", n);

    /* 1. Считаем среднее */
    double m = mean(data, n);
    printf("Среднее арифметическое: %.2f\n", m);

    /* 2. Считаем среднеквадратичное отклонение */
    double d = deviation(data, m, n);
    printf("Среднеквадратичное отклонение: %.2f\n\n", d);

    /* 3. Ищем выбросы */
    /* Будем использовать порог mean + 1*dev (можешь поменять на 2*dev или 3*dev) */
    double threshold = 1.0 * d; 
    const double *outlier = first_outlier(data, n, m, threshold);

    if (outlier == NULL) {
        printf("Выбросов не найдено (порог %.2f).\n", threshold);
    } else {
        printf("Найдены выбросы (порог %.2f):\n", threshold);
        
        /* Пока указатель не NULL, выводим и ищем дальше, начиная со следующего */
        while (outlier != NULL) {
            printf("  Значение: %.2f (индекс %ld)\n", 
                   *outlier, outlier - data);
            
            /* Ищем следующий выброс, начиная со следующего элемента */
            outlier = first_outlier(outlier + 1, n - (outlier + 1 - data), m, threshold);
        }
    }

    return 0;
}
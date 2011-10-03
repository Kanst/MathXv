/*
 * Модуль вычисления определителя матрицы n*n
 * matr-входная матрица
 * 
 * Авраменко Евгений АК5-31
 */


#ifndef DETERM_H
#define DETERM_H

void Get_matr(double **matr, int n, double **temp_matr, int indRow, int indCol);
double Det(double **matr, int n);



#endif

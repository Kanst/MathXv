

//Вычеркивания строки и столбца
void Get_matr(double **matr, int n, double **temp_matr, int indRow, int indCol)
{
        int ki = 0;
        for (int i = 0; i < n; i++){
                if(i != indRow){
                        for (int j = 0, kj = 0; j < n; j++){
                                if (j != indCol){
                                        temp_matr[ki][kj] = matr[i][j];
                                        kj++;
                                }
                        }
                        ki++;
                }
        }
}
 //Вычисления определителя матрицы
double Det(double **matr, int n)
{
        double temp = 0;   //временная переменная для хранения определителя
        int k = 1;              //степень
       if (n == 1)
                temp = matr[0][0];
        else if (n == 2)
                temp = matr[0][0] * matr[1][1] - matr[1][0] * matr[0][1];
        else{
                for(int i = 0; i < n; i++){
                        int m = n - 1;
                        double **temp_matr = new double * [m];
                        for(int j = 0; j < m; j++)
                                temp_matr[j] = new double [m];
                        Get_matr(matr, n, temp_matr, 0, i);
                        temp = temp + k * matr[0][i] * Det(temp_matr, m);
                        k = -k;

                }
        }
        return temp;
}

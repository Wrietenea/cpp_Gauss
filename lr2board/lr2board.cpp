// lr2board.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int i, j, n; //solution of systems of linear algebraic equations by the Gauss method

    cout << "Решение систем линейных алгебраических уравнений методом Гаусса ";
    cout << endl;

    cout << "Количество уравнений: ";
    cin >> n;//
 
    //создаем массив
    double** matrix = new double* [n];

    for (i = 0; i < n; i++) { matrix[i] = new double[n]; }

    //инициализируем

    for (i = 0; i < n; i++)

        for (j = 0; j < n+1; j++)
        {
            cout << " Элемент " << "[" << i + 1 << " , " << j + 1 << "]: ";

            cin >> matrix[i][j];//заполняем матрицу коэффициентами и свободными членами
        }




    //выводим массив
    cout << "расширенная матрица" << endl;//паказываем созданную матрицу "уравнений" 
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n+1; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    //Метод Гаусса
    //Прямой ход, приведение к верхнетреугольному виду
    double  tmp;
    int k;
    double* xx = new double[n+1];

    for (i = 0; i < n; i++)
    {
        tmp = matrix[i][i];

        cout << "tmp1 = matrix [" << i << "," << i << "] =" << matrix[i][i];     //[i][i];" <<tmp << " i= "<<i ;
        //cout << endl;

        for (j = n; j >= i; j--) {

            //cout <<"matrix ["<<i<<","<<j<<"] = " << matrix[i][j] ; 
            double vb = matrix[i][j];
            cout << endl;

            matrix[i][j] /= tmp;

            cout << "matrix [" << i << "," << j << "](" << vb << ")" << " /= " << "tmp1(" << tmp << ") == " << matrix[i][j];
            //cout << endl;
        }
        cout << endl;
        cout << "матрица после деления на tmp1" << endl;//паказываем созданную матрицу "уравнений" 
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n+1; j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
        cout << endl;

        for (j = i + 1; j < n; j++)
        {
            cout << endl;
            tmp = matrix[j][i];
            cout << "tmp2 = matrix [" << j << "," << i << "] = " << matrix[j][i];
            //cout << endl;   

            for (k = n; k >= i; k--) {

                //cout <<"matrix ["<<j<<","<<k<<"] = " << matrix[j][k] ;
                double vb = matrix[j][k];
                cout << endl;
                matrix[j][k] -= tmp * matrix[i][k];
                cout << "matrix [" << j << "," << k << "](" << vb << ")" << " -= tmp2" << "(" << tmp << ")" << " * " << "matrix [" << i << "," << k << "](" << matrix[i][k] << ")" << " == " << matrix[j][k];
                //cout << endl;                
            }
            cout << endl;
        }
        cout << endl;
    }

    cout << "матрица в верхнетреугольном виде" << endl;//матрица в верхнетреугольном виде
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n+1; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }  
    cout << endl;
  
        /*обратный ход*/
    xx[n - 1] = matrix[n - 1][n];
    for (i = n - 2; i >= 0; i--)
    {
        xx[i] = matrix[i][n];
        for (j = i + 1; j < n; j++) xx[i] -= matrix[i][j] * xx[j];
    }

    //Выводим решения
    cout << "решения системы уравнений" << endl;
    for (i = 0; i < n; i++)
        cout << xx[i] << " ";
    cout << endl;

    delete[] matrix;
    // system("pause");//зависимость от windows лучьше не использовать
    cout << "нажмите Enter для выхода ";
    cout << endl;
    cin.get();//а это пауза 
    cin.get();
    return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

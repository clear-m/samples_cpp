//This is WIP
double linear_interpolation(double x1, double y1, double x2, double y2, double x)
{
    return y1 + (y2 - y1) * (x - x1) / (x2 - x1);
}

double derivative(double (*func)(double), double x, double h)
{
    return (func(x + h) - func(x - h)) / (2 * h);
}

//#include <randlib.h>
#include <vector>

int main(int argc, char **argv)
{
    {
        //NormalRand X(0, 1); // Создаем нормальное распределение с математическим ожиданием 0 и дисперсией 1
        // double x{0.5};
        // double pdf = X.f(x); // Вычисляем плотность вероятности в точке x
        // double cdf = X.F(x); // Вычисляем функцию распределения в точке x
    }
    {
        // std::vector<double> samples{1.2, 0.8, 1.5, 1.1, 0.9}; // Выборка
        // NormalRand X;
        // X.Fit(samples);
        // double mean = X.Mean();
        // double variance = X.Variance();

    }
    return 0;
}
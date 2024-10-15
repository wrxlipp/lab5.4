#include <iostream>
#include <cmath>
using namespace std;

// Ітераційний спосіб
double S0(const int N) {
    double s = 0;
    for (int i = N; i <= 20; i++) {
        s += (cos(i) + sin(i)) / (1 + cos(i) * sin(i));
    }
    return s;
}

// Рекурсивний спосіб на спуску, параметр зростає
double S1(const int N, const int i) {
    if (i > 20)
        return 0;
    else
        return (cos(i) + sin(i)) / (1 + cos(i) * sin(i)) + S1(N, i + 1);
}

// Рекурсивний спосіб на спуску, параметр спадає
double S2(const int N, const int i) {
    if (i < N)
        return 0;
    else
        return (cos(i) + sin(i)) / (1 + cos(i) * sin(i)) + S2(N, i - 1);
}

// Рекурсивний спосіб на підйомі, параметр зростає
double S3(const int N, const int i, double t) {
    t = t + (cos(i) + sin(i)) / (1 + cos(i) * sin(i));
    if (i >= 20)
        return t;
    else
        return S3(N, i + 1, t);
}

// Рекурсивний спосіб на підйомі, параметр спадає
double S4(const int N, const int i, double t) {
    t = t + (cos(i) + sin(i)) / (1 + cos(i) * sin(i));
    if (i <= N)
        return t;
    else
        return S4(N, i - 1, t);
}

int main() {
    int N;
    cout << "N = ";
    cin >> N;

    // Виведення результатів без проміжних виводів
    cout << "(iter) S0 = " << S0(N) << endl;
    cout << "(rec up ++) S1 = " << S1(N, N) << endl;
    cout << "(rec up --) S2 = " << S2(N, 20) << endl;
    cout << "(rec down ++) S3 = " << S3(N, N, 0) << endl;
    cout << "(rec down --) S4 = " << S4(N, 20, 0) << endl;

    return 0;
}

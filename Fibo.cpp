#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void multiply(int F[2][2], int m[2][2])
{
    int temp[2][2];
    temp[0][0] = F[0][0] * m[0][0] + F[0][1] * m[1][0];
    temp[0][1] = F[0][0] * m[0][1] + F[0][1] * m[1][1];
    temp[1][0] = F[1][0] * m[0][0] + F[1][1] * m[1][0];
    temp[1][1] = F[1][0] * m[0][1] + F[1][1] * m[1][1];
    F[0][0] = temp[0][0];
    F[0][1] = temp[0][1];
    F[1][0] = temp[1][0];
    F[1][1] = temp[1][1];
}

void F_power(int F[2][2], int n)
{
    if (n == 1)
        return; // n==0 will never come

    F_power(F, n / 2);
    multiply(F, F);

    int m[2][2] = {
        {1, 1},
        {1, 0}};
    if (n % 2 != 0)
        multiply(F, m);
}

int main()
{
    int n;
    cout << "Fibonacci Sequences number: ";
    cin >> n;

    int F[2][2] = {
        {1, 1},
        {1, 0}};
    if (n == 0)
        cout << 0 << endl;
    F_power(F, n);
    cout << "Xn = " << F[0][1] << endl;
    return 0;
}
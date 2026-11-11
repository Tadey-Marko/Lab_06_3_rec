#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void printArray(const int a[], int n, int i = 0) {
    if (i == n) { cout << '\n'; return; }
    cout << setw(5) << a[i];
    printArray(a, n, i + 1);
}
int sumEven(const int a[], int n, int i = 0) {
    if (i == n) return 0;
    return (a[i] % 2 == 0 ? a[i] : 0) + sumEven(a, n, i + 1);
}
// Generic version for integral number types (int, long long, etc.).
template <typename T>
T sumEvenTemplate(const T a[], int n, int i = 0) {
    if (i == n) return T();
    return (a[i] % 2 == 0 ? a[i] : T()) + sumEvenTemplate<T>(a, n, i + 1);
}
#ifndef UNIT_TEST
int main() {
    const int n = 6;
    const int a[n] = { 2, -3, 4, 0, 7, 8 };
    const long long b[n] = { 12, -11, 14, 3, 20, 7 };
    cout << "Array a: ";
    printArray(a, n);
    cout << "Ordinary function: " << sumEven(a, n) << '\n';
    cout << "Template<int>:      " << sumEvenTemplate<int>(a, n) << '\n';
    cout << "Template<long long>: " << sumEvenTemplate<long long>(b, n) << '\n';
    return 0;
}
#endif

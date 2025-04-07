
#include <iostream>
#include <cmath>

using namespace std;

const int MAX_M = 100; // Giới hạn số dòng
const int MAX_N = 100; // Giới hạn số cột

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

// 1. Tìm số nguyên tố lớn nhất trong ma trận
int findMaxPrime(int a[MAX_M][MAX_N], int m, int n) {
    int maxPrime = -1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isPrime(a[i][j]) && a[i][j] > maxPrime) {
                maxPrime = a[i][j];
            }
        }
    }
    return maxPrime;
}

// 2. Tìm các dòng chứa ít nhất một số nguyên tố
void rowsWithPrime(int a[MAX_M][MAX_N], int m, int n) {
    cout << "Cac dong chua it nhat mot so nguyen to: ";
    for (int i = 0; i < m; i++) {
        bool foundPrime = false;
        for (int j = 0; j < n; j++) {
            if (isPrime(a[i][j])) {
                foundPrime = true;
                break;
            }
        }
        if (foundPrime) {
            cout << i + 1 << " "; // In ra chỉ số dòng (bắt đầu từ 1)
        }
    }
    cout << endl;
}

// 3. Tìm các dòng chỉ toàn số nguyên tố
void rowsOnlyPrime(int a[MAX_M][MAX_N], int m, int n) {
    cout << "Cac dong chi chua toan so nguyen to: ";
    for (int i = 0; i < m; i++) {
        bool allPrime = true;
        for (int j = 0; j < n; j++) {
            if (!isPrime(a[i][j])) {
                allPrime = false;
                break;
            }
        }
        if (allPrime) {
            cout << i + 1 << " "; // In ra chỉ số dòng (bắt đầu từ 1)
        }
    }
    cout << endl;
}

int main() {
    int m, n;
    int a[MAX_M][MAX_N];

    // Nhập kích thước ma trận
    cout << "Nhap so dong m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;

    // Nhập các phần tử của ma trận
    cout << "Nhap cac phan tu cua ma tran: \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // 1. Tìm số nguyên tố lớn nhất
    int maxPrime = findMaxPrime(a, m, n);
    if (maxPrime == -1) {
        cout << "Khong co so nguyen to trong ma tran.\n";
    } else {
        cout << "So nguyen to lon nhat trong ma tran: " << maxPrime << endl;
    }

    // 2. Tìm các dòng chứa ít nhất một số nguyên tố
    rowsWithPrime(a, m, n);

    // 3. Tìm các dòng chỉ toàn số nguyên tố
    rowsOnlyPrime(a, m, n);

    return 0;
}

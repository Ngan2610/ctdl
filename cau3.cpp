#include <stdio.h>

// Hàm tính xn bằng đệ quy
long long tinhXnDeQuy(int n) {
    if (n == 0 || n == 1) return 1;
    long long tong = 0;
    for (int i = 0; i < n; i++) {
        tong += n * tinhXnDeQuy(i);
    }
    return tong;
}

// Hàm tính xn không dùng đệ quy
long long tinhXnKhongDeQuy(int n) {
    long long f[100]; // Giả sử n không quá 100
    f[0] = f[1] = 1;

    for (int i = 2; i <= n; i++) {
        f[i] = 0;
        for (int j = 0; j < i; j++) {
            f[i] += i * f[j];
        }
    }
    return f[n];
}

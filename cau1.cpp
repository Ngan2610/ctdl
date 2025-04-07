#include <stdio.h>
#include <stdlib.h>

// Hàm đọc dữ liệu từ file và lưu vào mảng động 2 chiều (theo cách trong slide)
void docTuFile(FILE *file, int **&A, int &soDong, int &soCot) {
    fscanf(file, "%d %d", &soDong, &soCot); // Đọc số dòng và số cột

    // Cấp phát động mảng 2 chiều
    A = new int *[soDong];
    for (int i = 0; i < soDong; i++) {
        A[i] = new int[soCot];
    }

    // Đọc từng phần tử từ file và lưu vào mảng
    for (int i = 0; i < soDong; i++) {
        for (int j = 0; j < soCot; j++) {
            fscanf(file, "%d", &A[i][j]);
        }
    }
}

// Hàm tìm số lớn nhất và lớn nhì trong mảng 2 chiều
void timMaxVaMax2(int **A, int soDong, int soCot, int &max1, int &max2) {
    max1 = max2 = -1;  // Giá trị khởi tạo nhỏ ban đầu

    for (int i = 0; i < soDong; i++) {
        for (int j = 0; j < soCot; j++) {
            if (A[i][j] > max1) {
                max2 = max1;
                max1 = A[i][j];
            } else if (A[i][j] > max2 && A[i][j] != max1) {
                max2 = A[i][j];
            }
        }
    }
}

// Hàm tính tổng các phần tử trên mỗi cột
void tongCot(int **A, int soDong, int soCot, int *tongCacCot) {
    for (int j = 0; j < soCot; j++) {
        tongCacCot[j] = 0;
        for (int i = 0; i < soDong; i++) {
            tongCacCot[j] += A[i][j];
        }
    }
}

// Hàm tìm số nhỏ nhất trong từng dòng
void timMinDong(int **A, int soDong, int soCot, int *giaTriNhoNhatDong) {
    for (int i = 0; i < soDong; i++) {
        giaTriNhoNhatDong[i] = A[i][0];
        for (int j = 1; j < soCot; j++) {
            if (A[i][j] < giaTriNhoNhatDong[i]) {
                giaTriNhoNhatDong[i] = A[i][j];
            }
        }
    }
}

// Hàm tạo mảng C từ A
void taoMangC(int **A, int **&C, int *giaTriNhoNhatDong, int soDong, int soCot) {
    C = new int *[soDong];
    for (int i = 0; i < soDong; i++) {
        C[i] = new int[soCot];
        for (int j = 0; j < soCot; j++) {
            C[i][j] = A[i][j] * giaTriNhoNhatDong[i];
        }
    }
}

// Hàm ghi kết quả ra file
void ghiVaoFile(const char *tenFile, int max1, int max2, int *tongCacCot, int **C, int soDong, int soCot) {
    FILE *file = fopen(tenFile, "w");
    if (file == NULL) {
        printf("Khong the mo file de ghi!\n");
        return;
    }

    fprintf(file, "So lon nhat: %d\n", max1);
    fprintf(file, "So lon nhi: %d\n", max2);

    fprintf(file, "Tong cac cot: ");
    for (int j = 0; j < soCot; j++) {
        fprintf(file, "%d ", tongCacCot[j]);
    }
    fprintf(file, "\n");

    fprintf(file, "Ma tran C:\n");
    for (int i = 0; i < soDong; i++) {
        for (int j = 0; j < soCot; j++) {
            fprintf(file, "%d ", C[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

// Hàm thu hồi bộ nhớ cấp phát động
void giaiPhongBoNho(int **A, int **C, int *tongCacCot, int *giaTriNhoNhatDong, int soDong) {
    for (int i = 0; i < soDong; i++) {
        delete[] A[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] C;
    delete[] tongCacCot;
    delete[] giaTriNhoNhatDong;
}

int main() {
    int **A, **C;
    int soDong, soCot, max1, max2;
    int *tongCacCot;
    int *giaTriNhoNhatDong;

    // Mở file để đọc
    FILE *file = fopen("test.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file!\n");
        return 1;
    }

    // Đọc dữ liệu từ file (cách làm giống slide)
    docTuFile(file, A, soDong, soCot);
    fclose(file); // Đóng file sau khi đọc xong

    // Tìm số lớn nhất và lớn nhì
    timMaxVaMax2(A, soDong, soCot, max1, max2);

    // Tính tổng các cột
    tongCacCot = new int[soCot];
    tongCot(A, soDong, soCot, tongCacCot);

    // Tìm số nhỏ nhất trên từng dòng
    giaTriNhoNhatDong = new int[soDong];
    timMinDong(A, soDong, soCot, giaTriNhoNhatDong);

    // Tạo mảng C từ A
    taoMangC(A, C, giaTriNhoNhatDong, soDong, soCot);

    // Ghi kết quả ra file "output.txt"
    ghiVaoFile("output.txt", max1, max2, tongCacCot, C, soDong, soCot);

    // Giải phóng bộ nhớ cấp phát động
    giaiPhongBoNho(A, C, tongCacCot, giaTriNhoNhatDong, soDong);

    printf("Chuong trinh da hoan thanh, ket qua da duoc ghi vao output.txt\n");
    return 0;
}

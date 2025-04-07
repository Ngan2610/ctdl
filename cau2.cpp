#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Hàm kiểm tra ký tự có phải nguyên âm không (không dùng tolower)
int laNguyenAm(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

// Hàm đếm nguyên âm và phụ âm
void demNguyenAmPhuAm(char *chuoi, int &nguyenAm, int &phuAm) {
    nguyenAm = phuAm = 0;
    for (int i = 0; chuoi[i] != '\0'; i++) {
        if (isalpha(chuoi[i])) {
            if (laNguyenAm(chuoi[i])) {
                nguyenAm++;
            } else {
                phuAm++;
            }
        }
    }
}

// Hàm tách chuỗi thành các từ và đếm số từ, số ký tự trong từng từ
void demSoTuVaKyTu(char *chuoi, int &soTu, int doDaiTu[]) {
    soTu = 0;
    char *tu = strtok(chuoi, " ");
    while (tu != NULL) {
        doDaiTu[soTu] = strlen(tu);
        soTu++;
        tu = strtok(NULL, " ");
    }
}

// Hàm đếm số lần xuất hiện của từng từ
void demSoLanXuatHien(char *chuoi) {
    char tuGoc[1000];
    strcpy(tuGoc, chuoi);
    
    char *tu[100];
    int soLan[100] = {0};
    int soTu = 0;

    char *tachTu = strtok(tuGoc, " ");
    while (tachTu != NULL) {
        int timThay = 0;
        for (int i = 0; i < soTu; i++) {
            if (strcmp(tu[i], tachTu) == 0) {
                soLan[i]++;
                timThay = 1;
                break;
            }
        }
        if (!timThay) {
            tu[soTu] = tachTu;
            soLan[soTu] = 1;
            soTu++;
        }
        tachTu = strtok(NULL, " ");
    }

    printf("So lan xuat hien cua tung tu:\n");
    for (int i = 0; i < soTu; i++) {
        printf("%s: %d\n", tu[i], soLan[i]);
    }
}

// Hàm xóa tất cả các ký tự được nhập vào
void xoaKyTu(char *chuoi, char kyTuXoa) {
    int j = 0;
    for (int i = 0; chuoi[i] != '\0'; i++) {
        if (chuoi[i] != kyTuXoa) {
            chuoi[j++] = chuoi[i];
        }
    }
    chuoi[j] = '\0';
}

int main() {
    char chuoi[1000], chuoiGoc[1000];
    int nguyenAm, phuAm, soTu, doDaiTu[100];
    char kyTuXoa;

    // Nhập chuỗi từ bàn phím
    printf("Nhap chuoi: ");
    fgets(chuoi, sizeof(chuoi), stdin);
    chuoi[strcspn(chuoi, "\n")] = '\0'; // Xóa ký tự xuống dòng

    // Sao chép chuỗi gốc để sử dụng lại
    strcpy(chuoiGoc, chuoi);

    // Đếm nguyên âm và phụ âm
    demNguyenAmPhuAm(chuoi, nguyenAm, phuAm);
    printf("So nguyen am: %d\n", nguyenAm);
    printf("So phu am: %d\n", phuAm);

    // Đếm số từ và số ký tự trong từng từ
    demSoTuVaKyTu(chuoi, soTu, doDaiTu);
    printf("So tu: %d\n", soTu);
    for (int i = 0; i < soTu; i++) {
        printf("Tu thu %d co %d ky tu\n", i + 1, doDaiTu[i]);
    }

    // Đếm số lần xuất hiện của từng từ
    demSoLanXuatHien(chuoiGoc);

    // Nhập ký tự cần xóa
    printf("Nhap ky tu can xoa: ");
    scanf(" %c", &kyTuXoa);

    // Xóa ký tự khỏi chuỗi và in ra kết quả
    xoaKyTu(chuoiGoc, kyTuXoa);
    printf("Chuoi sau khi xoa ky tu '%c': %s\n", kyTuXoa, chuoiGoc);

    return 0;
}

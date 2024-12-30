#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void nhapMang(int **mang, int *kichThuoc) {
    printf("Nhap so phan tu: ");
    scanf("%d", kichThuoc);
    *mang = (int *)malloc(*kichThuoc * sizeof(int));
    printf("Nhap tung phan tu:\n");
    for (int i = 0; i < *kichThuoc; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &(*mang)[i]);
    }
}

void inChan(int *mang, int kichThuoc) {
    printf("Cac phan tu chan: ");
    for (int i = 0; i < kichThuoc; i++) {
        if (mang[i] % 2 == 0) {
            printf("%d ", mang[i]);
        }
    }
    printf("\n");
}

bool laSoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void inNguyenTo(int *mang, int kichThuoc) {
    printf("Cac phan tu la so nguyen to: ");
    for (int i = 0; i < kichThuoc; i++) {
        if (laSoNguyenTo(mang[i])) {
            printf("%d ", mang[i]);
        }
    }
    printf("\n");
}

void daoNguocMang(int *mang, int kichThuoc) {
    for (int i = 0; i < kichThuoc / 2; i++) {
        int temp = mang[i];
        mang[i] = mang[kichThuoc - 1 - i];
        mang[kichThuoc - 1 - i] = temp;
    }
    printf("Mang sau khi dao nguoc: ");
    for (int i = 0; i < kichThuoc; i++) {
        printf("%d ", mang[i]);
    }
    printf("\n");
}

void sapXepMang(int *mang, int kichThuoc, bool tangDan) {
    for (int i = 0; i < kichThuoc - 1; i++) {
        for (int j = i + 1; j < kichThuoc; j++) {
            if ((tangDan && mang[i] > mang[j]) || (!tangDan && mang[i] < mang[j])) {
                int temp = mang[i];
                mang[i] = mang[j];
                mang[j] = temp;
            }
        }
    }
    printf("Mang sau khi sap xep: ");
    for (int i = 0; i < kichThuoc; i++) {
        printf("%d ", mang[i]);
    }
    printf("\n");
}

void timKiem(int *mang, int kichThuoc) {
    int x, timThay = 0;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);
    for (int i = 0; i < kichThuoc; i++) {
        if (mang[i] == x) {
            printf("Tim thay %d tai vi tri %d\n", x, i);
            timThay = 1;
        }
    }
    if (!timThay) {
        printf("Khong tim thay %d trong mang.\n", x);
    }
}

int main() {
    int *mang = NULL;
    int kichThuoc = 0, luaChon;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("6. Nhap vao mot phan tu va tim kiem phan tu trong mang\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                if (mang) free(mang);
                nhapMang(&mang, &kichThuoc);
                break;
            case 2:
                if (mang) inChan(mang, kichThuoc);
                else printf("Mang chua duoc nhap.\n");
                break;
            case 3:
                if (mang) inNguyenTo(mang, kichThuoc);
                else printf("Mang chua duoc nhap.\n");
                break;
            case 4:
                if (mang) daoNguocMang(mang, kichThuoc);
                else printf("Mang chua duoc nhap.\n");
                break;
            case 5:
                if (mang) {
                    int subChoice;
                    printf("1. Tang dan\n");
                    printf("2. Giam dan\n");
                    printf("Lua chon cua ban: ");
                    scanf("%d", &subChoice);
                    if (subChoice == 1) {
                        sapXepMang(mang, kichThuoc, true);
                    } else if (subChoice == 2) {
                        sapXepMang(mang, kichThuoc, false);
                    } else {
                        printf("Lua chon khong hop le.\n");
                    }
                } else printf("Mang chua duoc nhap.\n");
                break;
            case 6:
                if (mang) timKiem(mang, kichThuoc);
                else printf("Mang chua duoc nhap.\n");
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (luaChon != 7);

    if (mang) free(mang);
    return 0;
}


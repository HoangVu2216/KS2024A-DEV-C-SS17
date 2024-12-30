#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void nhapChuoi(char **chuoi) {
    char temp[1000];
    printf("Nhap chuoi: ");
    getchar(); // Loai bo ky tu newline trong bo dem
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0'; // Loai bo ky tu newline
    *chuoi = (char *)malloc((strlen(temp) + 1) * sizeof(char));
    strcpy(*chuoi, temp);
}

void inChuoi(char *chuoi) {
    if (chuoi) {
        printf("Chuoi da nhap: %s\n", chuoi);
    } else {
        printf("Chuoi chua duoc nhap.\n");
    }
}

void demKyTu(char *chuoi, int *chuCai, int *chuSo, int *kyTuDacBiet) {
    *chuCai = *chuSo = *kyTuDacBiet = 0;
    if (chuoi) {
        for (int i = 0; chuoi[i] != '\0'; i++) {
            if (isalpha(chuoi[i])) {
                (*chuCai)++;
            } else if (isdigit(chuoi[i])) {
                (*chuSo)++;
            } else if (!isspace(chuoi[i])) {
                (*kyTuDacBiet)++;
            }
        }
    }
}

int main() {
    char *chuoi = NULL;
    int luaChon;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi va in ra\n");
        printf("4. Dem so luong chu so trong chuoi va in ra\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi va in ra\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                if (chuoi) {
                    free(chuoi);
                }
                nhapChuoi(&chuoi);
                break;
            case 2:
                inChuoi(chuoi);
                break;
            case 3: {
                int chuCai = 0, chuSo = 0, kyTuDacBiet = 0;
                demKyTu(chuoi, &chuCai, &chuSo, &kyTuDacBiet);
                printf("So luong chu cai: %d\n", chuCai);
                break;
            }
            case 4: {
                int chuCai = 0, chuSo = 0, kyTuDacBiet = 0;
                demKyTu(chuoi, &chuCai, &chuSo, &kyTuDacBiet);
                printf("So luong chu so: %d\n", chuSo);
                break;
            }
            case 5: {
                int chuCai = 0, chuSo = 0, kyTuDacBiet = 0;
                demKyTu(chuoi, &chuCai, &chuSo, &kyTuDacBiet);
                printf("So luong ky tu dac biet: %d\n", kyTuDacBiet);
                break;
            }
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (luaChon != 6);

    if (chuoi) {
        free(chuoi);
    }

    return 0;
}


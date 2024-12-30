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

void inChuoiDaoNguoc(char *chuoi) {
    if (chuoi) {
        int len = strlen(chuoi);
        printf("Chuoi dao nguoc: ");
        for (int i = len - 1; i >= 0; i--) {
            putchar(chuoi[i]);
        }
        printf("\n");
    } else {
        printf("Chuoi chua duoc nhap.\n");
    }
}

int demSoTu(char *chuoi) {
    if (!chuoi) return 0;
    int dem = 0;
    char *token = strtok(chuoi, " ");
    while (token) {
        dem++;
        token = strtok(NULL, " ");
    }
    return dem;
}

void soSanhChuoi(char *chuoi1, char *chuoi2) {
    if (chuoi1 && chuoi2) {
        int len1 = strlen(chuoi1);
        int len2 = strlen(chuoi2);
        if (len1 > len2) {
            printf("Chuoi nhap ngan hon chuoi ban dau.\n");
        } else if (len1 < len2) {
            printf("Chuoi nhap dai hon chuoi ban dau.\n");
        } else {
            printf("Hai chuoi co do dai bang nhau.\n");
        }
    } else {
        printf("Chuoi chua duoc nhap.\n");
    }
}

void inHoaChuoi(char *chuoi) {
    if (chuoi) {
        printf("Chuoi in hoa: ");
        for (int i = 0; chuoi[i] != '\0'; i++) {
            putchar(toupper(chuoi[i]));
        }
        printf("\n");
    } else {
        printf("Chuoi chua duoc nhap.\n");
    }
}

void themChuoi(char **chuoi1, char *chuoi2) {
    if (*chuoi1 && chuoi2) {
        *chuoi1 = (char *)realloc(*chuoi1, strlen(*chuoi1) + strlen(chuoi2) + 1);
        strcat(*chuoi1, chuoi2);
    } else {
        printf("Chuoi chua duoc nhap.\n");
    }
}

int main() {
    char *chuoi1 = NULL, *chuoi2 = NULL;
    int luaChon;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh do dai\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                if (chuoi1) free(chuoi1);
                nhapChuoi(&chuoi1);
                break;
            case 2:
                inChuoiDaoNguoc(chuoi1);
                break;
            case 3:
                if (chuoi1) {
                    char *temp = strdup(chuoi1);
                    printf("So luong tu trong chuoi: %d\n", demSoTu(temp));
                    free(temp);
                } else {
                    printf("Chuoi chua duoc nhap.\n");
                }
                break;
            case 4:
                if (chuoi2) free(chuoi2);
                nhapChuoi(&chuoi2);
                soSanhChuoi(chuoi1, chuoi2);
                break;
            case 5:
                inHoaChuoi(chuoi1);
                break;
            case 6:
                if (chuoi2) free(chuoi2);
                nhapChuoi(&chuoi2);
                themChuoi(&chuoi1, chuoi2);
                printf("Chuoi sau khi them: %s\n", chuoi1);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (luaChon != 7);

    if (chuoi1) free(chuoi1);
    if (chuoi2) free(chuoi2);

    return 0;
}


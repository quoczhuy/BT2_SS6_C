#include <stdio.h>
#include <string.h>

int main() {
    // 1. Khai bao cac mang song song va bien he thong
    const int MAX = 100;
    char maPhieu[100][15];
    char tenSach[100][50];
    int soNgayMuon[100];
    int tienPhat[100];
    int soLuong = 0;
    
    int luaChon;
    
    // 2. Vong lap Menu tuong tac lien tuc
    do {
        printf("\n================ HE THONG QUAN LY MUON TRA SACH (LIBRARY_WMS) ================\n");
        printf("1. Them luot muon sach moi\n");
        printf("2. Hien thi danh sach muon sach\n");
        printf("3. Cap nhat so ngay muon theo Ma phieu\n");
        printf("4. Xoa luot muon sach theo Ma phieu\n");
        printf("5. Thong ke danh sach phieu muon bi phat (Qua han > 14 ngay)\n");
        printf("6. Thoat chuong trinh\n");
        printf("==============================================================================\n");
        printf("Lua chon cua ban: ");
        
        scanf("%d", &luaChon);
        
        // Xoa bo dem ban phim triet de sau khi nhap so
        while (getchar() != '\n');
        
        switch (luaChon) {
            case 1: {
                // CHUC NANG 1: THEM LUOT MUON SACH MOI
                printf("\n=== THEM LUOT MUON SACH MOI ===\n");
                if (soLuong >= MAX) {
                    printf("He thong day, khong the them phieu muon moi!\n");
                    break;
                }
                
                char maTam[15];
                printf("Nhap ma phieu muon: ");
                scanf("%14s", maTam);
                while (getchar() != '\n'); // Xoa bo dem ban phim
                
                // Kiem tra trung lap Ma phieu (Tim kiem tuyen tinh)
                int biTrung = 0;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maTam) == 0) {
                        biTrung = 1;
                        break;
                    }
                }
                
                if (biTrung) {
                    printf("Loi: Ma phieu '%s' da ton tai. Vui long thu lai!\n", maTam);
                    break;
                }
                
                // Luu ma phieu
                strcpy(maPhieu[soLuong], maTam);
                
                // Nhap ten sach co khoang trang
                printf("Nhap ten sach: ");
                fgets(tenSach[soLuong], 50, stdin);
                // Loai bo ky tu xuong dong '\n' do fgets de lai
                int len = strlen(tenSach[soLuong]);
                if (len > 0 && tenSach[soLuong][len - 1] == '\n') {
                    tenSach[soLuong][len - 1] = '\0';
                }
                
                // Nhap so ngay muon (phai lon hon 0)
                do {
                    printf("Nhap so ngay muon thuc te: ");
                    scanf("%d", &soNgayMuon[soLuong]);
                    while (getchar() != '\n'); // Xoa bo dem ban phim
                    
                    if (soNgayMuon[soLuong] <= 0) {
                        printf("Loi: So ngay muon phai lon hon 0. Vui long nhap lai!\n");
                    }
                } while (soNgayMuon[soLuong] <= 0);
                
                // Tu dong tinh tien phat theo cong thuc
                if (soNgayMuon[soLuong] > 14) {
                    tienPhat[soLuong] = (soNgayMuon[soLuong] - 14) * 5000;
                } else {
                    tienPhat[soLuong] = 0;
                }
                
                printf("\n--> Tien phat tu dong tinh: %d VND\n", tienPhat[soLuong]);
                soLuong++; // Tang bien dem he thong
                printf("--> Them luot muon sach thanh cong!\n");
                break;
            }
            
            case 2: {
                // CHUC NANG 2: HIEN THI DANH SACH MUON SACH
                printf("\n================================ DANH SACH MUON SACH ================================\n");
                if (soLuong == 0) {
                    printf("Danh sach muon sach hien dang rong!\n");
                } else {
                    // In tieu de bang
                    printf("%-5s | %-12s | %-30s | %-10s | %-15s\n", "STT", "Ma Phieu", "Ten Sach", "So Ngay", "Tien Phat (VND)");
                    printf("-------------------------------------------------------------------------------------\n");
                    
                    long long tongTien = 0;
                    for (int i = 0; i < soLuong; i++) {
                        printf("%-5d | %-12s | %-30s | %-10d | %-15d\n", i + 1, maPhieu[i], tenSach[i], soNgayMuon[i], tienPhat[i]);
                        tongTien += tienPhat[i];
                    }
                    printf("-------------------------------------------------------------------------------------\n");
                    printf("Tong tien phat toan he thong: %lld VNĐ\n", tongTien);
                }
                break;
            }
            
            case 3: {
                // CHUC NANG 3: CAP NHAT SO NGAY MUON
                printf("\n=== CAP NHAT SO NGAY MUON ===\n");
                char maTim[15];
                printf("Nhap ma phieu muon can cap nhat: ");
                scanf("%14s", maTim);
                while (getchar() != '\n');
                
                int viTri = -1;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maTim) == 0) {
                        viTri = i;
                        break;
                    }
                }
                
                if (viTri == -1) {
                    printf("Khong tim thay phieu muon co ma: %s\n", maTim);
                } else {
                    printf("Tim thay phieu muon cua sach: %s (So ngay hien tai: %d)\n", tenSach[viTri], soNgayMuon[viTri]);
                    
                    int ngayMoi;
                    do {
                        printf("Nhap so ngay muon thuc te moi: ");
                        scanf("%d", &ngayMoi);
                        while (getchar() != '\n');
                        
                        if (ngayMoi <= 0) {
                            printf("Loi: So ngay muon phai lon hon 0. Vui long nhap lai!\n");
                        }
                    } while (ngayMoi <= 0);
                    
                    // Cap nhat va Tinh lai tien phat
                    soNgayMuon[viTri] = ngayMoi;
                    if (soNgayMuon[viTri] > 14) {
                        tienPhat[viTri] = (soNgayMuon[viTri] - 14) * 5000;
                    } else {
                        tienPhat[viTri] = 0;
                    }
                    
                    printf("\n--> Tien phat moi: %d VNĐ\n", tienPhat[viTri]);
                    printf("--> Cap nhat so ngay muon thanh cong!\n");
                }
                break;
            }
            
            case 4: {
                // CHUC NANG 4: XOA LUOT MUON SACH
                printf("\n=== XOA PHIEU MUON ===\n");
                char maXoa[15];
                printf("Nhap ma phieu muon can xoa: ");
                scanf("%14s", maXoa);
                while (getchar() != '\n');
                
                int viTri = -1;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maXoa) == 0) {
                        viTri = i;
                        break;
                    }
                }
                
                if (viTri == -1) {
                    printf("Khong tim thay phieu muon co ma: %s\n", maXoa);
                } else {
                    // Thuat toan xoa bang cach don mang sang trai
                    for (int i = viTri; i < soLuong - 1; i++) {
                        strcpy(maPhieu[i], maPhieu[i + 1]);
                        strcpy(tenSach[i], tenSach[i + 1]);
                        soNgayMuon[i] = soNgayMuon[i + 1];
                        tienPhat[i] = tienPhat[i + 1];
                    }
                    soLuong--; // Giam so luong phieu
                    printf("Xoa phieu muon thanh cong!\n");
                }
                break;
            }
            
            case 5: {
                // CHUC NANG 5: THONG KE PHIEU MUON QUA HAN (SO NGAY > 14)
                printf("\n=== DANH SACH PHIEU MUON BI PHAT (QUA HAN > 14 NGAY) ===\n");
                int coPhieuQuaHan = 0;
                
                printf("%-5s | %-12s | %-30s | %-10s | %-15s\n", "STT", "Ma Phieu", "Ten Sach", "So Ngay", "Tien Phat (VND)");
                printf("-------------------------------------------------------------------------------------\n");
                
                for (int i = 0; i < soLuong; i++) {
                    if (soNgayMuon[i] > 14) {
                        printf("%-5d | %-12s | %-30s | %-10d | %-15d\n", i + 1, maPhieu[i], tenSach[i], soNgayMuon[i], tienPhat[i]);
                        coPhieuQuaHan = 1;
                    }
                }
                
                if (!coPhieuQuaHan) {
                    printf("Khong co luot muon nao bi qua han phat!\n");
                }
                printf("-------------------------------------------------------------------------------------\n");
                break;
            }
            
            case 6:
                printf("Thoat chuong trinh. Chuc ban mot ngay hieu qua!\n");
                break;
                
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
                break;
        }
    } while (luaChon != 6);

    return 0;
}
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#define max 100
struct Date
{
	int ngay;
	int thang;
	int nam;
};
typedef Date date;
struct NhanVien
{
	int msnv;
	char ho[10];
	char ten[30];
	date namsinh;
	char noisinh[300];
	char diachi[300];
	float luong;
	date ngayvao;
};
typedef NhanVien nhanvien;
struct DanhSach
{
	nhanvien a[max];
	int soluong;
};
typedef DanhSach danhsach;
void menu();
void count_time();
void ngayvaolam(date &ntn);
void nhapngaythangnam(date &ntn);
void xuatngaythangnam(date ntn);
void xuatmotnhanvien(nhanvien nv);
void ThemNhanVien(danhsach *ds);
void XuatDanhSachNhanVien(danhsach ds);
void XoaNhanVienTheoMaSo(danhsach *ds, int msnv);
void TimNhanVienTheoMa(danhsach& ds, int msnv);
int TimTheoMaSo(danhsach ds, int msnv);
void TimTheoTen(danhsach ds);
void SapXepTheoLuongGiamDan(danhsach &ds);
int main() {
	menu();
	getch(); 
}
void menu(){
	danhsach ds;
    nhanvien nv;
    ds.soluong = 0;
    int chon;
    do {
        printf("\n-----------------MENU-----------------|\n");
        count_time();
        printf("\n 1: Them 1 nhan vien                  |");
        printf("\n 2: Xuat danh sach nhan vien          |");
        printf("\n 3: Xoa nhan vien                     |");
        printf("\n 4: Tim nhan vien theo ma so          |");
        printf("\n 5: Tim nhan vien theo ten            |");
        printf("\n 6: Sap xep luong nhan vien giam dan  |");
        printf("\n 0: Thoat chuong trinh                |");
        printf("\n------------------END-----------------|");
        printf("\nChon chuc nang: ");
        scanf("%d", &chon);
		
        switch (chon) {
            case 0: {
                printf("Ket thuc chuong trinh.\n");
                break;
            }
            case 1: {
            	printf("\n{Ban da chon chuc nang them nhan vien!!!}\n");
            ThemNhanVien(&ds);
            printf("\nThem nhan vien thanh cong\n");
            break;
            }
            case 2: {
    			printf("\n{Ban da chon chuc nang xuat danh sach nhan vien!!!}\n");
    			if(ds.soluong <= 0){
    				printf("Chua co thong tin nhan vien");
				}
    			XuatDanhSachNhanVien(ds);
    			break;
			}

            case 3: {
            	printf("\n{Ban da chon chuc nang xoa vien theo ma so!!!}\n");
                printf("\nNhap ma so nhan vien can xoa: ");
    			int msnv;
    			scanf("%d", &msnv);
    			XoaNhanVienTheoMaSo(&ds, msnv);
    			break;
            }
            case 4: { 	
            	int msnv;
            	printf("\n{Ban da chon chuc nang tim nhan vien theo ma so!!!}\n");
            	printf("\nNhap ma so nhan vien can tim:");
            	scanf("%d", &msnv);
            	int index =	TimTheoMaSo(ds, msnv);
            	if(index == -1){
            		printf("Khong tim thay nhan vien co ma so %d\n", msnv);
				}else{
					printf("Thong tin nhan vien co ma so %d\n", msnv);
					xuatmotnhanvien(ds.a[index]);
				}
				break; 
			}
            case 5: {
                printf("\n{Ban da chon chuc nang tim nhan vien theo ten}\n");
                TimTheoTen(ds);
                break;
            }
            case 6:{
            	printf("\nBan da chon chuc nang sap luong nhan vien giam dan");
            	SapXepTheoLuongGiamDan(ds);
            	XuatDanhSachNhanVien(ds);
				break;
			}
            default: {
                printf("\nKhong co chuc nang nay.");
                break;
            }
        }
    } while (chon != 0);
} 
void count_time() {
  time_t current_time;
  struct tm * time_info;
  char time_string[50];

  time(&current_time);
  time_info = localtime(&current_time);

  strftime(time_string, sizeof(time_string), "%d/%m/%Y %H:%M:%S", time_info);
  printf("Hôm nay là ngày: %s  |", time_string);
}
void nhapngaythangnam(date &ntn){
	 do
    {
        printf("\nNgay:");
        scanf("%d",&ntn.ngay);
    } while(ntn.ngay < 1 || ntn.ngay > 31);
    do
    {
        printf("Thang: ");
        scanf("%d",&ntn.thang);
    } while(ntn.thang < 1 || ntn.thang > 12);
    printf("Nam: ");
    scanf("%d",&ntn.nam);
}
void xuatngaythangnam(date ntn){
    printf("%02d/%02d/%d", ntn.ngay, ntn.thang, ntn.nam);
}
void ngayvaolam(date &ntn) {
    time_t now = time(NULL);
    struct tm* tm_info = localtime(&now);
    
    ntn.ngay = tm_info->tm_mday;
    ntn.thang = tm_info->tm_mon + 1;
    ntn.nam = tm_info->tm_year + 1900;
}
void ThemNhanVien(danhsach *ds){
    if (ds->soluong == max)
    {
        printf("Danh sach da day! Khong the them nhan vien moi.\n");
        return;
    }

    nhanvien nv;

    printf("Nhap ma so nhan vien: ");
    scanf("%d", &nv.msnv);

    printf("Nhap ho nhan vien: ");
    fflush(stdin);
    gets(nv.ho);

    printf("Nhap ten nhan vien: ");
    fflush(stdin);
    gets(nv.ten);

    printf("Nhap ngay sinh nhan vien (dd/mm/yyyy): ");
    nhapngaythangnam(nv.namsinh);

    printf("Nhap noi sinh nhan vien: ");
    fflush(stdin);
    gets(nv.noisinh);

    printf("Nhap dia chi nhan vien: ");
    fflush(stdin);
    gets(nv.diachi);

    printf("Nhap luong nhan vien: ");
    scanf("%f", &nv.luong);

    //printf("Ngay vao lam nhan vien: %d/%m/%Y %H:%M:%S");
    ngayvaolam(nv.ngayvao);

    ds->a[ds->soluong] = nv;
    ds->soluong++;

    printf("Da them nhan vien moi thanh cong.\n");
}
void XuatDanhSachNhanVien(danhsach ds){
    for (int i = 0; i < ds.soluong; i++) {
        nhanvien nv = ds.a[i];
        printf("\n---------------------------------|\n");
        printf("MSNV: %d                           |\n", nv.msnv);
        printf("Ho ten: %s %s                      |\n", nv.ho, nv.ten);
        printf("Ngay sinh:");
        xuatngaythangnam(nv.namsinh);
        printf("\nNoi sinh: %s                     |\n", nv.noisinh);
        printf("Dia chi: %s                        |\n", nv.diachi);
        printf("Luong: %f                          |\n", nv.luong);
        printf("Ngay vao lam:");
        xuatngaythangnam(nv.ngayvao);
        printf("\n---------------------------------|\n");
    }
}
void xuatmotnhanvien(nhanvien nv) {
    printf("Ma so nhan vien: %d\n", nv.msnv);
    printf("Ho va ten: %s %s\n", nv.ho, nv.ten);
    printf("Ngay thang nam sinh:s %d/%d/%d\n", nv.namsinh.ngay, nv.namsinh.thang, nv.namsinh.nam);
    printf("Noi sinh: %s\n", nv.noisinh);
    printf("Dia chi: %s\n", nv.diachi);
    printf("Luong: %f\n", nv.luong);
    printf("Ngay vao lam: %d/%d/%d\n", nv.ngayvao.ngay, nv.ngayvao.thang, nv.ngayvao.nam);
} 
void XoaNhanVienTheoMaSo(danhsach *ds, int msnv) {
    int index = -1;
    for (int i = 0; i < ds->soluong; i++) {
        if (ds->a[i].msnv == msnv) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < ds->soluong - 1; i++) {
            ds->a[i] = ds->a[i + 1];
        }
        ds->soluong--;
        printf("Da xoa nhan vien co ma so %d thanh cong!\n", msnv);
    } else {
        printf("Khong tim thay nhan vien co ma so %d trong danh sach!\n", msnv);
    }
}
//np 
int TimTheoMaSo(danhsach ds, int msnv) {
    int left = 0;
    int right = ds.soluong - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (ds.a[mid].msnv == msnv) {
            return mid;
        } else if (ds.a[mid].msnv > msnv) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}
 
void SapXepTheoLuongGiamDan(danhsach &ds) {
    int i, j;
    int n = ds.soluong;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (ds.a[j].luong < ds.a[j + 1].luong) {
                nhanvien temp = ds.a[j];
                ds.a[j] = ds.a[j + 1];
                ds.a[j + 1] = temp;
            }
        }
    }
}
void TimTheoTen(danhsach ds) {
    char ten[20];
    printf("\nNhap ten nhan vien can tim: ");
    scanf("%s", ten);
    int found = 0;
    for (int i = 0; i < ds.soluong; i++) {
        if (strcmp(ds.a[i].ten, ten) == 0) {
            nhanvien nv = ds.a[i];
            printf("MSNV: %d\n", nv.msnv);
            printf("Ho ten: %s %s\n", nv.ho, nv.ten);
            printf("Ngay sinh: ");
            xuatngaythangnam(nv.namsinh);
            printf("\nNoi sinh: %s\n", nv.noisinh);
            printf("Dia chi: %s\n", nv.diachi);
            printf("Luong: %f\n", nv.luong);
            printf("Ngay vao lam: ");
            xuatngaythangnam(nv.ngayvao);
            printf("\n-----------------------\n");
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay nhan vien co ten la %s.\n", ten);
    }
}

#include <iostream>
#include <string>
using namespace std;

// ======= Lớp MonHoc =======
class MonHoc {
private:
    string MaMH;
    string TenMH;
    float DTB;
    int SoTC;

public:
    // Khởi tạo
    MonHoc() {
        MaMH = "";
        TenMH = "";
        DTB = 0;
        SoTC = 0;
    }

    // Hủy bỏ
    ~MonHoc() {}

    // Hàm nhập
    void nhap() {
        cout << "Nhap ma mon hoc: ";
        getline(cin, MaMH);
        cout << "Nhap ten mon hoc: ";
        getline(cin, TenMH);
        cout << "Nhap diem trung binh: ";
        cin >> DTB;
        cout << "Nhap so tin chi: ";
        cin >> SoTC;
        cin.ignore();
    }

    // Hàm xuất
    void xuat() const {
        cout << "Ma MH: " << MaMH
             << ", Ten MH: " << TenMH
             << ", DTB: " << DTB
             << ", So TC: " << SoTC << endl;
    }

    // Trả về số tín chỉ
    int getSoTC() const {
        return SoTC;
    }

    // Trả về DTB
    float getDTB() const {
        return DTB;
    }
};

// ======= Lớp SinhVien =======
class SinhVien {
private:
    string MaSV;
    string TenSV;
    int SoMH;
    MonHoc arr[100];

public:
    // Khởi tạo
    SinhVien() {
        MaSV = "";
        TenSV = "";
        SoMH = 0;
    }

    // Hủy bỏ
    ~SinhVien() {}

    // Hàm nhập
    void nhap() {
        cout << "Nhap ma sinh vien: ";
        getline(cin, MaSV);
        cout << "Nhap ten sinh vien: ";
        getline(cin, TenSV);
        cout << "Nhap so mon hoc da dang ky: ";
        cin >> SoMH;
        cin.ignore();
        for (int i = 0; i < SoMH; ++i) {
            cout << "Nhap thong tin mon hoc thu " << i + 1 << ":\n";
            arr[i].nhap();
        }
    }

    // Hàm xuất
    void xuat() const {
        cout << "Ma SV: " << MaSV << ", Ten SV: " << TenSV << endl;
        for (int i = 0; i < SoMH; ++i) {
            cout << "\tMon hoc thu " << i + 1 << ": ";
            arr[i].xuat();
        }
        cout << "\t==> Diem tong ket: " << DTK() << endl;
    }

    // Tính điểm tổng kết
    float DTK() const {
        float tongTich = 0;
        int tongTC = 0;
        for (int i = 0; i < SoMH; ++i) {
            tongTich += arr[i].getDTB() * arr[i].getSoTC();
            tongTC += arr[i].getSoTC();
        }
        if (tongTC == 0) return 0;
        return tongTich / tongTC;
    }

    // Kiểm tra học lại
    bool hocLai() const {
        return DTK() < 4.0;
    }
};

// ======= Chương trình chính =======
int main() {
    // 1. Nhập và hiển thị một môn học
    cout << "=== NHAP & XUAT MOT MON HOC ===\n";
    MonHoc mh;
    mh.nhap();
    cout << "\nThong tin mon hoc vua nhap:\n";
    mh.xuat();

    // 2. Nhập và xuất n sinh viên
    int n;
    cout << "\nNhap so luong sinh vien: ";
    cin >> n;
    cin.ignore();

    SinhVien* ds = new SinhVien[n];

    for (int i = 0; i < n; ++i) {
        cout << "\n=== Nhap thong tin sinh vien thu " << i + 1 << " ===\n";
        ds[i].nhap();
    }

    cout << "\n=== DANH SACH SINH VIEN VA DIEM TONG KET ===\n";
    for (int i = 0; i < n; ++i) {
        cout << "\nThong tin sinh vien thu " << i + 1 << ":\n";
        ds[i].xuat();
    }

    // 3. Đếm số sinh viên học lại
    int demHocLai = 0;
    for (int i = 0; i < n; ++i) {
        if (ds[i].hocLai()) demHocLai++;
    }

    cout << "\nSo sinh vien bi hoc lai (DTK < 4): " << demHocLai << endl;

    // Giải phóng bộ nhớ
    delete[] ds;

    return 0;
}

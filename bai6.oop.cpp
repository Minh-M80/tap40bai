#include <iostream>
#include <string>
using namespace std;

// ====== Lớp SV ======
class SV {
protected:
    string MaSV;
    string hoten;

public:
    // Hàm thiết lập mặc định
    SV() {
        MaSV = "";
        hoten = "";
    }

    // Hàm huỷ
    ~SV() {
        // không cần làm gì vì không cấp phát động
    }

    // Hàm nhập
    void nhap() {
        cout << "Nhap MaSV: ";
        getline(cin, MaSV);
        cout << "Nhap Ho ten: ";
        getline(cin, hoten);
    }

    // Hàm hiển thị
    void hienthi() const {
        cout << "MaSV: " << MaSV << ", Ho ten: " << hoten << endl;
    }
};

// ====== Lớp SVSDH kế thừa từ SV ======
class SVSDH : public SV {
private:
    float hocphi;

public:
    // Hàm thiết lập mặc định
    SVSDH() : SV() {
        hocphi = 0;
    }

    // Hàm huỷ
    ~SVSDH() {
        // không cần làm gì
    }

    // Hàm nhập
    void nhap() {
        SV::nhap();
        cout << "Nhap hoc phi: ";
        cin >> hocphi;
        cin.ignore(); // Xóa ký tự newline trong buffer
    }

    // Hàm hiển thị
    void hienthi() const {
        SV::hienthi();
        cout << "Hoc phi: " << hocphi << endl;
    }

    // Trả về học phí
    float getHocphi() const {
        return hocphi;
    }
};

// ====== Chương trình chính ======
int main() {
    // 1. Nhập và hiển thị thông tin 1 SV
    cout << "=== NHAP VA HIEN THI 1 SINH VIEN ===" << endl;
    SV sv1;
    sv1.nhap();
    cout << "\nThong tin sinh vien vua nhap:" << endl;
    sv1.hienthi();

    // 2. Nhập thông tin n học viên cao học
    int n;
    cout << "\nNhap so luong hoc vien cao hoc: ";
    cin >> n;
    cin.ignore(); // Xóa ký tự newline

    SVSDH* ds = new SVSDH[n];

    for (int i = 0; i < n; ++i) {
        cout << "\nNhap thong tin hoc vien thu " << i + 1 << ":" << endl;
        ds[i].nhap();
    }

    // 3. Hiển thị thông tin các học viên cao học
    cout << "\n=== DANH SACH HOC VIEN CAO HOC ===" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Hoc vien thu " << i + 1 << ":" << endl;
        ds[i].hienthi();
    }

    // 4. Hiển thị các học viên có học phí > 9000
    cout << "\n=== HOC VIEN CO HOC PHI > 9000 ===" << endl;
    for (int i = 0; i < n; ++i) {
        if (ds[i].getHocphi() > 9000) {
            ds[i].hienthi();
        }
    }

    // Giải phóng bộ nhớ
    delete[] ds;

    return 0;
}

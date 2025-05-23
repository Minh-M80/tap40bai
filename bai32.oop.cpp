#include <iostream>
#include <string>
using namespace std;

// ======== Lớp DichVu ==========
class DichVu {
private:
    string maDV;
    string tenDV;
    double giaCuoc;

public:
    // Hàm khởi tạo
    DichVu() {
        maDV = "";
        tenDV = "";
        giaCuoc = 0;
    }

    // Nhập
    void Nhap() {
        cout << "Nhap ma dich vu: ";
        getline(cin, maDV);
        cout << "Nhap ten dich vu: ";
        getline(cin, tenDV);
        cout << "Nhap gia cuoc: ";
        cin >> giaCuoc;
        cin.ignore(); // Xóa bộ đệm
    }

    // Xuất
    void Xuat() {
        cout << "Ma DV: " << maDV << ", Ten DV: " << tenDV << ", Gia cuoc: " << giaCuoc << endl;
    }

    // Lấy giá cước
    double LayGiaCuoc() {
        return giaCuoc;
    }
};

// ======== Lớp Nguoi ==========
class Nguoi {
private:
    string hoTen;
    string diaChi;
    string soDT;

public:
    // Hàm khởi tạo
    Nguoi() {
        hoTen = "";
        diaChi = "";
        soDT = "";
    }

    // Nhập
    void Nhap() {
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap dia chi: ";
        getline(cin, diaChi);
        cout << "Nhap so dien thoai: ";
        getline(cin, soDT);
    }

    // Xuất
    void Xuat() {
        cout << "Ho ten: " << hoTen << ", Dia chi: " << diaChi << ", So DT: " << soDT << endl;
    }
};

// ======== Lớp KhachHang kế thừa từ Nguoi ==========
class KhachHang : public Nguoi {
private:
    int soLuongDichVu;
    DichVu dv[100];

public:
    // Hàm khởi tạo
    KhachHang() {
        soLuongDichVu = 0;
    }

    // Nhập
    void Nhap() {
        Nguoi::Nhap(); // Gọi hàm Nhap của lớp cha
        cout << "Nhap so luong dich vu da su dung: ";
        cin >> soLuongDichVu;
        cin.ignore(); // Xóa bộ đệm
        for (int i = 0; i < soLuongDichVu; ++i) {
            cout << "Nhap thong tin dich vu thu " << i + 1 << ":" << endl;
            dv[i].Nhap();
        }
    }

    // Xuất
    void Xuat() {
        Nguoi::Xuat(); // Gọi hàm Xuat của lớp cha
        cout << "So luong dich vu da su dung: " << soLuongDichVu << endl;
        for (int i = 0; i < soLuongDichVu; ++i) {
            cout << "  Dich vu " << i + 1 << ": ";
            dv[i].Xuat();
        }
    }

    // Tính tổng giá cước
    double TongGiaCuoc() {
        double tong = 0;
        for (int i = 0; i < soLuongDichVu; ++i) {
            tong += dv[i].LayGiaCuoc();
        }
        return tong;
    }
};

// ======== Chương trình chính ==========
int main() {
    // (3) Nhập thông tin 1 người
    cout << "=== Nhap thong tin mot nguoi ===" << endl;
    Nguoi n;
    n.Nhap();

    // (2) Xuất thông tin người đó
    cout << "\n=== Thong tin nguoi vua nhap ===" << endl;
    n.Xuat();

    // (2) Nhập thông tin khách hàng
    cout << "\n=== Nhap thong tin khach hang ===" << endl;
    KhachHang kh;
    kh.Nhap();

    // (2) Xuất thông tin khách hàng
    cout << "\n=== Thong tin khach hang ===" << endl;
    kh.Xuat();

    // (1) Tính và hiển thị tổng giá cước
    cout << "\nTong gia cuoc khach hang da su dung: " << kh.TongGiaCuoc() << endl;

    return 0;
}

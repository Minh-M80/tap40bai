#include <iostream>
#include <string>
using namespace std;

// ======= Lớp DATE =======
class DATE {
private:
    int ngay, thang, nam;

public:
    DATE() {
        ngay = thang = nam = 1;
    }

    ~DATE() {}

    void nhap() {
        cout << "Nhap ngay: ";
        cin >> ngay;
        cout << "Nhap thang: ";
        cin >> thang;
        cout << "Nhap nam: ";
        cin >> nam;
    }

    void xuat() const {
        cout << ngay << "/" << thang << "/" << nam;
    }

    // Dùng cho so sánh ngày mượn < 1/1/2020
    bool truocNgay(int d, int m, int y) const {
        if (nam < y) return true;
        if (nam == y && thang < m) return true;
        if (nam == y && thang == m && ngay < d) return true;
        return false;
    }

    // Cho lớp MUONTRA truy cập ngày, tháng, năm
    int getNgay() const { return ngay; }
    int getThang() const { return thang; }
    int getNam() const { return nam; }
};

// ======= Lớp MUONTRA =======
class MUONTRA : public DATE {
private:
    string maDocGia;
    string maSach;
    int soLuong;
    static float phiCuoc;  // Phí cược mượn trả (tĩnh)

public:
    MUONTRA() {
        maDocGia = maSach = "";
        soLuong = 0;
    }

    ~MUONTRA() {}

    void nhap() {
        cout << "Nhap ma doc gia: ";
        cin.ignore();
        getline(cin, maDocGia);
        cout << "Nhap ma sach: ";
        getline(cin, maSach);
        cout << "Nhap ngay thang nam muon:\n";
        DATE::nhap();
        cout << "Nhap so luong muon: ";
        cin >> soLuong;
    }

    void xuat() const {
        cout << "Ma doc gia: " << maDocGia
             << ", Ma sach: " << maSach
             << ", Ngay muon: ";
        DATE::xuat();
        cout << ", So luong: " << soLuong
             << ", So tien cuoc: " << tinhTienCuoc() << endl;
    }

    float tinhTienCuoc() const {
        return soLuong * phiCuoc;
    }

    bool muonTruocNgay(int d, int m, int y) const {
        return DATE::truocNgay(d, m, y);
    }

    string getMaDocGia() const {
        return maDocGia;
    }

    float getTienCuoc() const {
        return tinhTienCuoc();
    }

    // Hàm tĩnh thiết lập phí cược
    static void setPhiCuoc(float p) {
        phiCuoc = p;
    }
};

// Khởi tạo phí cược mặc định
float MUONTRA::phiCuoc = 10000;

int main() {
    // 1. Nhập và xuất 1 DATE
    cout << "=== Nhap & Xuat 1 Ngay ===\n";
    DATE d1;
    d1.nhap();
    cout << "Ngay vua nhap: ";
    d1.xuat();
    cout << endl;

    // 2. Nhập thông tin n đối tượng MUONTRA
    int n;
    cout << "\nNhap so luong giao dich MUONTRA: ";
    cin >> n;

    MUONTRA* ds = new MUONTRA[n];
    for (int i = 0; i < n; ++i) {
        cout << "\n=== Nhap thong tin MUONTRA thu " << i + 1 << " ===\n";
        ds[i].nhap();
    }

    // 3. In thông tin MUONTRA
    cout << "\n=== Danh sach MUONTRA ===\n";
    for (int i = 0; i < n; ++i) {
        ds[i].xuat();
    }

    // 4. Độc giả mượn trước ngày 1/1/2020
    cout << "\n=== Doc gia muon truoc 1/1/2020 ===\n";
    for (int i = 0; i < n; ++i) {
        if (ds[i].muonTruocNgay(1, 1, 2020)) {
            cout << "Ma doc gia: " << ds[i].getMaDocGia() << ", Ngay muon: ";
            ds[i].xuat();
        }
    }

    // 5. Doc gia có số tiền cược nhiều nhất
    float maxCuoc = 0;
    for (int i = 0; i < n; ++i) {
        float tien = ds[i].getTienCuoc();
        if (tien > maxCuoc) maxCuoc = tien;
    }

    cout << "\n=== Doc gia co tien cuoc nhieu nhat (" << maxCuoc << ") ===\n";
    for (int i = 0; i < n; ++i) {
        if (ds[i].getTienCuoc() == maxCuoc) {
            cout << ds[i].getMaDocGia() << endl;
        }
    }

    delete[] ds;
    return 0;
}

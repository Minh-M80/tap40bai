// Bài tập 8:
// Xây dựng chương trình quản lý sách và băng video cua một cửa hàng, chương trình gồm:
// +Xây dựng lớp Media mô tả các đối tượng phương tiện truyền thông, lớp gồm:
// 	- Thuộc tính: tên gọi, giá bán.
// 	- Phương thức: Hàm thiết lập, hàm huỷ bỏ, Hàm nhập dữ liệu, Hàm hiển thị dữ liệu.
// +Xây dựng lớp Video mô tả các đối tượng băng video, lớp kế thừa từ lớp Media và bổ sung thêm:
// 	- Thuộc tính: thời gian chạy.
// - Phương thức: Hàm thiết lập, Hàm nhập dữ liệu, Hàm hiển thị dữ liệu.
// Chương trình chính: 
// (3 -) Nhập từ bàn phím thông tin của một phương tiện truyền thông media. 
// (2 -) Hiển thị thông tin của phương tiện truyền thông media vừa nhập ra màn hình.
// (2 -) Nhập thông tin cho n đối tượng Video.
// (1 -) In ra màn hình thông tin của n đối tượng Video.
// (2 -) Hiển thị ra màn hình những cuốn sách có tên “Huong dan lap trinh Python” có thời gian chạy trên 10 đơn vị tính. 

#include <iostream>
#include <string>
using namespace std;

// ====== Lớp Media ======
class Media {
protected:
    string ten;
    float giaban;

public:
    // Constructor mặc định
    Media() {
        ten = "";
        giaban = 0.0;
    }

    // Destructor
    virtual ~Media() {}

    // Hàm nhập dữ liệu
    virtual void nhap() {
        cout << "Nhap ten phuong tien: ";
        getline(cin, ten);
        cout << "Nhap gia ban: ";
        cin >> giaban;
        cin.ignore(); // Xóa newline trong buffer
    }

    // Hàm hiển thị dữ liệu
    virtual void hienthi() const {
        cout << "Ten: " << ten << ", Gia ban: " << giaban << endl;
    }

    // Getter để so sánh tên
    string getTen() const {
        return ten;
    }
};

// ====== Lớp Video kế thừa Media ======
class Video : public Media {
private:
    float thoigian;

public:
    // Constructor mặc định
    Video() : Media() {
        thoigian = 0.0;
    }

    // Destructor
    ~Video() {}

    // Hàm nhập
    void nhap() override {
        Media::nhap();
        cout << "Nhap thoi gian chay: ";
        cin >> thoigian;
        cin.ignore();
    }

    // Hàm hiển thị
    void hienthi() const override {
        Media::hienthi();
        cout << "Thoi gian chay: " << thoigian << endl;
    }

    // Getter
    float getThoigian() const {
        return thoigian;
    }
};

// ====== Chương trình chính ======
int main() {
    // 1. Nhập và hiển thị 1 đối tượng Media
    cout << "=== NHAP VA HIEN THI 1 DOI TUONG MEDIA ===" << endl;
    Media media;
    media.nhap();
    cout << "\nThong tin Media vua nhap:" << endl;
    media.hienthi();

    // 2. Nhập n video
    int n;
    cout << "\nNhap so luong Video: ";
    cin >> n;
    cin.ignore();

    Video* ds = new Video[n];
    for (int i = 0; i < n; ++i) {
        cout << "\nNhap thong tin Video thu " << i + 1 << ":" << endl;
        ds[i].nhap();
    }

    // 3. Hiển thị danh sách video
    cout << "\n=== DANH SACH VIDEO ===" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Video thu " << i + 1 << ":" << endl;
        ds[i].hienthi();
    }

    // 4. Tìm video có tên “Huong dan lap trinh Python” và thời gian > 10
    cout << "\n=== VIDEO TEN 'Huong dan lap trinh Python' VA THOI GIAN > 10 ===" << endl;
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (ds[i].getTen() == "Huong dan lap trinh Python" && ds[i].getThoigian() > 10) {
            ds[i].hienthi();
            found = true;
        }
    }
    if (!found) {
        cout << "Khong co video nao thoa man dieu kien.\n";
    }

    // Giải phóng bộ nhớ
    delete[] ds;

    return 0;
}

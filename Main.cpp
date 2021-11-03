#include<iostream>
#include<fstream>
#include "QuanLy.h"
#include "DatTra.h"
#include "XuLy.h"

#include"MainFunction.h"
using namespace std;

int main()
{
	KhachHang* dsKhachHang[30];
	int soluongKhachHang;
	ChuyenBay* dsChuyenBay[30];
	int soluongChuyenBay;
	TaiKhoan* dsTaiKhoan[20];
	int soluongTaiKhoan;
	string User, Password;

	QUEUE q;
	KhoiTaoQueue(q);
	Ve x;

	DocFileChuyenBay(dsChuyenBay, soluongChuyenBay);
	DocFileKhachHang(dsKhachHang, soluongKhachHang);
	DocFileTaiKhoan(dsTaiKhoan, soluongTaiKhoan);

	backgrout();
	VeKhung();
	KhungGioiThieu();
	KhungHuongDan();
	//Demo + Test lỗi
	int luachon;
	
	do
	{
		cout << "\n\t\t ============== TEST LOI ==============" << endl;
		cout << "\t1.Hien thi danh sach chuyen bay" << endl;
		cout << "\t2.Dat Ve" << endl;
		cout << "\t3.Dang nhap Admin" << endl;

		cout << "\n\t\t  ============== End ==============" << endl;
		cout << "Nhap lua chon = ";
		cin >> luachon;

		switch (luachon)
		{
		case 1:
		{
			XuatDSChuyenBay(dsChuyenBay, soluongChuyenBay);
			break;
		}
		case 2:
		{
			NhapQueue(q, x);
			break;
		}
		case 3:
		{
			DangNhap(dsTaiKhoan,soluongTaiKhoan, User, Password, q);
			break;
		}
		case 4:
		{
			string MaCB = "VN001";
			XuatDSGheTrong(dsChuyenBay, soluongChuyenBay, MaCB);
		}
		default:
			break;
		}
	} while (luachon != 0);
	return 0;
}
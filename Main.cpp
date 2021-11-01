#include<iostream>
#include<fstream>
#include "QuanLy.h"
#include "XuLy.h"
#include "DatTra.h"

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

	//Demo + Test lỗi
	int luachon;
	
	do
	{
		cout << "\n\t\t ============== TEST LOI ==============" << endl;
		cout << "\t1.Doc xuat file Khach Hang" << endl;
		cout << "\t2.Them khach hang ( xu ly dat ve)" << endl;
		cout << "\t3.Dang nhap Admin" << endl;
		cout << "\t4.Xuat DS Chuyen bay" << endl;
		cout << "\t5.Test tao ve" << endl;
		cout << "\t6.Test Queue Dat ve";

		cout << "\n\t\t  ============== End ==============" << endl;
		cout << "Nhap lua chon = ";
		cin >> luachon;

		DocFileChuyenBay(dsChuyenBay, soluongChuyenBay);
		DocFileKhachHang(dsKhachHang, soluongKhachHang);
		DocFileTaiKhoan(dsTaiKhoan, soluongTaiKhoan);
		switch (luachon)
		{
		case 1:
		{
		
			XuatKhachHang(dsKhachHang, soluongKhachHang);
			break;
		}
		case 2:
		{
			ThemKhachHang(dsKhachHang, soluongKhachHang);
			break;
		}
		case 3:
		{
			DangNhap(dsTaiKhoan,soluongTaiKhoan, User, Password);
			break;
		}
		case 4:
		{
			XuatDSChuyenBay(dsChuyenBay, soluongChuyenBay);
			break;
		}
		case 5:
		{
			string Vt = "";
			cout << taoMaVe(dsChuyenBay, soluongChuyenBay,Vt);
			break;
		}
		case 6:
		{
			MenuQueue(q);
			break;
		}
		default:
			break;
		}
	} while (luachon != 0);
	return 0;
}
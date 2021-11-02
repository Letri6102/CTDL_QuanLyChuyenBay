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

	DocFileChuyenBay(dsChuyenBay, soluongChuyenBay);
	DocFileKhachHang(dsKhachHang, soluongKhachHang);
	DocFileTaiKhoan(dsTaiKhoan, soluongTaiKhoan);
	KhoiTaoGheTrong(dsChuyenBay, soluongChuyenBay);
	//Demo + Test lỗi
	int luachon;
	
	do
	{
		cout << "\n\t\t ============== TEST LOI ==============" << endl;
		cout << "\t1.Hien thi danh sach chuyen bay" << endl;
		cout << "\t2.Dat Ve" << endl;
		cout << "\t3.Dang nhap Admin" << endl;
		cout << "\t4.Xuat DS Chuyen bay" << endl;
		cout << "\t5.Test tao ve" << endl;
		cout << "\t6.Test Queue Dat ve";

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
			//inVe(x);
			break;
		}
		case 6:
		{
			MenuQueue(q);
			break;
		}
		case 7:
		{
			string MCB;
			cin >> MCB;
			ChuyenBay *h = TimKiemChuyenBay(dsChuyenBay, soluongChuyenBay, MCB);
			int soGhe;
			cin >> soGhe;
			DatGhe(h, soGhe);
			DatGhe(h, 15);
			cout << h->SanBayDen;
		}
		default:
			break;
		}
	} while (luachon != 0);
	return 0;
}
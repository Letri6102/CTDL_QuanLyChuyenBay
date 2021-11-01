#pragma once
#pragma warning(disable:4996)

#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<Windows.h>
#include "QuanLy.h"

using namespace std;

//--------Chuyến bay
void DocFileChuyenBay(ChuyenBay* dsChuyenBay[30], int& soluongChuyenBay)
{
	soluongChuyenBay = 0;
	fstream f("CHUYENBAY\\ChuyenBay.txt");
	if (!f.is_open())
		return;
	while (!f.eof())
	{
		dsChuyenBay[soluongChuyenBay] = new ChuyenBay;
		f >> dsChuyenBay[soluongChuyenBay]->MaChuyenBay;
		f >> dsChuyenBay[soluongChuyenBay]->NgayKhoiHanh;
		f >> dsChuyenBay[soluongChuyenBay]->SanBayDen;
		f >> dsChuyenBay[soluongChuyenBay]->TrangThai;
		f >> dsChuyenBay[soluongChuyenBay]->dsVe;
		soluongChuyenBay++;
	}
}

void Xuat1ChuyenBay(ChuyenBay* b)
{
	cout << "" << b->MaChuyenBay << "\t" << b->NgayKhoiHanh << "\t" << b->SanBayDen << "\t" << b->TrangThai << "\t" <<b->dsVe;
}

void XuatDSChuyenBay(ChuyenBay* dsChuyenBay[30], int soluongChuyenBay)
{
	for (int i = 0; i < soluongChuyenBay; i++)
	{
		Xuat1ChuyenBay(dsChuyenBay[i]);
		cout << endl;
	}
}

//--------Khách Hàng
void DocFileKhachHang(KhachHang* dsKhachHang[30], int& soluongKhachHang)
{
	soluongKhachHang = 0;
	fstream f("KHACHHANG\\KhachHang.txt");
	if (!f.is_open())
		return;
	while (!f.eof())
	{
		if (soluongKhachHang >= 30) // So luong toi da chuyen bay 
			return;
		dsKhachHang[soluongKhachHang] = new KhachHang;
		f >> dsKhachHang[soluongKhachHang]->STT;
		f >> dsKhachHang[soluongKhachHang]->HoTen;
		f >> dsKhachHang[soluongKhachHang]->CMND;
		soluongKhachHang++;
	}
}

void Xuat1KhachHang(KhachHang* h)
{
	cout << "" << h->STT << "\t" << h->HoTen << "\t" << h->CMND;
}

void XuatKhachHang(KhachHang* dsKhachHang[30], int& soluongKhachHang)
{
	for (int i = 0; i < soluongKhachHang; i++)
	{
		Xuat1KhachHang(dsKhachHang[i]);
		cout << endl;
	}
}

KhachHang* TimKiemKhachHang(KhachHang* dsKhachHang[30], int soluongKhachHang, int STT)
{
	for (int i = 0; i < soluongKhachHang; i++)
	{
		if (STT == dsKhachHang[i]->STT)
			return dsKhachHang[i];
	}
	return NULL;
}

void ThemKhachHang(KhachHang* dsKhachHang[60], int& soluongKhachHang)
{
	KhachHang* h = new KhachHang;
	if (soluongKhachHang > 60)
		return;
	cout << "Nhap STT: ";
	cin >> h->STT;
	if (TimKiemKhachHang(dsKhachHang, soluongKhachHang, h->STT))
		cout << "Da co nguoi dat ve";
	if (TimKiemKhachHang(dsKhachHang, soluongKhachHang, h->STT) != NULL)
		return;
	cout << "Nhap CMND: ";
	cin >> h->CMND;
	cout << "Nhap Hoten: ";
	cin >> h->HoTen;
	fstream f("KHACHHANG\\KhachHang.txt", ios::app);
	if (!f.is_open())
		return;
	dsKhachHang[soluongKhachHang] = h;
	f << "\n" << h->STT << "\t" << h->CMND << "\t" << h->HoTen;
	soluongKhachHang++;
}

//-----------Ve
string taoMaVe(ChuyenBay* dsChuyenBay[30], int soluongChuyenBay, string Vt)
{
	string a = "";
	int i;
	cout << "Nhap chuyen Bay: "; 
	cin >> i;
	cout << "Nhap so ghe: ";
	cin >> Vt;
	a = dsChuyenBay[i-1]->MaChuyenBay + Vt;
		return a;
}

bool checkDatVe(KhachHang* dsKhachHang[30], int& soluongKhachHang, Ve &x)
{
	for (int i = 0; i < soluongKhachHang; i++)
	{
		if (x.ThongTinKhachHang.HoTen == dsKhachHang[i]->HoTen)
			return true;
	}
	return false;
}

//----------Admin 
void DocFileTaiKhoan(TaiKhoan *dsTaiKhoan[20], int& soluongTaiKhoan)
{
	soluongTaiKhoan = 0;
	fstream f("ADMIN\\Admin.txt");
	if (!f.is_open())
		return;
	while(!f.eof())
	{
		dsTaiKhoan[soluongTaiKhoan] = new TaiKhoan;
		f >> dsTaiKhoan[soluongTaiKhoan]->User;
		f >> dsTaiKhoan[soluongTaiKhoan]->Password;
		soluongTaiKhoan++;
	}
}

bool checkDangNhap(TaiKhoan* dsTaiKhoan[20], int soluongTaiKhoan, string User, string Password)
{
	for (int i = 0; i < soluongTaiKhoan; i++)
	{
		if (User == dsTaiKhoan[i]->User && Password == dsTaiKhoan[i]->Password)
			return true;
	}
	return false;
}

void DangNhap(TaiKhoan* dsTaiKhoan[20], int soluongTaiKhoan, string User, string Password)
{
	char x;
	int temp = 0;
	User = "";
	while (temp < 3)
	{	
		system("cls");
		cout << "\n\t\t ============== DANG NHAP HE THONG ==============" << endl;
		cout << "\n\t\tUser: ";
		cin >> User;
		Password = "";
		cout << "\n\t\tPassword: ";
		while (true)
		{
			x = _getch(); 

			if (x == 13) 
			{
				break;
			}
			else if (x == 8) 
			{
				Password.erase(Password.begin() + Password.length() - 1);
				cout << "\b \b"; 
			}
			else if (((x >= '0' && x <= '9') || (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || x >= 32 && x <= 39))
			{
				if (Password.length() <= 16)
				{
					cout << x;
					_sleep(200);
					cout << "\b";
					cout << "*"; 
					Password.push_back(x); 
				}
			}
		}
		if (checkDangNhap(dsTaiKhoan,soluongTaiKhoan,User,Password)) 
		{
			cout << "\nLoading";
			for (int i = 1; i <= 8; i++)
			{
				cout << ".";
				Sleep(500);
			}
			//DO SOME THING
			cout << " Successfull";
			Sleep(200);
			cout << endl;
			cout << "Done!";

			break;
		}
		else
		{
			cout << endl;
			temp++;
			if (temp == 3)
			{
				cout << "\n\t\tWRONG PASSWORD PLEASE TRY AGAIN!";
				cout << "\n\n";
				break;
			}
		}
	}
}


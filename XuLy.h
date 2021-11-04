#pragma once
#pragma warning(disable:4996)

#include<iostream>
#include<conio.h>
#include<Windows.h>
#include "QuanLy.h"
#include "DatTra.h"
#include "Design.h"

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
		dsChuyenBay[soluongChuyenBay]->dsGheTrong = new bool[dsChuyenBay[soluongChuyenBay]->dsVe]; //Cap phat so luong ve
		// B1: Chay for khai báo so ghe trong la false ( chua dat ve) - true dat ve - khoi tao false
		// B2: Goi lai chuyen bay -> ghetrong = flase la dc dat ve
		soluongChuyenBay++;
	}
}

void Xuat1ChuyenBay(ChuyenBay* b)
{
	cout << "" << b->MaChuyenBay << "\t" << b->NgayKhoiHanh << "\t" << b->SanBayDen << "\t\t" << b->TrangThai << "\t" << b->dsVe;
}

void XuatDSChuyenBay(ChuyenBay* dsChuyenBay[30], int soluongChuyenBay)
{
	int y = Tuong_tren;
	setTextColor(1);
	out_toando(Tuong_phai + 2, ++y, "  MaCB       Ngay Khoi Hanh    San Bay Den       TrangThai   SoVe ");
	for (int i = 0; i < soluongChuyenBay; i++)
	{
		setTextColor(15);
		gotoXY(Tuong_phai + 4, ++y);
		Xuat1ChuyenBay(dsChuyenBay[i]);
	}
}

ChuyenBay* TimKiemChuyenBay(ChuyenBay* dsChuyenBay[30], int soluongChuyenBay, string MCB)
{
	for (int i = 0; i < soluongChuyenBay; i++)
	{
		if (MCB == dsChuyenBay[i]->MaChuyenBay)
			return dsChuyenBay[i];
	}
	//return NULL;
}

bool checkMaCB(ChuyenBay* dsChuyenBay[30], int soluongChuyenBay, string MCB)
{
	for (int i = 0; i < soluongChuyenBay; i++)
	{
		if (MCB == dsChuyenBay[i]->MaChuyenBay)
			return true;
	}
	return false;
}

//---------Xu ly ghe trong
void GheTrong(ChuyenBay* h)
{
	for (int i = 0; i < h->dsVe; i++)
	{
		h->dsGheTrong[i] = false;
	}
}

void KhoiTaoGheTrong(ChuyenBay* dsChuyenBay[30], int soluongChuyenBay)
{
	for (int i = 0; i < soluongChuyenBay; i++)
	{
		if (dsChuyenBay[i]->TrangThai == 3)
			return;
		GheTrong(dsChuyenBay[i]);
	}
}

void DSGheTrong(ChuyenBay* h)
{
	for (int i = 1; i <= 10; i++)
	{
		if (h->dsGheTrong[i] == false)
			cout << i << endl;
	}
}

void XuatDSGheTrong(ChuyenBay* dsChuyenBay[30], int soluongChuyenBay, string MaCB)
{
	ChuyenBay* h = TimKiemChuyenBay(dsChuyenBay, soluongChuyenBay, MaCB);
	DSGheTrong(h);
}

//----------Dat cho ngoi
void DatGhe(ChuyenBay* h, int soGhe)
{
	int y = Tuong_tren;
	if (h->dsGheTrong[soGhe] == false)
	{
		setTextColor(10);
		h->dsGheTrong[soGhe] = true;
		out_toando(Tuong_phai + 25, ++y + 15, "Dat so ghe thanh cong!");
	}
	else
	{
		setTextColor(4);
		out_toando(Tuong_phai + 25, ++y + 15, "Ghe nay da co nguoi dat!");
	}
}

//Xử lý trạng thái máy bay
bool TrangThai(ChuyenBay* h)
{
	if (h->TrangThai == 3 || h->TrangThai == 0)
	{
		return false;
	}
	return true;
}

void XuLyTrangThai(ChuyenBay* h)
{
	int y = Tuong_tren;
	setTextColor(4);
	if (h->TrangThai == 3)
	{
		out_toando(Tuong_phai + 25, ++y + 8, "CHUYEN BAY NAY DA HOAN TAT!");
		out_toando(Tuong_phai + 22, ++y + 9, " Vui long chon chuyen bay khac!");
	}
	else if (h->TrangThai == 0)
	{
		out_toando(Tuong_phai + 25, ++y + 8, "CHUYEN BAY NAY DA BI HUY! ");
		out_toando(Tuong_phai + 22, ++y + 9, "Vui long chon chuyen bay khac!");
	}
}

//-----------Vé
string taoMaVe(ChuyenBay* h, string soGhe)
{
	string a = "";
	a = h->MaChuyenBay + soGhe;
	return a;
}

void inVe(Ve x, ChuyenBay* h, string soGhe)
{
	string MaVe = taoMaVe(h,soGhe);
	fstream f;
	f.open(MaVe, ios::out);
	if (!f.is_open())
		return;
	f << x.ThongTinKhachHang.HoTen << "\t" << x.ThongTinKhachHang.CMND <<"\t" << soGhe;
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


//Xu ly Dat ve
/*
KhachHang* dsKhachHang[30];
int soluongKhachHang;
ChuyenBay* dsChuyenBay[30];
int soluongChuyenBay;*/

//Đặt vé
void NhapQueue(QUEUE& q, Ve x, ChuyenBay* dsChuyenBay[30], int& soluongChuyenBay)
{
	DocFileChuyenBay(dsChuyenBay, soluongChuyenBay);
	//KhoiTaoGheTrong(dsChuyenBay, soluongChuyenBay);
	setTextColor(11);
	cls_sreen();
	int y = Tuong_tren;
	out_toando(Tuong_phai + 13, ++y + 2, "============== DAT VE MAY BAY ==============");
	out_toando(Tuong_phai + 10, ++y + 5, "Nhap ma chuyen bay: ");
	cin >> x.ThongTinChuyenBay.MaChuyenBay;
	string MaCB = x.ThongTinChuyenBay.MaChuyenBay;

	//Kiểm tra mã chuyến bay hợp lệ
	if(checkMaCB(dsChuyenBay, soluongChuyenBay, MaCB))
	{ 
		ChuyenBay* h = TimKiemChuyenBay(dsChuyenBay, soluongChuyenBay, MaCB);

		//Xử lý trạng thái máy bay (0,1,2,3)
		if (TrangThai(h))
		{
			out_toando(Tuong_phai + 10, ++y + 6, "Nhap ho ten: ");
			cin >> x.ThongTinKhachHang.HoTen;
			out_toando(Tuong_phai + 10, ++y + 7, "Nhap so CMND: ");
			cin >> x.ThongTinKhachHang.CMND;
			int soGhe;
			out_toando(Tuong_phai + 10, ++y + 8, "Nhap so ghe: ");
			cin >> soGhe;
			DatGhe(h, soGhe);
			string maGhe = to_string(soGhe);
			x.MaVe = taoMaVe(h, maGhe);
			inVe(x, h, maGhe);
			NODE* p = KhoiTaoNode(x);
			Push(q, p);
		}
		else
		{
			XuLyTrangThai(h);
		}
	}
	else
	{
		setTextColor(4);
		out_toando(Tuong_phai + 10, ++y + 6, "KHONG TIM THAY CHUYEN BAY HOP LE !!! ");
	}
}


void XuatQueue(QUEUE q)
{
	while (IsEmpty(q) == false)
	{
		Ve x;
		Pop(q, x);
		cout << x.ThongTinChuyenBay.MaChuyenBay << "\t" << x.MaVe << "\t" << x.ThongTinKhachHang.HoTen << "\t" << x.ThongTinKhachHang.CMND;
		cout << endl;
	}
}

//Xử lý Admin
void MenuQueue(QUEUE& q, ChuyenBay* dsChuyenBay[30], int& soluongChuyenBay)
{
	DocFileChuyenBay(dsChuyenBay, soluongChuyenBay);
	int luachon = 1;
	clrscr();
	VeKhung();
	KhungGioiThieu();
	KhungHuongDan();
	toado t;
	t.x = Tuong_Trai + 2;
	t.y = Tuong_Giua;
	while (luachon != 0)
	{

		setTextColor(11);
		out_toando(++t.x, ++t.y, "Xu ly dat ve");
		out_toando(t.x, ++t.y, "Xu ly tra ve");
		out_toando(t.x, ++t.y, "Thong ke");

		setTextColor(11);
		luachon = BatSuKien(++t.y);
		cls_sreen();
		setTextColor(15);
		switch (luachon)
		{
		case 1:
		{
			Beep(600, 100);
			Ve x;
			Top(q, x);
			cout << x.ThongTinChuyenBay.MaChuyenBay << "\t" << x.MaVe << "\t" << x.ThongTinKhachHang.HoTen << "\t" << x.ThongTinKhachHang.CMND;
			Pop(q, x);
			break;
		}
		case 2:
		{
			Beep(600, 100);
			break;
		}
		case 3:
		{
			Beep(600, 100);
			break;
		}
		default:
			break;
		}
		t.x = Tuong_Trai + 2;
		t.y = Tuong_Giua;
	}
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

//Quản lý
void DangNhap(TaiKhoan* dsTaiKhoan[20], int soluongTaiKhoan, string User, string Password, QUEUE& q)
{
	char x;
	int temp = 0;
	User = "";
	while (temp < 3)
	{	
		setTextColor(14);
		cls_sreen();
		int y = Tuong_tren;
		out_toando(Tuong_phai + 13, ++y+5, "============== DANG NHAP HE THONG ==============");
		gotoXY(Tuong_phai + 4, ++y+5);
		setTextColor(9);
		out_toando(Tuong_phai + 10, ++y+5, "User: ");
		cin >> User;
		Password = "";
		out_toando(Tuong_phai + 10, ++y+6, "Password: ");
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
			setTextColor(2);
			out_toando(Tuong_phai + 10, ++y + 7, "Loading");
			for (int i = 1; i <= 10; i++)
			{
				cout << ".";
				Sleep(500);
			}
			//Menu quản lý
			//MenuQueue(q,dsChuyenBay,soluongChuyenBay);
			break;
		}
		else
		{
			cls_sreen();
			setTextColor(4);
			out_toando(Tuong_phai + 10, ++y+7, "TAI KHOAN HOAC MAT KHAU SAI! VUI LONG NHAP LAI!!!");
			temp++;
			if (temp == 3)
			{
				cls_sreen();
				out_toando(Tuong_phai + 25, ++y + 5, "BAN DA NHAP QUA 3 LAN!");
				out_toando(Tuong_phai + 13, ++y + 6, "HAY CHAC RANG BAN DANG DANG NHAP VOI TU CACH ADMIN");
				break;
			}
			_getch();
		}
	}
}


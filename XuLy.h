#pragma once
#pragma warning(disable:4996)

#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<Windows.h>
#include "QuanLy.h"
#include "DatTra.h"

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
	cout << "" << b->MaChuyenBay << "\t" << b->NgayKhoiHanh << "\t" << b->SanBayDen << "\t" << b->TrangThai << "\t" << b->dsVe;
}

void XuatDSChuyenBay(ChuyenBay* dsChuyenBay[30], int soluongChuyenBay)
{
	for (int i = 0; i < soluongChuyenBay; i++)
	{
		Xuat1ChuyenBay(dsChuyenBay[i]);
		cout << endl;
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

//Khoi tao danh sach ghe trong
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

//Dat cho ngoi
void DatGhe(ChuyenBay* h, int soGhe)
{
	if (h->dsGheTrong[soGhe] == false)
	{
		h->dsGheTrong[soGhe] = true;
		cout << "Dat so ghe thanh cong!" << endl;
	}
	else
		cout << "Ghe nay da co nguoi dat!" << endl;
}

void XuLyTrangThai(ChuyenBay* h)
{
	if (h->TrangThai == 3)
	{
		cout << "Chuyen bay nay da hoan tat! Vui long chon chuyen bay khac!" << endl;
	}
	else if (h->TrangThai == 0)
	{
		cout << "Chuyen bay nay da huy! Vui long chon chuyen bay khac!" << endl;
	}
	else 
	{
		cout << "Ban da dat ve thanh cong!" << endl;
	}
}

//-----------Ve
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

bool checkDatVe(KhachHang* dsKhachHang[30], int& soluongKhachHang, Ve &x)
{
	for (int i = 0; i < soluongKhachHang; i++)
	{
		if (x.ThongTinKhachHang.HoTen == dsKhachHang[i]->HoTen)
			return true;
	}
	return false;
}

//Xu ly Dat ve
KhachHang* dsKhachHang[30];
int soluongKhachHang;
ChuyenBay* dsChuyenBay[30];
int soluongChuyenBay;
void NhapQueue(QUEUE& q, Ve x)
{
	cout << "\n\t\tDAT VE ";
	cout << "\nNhap ma chuyen bay: ";
	cin >> x.ThongTinChuyenBay.MaChuyenBay;
	string MaCB = x.ThongTinChuyenBay.MaChuyenBay;
	ChuyenBay* h = TimKiemChuyenBay(dsChuyenBay, soluongChuyenBay, MaCB);

	cout << "\nHo ten: ";
	cin >> x.ThongTinKhachHang.HoTen;
	cout << "\nSo CMND: ";
	cin >> x.ThongTinKhachHang.CMND;

	int soGhe;
	cout << "\nNhap so ghe: ";
	cin >> soGhe;
	DatGhe(h, soGhe);
	string maGhe = to_string(soGhe);
	x.MaVe = taoMaVe(h, maGhe);
	XuLyTrangThai(h);
	inVe(x, h, maGhe);
	system("pause");
	NODE* p = KhoiTaoNode(x);
	Push(q, p);
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
	if (IsEmpty(q) == true)
	{
		cout << "\nDANH SACH DANG RONG";
	}
	else
	{
		cout << "\nDANH SACH DANG TON TAI PHAN TU";
	}
}

void MenuQueue(QUEUE& q)
{
	DocFileChuyenBay(dsChuyenBay, soluongChuyenBay);
	KhoiTaoGheTrong(dsChuyenBay, soluongChuyenBay);
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ============== Menu ==============";
		cout << "\n\t1. Them ve vao queue - Push";
		cout << "\n\t2. Xuat danh sach ve ra man hinh - Pop";
		cout << "\n\t3. Xem thong tin phan tu dau queue - Top";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ============== End ==============";

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon == 1)
		{
			Ve x;
			NhapQueue(q, x);
		}
		else if (luachon == 2)
		{
			XuatQueue(q);
			system("pause");
		}
		else if (luachon == 3)
		{
			Ve x;
			Top(q, x);
			cout << x.ThongTinChuyenBay.MaChuyenBay << "\t" << x.MaVe << "\t" << x.ThongTinKhachHang.HoTen << "\t" << x.ThongTinKhachHang.CMND;
			Pop(q, x);
			system("pause");
		}
		else
		{
			break;
		}
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
			//MenuQueue(q);
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

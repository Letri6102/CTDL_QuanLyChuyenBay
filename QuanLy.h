#pragma once

#include<iostream>
#include<string>

using namespace std;

struct Maybay 
{
	string SoHieuMayBay;
	int SoCho;
};

struct KhachHang 
{
	int STT;
	string CMND;
	string HoTen;
};

struct ChuyenBay
{
	string MaChuyenBay;
	string SoHieuMayBay;
	string NgayKhoiHanh;
	string SanBayDen;
	int TrangThai; //0: Huy chuyen      1: Con ve		2: Het ve		3: Hoan tat
	int dsVe;
	bool* dsGheTrong;
};

struct Ve 
{
	string MaVe; 
	ChuyenBay ThongTinChuyenBay;
	KhachHang ThongTinKhachHang;
};

struct TaiKhoan
{
	string User, Password;
};

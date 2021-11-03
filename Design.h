#pragma once

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include<string>
#include<fstream>
#include "iostream"
using namespace std;

#define BLACK_COLOR			0
#define DARK_BLUE_COLOR		1
#define DARK_GREEN_COLOR	2
#define DARK_CYAN_COLOR		3
#define DARK_RED_COLOR		4
#define DARK_PINK_COLOR		5
#define DARK_YELLOW_COLOR	6
#define DARK_WHITE_COLOR	7
#define GREY_COLOR			8
#define BLUE_COLOR			9
#define GREEN_COLOR			10
#define CYAN_COLOR			11
#define RED_COLOR			12
#define PINK_COLOR			13
#define YELLOW_COLOR		14
#define WHITE_COLOR			15

#define KEY_UP		1072
#define KEY_DOWN	1080
#define KEY_LEFT	1075
#define KEY_RIGHT	1077
#define KEY_NONE	-1
#define Tuong_Trai 5
#define Tuong_phai 40
#define Tuong_tren 1
#define Tuong_Giua 8
#define Tuong_duoi 28
#define Bien_Ben 115
#define Tuong_Duoi_Header 4
#define Tuong_Giua_sreen 80
#define Tuong_Tren_Ifo 21
#define Tuong_Tren_Huong_Dan 16
struct toado
{
	int x;
	int y;
};

// Lấy nút bàn phím do người dùng bấm
// Trả về: Mã của phím
int inputKey();

// Xóa màn hình
void clrscr();

// Di chuyển con trỏ console đến vị trí có tọa độ (x, y)
void gotoXY(int x, int y);

// Lấy tọa độ x hiện tại của con trỏ console
int whereX();

// Lấy tọa độ y hiện tại của con trỏ console
int whereY();

// Xóa con trỏ nháy
void noCursorType();

// Đổi màu chữ
// Tham số: Mã màu
void setTextColor(int color);
//end----------------------Screen----------------------end

int inputKey()
{
	if (_kbhit())
	{
		int key = _getch();

		if (key == 224)
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return KEY_NONE;
	}

	return KEY_NONE;
}

// Xóa màn hình
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

// Di chuyển con trỏ console đến vị trí có tọa độ (x, y)
void gotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Lấy tọa độ x hiện tại của con trỏ console
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}

// Lấy tọa độ y hiện tại của con trỏ console
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}

// Xóa con trỏ nháy
void noCursorType()
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = FALSE;
	info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

void out_toando(int x, int y, string s)
{
	gotoXY(x, y);
	cout << s;
}

// Đổi màu chữ
// Tham số: Mã màu
void setTextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void VeKhung()
{
	setTextColor(11);
	for (int i = Tuong_Trai; i < Bien_Ben; i++)
	{
		gotoXY(i, 0);
		cout << (char)220;
	}
	for (int i = Tuong_tren; i < Tuong_duoi; i++)
	{
		gotoXY(Bien_Ben - 1, i);
		cout << (char)222;
	}
	for (int i = Bien_Ben - 1; i >= Tuong_Trai; i--)
	{
		gotoXY(i, Tuong_duoi - 1);
		cout << (char)223;
	}
	for (int i = Tuong_duoi - 2; i >= Tuong_tren; i--)
	{
		gotoXY(Tuong_Trai, i);
		cout << (char)221;
	}
	for (int i = Tuong_tren; i < Tuong_duoi - 1; i++)
	{
		gotoXY(Tuong_phai - 1, i);
		cout << (char)222;
	}
}
void KhungGioiThieu()
{

	setTextColor(6);
	out_toando(Tuong_Trai + 3, Tuong_tren, "NHOM");
	out_toando((Tuong_phai + Tuong_Trai) / 2 + 6, Tuong_tren, "De_Tai_5");
	out_toando((Tuong_phai + Tuong_Trai) / 2 - 11, Tuong_tren + 1, "MON: Cau Truc Du Lieu");
	out_toando(Tuong_Trai + 3, Tuong_tren + 2, "Le Cong Tri - 4601104194");
	out_toando(Tuong_Trai + 3, Tuong_tren + 3, "Le Cong Tri - 4601104194");
	out_toando(Tuong_Trai + 3, Tuong_tren + 4, "Le Cong Tri - 4601104194");
	out_toando(Tuong_Trai + 3, Tuong_tren + 5, "Le Cong Tri - 4601104194");
	out_toando(Tuong_Trai + 3, Tuong_tren + 6, "Le Cong Tri - 4601104194");
	setTextColor(11);
	for (int i = Tuong_Trai + 1; i < Tuong_phai - 1; i++)
	{
		gotoXY(i, Tuong_Giua);
		cout << (char)223;
	}
}

void KhungHuongDan()
{
	for (int i = Tuong_Trai + 1; i < Tuong_phai - 1; i++)
	{
		gotoXY(i, 23);
		cout << (char)223;
	}
	setTextColor(2);
	out_toando(Tuong_Trai + 12, 23, "Huong Dan");
	out_toando(Tuong_Trai + 5, 24, "Di Chuyen: Phim Mui Ten");
	out_toando(Tuong_Trai + 1, 25, "Enter: chon");
	out_toando(Tuong_Trai + 21, 25, "ESC: Ket Thuc");
	out_toando(Tuong_Trai + 13, 26, "F5: Reset");
	setTextColor(11);
}

void cls_sreen()
{
	for (int i = Tuong_tren + 1; i < Tuong_duoi - 1; i++)
	{
		for (int j = Tuong_phai + 1; j < Bien_Ben - 1; j++)
			out_toando(j, i, " ");
	}
}

void backgrout()
{
	setTextColor(12);
	fstream f("BACKGROUND//introduce.txt");
	if (!f.is_open())
		cout << "\nKhong mo duoc file";
	else
	{
		string str;
		while (!f.eof())
		{
			getline(f, str);
			Sleep(100);
			cout << "\n\t\t\t\t\t\t\t" << str;
		}
		f.close();
		Beep(600, 200);
	}
}

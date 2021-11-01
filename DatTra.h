#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include"QuanLy.h"
#include"XuLy.h"

using namespace std;

KhachHang* dsKhachHang[30];
int soluongKhachHang;
ChuyenBay* dsChuyenBay[30];
int soluongChuyenBay;


struct Node
{
	Ve data;
	struct Node* pNext;
};
typedef struct Node NODE;

struct Queue
{
	NODE* pHead;
	NODE* pTail;
};
typedef struct Queue QUEUE;

//Khoi tao Queue
void KhoiTaoQueue(QUEUE& q)
{
	q.pHead = NULL;
	q.pTail = NULL;
}

NODE* KhoiTaoNode(Ve x)
{
	NODE* p = new NODE();
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !!!";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

//Kiem tra Queue 
bool IsEmpty(QUEUE q)
{
	if (q.pHead == NULL)
	{
		return true;
	}
	return false;
}

//Them phan tu 
bool Push(QUEUE& q, NODE* p)
{
	if (p == NULL)
	{
		return false;
	}

	if (IsEmpty(q) == true)
	{
		q.pHead = q.pTail = p; 
	}
	else
	{
		q.pTail->pNext = p; 
		q.pTail = p;
	}
	return true;
}

//Lay phan tu dau
bool Pop(QUEUE& q, Ve& x) 
{
	if (IsEmpty(q) == true)
	{
		return false;
	}
	else
	{
		NODE* p = q.pHead; 
		x = p->data;
		q.pHead = q.pHead->pNext; 	
		delete p; 

	}
	return true;
}

//Xem thong tin phan tu dau 
bool Top(QUEUE& q, Ve& x) 
{
	if (IsEmpty(q) == true)
	{
		return false;
	}
	x = q.pHead->data; 
	return true;
}

//Dat ve
void NhapQueue(QUEUE &q, Ve x)
{
	cout << "\n\t\tDAT VE ";
	cout << "\nNhap ma chuyen bay: ";
	cin >> x.ThongTinChuyenBay.MaChuyenBay;
	cout << "\nNhap so ghe: "; // Cho nay chua xu ly dc ghe trong 
	cin >> x.MaVe; //ghi tam ma ve
	cout << "\nHo ten: ";
	cin >> x.ThongTinKhachHang.HoTen;
	if (x.ThongTinKhachHang.HoTen == "A")
	{
		cout << "False";
	}
	cout << "\nSo CMND: ";
	cin >> x.ThongTinKhachHang.CMND;
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
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ============== Menu ==============";
		cout << "\n\t1. Them ve vao queue - Push";
		cout << "\n\t2. Xuat danh sach ve ra man hinh - Pop";
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
		else
		{
			break;
		}
	}
}

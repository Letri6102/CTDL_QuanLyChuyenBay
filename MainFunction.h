#pragma once

#include"Design.h"
#include "iostream"
#include"QuanLy.h"
#include"XuLy.h"

using namespace std;
int BatSuKien(int& bien)
{
    noCursorType();
    setTextColor(4);
    toado T;
    T.x = Tuong_Trai + 1;
    T.y = Tuong_Giua + 1;
    out_toando(T.x, T.y, "->");
    while (true)
    {
        ShowCur(0);
        toado cu = T;
        char key = _getch();
        if (key == 13)
        {
            out_toando(cu.x, cu.y, "  ");
            return T.y - Tuong_Giua;
        }
        else if (key == 27)
        {
            system("cls");
            cout << "\n\n\t\tChuong trinh ket thuc";
            return 0;
        }
        else if (key == '?')
        {
            system("cls");
            VeKhung();
            KhungGioiThieu();
            KhungHuongDan();
            return -1;
        }
        else if (key == -32)
            key = _getch();
        switch (key)
        {
        case 80:
            Beep(600, 100);
            T.y++;
            if (T.y == bien)
                T.y = Tuong_Giua + 1;
            out_toando(cu.x, cu.y, "  ");
            out_toando(T.x, T.y, "->");
            break;
        case 72:
            Beep(600, 100);
            T.y--;
            if (T.y == Tuong_Giua)
                T.y = bien - 1;
            out_toando(cu.x, cu.y, "  ");
            out_toando(T.x, T.y, "->");
            break;
        }
    }
}

void menu()
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
    int luachon = 1;

    backgrout();
    VeKhung();
    KhungGioiThieu();
    KhungHuongDan();
    toado t;
    t.x = Tuong_Trai + 2;
    t.y = Tuong_Giua;
    while (luachon != 0)
    {
        DocFileChuyenBay(dsChuyenBay, soluongChuyenBay);
        DocFileKhachHang(dsKhachHang, soluongKhachHang);
        DocFileTaiKhoan(dsTaiKhoan, soluongTaiKhoan);
        KhoiTaoGheTrong(dsChuyenBay, soluongChuyenBay);

        setTextColor(11);
        out_toando(++t.x, ++t.y, "Xuat danh sach chuyen bay");
        out_toando(t.x, ++t.y, "Dat ve");
        out_toando(t.x, ++t.y, "Quan ly chuyen bay");


        setTextColor(11);
        luachon = BatSuKien(++t.y);
        cls_sreen();
        setTextColor(15);
        switch (luachon)
        {
        case 1:
        {
            Beep(600, 100);
            XuatDSChuyenBay(dsChuyenBay, soluongChuyenBay);
            _getch();
            break;
        }
        case 2:
        {
            Beep(600, 100);
            NhapQueue(q, x);
            break;
        }
        case 3: 
        {
            Beep(600, 100);
            DangNhap(dsTaiKhoan, soluongTaiKhoan, User, Password, q);
            break;
        }
        default:
            break;
        }
    }
}
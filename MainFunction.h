#pragma once

#include"Design.h"
#include "iostream"
#include"QuanLy.h"
#include"XuLy.h"

using namespace std;

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
        t.x = Tuong_Trai + 2;
        t.y = Tuong_Giua;
    }
}
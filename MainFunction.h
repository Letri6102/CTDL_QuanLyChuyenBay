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
            cout << "\n\tChuong trinh ket thuc";
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
            T.y++;
            if (T.y == bien)
                T.y = Tuong_Giua + 1;
            out_toando(cu.x, cu.y, "  ");
            out_toando(T.x, T.y, "->");
            break;
        case 72:
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

}
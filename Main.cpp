#include<iostream>
#include<fstream>
#include "QuanLy.h"
#include "DatTra.h"
#include "XuLy.h"

#include"MainFunction.h"
using namespace std;

int main()
{
	menu();
    string a = "11/11/2021";
    int i = a.find("/");
    int i1 = a.find("/", i + 1);
    a = a.substr(i1 + 1, a.length());
    cout << a;
}
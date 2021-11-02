#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include"QuanLy.h"

using namespace std;

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




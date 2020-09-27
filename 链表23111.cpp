#include<iostream>
#include<malloc.h>
#include<stdio.h>
using namespace std;
typedef int Elementdata;
typedef struct Lnode* List;
struct Lnode
{   Elementdata data;  //数据域
   
     List next; // 指向下个数据的指针
}
List  L;
List head;

List Makempty()
{   List L=(List)malloc(sizeof(struct Lnode)); //为链表分配动态结点
       
      L=NULL;
    return L;
}

List Insert(  Elementdata X,int i,List L){
	List p,s;
	if(i == 1){     // 新结点插入在表头 
		s = (List)malloc(sizeof(struct LNode));
		s->Data = X;
		s->Next = L;
		return s;     //插入的结点为头结点 
	}
	p = FindKth(i-1,L);   // 找到第 i-1 个结点
	if(!p){   // 第 i-1 个结点不存在 
		printf("结点错误");
		return NULL;
	}else{
		s = (List)malloc(sizeof(struct LNode));
		s->Data = X;
		s->Next = p->Next;   //将 s 的下一个结点指向 p 的下一个结点 
		p->Next = s;   // 将 p 的下一结点改为 s
		return L;
	}
}











int main()
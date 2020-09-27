#include<iostream>
#include<malloc.h>
#include<stdio.h>
using namespace std;
typedef int Elementdata;
typedef struct Lnode* List;
struct Lnode
{   Elementdata data;  //数据域
   
     List next; // 指向下个数据的指针
};
List  L;
List head;

List Makempty()
{   List L=(List)malloc(sizeof(struct Lnode)); //为链表分配动态内存
       
      L=NULL;
    return L;
}
List FindKth(int K,List L){  //按位置查找
	List p = L;    //用一个临时指针指向 l  指向链表所在的地址
	int i = 1;  //从 1 开始 
	while(p && i<K){
		p = p->next;
		i++;
	}
	if(i == K)    // 找到了 
		return p;
	else    // 未找到 
		return NULL;
} 


List Findknum(Elementdata y,List L)
{  List P=L;
   int i=1;
   while(P&&P->data!=y)
   {
       P=P->next;
   }


   return P;


       
}
List Insert(Elementdata num,int i,List l) //把num插入到l的第L个位置。
{
   List p,s; //两个临时指针
   if(i==1)  //在首节点
    {   s=(List)malloc(sizeof(struct Lnode));

        s->data=num;
        s->next=L;
        return s;    //插入的为头结点   
    }
    //若不是第一个节点
p=FindKth(i-1,L);  // 找到i-1个结点 此时p获得了L的地址
  if(!p)
    {
        cout<<"no exist";
        return NULL;
    }
  else
  {s=(List)malloc(sizeof(struct Lnode));
    s->data=num;
    s->next=p->next;
    p->next=s;

     
return l;

  }



}
void Print(List L)
{
	 List t;

	int flag = 1;
	printf("当前链表为：");
	for(t = L;t;t =t->next){
		printf("%d  ",t->data);
		flag = 0;
	}
	if(flag)
		printf("NULL");
	printf("\n"); 
    
}
int main()
{
    L = Makempty();
	Print(L);
	
	L = Insert(225,1,L);
	L = Insert(33,2,L);
	L = Insert(77,3,L);
    L = Insert(11,4,L);
    L = Insert(14441,1,L);
	Print(L);





}
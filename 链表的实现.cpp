#include<iostream>
#include<malloc.h>
#include<stdio.h>
using namespace std;
typedef int Elementdata;
typedef struct Lnode* List;
struct Lnode
{   Elementdata data;  //������
   
     List next; // ָ���¸����ݵ�ָ��
};
List  L;
List head;

List Makempty()
{   List L=(List)malloc(sizeof(struct Lnode)); //Ϊ������䶯̬�ڴ�
       
      L=NULL;
    return L;
}
List FindKth(int K,List L){  //��λ�ò���
	List p = L;    //��һ����ʱָ��ָ�� l  ָ���������ڵĵ�ַ
	int i = 1;  //�� 1 ��ʼ 
	while(p && i<K){
		p = p->next;
		i++;
	}
	if(i == K)    // �ҵ��� 
		return p;
	else    // δ�ҵ� 
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
List Insert(Elementdata num,int i,List l) //��num���뵽l�ĵ�L��λ�á�
{
   List p,s; //������ʱָ��
   if(i==1)  //���׽ڵ�
    {   s=(List)malloc(sizeof(struct Lnode));

        s->data=num;
        s->next=L;
        return s;    //�����Ϊͷ���   
    }
    //�����ǵ�һ���ڵ�
p=FindKth(i-1,L);  // �ҵ�i-1����� ��ʱp�����L�ĵ�ַ
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
	printf("��ǰ����Ϊ��");
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
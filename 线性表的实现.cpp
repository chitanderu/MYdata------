#include<iostream>
#include<malloc.h>
using namespace std;
const int MAXSIZE=2000;
typedef int datatype;
typedef struct node * List;
struct node{
    datatype num[MAXSIZE];//存放的数
     int n; //表长
};
List L;
  
List makeEmpty()
{   List L;
    L=(List)malloc(sizeof(struct node));
     L->n=0;
     return L;
     
}  //初始化为0的表长
 

int Find(datatype n,List L)   //按照值查找
{   int i=0;
   while(i<=L->n&&L->num[i]!=n)  //以最大值为终止点，在未查找到对应数做i++;
    {
        i++;
    }
     
   if(i>L->n)
     return -1;

    else
    {
        return i;
    }
    


}

int Length(List L)
{
    return L->n;
}

void insert(datatype x,int i,List L)
{   int j;
  if(L->n==MAXSIZE-1) 
     {
            cout<<"full list!";
             return ;  //表满
     }

         if(i<0||i>L->n+1)
          {

              cout<<"error place";
          }

        for(j=L->n;j>=i;j--)    //在第i个位置中插入数
          {
               L->num[j]=L->num[j-1];
          }

          L->num[i-1]=x; //注意 这里的i为逻辑位序
             
           L->n++;


}

void  delete1(int i,List L)  //删掉第i个数  区分下标
{  int j;
   if(i<0||L->n<i) 
   {
       cout<<"error";
   }
     
   for(j=i;j<=L->n;j++)
       {  
            L->num[j-1]=L->num[j];
       }
    L->n--;
    
    return ;

   
}
 
void  deleteNUM(List L)  //   区分下标   删掉所有奇数号码元素 例如1  3  5  7  9对应下标为 0 2 4 4 6 8  但是每次删除一个数之后，
{                        //    原本奇数的下标又会往前移动一格，所以先标记 再对标记的数字删除
       //标志数组 当下标为奇数时
  
    
  for(int i=1;i<=L->n;i++)
    {
         
            delete1(i,L);
    }
   
}

int main()
{   
 L = makeEmpty();  
  insert(1,1,L);
  insert(2,2,L);
  insert(3,3,L);
  insert(4,4,L);
  insert(5,5,L);
  insert(6,6,L);
  insert(7,7,L);
  insert(8,8,L);
  insert(9,9,L);
  insert(10,10,L);
  insert(11,11,L);
  insert(12,12,L);
  insert(13,13,L);
  insert(14,14,L);
  for(int i=0;i<Length(L);i++)
		 cout<<" "<<L->num[i];
   deleteNUM(L);
  // delete1(1,L);
  cout<<endl;
  for(int i=0;i<Length(L);i++)
		 cout<<" "<<L->num[i];
      return 0;
}
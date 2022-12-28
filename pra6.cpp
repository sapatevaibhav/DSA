#include<iostream>
using namespace std;
class Ttree
{ public:
char Data;
int LFlag,RFlag;
Ttree *Left,*Right;
Ttree(char c='\0'){Data=c;LFlag=RFlag=1;Left=Right=NULL;}
};
class Threaded_Tree
{
Ttree *Head;
public:
Threaded_Tree(){Head=new Ttree; Head->Right=Head;}
void Create(char[]);
void PreTrav();
void InTrav();
};
void Threaded_Tree ::Create(char Estr[25])
{
Ttree *Stk[20], *Temp;
int Top=-1, I=0;
while(Estr[I]!='\0')
{
Ttree *Node=new Ttree(Estr[I]);
Node->Left=Node->Right=Head;
if(isalnum(Estr[I]));
else
{
Node->Right=Temp=Stk[Top--];
while(Temp->Left!=Head)
Temp=Temp->Left;
Temp->Left=Node;
Node->RFlag=0;
Node->Left=Temp=Stk[Top--];
while(Temp->Right!=Head)
Temp=Temp->Right;
Temp->Right=Node;
Node->LFlag=0;
}
Stk[++Top]=Node;
I++;
}
Head->Left=Stk[Top--]; }

void Threaded_Tree::InTrav()
{
Ttree *Temp=Head->Left;
do
{
while(!Temp->LFlag)
Temp=Temp->Left;
cout<<Temp->Data;
Temp=Temp->Right;
cout<<Temp->Data;
Temp=Temp->Right;
}while(Temp!=Head);
}
void Threaded_Tree::PreTrav()
{
Ttree *Temp=Head->Left;
do
{
while(!Temp->LFlag)
{
cout<<Temp->Data;
Temp=Temp->Left;
}
cout<<Temp->Data;
Temp=Temp->Right;
Temp=Temp->Right;
}while(Temp!=Head);
}
int main()
{
Threaded_Tree B;
char Estr[25];
cout<<"Enter Postfix Expression";
cin>>Estr;
B.Create(Estr);
cout<<" \n----------------------------------\n ";
cout<<" \nPreorder : \n";
B.PreTrav();
cout<<" \n----------------------------------\n ";
cout<<" \n Inorder : \n";
B.InTrav();
cout<<" \n----------------------------------\n ";
}
#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <process.h>

struct emp
{
	int eno;
	char name[20];
	emp *ptr;
};

class dynamic_queue
{
	emp *f, *r;
public:
	dynamic_queue()
	{
		f=NULL;
		r=NULL;
	}
	void indata();
	void deldata();
	void show();
};

void dynamic_queue:: indata()
{
	emp *tmp;
	tmp = new(emp);
	tmp->ptr=NULL;
	cout<<"\nEnter the details";
	cout<<"\nEno:";
	cin>>tmp->eno;
	cout<<"\nName";
	gets(tmp->name);
	if (r==NULL)
	{
		f=tmp;
		r=tmp;
	}
	else
	{
		r->ptr=tmp;
		r=tmp;	
	}
}
void dynamic_queue:: deldata()
{
	emp *tmp;
	if (r==NULL)
	{
		cout<<"\nQueue is empty";
		getch();
		exit(0);
	}
	else if (f==r)
	{
		tmp=f;
		f=NULL;
		r=NULL;
		delete(tmp);
	}
	else
	{
		tmp=f;
		f=f->ptr;
		delete(tmp);
	}
}
void dynamic_queue:: show()
{
	emp *tmp;
	if (r==NULL)
	{
		cout<<"\nQueue is empty";
		getch();
		exit(0);
	}
	else
	{	tmp=f;
		while(tmp!=NULL)
		{
			cout<<"\nShowing Details";
			cout<<"\nEno:"<<tmp->eno;
			cout<<"\nName:"<<tmp->name;
			cout<<endl;
			tmp=tmp->ptr;
		}
	}
}

void main()
{
	clrscr();
	dynamic_queue dq;
	int n;
	char ch='y';
	do
	{	clrscr();
		cout<<"\nEnter your choice:\n";
		cout<<"\n1.Add Data\n2.Delete Data\n3.Show data\n4.Exit\n";
		cin>>n;
		switch(n)
		{
			case 1:
			dq.indata();
			break;

			case 2:
			dq.deldata();
			break;

			case 3:
			dq.show();
			break;

			case 4:
			exit(0);
			break;

			default:
			cout<<"\nWrong Choice!";
			getch();
		}
		cout<<"\nWant to enter more?\n";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
}
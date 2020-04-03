#include<iostream>
#include<cstring>
using namespace std;
int temp = 0, mutex = 1;

int wait(int count)
{
      return(--count);   
} 
int signal(int count)
{
      return(++count);
}

void Leave(int x)
{
	wait(temp);
	cout<<"Vehicle "<<x<<" had left the intersection\n";
}
void check(int a,int b,int c)
{
	if((a+2==0&&a+3==2)||(a+2==1&&a+3== 2))
	{
		signal(mutex);
		cout<<"Vehicle "<<c<<" entered the intersection\n";
		Leave(c);
	}
}
int Enter(int x,int y,int z)
{
	if(x>2||x<0 || y>2 ||y<0)
	{
		cout<<"Invalid input ! try again \n";
	}
	else if((x==0&&y==0)||(x==1&&y==1)||(x==2&&y==2))
	{
		cout<<"U-Turn is not possible, Try again \n";
	}
	else if(x==1&&y==0)
	{
		cout<<"Vehicle "<<x<<" entered the intersection\n";
		Leave(z);
	}
	else if((x==0 && y==2) || (x==1 && y==2))
	{
		cout<<"Vehicle "<<x<<" entered the intersection\n";
		Leave(z);
		check(x,y,z);
	}
	return 1;
}

int main()
{
	int n,i,d,e=0;
	char indir[10],outdir[10];
	cout<<"Enter no; of vehicles : ";
	cin>>n;
	d=2*n;
	int a[d];
	for (i=0;i<n;i++,e+=2)
	{
		cout<<"Enter the direction in which car "<<i+1<<" enters : ";
		cin>>indir;
		cout<<"Enter the direction in which car "<<i+1<<" exits : ";
		cin>>outdir;
		if(indir=="north")
		{
			a[e]=0;
		}
		if(strcmp(indir,"east")==0)
		{
			a[e]=1;
		}
		if(strcmp(indir,"west")==0)
		{
			a[e]=2;
		}
		if(outdir=="north")
		{
			a[e+1]=0;
		}
		if(strcmp(outdir,"east")==0)
		{
			a[e+1]=1;
		}
		if(strcmp(outdir,"west")==0)
		{
			a[e+1]=2;
		}
}
cout<<""<<endl;
for(i=0,d=0;i<n;i++,d+=2)
{
	Enter(a[d],a[d+1],i+1);
}
return 1;
}

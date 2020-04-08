#include<string>
#include<iostream>
#include<semaphore.h>
#include<unistd.h>
#include<pthread.h>
#include<bits/stdc++.h>
using namespace std;
sem_t mutex;
void* Mutex1(void* arg)
{
	sem_wait(&mutex);
	cout<<"\nFirst Car Entered the intersection Sucessfully\n";
	sleep(4);
	cout<<"\nFirst car is Leaving the intersection Succesfully\n";
	sem_post(&mutex);	
}
void* Mutex2(void* arg)
{
	//wait
	sem_wait(&mutex);
	sleep(3);
	cout<<"\nSecond Car Entered the intersection Sucessfully\n";
	sleep(4);
	cout<<"\nSecond car is Leaving the intersection Succesfully\n";
	sem_post(&mutex);
	sleep(5);
}

void Enter(int a,int b)
{
	int n;
	
	if(a == b)
	{
		cout<<"\nCAR IS TAKING U TURN\n";
		switch(a)
		{
			case 1:cout<<"\nENTERING NORTH\n";break;
			case 2:cout<<"\nENTERING EAST\n";break;
			case 3:cout<<"\nENTERING SOUTH\n";break;
			case 4:cout<<"\nENTERING WEST\n";break;
			default:break;
		}
		cout<<"\nLEAVING INTERSECTION SAFELY \n"; 
		switch(b)
		{
			case 1:cout<<"\nEXITING FROM NORTH\n";break;
			case 2:cout<<"\nEXITING FROM EAST\n";break;
			case 3:cout<<"\nEXITING FROM SOUTH\n";break;
			case 4:cout<<"\nEXITING FROM WEST\n";break;
			default:break;
		}
	}
	else if(a==2 || a==1)
	{
		cout<<"IS There IS ANY OTHER CAR ENTERING..?\n";
		cout<<"Press 1 for yess\n";
		cout<<"Press 2 for no\n";
		cin>>n;
		if(n==2)
		{
			cout<<"\nCAR IS";
		cout<<"\nLEAVING INTERSECTION SAFELY \n"; 

	}
		else if(n==1)
		{	
			int a1,b1;
			 cout<<"Enter the details for Second Car\n\n";
			 cout<<"___________ SELECT THE IN DIRETION ____________\n\n\n";
             cout<<"Press 1 for North\n\nPress 2 for East\n\nPress 3 for South\n\nPress 4 for West\n\n";
             cin>>a1;
             cout<<"\n\n\n"; 
             cout<<"___________ SELECT THE OUT DIRETION ____________\n\n\n";
             cout<<"Press 1 for North\n\nPress 2 for East\n\nPress 3 for South\n\nPress 4 for West\n\n";
             cin>>b1;
             cout<<"\n\n\n\n";
			 sem_init(&mutex,0,1);
			 pthread_t t1,t2;
			 pthread_create(&t1,NULL,Mutex1,NULL);
			 sleep(2);
			 pthread_create(&t2,NULL,Mutex2,NULL);
			 pthread_join(t1,NULL);
			 pthread_join(t2,NULL);
			 sem_destroy(&mutex);
		}
		else
		{
			cout<<"Select the correct option";
		}
	}
}

int main()
{

 	
 int InDir, OutDir;
 while(1)
 {
 cout<<"___________ SELECT THE IN DIRETION ____________\n\n\n";
 cout<<"Press 1 for North\n\nPress 2 for East\n\nPress 3 for South\n\nPress 4 for West\n\n";
 cin>>InDir;
 if(InDir>4 ||InDir < 1)
 {
 	cout<<"Enter the correct option\n\n";
 	continue;
 }
 cout<<"\n\n\n"; 
 cout<<"___________ SELECT THE OUT DIRETION ____________\n\n\n";
 cout<<"Press 1 for North\n\nPress 2 for East\n\nPress 3 for South\n\nPress 4 for West\n\n";
 cin>>OutDir;
 if(OutDir> 4 || OutDir < 1)
 {
 	cout<<"Enter the correct option";
 	continue;
 } 
 Enter(InDir,OutDir);
}
}

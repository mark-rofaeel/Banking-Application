#include <iostream>
#include <fstream>
#include <string>
#include "SavingBankAccount.h"
#include "CertificateOfDeposit.h"
#include <cstring>
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#endif
#include "Client.h"
using namespace std;

char* FName = "Acc.txt";
int count=0;
Client c[10];

string IDGet(int d)
{

	int count=0;
	string s="FCI-";
	int n=count+1;
	int x=49;
	for(int i=1;i<11;i++)
	{
		if(i==d)
		{
			s+=x;
			return s;
		
		}
		else
		{
			x++;
		}
	}	
}
	void Save()
{
	string s1="FCI-";
	string s2="Type: ";
	ofstream OutData;
	OutData.open("Acc.txt",ios::app|ios::out);
	OutData<<s1<<c[count].Account->getID()<<"  "<< s2<<c[count].Account->gettype()<<"  "<<c[count].name<<"  "<<c[count].address<<"  "<<c[count].PhoneNumber<<"  ";
	OutData<<c[count].Account->getbal()<<endl;
	OutData.close();
}
void Update(string n,string add, string p, string t /*,string search*/,int x, int b)
{
	
		c[count].name=n;
		c[count].address=add;
		c[count].PhoneNumber=p;
		//c[count].Account->setID();
		c[count].Account->settype(t);
        //makingaccount(x,b);
        Save();
		
}

int Search(int d)
{
	string search;
	search=IDGet(d);//keda hygyb el id ka string
	ifstream InData;
	InData.open(FName);
	bool isFound=0; 
    while(!InData.eof())
    {
    	string temp = "";
		getline(InData,temp);
		//cout<<temp<<endl;
		string r = temp.substr(0, 5);
		string t = temp.substr(12, 16);
		string b1="Basic Balance";
		string s1="Saving  Bank ";
		string c1="Certificate  ";
		int x;
		if(r==search)
		{
			cout<<"Account ID:"<<r<<"   Acocunt Type:"<<t;
			break;
		}
		if (b1==t)
		{
			x=1;
		}
		else if(s1==t)
		{
			x=2;
		}
		else if(c1==t)
		{
			x=3;
		}
		string name=c[count].name;
		string add=c[count].address;
		string p=c[count].PhoneNumber;
		//Update(name,add, p, t, search, x  ,b);
	}
	InData.close();
}

void makingaccount(int x, int b)
	{
		if(x==1)
		{
			c[count].Account=new BankAccount(b);
			c[count].Account->setbal(b);
			c[count].Account->settype("Basic Balance");
		}
		else if(x==2)
		{
			c[count].Account=new SavingBankAccount(b);
			c[count].Account->setbal(b);
			c[count].Account->settype("Saving  Bank ");
		}
		else if(x==3)
		{
			c[count].Account=new CertificateOfDeposit(b);
			c[count].Account->setbal(b);
			c[count].Account->settype("Certificate  ");
		}
	}

void Show()
{
	ifstream InData(FName);
	cout<<InData.rdbuf();
	InData.close();	
}


void Create()
{
	if(count<999)
	{
		string n; string add; string p;
		cout<<"Please Enter Client Name =========> ";
		cin.ignore();
		getline (cin,n);
		c[count].name=n;
		cout<<endl;
		cout<<"Please Enter Client address =========> ";
		getline (cin,add);
		c[count].address=add;
		cout<<endl;
		cout<<"Please Enter Client Phone =========> ";
		//cin>>p;
		cin.ignore();
		getline (cin,p);
		c[count].PhoneNumber=p;
		cout<<endl;
		cout<<"What Type of Account Do You Like? (1) Basic (2) Saving (3) Certificate - Type 1 or 2 or 3 =========>";
		int x;
        cin>>x;
        cout<<"Please Enter the Starting Balance =========>";
        int b;
		cin>>b;
        makingaccount(x,b);
        c[count].Account->IDinc();
		cout<<"An account was created with ID FCI-"<<c[count].Account->getID()<<" and Starting Balance "<<c[count].Account->getbal(); 
		
        } 
	}

class BankingApplication
{
public:
    void display()
    {
        cout<<endl;
		cout<<"Welcome to FCI Banking Application"<<endl
		<<"1. Create a New Account"<<endl
		<<"2. List Clients and Accounts "<<endl
		<<"3. Withdraw Money"<<endl
		<<"4. Deposit Money "<<endl
		<<"Please Enter Choice =========> ";
        int m;
        cin>>m;
        switch (m)
        {
        case 1:
            	{
           	Create();
          	Save();
           	count++;
           	break;
				}
        case 2:{
			Show();
			break;
				}
		case 3:{
		int id;
        cout<<"Please Enter Account ID =========> FCI-";
        cin>>id;
        int x;
        x=Search(id);
        cout<<endl<<"Please Enter The Amount to Withdraw =========>";
        int b;
       	cin>>b;
       	int bal;
       	bal=c[count].Account->withdraw(b);
       	cout<<bal;
       	//c[count].Account->setbal(bal-b);
      	//cout<<c[count].Account->getbal();
		break;
		}	
		
        case 4:{
       	int id;
        cout<<"Please Enter Account ID =========> FCI-";
        cin>>id;
        int x;
        x=Search(id);
        cout<<endl<<"Please Enter The Amount to Deposit =========>";
        int b;
       	cin>>b;
       	int bal;
       	bal=c[count].Account->deposit(b);
       	cout<<bal;
       	//c[count].Account->setbal(bal+b);
       	//cout<<c[count].Account->getbal();
		break;
		}
        default:
		break;
        }
}
};

int main()
{
	BankingApplication a;
	for(;;)
	a.display();
}

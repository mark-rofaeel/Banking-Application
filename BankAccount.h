#include <iostream>
#include <string>
#ifndef BankAccount_h
#define BankAccount_h
using namespace std;
	class BankAccount
{
	protected:
		static int accountID;
		int balance;
		string type;
	
	public:
	BankAccount()
    {
       balance=0;
    }
    BankAccount(int b)
    {
        balance=b;
    }
    void settype(string t)
    {
    	type=t;
	}
	string gettype()
	{
		return type;
	}
    void IDinc()
    {
    	accountID++;
	}
    void setID(int id)
    {
        accountID=id;
    }
    void setbal(int b)
    {
        balance=b;
    }
    int getID()
    {
        return accountID;
    }
    int getbal()
    {
        return balance;
    }
	virtual int withdraw(int w) 
	{
		if (w<=balance)
		{
		balance-=w;
		cout<<"New Balance:"<<balance<<endl;
		}
		else cout<<"Sorry. This is more than what you can withdraw."<<endl;
	}
	virtual int deposit(int d)
	{
		balance+=d;
		cout<<"New Balance:"<<balance<<endl;
	}
};
 int BankAccount::accountID = 0;

#endif

#include <iostream>
#include "BankAccount.h"

#ifndef SavingBankAccount_h
#define SavingBankAccount_h
using namespace std;

	class SavingBankAccount : public BankAccount
{
	private:	
		 int minimumBalance;
	public:
		SavingBankAccount(int initial)
		{
		minimumBalance=1000;
		if(initial>=minimumBalance)
			{
			balance=initial;
			cout<<"Balance = "<<balance<<endl;
            cout<<"Minimum Balance = "<<minimumBalance<<endl;
			}
			else 
		      cout<<"Initial balance is lower than minimum balance"<<endl;
		}
		
		void setmin(int b)
    	{
       		if(b<1000)
       		cout<<"This amount is less than default value"<<endl;
       		else
       		minimumBalance=b;
   		}
    	int getmin()
    	{
        	return minimumBalance;
    	}
			
		int withdraw(int w) 
		{
		if (w>1000 && w<=balance)
		{
		balance-=w;
		cout<<"New Balance:"<<balance<<endl;
		}
		else 
		cout<<"Sorry. This is more than what you can withdraw."<<endl;
		}
		
		 int deposit(int d)
		{
			if (d>=100)
			{
				balance+=d;
				cout<<"New Balance:"<<balance<<endl;
			}
			else cout<<"Sorry. This is less than what you can deposit."<<endl;
		} 
		~SavingBankAccount() {}
};
#endif


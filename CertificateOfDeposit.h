#include <iostream>
#include <iostream>
#include "BankAccount.h"
#ifndef CertificateOfDeposit_h
#define CertificateOfDeposit_h
using namespace std;

	class CertificateOfDeposit : public BankAccount
{
	private:
		int minimumBalance;
		int withdrawPenaltyPercent;
	public:
		CertificateOfDeposit(int initial)
		{
			minimumBalance=20000;
			if(initial%minimumBalance==0 && initial>=minimumBalance)
				balance=initial;	
			else 
		   		cout<<"Balance not multiple of 20000"<<endl;	
		}
		
		void setmin(int b)
    	{
       		if(b<20000)
       		cout<<"This amount is less than default value"<<endl;
       		else
       		minimumBalance=b;
   		}
    	int getmin()
    	{
        	return minimumBalance;
    	}
    	void setpercent(int p)
    	{
       		withdrawPenaltyPercent=p;
   		}
    	int getpercent()
    	{
        	return withdrawPenaltyPercent;
    	}
    	
		 int withdraw(int x) 
		{
			int p;
			p=x*0.01;
			x+=p;
			if (x>balance)
			 cout<<"This is more than what you can withdraw."<<endl;
			else
			{
				this->balance-x;
			}
		}
		 int deposit(int d)
		{
			if(d%20000==0)
			this->balance+=d;
			else
			   {
			   cout<<"Balance not multiple of 20000"<<endl;	
			   }
		}
		~ CertificateOfDeposit() {}
};
#endif

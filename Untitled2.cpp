#include<iostream>
#include<string>
using namespace std;
class Account{
	public:
		char customer[20];
		int accNo;
		char accType[20];
		int balance;
		int deposit;
//		function protyping for open account
		void OpenAccount(int i);
		void Display();
		void Deposit();
		void Penalty();
		void Balance();
		int Search(int z);
		int Search(string z);
};



int Account::Search(int z)
{
	if(accNo==z)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Account::Search(string z)
{
	if(z=="saving")
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//function to impose penalty
void Account::Penalty(){

		if(balance<1000){
		balance-=500;
				}
	} 
//function defintion for open account
void Account::OpenAccount(int i)
{
	cout<<":::::::DETAILS FOR CUSTOMER ("<<i+1<<")"<<endl;
	cout<<"Enter customer name"<<endl;
	cin>>customer;
	cout<<"Enter Account Number"<<endl;
	cin>>accNo;
	cout<<"Enter Account Type"<<endl;
	cin>>accType;
		cout<<"Enter Account Balance"<<endl;
	cin>>balance;
cout<<":::::::::END::::::"<<endl;
	
};
//function to deposit

void Account::Deposit()
{
	cout<<"Enter amount to Deposit"<<endl;
	cin>>deposit;
	balance+=deposit;
	cout<<"Account topped with "<<deposit<< " amount. /n";
}
void Account::Balance()
{
	cout<<"Your balance is "<<balance<<"/n";
}

//function to Display

void Account::Display()

{
	cout<<"::::RESULTS::::"<<endl;
	cout<<"Customer Name:"<<customer<<endl;
	cout<<"Balance UGX:"<<balance<<endl;
}


class Saving:public Account
{
	public:
		
		void Withdraw()
		{
			int amt;
			cout<<"Enter the amount to withdraw"<<endl;
			cin>>amt;
			if(amt<balance)
			{
				cout<<"Insufficient balance /n"<<endl;
			}else
			{
				balance-=amt;
			}
		}
		
		//Compound interest
		int interest(){
		int interest_amt = .2*balance;
		balance +=interest_amt;
		return balance;
		
	}
//		void Compound();/
};

class Current:public Account
{
	
};

int main()
{
	int choice;
	int select;
	cout<<"Do you want to perform a transaction \n1.Yes\n0.No\n>";
	cin>>choice;
	while(choice==1)
	{
		
	
	do
	{
			Saving s[120];
			int i;
	
	cout<<"\n:::::WELCOME::::: "<<endl;
	cout<<"1::Open Account"<<endl<<"2::Deposit"<<endl<<"3::Withdraw"<<endl<<"4::Check Balance"<<endl<<"5::Display"<<endl;
	cin>>choice;
	switch(choice)
	{
		int number;
		case 1:
			{
				
				cout<<"Enter the no of customers you want to open for"<<endl;
				cin>>number;
				for(i=0;i<number;i++)
				{
					s[i].OpenAccount(i);
				}
			
				break;
			}
		case 2:
		{
			int accNo;
			cout<<"Enter the account number to deposit on"<<endl;
			cin>>accNo;
			for(i=0;i<number;i++)
			{
					if(s[i].Search(accNo))
					{
						s[i].Deposit();
					}
					
			}
			
		
			break;
		}
		case 3:
			{
				int accNo;
				string accType;
				cout<<"Enter the account number to withdraw from"<<endl;
					cin>>accNo;
					cout<<"Enter the account type to withdraw from"<<endl;
					cin>>accType;
					if(accType =="current"){
						cout<<"You cant withdraw from this account\n";
					}
					for(i=0;i<number;i++)
					{
							if(s[i].Search(accNo))
							{
								if(s[i].Search(accType))
								{
									s[i].Withdraw();
								}
								
							}
						
					}
			
				break;
			}
		case 4:
			{
				int accNo;
				string accType;
			cout<<"Enter the account number to display"<<endl;
				cin>>accNo;
			cout<<"Enter the account type"<<endl;
				cin>>accType;
				
				for(i=0;i<number;i++)
				{
						if(s[i].Search(accNo))
						{
							if(accType == "saving"){
								s[i].interest();
							}
							s[i].Penalty();
							s[i].Display();
							
						}
					
				}
			
				break;
			}
		case 5:
			{
				for(i=0;i<number;i++)
				{
					s[i].Display();
				}
			
				break;
			}
		default:
			{
				cout<<"Out of range";
				break;
			}
	}
}while(select==1);
}
	return 0;
}

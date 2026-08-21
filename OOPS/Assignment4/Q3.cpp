#include <iostream>
#include <string>

class account//min balance = 100Rs
{
    private:
    int accnum;
    std::string accname;
    double balance;

    public:
    account()
    {
        balance = 0;
    }

    void openacc()
    {
        std::cout<<"Enter your name:";
        std::getline(std::cin,accname);

        std:: cout<<"Enter account number:";
        std::cin>>accnum;

            while(balance<100)
            {   
                std::cout << "Balance below 100Rs. Minimum balance is 100Rs." << std::endl;
                std::cout << "Enter balance: ";
                std::cin >> balance;
            }
        
        std::cout<<"Account Opened Successfully"<<std::endl; 
    }

    void withdraw()
    {
        double temp = 0;
        do
        {
            std::cout << "Enter amount to be withdrawn (Enter 0 to exit): ";
            std::cin >> temp;
            
            if(temp == 0) return;

            if(temp < 0)
            {
                std::cout << "Do not enter a negative number.\n";
            }
            else if((balance - temp) < 100)
            {
                std::cout << "If withdrawn,balance will go below minimum,Try a smaller amount.\n";
                temp = -1;
            }
        } while(temp < 0);

    
        balance -= temp;
        std::cout<<"Withdrawn sucessfully"<<std::endl;
    }

    void deposit()
    {
        double temp;
        do
        {
            std::cout << "Enter amount to be Deposited ,Enter 0 to exit: ";
            std::cin >> temp;
            
            if(temp == 0) return;

            if(temp < 0)
            {
                std::cout << "Enter a positive number.\n";
            }
        } while(temp < 0);

        balance += temp;
        std::cout << "Money deposited successfully\n" << std::endl;
    }
    

    void display()
    {
        std::cout<<accname<<" account number:"<<accnum<<"\n Your balance is "<<balance<<"Rs"<<std::endl;
    }
};

int main()
{
    account a1;
    a1.openacc();
    a1.display();
    std::cout<<"Deposit"<<std::endl;
    a1.deposit();
    a1.display();
    std::cout<<"withdraw"<<std::endl;
    a1.withdraw();
    a1.display();
}
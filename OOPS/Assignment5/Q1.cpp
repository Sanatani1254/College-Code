#include <iostream>
#include <iomanip>

class account
{
    private:
        int accNo;
        std::string Name;
        double Balance;
        static int total;
        static int Nextaccount;
    
    public:

    account(std::string Name,double Balance)
    {
        this->Name = Name;
        this->Balance = Balance;
        this-> accNo = Nextaccount;
        Nextaccount++;
        total++;
    }
    void display()const
    {
        std::cout<<"Account No."<<accNo<<std::endl;
        std::cout<<"Name:"<<Name<<std::endl;
        std::cout<<std::fixed<<std::setprecision(2)<<"Balance:"<<Balance<<std::endl;
    }
    static void displayTotal() 
    {
        std::cout << "Total accounts created: " << total << std::endl;
    }
};

int account::total = 0;
int account::Nextaccount = 1;

int main()
{
    account::displayTotal();

    account acc1("Suryansh",1000000);
    account acc2("VINIT",20000000);
    account acc3("Uttu swami muttu swami veru gopal eiyeer",1000000);

    acc1.display();
    acc2.display();
    acc3.display();

    account::displayTotal();


}


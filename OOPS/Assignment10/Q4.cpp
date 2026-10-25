#include <iostream>

class payment
{
    protected:
    int amount;
    std::string paymentid;

    public:

    payment(int a, std::string p): amount(a),paymentid(p) {}

    virtual void processpayment() = 0;

    virtual void displaydetails(){std::cout<<"Payment ID:"<<paymentid<<"Amount:"<<amount<<std::endl;}

};

class creditcardpayment: public payment
{
    private:
    std::string cardnum;

    public:

    creditcardpayment(int a,std::string p,std::string c): payment(a,p), cardnum(c) {}

    void processpayment  () override
    {
        std::cout<<"payment processed"<<std::endl;
    }

    void displaydetails() override 
    {
        std::cout<<"paymentID:"<<paymentid<<"\nfrom creditcard no."<<"*********"<<cardnum<<"\namount:"<<amount<<std::endl;
    }
    

};

class upipayment: public payment
{
    private:
    std::string upiid;

    public:

    upipayment(int a,std::string p,std::string u): payment(a,p),upiid(u) {}

    void processpayment  () override
    {
        std::cout<<"payment processed"<<std::endl;
    }

    void displaydetails() override 
    {
        std::cout<<"paymentID:"<<paymentid<<"\nfrom UPIID"<<upiid<<"\namount:"<<amount<<std::endl;
    }
    
};

int main()
{
    creditcardpayment c(5000,"credit1","5643");
    upipayment u(5000,"upi1","5244545464654");

    payment* payments[2];
    payments[0] = &c;
    payments[1] = &u;

    for(int i = 0;i<2;i++)
    {
        payments[i]->displaydetails();
        payments[i]->processpayment();
    }
}
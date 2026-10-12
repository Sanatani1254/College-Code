#include <iostream>

class engine
{
    protected:
    int enginecapacity;
    std::string fuel;

    public:
    engine(int hp,std::string f): enginecapacity(hp),fuel(f) {}
};

class gps
{
    protected:
    std::string longitude;
    std::string latitude;

    public:
    gps(std::string lo,std::string la): longitude(lo),latitude(la) {}
};

class car :public engine,public gps
{
    protected:
    std::string name;
    std::string color;
    public:

    car(std::string n,std::string c,int hp,std::string fuel,std::string lo,std::string la)
    : name(n),color(c),engine(hp,fuel),gps(lo,la) {}

    void display()
    {
        std::cout<<name<<"|color:"<<color<<"|Engine:"<<enginecapacity<<fuel<<"|Location:"<<longitude<<","<<latitude<<std::endl;
    }
};

class electriccar : public car {
    private:
    double batteryCapacity;

    public:
    electriccar(std::string n, std::string c, int motorPower, std::string la, std::string lo, double batteryCap)
        : car(n, c, motorPower, "Electric", la, lo), batteryCapacity(batteryCap) {}

    double calculateRange() 
    {
        return batteryCapacity * 6.5; 
    }

    void electricdisplay() 
    {
        display(); 
        std::cout<<"Battery:"<<batteryCapacity<<" kWh"<<"Range:"<<calculateRange()<<" km\n";
    }
};

int main()
{
    class car c1("911 carera S","red",473,"petrol","45555W","756412.2S");
    c1.display();

    electriccar ec1("Tesla Model S", "Black", 1020, "37.7749 N", "122.4194 W", 100.0);
    ec1.electricdisplay();
}

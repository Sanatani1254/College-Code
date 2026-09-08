#include <iostream>
#include <cstring>

class String 
{
    private:
        char* str;

    public:
        String() 
        {
            this->str = nullptr;
        }

        ~String() {
            if (str != nullptr) {
                delete[] str;
                std::cout << "Memory released by destructor.\n";
            }
        }

        void input() {
            char tempBuffer[1000];
            std::cout << "Enter a string: ";
            std::cin.getline(tempBuffer, 1000);

            if (str != nullptr) {
                delete[] str; 
            }

            str = new char[strlen(tempBuffer) + 1];
            strcpy(str, tempBuffer); 
        }

        void display() const 
        {
            if (str != nullptr) {
                std::cout << "Stored String: " << str << std::endl;
            } else {
                std::cout << "String is empty." << std::endl;
            }
        }
};

int main() {
    String myText;
    myText.input();
    myText.display();
    return 0;
}

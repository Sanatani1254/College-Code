
#include <iostream>

template <class T>
class cqueue
{
    T arr[5];
    int front,rear,count;

public:
    cqueue()
    {
        front = 0;
        rear = -1;
        count = 0;
    }

    T dequeue()
    {
        if (count == 0)
        {
            std::cout << "Empty" << std::endl;
            return T{};
        }
        else
        {
            T value = arr[front];
            front = (front + 1) % 5;
            count--;
            return value;
        }
    }

    int enqueue(T value)
    {
        if (count == 5)
        {
            std::cout<<"Full"<<std::endl;
            return 0;
        }
        else
        {
            rear = (rear+1) % 5;
            arr[rear] = value;
            count++;
            return 1;
        }
    }

    

    void display()
    {
        if (count == 0)
        {
            std::cout << "empty" << std::endl;
            return;
        }


        for (int i = 0; i < count; i++)
            std::cout << arr[(front+i)%5] << " ";

        std::cout << std::endl;
    }
};

int main()
{
    cqueue<int> q;
    int x;

    for (int i = 1;i <= 5;i++)
    {
        x = q.enqueue(i*10);

        if (x == 0) std::cout << "ERROR" << std::endl;
    }

    q.display();

    std::cout<<"dequeue:"<<q.dequeue()<<std::endl;
    q.display();
    std::cout<<"enqueue(60)"<<std::endl;
    q.enqueue(60);
    q.display();

}

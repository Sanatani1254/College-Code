#include <iostream>

class arrqueue 
{
    private:
    int *arr;
    int capacity;
    int front;   
    int rear;    
    int count;   
 
    public:
    arrqueue(int size = 5):capacity(size),front(0),rear(-1),count(0) {arr = new int[capacity];}
    ~arrqueue() { delete[] arr; }
 
 
    bool isEmpty() const {return count == 0;}
    bool isFull() const {return count == capacity;}
    int size() const {return count;}
 
    void enqueue(int x) {
        if (isFull())
        {
            std::cout<<"OVERFLOW"<<std::endl;
            return;
        }
        rear = (rear+1)%capacity;
        arr[rear] = x;
        count++;
    }

    int peek()  {
        if (isEmpty())
        {
            std::cout<<"UNDERFLOW"<<std::endl;
            return -1;
        }
        return arr[front];
    }
 
    int dequeue() {
        if (isEmpty())
        {
            std::cout<<"UNDERFLOW"<<std::endl;
            return -1;
        }
            
        int val = arr[front];
        front = (front+1)%capacity;
        count--;
        return val;
    }
 
    
 
    void display()  
    {
        if (isEmpty()) 
        {
            std::cout<<"Queue is empty\n";
            return;
        }
        for (int i = 0; i < count; i++)
            {
                std::cout<<arr[(front+i) % capacity]<<" ";
            }
        std::cout<<std::endl;
    }
};

class linkedqueue 
{
    private:
    struct Node 
    {
        int data;
        Node *next;
        Node(int d) :data(d),next(nullptr) {}
    };
    Node *front;
    Node *rear;
    int count;
 
    public:
    linkedqueue() :front(nullptr),rear(nullptr),count(0) {}
 
    ~linkedqueue() {
        while (!isEmpty())
            dequeue();
    }
 
    linkedqueue(const linkedqueue &) = delete;
    linkedqueue &operator=(const linkedqueue &) = delete;
 
    bool isEmpty() { return front == nullptr; }
    int size() { return count; }
 
    void enqueue(int x) 
    {
        Node *newNode = new Node(x);
        if (rear == nullptr) front = rear = newNode;
        else 
        {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }
 
    int dequeue() 
    {
        if (isEmpty())
        {
            std::cout<<"UNDERFLOW"<<std::endl;
            return -1;
        }
        Node *temp = front;
        int val = temp->data;
        front = front->next;
        if (front==nullptr) rear = nullptr;
        delete temp;
        count--;
        return val;
    }
 
    int peek() 
    {
        if (isEmpty())
        {
            std::cout<<"UNDERFLOW"<<std::endl;
            return -1;
        }
        return front->data;
    }
 
    void display()  
    {
        if (isEmpty()) 
        {
            std::cout<<"Queue is empty\n";
            return;
        }
        for (Node *t = front; t != nullptr; t = t->next)
            {
                std::cout<<t->data<<" ";
            }
        std::cout<<"\n";
    }
};

int main()
{
    arrqueue a;
    linkedqueue b;
    a.enqueue(5);
    a.enqueue(6);

    b.enqueue(7);
    b.enqueue(8);

    std::cout<<"a:";
    a.display();
    std::cout<<"b:";
    b.display();

}
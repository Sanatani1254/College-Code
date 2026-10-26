#include <iostream>
#include <vector>
#include <algorithm>

class node 
{
    public:
    int val;
    node* next;
    node* prev;

    node(int v) : val(v),next(nullptr),prev(nullptr) {}
};

class deque 
{
    private:
    node* head;
    node* tail;

    public:
    deque() :head(nullptr),tail(nullptr) {}
    
    ~deque() {
        while (!empty()) 
        {
            pop_front();
        }
    }
    
    bool empty() 
    {
        if(head == nullptr) return 1;
        else return 0;
    }
    
    void push_back(int val) {
        node* newNode = new node(val);
        if (empty()) 
        {
            head = tail = newNode;
        } 
        else 
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void pop_back() {
        if (empty()) return;
        node* temp = tail;
        if (head == tail) 
        {
            head = tail = nullptr;
        } 
        else 
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }
    
    int back() 
    {
        return tail->val;
    }
    
    void pop_front() {
        if (empty()) return;

        node* temp = head;
        if (head == tail) 
        {
            head = nullptr;
            tail = nullptr;
        } 
        else 
        {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }
    
    int front() {return head->val;}
    
};

int largest(std::vector<int> &stress,int K) {
    deque maxdq;
    deque mindq;
    
    int left = 0;
    int max_passengers = 0;

    for (int right = 0; right < stress.size(); ++right) {
        while (!maxdq.empty() && (maxdq.back() < stress[right])) 
        {
            maxdq.pop_back();
        }
        maxdq.push_back(stress[right]);

        while (!mindq.empty() && (mindq.back() > stress[right])) 
        {
            mindq.pop_back();
        }
        mindq.push_back(stress[right]);

        while (!maxdq.empty() && !mindq.empty() && maxdq.front()-mindq.front()>K) 
        {
            if (maxdq.front() == stress[left]) 
            {
                maxdq.pop_front();
            }
            if (mindq.front() == stress[left]) 
            {
                mindq.pop_front();
            }
            left++;
        }

        max_passengers = std::max(max_passengers, right - left + 1);
    }

    return max_passengers;
}

int main() 
{
    std::vector<int> stress = {8,2,4,7};
    int K = 4;
    
    std::cout<<"Maximum passengers :"<<largest(stress,K)<<std::endl;

}
#include <iostream>
#include <vector>
#include <algorithm>

struct node 
{
    int data;
    node* next;
    node* prev;
    
    node(int val): data(val),next(nullptr),prev(nullptr) {}
};

class deque 
{
    private:
    node* head;
    node* tail;

    public:
    deque(): head(nullptr),tail(nullptr) {}
    
    ~deque() {
        while (!empty()) 
        {
            pop_front();
        }
    }
    
    bool empty() {
        return head == nullptr;
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
    
    void pop_back() 
    {
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
    
    int back() {return tail->data;}

    
    
    void pop_front() 
    {
        if (empty()) return;
        node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } 
        else 
        {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }
    
    int front() {return head->data;}
};

bool check( std::vector<int> &task,int k, std::vector<int> &worker, int pill, int str) {
    deque dq;
    int ptr = worker.size() - 1;
    
    for (int i = k - 1; i >= 0; --i) 
    {
        while (ptr >= (int)worker.size() - k && worker[ptr] + str >= task[i]) 
        {
            dq.push_back(worker[ptr]);
            ptr--;
        }
        
        if (dq.empty()) return false;
        
        if (dq.front() >= task[i]) dq.pop_front(); 
        else 
        {
            if (pill == 0) return false;
            pill--;
            dq.pop_back();
        }
    }
    
    return true;
}

int maxtask(std::vector<int> &task,std::vector<int> &worker,int str,int pill) {
    std::sort(task.begin(), task.end());
    std::sort(worker.begin(), worker.end());
    
    int left = 0;
    int right = std::min(task.size(), worker.size());
    int ans = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(task,mid,worker,pill,str)) 
        {
            ans = mid;
            left = mid + 1;
        } 
        else 
        {
            right = mid - 1;
        }
    }
    
    return ans;
}

int main() 
{
    std::vector<int> tasks = {3,6,1};
    std::vector<int> workers = {0,3,1};
    int pill = 1;
    int str = 1;
    std::cout<<maxtask(tasks,workers,str,pill)<<std::endl;
}
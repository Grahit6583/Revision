#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Stack
{
    private:
        int top = -1;
        int st[10];
    public:
        void push_st(int data)
        {
            if(top >= 10)
            {
                cout<<"Stack Overflow";
            }

            // cout<<"top->"<<top<<endl;
            top = top+1;
            st[top] = data;
            return ;
        }

        void pop_st()
        {
            if(top == -1)
            {
                cout<<"Stack Underflow";
                return;
            }

            top = top-1;
            return;
        }

        int peek()
        {
            if(top == -1)
            {
                cout<<"Stack is Empty";
                return -1;
            }
            return st[top];
        }

        int size_st()
        {
            return top+1;
        }
};

class Queue
{
    int *arr;
    int size;
    int currsize;
    int start,end;

    public:
        Queue(int s)
        {
            this->size = s;
            arr = new int[size];
            start = end = -1;
            currsize = 0;
        }

        void q_push(int data)
        {
            if(currsize == size)
            {
                cout<<"Queue is full"<<endl;
                return ;
            }

            if(currsize == 0)
            {
                start = end = 0;
            }
            else
            {
                end = (end + 1)%size;
            }
            arr[currsize] = data;
            currsize += 1;
        }

        int q_pop()
        {
            if(currsize == 0)
            {
                cout<<"Queue underflow"<<endl;
                return -1;
            }

            int ele = arr[start];
            if(currsize == 1)
            {
                start = end = -1;
            }
            else
            {
                start  =  (start+1)%size;
            }
            currsize -= 1;
            return ele;
        }

        int q_top()
        {
            if(currsize == 0)
            {
                cout<<"Queue is empty"<<endl;
                return -1;
            }

            return arr[start];
        }

        int q_size()
        {
            return currsize;
        }
};

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    // Stack s;

    // s.pop_st();
    // cout<<endl;
    // s.push_st(3);
    // s.push_st(4);
    // cout<<s.peek()<<endl;
    // cout<<s.size_st()<<endl;
    // s.pop_st();
    // cout<<s.peek()<<endl;
    // cout<<s.size_st()<<endl;
    // s.pop_st();
    // s.pop_st();

    Queue Q(5);
    cout<<Q.q_pop()<<endl;
    cout<<Q.q_top()<<endl;
    cout<<Q.q_size()<<endl;
    Q.q_push(3);
    Q.q_push(4);
    cout<<Q.q_pop()<<endl;
    cout<<Q.q_top()<<endl;
    cout<<Q.q_size()<<endl;
    return 0;
}
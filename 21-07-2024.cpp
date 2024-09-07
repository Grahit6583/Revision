//implementation of stack and queue using link list
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class node
{
    public:
        int data;
        node* next;

        node(int data)
        {
            this->data = data;
            next = NULL;
        }
};

class Stack
{
    private:
        node* top; 
        int size = 0;

    public:
        void st_push(int x)
        {
            node* temp = new node(x);
            temp->next = top;
            top = temp;
            size += 1; 
        }

        void st_pop()
        {
            if(size == 0)
            {
                cout<<"stack is empty"<<endl;
                return ;
            }
            node* temp = top;
            top = top->next;
            delete temp;
            size -= 1;
        }

        int st_top()
        {
            if(size == 0)
            {
                cout<<"stack is empty"<<endl;
                return 0;
            }
            return top->data;
        }

        int st_size()
        {
            return size;
        }
};

class Queue
{
    private:
        int size=0;
        node *start = NULL;
        node *end = NULL;

    public:
        void Q_push(int n)
        {
            node* temp = new node(n);
            if(start == NULL)
            {
                start = end = temp;
            }
            else
            {
                end->next = temp;
                end = temp;
            }
            size += 1;
        }

        void Q_pop()
        {
            if(start == NULL)
            {
                cout<<"Queue is empty"<<endl;
                return;
            }
            node* temp = start;
            start = start->next;
            delete temp;
            size -= 1;

            if(start == NULL)
            {
                end = NULL;
            }
        }

        int Q_size()
        {
            return size;
        }

        int Q_top()
        {
            if(start == NULL)
            {
                cout<<"Queue is empty"<<endl;
                return 0;
            }

            return start->data;
        }
};

main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    // Stack st;
    // st.st_push(4);
    // st.st_push(3);
    // st.st_push(2);
    // st.st_pop();
    // st.st_pop();
    // st.st_pop();
    // st.st_pop();

    // cout<<st.st_top()<<endl;
    // cout<<st.st_size()<<endl;

    Queue q;
    q.Q_push(4);
    q.Q_push(3);
    q.Q_push(1);
    q.Q_pop();
    q.Q_pop();
    q.Q_pop();
    cout<<q.Q_top()<<endl;
    q.Q_pop();
    cout<<q.Q_size()<<endl;

}
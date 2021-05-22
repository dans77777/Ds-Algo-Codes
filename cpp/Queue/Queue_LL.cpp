#include<iostream>
using namespace std;

template<typename T>
class Queue
{

    T *arr;
    int capacity=5;
    int size;
    int frontIndex;
    int nextIndex;

public:
    Queue()
    {
        arr= new T[capacity];
        size=0;
        frontIndex=-1;
        nextIndex=0;

    }


    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size==0;
    }

    void insert(T ele)
    {

        if(size == capacity)

        {

            T *newArr= new T[capacity*2];
            int j=0;
            for(int i=frontIndex; i<capacity; i++)
            {
                newArr[j]=arr[i];
                j++;
            }
            for(int i=0; i<frontIndex; i++)
            {
                newArr[j]=arr[i];
                j++;

            }

            frontIndex=0;
            nextIndex=capacity;
            capacity=2*capacity;

            delete []arr;
            arr= newArr;
            cout<<capacity<<endl;

        }
        arr[nextIndex]=ele;
        nextIndex=(nextIndex+1)%capacity;

        if(frontIndex==-1)
        {
            frontIndex=0;
        }
        size++;
    }

    void pop()
    {
        if(isEmpty())
        {
            cout<<"Q is empty cant delete"<<endl;
            return;
        }
        frontIndex=(frontIndex+1)%capacity;
        size--;
    }

    T getFront()
    {
        if(isEmpty())
        {
            return -1;
        }
        return arr[frontIndex];
    }
};
int main()
{
    Queue<int> q;
    q.insert(100);
    q.insert(200);
    q.insert(300);
    q.insert(400);
    q.insert(500);
    q.insert(600);
    q.insert(700);
     q.insert(400);
    q.insert(500);
    q.insert(600);
    q.insert(700);
    // q.insert(500);

    q.pop();

    cout<<q.getFront()<<endl;


    q.pop();
    // q.pop();
    cout<<q.getSize()<<endl;

    cout<<q.isEmpty()<<endl;

    cout<<q.getFront();

}


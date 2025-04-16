#include <iostream>
#define MAX 1024
typedef struct queue{
    int front;
    int rear;
    int data[MAX];
    queue():front(0),rear(0),data{0}{}
}QUEUE;

int dequeue(QUEUE& que)
{
        return que.data[que.rear--];
}

void enqueue(QUEUE& que,int x)
{
    que.data[++que.rear]=x;
}

bool empty(QUEUE que)
{
    return que.rear==0;
}

bool full(QUEUE que)
{
    return que .rear==MAX-1;
}







int main()
{
    QUEUE que;
    enqueue(que, 10);
    enqueue(que, 20);
    enqueue(que, 30);

    std::cout << "Dequeued: " << dequeue(que) << std::endl; // 输出 10
    std::cout << "Dequeued: " << dequeue(que) << std::endl; // 输出 20

    std::cout << "Is queue empty? " << (empty(que) ? "Yes" : "No") << std::endl; // 输出 No

    enqueue(que, 40);
    std::cout << "Is queue full? " << (full(que) ? "Yes" : "No") << std::endl; // 输出 No

    std::cout << "Dequeued: " << dequeue(que) << std::endl; // 输出 30
    std::cout << "Dequeued: " << dequeue(que) << std::endl; // 输出 40

    std::cout << "Is queue empty? " << (empty(que) ? "Yes" : "No") << std::endl; // 输出 Yes

    return 0;

}

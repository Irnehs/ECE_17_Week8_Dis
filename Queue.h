#ifndef WEEK8_QUEUE_H
#define WEEK8_QUEUE_H

template<class T>
class Queue {
private:
    struct Node {
        T element;
        Node* next;
        Node(T val) {
            element = val;
            next = nullptr;
        }
    };

    Node* front;
    Node* back;
    int numNodes;

public:
    Queue();
    ~Queue();
    void enqueue(T);
    void dequeue(T &);
    bool isEmpty();
    void clear();
};

//************************************************
// Constructor                                   *
//************************************************
template <class T>
Queue<T>::Queue() {
    front = nullptr;
    back = nullptr;
    numNodes = 0;
}

//************************************************
// Destructor                                    *
//************************************************
template <class T>
Queue<T>::~Queue() {
    clear();
}

//************************************************
// Function enqueue inserts the value in num     *
// at the rear of the queue.                     *
//************************************************
template <class T>
void Queue<T>::enqueue(T data) {
    Node* newNode = new Node(data);
    if(isEmpty()) {
        front = newNode;
        back = newNode;

        return;
    }
    else {
        back->next = newNode;
        back = newNode;
    }
    ++numNodes;
}

//************************************************
// Function dequeue removes the value at the     *
// front of the queue, and copies it into num.   *
//************************************************
template <class T>
void Queue<T>::dequeue(T& value) {
    Node* temp;
    if(isEmpty()) {
        return;
    }
    else {
        value = front->element;
        temp = front->next;
        delete front;
        front = temp;
        --numNodes;
    }
}

//************************************************
// Function isEmpty returns true if the queue    *
// is empty, and false otherwise.                *
//************************************************
template <class T>
bool Queue<T>::isEmpty() {
    return numNodes == 0;
}

//************************************************
// Function clear dequeues all the elements      *
// in the queue.                                 *
//************************************************
template <class T>
void Queue<T>::clear() {
    T t;
    while(!isEmpty()) {
        dequeue(t);
    }
}

#endif //WEEK8_QUEUE_H

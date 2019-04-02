#include <iostream>

struct Node {
    int data;
    Node* next_ptr;

    Node(int x) {
       this->data = x;
       this->next_ptr = nullptr;
    }
};


class Queue {

public:
    Node* front;
    Node* back;

    Queue() {
        this->front = this->back = nullptr;
    }

    void append(int x) {

        Node* n = new Node(x);

        // * if the queue is empty
        if (front == nullptr) {
            front = back = n;
            //std::cout << "==\n";
            return;
        }

        // * if the queue is not empty
        if (front != nullptr) {
            back->next_ptr = n;
            back = n;
            //std::cout << "!=\n";
            return;
        }
    } // end append


    int serve() {

        Node* temp = this->front;
        this->front = this->front->next_ptr;
        delete temp;
    }

    void traverse(void (*f)(int x)) {

        Node* n = this->front;
        while(n) {
            f(n->data);
            n = n->next_ptr;
        }
    }
};

void print(int x) {
    std::cout << x << std::endl;
}


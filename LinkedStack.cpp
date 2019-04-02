#include <iostream>


struct Node {
    int data;
    Node* next_ptr;

    Node(int x) {
        this->data = x;
        this->next_ptr = nullptr;
    }
};


class Stack {

    Node* top_ptr;
    int stack_size;

public:

    Stack(){
        this->top_ptr = nullptr;
        this->stack_size = 0;
    }

    bool isEmpty(){
        //return this->size() == 0;
    }

    int size() {
        // loved to iterate over linked structures
        // not optimal I know but funny
        int i = 0;

        Node* n = this->top_ptr;
        while(n) {
            i++;
            n = n->next_ptr;
        }

        return i;
    }

    void push(int x){

        // * make a new node
        Node* n = new Node(x);

        // * temp ptr for the current top
        Node* tail_nodes = this->top_ptr;

        // * update the current top to be the new one
        this->top_ptr = n;

        // * connect the new node with the tail
        n->next_ptr = tail_nodes;


    }

    void pop(){

        // * hold the top with a tmp ptr to delete it with
        Node* tmp = this->top_ptr;

        // * update the top ptr to the next node
        this->top_ptr = this->top_ptr->next_ptr;

        // * delete the tmp ptr
        delete tmp;

    }

    void traverse(void (*f)(int x)) {

        Node* n = this->top_ptr;
        while(n) {
            f(n->data);
            n = n->next_ptr;
        }
    }

    ~Stack() {
        while(this->top_ptr)
            this->pop();
    }

};

void print(int x) {
    std::cout << x << std::endl;
}


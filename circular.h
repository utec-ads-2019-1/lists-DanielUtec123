#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"

template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

    T front() {
            if(this->head){
                    return this->head->data;
            }

            throw out_of_range("lista sin elementos\n");
    }

    T back() {
            if(this->tail){
                    return this->tail->data;
            }

            throw out_of_range("lista sin elementos\n");
    }

    void push_front(T value) {
            Node<T>* A =new Node<T>{value, nullptr, nullptr};
            if(!empty()){

                    A->prev = this->tail;
                    A->next = this->head;
                    this->head->prev = A;
                    this->tail->next=A;
                    this->head =A;


            } else{
                    this->tail =A ;
                    this->head = A;
                    A->prev =A;
                    A->next =A;

            }



    }

    void push_back(T value) {
            Node<T>* A =new Node<T>{value, nullptr, nullptr};
            if(!empty()){

                    A->prev = this->tail;
                    A->next = this->head;
                    this->tail->next = A;
                    this->head->prev = A;
                    this->tail =A;


            } else{
                    this->tail =A ;
                    this->head = A;
                    A->prev =A;
                    A->next =A;

            }
    }

    void pop_front() {
            if(!empty()){
                    if(this->head==this->head->next){//si tiene 1 elemento
                            delete this->head;
                            this->head=this->tail= nullptr;
                    } else{//al menos 2 elementos
                            Node<T>* temp = this->head->next;
                            delete this->head;
                            this->head = temp;
                            this->tail->next = this->head;
                            this->head->prev = this->tail;
                    }


            }
    }

    void pop_back() {
            if(!empty()){
                    if(this->head==this->head->next){//si tiene 1 elemento
                            delete this->head;
                            this->head= nullptr;
                            this->tail= nullptr;
                    } else{//al menos 2 elementos
                            Node<T>* temp = this->tail->prev;
                            delete this->tail;
                            this->tail = temp;
                            this->tail->next = this->head;
                            this->head->prev = this->tail;
                    }


            }

    }

    T operator[](int index) {

            if(!empty()){

                    index = index%size();
                    int i = 0;
                    Node<T>* temp = this->head;
                    for(int i=0;i<index;i++){
                            temp = temp->next;

                    }
                    return temp->data;
                    //i = numero de elementos de la lista

            }
            throw out_of_range("lista sin elememtos ");
    }

    bool empty() {
            if(this->head){
                    return false;
            }
            return true;
    }

    int size() {
            if(!empty()) {


                    int i=1;
                    Node<T>* temp = this->head->next;
                    while (temp!=this->head){
                            i++;
                            temp = temp->next;
                    }
                    return i;

            }
            return 0;
    }

    void clear() {

            if(!empty()){

                    Node<T> *temp = this->head;

                    while (temp!=this->tail){
                            temp = this->head->next;
                            delete this->head;
                            this->head = temp;
                            temp = temp->next;

                    }
                    delete temp;

                    this->head = nullptr;
                    this->tail = nullptr;

            }
    }

    void sort() {

            if(!empty()){

                    Node<T>* i = this->head;

                    while (i->next!=this->head){

                            Node<T>* j= i->next;
                            while (j!=this->head){

                                    if(i->data>j->data){//switch i con j
                                            T temp = i->data;
                                            i->data = j->data;
                                            j->data = temp;
                                    }

                                    j= j->next;
                            }
                            i = i->next;
                    }


            }




    }

    void reverse() {
            if(!empty()){

                    Node<T> * left = this->head;
                    Node<T> * right = this->tail;


                    while (true){
                            T temp = left->data;
                            left->data = right->data;
                            right->data = temp;


                            if(left->next==right->prev or left->next==right){
                                    break;
                            }
                            left = left->next;
                            right = right->prev;

                    }



            }





    }

    string name() {
            return "Circular Linked List";
    }

    BidirectionalIterator<T> begin() {
            return BidirectionalIterator<T>(this->head);


    }

    BidirectionalIterator<T> end() {
            return BidirectionalIterator<T>(this->tail);
    }

    void merge(CircularLinkedList<T> list) {
            Node<T>* temp = list.head;

            this->push_back(temp->data);

            while (temp->next!=list.head ){
                    this->push_back(temp->data);
                    temp = temp ->next;
            }
    }
};

#endif
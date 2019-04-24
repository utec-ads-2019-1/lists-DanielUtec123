#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList() : List<T>() {}

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

            Node<T> *A = new Node<T>{value, nullptr, nullptr};
            if(!empty()){
                    this->head->prev = A;
                    A->next = this->head;
                    this->head = A;
            } else{
                    this->head = A;
                    this->tail = A;
            }

    }

    void push_back(T value) {
            Node<T> *A = new Node<T>{value, nullptr, nullptr};
            if(!empty()){
                    this->tail->next = A;
                    A->prev = this->tail;
                    this->tail = A;
            } else{
                    this->head = A;
                    this->tail = A;
            }
    }

    void pop_front() {
            if(!empty()){
                    Node<T>* temp = this->head->next;
                    delete this->head;
                    this->head = temp;
                    this->head->prev = nullptr;


            }
    }

    void pop_back() {
            if(!empty()){
                    Node<T>* temp = this->tail->prev;
                    delete this->tail;
                    this->tail = temp;
                    this->tail->next = nullptr;

            }
    }

    T operator[](int index) {
            if(this->head){
                    int i = 0;
                    Node<T>* temp = this->head;
                    if(index == 0){

                            return temp->data;
                    }

                    while(temp->next){
                            i++;
                            temp = temp->next;
                            if(i==index){
                                    return temp->data;
                            }
                    }
                    //i = numero de elementos de la lista

                    throw out_of_range("indice mayor al numero de elementos");

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
            if(this->head){
                    int i = 1;
                    Node<T>* temp = this->head;

                    while (temp->next){
                            temp = temp->next;
                            i++;

                    }
                    return i;

            }
            return 0;
    }

    void clear() {
            if(!empty()){

                    Node<T> *temp = this->head;

                    while (temp){
                            temp = this->head->next;
                            delete this->head;
                            this->head = temp;
                    }

                    this->head = nullptr;
                    this->tail = nullptr;

            }
    }

    void sort() {
            if(!empty()){

                    Node<T>* i = this->head;

                    while (i->next){

                            Node<T>* j= i->next;
                            while (j){

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

                    ForwardList<T> lista;
                    Node<T> *temp = this->head;
                    while (temp){
                            lista.push_front(temp->data);
                            temp =temp->next;
                    }

                    temp = this->head;
                    Node<T> *reverse = lista.head;

                    while(temp){

                            temp->data = reverse->data;

                            reverse =reverse->next;

                            temp = temp->next;
                    }

            }
    }

    string name() {
            return "Linked List";
    }

    BidirectionalIterator<T> begin() {
            return BidirectionalIterator<T>(this->head);
    }

    BidirectionalIterator<T> end() {
            return nullptr;
    }

    void merge(LinkedList<T> list) {
            Node<T>* temp = list.head;

            while (temp){
                    this->push_back(temp->data);
                    temp = temp ->next;
            }


    }
};

#endif
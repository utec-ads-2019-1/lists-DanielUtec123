#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"

template <typename T>
class ForwardList : public List<T> {
    public:
        ForwardList() : List<T>() {}

        T front() {
            if(this->head){
                    return this->head->data;
            }

            throw out_of_range("number of elements");
        }

        T back() {

            if(this->tail){
                return this->tail->data;
            }

            throw out_of_range("number of elements");

        }

        void push_front(T value) {

            //añade un elemento al inicio de la lista
            Node<T>* A = new Node<T>;
            A->data = value;
            if(this->head){
                A->next = this->head;
                this->head = A;
            } else{
                A->next = nullptr;
                this->head = A;
                this->tail = A;

            }
        }

        void push_back(T value) {
            // añade un elemento al final de la lista
            Node<T>* A = new Node<T>;
            A->data = value;
            if(this->tail){
                A->next = nullptr;
                this->tail->next = A;
                this->tail = A;
            } else{
                this->head = A;
                this->tail = A;

            }
        }

        void pop_front() {
            //elimina el primer elemento

            //si hay al menos un elemento
            if(this->head){
                Node<T>* temp = this->head;
                this->head = temp->next;
                if(!(this->head)){
                   this->tail = nullptr;
                }
                delete temp;
            }

        }

        void pop_back() {
            // elimina el ultimo elemento
            //si hay al menos un elemento
            if(this->tail){
                Node<T>* temp = this->tail;

                if(this->head->next) {//si hay al menos 2  elementos
                    while (temp->next->next){
                        temp = temp->next;
                    }
                    //temp apunta al penultimo elemento
                    this->tail = temp;
                    temp = temp->next;
                    delete temp;
                    this->tail->next = nullptr;

                } else{ //si hay 1 elemento
                    delete this->head;
                    this->head = nullptr;
                    this->tail = nullptr;
                }

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

                throw out_of_range("index");

            }
            throw out_of_range("cero");

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
            // TODO
        }

        void sort() {
            // TODO
        }
    
        void reverse() {
            // TODO
        }

        string name() {
            return "Forward List";
        }

        ForwardIterator<T> begin() {
            // TODO
        }

	    ForwardIterator<T> end() {
            // TODO
        }

        void merge(ForwardList<T> list) {
            // TODO
        }
};

#endif
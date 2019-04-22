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

            throw out_of_range("lista sin elementos\n");
        }

        T back() {

            if(this->tail){
                return this->tail->data;
            }

            throw out_of_range("lista sin elementos\n");

        }

        void push_front(T value) {

            //añade un elemento al inicio de la lista
            Node<T>* A = new Node<T>{value, nullptr, nullptr};
            if(this->head){
                A->next = this->head;
                this->head = A;
            } else{

                this->head = A;
                this->tail = A;

            }
        }

        void push_back(T value) {
            // añade un elemento al final de la lista
            Node<T>* A = new Node<T>{value, nullptr, nullptr};

            if(this->tail){

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
                Node<T>* temp = this->head->next;
                delete this->head;
                this->head = temp;
            }


        }

        void pop_back() {
            // elimina el ultimo elemento
            //si hay al menos un elemento
            if(this->tail){
                Node<T>* temp = this->head;

                if(this->head->next) {//si hay al menos 2  elementos
                    while (temp->next->next){
                        temp = temp->next;
                    }
                    //temp apunta al penultimo elemento
                    this->tail = temp;
                    temp = temp->next;
                    this->tail->next = nullptr;
                    delete temp;

                } else{ //si hay 1 elemento
                    this->head = nullptr;
                    this->tail = nullptr;
                    delete temp;
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
            //bubble sort

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
            return "Forward List";
        }

        ForwardIterator<T> begin() {
            return ForwardIterator<T>(this->head);
        }

	    ForwardIterator<T> end() {
            return nullptr;
        }

        void merge(ForwardList<T> list) {

            Node<T>* temp = list.head;

            while (temp){
                this->push_back(temp->data);
                temp = temp ->next;
            }


        }
};

#endif
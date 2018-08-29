#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"
#include <stdexcept>

using namespace std;

template <typename T>
class List {
    private:
        Node<T>* start;
        int nodes;

    public:
        List()
        {
            start = NULL;
            nodes = 0;
        }

        T front()
        {
            return start->data; 
        }
        T back()
        {       
            if(!start)
            {
                throw out_of_range("Lista vacia");
            }     
            return start->prev->data;
        }
        void push_front(T value)
        {
            Node<T> *temp = new Node<T>;

            if(!start)
            {
                start =  new Node<T>;
                start->data = value;
                start->next = start;
                start->prev = start;
            }
            else
            {
                //Node<T> *temp = new Node<T>;
                temp->data = value;
                temp->next = start;
                temp->prev = start->prev;
                start->prev->next = temp;
                start->prev = temp;
                start =temp;
            }
            nodes++;
        }
        void push_back(T value)
        {
            Node<T> *temp = new Node<T>;
            if(!start)
            {
                start =  new Node<T>;
                start->data = value;
                start->next = start;
                start->prev = start;
            }
            else
            {
                //Node<T> *temp = new Node<T>;
                temp->data = value;
                temp->next = start;
                temp->prev = start->prev;
                start->prev->next = temp;
                start->prev = temp;
            }
            nodes++;
        }
        void pop_front()
        {

        }
        void pop_back()
        {

        }
        T get(int position)
        {
            if (position >= nodes || position < 0)
            {
                throw out_of_range("Lista");
            }
            Node <T> *temp = start;
            for (int i  = 0; i < nodes; i++)
            {
                if(i == position)
                    return temp -> data;
                temp = temp->next;
            }

        }
        void concat(List<T> &other);
        bool empty()
        {
            return start = nullptr;
        }
        int size()
        {
            return nodes;
        }
        void clear()
        {

        }

        Iterator<T> begin();
        Iterator<T> end();

        ~List(){}
};

#endif
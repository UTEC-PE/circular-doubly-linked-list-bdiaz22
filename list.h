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
            return start->data;  // Falta controlar el vacío como en el back
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
            Node<T> *temp = start;
            if(start == start->next)
            {
                start = nullptr;
                temp->killSelf();
            }
            else
            {

                start->prev->next = start-> next;
                start = start->next;
                start->prev = temp->prev;
                temp->killSelf();
                nodes--;
            }
        }
        void pop_back(
)        {
            Node<T> *temp = start->prev;
            if(nodes == 1)
            {
                start = nullptr;
                temp->killSelf();
            }
            else
            {
                temp->prev->next = start;
                start->prev = temp->prev;
                temp->killSelf();
                nodes--;
            }
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
            // Warning por return

        }
        void concat(List<T> &other)
        {
            if(!other.start)
            {
                if(!start)
                    throw "Ambas listas vacias";

                throw "Segunda lista vacia"; // Si la otra está vacía solo retorna la lista
            }
            else if(!start)
            {
                start = other.start;
            }
            else{
            Node<T> *tail = other.start->prev;
            start->prev->next = other.start;
            tail->next = start;
            other.start->prev = start->prev;
            start->prev = tail;
            nodes += other.nodes;
            }
        }
        bool empty()
        {
            return start == nullptr;
        }
        int size()
        {
            return nodes;
        }
        void clear()
        {
            Node<T> *temp= start->next;
            while(temp != start)
            {
                Node<T> *eliminable = temp;
                temp = temp->next;
                eliminable->killSelf();
            }
            start = nullptr;
            temp->killSelf();
            nodes = 0;
        }

        Iterator<T> begin()
        {
            if(!start)
                throw "Lista Vacia";
            else{
            Iterator<T> first(start);
            return first;
            }
        }
        Iterator<T> end()
        {
            if(!start)
                throw "Lista Vacia";
            else{
            Iterator<T> last(start->prev);
            return last;

            }
        }

        ~List(){} // No hay destructor
};

#endif
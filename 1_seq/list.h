#ifndef _LIST_H_
#define _LIST_H_

#include <cstdlib>
#include "list-def.h"
#include <iostream>

using namespace std;

// your answer

template<typename T>
inline iterator_l<T>::iterator_l() :
    ptr(0) {
}

template<typename T>
inline iterator_l<T>::iterator_l(const iterator_l<T>& it)
{
}

template<typename T>
inline iterator_l<T>::~iterator_l() { }

template<typename T>
inline T& iterator_l<T>::operator*() const
{
    return ptr->value;
}

template<typename T>
inline iterator_l<T> iterator_l<T>::operator++(int)
{
    iterator_l<T> iter; 
    iter.ptr = ptr; // Postfix Operator
    ptr = ptr->right;
    return iter;
}

template<typename T>
inline iterator_l<T> iterator_l<T>::operator+(int s)
{
    iterator_l<T> iter;
    return iter;
}

template<typename T>
inline iterator_l<T> iterator_l<T>::operator--()
{
    iterator_l<T> iter;
    return iter;
}

template<typename T>
inline iterator_l<T> iterator_l<T>::operator-(int s)
{
    iterator_l<T> iter;
    return iter;
}

template<typename T>
inline bool iterator_l<T>::operator!=(const iterator_l<T>& it) const
{
    if (it.ptr == ptr) {
        return false;
    }
    else {
        return true;
    }
}

template<typename T>
inline bool iterator_l<T>::operator==(const iterator_l<T>& it) const
{
    if (it.ptr == ptr) {
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
inline list_element<T>::list_element() :
left(0),
right(0),
value("") {
}

template<typename T>
inline list_t<T>::list_t() :
num_elements(0) {
    head = new list_element<T>;
    head->left = head;
}

template<typename T>
inline list_t<T>::list_t(const list_t<T>& v)
{
    num_elements = v.num_elements;
    head = new list_element<T>;
    head->left = head;
    head->value = v.head->value;

    list_element<T>* tmp = v.head->right;
    list_element<T>* ntmp = head;
    while (tmp->right != NULL) {
        list_element<T>* newElement = new list_element<T>;
        ntmp->right = newElement;
        newElement->value = tmp->value;
        tmp = tmp->right;
        ntmp = ntmp->right;
    }
    list_element<T>* newElement = new list_element<T>;
    ntmp->right = newElement;
    newElement->value = tmp->value;
}

template<typename T>
inline list_t<T>::~list_t() { num_elements = 0; free(head); }

template<typename T>
inline void list_t<T>::operator=(const list_t<T>& v)
{
    num_elements = v.num_elements;
    head->value = v.head->value;
    list_element<T>* tmp = v.head->right;
    list_element<T>* ntmp = head;
    while (tmp->right != NULL) {
        list_element<T>* newElement = new list_element<T>;
        ntmp->right = newElement;
        newElement->value = tmp->value;
        tmp = tmp->right;
        ntmp = ntmp->right;
    }
    list_element<T>* newElement = new list_element<T>;
    ntmp->right = newElement;
    newElement->value = tmp->value;
}

template<typename T>
inline iterator_l<T> list_t<T>::begin() const
{
    iterator_l<T> iter;
    iter.ptr = head;
    return iter;
}

template<typename T>
inline iterator_l<T> list_t<T>::end() const
{
    iterator_l<T> iter;
    iter.ptr = NULL;
    return iter;
}

template<typename T>
inline size_t list_t<T>::size() const
{
    return num_elements;
}

template<typename T>
inline bool list_t<T>::empty() const
{
    if (num_elements == 0) {
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
inline iterator_l<T> list_t<T>::insert(const iterator& pos, const T& d)
{
    num_elements++;
    list_element<T>* newElement = new list_element<T>;
    newElement->value = d;
    if (pos.ptr == head) {
        head->left = newElement;
        newElement->right = head;
        head = newElement;
        newElement->left = head;
    }
    else {
        pos.ptr->left->right = newElement;
        newElement->right = pos.ptr;
        pos.ptr->left = newElement;
    }
    return pos;
}

template<typename T>
inline iterator_l<T> list_t<T>::erase(const iterator& pos)
{
    num_elements--;
    if (pos.ptr == head) {
        pos.ptr->right->left = pos.ptr->right;
        head = pos.ptr->right;
    }
    else {
        pos.ptr->left->right = pos.ptr->right;
        pos.ptr->right->left = pos.ptr->left;
    }
    pos.ptr->left = NULL;
    pos.ptr->right = NULL;
    pos.ptr->value = "";

    return pos;
}

template<typename T>
inline void list_t<T>::push_back(const T& d)
{
    if (num_elements == 0) {
        head->value = d;
    }
    else {
        list_element<T>* newElement = new list_element<T>;
        newElement->value = d;
        list_element<T>* last = head;
        while (last->right != NULL) {
            last = last->right;
        }
        last->right = newElement;
        newElement->left = last;
    }
    num_elements++;
}

template<typename T>
inline void list_t<T>::pop_back()
{
    num_elements--;
    list_element<T>* deleteElement = head->right;
    while (deleteElement->right != NULL) {
        deleteElement = deleteElement->right;
    }
    deleteElement->left->right = NULL;
    deleteElement->left = NULL;
    deleteElement->value = "";
}

template<typename T>
inline void list_t<T>::push_front(const T& d)
{
    if (num_elements == 0) {
        head->value = d;
    }
    else {
        list_element<T>* newElement = new list_element<T>;
        head->left = newElement;
        newElement->right = head;
        head = newElement;
        newElement->left = head;
        newElement->value = d;
    }
    num_elements++;
}

template<typename T>
inline void list_t<T>::pop_front()
{
    num_elements--;
    list_element<T>* deleteElement = head;
    head->right->left = head->right;
    head = head->right;
    deleteElement->left = NULL;
    deleteElement->right = NULL;
    deleteElement->value = "";
}

template<typename T>
inline void list_t<T>::clear()
{
    num_elements = 0;
    while (head->right != NULL) {
        head = head->right;
        delete(head->left);
    }
    head->value = "";
}

template<typename T>
inline void list_t<T>::sort() // N^2 // merge sort is better
{
    T tmp;
    for (list_t<T>::iterator i = this->begin(); i != this->end(); i++) {
        for (list_t<T>::iterator j = (this->begin())++; j != this->end(); j++) {
            if ((*i) < (*j)) {
                    tmp = *i;
                    *i = *j;
                    *j = tmp;
            }
        }
    }
}

template<typename T>
inline void list_t<T>::merge(const list_t<T>& v)
{
    for (list_t<T>::iterator i = this->begin(); i != this->end(); i++) {
        cout << "*it    : " << *it << endl;
    }
    for (list_t<T>::iterator i = v.begin(); i != v.end(); i++) {
        cout << "*it    : " << *it << endl;
    }

}

#endif
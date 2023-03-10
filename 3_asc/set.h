#ifndef _SET_H_
#define _SET_H_

#include <cstdlib>
#include "set-def.h"

// your answer

template<typename T>
inline iterator_s<T>::iterator_s() :
    ptr(0) {
}

template<typename T>
inline iterator_s<T>::iterator_s(const iterator_s<T>& it)
{
}

template<typename T>
inline iterator_s<T>::~iterator_s() { }

template<typename T>
inline T& iterator_s<T>::operator*() const
{
    return ptr->value;
}

template<typename T>
inline iterator_s<T> iterator_s<T>::operator++(int)
{
    iterator_s<T> iter;
    iter.ptr = ptr; // Postfix Operator
    ptr = ptr->right;
    return iter;
}

template<typename T>
inline iterator_s<T> iterator_s<T>::operator+(int s)
{
    iterator_s<T> iter;
    return iter;
}

template<typename T>
inline iterator_s<T> iterator_s<T>::operator--()
{
    iterator_s<T> iter;
    return iter;
}

template<typename T>
inline iterator_s<T> iterator_s<T>::operator-(int s)
{
    iterator_s<T> iter;
    return iter;
}

template<typename T>
inline bool iterator_s<T>::operator!=(const iterator_s<T>& it) const
{
    if (it.ptr == ptr) {
        return false;
    }
    else {
        return true;
    }
}

template<typename T>
inline bool iterator_s<T>::operator==(const iterator_s<T>& it) const
{
    if (it.ptr == ptr) {
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
inline set_element<T>::set_element() :
    left(0),
    right(0),
    value("") {
}

template<typename T>
inline set_t<T>::set_t() :
    num_elements(0) {
    head = new set_element<T>;
    head->left = head;
}

template<typename T>
inline set_t<T>::set_t(const set_t<T>& v)
{
    num_elements = v.num_elements;
    head = new set_element<T>;
    head->left = head;
    head->value = v.head->value;

    set_element<T>* tmp = v.head->right;
    set_element<T>* ntmp = head;
    while (tmp->right != NULL) {
        set_element<T>* newElement = new set_element<T>;
        ntmp->right = newElement;
        newElement->value = tmp->value;
        tmp = tmp->right;
        ntmp = ntmp->right;
    }
    set_element<T>* newElement = new set_element<T>;
    ntmp->right = newElement;
    newElement->value = tmp->value;
}

template<typename T>
inline set_t<T>::~set_t() { num_elements = 0; free(head); }

template<typename T>
inline void set_t<T>::operator=(const set_t<T>& v)
{
    num_elements = v.num_elements;
    head->value = v.head->value;
    set_element<T>* tmp = v.head->right;
    set_element<T>* ntmp = head;
    while (tmp->right != NULL) {
        set_element<T>* newElement = new set_element<T>;
        ntmp->right = newElement;
        newElement->value = tmp->value;
        tmp = tmp->right;
        ntmp = ntmp->right;
    }
    set_element<T>* newElement = new set_element<T>;
    ntmp->right = newElement;
    newElement->value = tmp->value;
}

template<typename T>
inline iterator_s<T> set_t<T>::begin() const
{
    iterator_s<T> iter;
    iter.ptr = head;
    return iter;
}

template<typename T>
inline iterator_s<T> set_t<T>::end() const
{
    iterator_s<T> iter;
    iter.ptr = NULL;
    return iter;
}

template<typename T>
inline size_t set_t<T>::size() const
{
    return num_elements;
}

template<typename T>
inline bool set_t<T>::empty() const
{
    if (num_elements == 0) {
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
inline iterator_s<T> set_t<T>::insert(const iterator& pos, const T& d)
{
    num_elements++;
    set_element<T>* newElement = new set_element<T>;
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
inline iterator_s<T> set_t<T>::erase(const iterator& pos)
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
inline void set_t<T>::push_back(const T& d)
{
    if (num_elements == 0) {
        head->value = d;
    }
    else {
        set_element<T>* newElement = new set_element<T>;
        newElement->value = d;
        set_element<T>* last = head;
        while (last->right != NULL) {
            last = last->right;
        }
        last->right = newElement;
        newElement->left = last;
    }
    num_elements++;
}

template<typename T>
inline void set_t<T>::pop_back()
{
    num_elements--;
    set_element<T>* deleteElement = head->right;
    while (deleteElement->right != NULL) {
        deleteElement = deleteElement->right;
    }
    deleteElement->left->right = NULL;
    deleteElement->left = NULL;
    deleteElement->value = "";
}

template<typename T>
inline void set_t<T>::push_front(const T& d)
{
    if (num_elements == 0) {
        head->value = d;
    }
    else {
        set_element<T>* newElement = new set_element<T>;
        head->left = newElement;
        newElement->right = head;
        head = newElement;
        newElement->left = head;
        newElement->value = d;
    }
    num_elements++;
}

template<typename T>
inline void set_t<T>::pop_front()
{
    num_elements--;
    set_element<T>* deleteElement = head;
    head->right->left = head->right;
    head = head->right;
    deleteElement->left = NULL;
    deleteElement->right = NULL;
    deleteElement->value = "";
}

template<typename T>
inline void set_t<T>::clear()
{
    num_elements = 0;
    while (head->right != NULL) {
        head = head->right;
        delete(head->left);
    }
    head->value = "";
}

template<typename T>
inline void set_t<T>::sort() // N^2 // merge sort is better
{
    T tmp;
    for (set_t<T>::iterator i = this->begin(); i != this->end(); i++) {
        for (set_t<T>::iterator j = (this->begin())++; j != this->end(); j++) {
            if ((*i) < (*j)) {
                tmp = *i;
                *i = *j;
                *j = tmp;
            }
        }
    }
}

template<typename T>
inline void set_t<T>::merge(const set_t<T>& v)
{
    num_elements = num_elements + v.num_elements;
    set_t<T>* newList = new set_t<T>;
    set_element<T>* tmp = newList->head;
    set_element<T>* f = head;
    set_element<T>* s = v.head;

    T a = f->value;
    T b = s->value;
    while (!((f->right == NULL) && (s->right == NULL))) {
        if (a < b) {
            tmp->value = a;
            set_element<T>* newElement = new set_element<T>;
            tmp->right = newElement;
            newElement->left = tmp;
            tmp = tmp->right;
            if (f->right == NULL) {
                a = "MAX";
            }
            else {
                f = f->right;
                a = f->value;
            }
        }
        else if (a > b) {
            tmp->value = b;
            set_element<T>* newElement = new set_element<T>;
            tmp->right = newElement;
            newElement->left = tmp;
            tmp = tmp->right;
            if (s->right == NULL) {
                b = "MAX";
            }
            else {
                s = s->right;
                b = s->value;
            }
        }
        else {
            tmp->value = a;
            set_element<T>* newElement1 = new set_element<T>;
            tmp->right = newElement1;
            newElement1->left = tmp;
            tmp = tmp->right;
            if (f->right == NULL) {
                a = "MAX";
            }
            else {
                f = f->right;
                a = f->value;
            }

            tmp->value = b;
            set_element<T>* newElement2 = new set_element<T>;
            tmp->right = newElement2;
            newElement2->left = tmp;
            tmp = tmp->right;
            if (s->right == NULL) {
                b = "MAX";
            }
            else {
                s = s->right;
                b = s->value;
            }
        }
    }

    if (a != "MAX") {
        tmp->value = a;
    }

    if (b != "MAX") {
        tmp->value = b;
    }

    head = newList->head;
}

template<typename T>
inline void set_t<T>::reverse()
{
    set_element<T>* last = head->right;
    while (last->right != NULL) {
        last = last->right;
    }

    set_element<T>* start = head;
    size_t n = num_elements / 2;
    T tmp;
    for (size_t i = 0; i < n; i++)
    {
        tmp = start->value;
        start->value = last->value;
        last->value = tmp;

        start = start->right;
        last = last->left;
    }
}

template<typename T>
inline void set_t<T>::remove(const T& d)
{
    for (set_t<T>::iterator it = this->begin(); it != this->end(); it++) {
        if (*it == d) {
            if (it.ptr->right == NULL) {
                it.ptr->left->right = NULL;
            }
            else {
                it.ptr->left->right = it.ptr->right;
                it.ptr->right->left = it.ptr->left;
            }
        }
    }
}

template<typename T>
inline void set_t<T>::unique()
{
    set_element<T>* same = head;
    for (set_t<T>::iterator it = ((this->begin())++); it != this->end(); it++) {
        if (*it == same->value) {
            if (it.ptr->right == NULL) {
                same->right = it.ptr->right;
            }
            else {
                it.ptr->right->left = same;
                same->right = it.ptr->right;
            }
        }
        same = it.ptr;
    }
}

#endif
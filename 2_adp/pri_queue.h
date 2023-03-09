#ifndef _PRI_QUEUE_H_
#define _PRI_QUEUE_H_

#include <cstring>
#include <iostream>
#include "pri_queue-def.h"

using namespace std;

struct cmp{
    bool operator()(string a, string b){
        return a < b;
    };
};

template <typename T1, typename T2, typename T3>
inline priority_queue<T1,T2,T3>::priority_queue() :
    queue(0),
    queue_size(0) {
}

template <typename T1, typename T2, typename T3>
inline priority_queue<T1, T2, T3>::priority_queue(const priority_queue<T1, T2, T3>& v)
{
    queue_size = v.queue_size;
    queue = (T*)calloc(queue_size, sizeof(T));
    for (size_t i = 0; i < queue_size; i++)
    {
        queue[i] = v.queue[i];
    }
}

template <typename T1, typename T2, typename T3>
inline priority_queue<T1,T2,T3>::~priority_queue() { queue_size = 0; free(queue); }


template <typename T1, typename T2, typename T3>
size_t priority_queue<T1,T2,T3>::size() const
{
    return queue_size;
}

template <typename T1, typename T2, typename T3>
inline bool priority_queue<T1,T2,T3>::empty() const
{
    if (queue_size == 0) {
        return true;
    }
    else {
        return false;
    }
}

template <typename T1, typename T2, typename T3>
inline T& priority_queue<T1,T2,T3>::back() const
{
    return queue[queue_size - 1];
}

template <typename T1, typename T2, typename T3>
inline void priority_queue<T1,T2,T3>::push(const T& v)
{
    queue_size++;
    T* newqueue = (T*)calloc(queue_size, sizeof(T));
    for (size_t i = 0; i < (queue_size - 1); i++)
    {
        newqueue[i] = queue[i];
    }
    newqueue[queue_size - 1] = v;
    free(queue);
    queue = newqueue;
    newqueue = NULL;
}

template <typename T1, typename T2, typename T3>
inline void priority_queue<T1,T2,T3>::pop()
{
    if (queue_size >= 1) {
        queue_size--;
        T* newqueue = (T*)calloc(queue_size, sizeof(T));
        for (size_t i = 1; i <= (queue_size); i++)
        {
            newqueue[i - 1] = queue[i];
        }
        free(queue);
        queue = newqueue;
        newqueue = NULL;
    }
    else {
        throw "error!!!";
    }

}

#endif
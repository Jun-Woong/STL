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

template <typename T, typename V, typename F>
inline priority_queue<T, V, F>::priority_queue(){}

template <typename T, typename V, typename F>
inline priority_queue<T, V, F>::~priority_queue() {}

template <typename T, typename V, typename F>
size_t priority_queue<T, V, F>::size() const
{
    queue.push_back(v);
    cmp c;
    T tmp;
    for (size_t i = 0; i < queue.size(); i++) {
        for (size_t j = 1; j < queue.size(); j++) {
            if (c(queue[i], queue[j])) {
                tmp = queue[i];
                queue[i] = queue[j];
                queue[j] = tmp;
            }
        }
    }
}

template <typename T, typename V, typename F>
inline bool priority_queue<T, V, F>::empty() const
{
    if (queue.size() == 0) {
        return true;
    }
    else {
        return false;
    }
}

template <typename T, typename V, typename F>
inline T& priority_queue<T, V, F>::top() const
{
    return queue[0];
}

template <typename T, typename V, typename F>
inline void priority_queue<T, V, F>::push(const T& v)
{
    queue.push_back(v); // fix here tomorrow
}

template <typename T, typename V, typename F>
inline void priority_queue<T, V, F>::pop()
{
    queue.pop_front();
}

#endif
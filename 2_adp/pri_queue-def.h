#ifndef _PRI_QUEUE_DEF_H_
#define _PRI_QUEUE_DEF_H_

#include "vector.h"

struct cmp;

template <typename T, typename V, typename F>
class priority_queue {
public:
    priority_queue();
    priority_queue(const priority_queue<T, V, F>& v);
    ~priority_queue();

    size_t size() const;
    bool empty() const;
    T& top() const;
    void push(const T& v);
    void pop();

private:
    V queue; 
};

#endif

#ifndef _PRI_QUEUE_DEF_H_
#define _PRI_QUEUE_DEF_H_

#include "vector.h"

struct cmp;

template <typename T1, typename T2, typename T3>
class priority_queue {
public:
    priority_queue();
    priority_queue(const priority_queue<T1,T2,T3>& v);
    ~priority_queue();

    size_t size() const;
    bool empty() const;
    T& back() const;
    void push(const T& v);
    void pop();

private:
    T1* queue;
    size_t queue_size;
};

#endif

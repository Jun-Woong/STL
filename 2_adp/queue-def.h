#ifndef _QUEUE_DEF_H_
#define _QUEUE_DEF_H_

template <typename T>
class queue_t {
public:
    queue_t();
    queue_t(const queue_t<T>& v);
    ~queue_t();

    size_t size() const;
    bool empty() const;
    T& back() const;
    void push(const T& v);
    void pop();
    void swap(queue_t<T>& v);

private:
    T* array;
    size_t array_size;
};

#endif

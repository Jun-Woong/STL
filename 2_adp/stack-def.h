#ifndef _STACK_DEF_H_
#define _STACK_DEF_H_

template <typename T>
class stack_t {
public:
    stack_t();
    stack_t(const stack_t<T>& v);
    ~stack_t();

    size_t size() const;
    bool empty() const;
    T& top() const;
    void push(const T& v);
    void pop();
    void swap(stack_t<T>& v);

private:
    T* array;
    size_t array_size;
};

#endif

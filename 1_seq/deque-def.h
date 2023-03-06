#ifndef _ITER_DQ_
#define _ITER_DQ_

template <typename T> class deque_t;

template <typename T>
class iterator_t {
public:
    iterator_t();
    iterator_t(const iterator_t<T> &it);
    ~iterator_t();

    T& operator*() const;
    iterator_t<T> operator++(int);
    iterator_t<T> operator+(int s);
    iterator_t<T> operator--();
    iterator_t<T> operator-(int s);
    bool operator!=(const iterator_t<T> &it) const;
    bool operator==(const iterator_t<T> &it) const;

private:
    T *ptr;
    friend class deque_t<T>;
    friend class deque_t<T>;
    friend class deque_t<T>;
};

#endif



#ifndef _DEQUE_DEF_H_
#define _DEQUE_DEF_H_

template <typename T>
class deque_t {
public:
    deque_t();
    deque_t(const deque_t &v);
    ~deque_t();
    deque_t& operator=(const deque_t v);
    
    typedef iterator_t<T> iterator;

    iterator begin() const;
    iterator end() const;
    size_t size() const;
    bool empty() const;
    T& front() const;
    T& back() const;
    T& operator[](size_t s) const;
    iterator insert(const iterator &pos, const T &d);
    iterator erase(const iterator pos);
    void push_back(const T &d);
    void pop_back();
    void push_front(const T &d);
    void pop_front();
    void clear();

private:
    T *array;
    size_t num_elements;
};

#endif

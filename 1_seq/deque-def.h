#ifndef _ITER_DQ_
#define _ITER_DQ_

template <typename T> class deque_t;

template <typename T>
class iterator_dq {
public:
    iterator_dq();
    iterator_dq(const iterator_dq<T> &it);
    ~iterator_dq();

    T& operator*() const;
    iterator_dq<T> operator++(int);
    iterator_dq<T> operator+(int s);
    iterator_dq<T> operator--();
    iterator_dq<T> operator-(int s);
    bool operator!=(const iterator_dq<T> &it) const;
    bool operator==(const iterator_dq<T> &it) const;

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
    void operator=(const deque_t<T>& v);
    
    typedef iterator_dq<T> iterator;

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
    size_t num_elements; // chunk_size
};

#endif

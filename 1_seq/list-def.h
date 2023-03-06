#ifndef _ITER_
#define _ITER_

template <typename T>
class iterator_t {
public:
    iterator_t();
    iterator_t(const iterator_t<T> &it);
    ~iterator_t();

    T& operator*() const;
    iterator_t<T> operator++();
    iterator_t<T> operator++(int);
    iterator_t<T> operator--();
    iterator_t<T> operator--(int);
    bool operator!=(const iterator_t<T> &it) const;
    bool operator==(const iterator_t<T> &it) const;

private:
    T *ptr;
    friend class vector_t<T>;
    friend class deque_t<T>;
    friend class list_t<T>;
};

#endif



#ifndef _LIST_DEF_H_
#define _LIST_DEF_H_

template <typename T>
class list_element {
public:
    list_element();
    list_element* left;
    list_element* right;
    T value;
};

template <typename T>
class list_t {
public:
    list_t();
    list_t(const list_t &v);
    ~list_t();
    list_t& operator=(const list_t v);

    typedef iterator_t<T> iterator;

    iterator begin() const;
    iterator end() const;
    size_t size() const;
    bool empty() const;
    T& front() const;
    T& back() const;
    iterator insert(const iterator &pos, const T &d);
    iterator erase(const iterator pos);
    void push_back(const T &d);
    void pop_back();
    void push_front(const T &d);
    void pop_front();
    void clear();


private:
    class list_element<T> *array;
    size_t num_elements;
};

#endif

#ifndef _ITER_
#define _ITER_

template <typename T> class vector_t;

template <typename T>
class iterator_t {
public:
    iterator_t();
    iterator_t(const iterator_t<T> &it);
    ~iterator_t();

    T& operator*() const;
    iterator_t<T> operator++();
    iterator_t<T> operator+(int s);
    iterator_t<T> operator--();
    iterator_t<T> operator-(int s);
    bool operator!=(const iterator_t<T> &it) const;
    bool operator==(const iterator_t<T> &it) const;

private:
    T *ptr;
    friend class vector_t<T>;
    friend class vector_t<T>;
    friend class vector_t<T>;
};

#endif

#ifndef _VECTOR_DEF_H_
#define _VECTOR_DEF_H_

template <typename T>
class vector_t {
public:
    vector_t();
    vector_t(const vector_t &v);
    ~vector_t();
    vector_t& operator=(const vector_t v);

    typedef iterator_t<T> iterator;

    iterator begin() const;
    iterator end() const;
    size_t size() const;
    bool empty() const;
    size_t capacity() const;
    void reserve(size_t s);
    T& front() const;
    T& back() const;
    T& operator[](size_t s) const;
    iterator insert(const iterator &pos, const T &v);
    iterator erase(const iterator pos);
    void push_back(const T &v);
    void pop_back();
    void clear();

private:
    T *array;
    size_t array_size;
    size_t num_elements;
};

#endif

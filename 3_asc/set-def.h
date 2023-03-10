#ifndef _ITER_S_
#define _ITER_S_

template <typename T> class set_t;
template <typename T> class set_element;

template <typename T>
class iterator_s {
public:
    iterator_s();
    iterator_s(const iterator_s<T>& it);
    ~iterator_s();

    T& operator*() const;
    iterator_s<T> operator++(int);
    iterator_s<T> operator+(int s);
    iterator_s<T> operator--();
    iterator_s<T> operator-(int s);
    bool operator!=(const iterator_s<T>& it) const;
    bool operator==(const iterator_s<T>& it) const;

public:
    set_element<T>* ptr;
    friend class set_t<T>;
};

#endif

#ifndef _SET_DEF_H_
#define _SET_DEF_H_

template <typename T>
class set_element {
public:
    set_element();
    set_element<T>* left;
    set_element<T>* right;
    T value;
};

template <typename T>
class set_t {
public:
    set_t();
    set_t(const set_t<T>& v);
    ~set_t();
    void operator=(const set_t<T>& v);

    typedef iterator_s<T> iterator;

    iterator begin() const;
    iterator end() const;
    size_t size() const;
    bool empty() const;
    T& front() const;
    T& back() const;
    iterator insert(const iterator& pos, const T& d);
    iterator erase(const iterator& pos);
    void push_back(const T& d);
    void pop_back();
    void push_front(const T& d);
    void pop_front();
    void clear();
    void sort();
    void merge(const set_t<T>& v);
    void reverse();
    void remove(const T& d);
    void unique();

private:
    class set_element<T>* head;
    size_t num_elements;
};

#endif

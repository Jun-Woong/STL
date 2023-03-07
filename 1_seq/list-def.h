#ifndef _ITER_L_
#define _ITER_L_

template <typename T> class list_t;

template <typename T>
class iterator_l {
public:
    iterator_l();
    iterator_l(const iterator_l<T> &it);
    ~iterator_l();

    T& operator*() const;
    iterator_l<T> operator++(int);
    iterator_l<T> operator+(int s);
    iterator_l<T> operator--();
    iterator_l<T> operator-(int s);
    bool operator!=(const iterator_l<T> &it) const;
    bool operator==(const iterator_l<T> &it) const;

private:
    list_element<T>* ptr;
    friend class list_t<T>;
};

#endif



#ifndef _LIST_DEF_H_
#define _LIST_DEF_H_

template <typename T>
class list_element {
public:
    list_element();
    list_element<T>* left;
    list_element<T>* right;
    T value;
};

template <typename T>
class list_t {
public:
    list_t();
    list_t(const list_t<T> &v);
    ~list_t();
    list_t& operator=(const list_t v);

    typedef iterator_l<T> iterator;

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
    class list_element<T>* head;
    size_t num_elements;
};

#endif

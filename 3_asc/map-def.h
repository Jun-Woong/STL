#ifndef _ITER_M_
#define _ITER_M_

template <typename K, typename V> class map_t;
template <typename K, typename V> class map_element;

template <typename K, typename V>
class iterator_m {
public:
    iterator_m();
    iterator_m(const iterator_m<K, V>& it);
    ~iterator_m();

    K& operator*() const;
    iterator_m<K, V> operator++(int);
    iterator_m<K, V> operator++();
    iterator_m<K, V> operator+(int s);
    iterator_m<K, V> operator--();
    iterator_m<K, V> operator-(int s);
    bool operator!=(const iterator_m<K, V>& it) const;
    bool operator==(const iterator_m<K, V>& it) const;

public:
    map_element<K, V>* ptr;
    K first;
    V second;
    friend class map_t<K, V>;
};

#ifndef _MAP_DEF_H_
#define _MAP_DEF_H_

template <typename K, typename V>
class map_element {
public:
    map_element();
    map_element<K, V>* left;
    map_element<K, V>* right;
    K key;
    V value;

public:
    void operator=(const V d);
};

template <typename K, typename V>
class map_t {
public:
    map_t();
    ~map_t();
    void operator=(const map_t<K, V>& v);

    typedef iterator_m<K, V> iterator;

    map_element<K, V>& operator[](K s) const; // insert
    iterator begin() const;
    iterator end() const;
    size_t size() const;
    bool empty() const;
    void erase(const K& d);
    void erase(const iterator pos);
    iterator find(const K& d);
    void clear();
    void sort();

private:
    class map_element<K, V>* head;
    size_t num_elements;
};

#endif

#endif
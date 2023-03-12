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

    iterator_m<K, V> operator++(int);
    iterator_m<K, V> operator++();
    iterator_m<K, V> operator+(int s);
    iterator_m<K, V> operator--();
    iterator_m<K, V> operator-(int s);
    bool operator!=(const iterator_m<K, V>& it) const;
    bool operator==(const iterator_m<K, V>& it) const;
    K& first() const;
    V& second() const;

public:
    map_element<K, V>* ptr;
    friend class map_t<K, V>;
};

#endif

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
};

template <typename K, typename V>
class map_t {
public:
    map_t();
    ~map_t();
    void operator=(const map_t<K, V>& v);

    typedef iterator_m<K, V> iterator;

    V& operator[](K s); // insert
    iterator begin() const;
    iterator end() const;
    size_t size() const;
    bool empty() const;
    void erase(const K& d);
    void erase(iterator pos);
    iterator find(const K& d);
    void clear();
    void sort();

private:
    class map_element<K, V>* head;
    size_t num_elements;
};

#endif
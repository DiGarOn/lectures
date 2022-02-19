#include <iostream>
#include <iterator>

using namespace std;

/*
cвязный список - абстрактный тип данных, который можно представить следующей схемой 

элемент списка (Узел), в котором хранятся какие-то данные и указатель на следующий элемент списка



*/

template<typename T>
class LinkedList {
public:
    class ListIterator;
private:
    typedef ListIterator iterator;

    typedef size_t size_type;
    typedef T value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    class ListNode;
    size_type count;
    ListNode *head;
    ListNode *tail;
    void copy(const LinkedList &);

public: 
    LinkedList();//
    LinkedList(const LinkedList &);//
    ~LinkedList();//

    explicit LinkedList(size_type);//

    LinkedList& operator =(const LinkedList &);//

    //void assign(size_type, T);
    //void assign(Iter);

    //reference front();
    //const_reference front() const;
    //reference back();
    //const_reference back() const;

    //iterator begin();
    //iterator end();

    bool empty() const;//
    size_type size() const;//

    
    void clear();//
    //iterator insert(It, T);
    //iterator insert(It, size_type, T);
    //iterator insert(It, ItFrom, ItLa);

    //iterator erase(It);
    //iterator erase(ItFirst, ItLast);

    void pop_back();//
    void push_back(const T &);//
    void pop_front();//
    //void push_front(T);

    void resize(size_type);
    void swap(LinkedList &);
    friend LinkedList& operator =(const LinkedList &);
};

template<typename T>
class LinkedList<T>::ListNode {
    template<typename T>
    friend class LinkedList;

    template<typename T>
    friend class ListIterator;

    T value;
    ListNode * next;
public:
    ListNode();
    ListNode(const T&);
};

template<typename T>
LinkedList<T>::ListNode::ListNode(): value(), next(0){}

template<typename T>
LinkedList<T>::LinkedList():count(0), head(0), tail(0){}

template<typename T>
LinkedList<T>::ListNode(const T& val): value(val.value), next(val.next){}

template<typename T>
LinkedList<T>::~LinkedList(){}

template<typename T>
void LinkedList<T>::copy(const LinkedList & other){
    if(other.count) {
        ListNode *cur1 = new ListNode(other.head);
        ListNode *cur2 = other.head->next;
        head = cur1;

        for(count = 1; count < other.count; ++count) {
            cur1->next = new ListNode(cur2);
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        tail = cur1;
    }
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList & other):count(0), head(0), tail(0) {
    copy(other);
}

template<typename T>
LinkedList& LinkedList<T>::operator =(const LinkedList & other) {
    if(this != &other) copy(other);
    return *this;
}

template<typename T>
LinkedList<T>::LinkedList(size_type size): count(count), head(0), tail(0) {
    if(count) {
        ListNode * cur = new ListNode;
        head = cur;
        for(size_type i = 1; i < count; ++i) {
            cur->next = new ListNode;
            cur = cur->next;
        }
        tail = cur;
    }
}

template<typename T>
bool LinkedList<T>::empty() const {
    return count == 0;
}

template<typename T>
typename LinkedList::size_type LinkedList<T>::size() const {
    return count;
}

template<typename T>
void LinkedList<T>::clear() {
    while(count) pop_front();
    head = 0;
    tail = 0;
}

template<typename T>
void LinkedList<T>::pop_front() {
    Listnode *tmp = head;
    head = tmp->next;
    delete tmp;
    --count;
}

template<typename T>
void LinkedList<T>::pop_back() {
    ListNode *tmp = head;
    while(cur->next != tail) {
        cur = cur->next;
    }
    cur->next = 0;
    delete tail;
    tail = cur;
    --count;
}

template<typename T>
void LinkedList<T>::swap(LinkedList<T> & other) {
    ListNode * n = head;
    head = other.head;
    other.head = n;
    n = tail;
    tail = other.tail;
    other.tail = n;
    size_type c = count;
    count = other.count;
    other.count = c;
}

template<typename T>
void LinkedList<T>::resize(size_type size) {
    ListNode *cur;
    if(count == 0 && size > 0) {
        head = new ListNode;
        count = 1;
        cur = head;
        for(size_type i = count; i < size; ++i) {
            cur->next = new ListNode;
            cur = cur->next;
        }
        tail = cur;
    } else {
        if(size <= count) {
            if(size == 0) {
                clear();
                return;
            }
            cur = head;
            for(size_type i = 0; i < size-1; ++i) 
                cur = cur->next;
            tail = cur;
            cur = cur->next;
            tail->next = 0;
            ListNode *tmp;
            for(size_type i = size; i < count; ++i) {
                tmp = cur->next;
                delete cur;
                cur = tmp;
            }
        } else {
            cur = tail;
            for(size_type i = count; i < size; ++i) {
                cur->next = new ListNode;
                cur = cur->next;
            }
            tail = cur;
        }
    }
    count = size;
}

template<typename T>
void LinkedList<T>::push_back(const T & v) {
    tail->next = new ListNode(v);
    tail = tail->next;
    ++count;
}

template<typename T>
class LinkedList<T>::ListIterator {
    template<typename T>
    friend struct std::iterator_traits;

    typedef std::ptrdiff_t difference_type;
    typedef typename LinkedList<T>::value_type value_type;
    typedef typename LinkedList<T>::value_type* pointer;
    typedef typename LinkedList<T>::value_type& reference;
    typedef std::forward_iterator_tag iterator_category;

    typename LinkedList<T>::ListNode * node;

public:
    ListIterator(typename LinkedList<T>::listNode *n):node(n){}
    bool operator==(const ListIterator & other) const {
        return node == other.node;
    }

    typename LinkedList<T>::reference operator*() {
        return node->value;
    }

    typename LinkedList<T>::const_reference operator*() const {
        return node->value;
    }

    ListIterator operator++() {
        if(node) node = node->next;
        return *this;
    }
};

int main() {



    return 0;
}
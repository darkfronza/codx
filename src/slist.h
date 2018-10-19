#ifndef CODX_SLIST_H
#define CODX_SLIST_H

#include <cstddef>
#include <stdexcept>

namespace cx {

template <typename T>
struct SNode {
    T *data;
    SNode *next;

    SNode(T *node_data=nullptr, SNode *next_node=nullptr) : data{node_data}, next{next_node} {}
};

template <typename T>
class SList {
public:
    SList() : m_size{0}, m_list{nullptr} {}

    ~SList() {
        while (!empty()) {
            pop_front();
        }
    }

    void push_front(const T& element) {
        m_list = new SNode<T>(new T(element), m_list);
        ++m_size;
    }

    void push_back(const T& element) {
        if (empty()) {
            push_front(element);
        } else {
            SNode<T> *p = m_list;

            while (p->next) {
                p = p->next;
            }

            p->next = new SNode<T>(new T(element));
            ++m_size;
        }
    }

    std::size_t size() const {
        return m_size;
    }

    bool empty() const {
        return m_size == 0;
    }

    T& front() {
        if (empty()) {
            throw std::runtime_error("SList::front(): Empty list.");
        }

        return *(m_list->data);
    }

    T& back() {
        if (empty()) {
            throw std::runtime_error("SList::back(): Empty list.");
        }

        SNode<T> *p = m_list;
        SNode<T> *target = p;

        while (p->next) {
            target = p->next;
            p = target;
        }

        return *(target->data);
    }

    void pop_front() {
        if (empty()) {
            throw std::runtime_error("SList::pop_front(): Cannot pop from empty list.");
        }

        SNode<T> *p = m_list;
        m_list = m_list->next;

        delete p->data;
        delete p;

        --m_size;
    }

private:
    SNode<T> *m_list;
    std::size_t m_size;
};

}

#endif

/**
 * clist.h
 *
 * Circular Linked List implementation.
 *
 * Author: Diego Fronza
 * darkfronza@gmail.com
 */

#ifndef CODX_CIRCULAR_LIST_H
#define CODX_CIRCULAR_LIST_H

#include <cstddef>

namespace cx {

template <typename T>
struct CNode {
    T data;
    CNode *next;

    CNode(const T& data, CNode *next=nullptr) : data{data}, next{next} {}
};

template <typename T>
class CircularList {

public:
    CircularList() : m_cursor{nullptr}, m_size{0} {}

    ~CircularList() {
        while (!empty()) {
            remove();
        }
    }

    bool empty() const {
        return m_size == 0;
    }

    std::size_t size() const {
        return m_size;
    }

    const T& front() const {
        return m_cursor->next->data;
    }

    const T& back() const {
        return m_cursor->data;
    }

    void advance() {
        m_cursor = m_cursor->next;
    }

    void add(const T& element) {
        if (m_cursor == nullptr) {
            m_cursor = new CNode<T>(element);
            m_cursor->next = m_cursor;
        } else {
            CNode<T> *new_node = new CNode<T>(element, m_cursor->next);
            m_cursor->next = new_node;
        }

        ++m_size;
    }

    void remove() {
        CNode<T> *old = m_cursor->next;

        if (old == m_cursor) {
            m_cursor = nullptr;
        } else {
            m_cursor->next = old->next;
        }

        --m_size;
    }

private:
    CNode<T> *m_cursor;
    std::size_t m_size;
};

}

#endif

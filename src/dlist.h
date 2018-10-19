#ifndef CODX_DLIST_H
#define CODX_DLIST_H

#include <cstddef>
#include <stdexcept>

namespace cx {

template <typename T>
struct DNode {
    T data;
    DNode *prev;
    DNode *next;

    DNode(const T& data_=T(), DNode *prev_=nullptr, DNode *next_=nullptr) : data{data_}, prev{prev_}, next{next_} {}
};


template <typename T>
class DList {
public:
    DList() : m_head{new DNode<T>()}, m_tail{new DNode<T>(T(), m_head)}, m_size{0} {
        m_head->next = m_tail;
    }

    ~DList() {
        while (!empty()) {
            pop_front();
        }

        delete m_head;
        delete m_tail;
    }

    bool empty() const { return m_size == 0; }

    std::size_t size() const { return m_size; }

    void push_front(const T& element) {
        add_before(m_head->next, element);
    }

    void push_back(const T& element) {
        add_before(m_tail, element);
    }

    const T& front() const {
        if (empty()) {
            throw std::runtime_error("DList::front(): Empty list.");
        }

        return m_head->next->data;
    }

    const T& back() const {
        if (empty()) {
            throw std::runtime_error("DList::back(): Empty list.");
        }

        return m_tail->prev->data;
    }

    void pop_front() {
        if (empty()) {
            throw std::runtime_error("DList::pop_front(). Empty list.");
        }

        remove(m_head->next);
    }

    void pop_back() {
        if (empty()) {
            throw std::runtime_error("DList::pop_back(). Empty list.");
        }

        remove(m_tail->prev);
    }

private:
    void add_before(DNode<T> *node, const T& element) {
        DNode<T> *new_node = new DNode<T>(element, node->prev, node);
        node->prev->next = new_node;
        node->prev = new_node;
        ++m_size;
    }

    void remove(DNode<T> *target) {
        target->prev->next = target->next;
        target->next->prev = target->prev;

        delete target;

        --m_size;
    }

private:
    DNode<T> *m_head;
    DNode<T> *m_tail;
    std::size_t m_size;
};

}

#endif

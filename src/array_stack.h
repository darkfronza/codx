/**
 * array_stack.h
 *
 * Stack data structure implentation, with fixed array.
 * Efficient when size for input is predictable beforehand.
 *
 * Author: Diego Fronza
 * darkfronza@gmail.com
 */

#ifndef CODX_ARRAY_STACK_H
#define CODX_ARRAY_STACK_H

#include <cstddef>
#include <stdexcept>


namespace cx {

template <typename T>
class ArrayStack {
    enum { DEF_CAPACITY = 100 };

public:
    ArrayStack(std::size_t capacity=DEF_CAPACITY) : m_capacity{capacity}, m_top{-1}, m_buffer{nullptr} {
        if (capacity <= 0) {
            throw std::invalid_argument("Capacity must be greater than zero.");
        }

        m_buffer = new T[capacity];
    }

    ~ArrayStack() {
        delete [] m_buffer;
    }

    ArrayStack(const ArrayStack& rhs) : m_capacity{rhs.m_capacity}, m_top{rhs.m_top}, m_buffer{nullptr} {
        m_buffer = new T[m_capacity];

        std::copy(rhs.m_buffer, rhs.m_buffer + m_top, m_buffer);
    }

    ArrayStack& operator=(const ArrayStack& rhs) {
        if (*this == &rhs) {
            return *this;
        }

        if (m_capacity != rhs.m_capacity) {
            delete [] m_buffer;
            m_buffer = new T[rhs.m_capacity];
            m_capacity = rhs.m_capacity;
        }

        m_top = rhs.m_top;
        std::copy(rhs.m_buffer, rhs.m_buffer + m_top, m_buffer);

        return *this;
    }

    std::size_t size() const { return static_cast<std::size_t>(m_top + 1); }

    std::size_t capacity() const { return m_capacity; }

    bool empty() const { return m_top < 0; }

    const T& top() const {
        return m_buffer[m_top];
    }

    void push(const T& element) noexcept(false) {
        if ((m_top + 1) == m_capacity) {
            throw std::runtime_error("Stack is full.");
        }

        m_buffer[++m_top] = element;
    }

    void pop() noexcept(false) {
        if (m_top == -1) {
            throw std::runtime_error("Stack is empty");
        }

        --m_top;
    }

private:
    std::size_t m_capacity;
    int m_top;
    T *m_buffer;
};

}

#endif

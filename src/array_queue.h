/**
 * array_queue.h
 *
 * Queue data structure implentation, with fixed array.
 * Efficient when size for input is predictable beforehand.
 *
 * Author: Diego Fronza
 * darkfronza@gmail.com
 */

#ifndef CODX_ARRAY_QUEUE_H
#define CODX_ARRAY_QUEUE_H

#include <cstddef>
#include <stdexcept>

namespace cx {

template <typename T>
class ArrayQueue {
    enum { DEF_CAPACITY = 32 };
public:
    ArrayQueue(std::size_t capacity=DEF_CAPACITY) : m_front{0}, m_rear{0}, m_size{0}, m_capacity{capacity} {
        if (capacity == 0) {
            throw std::runtime_error("Capacity must be greater then zero.");
        }

        m_buffer = new T[capacity];
    }

    ~ArrayQueue() {
        delete [] m_buffer;
    }

    ArrayQueue(const ArrayQueue& rhs) :
        m_front{rhs.m_front},
        m_rear{rhs.m_rear},
        m_size{rhs.m_size},
        m_capacity(rhs.m_capacity)
    {
        m_buffer = new T[m_capacity];
        std::copy(rhs.m_buffer, rhs.m_buffer + m_capacity, m_buffer);
    }

    ArrayQueue& operator=(const ArrayQueue& rhs) {
        if (this == &rhs) {
            return *this;
        }

        if (m_capacity != rhs.m_capacity) {
            delete [] m_capacity;
            m_buffer = new T[rhs.m_capacity];
            m_capacity = rhs.m_capacity;
        }

        m_front = rhs.m_front;
        m_rear = rhs.m_rear;
        m_size = rhs.m_size;
        std::copy(rhs.m_buffer, rhs.m_buffer + m_capacity, m_buffer);

        return *this;
    }

    std::size_t size() const { return m_size; }

    const T& front() const {
        if (empty()) {
            throw std::runtime_error("Empty queue");
        }

        return m_buffer[m_front];
    }

    const T& back() const {
        if (empty()) {
            throw std::runtime_error("Empty queue.");
        }

        if (m_rear == 0) {
            return m_buffer[m_capacity - 1];
        } else {
            return m_buffer[m_rear - 1];
        }
    }

    void enqueue(const T& element) {
        if (m_size == m_capacity) {
            throw std::runtime_error("Queue is full.");
        }

        m_buffer[m_rear] = element;
        m_rear = (m_rear + 1) % m_capacity;
        ++m_size;
    }

    void dequeue() {
        if (empty()) {
            throw std::runtime_error("Queue is empty.");
        }

        m_front = (m_front + 1) % m_capacity;
        --m_size;
    }

    bool empty() const {
        return m_size == 0;
    }

private:
    std::size_t m_front;
    std::size_t m_rear;
    std::size_t m_size;
    std::size_t m_capacity;
    T *m_buffer;
};

}

#endif

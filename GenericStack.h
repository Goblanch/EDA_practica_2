#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

template<typename T>
class GenericStack {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value, Node* nextNode = nullptr)
        : data(value), next(nextNode) {}
    };

    Node* topNode;
    int count;

public:
    GenericStack() : topNode(nullptr), count(0) {}
    ~GenericStack() {
        clear();
    }

    void push(const T& value) {
        topNode = new Node(value, topNode);
        ++count;
    }
    void pop() {
        if (empty()) {
            throw std::out_of_range("La pila está vacía");
        }

        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        --count;
    }
    T& top() const {
        if (empty()) {
            throw std::out_of_range("La pila está vacía");
        }

        return topNode->data;
    }
    bool empty() const {
        return topNode == nullptr;
    }
    int size() const {
        return count;
    }
    void clear() {
        while (!empty()) {
            pop();
        }
    }

};

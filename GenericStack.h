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
    GenericStack(const GenericStack& other) : topNode(nullptr), count(0) {
        if (other.topNode == nullptr) return;

        // Primero copiamos a una pila auxiliar para conservar orden
        GenericStack<T> temp;
        Node* current = other.topNode;

        // Recorremos other de cima a base
        while (current != nullptr) {
            temp.push(current->data); // queda invertido
            current = current->next;
        }

        // Volvemos a invertir para dejar el mismo orden que other
        while (!temp.empty()) {
            push(temp.top());
            temp.pop();
        }
    }

    // Operador de asignación por copia (deep copy)
    GenericStack& operator=(const GenericStack& other) {
        if (this != &other) {
            clear();

            GenericStack<T> temp;
            Node* current = other.topNode;

            while (current != nullptr) {
                temp.push(current->data);
                current = current->next;
            }

            while (!temp.empty()) {
                push(temp.top());
                temp.pop();
            }
        }
        return *this;
    }
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

    void print() {
        if (empty()) {
            std::cout << "[Pila vacia]\n";
            return;
        }

        Node* current = topNode;
        std::cout << "Escaneando pila\n";
        std::cout << "=== Contenido de la pila (cima -> base) ===\n";

        while (current != nullptr) {
            current->data.mostrar();
            current = current->next;
        }

        std::cout << "=========================================\n";
    }

};

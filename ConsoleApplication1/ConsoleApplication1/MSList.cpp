#include "MSList.h"

template<typename T>
MSList<T>::MSList() : head(nullptr), tail(nullptr), size(0) {}

template<typename T>
MSList<T>::~MSList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
void MSList<T>::push_back(const T& data) {
    Node* newNode = new Node(data);
    if (tail == nullptr) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

template<typename T>
void MSList<T>::pop_back() {
    if (tail == nullptr) {
        return;
    }
    else if (head == tail) {
        delete tail;
        head = tail = nullptr;
    }
    else {
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }
    size--;
}

template<typename T>
int MSList<T>::getSize() const {
    return size;
}

template<typename T>
bool MSList<T>::empty() const {
    return size == 0;
}

template<typename T>
const T& MSList<T>::back() const {
    return tail->data;
}

// Explicit instantiation for supported types
template class MSList<int>;
template class MSList<float>;
template class MSList<double>;
// Add more types as needed

#pragma once

template<typename T>
class MSList {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    MSList();
    ~MSList();

    void push_back(const T& data);
    void pop_back();
    int getSize() const;
    bool empty() const;
    const T& back() const;
};


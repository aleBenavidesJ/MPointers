#ifndef MPOINTERGC_H
#define MPOINTERGC_H

#include <mutex>
#include <thread>
#include <chrono>
#include <iostream>

class MPointerBase {
public:
    virtual ~MPointerBase() = default;
};

struct Node {
    MPointerBase *pointer;
    Node* next;
    Node(MPointerBase* ptr) : pointer(ptr), next(nullptr) {}
};

template <typename T>
class MPointer;

class MPointerGC {
private:
    static MPointerGC* instance;
    std::mutex mtx;
    Node* head;
    std::thread gcThread;
    int interval;
    bool stopGC;
    int nextID;
    MPointerGC();

    void garbageCollector();

public:
    static MPointerGC* getInstance();
    int generateID();
    void initializeGC(int n);

    template <typename T>
    void addPointer(MPointer<T>* ptr) {
        std::lock_guard<std::mutex> lock(mtx);
        Node* newNode = new Node(ptr);
        newNode->next = head;
        head = newNode;
    }

    template <typename T>
    void deletePointer(MPointer<T>* ptr) {
        std::lock_guard<std::mutex> lock(mtx);
        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr && curr->pointer != ptr) {
            prev = curr;
            curr = curr->next;
        }
        if (curr != nullptr) {
            if (prev == nullptr) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            delete curr;
        }
    }

    ~MPointerGC();

    void addressInMemory();
};

#endif // MPOINTERGC_H
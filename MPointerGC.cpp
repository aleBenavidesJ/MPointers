#include "MPointerGC.h"

#include <iostream>

MPointerGC* MPointerGC::instance = nullptr;

MPointerGC::MPointerGC() : stopGC(false), nextID(0), head(nullptr), interval(10) {}

MPointerGC* MPointerGC::getInstance() {
    if (!instance) {
        instance = new MPointerGC();
    }
    return instance;
}

void MPointerGC::initializeGC(int n) {
    interval = n;
    stopGC = false;
    gcThread = std::thread(&MPointerGC::garbageCollector, this);
    gcThread.detach();
}

void MPointerGC::garbageCollector() {
    while (!stopGC) {
        std::this_thread::sleep_for(std::chrono::seconds(interval));

        std::lock_guard<std::mutex> lock(mtx);
        Node* current = head;
        std::cout << "basura basuraaa" << std::endl;
        while (current != nullptr) {
            if (current->pointer == nullptr) {
                std::cout << "Puntero nulo encontrado, omitiendo..." << std::endl;
            } else {
                std::cout << "Pointer at memory address: " << current->pointer << std::endl;
            }
            current = current->next;
        }
        std::cout << "doneee" << std::endl;
    }
}

int MPointerGC::generateID() {
    std::lock_guard<std::mutex> lock(mtx);
    return nextID++;
}

void MPointerGC::addressInMemory() {
    std::lock_guard<std::mutex> lock(mtx);
    Node* current = head;
    if (!current) {
        std::cout << "No pointers added" << std::endl;
        return;
    }
    while (current != nullptr) {
        std::cout << "Pointer at memory address: " << current->pointer << std::endl;
        current = current->next;
    }
}

MPointerGC::~MPointerGC() {
    stopGC = true;
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}
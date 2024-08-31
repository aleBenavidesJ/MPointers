#include "MPointerGC.h"

MPointerGC* MPointerGC::instance = nullptr;

MPointerGC::MPointerGC() : stopGC(false), nextID(0) {
    gcThread = std::thread(&MPointerGC::trashCan, this);
}

MPointerGC* MPointerGC::getInstance() {
    if (!instance) {
        instance = new MPointerGC();
    }
    return instance;
}

int MPointerGC::generateID() {
    std::lock_guard<std::mutex> lock(mtx);
    return nextID++;
}

void MPointerGC::trashCan() {
    while (!stopGC) {
        std::this_thread::sleep_for(std::chrono::seconds(10));
        std::lock_guard<std::mutex> lock(mtx);
        for (auto it = pointers.begin(); it != pointers.end();) {
            delete *it;
            it = pointers.erase(it);
        }
    }
}

MPointerGC::~MPointerGC() {
    stopGC = true;
    gcThread.join();
    for (auto ptr : pointers) {
        delete ptr;
    }
}
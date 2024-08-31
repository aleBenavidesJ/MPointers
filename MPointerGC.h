#ifndef MPOINTERGC_H
#define MPOINTERGC_H

#include <list>
#include <mutex>
#include <thread>

class MPointerBase {
public:
    virtual ~MPointerBase() = default;
};

template <typename T>
class MPointer;

class MPointerGC {
private:
    static MPointerGC* instance;
    std::mutex mtx;
    std::list<MPointerBase*> pointers;
    std::thread gcThread;
    bool stopGC;
    int nextID;
    MPointerGC();
    void trashCan();

public:
    static MPointerGC* getInstance();
    int generateID();

    template <typename T>
    void registerPointer(MPointer<T>* ptr) {
        std::lock_guard<std::mutex> lock(mtx);
        pointers.push_back(ptr);
    }

    template <typename T>
    void unregisterPointer(MPointer<T>* ptr) {
        std::lock_guard<std::mutex> lock(mtx);
        pointers.remove(ptr);
    }
    ~MPointerGC();
};

#endif // MPOINTERGC_H
#ifndef MPOINTER_H
#define MPOINTER_H

#include <iostream>
#include "MPointerGC.h"

template <typename T>
class MPointer : public MPointerBase {
private:
    T* ptr;
    int id;
    MPointer() : ptr(new T) {
        id = MPointerGC::getInstance()->generateID();
        MPointerGC::getInstance()->registerPointer(this);
    }

public:
    static MPointer<T> New() {
        return MPointer<T>();
    }

    T& operator*() {
        return *ptr;
    }

    T operator&() {
        return *ptr;
    }

    MPointer<T>& operator=(const MPointer<T>& other) {
        if (this != &other) {
            delete this->ptr;
            this->ptr = new T(*other.ptr);
            this->id = other.id;
        }
        return *this;
    }

    ~MPointer() {
        MPointerGC::getInstance()->unregisterPointer(this);
        delete ptr;
    }

    int getID() const {
        return id;
    }
};

#endif // MPOINTER_H
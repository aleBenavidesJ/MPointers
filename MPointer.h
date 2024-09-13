#ifndef MPOINTER_H
#define MPOINTER_H

#include <iostream>
#include "MPointerGC.h"

template <typename T>
class MPointer : public MPointerBase {
private:
    T* ptr;
    int id;
    int* refCount;
    MPointer(T* p) : ptr(p), refCount(new int(1)), id(MPointerGC::getInstance()->generateID()) {
        MPointerGC::getInstance()->addPointer(this);
    }

public:
    MPointer() : ptr(nullptr), refCount(new int(1)), id(MPointerGC::getInstance()->generateID()) {}
    MPointer(std::nullptr_t) : ptr(nullptr), refCount(new int(1)), id(MPointerGC::getInstance()->generateID()) {}

    static MPointer<T> New() {
        MPointer<T> newPtr;
        newPtr.ptr = new T();
        return newPtr;
    }

    T& operator*() { return *ptr; }

    T* operator->() { return ptr; }

    //MPointer(T* p) : ptr(p), refCount(new int(1)) {}

    MPointer(const MPointer<T>& other) : ptr(other.ptr), refCount(other.refCount), id(other.id) {
        (*refCount)++;
    }

    MPointer& operator=(const MPointer<T>& other) {
        if (this != &other) {
            --(*refCount);
            if (*refCount == 0) {
                delete ptr;
                delete refCount;
                MPointerGC::getInstance()->deletePointer(this);
            }
            ptr = other.ptr;
            refCount = other.refCount;
            id = other.id;
            ++(*refCount);
        }
        return *this;
    }

    template <typename U>
    MPointer<T>& operator=(const U& value) {
        static_assert(std::is_same<T, U>::value, "El tipo asignado no coincide con el tipo interno de MPointer");
        if (ptr) {
            *ptr = value;
        }
        return *this;
    }

    bool operator==(std::nullptr_t) const { return ptr == nullptr; }
    bool operator!=(std::nullptr_t) const { return ptr != nullptr; }
    bool operator==(const MPointer<T>& other) const { return *ptr == *other.ptr; }
    bool operator!=(const MPointer<T>& other) const { return ptr != other.ptr; }
    bool operator!() const { return ptr == nullptr; }
    bool operator<(const MPointer<T>& other) const { return *this->ptr < *other.ptr; }
    explicit operator bool() const { return ptr != nullptr; }

    friend std::ostream& operator<<(std::ostream& os, const MPointer<T>& mp) {
        if (mp.ptr != nullptr) {
            os << *(mp.ptr);
        } else {
            os << "null";
        }
        return os;
    }

    void printPtr() {
            std::cout << "ID: " << getID()
                      << ", Value: " << *this
                      << ", RefCount: " << getRefCount()
                      << ", Address: " << this
                      << std::endl;
    }

    ~MPointer() {
        if (ptr && --(*refCount) == 0) {
            delete ptr;
            delete refCount;
            MPointerGC::getInstance()->deletePointer(this);
            std::cout << "MPointer con ID: " << getID() << " ha sido destruido" << std::endl;
        }
    }

    int getID() const {
        return id;
    }

    int getRefCount() const {
        return *refCount;
    }
};

#endif // MPOINTER_H
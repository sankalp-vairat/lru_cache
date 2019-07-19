#ifndef LRU_OBJECT_H
#define LRU_OBJECT_H
#include <iostream>
using namespace std;

template <typename T, typename U>
class LRUObject {
    private:
        T object_;
        U id_;
    public:
        LRUObject() = default;
        LRUObject(U id, T object):id_(id), object_(object) {};

        T* getObject() {
            return &object_;
        }

        U getId() {
            return id_;
        }
};

#endif //LRU_OBJECT_H

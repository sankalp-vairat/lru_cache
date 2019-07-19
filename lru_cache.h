#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <iostream>
#include <mutex>
#include <list>
#include <unordered_map>

#include "lru_object.h"

using namespace std;

template <typename T, typename U>
class LRUCache {
    private:
        static LRUCache<T, U> *CACHE_INSTANCE;
        static std::mutex mtx;
        std::list<U> lru_queue_;
        std::unordered_map<U, LRUObject<T, U>> mp_;
        int size_;

        LRUCache<T, U>(int size) : size_(size) {};
        ~LRUCache<T, U>() = default;

        LRUCache<T, U>(const LRUCache<T, U>& cache) = delete;
        LRUCache<T, U>& operator=(LRUCache<T, U>& cache) = delete;

    public:
        static LRUCache<T, U>* getInstance(int size) {
            if(CACHE_INSTANCE == nullptr) {
                std::lock_guard<std::mutex> lock(mtx);
                if(CACHE_INSTANCE == nullptr) {
                    CACHE_INSTANCE = new LRUCache(size);
                }
            }
            return CACHE_INSTANCE;
        }

        void addToCache(const U& id, const T& obj);
        T* getFromCache(U& id);
        void printLRUCache();
};


template <typename T, typename U>
LRUCache<T, U> *LRUCache<T, U>::CACHE_INSTANCE;

template <typename T, typename U>
std::mutex LRUCache<T, U>::mtx;

#endif //LRU_CACHE_H

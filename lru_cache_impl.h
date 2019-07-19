#include "lru_cache.h"

template <typename T, typename U>
void LRUCache<T, U>::addToCache(const U& id, const T& obj) {

    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Adding to cache:" << id << std::endl;

    LRUObject<T, U> lr_obj(id, obj);
    LRUObject<T, U>& lr = lr_obj;
    if(lru_queue_.size() < size_ && mp_.find(id) == mp_.end()) {
        mp_.emplace(std::make_pair(id, LRUObject<T, U>(id, obj)));
        lru_queue_.push_front(id);
        return;
    }
    else if(lru_queue_.size() == size_) {
        if(mp_.find(id) == mp_.end()) {
            auto d_id = lru_queue_.back();
            lru_queue_.pop_back();
            lru_queue_.push_front(id);
            mp_.erase(d_id);
            mp_.emplace(std::make_pair(id, LRUObject<T, U>(id, obj)));
        }
        else {
            lru_queue_.remove(id);
            lru_queue_.push_front(id);
        }
    }
}

template <typename T,typename U>
T* LRUCache<T, U>::getFromCache(U &id) {
    std::lock_guard<std::mutex> lock(mtx);
    if(mp_.find(id) != mp_.end()) {
        lru_queue_.remove(id);
        lru_queue_.push_front(id);
        return (mp_[id].getObject());
    }
    else
        return (T*)nullptr;
}

template <typename T, typename U>
void LRUCache<T, U>::printLRUCache() {
    std::lock_guard<std::mutex> lock(mtx);
    for(auto element : lru_queue_) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

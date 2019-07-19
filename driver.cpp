#include "lru_cache_impl.h"
#include <thread>

void addToCache( LRUCache<int, int> *lru_cache ) {
    lru_cache->addToCache(1, 1);
    lru_cache->addToCache(2, 2);
    lru_cache->addToCache(3, 3);
    lru_cache->printLRUCache();
}

void addToCache1( LRUCache<int, int> *lru_cache ) {
    lru_cache->addToCache(4, 4);
    lru_cache->addToCache(5, 5);
    lru_cache->printLRUCache();
    lru_cache->addToCache(4, 4);
    lru_cache->printLRUCache();
}

void accessFromCache( LRUCache<int, int> *lru_cache ) {

    int c = 3;
    std::cout << "Accessing from the cache:" << std::endl;
    std::cout << *(lru_cache->getFromCache(c)) << std::endl;
    std::cout << "There is a hit" << std::endl;

    lru_cache->printLRUCache();

}

int main() {

    LRUCache<int, int> *lru_cache = LRUCache<int, int>::getInstance(3);

    std::thread first(addToCache, lru_cache);
    std::thread second(addToCache1, lru_cache);
    std::thread third(accessFromCache, lru_cache);

    first.join();
    second.join();
    third.join();
}

# lru_cache

Synchronized templated LRU Cache.

1.  The LRU Cache is itself a thread-safe singleton class.
2.  The API description is as follows:

    Access the LRU Cache singleton Object:
    
        static LRUCache<T, U>* getInstance(int size)

    Add to cache API: (The id should be unique and can be primitive data type, obj can be any type of object)
    
        void LRUCache<T, U>::addToCache(const U& id, const T& obj)
    
    Get from Cache API:
    
        T* LRUCache<T, U>::getFromCache(U &id)
    
    
    
For detailed usage refer driver.cpp

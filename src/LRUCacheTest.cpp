#include "LRUCache.h"

void RunLRUCacheTest() {
    PRINTF("");
    std::cout<<"\n---------------------------------------------------\
    ---------------------------------\n RunLRUCacheTest :::::::::::::::::\n";
    LRUCache* cache = new LRUCache( 2 /* capacity */ );
    cache->put(1, 1);
    cache->put(2, 2);
    std::cout<<cache->get(1)<<"\n";       // returns 1
    cache->put(3, 3);                     // evicts key 2
    std::cout<<cache->get(2)<<"\n";       // returns -1 (not found)
    cache->put(4, 4);                     // evicts key 1
    std::cout<<cache->get(1)<<"\n";       // returns -1 (not found)
    std::cout<<cache->get(3)<<"\n";       // returns 3
    std::cout<<cache->get(4)<<"\n";       // returns 4
}
void RunLRUCacheTest1() {
    PRINTF("");
    std::cout<<"\n-----------------------------------------------------\
    -------------------------------\n RunLRUCacheTest :::::::::::::::::\n";
    LRUCache* cache = new LRUCache( 3 /* capacity */ );
    cache->put(1, 1);
    cache->put(2, 2);
    std::cout<<cache->get(1)<<"\n";
    cache->put(3, 3);
    std::cout<<cache->get(2)<<"\n";
    cache->put(4, 4);
    std::cout<<cache->get(1)<<"\n";
    std::cout<<cache->get(3)<<"\n";
    std::cout<<cache->get(4)<<"\n";
}
void RunLRUCacheTest2() {
    PRINTF("");
    std::cout<<"\n------------------------------------------------------\
    ------------------------------\n RunLRUCacheTest :::::::::::::::::\n";
    LRUCache* cache = new LRUCache( 2 /* capacity */ );
    std::cout<<cache->get(2)<<"\n";
    cache->put(2, 6);
    std::cout<<cache->get(1)<<"\n";
    cache->put(1, 5);
    cache->put(1, 2);
    std::cout<<cache->get(1)<<"\n";
    std::cout<<cache->get(2)<<"\n";
}
void RunLRUCacheTestAll() {
    RunLRUCacheTest();
    RunLRUCacheTest1();
    RunLRUCacheTest2();
}

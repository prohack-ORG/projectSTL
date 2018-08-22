#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <iostream>
#include <map>
#include <utility>
#include "Logging.h"

using namespace std;

class DLLNode{ //Circular Double Link List
public:
    DLLNode(int init_key = -1, int init_value = -1, DLLNode* init_prev = nullptr, DLLNode* init_next = nullptr):
    key(init_key), value(init_value), prev(init_prev), next(init_next) {}
    ~DLLNode() {}
    std::pair<int,int> GetValue();
    void     PutValue(std::pair<int,int> node_data);
    void     PrintList(DLLNode* head);
    DLLNode* DeleteList(DLLNode* head);
    DLLNode* GetLastNode(DLLNode* head);
    DLLNode* AddNodeAtHead(DLLNode* head, std::pair<int,int> node_data);
    DLLNode* AddNodeAtHead(DLLNode* head, DLLNode* node_address);
    DLLNode* MoveLastNodeToHead(DLLNode* head);
    DLLNode* MoveNodeToHead(DLLNode* head, DLLNode* node_address);
private:
    int key;
    int value;
    DLLNode *prev;
    DLLNode *next;
};
class LRUCacheImpl{
public:
    LRUCacheImpl(int capacity, DLLNode* init_list = NULL) :
    cache_capacity(capacity), head_dll( init_list), lru_cache_container() {}
    ~LRUCacheImpl();
    int  Get(int key);
    void Put(int key, int value);
    int  GetCapacity() { return cache_capacity;}
private:
    int cache_capacity;
    DLLNode* head_dll;
    map<int, DLLNode*> lru_cache_container;
};
class LRUCache {
public:
    LRUCache(int capacity);
    int  get(int key);
    void put(int key, int value);
private:
    LRUCacheImpl* lru_cache;
};
#endif//end of LRUCACHE_H

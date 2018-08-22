#include "LRUCache.h"

LRUCacheImpl::~LRUCacheImpl() {
    head_dll = head_dll->DeleteList(head_dll);
    lru_cache_container.clear();
}

int LRUCacheImpl::Get(int key) {
#ifdef DEBUG_PRINT
    PRINTF(("key : " + TO_STR(key)).c_str());
#endif
    int result = -1;
    if(lru_cache_container.find(key) == lru_cache_container.end()) {
        return result;
    }
    DLLNode* node = lru_cache_container.find(key)->second;
    result = node->GetValue().second;
    head_dll = head_dll->MoveNodeToHead(head_dll, node);
#ifdef DEBUG_PRINT
    head_dll->PrintList(head_dll);
#endif
    return result;
}
void LRUCacheImpl::Put(int key, int value) {
#ifdef DEBUG_PRINT
    PRINTF(("key : " + TO_STR(key) + " value : " + TO_STR(value)).c_str());
#endif
    if(lru_cache_container.find(key) != lru_cache_container.end()) {
        DLLNode* existing_node = lru_cache_container.find(key)->second;
        lru_cache_container.erase(key);
        existing_node->PutValue(std::make_pair(key, value));
        head_dll = head_dll->MoveNodeToHead(head_dll, existing_node);
        lru_cache_container[key] = head_dll;
    } else {
        if(lru_cache_container.size() < GetCapacity()) {
            // Add Node at head of DLL
            if(!head_dll) {
                head_dll = new DLLNode(key, value);
                head_dll = head_dll->AddNodeAtHead(nullptr, head_dll);
            } else {
                head_dll = head_dll->AddNodeAtHead(head_dll, std::make_pair(key, value));
            }
        } else {
            // Find Address of Least recent used Node at tail of List
            // Update New value to the same address
            // MoveNodeToHead
            DLLNode* last_node_of_dll = head_dll->GetLastNode(head_dll);
            int curr_key = last_node_of_dll->GetValue().first;
            last_node_of_dll->PutValue(std::make_pair(key, value));
            head_dll = head_dll->MoveLastNodeToHead(head_dll);
            lru_cache_container.erase(curr_key);
        }
    }
    // Insert Node Address with key in Cache Container
    lru_cache_container[key] = head_dll;
#ifdef DEBUG_PRINT
    head_dll->PrintList(head_dll);
#endif
}
std::pair<int,int> DLLNode::GetValue() {
    return std::make_pair(key, value);
}
void DLLNode::PutValue(std::pair<int,int> node_data) {
    key   = node_data.first;
    value = node_data.second;
}
DLLNode* DLLNode::DeleteList(DLLNode* head) {
    DLLNode* curr = head;
    while (curr && curr->next != head) {
        DLLNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = nullptr;
    return head;
}
void DLLNode::PrintList(DLLNode* head) {
    DLLNode* curr = head;
    std::cout<<"CURR_TABLE :\t";
    while (curr) {
        std::cout<<curr->key<<"["<<curr->value<<"]    ";
        curr = curr->next;
        if (curr == head)
            break;
    }
    std::cout<<"\n";
}
DLLNode* DLLNode::GetLastNode(DLLNode* head) {
    DLLNode* last_node = nullptr;
    if (head != nullptr) {
        last_node = head->prev ? head->prev : nullptr;
    }
    return last_node;
}
DLLNode* DLLNode::AddNodeAtHead(DLLNode* head, std::pair<int,int> node_data) {
    return AddNodeAtHead(head, new DLLNode(node_data.first, node_data.second));
}
DLLNode* DLLNode::AddNodeAtHead(DLLNode* head, DLLNode* node_address) {
    DLLNode* new_node = node_address;
    if( head == nullptr) {
        head           = new_node;
        new_node->next = head;
        new_node->prev = head;
    } else {
        head->prev->next = new_node;
        new_node->prev   = head->prev;
        new_node->next   = head;
        head->prev       = new_node;
        head             = new_node;
    }
    return head;
}
DLLNode* DLLNode::MoveLastNodeToHead(DLLNode* head) {
    DLLNode* last_node = nullptr;
    if (head != nullptr) {
        last_node = head->prev ? head->prev : nullptr;
        head = last_node;
    }
    return head;
}
DLLNode* DLLNode::MoveNodeToHead(DLLNode* head, DLLNode* node_address) {
    if (!head) return nullptr;
    if (head == node_address) {
        head = node_address;
    } else if (head->prev == node_address) {
        head = MoveLastNodeToHead(head);
    } else {
        node_address->prev->next = node_address->next;
        node_address->next->prev = node_address->prev;
        head = AddNodeAtHead(head, node_address);
    }
    return head;
}
LRUCache::LRUCache(int capacity) {
    lru_cache = new LRUCacheImpl(capacity);
}
int LRUCache::get(int key) {
    return lru_cache->Get(key);
}
void LRUCache::put(int key, int value) {
    lru_cache->Put(key, value);
}

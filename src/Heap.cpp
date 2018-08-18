#include "Heap.h"
#include <iostream>
#include <string>
#ifdef DEBUG_PRINT
#define PRINTF(X) printf("\n%s %s", __func__, X);
#else
#define PRINTF(X)
#endif

void Heap::Insert(int val) {
    PRINTF("++++++");
    heap_container.push_back(val);
    int index = heap_container.size() - 1;
    while(index != 0) {
        index = GetParent(index);
        Heapify(index);
    }
    PRINTF("-----");
}

int Heap::GetTop() {
    PRINTF("++++++");
    if(capacity == 0) {
        PRINTF("Heap Container Is Empty");
        return -1;
    }
    PRINTF(("------ returning" + std::to_string(heap_container[0])).c_str());
    return heap_container[0];
}

void Heap::RemoveTop() {
    PRINTF("+++++");
    if(capacity == 0) {
        PRINTF("Heap Container Is Empty");
        return;
    }
    heap_container[0] = heap_container[capacity-1];
    heap_container.resize(capacity-1);
    capacity = heap_container.size();
    Heapify(0);
    PRINTF("-----\n");
}

void Heap::swap(int first, int last) {
    PRINTF((" " + std::to_string(heap_container[first]) + " , " + std::to_string(heap_container[last])).c_str());
    int temp = heap_container[last];
    heap_container[last] = heap_container[first];
    heap_container[first] = temp;
}

void Heap::Heapify(int index) {
    int i = index;
    int left  = GetLeftChild(index);
    int right = GetRightChild(index);
    if (left < capacity && heap_container[i] < heap_container[left]) {
        i = left;
    }
    if (right < capacity && heap_container[i] < heap_container[right]) {
        i = right;
    }
    
    if (i == index) {
        return;
    }
    swap(i, index);
    Heapify(i);
}

int Heap::GetParent(int child_index) {
    return child_index/2;
}

int Heap::GetLeftChild(int parent_index) {
    int index = parent_index*2 + 1;
    return index;
}

int Heap::GetRightChild(int parent_index) {
    int index = parent_index*2 + 2;
    return index;
}

void MyContainer::Add(int element) {
    heap_container.push_back(element);
}

void MyContainer::Sort() {
    PRINTF("+++++");
    capacity = heap_container.size();
    BuildHeap();
    int len = capacity;
    while (len) {
        //Print();
        swap(0,len-1);
        len--;
        capacity = len;
        Heapify(0);
    }
    PRINTF("-----\n");
}

void MyContainer::BuildHeap() {
    PRINTF("+++++");
    for(int i = capacity/2; i >= 0; --i) {
        Heapify(i);
    }
    PRINTF("-----\n");
}

void MyContainer::Print() {
    for(auto &v:heap_container) {
        std::cout<<" "<<v;
    }
    std::cout<<"\n";
}


#include "Heap.h"
#include <iostream>
#include <string>

#ifdef DEBUG_PRINT
#define PRINTF(X) printf("%s\t%s\n", __func__, X);
#else
#define PRINTF(X)
#endif
#define TO_STR(X) std::to_string(X)

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
    if(heap_container.size() == 0) {
        PRINTF("Heap Container Is Empty");
        return -1;
    }
    PRINTF(("------ returning" + std::to_string(heap_container[0])).c_str());
    return heap_container[0];
}
void Heap::RemoveTop() {
    PRINTF("+++++");
    if(heap_container.size() == 0) {
        PRINTF("Heap Container Is Empty");
        return;
    }
    int curr_len = heap_container.size();
    heap_container[0] = heap_container[curr_len-1];
    heap_container.resize(curr_len-1);
    Heapify(0);
    PRINTF("-----");
}
void Heap::swap(int first, int last) {
    PRINTF((" " + std::to_string(heap_container[first]) + " , " + std::to_string(heap_container[last])).c_str());
    int temp = heap_container[last];
    heap_container[last] = heap_container[first];
    heap_container[first] = temp;
}
void Heap::Heapify(int index) {
    Heapify(index, heap_container.size());
}
void Heap::Heapify(int index, int len) {
    int i = index;
    int left  = GetLeftChild(index);
    int right = GetRightChild(index);
    if (left < len && heap_container[i] < heap_container[left]) {
        i = left;
    }
    if (right < len && heap_container[i] < heap_container[right]) {
        i = right;
    }
    if (i == index) {
        return;
    }
    swap(i, index);
    Heapify(i, len);
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
void MyArray::Add(int element) {
    PRINTF(("+++++ \n\t" + std::to_string(element)).c_str());
    if(arr_len < heap_container.size()) {
        PRINTF("Can't Add More Element to Array until its resize!  Try Calling Resize() to add more element");
        return;
    }
    heap_container.push_back(element);
    PRINTF("------");
}
void MyArray::Resize(int new_len) {
    if(new_len < 0) {
        PRINTF("Invalid Size provided!!");
        return;
    }
    if(new_len == arr_len) {
        return;
    }
    arr_len = new_len;
    //TODO : can resize the contianer if shortening the contaner;
}
void MyArray::Sort() {
    PRINTF("+++++");
    int len = heap_container.size();
    BuildHeap(len);
    while (len) {
#ifdef DEBUG_PRINT
        Print();
#endif
        swap(0,len-1);
        len--;
        Heapify(0, len);
    }
    PRINTF("-----");
}
void MyArray::BuildHeap(int len) {
    PRINTF("+++++");
    for(int i = len/2; i >= 0; --i) {
        Heapify(i, len);
    }
    PRINTF("-----");
}
void MyArray::Print() {
    PRINTF("++++++ ");
    for(auto &v:heap_container) {
        std::cout<<" "<<v;
    }
    std::cout<<"\n";
}
int MyArray::GetAt(int index) {
    PRINTF(("\n[" + std::to_string(index) + "]").c_str());
    if (index >= heap_container.size()) {
        PRINTF("Invalid Index Provided!!!!");
        return -1;
    }
    PRINTF((std::to_string(heap_container[index])).c_str());
    return heap_container[index];
}

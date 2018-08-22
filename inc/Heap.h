#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <iostream>
#include <string>
#include "Logging.h"
//#define DEBUG_PRINT

#define MIN_HEAP 0
#define MAX_HEAP 1
template <class T, int heap_type = MAX_HEAP>
class Heap{
public:
    Heap() {
        heap_container.resize(0);
    }
    ~Heap() {
        heap_container.resize(0);
    }
    void Insert(T& val);
    void RemoveTop();
    T&   GetTop();
protected:
    void Heapify(int index);
    void Heapify(int index, int len);
    int  GetParentIndex(int child_index);
    int  GetLeftChildIndex(int parent_index);
    int  GetRightChildIndex(int parent_index);
    void swap(int first_index, int last_index);
    std::vector<T> heap_container;
};
template <class T>
class MyArray : public Heap<T, MAX_HEAP>{
public:
    MyArray() {}
    MyArray(int len = 0) : arr_len(len), Heap<T, MAX_HEAP>() {}
    ~MyArray() {}
    void Add(T& element);
    void Resize(int new_len);
    void Sort();
    void Print();
    T& GetAt(int index);
private:
    void BuildHeap(int len);
    int arr_len;
};
template <class T, int heap_type>
void Heap<T,heap_type>::Insert(T& val) {
    PRINTF("++++++");
    heap_container.push_back(val);
    int ind = heap_container.size() - 1;
    while(ind != 0) {
        ind = GetParentIndex(ind);
        Heapify(ind);
    }
    PRINTF("-----");
}
template <class T, int heap_type>
T& Heap<T,heap_type>::GetTop() {
    PRINTF("++++++");
    if(heap_container.size() == 0) {
        PRINTF("Heap Container Is Empty");
        //return;
    }
    PRINTF(("------ returning" + std::to_string(heap_container[0])).c_str());
    return heap_container[0];
}
template <class T, int heap_type>
void Heap<T,heap_type>::RemoveTop() {
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
template <class T, int heap_type>
void Heap<T,heap_type>::swap(int first, int last) {
    PRINTF((" " + TO_STR(heap_container[first]) + " , " + TO_STR(heap_container[last])).c_str());
    T temp = heap_container[last];
    heap_container[last] = heap_container[first];
    heap_container[first] = temp;
}
template <class T, int heap_type>
void Heap<T,heap_type>::Heapify(int index) {
    Heapify(index, heap_container.size());
}
template <class T, int heap_type>
void Heap<T,heap_type>::Heapify(int index, int len) {
    int i = index;
    int left  = GetLeftChildIndex(index);
    int right = GetRightChildIndex(index);
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
template <class T, int heap_type>
int Heap<T,heap_type>::GetParentIndex(int child_index) {
    return child_index/2;
}
template <class T, int heap_type>
int Heap<T,heap_type>::GetLeftChildIndex(int parent_index) {
    int index = parent_index*2 + 1;
    return index;
}
template <class T, int heap_type>
int Heap<T, heap_type>::GetRightChildIndex(int parent_index) {
    int index = parent_index*2 + 2;
    return index;
}
template <class T>
void MyArray<T>::Add(T& element) {
    PRINTF(("+++++ \n\t" + TO_STR(element)).c_str());
    if(arr_len < Heap<T>::heap_container.size()) {
        PRINTF("Can't Add More Element to Array until its resize!  Try Calling Resize() to add more element");
        return;
    }
    Heap<T>::heap_container.push_back(element);
    PRINTF("------");
}
template <class T>
void MyArray<T>::Resize(int new_len) {
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
template <class T>
void MyArray<T>::Sort() {
    PRINTF("+++++");
    int len = Heap<T>::heap_container.size();
    BuildHeap(len);
    while (len) {
#ifdef DEBUG_PRINT
        Print();
#endif
        Heap<T>::swap(0,len-1);
        len--;
        Heap<T>::Heapify(0, len);
    }
    PRINTF("-----");
}
template <class T>
void MyArray<T>::BuildHeap(int len) {
    PRINTF("+++++");
    for(int i = len/2; i >= 0; --i) {
        Heap<T>::Heapify(i, len);
    }
    PRINTF("-----");
}
template <class T>
void MyArray<T>::Print() {
    PRINTF("++++++ ");
    for(auto &v:Heap<T>::heap_container) {
        std::cout<<" "<<v;
    }
    std::cout<<"\n";
}
template <class T>
T& MyArray<T>::GetAt(int index) {
    PRINTF(("\n[" + TO_STR(index) + "]").c_str());
    if (index >= Heap<T>::heap_container.size()) {
        PRINTF("Invalid Index Provided!!!!");
        return -1;
    }
    PRINTF((TO_STR(Heap<T>::heap_container[index])).c_str());
    return Heap<T>::heap_container[index];
}
#endif //end of HEAP_H

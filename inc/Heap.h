#ifndef HEAP_H
#define HEAP_H

#include <vector>
//#define DEBUG_PRINT
class Heap{
public:
    Heap() {
        heap_container.resize(0);
    }
    ~Heap() {
        heap_container.resize(0);
    }
    void Insert(int val);
    int  GetTop();
    void RemoveTop();
protected:
    void Heapify(int index);
    void Heapify(int index, int len);
    int  GetParent(int child_index);
    int  GetLeftChild(int parent_index);
    int  GetRightChild(int parent_index);
    void swap(int first, int last);
    std::vector<int> heap_container;
};

class MyArray : public Heap{
public:
    MyArray() {}
    MyArray(int len = 0) : arr_len(len) {}
    ~MyArray() {}
    void Add(int element);
    void Resize(int new_len);
    void Sort();
    void Print();
    int GetAt(int index);
private:
    void BuildHeap(int len);
    int arr_len;
};
#endif //end of HEAP_H

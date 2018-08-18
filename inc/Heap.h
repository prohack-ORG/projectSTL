#ifndef HEAP_H
#define HEAP_H

#include <vector>

class Heap{

public:
    Heap() {}
    Heap(int capacity = 0):capacity(capacity) {
        heap_container.resize(0);
    }
    void Insert(int val);
    int  GetTop();
    void RemoveTop();

protected:
    void Heapify(int index);
    int  GetParent(int child_index);
    int  GetLeftChild(int parent_index);
    int  GetRightChild(int parent_index);
    void swap(int first, int last);
    std::vector<int> heap_container;
    int capacity;
};

class MyContainer : public Heap{

public:
    MyContainer(int capacity = 0) : Heap(capacity) {
    }
    void Add(int element);
    void Sort();
    void Print();
private:
    void BuildHeap();
};


#endif //end of HEAP_H

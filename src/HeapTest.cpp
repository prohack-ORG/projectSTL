#include "Heap.h"
#include <iostream>

using namespace std;
void TestHeapInteger() {
    cout<<"\nHEAP OPERATION ON INTEGER\n\n";
    int input[] = {4, 5, 6, 2, 1, -1, 77, 88, 23, 45};
    int len = sizeof(input)/ sizeof(input[0]);
    MyArray<int> arr(len);
    Heap<int , MAX_HEAP> max_heap_arr;
    for(int i = 0; i < len; i++) {
        cout<<input[i]<<" TOP : ";
        arr.Add(input[i]);
        max_heap_arr.Insert(input[i]);
        std::cout<<max_heap_arr.GetTop()<<"\n";
    }
    arr.Print();
    arr.Sort();
    arr.Print();
}
void TestHeapDouble() {
    cout<<"\nHEAP OPERATION ON DOUBLE\n\n";
    double input_d[] = {4.234, 5.6789, 22.46, 0.2, 112.1, -89.1, 111.77, 111.88, 111.23, 111.45};
    int len = sizeof(input_d)/ sizeof(input_d[0]);
    MyArray<double> arr_d(len);
    Heap<double , MAX_HEAP> max_heap_arr_d;
    for(int i = 0; i < len; i++) {
        cout<<input_d[i]<<" TOP : ";
        arr_d.Add(input_d[i]);
        max_heap_arr_d.Insert(input_d[i]);
        std::cout<<max_heap_arr_d.GetTop()<<"\n";
    }
    arr_d.Print();
    arr_d.Sort();
    arr_d.Print();
}

void TestHeapString() {
    cout<<"\nHEAP OPERATION ON STRING\n\n";
    string str[] = {"Hi", "hello", "there", "I", "do", "you", "really", "want"};
    int len = sizeof(str)/ sizeof(str[0]);
    MyArray<string> arr_str(len);
    Heap<string , MAX_HEAP> max_heap_arr_str;
    for(int i = 0; i < len; i++) {
        cout<<str[i]<<" TOP : ";
        arr_str.Add(str[i]);
        max_heap_arr_str.Insert(str[i]);
        std::cout<<max_heap_arr_str.GetTop()<<"\n";
    }
    arr_str.Print();
    arr_str.Sort();
    arr_str.Print();
}

void RunHeapTestAll() {
    TestHeapInteger();
    TestHeapDouble();
    TestHeapString();
}

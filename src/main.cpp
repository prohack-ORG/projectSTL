#include "Heap.h"
#include <iostream>


using namespace std;

int main() {
    cout<<"Hello World\n";
    int len = 0;
    
    int input[] = {4, 5, 6, 2, 1, -1, 77, 88, 23, 45};
    
    len = sizeof(input)/ sizeof(input[0]);
    MyContainer arr(len);
    
    for(int i = 0; i < len; i++) {
        //cout<<input[i]<<"\n";
        arr.Add(input[i]);
    }
    arr.Print();
    arr.Sort();
    arr.Print();
    return 0;
}

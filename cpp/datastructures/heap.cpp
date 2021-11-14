#include <iostream>
using namespace std;
#define left(i) 2*i+1
#define right(i) 2*i+2
#define parent(i) (i-1)/2

class heap{
    private:
    int size;
    public:
    const int capacity;
    int *h_arr;
    heap(int n): size(0), capacity(n), h_arr(NULL){
        h_arr = new int(n);
    }
    void heapify(int i){
        int largest = i;
        if(left(i) < size && h_arr[largest] < h_arr[left(i)]) largest = left(i);
        if(right(i) < size && h_arr[largest] < h_arr[right(i)]) largest = right(i);
        if(largest != i){
            swap(h_arr[largest], h_arr[i]);
            heapify(largest);
        }
    }
    void insert(int n){
        if(size == capacity) throw out_of_range("OverFlow");
        h_arr[size++] = n;
        int i = size - 1;
        while(i != 0 && h_arr[parent(i)] < h_arr[i]){
            swap(h_arr[i], h_arr[parent(i)]);
            i = parent(i);
        }
    }
    void pop(){
        if(size == 0) return;
        swap(h_arr[0], h_arr[size-1]);
        size--;
        heapify(0);
    }
    int getTop(){
        return h_arr[0];
    }
    void printHeap(){
        for(int i = 0; i < size; i++) cout << h_arr[i] << " ";
        cout << endl;
    }
};

int main(){
    heap *maxHeap = new heap(5);
    maxHeap->insert(2);
    maxHeap->insert(3);
    maxHeap->insert(1);
    maxHeap->insert(6);
    maxHeap->insert(4);
    maxHeap->printHeap();
    maxHeap->pop();
    maxHeap->printHeap();
    cout << maxHeap->getTop() << endl;
    maxHeap->insert(5);
    maxHeap->printHeap();
    maxHeap->insert(0);
    
}


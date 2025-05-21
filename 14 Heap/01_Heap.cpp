#include<iostream>
using namespace std;

class Heap {
public:
    int size;
    int arr[100];

    void insertion(int val) {
        size = size+1;
        int index = size;
        arr[index] = val;

        while (1<index) {
            int parent = index/2;

            if (arr[parent]<arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else return;
        }
    }

    
    void deletion() {
        if (size==0) {
            cout<<"Heap is empty"<<endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int index = 1;

        while (index<size) {
            int left = index*2;
            int right = index*2+1;
            int largest = index;

            if (left<=size && arr[left]>arr[largest]) {
                largest = left;
            }
            if (right<=size && arr[right]>arr[largest]) {
                largest = right;
            }
            if (largest!=index) {
                swap(arr[index], arr[largest]);
                index = largest;
            }
            else return;
        }
    }


    void heapify(int* arr, int n) {
        for (int i = n/2; i>=1; i--) {
            int index = i;
            while (index<=n) {
                int left = index*2;
                int right = index*2+1;
                int largest = index;

                if (left<=n && arr[left]>arr[largest]) {
                    largest = left;
                }
                if (right<=n && arr[right]>arr[largest]) {
                    largest = right;
                }
                if (largest!=index) {
                    swap(arr[index], arr[largest]);
                    index = largest;
                }
                else break;
            }
        }
    }

    void heapSort(int* arr, int n) {
        heapify(arr, n);

        for (int i = n; i>=1; i--) {
            swap(arr[1], arr[i]);
            int index = 1;
            while (index<=i) {
                int left = index*2;
                int right = index*2+1;
                int largest = index;

                if (left<=i && arr[left]>arr[largest]) {
                    largest = left;
                }
                if (right<=i && arr[right]>arr[largest]) {
                    largest = right;
                }
                if (largest!=index) {
                    swap(arr[index], arr[largest]);
                    index = largest;
                }
                else break;
            }
        }
    }

};

int main() {
    

    return 0;
}
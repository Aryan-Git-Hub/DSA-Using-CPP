// removing element in array
#include<iostream>
using namespace std;

int removeElement(int* A, int n1, int B) {
    int start = 0, end = n1-1;
    while (start<end)
    {
        if (A[start]!=B) start++;
        else
        {
            if (A[end]!=B) {
                int temp = A[start];
                A[start] = A[end];
                A[end] = temp;
                start++;
            }
            end--;
        }
    }
    int count = 0;
    for (int i = n1-1; i >= 0; i--) if (A[i]==B) count++;
    for (int i = 0; i < n1-count; i++) cout<<A[i]<<" ";
    return count;
}

int main() {
    int n1 = 6;
    int A[6] = {4, 1, 1, 2, 1, 3};
    int B = 1;
    int no_of_remove_elem = removeElement(A, n1, B);
    cout<<endl;
    cout<<no_of_remove_elem;

    return 0;
}
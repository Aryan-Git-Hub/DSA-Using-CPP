// To find the missing and repeating element in an array of size n.
// we will use the concept of remaiander and quotient or storing two numbers at one position.
// x = n * occurence + number_at_index
// Time Complexity: O(n)
// Space Complexity: O(1)
#include<iostream>
using namespace std;

int main() {
    int n = 7;
    int arr[7] = {4, 3, 6, 2, 2, 1, 7};

    for (int i = 0; i < n; i++) arr[i] = arr[i] - 1;
    // {3, 2, 5, 1, 1, 0, 6}

    int sum = 0;
    for (int i = 0; i < n; i++) arr[arr[i]%n] += n;
    
    // {10, 8, 12, 2, 1, 0, 13}
    for (int i = 0; i < n; i++) {
        if (arr[i]/n == 0) cout << "Missing: " << i + 1 << endl;
        if (arr[i]/n >= 2) cout << "Repeating: " << i + 1 << endl;
    }

    return 0;
}
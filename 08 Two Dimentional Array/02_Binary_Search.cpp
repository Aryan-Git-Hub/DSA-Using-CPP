#include<iostream>
using namespace std;

int main() {
    int row = 4, col = 4, key = 7;
    typedef vector<int> vi;
    vector<vi> v(row, vector<int>(col));

    // taking input
    for (int i = 0; i < row; i++) for (int j = 0; j < col; j++) v[i][j] = col*i+j+1;

    // printing the 2D array
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) cout<<v[i][j]<<" ";
        cout<<endl;
    }

    // main code
    int mid, start = 0, end = row*col-1;
    int ans[2] = {-1, -1};
    while (start<=end)
    {
        mid = (start+end)/2;
        int i = mid/col, j = mid%col;
        if (v[i][j]==key)
        {
            ans[0] = i;
            ans[1] = j;
            break;
        }
        else if (v[i][j]<key) start = mid+1;
        else end = mid-1;
    }
    cout<<"Answer is {"<<ans[0]<<", "<<ans[1]<<"}"<<endl;

    return 0;
}
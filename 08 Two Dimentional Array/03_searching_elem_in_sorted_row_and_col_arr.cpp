#include<iostream>
#include<vector>
using namespace std;

int main() {
    int row = 5, col = 5, target = 51;
    typedef vector<int> vi;
    vector<vi> v(row, vector<int>(col, 0));

    // taking input
    int arr[5][5] = {
        {10, 20, 30, 40, 50},
        {15, 25, 35, 45, 55},
        {27, 29, 37, 48, 57},
        {32, 33, 39, 50, 60},
        {37, 39, 40, 51, 70}
    };
    for (int i=0; i<row; i++) for (int j=0; j<col; j++) v[i][j] = arr[i][j];

    // main code
    int left = col-1, down = 0;
    int ans[2] = {-1, -1};
    while (left>=0 && down<row)
    {
        if (v[down][left]==target)
        {
            ans[0] = down;
            ans[1] = left;
            break;
        }
        else if (v[down][left]>target) left--;
        else down++;
    }
    
    cout<<"Answer is {"<<ans[0]<<", "<<ans[1]<<"}"<<endl;

    return 0;
}
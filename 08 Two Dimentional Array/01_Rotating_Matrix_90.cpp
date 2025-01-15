// This is code for rotating a matrix by 90 degrees.
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int row = 5, col = 4;
    typedef vector<int> vi;
    vector<vi> v(row, vector<int>(col, 0));
    vector<vi> v_temp(col, vector<int>(row, 0));

    // taking inputs
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++) v[i][j] = i*col+j+1;

    // main logic
    for (int i = 0; i < col; i++)
        for (int j = 0; j < row; j++) v_temp[i][j] = v[row-j-1][i];

    // output
    for(int i = 0; i < col; i++) {
        for(int j = 0; j < row; j++) {
            cout << v_temp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

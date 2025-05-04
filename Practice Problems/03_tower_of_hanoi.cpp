#include<iostream>
using namespace std;

void TOI(int N, int from, int help, int to) {
    if(N == 1) {
        cout << "Move disk 1 from rod " << from << " to rod " << to << endl;
        return;
    }
    TOI(N-1, from, to, help);
    cout << "Move disk " << N << " from rod " << from << " to rod " << to << endl;
    TOI(N-1, help, from, to);
}

int main() {
    int n = 3;
    TOI(n, 0, 1, 2);

    return 0;
}
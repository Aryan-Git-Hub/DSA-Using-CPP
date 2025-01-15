// Question - Find target = sum of two elements
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n = 5;
    vector<int> v(n);
    v[0] = 15;
    v[1] = 27;
    v[2] = 11;
    v[3] = 5;
    v[4] = 7;
    sort(v.begin(), v.end());

    int target = 22, prefix = 0, suffix = n-1, ans = 0;
    while (prefix<suffix)
    {
        int sum = v[prefix]+v[suffix];
        if (sum==target) {
            ans = 1;
            break;
        }
        else {
            if (sum>target) suffix--;
            else prefix++;
        }
    }
    cout<<"Answer is "<<ans;


    return 0;
}
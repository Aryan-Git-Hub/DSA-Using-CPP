#include<iostream>
using namespace std;

string reverse(string str) {
    int start = 0,  end = str.size()-1;
    while (start<end)
    {
        swap(str[start], str[end]);
        start++; end--;
    }
    return str;
}

string multiply(string str, int num) {
    string ans = "";
    int carry = 0;
    int temp;
    for (int i = str.size()-1; i >= 0; i--)
    {
        temp = (str[i]-'0')*num+carry;
        carry = temp/10;
        ans += ('0'+temp%10);
    }
    if(carry) ans += to_string(carry);
    return reverse(ans);
}

int main() {
    int n;
    cout<<"Enter a number to find its factorial: ";
    cin>>n;
    
    string fac = "1";
    for (int i = 1; i <= n; i++) fac = multiply(fac, i);
    cout<<fac<<endl;

    return 0;
}
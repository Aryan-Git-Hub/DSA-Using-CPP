#include<iostream>
using namespace std;

int main() {
    int arr[7] = {27*1+'I'-'A', 27*5+'V'-'A', 27*10+'X'-'A', 27*50+'L'-'A', 27*100+'C'-'A', 27*500+'D'-'A', 27*1000+'M'-'A'};

    string str = "MCMXCIV"; // 1994

    int ans = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int val1, val2;
        for (int j = 0; j < 7; j++)
        {
            if (str[i]==(char)(arr[j]%27+'A')) val1 = arr[j]/27;
            if (str[i+1]==(char)(arr[j]%27+'A')) val2 = arr[j]/27;
        }

        if (val1>=val2) ans += val1;
        else
        {
            ans += val2 - val1;
            i++;
        }
    }

    cout<<str<<" = "<<ans<<endl;

    return 0;
}
#include<iostream>
using namespace std;

void sort_str(string &str, string &vowels) {
    int n = str.size();
    string temp = "";
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vowels[i]==str[j]) temp += str[j];
        }
    }
    str = temp;
}

int main() {
    string vowels = "AEIOUaeiou";
    string s;
    cout<<"Enter the string: ";
    cin>>s; // lEetcOde
    
    string v = "";
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (s[i]==vowels[j])
            {
                v += s[i];
                s[i] = '#';
                break;
            }
        }
    }
    
    sort_str(v, vowels);

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i]=='#')
        {
            s[i] = v[count];
            count++;
        }
    }

    cout<<s<<endl;

    return 0;
}
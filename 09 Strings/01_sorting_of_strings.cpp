#include<iostream>
using namespace std;

int main() {
    string s = "Aryan3 Jain4 name1 is2 my0";
    string s1[10];
    string temp = "";
    int count = 0;
    for (int i = 0; i <= s.size(); i++)
    {
        if (s[i]==' ' | i==s.size())
        {
            char position = temp[temp.size()-1];
            int position_num = position-'0';
            temp.pop_back();
            s1[position_num] = temp;
            temp = "";
            count++;
        } else temp += s[i];
    }
    
    temp = "";
    for (int i = 0; i < count; i++)
    {
        temp += s1[i];
        temp += ' ';
    }
    temp += '\n';
    cout<< temp;


    return 0;
}
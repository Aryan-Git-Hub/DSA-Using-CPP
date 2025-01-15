// vector is used to create an array which is dynamically alocated in heap memory and use various method with it i.e., sorting an array using just vector.sort() method and many other method
// vector contains all functionaity of array and having many additional methods to perform many type of operations
#include<iostream>
#include<vector>
using namespace std;

void display_vector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) cout<<v[i]<<" ";
}

int main() {
    // // creating dynamic array using vector
    // int n;
    // cout<<"Enter the size of array: ";
    // cin>>n;
    // vector<int> v(n, 2); // v(size, initialization value) -> by default initialization value is 0
    // display_vector(v);




    vector<int> v1;
    cout<<sizeof(v1)<<endl;
    v1.push_back(65); // capacity = 1
    v1.push_back(66); // capacity *= 2 = 2
    v1.push_back(67); // capacity *= 2 = 4
    v1.push_back(68); // capacity *= 2 = 8
    v1.push_back(69); // capacity = 1 = 8 // since there is capacity available to add 69 in this vector if not capacity available then it will increase it capacity by the factor of 2
    display_vector(v1);
    cout<<endl;
    cout<<v1.capacity()<<endl; // 8

    v1.pop_back();
    display_vector(v1);
    cout<<endl;
    cout<<v1.capacity()<<endl; // 8 -> capacity will remains same after removing any element

    v1.clear();
    display_vector(v1);
    cout<<endl;
    cout<<v1.capacity()<<endl; // 8

    cout<<v1.empty()<<endl; // returns vector is empty or not (0,1)

    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.begin(); // ---> this is an iterator which points to first element of a vector
    v1.end(); // ---> this is an iterator which points to just after last element of a vector
    v1.rend(); // ---> this is an iterator which points to last element of a vector
    v1.rbegin(); // ---> this is an iterator which points to just before first element of a vector

    // we can perform such methods or functions on vector like removing particular element using iterator i.e. element slicing or removing in python list
    v1.erase(v1.begin()+1); // removing particular element, it remove element of index 1
    display_vector(v1);
    cout<<endl;

    cout<<v1[1]<<endl;
    v1.insert(v1.begin()+1, 50);
    display_vector(v1);
    cout<<endl;

    // front and back method
    cout<<v1[0]<<" = "<<v1.front()<<endl;
    cout<<v1[v1.size()-1]<<" = "<<v1.back ()<<endl;

    // copying vector
    vector<int> v2;
    v2 = v1;
    display_vector(v2);
    cout<<endl;
    cout<<v1.capacity()<<endl;

    // methods to print vector
    // 1.
    for(auto it = v2.begin(); it != v2.end(); it++)
        cout<<*it<<" ";
    cout<<endl;
    // 2.
    for(auto i: v2)
        cout<<i<<" ";
    cout<<endl;
    // 3.
    display_vector(v2);
    cout<<endl<<endl;


    // sorting vector
    vector<int> v3;
    v3.push_back(5);
    v3.push_back(235);
    v3.push_back(15);
    v3.push_back(54);
    v3.push_back(125);


    // sort in increasing order
    sort(v3.begin(), v3.end());
    display_vector(v3);
    cout<<endl;

    // // sort in decreasing order
    // sort(v3.begin(), v3.end(), greater<int>());
    // display_vector(v3);
    // cout<<endl;
    // // another method to sort in decreasing order is 
    // sort(v3.rbegin(), v3.rend());
    // display_vector(v3);
    // cout<<endl;

    // search in binary search
    cout<<v3.end()-v3.begin()<<endl;
    cout<<binary_search(v3.begin(), v3.end(), 54)<<endl; // binary_search(kaha_se, kaha_tk, konsa_elem)

    // finding index of element
    cout<<find(v3.begin(), v3.end(), 54) - v3.begin()<<endl; // since find function returns an iterator so we have to subtract iterator of first element to get answer in proper integer index
    return 0;
}
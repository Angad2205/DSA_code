// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

void subset(vector<int> &array , vector<int> &sub , int index)
{
 if(index == array.size())
 {
     // print the sequence 
     for(int value : sub)
     cout<< value << " ";
     cout<<endl;
     return;
 }
 
 //include
 sub.push_back(array[index]);
 subset(array,sub,index+1);
 
 sub.pop_back();
 subset(array,sub,index+1);
}
int main() {
vector<int> array = {1,2,3,4,5};
vector<int>sub = {};

subset(array,sub,0);

    return 0;
}

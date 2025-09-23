// pair sum 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> pairSum(vector<int>&array, vector<int>&answer,int target)
{   int size = array.size();
    int min = 0;
    int max = size -1;
    while(min < max)
    {   
        if((array[min] + array[max]) == target)
        {
            break;
        }
        
        if((array[min] + array[max]) < target)//increment min
        {
            min++;
        }
        else{//decrement the max index
            max--;
        }
    }
    answer.push_back(min);
    answer.push_back(max);
    return answer;
}

int main()
{
    vector<int>array = {1,4,7,9,10};
    vector<int>answer;
    pairSum(array,answer,19);
    for(int val : answer)
        cout<<val<< " ";
    cout<<endl;
    return 0;
}

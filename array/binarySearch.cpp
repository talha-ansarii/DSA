// Container with most water

#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int binarySearch(vector<int> vec, int target){
    int start = 0;
    int end = vec.size()-1;
    while(start<=end){
        int mid = (start+end)/2;
        if(target > vec[mid]  ){
            start=mid+1;
        }
        else if(target<vec[mid]){
            end = mid - 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}


int main()
{

    vector<int> vec = {1, 2, 3, 4};
    int position = binarySearch(vec, 7);
    cout<<position;
    return 0;
}
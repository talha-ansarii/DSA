// Container with most water

#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int binarySearch(vector<int> vec, int target){
    int start = 0;
    int end = vec.size()-1;
    while(start<=end){
        // int mid = (start+end)/2;
        int mid = start + (end-start)/2;  //no overflow condition
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

int recursivebinarySearch(vector<int> vec, int target, int start, int end){
    if(start<=end){
        int mid = start + (end-start)/2;  //no overflow condition
        if(target > vec[mid]  ){
           return recursivebinarySearch(vec, target, mid+1, end);
        }
        else if(target<vec[mid]){
           return recursivebinarySearch(vec, target, start, mid-1);

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
    // int position = binarySearch(vec, 7);
    int position = recursivebinarySearch(vec,3,0,vec.size()-1);
    cout<<position;
    return 0;
}
// Container with most water

#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int searchInRotatedArray(vector<int> vec, int target){
    int start = 0;
    int end = vec.size()-1;
    while(start<=end){
        // int mid = (start+end)/2;
        int mid = start + (end-start)/2;  //no overflow condition
        if(vec[mid] == target) return mid;


       if(vec[start] <= vec[mid]){   //left sorted
            if(vec[start] <= target && target <= vec[mid]){ //appear in left part
                end=mid-1;
            }
            else{   //appear in right part
                start = mid+1;
            }
       }
       else{    //right sorted
            if(vec[mid] <= target && target <= vec[end]){ //right part
                start = mid+1;
            }
            else{   //left part
                end = mid-1;
            }
       }
    }
    return -1;
}


int main()
{

    vector<int> vec = {4, 1, 2, 3};
    // int position = binarySearch(vec, 7);
    int position = searchInRotatedArray(vec,3);
    cout<<position;
    return 0;
}
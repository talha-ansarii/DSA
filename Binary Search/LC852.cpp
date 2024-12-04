// Container with most water

#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int peakIndexInMountainArray(vector<int>& arr) {
        int s = 1;
        int e = arr.size() - 2;
        while(s<=e){
            int mid = (s+e)/2;
            if(arr[mid-1] < arr[mid] && arr[mid+1] < arr[mid]){
                return mid;
            }
            if(arr[mid-1] < arr[mid]) { //left side
                s = mid +1;
            }
            else{ //right side
                e = mid-1;
            }
        }
        return -1;
    }

int main()
{

    vector<int> vec = {1, 2, 4, 3};
    // int position = binarySearch(vec, 7);
    int position = peakIndexInMountainArray(vec);
    cout<<position;
    return 0;
}
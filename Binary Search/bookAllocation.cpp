#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool isValid(vector<int> &arr, int n, int m, int maxAllowedPages){
    int student = 1;
    int pages=0;
    for(int i=0; i<n; i++){
        if(arr[i] > maxAllowedPages) return false;

        if(pages + arr[i] <= maxAllowedPages){
            pages = pages + arr[i];
        }else{
            student++;
            pages = arr[i];
        }

    }

    if(student > m) return false;
    else return true;

}


int allocateBooks(vector<int> &arr, int n, int m){
    int sum = 0;
    for (int i=0; i<n ; i++){
        sum += arr[i];
    }

    int start =0; 
    int end = sum;
    int ans=-1;
    while(start <= end){
        int mid = start + ((end-start)/2);

        if(isValid(arr, n, m, mid)){    
            ans = mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return ans;
}



int main()
{

    vector<int> vec = {2, 1, 3, 4};
    int minMaxAllowedPages = allocateBooks(vec,vec.size(),2);
    cout<<minMaxAllowedPages;
    return 0;
}
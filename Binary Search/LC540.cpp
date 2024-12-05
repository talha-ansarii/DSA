// Single element in sorted array
#include <iostream>
#include <vector>
#include <climits>
using namespace std;


 int singleNonDuplicate(vector<int>& A) {
        int n = A.size();
        int start =  0;
        int end = n-1;
        if (n==1){
            return A[0];
        }
        while(start <=  end){
            int mid = (start+end)/2;
            //edge cases
            if(mid==0 && A[0] != A[1]) return A[mid];
            if(mid == n-1 && A[n-1] != A[n-2]) return A[mid];

            //base case
            if(A[mid-1] != A[mid] && A[mid] != A[mid+1]) return A[mid];

            //search space
            if(mid%2 == 0 ){ //even elements in L & R
                if(A[mid] == A[mid-1]) {  //left part
                    end = mid - 1;
                }else{ //right part
                    start =  mid +1;
                }
            } else{ // odd elements in L&R
                if(A[mid] == A[mid-1]) {  //right part
                    start =  mid +1;
                }else{ //left part
                end = mid -1;
                }
            }
            
        }
        return -1;

    }


int main()
{

    vector<int> vec = {3,3,7,7,10,11,11};
    int position = singleNonDuplicate(vec);
    cout<<position;
    return 0;
}
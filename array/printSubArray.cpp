#include<iostream>
#include<vector>
#include <climits>
using namespace std;

int subArrayMaxSum(vector<int> vec){

int maxSum = INT_MIN ;

 for(int s=0; s< vec.size() ; s++){
    int currentSum = 0;
    for(int e=s; e< vec.size(); e++){
            currentSum += vec[e];

        if(currentSum > maxSum ){
            maxSum = currentSum;
        }
    }
 }

 return maxSum;

}

int subArrayMaxSumKadaneAlgo(vector<int> vec){

    int maxSum = INT_MIN;
    int currentSum = 0;

    for(int i = 0; i < vec.size(); i++){
        currentSum += vec[i];

        if(currentSum > maxSum){
            maxSum= currentSum;
        }
        if (currentSum < 0){
            currentSum =0;
        }
    }

    return maxSum;
}



int main(){

    vector<int> vec = {1,2,-3,4};

    
    // int max = subArrayMaxSum(vec);
    int max = subArrayMaxSumKadaneAlgo(vec);

    cout<<"max is: "<<max;

   

    return 0;
}
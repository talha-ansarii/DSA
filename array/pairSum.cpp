#include<iostream>
#include<vector>
#include <climits>
using namespace std;

vector<int> pairSum(vector<int> vec, int target){

int maxSum = INT_MIN ;

 for(int s=0; s< vec.size() ; s++){
    for(int e=s; e< vec.size(); e++){
          if(vec[s] + vec[e] == target){
            vector<int> ans;
            ans.push_back(s);
            ans.push_back(e);
            return ans;
          }
    }
 }

}

vector<int> pairSumOptimized(vector<int> vec, int target){


    int i=0;
    int j= vec.size()-1;

    while (i<j)
    {
        int pairSum = vec[i] + vec[j];
        
        if (pairSum > target)
        {
            j--;
        }
        else if (pairSum < target)
        {
            i++;
        }
        else{
            vector<int> ans;
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
        
        
    }
    
    

}



int main(){

    vector<int> vec = {1,2,3,4};

    
    // int max = subArrayMaxSum(vec);
    vector<int> ans = pairSumOptimized(vec,6);

    cout<<"ans is: "<<ans[0]<<" "<<ans[1]<<endl;

   

    return 0;
}
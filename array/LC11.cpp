//Container with most water

#include<iostream>
#include<vector>
#include <climits>
using namespace std;


 int maxAreaBruteForce(vector<int>& height) {
        int maxArea = INT_MIN;
        int currentArea;
        
        for(int i=0; i< height.size(); i++){
            for(int j = i+1 ; j<height.size(); j++){
                currentArea = min(height[i], height[j]) * (j-i);
                maxArea = max(maxArea, currentArea);

            }
        }
            return maxArea;

    }

int maxAreaTwoPointer(vector<int>& height) {
        int maxArea = INT_MIN;
        
        int i = 0;
        int j = height.size()-1;

        while(j>i){
            int currentArea = min(height[i],height[j]) * (j-i);
            maxArea = max(maxArea, currentArea);

            height[i]>height[j] ? j-- : i++; 
        }
            return maxArea;

    }

int main(){

    vector<int> vec = {4,2,3,4};

    // int maxWater = maxAreaBruteForce(vec) //TLE
    int maxWater = maxAreaTwoPointer(vec); 
   
    cout<<"max water area: " <<maxWater<<endl;
    return 0;
}
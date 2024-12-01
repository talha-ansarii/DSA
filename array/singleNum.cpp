#include<iostream>
#include<vector>
using namespace std;

int singleNum(vector<int> &nums){

int ans=0;
for(int i :nums){
    ans = ans^i;
}
return ans;
    
}


int main(){

    vector<int> vec = {1,2,3,2,1};

    int ans = singleNum(vec);

    cout<<"answer : "<<ans<<endl;

   

    return 0;
}
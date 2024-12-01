// Container with most water

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> productExceptSelfBruteForce(vector<int> &nums)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        int currentAnswer = 1;
        for (int j = 0; j < nums.size(); j++)
        {
            if (i == j)
                continue;
            currentAnswer = currentAnswer * nums[j];
        }
        ans.push_back(currentAnswer);
    }
    return ans;
}

vector<int> productExceptSelfOptimal(vector<int> &nums)
{
    int allProd = 1;

    vector<int> ans(nums.size(), 0);
    int flag = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            flag++;
            continue;
        }
        allProd *= nums[i];
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (flag >= 2)
        {
            break;
        }
        else
        {
            if (flag > 0)
            {
                if (nums[i] == 0)
                {
                    ans[i] = allProd;
                }else{
                    continue;
                }
                
            }else{
                ans[i] = allProd / nums[i];
            }
        }
    }

    return ans;
}
vector<int> productExceptSelfOptimalWithoutDivision(vector<int> &nums)
{
    int n = nums.size();
    vector<int> prefix(n,1);
    vector<int> suffix(n,1);
    vector<int> ans(n,1);

    ///prefix
    for(int i = 1 ; i<n; i++){
        prefix[i] = prefix[i-1] * nums[i-1];
    }

    //suffix
    for(int i =n-2 ; i>=0; i--){
        suffix[i] = suffix[i+1] * nums[i+1];
    }

    //ans
    for(int i =0 ; i<n; i++){
        ans[i] = prefix[i] * suffix[i];
    }

    return ans;
   
}

vector<int> productExceptSelfOptimalWithoutDivisionOtimizesSC(vector<int> &nums){
    int n = nums.size();
    vector<int> ans(n,1);

    for(int i = 1 ; i<n; i++){
        ans[i] = ans[i-1] * nums[i-1];
    }

    int suffix = 1;
    for(int i = n-2; i>=0; i--){
        suffix = suffix * nums[i+1];
        ans[i] = suffix * ans[i];
    }
    return ans;
}


int main()
{

    vector<int> vec = {1, 2, 3, 4};
    vector<int> ans;
    // ans = productExceptSelfBruteForce(vec); //O(n^2)
    // ans = productExceptSelfOptimal(vec); //O(n)
    ans = productExceptSelfOptimalWithoutDivision(vec);
    ans = productExceptSelfOptimalWithoutDivisionOtimizesSC(vec);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
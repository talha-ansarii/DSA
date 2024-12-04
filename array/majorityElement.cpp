
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm> // Required for sort
using namespace std;

int bruteForce(vector<int> vec)
{

    for (int val : vec)
    {
        int frequency = 0;
        for (int ele : vec)
        {
            if (ele == val)
            {
                frequency++;
            }
        }
        if (frequency > vec.size() / 2)
            return val;
    }

    return -1;
}

int betterSolution(vector<int> vec) {
    sort(vec.begin(), vec.end());

    int frequency = 1; // Start with 1 for the current element
    for (int i = 1; i < vec.size(); i++) { // Start from 1 to compare with the previous element
        if (vec[i] == vec[i - 1]) {
            frequency++;
        } else {
            frequency = 1; // Reset frequency for the new element
        }
        if (frequency > vec.size() / 2) {
            return vec[i - 1]; // Return the previous element as the majority
        }
    }

    return -1; // Return -1 if no majority element exists
}

int moorealgo(std::vector<int>& nums) {

    // Phase 1: Candidate Selection
    int candidate = 0, count = 0;
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
            count = 1;
        } else if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }

    // Phase 2: Candidate Verification
    count = 0;
    for (int num : nums) {
        if (num == candidate) {
            count++;
        }
    }

    if (count > nums.size() / 2) {
        return candidate;
    }
    return -1; // No majority element
}

int main()
{

    vector<int> vec = {2, 1, 1, 1, 2, 1};
    // int element = bruteForce(vec);
    // int element = betterSolution(vec);
    int element = moorealgo(vec);

    cout << element;
    return 0;
}
// Jump Game - Leetcode 55
#include <vector>
#include <iostream>
using namespace std;
bool canJump(vector<int>& nums) {
    int n = nums.size();
    int maxIndex = 0;
    
    for(int i=0;i<n;i++) {
        if(i > maxIndex) return false; 
        maxIndex = max(maxIndex, i + nums[i]);
    }
    return true;
}

int main(){
    vector<int> nums = {2, 3, 1, 1, 4};
    bool result = canJump(nums);
    if(result) {
        cout<<"You can reach the last index.\n";
    } else {
        cout<<"You cannot reach the last index.\n";
    }
}

/*
Time Complexity: O(n), where n is the length of the input vector nums.
Space Complexity: O(1), as we are using only a constant amount of extra space for variables.
*/
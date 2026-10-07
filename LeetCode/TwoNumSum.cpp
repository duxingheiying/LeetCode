#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        unsigned int vec_size = nums.size();
        for(int i =0; i<vec_size; i++){
            for(int j=i+1; j< vec_size; j++) {
                if(nums[i]+nums[j]==target){
                    return {i, j};
                    break;
                }
            }
        }
        return{-1, -1};
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = solution.twoSum(nums, target);
    
    // Output the result
    for (int index : result) {
        std::cout << index << " ";
    }
    
    return 0;
}
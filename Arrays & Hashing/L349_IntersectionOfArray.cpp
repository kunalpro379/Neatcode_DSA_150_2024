#include <iostream>
#include <vector>
using namespace std;
#include <unordered_set>

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int>nums1_set(nums1.begin(), nums1.end());
                unordered_set<int>nums2_set(nums2.begin(), nums2.end());
                    vector<int>result;
                for(auto &num : nums1_set){
                            if(nums2_set.count(num)>0){
                                result.push_back(num);
                            }
                }
            return result;

    }
};
int main() {
    Solution solution;

    std::vector<int> nums1_1 = {1, 2, 2, 1};
    std::vector<int> nums2_1 = {2, 2};
    std::vector<int> output_1 = solution.intersection(nums1_1, nums2_1);
    
    for (const int& num : output_1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> nums1_2 = {4, 9, 5};
    std::vector<int> nums2_2 = {9, 4, 9, 8, 4};
    std::vector<int> output_2 = solution.intersection(nums1_2, nums2_2);
    
    for (const int& num : output_2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int numberFindIdx = 0;
        int writeIdx = 0;

        while (numberFindIdx < nums.size())
        {
            if (nums[numberFindIdx] != 0)
            {
                std::swap(nums[writeIdx], nums[numberFindIdx]);
                ++writeIdx;
            }
            
            ++numberFindIdx;
        }
    }
};

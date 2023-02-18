class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = accumulate(nums.begin(), nums.end(), 0);

        for(int pivotIdx = 0; pivotIdx < nums.size(); ++pivotIdx)
        {
            rightSum -= nums[pivotIdx];

            if (leftSum == rightSum)
                return pivotIdx;

            leftSum += nums[pivotIdx];
        }

        return -1;
    }
};

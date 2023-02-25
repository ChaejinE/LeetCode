#include <vector>

using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;

        int leftIdx = 0;
        int rightIdx = nums.size() - 1;
        int pivotIdx;
        while (leftIdx < rightIdx)
        {
            pivotIdx = (leftIdx + rightIdx) / 2;

            if (nums[pivotIdx] <= nums[pivotIdx + 1])
                leftIdx = pivotIdx + 1;
            else
                rightIdx = pivotIdx;
        }

        return leftIdx;
    }
};

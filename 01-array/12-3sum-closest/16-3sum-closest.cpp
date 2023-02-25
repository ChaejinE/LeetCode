#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int result = numeric_limits<int>::max() - 1e4;
        sort(nums.begin(), nums.end());

        for (int firstIdx = 0; firstIdx < nums.size() - 2; ++firstIdx)
        {
            if (firstIdx > 0 && nums[firstIdx] == nums[firstIdx - 1])
                continue;

            int secondIdx = firstIdx + 1;
            int thirdIdx = nums.size() - 1;

            for (; secondIdx < thirdIdx;)
            {
                int sum = nums[firstIdx] + nums[secondIdx] + nums[thirdIdx];

                if (sum < target)
                {
                    ++secondIdx;
                }
                else if (sum > target)
                {
                    --thirdIdx;
                }
                else
                {
                    return sum;
                }

                if (abs(target - sum) < abs(target - result))
                    result = sum;
            }
        }

        return result;
    }
};

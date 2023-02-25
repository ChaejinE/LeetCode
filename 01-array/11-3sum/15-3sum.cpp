#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int target = 0;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int firstIdx = 0; firstIdx < nums.size(); ++firstIdx)
        {
            if (nums[firstIdx] > target)
                continue;

            // remove duplicate calculation
            if (firstIdx > 0 && nums[firstIdx] == nums[firstIdx - 1])
                continue;

            int secondIdx = firstIdx + 1, thirdIdx = nums.size() - 1;
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
                    result.emplace_back(vector<int>{nums[firstIdx], nums[secondIdx], nums[thirdIdx]});

                    ++secondIdx;
                    --thirdIdx;
                    while (secondIdx < thirdIdx && nums[secondIdx] == nums[secondIdx - 1])
                        ++secondIdx;
                    while (secondIdx < thirdIdx && nums[thirdIdx] == nums[thirdIdx + 1])
                        --thirdIdx;
                }
            }
        }

        return result;
    }
};

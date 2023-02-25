#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        if (nums.size() < 4)
            return vector<vector<int>>{};

        vector<vector<int>> output;
        sort(nums.begin(), nums.end());
        long long myTarget = static_cast<long long>(target);
        for (int firstIdx = 0; firstIdx < nums.size() - 3; ++firstIdx)
        {
            if (firstIdx > 0 && nums[firstIdx] == nums[firstIdx - 1])
                continue;

            for (int fourthIdx = nums.size() - 1; fourthIdx > 2; --fourthIdx)
            {
                if (fourthIdx < nums.size() - 1 && nums[fourthIdx] == nums[fourthIdx + 1])
                    continue;

                int secondIdx = firstIdx + 1;
                int thirdIdx = fourthIdx - 1;
                while (secondIdx < thirdIdx)
                {
                    long long sum = static_cast<long long>(nums[firstIdx]) +
                                    static_cast<long long>(nums[secondIdx]) +
                                    static_cast<long long>(nums[thirdIdx]) +
                                    static_cast<long long>(nums[fourthIdx]);

                    if (sum < myTarget)
                    {
                        ++secondIdx;
                    }
                    else if (sum > myTarget)
                    {
                        --thirdIdx;
                    }
                    else
                    {
                        output.emplace_back(vector<int>{nums[firstIdx], nums[secondIdx], nums[thirdIdx], nums[fourthIdx]});
                        ++secondIdx;
                        --thirdIdx; // secondIdx가 가리키는 값이 이미 다른 값이라 sum이 target이 될일이 없다.
                                    // 그러므로 thridIdx도 다른 값을 찾아주자.

                        while (secondIdx < thirdIdx && nums[secondIdx] == nums[secondIdx - 1])
                            ++secondIdx;
                        while (secondIdx < thirdIdx && nums[thirdIdx] == nums[thirdIdx + 1])
                            --thirdIdx;
                    }
                }
            }
        }

        return output;
    }
};

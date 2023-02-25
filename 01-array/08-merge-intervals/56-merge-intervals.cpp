#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        for (auto interval : intervals)
        {
            if (result.empty())
            {
                result.emplace_back(interval);
                continue;
            }

            auto mergedInterval = result.back();
            if (mergedInterval[1] >= interval[0])
            {
                if (mergedInterval[1] <= interval[1])
                {
                    result.pop_back();
                    result.emplace_back(vector<int>{mergedInterval[0], interval[1]});
                }
            }
            else
            {
                result.emplace_back(interval);
            }
        }

        return result;
    }
};

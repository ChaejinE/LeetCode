#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    unordered_map<char, vector<char>> make_hash()
    {
        unordered_map<char, vector<char>> hash_map;
        hash_map['1'] = vector<char>{};

        char ascii = 'a';
        size_t range;
        for (char num = '2'; num <= '9'; ++num)
        {
            size_t count = 0;
            vector<char> alphabets;

            if (num == '7' || num == '9')
                range = 4;
            else
                range = 3;

            alphabets.reserve(range);
            for (; ascii <= 'z' && count < range; ++ascii)
            {
                alphabets.emplace_back(ascii);
                ++count;
            }
            hash_map[num] = alphabets;
        }

        return hash_map;
    }

    void combinate(unordered_map<char, vector<char>> &hash,
                   vector<string> &result, string &digits, size_t idx, string &letter)
    {
        if (idx > digits.length() - 1)
        {
            result.emplace_back(letter);
            return;
        }

        vector<char> &s = hash[digits[idx]];
        for (auto &c : s)
        {
            letter += c;
            combinate(hash, result, digits, idx + 1, letter);
            letter.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        auto hash = Solution::make_hash();
        vector<string> result{};
        string letter = "";
        combinate(hash, result, digits, 0, letter);

        return result;
    }
};

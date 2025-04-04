class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, int> sequence;
        int longest_streak = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sequence[nums[i]]++;
        }

        for (auto it : sequence)
        {
            int num = it.first; 
            if (sequence.find(num - 1) == sequence.end())
            {
                int current_num = num;
                int curr_streak = 1;

                while (sequence.find(current_num + 1) != sequence.end())
                {
                    curr_streak++;
                    current_num++;
                }

                if (curr_streak > longest_streak)
                {
                    longest_streak = curr_streak;
                }
            }
        }

        return longest_streak;
    }
};

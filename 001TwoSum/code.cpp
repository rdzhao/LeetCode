class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		std::map<int, int> pair;

		for (int i = 0; i < nums.size(); ++i)
		{
			std::map<int, int>::iterator iter = pair.find(target - nums[i]);
			if (iter != pair.end())
			{
				std::vector<int> r;
				r.push_back(i);
				r.push_back(iter->second);

				return r;
			}
			pair[nums[i]] = i;
		}
	}
};
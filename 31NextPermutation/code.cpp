class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int asc = nums.size() - 1;
		int des = nums.size() - 1;

		if (nums.size() != 0 && nums.size() != 1)
		{
			for (int i = 0; i < nums.size() - 1; ++i)
			{
				if (nums[i] > nums[i + 1])
					des = i;

				if (nums[i] < nums[i + 1])
					asc = i;
			}

			if (asc == nums.size() - 1 && des != nums.size() - 1)
			{
				std::sort(nums.begin(), nums.end());
			}
			else if (asc != nums.size() - 1)
			{
				if (des == nums.size() - 1)
				{
					des = -1;
				}

				if (asc > des)
				{
					std::swap(nums[asc], nums[asc + 1]);
				}
				else
				{
					int idx = des + 2;
					for (int i = asc + 1; i < des + 2; ++i)
					{
						if (nums[i] <= nums[asc])
						{
							idx = i;
							break;
						}
					}

					std::swap(nums[asc], nums[idx - 1]);
					std::sort(nums.begin() + asc + 1, nums.end());
				}
			}
		}
	}
};
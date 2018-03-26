class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int mmin, mmax;
		vector<int> res;
		//cout << "T: " << target << endl;
		if (nums.empty())
			mmin = mmax = -1;
		else {
			minHelper(nums, target, 0, nums.size(), mmin);
			if (mmin != -1)
				maxHelper(nums, target, 0, nums.size(), mmax);
			else
				mmax = -1;
		}
		//cout<<mmin<<" "<<mmax;

		res.push_back(mmin);
		res.push_back(mmax);

		return res;
	}

	void minHelper(vector<int>& nums, int target, int lower, int upper, int& ohYes)
	{
		if (lower == upper) {
			// cout<<lower<<" "<<nums[lower]<<" "<<target<<endl;
			if (lower == nums.size())
				ohYes = -1;
			else {
				if (nums[lower] != target)
					ohYes = -1;
				else
					ohYes = lower;
			}
		}
		else {
			int idx = (lower + upper) / 2;

			if (target <= nums[idx]) {
				minHelper(nums, target, lower, idx, ohYes);
			}
			else {
				minHelper(nums, target, idx + 1, upper, ohYes);
			}
		}
	}

	void maxHelper(vector<int>& nums, int target, int lower, int upper, int& ohYes)
	{
		if (lower == upper) {
			ohYes = lower - 1;
			//if(upper<nums.size())
			//--ohYes;
		}
		else {
			int idx = (lower + upper) / 2;

			if (target >= nums[idx]) {
				maxHelper(nums, target, idx + 1, upper, ohYes);
			}
			else {
				maxHelper(nums, target, lower, idx, ohYes);
			}
		}
	}

};
class Solution {
public:
	int lengthOfLongestSubstring(string s) {

		int start = 0;
		int maxSize = 0;
		for (int i = 0; i < s.size(); i++)
		{
			string sub = s.substr(start, i - start + 1);

			int dup = CheckDuplicate(sub);
			if (dup != -1)
			{
				start = start + dup + 1;
			}
			else
			{
				if (maxSize < sub.size())
					maxSize = sub.size();
			}
		}

		return maxSize;
	}

	int CheckDuplicate(string s)
	{
		for (int i = 0; i < s.size() - 1; i++)
		{
			if (s[i] == s[s.size() - 1])
				return i;
		}

		return -1;
	}
};
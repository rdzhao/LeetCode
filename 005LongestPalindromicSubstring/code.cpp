class Solution {
public:
	string longestPalindrome(string s) {
		string cs;

		if (s.size() == 1 || s.size() == 0)
		{
			cs = s;
		}
		else {
			for (int i = 0; i < s.size(); i++) {
				int j, k;
				j = i; k = i;

				while (k + 1 < s.size())
				{
					if (s[k] == s[k + 1]) { k++; }
					else { break; }
				}

				while (j - 1 >= 0 && k + 1 < s.size())
				{
					if (s[j - 1] == s[k + 1]) { j--; k++; }
					else { break; }
				}

				string ccss = s.substr(j, k - j + 1);

				if (cs.size() < ccss.size())
					cs = ccss;
			}
		}
		return cs;
	}
};
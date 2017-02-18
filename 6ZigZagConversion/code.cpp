class Solution {
public:
	string convert(string s, int numRows) {
		string ss;

		if (numRows == 0 || numRows == 1)
			return s;
		else
		{
			for (int k = 0; k < numRows; ++k)
			{
				for (int i = 0; i < s.size() / (2 * numRows - 2) + 1; ++i)
				{
					if (k + i*(2 * numRows - 2) < s.size())
						ss += s[k + i*(2 * numRows - 2)];

					if (k != 0 && k != numRows - 1 && k + i*(2 * numRows - 2) + 2 * (numRows - 1 - k) < s.size())
						ss += s[k + i*(2 * numRows - 2) + 2 * (numRows - 1 - k)];
				}
			}

			return ss;
		}
	}
};
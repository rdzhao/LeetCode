class Solution {
public:
	string countAndSay(int n) {
		string res = "1";
		int i = 0;
		while (i<n - 1) {
			++i;

			res = helper(res);
		}

		return res;
	}

	string helper(string s)
	{
		string res;
		bool counting = false;
		char digit;
		int count = 0;

		for (int i = 0; i<s.size(); ++i) {
			if (!counting) {
				digit = s[i];
				counting = true;
				++count;
			}
			else {
				if (digit == s[i])
					++count;
				else {
					res += int2string(count);
					res += digit;

					digit = s[i];
					count = 1;
				}

			}
		}

		res += int2string(count);
		res += digit;

		return res;
	}

	string int2string(int n) {
		string res;

		while (n != 0) {
			int i = n % 10;
			n = n / 10;

			res += static_cast<char>(i + 48);
		}

		return res;
	}
};
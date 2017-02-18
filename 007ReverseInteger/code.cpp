class Solution {
public:
	int reverse(int x) {
		bool overflow = false;
		bool positive;

		if (x > 0) positive = true;
		else positive = false;

		int newX = 0;

		if (positive)
		{
			while (x != 0)
			{
				if (INT_MAX / 10 < newX)
				{
					overflow = true;
					break;
				}
				else
				{
					newX = newX * 10;
				}

				if (INT_MAX - x % 10 < newX)
				{
					overflow = true;
					break;
				}
				else
				{
					newX = newX + x % 10;
				}

				x = x / 10;
			}
		}
		else
		{
			while (x != 0)
			{
				if (INT_MIN / 10 > newX)
				{
					overflow = true;
					break;
				}
				else
				{
					newX = newX * 10;
				}

				if (INT_MIN - x % 10 > newX)
				{
					overflow = true;
					break;
				}
				else
				{
					newX = newX + x % 10;
				}

				x = x / 10;
			}
		}

		if (overflow)
			return 0;
		else
			return newX;
	}
};
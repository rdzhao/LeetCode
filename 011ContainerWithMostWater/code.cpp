class Solution {
public:
	int maxArea(vector<int>& height) {
		double volume = (height.size() - 1)*min(height[0], height[height.size() - 1]);

		int i = 0;
		int j = height.size() - 1;

		while (i != j)
		{
			if (height[i] > height[j])
			{
				j--;
			}
			else
			{
				i++;
			}

			if ((j - i)*min(height[i], height[j]) > volume)
				volume = (j - i)*min(height[i], height[j]);
		}


		return volume;
	}
};
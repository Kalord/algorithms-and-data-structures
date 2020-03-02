#include <vector>
#include <iostream>

std::vector<int> merge(std::vector<int> left, std::vector<int> right)
{
	std::vector<int> result;

	int l = 0;
	int r = 0;

	while(l < left.size() && r < right.size())
	{
		if(left[l] <= right[r])
		{
			result.push_back(left[l]);
			l++;
			continue;
		}
		result.push_back(right[r]);
		r++;
	}

	while(l < left.size())
	{
		result.push_back(left[l++]);
	}

	while(r < right.size())
	{
		result.push_back(right[r++]);
	}

	return result;
}

std::vector<int> mergeSort(std::vector<int> vect)
{
	if(vect.size() < 2) return vect;

	std::vector<int> left;
	std::vector<int> right;
	int mid = vect.size() / 2;

	int i = 0;
	
	while(i < mid)
	{
		left.push_back(vect[i++]);
	}

	while(i < vect.size())
	{
		right.push_back(vect[i++]);
	}

	return merge(mergeSort(left), mergeSort(right));
}

void render(const std::vector<int>& vect)
{
	for(const auto item : vect)
	{
		std::cout << item << ' ';
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> vect = {9, 8, 7, 6, 5, 4, 3, 2, 1};

	render(vect);
	std::vector<int> result = mergeSort(vect);
	render(result);

	return 0;
}

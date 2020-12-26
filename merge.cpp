#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n,m;

void printVector(string name, vector<int>& vec) {
    cout << name << " ";
    for (auto elem : vec)
        cout << elem << " ";
    cout << "\n";
}

vector<int> merge(vector<int> nums1, vector<int> nums2) {
	int m = nums1.size(), n = nums2.size();
    vector<int> result;
    int p1 = 0, p2 = 0;
    while(p1 < m || p2 < n)
    {
    	if(p2 == n)
    	{
    		result.push_back(nums1[p1]);
    		p1++;
    		continue;
		}
		if(p1 == m)
		{
			result.push_back(nums2[p2]);
			p2++;
			continue;			
		}
    	if(nums1[p1]<nums2[p2])
    	{
    		result.push_back(nums1[p1]);
    		p1++;
		}
		else
		{
			result.push_back(nums2[p2]);
			p2++;
		}
		
	}
    return result;
}

vector<int> mergesort(vector<int> nums)
{
	int n = nums.size();
	if(n == 1)
	{
		return nums;
	}
    int m = n/2;
    vector<int> left, right;
    for(int i = 0; i < m; i++)
    {
    	left.push_back(nums[i]);	 
	}
	for(int i = m; i < n; i++)
	{
		right.push_back(nums[i]);
	}
	return merge(mergesort(left), mergesort(right));
}

int main()
{
	int n, m;
	vector<int> input;
	cin >> n;
	while (n--) {
    	cin >> m;
    	input.push_back(m);
	}
	
	vector<int> result = mergesort(input);
	
	cout << "posortowane mergesortem:\n";
	printVector("wynik: ", result);
}

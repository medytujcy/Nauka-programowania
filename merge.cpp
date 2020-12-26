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
    //--------------------
    // DAWAJ MERGE TU POD SPODEM
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
	// TU WPISZ SWOJ KOD
	// POWIEDZMY, ZE MASZ JUZ NAPISANA FUNKCJE merge(vector<int> lewy vector<int> prawy)
	// KTORA LACZY DWA POSORTOWANE WEKTORY I ZWRACA JEDEN
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
//	merge(mergesort(left), mergesort(right));
	
	return merge(mergesort(left), mergesort(right));
}

int main()
{
    //cin>>n;
	vector<int> tab = vector<int>({7,8,11,23,1,4,7,12,53,5,88,14,5,9});
//	
//	
//	vector<int> result = merge(vector<int>({3,5,12,15}),
//							   vector<int>({6,11,27}));
//
//	cout << "zmergeowane:\n";
//	printVector("wynik: ", result);
	
//    while (n--) {
//    	cin>>m;
//    	tab.push_back(m);
//	}
	
	vector<int> result = mergesort(tab);
	
	cout << "posortowane mergesortem:\n";
	printVector("wynik: ", result);
}

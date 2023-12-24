#include <bits/stdc++.h>

std::vector<int> array{10, 20, 30, 40, 50, 60};
static std::vector<int> segTree(array.size()*4, -1);


int constructST(int ss, int se, int si)
{
	//base case or for the leaf nodes
	if(ss == se)
	{
		segTree[si] = array[ss];
		return array[ss];
	}
	
	int mid = (ss + se)/2;
	
	// sum of the left and right children for every internal nodes
	segTree[si] = constructST(ss, mid, 2*si+1) + constructST(mid+1, se, 2*si+2);
	
	// this return is for any internal up to root node
	return segTree[si];
}

int getSumRec(int qs, int qe, int ss, int se, int si)
{
	if(se < qs || ss > qe) return 0;
	if(ss >= qs && se <= qe) return segTree[si];
	int mid = (ss+se)/2;
	return getSumRec(qs, qe, ss, mid, 2*si+1) + getSumRec(qs, qe, mid+1, se, 2*si+2);
}

int main()
{
	
	int rootNode = constructST(0, array.size()-1, 0);
	std::cout << "RootNode: " << rootNode << std::endl;
//	for(int item : segTree)
//		std::cout << item << '\t' << std::endl;	
	int sum = getSumRec(2,5, 0, array.size()-1, 0);
	std::cout << sum << std::endl;
	
}
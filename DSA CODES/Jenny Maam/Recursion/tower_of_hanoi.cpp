#include <iostream>

void TOH(int n, char A, char B, char C)
{
	if(n > 0)
	{
		TOH(n-1, A, C, B);
		std::cout << "Move disk " << n << " From " << A << " to " << C << std::endl;
		TOH(n-1, B, A, C);
	}
}

int main()
{
	std::cout << "Enter the number of disks: ";
	int disk_n;
	std::cin >> disk_n;
	TOH(disk_n, 'A', 'B', 'C');
	return 0;
}
#include <iostream>
#include <vector>

main()
{
    std::vector<int> data = {15,5,20,35,2,42,97,17};
    int searchNum, j = 0;
    std::cout << "Enter the searching number: ";
    std::cin >> searchNum;
    auto i = data.begin();
    for(;i != data.end(); i++, j++)
    {
        if (searchNum == *i)
        std::cout << "Searching Found" << j;
    }
}
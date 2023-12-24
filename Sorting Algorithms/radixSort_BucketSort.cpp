#include <iostream>
#include <vector>

main()
{
    std::vector<int> data = {001, 002, 003, 004, 005};
    for(int i:data)
    {
        std::cout << i << std::endl;
    }
    
}
#include <iostream>
#include <ctime>
#include <cmath>

main()
{
    float x,y;
    clock_t time_req;
    time_req = clock();
    for(int i = 0; i < 1000; i++)
    {
        y = log(pow(i,5));
    }
    time_req = clock() - time_req;
    std::cout << (float)time_req/CLOCKS_PER_SEC << std::endl;

    time_req = clock();
	for(int i=0; i<100000; i++)
	{
		y = log(i*i*i*i*i);
	}
	time_req = clock()- time_req;
	std::cout << "Without using pow function, it took " << (float)time_req/CLOCKS_PER_SEC << " seconds" << std::endl;

	return 0;
}

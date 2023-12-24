#include <iostream>
#include <ctime>
#include <iostream>
using namespace std;
#include <fstream>

main()
{
    srand((unsigned) time(0));
    int randomNumber;
    ofstream file("arraydata.txt");

    for(int i = 0; i < 50; i++)
    {
        randomNumber = (rand()%100)+1;
        file << randomNumber << ", ";
    }
}
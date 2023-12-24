#include <iostream>
using namespace std;

int main()
{
    int arr[6] = {1,2,3,4,5};
    int pos = 3;
    int num = 10;
    bool turn = false;

    for (int i = 4; i >= 2; i--)
    {

      arr[i+1] = arr[i];
      if ( i == 2)
      {
          arr[i] = num;
      }
    }

    for(int i = 0; i < 6; i++)
    {
        cout << arr[i];
    }



}

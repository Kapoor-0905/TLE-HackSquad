#include <iostream>
#include <limits.h>
using namespace std;
int Max(int array[], int size)
{
    int maxi = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        maxi = max(maxi,array[i]);
        // if (array[i] > max)
        // {
        //     max = array[i];
        // }
    }
    return maxi;
}
int Min(int array[], int size)
{
    int min = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    return min;
}
int main()
{

    int size;
    cin >> size;
    int array[100];
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    cout << "Maximum Number " << Max(array, size) << "  " << endl;
    cout << "Minimum Number " << Min(array, size) << "  " << endl;
}

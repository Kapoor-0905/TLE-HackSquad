#include <iostream>
using namespace std;
void PrintArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
int main()
{
    int number[10] = {0};
    int size = sizeof(number) / sizeof(int);
    cout << size << endl;
    PrintArray(number, 10);
}

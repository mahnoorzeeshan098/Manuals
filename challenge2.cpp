#include <iostream>
using namespace std;

int main()
{
    int arr[10], i, smallest;

    // Taking 10 inputs from user
    cout << "Enter 10 numbers: " << endl;
    for(i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }

    // Assume first element as smallest
    smallest = arr[0];
for(i = 1; i < 10; i++)
    {
        if(arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }

    // Displaying smallest element
    cout << "Smallest number in the array is: " << smallest << endl;

    return 0;
}
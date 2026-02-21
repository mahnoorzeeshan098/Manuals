#include <iostream>
using namespace std;

int main() {
    int array[10];
    int largest;

    // Input array values
    for (int i = 0; i < 10; i++) {
        cout << "Enter number: ";
        cin >> array[i];
    }
     largest = array[0];
    for (int j = 1; j < 10; j++) {
        if (array[j] > largest)
            largest = array[j];
    }
     cout << "Largest Value = " << largest << endl;

    return 0;
}
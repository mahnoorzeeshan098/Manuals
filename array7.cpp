#include <iostream>
using namespace std;

int main() {
    int array[10];
    int n;

    // Input array values
    for (int i = 0; i < 10; i++) {
        cout << "Enter number: ";
        cin >> array[i];
    }
    cout << "Enter scalar number: ";
    cin >> n;

    // Display multiplied results
    cout << "\nNumber\tScalar Result\n";
    for (int j = 0; j < 10; j++) {
        cout << array[j] << "\t" << n * array[j] << endl;
    }

    return 0;
}
 #include <iostream>
#include <cmath>
using namespace std;

int main()
 {
    int n;
    cout << "Enter how many numbers you want to input: ";
    cin >> n;

    int num;
    int sum = 0;
    int maxNum;
    int minNum;
    int primecount = 0;
   int squarecount = 0;
    cout<<"Enter maximum number:";
    cin>>maxNum;
    cout<<endl<<"Enter the minimum number";
    cin>>minNum;

    for (int i = 1; i <= n; i++) {
        cout << "Enter number " << i << ": "<<endl;
        cin >> num;
        cout << "Pyramid for " << num <<endl;
        for (int r = 1; r <= num; r++) {
            for (int s = r; s < num; s++)
                cout << " ";
            for (int k = 1; k <= (2 * r - 1); k++)
                cout << "*";
            cout << endl;
        }
         sum = sum+num;
        if (num > maxNum)
        {
         maxNum = num;
        }
        if (num < minNum)
        {
         minNum = num;
        }
        bool isPrime = true;
        if (num < 2)
            isPrime = false;
        else {
            for (int j = 2; j <= sqrt(num); j++) 
            {
                if (num % j == 0) 
                {
                    isPrime = false;
                    break;
                }
            }
        }
        if (isPrime)
            primecount++;
        int root = sqrt(num);
        if (root * root == num)
            squarecount++;
    }

    double avg = (double)sum / n;

    
    cout << endl<<"            RESULTS         "<<endl;
    cout << "Sum = " << sum << endl;
    cout << "Average = " << avg << endl;
    cout << "Maximum = " << maxNum << endl;
    cout << "Minimum = " << minNum << endl;
    cout << "Number of Prime Numbers = " << primecount << endl;
    cout << "Number of Perfect Squares = " << squarecount << endl;
    

    return 0;
}

 
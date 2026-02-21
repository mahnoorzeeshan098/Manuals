 #include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter total number of students: ";
    cin >> n;

    int marks[100];  // assuming max 100 students
    int total = 0;
    int highest = 0;
    int lowest = 100;

    // Input marks
    for (int i = 0; i < n; i++) {
        cout << "Enter marks of student " << i + 1 << ": ";
        cin >> marks[i];
        total += marks[i];

        if (marks[i] > highest)
            highest = marks[i];
        if (marks[i] < lowest)
            lowest = marks[i];
    }

    // Calculate average
    double average = (double)total / n;

    // Count above average
    int countAbove = 0;
    for (int i = 0; i < n; i++) {
        if (marks[i] > average)
            countAbove++;
    }

    // Display results
    cout << "\nTotal Marks: " << total;
    cout << "\nAverage Marks: " << average;
    cout << "\nHighest Marks: " << highest;
    cout << "\nLowest Marks: " << lowest;
    cout << "\nNumber of students above average: " << countAbove << endl;

    // Display grades
    cout << "\nGrades of each student:\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << " (" << marks[i] << "): ";
        if (marks[i] >= 90)
            cout << "A";
        else if (marks[i] >= 80)
            cout << "B";
        else if (marks[i] >= 70)
            cout << "C";
        else if (marks[i] >= 60)
            cout << "D";
        else
            cout << "F";
        cout << endl;
    }

    return 0;
}











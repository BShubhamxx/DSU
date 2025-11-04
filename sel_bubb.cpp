#include <iostream>
using namespace std;

class Sorting {
    int marks[100], n;

public:
    void readMarks() {
        cout << "Enter number of students: ";
        cin >> n;
        cout << "Enter marks of " << n << " students:\n";
        for (int i = 0; i < n; i++)
            cin >> marks[i];
    }

    void display() {
        cout << "Student Marks: ";
        for (int i = 0; i < n; i++)
            cout << marks[i] << " ";
        cout << endl;
    }

    void bubbleSort() {
        int arr[100];
        for (int i = 0; i < n; i++) arr[i] = marks[i];

        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] < arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }

        cout << "\nMarks sorted (Bubble Sort - Descending):\n";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;

        topFive(arr);
    }

    void selectionSort() {
        int arr[100];
        for (int i = 0; i < n; i++) arr[i] = marks[i];

        for (int i = 0; i < n - 1; i++) {
            int maxIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[maxIndex])
                    maxIndex = j;
            }
            swap(arr[i], arr[maxIndex]);
        }

        cout << "\nMarks sorted (Selection Sort - Descending):\n";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;

        topFive(arr);
    }

    void topFive(int arr[]) {
        cout << "\nTop Scores:\n";
        int limit = (n < 5) ? n : 5;
        for (int i = 0; i < limit; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Sorting s;
    int choice;

    do {
        cout << "\n--- Sorting Operations ---\n";
        cout << "1. Read Marks\n";
        cout << "2. Display Marks\n";
        cout << "3. Bubble Sort\n";
        cout << "4. Selection Sort\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                s.readMarks();
                break;
            case 2:
                s.display();
                break;
            case 3:
                s.bubbleSort();
                break;
            case 4:
                s.selectionSort();
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}

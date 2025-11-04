#include <iostream>
using namespace std;

class Searching {
    int arr[100], n;

public:
    void readData() {
        cout << "Enter number of students: ";
        cin >> n;
        cout << "Enter roll numbers:\n";
        for (int i = 0; i < n; i++)
            cin >> arr[i];
    }

    void display() {
        cout << "Roll Numbers: ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void linearSearch(int key) {
        int i;
        for (i = 0; i < n; i++) {
            if (arr[i] == key) {
                cout << "Student found at position " << i + 1;
                cout << " with " << i + 1 << " comparisons.\n";
                return;
            }
        }
        cout << "Student not found! Comparisons: " << i << endl;
    }

    void sortArray() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j])
                    swap(arr[i], arr[j]);
            }
        }
    }

    void binarySearch(int key) {
        sortArray(); // ensure array is sorted
        int low = 0, high = n - 1, mid, count = 0;

        while (low <= high) {
            mid = (low + high) / 2;
            count++;
            if (arr[mid] == key) {
                cout << "Student found at position " << mid + 1;
                cout << " with " << count << " comparisons.\n";
                return;
            } else if (key > arr[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        cout << "Student not found! Comparisons: " << count << endl;
    }
};

int main() {
    Searching s;
    int choice, key;

    do {
        cout << "\n--- Search Operations ---\n";
        cout << "1. Read Roll Numbers\n";
        cout << "2. Display Roll Numbers\n";
        cout << "3. Linear Search\n";
        cout << "4. Binary Search\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                s.readData();
                break;
            case 2:
                s.display();
                break;
            case 3:
                cout << "Enter roll number to search: ";
                cin >> key;
                s.linearSearch(key);
                break;
            case 4:
                cout << "Enter roll number to search: ";
                cin >> key;
                s.binarySearch(key);
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

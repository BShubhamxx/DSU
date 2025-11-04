#include <iostream>
#include <limits>
using namespace std;

struct Student {
    int prn;
    string name, role;
    Student* next;
};

class PinnacleClub {
private:
    Student* headA;
    Student* headB;
    Student* mergedHead;

public:
    PinnacleClub() : headA(NULL), headB(NULL), mergedHead(NULL) {}

    // Function to create and return new student node
    Student* createNode(int prn, string name, int type) {
        Student* p = new Student;
        p->prn = prn;
        p->name = name;
        if (type == 1) p->role = "Regular";
        else if (type == 2) p->role = "President";
        else p->role = "Secretary";
        p->next = NULL;
        return p;
    }

    // Add student to specific division list
    void addStudent(Student*& head, int prn, string name, int type) {
        Student* p = createNode(prn, name, type);
        if (!head) {
            head = p;
            return;
        }

        if (p->role == "President") {
            if (head->role == "President") {
                cout << "\nPresident already exists!\n";
                delete p;
            } else {
                p->next = head;
                head = p;
            }
        } 
        else if (p->role == "Secretary") {
            Student* temp = head;
            while (temp->next && temp->next->role != "Secretary")
                temp = temp->next;
            if (temp->next && temp->next->role == "Secretary")
                cout << "\nSecretary already exists!\n";
            else
                temp->next = p;
        } 
        else { // Regular
            Student* temp = head;
            while (temp->next && temp->next->role != "Secretary")
                temp = temp->next;
            p->next = temp->next;
            temp->next = p;
        }
    }

    // Delete student by PRN
    void deleteStudent(Student*& head, int prn) {
        if (!head) {
            cout << "\nList Empty!\n";
            return;
        }

        Student *cur = head, *prev = NULL;
        while (cur && cur->prn != prn) {
            prev = cur;
            cur = cur->next;
        }
        if (!cur) {
            cout << "\nPRN not found!\n";
            return;
        }

        if (!prev)
            head = cur->next;
        else
            prev->next = cur->next;
        delete cur;
        cout << "\nStudent deleted successfully.\n";
    }

    // Display members
    void displayList(Student* head, string divName) {
        cout << "\n" << divName << " Members:\n";
        if (!head) {
            cout << "List Empty!\n";
            return;
        }
        while (head) {
            cout << "[" << head->prn << " | " << head->name << " | " << head->role << "] → ";
            head = head->next;
        }
        cout << "NULL\n";
    }

    // Count members
    int countMembers(Student* head) {
        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        return count;
    }

    // Merge both lists
    void mergeLists() {
        if (!headA && !headB) {
            cout << "\nBoth lists empty!\n";
            mergedHead = NULL;
            return;
        }
        if (!headA) mergedHead = headB;
        else if (!headB) mergedHead = headA;
        else {
            Student* temp = headA;
            while (temp->next) temp = temp->next;
            temp->next = headB;
            mergedHead = headA;
        }
        headA = headB = NULL;
        cout << "\nLists merged successfully!\n";
    }

    // Menu operations
    void menu() {
        int choice, prn, type, div;
        string name;

        do {
            cout << "\n===== Pinnacle Club Menu =====";
            cout << "\n1. Add Student";
            cout << "\n2. Delete Student";
            cout << "\n3. Display Lists";
            cout << "\n4. Count Members";
            cout << "\n5. Merge Divisions";
            cout << "\n6. Exit";
            cout << "\nEnter choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter PRN: "; cin >> prn;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter Name: "; getline(cin, name);
                    cout << "1-Regular, 2-President, 3-Secretary: "; cin >> type;
                    cout << "Division (1-A, 2-B): "; cin >> div;
                    if (div == 1) addStudent(headA, prn, name, type);
                    else addStudent(headB, prn, name, type);
                    break;

                case 2:
                    cout << "Enter PRN to delete: "; cin >> prn;
                    cout << "From which Division (1-A, 2-B): "; cin >> div;
                    if (div == 1) deleteStudent(headA, prn);
                    else deleteStudent(headB, prn);
                    break;

                case 3:
                    displayList(headA, "SY Div-A");
                    displayList(headB, "SY Div-B");
                    break;

                case 4:
                    cout << "\nCount A: " << countMembers(headA);
                    cout << "\nCount B: " << countMembers(headB) << endl;
                    break;

                case 5:
                    mergeLists();
                    displayList(mergedHead, "Merged SY List");
                    break;

                case 6:
                    cout << "\nExiting... Thank you!\n";
                    break;

                default:
                    cout << "\nInvalid Choice!\n";
            }

        } while (choice != 6);
    }
};

int main() {
    PinnacleClub club;
    club.menu();
    return 0;
}

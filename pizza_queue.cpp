#include <iostream>
using namespace std;

#define MAX 10  // Maximum queue size

struct Order {
    int id;        // Order ID
    int quantity;  // Number of pizzas
};

class CircularQueue {
private:
    Order queue[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % MAX == front;
    }

    void enqueue(int id, int qty) {
        if (isFull()) {
            cout << "\nQueue is full! Cannot accept more orders.\n";
            return;
        }
        if (front == -1)
            front = 0;
        rear = (rear + 1) % MAX;
        queue[rear].id = id;
        queue[rear].quantity = qty;
        cout << "\nOrder placed successfully! Order ID: " << id << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "\nNo orders to serve!\n";
            return;
        }
        cout << "\nServing Order ID: " << queue[front].id
             << " | Quantity: " << queue[front].quantity << endl;

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
    }

    void display() {
        if (isEmpty()) {
            cout << "\nNo pending orders.\n";
            return;
        }
        cout << "\nPending Orders:\n";
        int i = front;
        while (true) {
            cout << "[ID: " << queue[i].id << " | Qty: " << queue[i].quantity << "] ";
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

class PizzaParlor {
private:
    CircularQueue orders;
    int nextOrderID;

public:
    PizzaParlor() {
        nextOrderID = 1;
    }

    void takeOrder() {
        int qty;
        cout << "\nEnter number of pizzas: ";
        cin >> qty;
        orders.enqueue(nextOrderID++, qty);
    }

    void serveOrder() {
        orders.dequeue();
    }

    void showOrders() {
        orders.display();
    }
};

int main() {
    PizzaParlor parlor;
    int choice;

    do {
        cout << "\n========== Pizza Parlor Menu ==========\n";
        cout << "1. Take Order\n";
        cout << "2. Serve Order\n";
        cout << "3. View Pending Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                parlor.takeOrder();
                break;
            case 2:
                parlor.serveOrder();
                break;
            case 3:
                parlor.showOrders();
                break;
            case 4:
                cout << "\nThank you for using Pizza Parlor System!\n";
                break;
            default:
                cout << "\nInvalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}

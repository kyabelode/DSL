#include "bits/stdc++.h"
const int MAX = 100;
using namespace std;
class Deque {
public:
    int front = -1, rear = -1;
    int arr[MAX];
    int size = 0;

    bool isfull() {
        return size == MAX;
    }

    bool isempty() {
        return size == 0;
    }

    void insertfront(int x) {
            if (isempty()) {
                front = rear = 0;
            } else {
                front = (front - 1 + MAX) % MAX;
            }
            arr[front] = x;
            size++;
            cout << "Enqueued " << x << endl;
        
    }

    void insertrear(int x) {
            if (isempty()) {
                front = rear = 0;
            } else {
                rear = (rear + 1) % MAX;
            }
            arr[rear] = x;
            size++;
            cout << "Enqueued " << x << endl;
        
    }

    void deletefront() {
            cout << "Dequeued " << arr[front] << endl;
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % MAX;
            }
            size--;
    }

    void deleterear() {
            cout << "Dequeued " << arr[rear] << endl;
            if (front == rear) {
                front = rear = -1;
            } else {
                rear = (rear - 1 + MAX) % MAX;
            }
            size--;
    }

    void display() {
        if (isempty()) {
            cout << "Deque is empty." << endl;
            return;
        }
        int i = front;
        for (int count = 0; count < size; count++) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;
    int choice;

label:
    cout << "Enter your choice: " << endl;
    cout << "1: Insert at Front\n2: Insert at Rear\n3: Delete from Front\n4: Delete from Rear\n5: Display and Exit" << endl;

    cin >> choice;
    do {
        if (choice == 1) {
            int x;
            cin >> x;
            dq.insertfront(x);
            goto label;
        } else if (choice == 2) {
            int x;
            cin >> x;
            dq.insertrear(x);
            goto label;
        } else if (choice == 3) {
            dq.deletefront();
            dq.display();
            goto label;
        } else if (choice == 4) {
            dq.deleterear();
            dq.display();
            goto label;
        } else if (choice == 5) {
            dq.display();
            return 0;
        } else {
            cout << "Invalid choice! Try again." << endl;
            goto label;
        }
    } while (choice);

    return 0;
}

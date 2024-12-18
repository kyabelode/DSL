#include "iostream"
using namespace std;

struct Node {
    int prn;
    string name;
    Node *next;
    Node(int p, string s) : prn(p), name(s), next(NULL) {}
};

Node *addStudent(Node *head, int prn, string name) {
    Node *newNode = new Node(prn, name);
    newNode->next = head;
    return newNode;
}

bool search(Node *head, int prn) {
    Node *temp = head;
    while (temp != NULL) {
        if (temp->prn == prn) return true;
        temp = temp->next;
    }
    return false;
}

Node *intersection(Node *setA, Node *setB) {
    Node *result = NULL;
    Node *tempA = setA;
    while (tempA != NULL) {
        if (search(setB, tempA->prn)) {
            result = addStudent(result, tempA->prn, tempA->name);
        }
        tempA = tempA->next;
    }
    return result;
}

Node *unionSet(Node *setA, Node *setB) {
    Node *result = setA;
    Node *tempB = setB;
    while (tempB != NULL) {
        if (!search(setA, tempB->prn)) {
            result = addStudent(result, tempB->prn, tempB->name);
        }
        tempB = tempB->next;
    }
    return result;
}

Node *difference(Node *setA, Node *setB) {
    Node *result = NULL;
    Node *tempA = setA;
    while (tempA != NULL) {
        if (!search(setB, tempA->prn)) {
            result = addStudent(result, tempA->prn, tempA->name);
        }
        tempA = tempA->next;
    }
    return result;
}

int countStudents(Node *head) {
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void display(Node *head) {
    Node *temp = head;
    if (head == NULL) {
        cout << "No students" << endl;
        return;
    }
    while (temp != NULL) {
        cout << "PRN: " << temp->prn << ", Name: " << temp->name << endl;
        temp = temp->next;
    }
}

int main() {
    Node *setA = NULL, *setB = NULL;
    int choice;

    do {
        cout << "1.Add Student to Set A (Vanilla Ice-Cream)" << endl;
        cout << "2.Add Student to Set B (Butterscotch Ice-Cream)" << endl;
        cout << "3.Display Students who like both Vanilla and Butterscotch" << endl;
        cout << "4.Display Students who like either Vanilla or Butterscotch but not both" << endl;
        cout << "5.Display Number of Students who like neither Vanilla nor Butterscotch" << endl;
        cout << "6.Exit" << endl;
        cout << "Enter your choice:" << endl;
        cin >> choice;

        if (choice == 1) {
            int prn;
            string name;
            cout << "Enter PRN and Name of student who likes Vanilla" << endl;
            cin >> prn >> name;
            setA = addStudent(setA, prn, name);
        } else if (choice == 2) {
            int prn;
            string name;
            cout << "Enter PRN and Name of student who likes Butterscotch" << endl;
            cin >> prn >> name;
            setB = addStudent(setB, prn, name);
        } else if (choice == 3) {
            Node *both = intersection(setA, setB);
            cout << "Students who like both Vanilla and Butterscotch:" << endl;
            display(both);
        } else if (choice == 4) {
            Node *either = unionSet(setA, setB);
            Node *both = intersection(setA, setB);
            Node *eitherButNotBoth = difference(either, both);
            cout << "Students who like either Vanilla or Butterscotch but not both:" << endl;
            display(eitherButNotBoth);
        } else if (choice == 5) {
            int totalStudents = countStudents(setA) + countStudents(setB);
            Node *either = unionSet(setA, setB);
            int neither = totalStudents - countStudents(either);
            cout << "Number of students who like neither Vanilla nor Butterscotch: " << neither << endl;
        }

    } while (choice != 6);

    return 0;
}

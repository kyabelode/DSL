#include "bits/stdc++.h"
using namespace std;
struct Node{
    int prn;
    string name;
    Node *next;
    Node(int p,string s):prn(p),name(s),next(NULL){}
};
Node *addPresident(Node *head,int roll,string nav){
    Node *newNode = new Node(roll,nav);
    newNode->next = head;
    return newNode;
}
Node* addSecretory(Node *head,int roll,string nav){
   Node *newNode = new Node(roll,nav);
   if(head == NULL){
    return newNode;
   }
   Node *temp = head;
   while(temp->next!=NULL){
     temp = temp->next;
   }
   temp->next = newNode;
   newNode->next = NULL;
   return head;
}
Node *deletePresident(Node *head){
    Node *temp = head;
    if(head == NULL){
        cout<<"List is empty";
    }
    head = head->next;
    delete temp;
    return head;
}
Node *deleteSecretory(Node *head){
    if(head == NULL || head->next == NULL){
        cout<<"Cant delete the list is already empty";
    }
    Node *temp = head;
    while (temp->next->next!=NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}
Node *Concatenate(Node *head1 , Node *head2){
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    Node *temp = head1;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = head2;
    return head1; 
}
int Traversal(Node *head){
    int size = 0;
    Node *temp = head;
    while(temp!=NULL){
        size++;
        temp = temp->next;
    }
    return size;
}
void DisplayLL(Node *head) {
    if (head == NULL) {
        cout << "No one is there" << endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL) {
        cout << "PRN: " << temp->prn << ", Name: " << temp->name << endl;
        temp = temp->next;
    }
}
int main() {
    Node *Div1 = NULL;
    Node *Div2 = NULL;
    Node *CombinedList = NULL;  
    int choice;
    do {
        cout << "Welcome to Pinnacle Club" << endl;
        cout << "Enter your choice :" << endl;
        cout << "1.Add President\n2.Add Secretory\n3.Delete President\n4.Delete Secretory\n5.Concatenate\n6.Display\n7.Exit" << endl;
        cin >> choice;

        if (choice == 1) {
            cout << "Select Division\n1.Div1\n2.Div2" << endl;
            int Div;
            cin >> Div;
            cout << "Enter the roll and name of the President" << endl;
            int roll;
            string name;
            cin >> roll >> name;
            if (Div == 1) {
                Div1 = addPresident(Div1, roll, name);
            } else if (Div == 2) {
                Div2 = addPresident(Div2, roll, name);
            }
        } else if (choice == 2) {
            cout << "Select Division\n1.Div1\n2.Div2" << endl;
            int Div;
            cin >> Div;
            cout << "Enter the roll and name of the Secretory" << endl;
            int roll;
            string name;
            cin >> roll >> name;
            if (Div == 1) {
                Div1 = addSecretory(Div1, roll, name);
            } else if (Div == 2) {
                Div2 = addSecretory(Div2, roll, name);
            }
        } else if (choice == 3) {
            cout << "Select Division\n1.Div1\n2.Div2" << endl;
            int Div;
            cin >> Div;
            if (Div == 1) {
                Div1 = deletePresident(Div1);
            } else if (Div == 2) {
                Div2 = deletePresident(Div2);
            }
        } else if (choice == 4) {
            cout << "Select Division\n1.Div1\n2.Div2" << endl;
            int Div;
            cin >> Div;
            if (Div == 1) {
                Div1 = deleteSecretory(Div1);
            } else if (Div == 2) {
                Div2 = deleteSecretory(Div2);
            }
        } else if (choice == 5) {
            CombinedList = Concatenate(Div1, Div2);  // Store the concatenated list here
            cout << "Two divisions combined" << endl;
        } else if (choice == 6) {
            cout << "Select Division\n1.Div1\n2.Div2\n3.Concatenated List" << endl;
            int Div;
            cin >> Div;
            if (Div == 1) {
                DisplayLL(Div1);
            } else if (Div == 2) {
                DisplayLL(Div2);
            } else if (Div == 3) {
                DisplayLL(CombinedList);  // Display the concatenated list
            }
        }
    } while (choice != 7);

    return 0;
}

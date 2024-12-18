#include "bits/stdc++.h"
typedef long long ll;
using namespace std;
const int MAX = 100;
class Queue{
    public :
    int front = 0,rear = -1;
    int size = 0;
    vector<pair<string,int>>Pizza;
    Queue(){
        Pizza.resize(MAX+1);
    }
    bool isfull(){
        return size == MAX;
    }
    bool isempty(){
        return size == 0;
    }
    void enqueue(string x,int y){
        if(!isfull()){
            rear=(rear+1)%MAX;
            Pizza[rear] = {x,y};
            size++;
            cout<<"the Enqueued Pizza is "<<x<<" of cost "<<y<<endl;
        }
        else{
            cout<<"Queue is full"<<endl;
            return;
        }
    }
    void dequeue(){
        if(!isempty()){
            front = (front + 1)%MAX;
            size--;
            cout<<"Order Deleted"<<endl;
        }
    }
    void display(){
        for(int i = 0;i<size;i++){
            cout<<"item : "<<Pizza[i].first<<" of cost "<<Pizza[i].second;
            cout<<endl;
        }
        cout<<endl;   
    }
};
int main(){
    Queue q;
    int choice;
    label :
    cout<<"Enter the opeartion you want to do"<<endl;
    cout<<"\n1.Add a Pizza to Order  \n2.Delete from cart \n3.Display oreders \n4.confirm and exit"<<endl;
    cin>>choice;
    do
    {
        if (choice == 1)
        {
            string s;int k;
            cout<<"Enter the name of Pizza and cost"<<'\n';
            cin>>s>>k;
            q.enqueue(s,k);
            goto label;
        }
        else if(choice==2){
            q.dequeue();
            goto label;
        }
        else if (choice ==3){
            q.display();
            goto label;
        }
        else if(choice == 4){
            break;
            return 0;
        }
        else{
            goto label;
        }
    } while (choice);
}
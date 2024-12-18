#include "bits/stdc++.h"
typedef long long ll;
using namespace std;

const int MAX = 100;
class Queue{
    public :
    int front = 0,rear = -1;
    int size = 0;
    vector<pair<pair<string,string>,ll>>Job;
    Queue(){
        Job.resize(MAX+1);
    }
    bool isfull(){
        return size == MAX;
    }
    bool isempty(){
        return size == 0;
    }
    void enqueue(string x,string y,ll z){
        if(!isfull()){
            rear=(rear+1)%MAX;
            Job[rear].first={x,y};
            Job[rear].second={z};
            size++;
            cout<<"the Enqueued Job is "<<x<<" of id "<<y<<" of salary "<<z<<endl;
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
            cout<<"I made him jobless"<<endl;
        }
    }
    void display(){
        for(int i = 0;i<size;i++){
            cout<<"Job : "<<Job[i].first.first<<"id : "<<Job[i].first.second<<"salary : "<<Job[i].second;
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
    cout<<"\n1.Add a new Job \n2. Delete a Job \n3.Display the Job \n4.exit"<<endl;
    cin>>choice;
    do
    {
        if (choice == 1)
        {
            string s,j;
            ll k;
            cout<<"Enter the Name of the Job id  and salary"<<'\n';
            cin>>s>>j;
            cin>>k;
            q.enqueue(s,j,k);
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
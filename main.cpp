#include <iostream>
#include <new>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int x,Node* n){
        data=x;
        next=n;}};
class Queue{
private:
    Node* front;
    Node* back;
    int c;
public:
    Queue(){
        front=nullptr;
        back=nullptr;
        c=0;}
    void enqueue(int x){
        Node* node=new Node(x,nullptr);
        if(back==nullptr){
            front=back=node;}
        else{
            back->next=node;
            back=node;}
        c++;}
    void dequeue(){
        if(front==nullptr){
            cout<<"Queue is empty."<<endl;
            return;}
        Node* node=front;
        front=front->next;
        delete node;
        c--;
        if(front==nullptr){back=nullptr;}}
    int top(){
        if(front==nullptr){
            cout<<"Queue is empty."<<endl;
            return -1;}
        return front->data;}
    int getSize(){return c;}
    bool isEmpty(){return (front==nullptr);}};
class Stack{
private:
    Node* top;
    int c;
public:
    Stack(){
        top=nullptr;
        c=0;}
    void push(int x){
        Node* node=new Node(x,top);
        top=node;
        c++;}
    void pop(){
        if(isEmpty()){
            cout<<"Stack is empty."<<endl;
            return;}
        Node* node=top;
        top=top->next;
        delete node;
        c--;}
    int getTop(){
        if(isEmpty()){
            cout<<"Stack is empty."<<endl;
            return -1;}
        return top->data;}
    int getSize(){return c;}
    bool isEmpty(){return top==nullptr;}};
int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout<<"Queue's size: "<<q.getSize()<<endl;
    cout<<"Queue's top element: "<<q.top()<<endl;
    q.dequeue();
    cout<<"Queue's size: "<<q.getSize()<<endl;
    cout<<"Queue's top element: "<<q.top()<<endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    if(q.isEmpty()){cout<<"Queue is empty."<<endl;}
    else{cout<<"Queue is nonempty."<<endl;}
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<"Stack's size: "<<s.getSize()<<endl;
    cout<<"Stack's top element: "<<s.getTop()<<endl;
    s.pop();
    cout<<"Stack's size: "<<s.getSize()<<endl;
    cout<<"Stack's top element: "<<s.getTop()<<endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    if(s.isEmpty()){cout<<"Stack is empty."<<endl;}
    else{cout<<"Stack is nonempty."<<endl;}

    return 0;
}
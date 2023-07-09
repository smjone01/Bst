#include<bits/stdc++.h>
using namespace std;

// binary tree so 2 pointers
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

void insert(Node* root,int data){
    // int data;
    // cin>>data;
    if(data!=-1){
        Node *inserted = new Node(data);
        if(data<root->data){
            if(root->left==NULL){
                root->left=inserted;
                return;
            }
            insert(root->left,data);
        }
        if(data>=root->data){
            if(root->right==NULL){
                root->right=inserted;
                return;
            }
            insert(root->right,data);
        }
    }
}

void levelorderTraversal_tree(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    Node* temp = q.front();
    while(!q.empty()){
        if(q.front()==NULL){
            cout<<endl;
            q.push(NULL);
            q.pop();
        }
        temp=q.front();
        if(temp==NULL){
            break;
        }
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int data;
    cout<<"Enter the root's data"<< endl;
    cin>>data;
    Node* root=new Node(data);
    root->left=NULL;
    root->right=NULL;
    for(int i=0;i<5;i++){
        int data;
        cin>>data;
        insert(root,data);
    }
    levelorderTraversal_tree(root);
    return 0;
}
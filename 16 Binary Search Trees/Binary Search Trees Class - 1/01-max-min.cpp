#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node*left;
        Node*right;
        Node(int val){
            this->data = val;
            left = NULL;
            right = NULL;
        }
};

// O(logn) to insert a node
Node* buildBST(int val, Node* root){
    if(root == NULL){
        root = new Node(val);
        return root;
    }
    else{
        if(val < root->data){
            // val-> left subtree
            root->left = buildBST(val,root->left);
        }
        else{
            // val-> right subtree
            root->right = buildBST(val,root->right);
        }
    }
    return root;
}

// preorder
void preOrderTraversal(Node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// inorder
void inOrderTraversal(Node* root){
    if(root == NULL) return;
    
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// postorder
void postOrderTraversal(Node* root){
    if(root == NULL) return;
    
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

Node* createTree(){
    cout << "Enter the value for node: "<< endl;
    int val;
    cin>>val;
    Node* root = NULL;
    while(val != -1){
        root = buildBST(val, root);
        cout << "Enter the value for node: "<< endl;
        // int val;
        cin>>val;
    }
    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        if(front == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<< front->data << " ";
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
    }
}


int getMin(Node* root){
    if(root == NULL) return -1;
    while(root->left != NULL){
        root = root->left;
    }
    // reached root extreme left
    return root->data;
}

int getMax(Node* root){
    if(root == NULL) return -1;
    while(root->right != NULL){
        root = root->right;
    }
    // reached root extreme right
    return root->data;
}

int main(){
    // Node* root = NULL;
    Node* root = createTree();
    cout<<"printing level order: "<<endl;
    levelOrderTraversal(root);
    cout<<"printing pre order: "<<endl;
    preOrderTraversal(root);
    cout<<endl<<"printing in order: "<<endl;
    inOrderTraversal(root);
    cout<<endl<<"printing post order: "<<endl;
    postOrderTraversal(root);
    cout<<endl;
    cout<<"MIN element "<<getMin(root)<<endl;
    cout<<"MAX element "<<getMax(root)<<endl;
    return 0;
}
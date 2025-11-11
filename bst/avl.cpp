#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        int height;

        Node(int x){
            data = x;
            height = 1;
            left = nullptr;
            right = nullptr;
        }
};

class AVL{
    Node* root = nullptr;

    int heightAVL(Node* root){
        if(root == NULL){
            return 0;
        }
        return root->height;
    }

    int getBalanceFactor(Node* node){
        if(node == NULL){
            return 0;
        }
        return heightAVL(node->left) - heightAVL(node->right);
    }

    Node* rightRotate(Node* node){
        Node* curr = node->left;
        Node* currRight = curr->right;

        node->left = currRight;
        curr->right = node;

        curr->height = 1 + max(heightAVL(curr->left),heightAVL(curr->right));
        node->height = 1 + max(heightAVL(node->left),heightAVL(node->right));

        return curr;
    }

    Node* leftRotate(Node* node){
        Node* curr = node->right;
        Node* currLeft = curr->left;

        node->right = currLeft;
        curr->left = node;

        curr->height = 1+ max(heightAVL(curr->left),heightAVL(curr->right));
        node->height = 1+ max(heightAVL(node->left),heightAVL(node->right));

        return curr;
    }

    Node* insertAVL(Node* root,int x){
        if(root == NULL){
            return new Node(x);
        }
        else if(root->data >= x){
            root->left = insertAVL(root->left,x);
        }
        else if(root->data < x){
            root->right = insertAVL(root->right,x);
        }

        root->height = 1 + max(heightAVL(root->left),heightAVL(root->right));

        int balanceFactor = getBalanceFactor(root);

        if(balanceFactor>1 && x<root->left->data){
            //left left
            return rightRotate(root);
        }
        else if(balanceFactor>1 && x>root->left->data){
            //left right
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        else if(balanceFactor < -1 && x<root->right->data){
            //right left
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        else if(balanceFactor < -1 && x>root->right->data){
            //right right
            return leftRotate(root);
        }

        return root;
    }

    void inorder(Node* root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
        return;
    }

    void breadthFirst(Node* root){
            if(root == NULL){
                return;
            }
            queue<Node*> q;
            Node* temp = root;
            q.push(temp);
            while(!q.empty()){
                Node* frontNode = q.front();
                q.pop();
                cout<<frontNode->data<<" ";
                if(frontNode->left != NULL){
                    q.push(frontNode->left);
                }
                if(frontNode->right != NULL){
                    q.push(frontNode->right);
                }
            }
            return;
        }


    public:
        AVL(int x){
            root = new Node(x);
            return;
        }

        void insert(int x){
            root = insertAVL(root,x);
        }

        void inorderPrint(){
            inorder(root);
            return;
        }

        void print(){
            breadthFirst(root);
            return;
        }
    
};

int main(){
    AVL* root = new AVL(5);

    root->insert(30);
    root->insert(20);
    root->insert(40);
    root->insert(73);

    root->print();
    cout<<endl;

    return 0;
}
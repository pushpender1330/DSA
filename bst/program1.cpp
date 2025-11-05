#include <iostream>
#include <climits>
#include <queue>
using namespace std;

class Node{
    public:
        int data;
        Node* right;
        Node* left;
        Node(int x){
            data = x;
            right = nullptr;
            left = nullptr;
        }
};

class BST{
    private:
        Node* root = nullptr;

        Node* insertBST(Node* root,int x){
            if(root == NULL){
                return new Node(x);
            }

            else if(root->data >= x){
                root->left = insertBST(root->left,x);
            }
            else{
                root->right = insertBST(root->right,x);
            }
            return root;
        }

        void printBST(Node* root){
            if(root == NULL){
                return;
            }
            cout<<root->data<<" ";
            printBST(root->left);
            printBST(root->right);
            return;
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
        void preorder(Node* root){
            if(root == NULL){
                return;
            }
            cout<<root->data<<" ";
            inorder(root->left);
            inorder(root->right);
            return;
        }
        void postorder(Node* root){
            if(root == NULL){
                return;
            }
            inorder(root->left);
            inorder(root->right);
            cout<<root->data<<" ";
            return;
        }

        //use queue (fifo)
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

        int heightBST(Node* root){
            if(root == NULL){
                return -1;
            }
            int leftHeight = 1+heightBST(root->left);
            int rightHeight = 1+heightBST(root->right);

            if(leftHeight > rightHeight){
                return leftHeight;
            }
            return rightHeight;
        }

        bool checkBST(Node* root,int min, int max){
            if(root == NULL){
                return true;
            }
            return root->data>min && root->data<=max && checkBST(root->left,min,root->data) && checkBST(root->right,root->data,max);
        }

        Node* deleteBST(Node* root,int x){
            if(root == NULL){
                return NULL;
            }
            else if(root->data > x){
                root->left = deleteBST(root->left,x);
            }
            else if(root->data < x){
                root->right = deleteBST(root->right,x);
            }
            else{
                if(root->left == NULL && root->right == NULL){
                    delete root;
                    return NULL;
                }
                else if(root->left == NULL){
                    Node* temp = root->right;
                    delete root;
                    return temp;
                }
                else if(root->right == NULL){
                    Node* temp = root->left;
                    delete root;
                    return temp;
                }
                else{
                    Node* rightNode = root->right;

                    //find min from right subtree;
                    while(rightNode->left != NULL){
                        rightNode = rightNode->left;
                    }
                    
                    root->data = rightNode->data;
                    root->right = deleteBST(root->right,rightNode->data);
                }
            }
            return root;
        }
         
    
    public:
        BST(){
            root = nullptr;
        }

        void insert(int x){
            root = insertBST(root,x);
            return;
        }

        void deleteNode(int x){
            root = deleteBST(root,x);
            return;
        }

        int findMin(){
            Node* temp = root;
            if(temp == NULL){
                cout<<"bst is empty\n";
                return -1;
            }
            while(temp->left != NULL){
                temp = temp->left;
            }
            return temp->data;
        }

        int findMax(){
            Node* temp = root;
            if(temp == NULL){
                cout<<"bst is empty\n";
                return -1;
            }
            while(temp->right != NULL){
                temp = temp->right;
            }
            return temp->data;
        }

        int height(){
            return heightBST(root);
        }

        void print(){
            printBST(root);
            cout<<endl;
            return;
        }

        //depth first traversal
        void inorderTraversal(){
            inorder(root);
            cout<<endl;
            return;
        }
        void preTraversal(){
            preorder(root);
            cout<<endl;
            return;
        }
        void postTraversal(){
            postorder(root);
            cout<<endl;
            return;
        }

        //breadth first traversal
        void breadthFirstTraversal(){
            breadthFirst(root);
            cout<<endl;
            return;
        }

        
        bool isBST(){
            return checkBST(root,INT_MIN,INT_MAX);
        }
    };



int main(){
    BST b = BST();

    b.insert(5);
    b.insert(23);
    b.insert(55);
    b.insert(9);
    b.insert(45);

    b.print();

    b.insert(22);
    b.insert(2);
    b.insert(22);

    cout<<endl;
    b.print();

    cout<<endl;

    cout<<(b.findMin())<<endl;
    cout<<(b.findMax())<<endl;

    cout<<(b.height())<<endl;

    cout<<endl;

    b.breadthFirstTraversal();
    b.inorderTraversal();
    b.preTraversal();
    b.postTraversal();
    cout<<endl;

    b.deleteNode(9);
    cout<<"---------------------------\n";
    b.breadthFirstTraversal();
    b.inorderTraversal();
    b.preTraversal();
    b.postTraversal();
    cout<<endl;

    cout<<b.isBST();
    cout<<endl;
    

    return 0;
}
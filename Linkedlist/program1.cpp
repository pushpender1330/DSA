#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void insertBeg(int data, Node **head)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    return;
}

void insertEnd(int data, Node **head)
{
    if (*head == NULL)
    {
        (*head)->data = data;
        (*head)->next = nullptr;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    temp->next = newNode;
    return;
}

void insert(int data, int posi, Node **head)
{
    if (posi <= 0)
    {
        cout << "cannot insert at position " << posi << endl;
        return;
    }

    if (posi == 1)
    {
        insertBeg(data, head);
        return;
    }
    Node *temp = *head;

    for (int i = 2; i < posi; i++)
    {
        if (temp->next == NULL)
        {
            cout << "cannot insert at position " << posi << endl;
            return;
        }
        temp = temp->next;
    }

    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
    return;
}

void deleteBeg(Node **head)
{

    if (*head == nullptr)
    {
        cout << "List is already empty";
        return;
    }

    Node *temp = *head;
    (*head) = (*head)->next;
    delete temp;
    return;
}

void deleteEnd(Node **head)
{
    if (*head == NULL)
    {
        cout << "List is already empty";
        return;
    }
    if ((*head)->next == NULL)
    {
        *head = NULL;
        return;
    }

    Node *temp = *head;
    while ((temp->next)->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next->next;
    temp->next = NULL;
}

void deleteNode(int posi, Node **head)
{
    if (*head == NULL)
    {
        cout << "List is already empty";
        return;
    }
    if (posi <= 0)
    {
        cout << "cannot delete at position " << posi << endl;
        return;
    }
    if (posi == 1)
    {
        deleteBeg(head);
        return;
    }
    Node *temp = *head;
    for (int i = 2; i < posi; i++)
    {
        temp = temp->next;
        if (temp->next == NULL)
        {
            cout << "cannot delete at position " << posi << endl;
            return;
        }
    }

    if (temp->next == NULL)
    {
        cout << "cannot delete at position " << posi << endl;
        return;
    }

    Node *delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
    return;
}

int linearSearch(int key, Node *head)
{
    int posi = 1;
    if (head == NULL)
    {
        cout << "List is empty";
        return -1;
    }

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return posi;
        }
        posi++;
        temp = temp->next;
    }

    return -1;
}

int listLength(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

Node *ReverseList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *prev = nullptr;
    Node *curr = head;
    Node *nexxt = curr->next;  

    while (curr != NULL)
    {
        curr->next = prev;
        prev = curr;
        if (nexxt == NULL)
        {
            return curr;
        }
        curr = nexxt;
        nexxt = nexxt->next;
    }
    return curr;
}

Node* MiddleElement(Node *head)
{
    if (head == NULL)
    {
        return nullptr;
    }
    if (head->next == NULL)
    {
        return head;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

bool detectCycle(Node *head)
{
    // Floyd’s Cycle Detection algorithm
    if (head == NULL || head->next == NULL)
    {
        return false;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

Node* detectCycleNode(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return nullptr;
    }
    Node *slow = head;
    Node *fast = head;
    bool isCycle = false;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            isCycle = true;
            break;
        }
    }

    if (!isCycle)
    {
        return nullptr;
    }

    Node *temp = head;
    while (temp != slow)
    {
        temp = temp->next;
        slow = slow->next;
    }
    return temp;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


// recursive solution
void printRecursive(Node* head){
    if(head == NULL){
        cout<<endl;
        return;
    }
    cout<<head->data<<" ";
    return printRecursive(head->next);
}

void reverseRecursive(Node* head,Node** start){
    if(head == NULL || head->next == NULL){
        *start = head;
        return;
    }

    reverseRecursive(head->next,start);

    head->next->next = head;
    head->next = NULL;
    return;
}

int main()
{
    Node *head = new Node();

    head = NULL;
    insertBeg(736, &head);

    // head = insertBeg(5,head);
    // head = insertBeg(15,head);
    // head = insertBeg(89,head);

    insertBeg(5, &head);
    insertBeg(89, &head);
    insertEnd(15, &head);
    insertEnd(25, &head);
    insertEnd(88, &head);
    insertEnd(45, &head);
    insert(283, 1, &head);

    deleteBeg(&head);
    // deleteBeg(&head);
    // deleteBeg(&head);
    // deleteBeg(&head);
    // deleteEnd(&head);
    // deleteEnd(&head);
    deleteEnd(&head);

    deleteNode(3, &head);
    // deleteNode(2,&head);
    // deleteNode(2,&head);
    // deleteNode(2,&head);
    // deleteNode(1,&head);
    // deleteNode(1,&head);

    printRecursive(head);
    printList(head);

    cout << linearSearch(6, head) << endl;
    cout << linearSearch(89, head) << endl;

    cout << listLength(head) << endl;

    // head = ReverseList(head);

    reverseRecursive(head,&head);

    printRecursive(head);
    printList(head);

    // cout << MiddleElement(head) << endl;

    cout << detectCycle(head) << endl;

    cout << endl;
    return 0;
}

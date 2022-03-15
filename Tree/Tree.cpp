#include<iostream>
using namespace std;

struct TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
};

class BST
{
    public:
    TreeNode* root = NULL;
bool isEmpty()
{
    if(root == NULL)
        return true;
    else    
        return false;
}

void insertTnode()
{
    TreeNode* newNode = new TreeNode();
    cout<<"Enter the value of the node: ";
    cin>> newNode->data;
    if(root == NULL)
        {
            root = newNode;
        cout<<"Node inserted as a root" <<endl;
        }
   else
    {
        TreeNode* temp0 = root;
        while(temp0 != NULL)
        {
            if(newNode->data == temp0->data)
                {
                    cout << "Duplicate values are not allowed" <<endl;
                    return;
                }

            else if(newNode->data < temp0->data && temp0->left == NULL)
                {
                    temp0->left = newNode;
                    cout<<"Node added to the left." <<endl; 
                    break;
                }
            else if(newNode->data < temp0->data)
                temp0 = temp0->left;

            else if(newNode->data > temp0->data && temp0->right == NULL)
                {
                    temp0->right = newNode;
                    cout<<"Node added to the right." <<endl; 
                    break;
                }
            else if(newNode->data > temp0->data)
                temp0 = temp0->right;
        }
    }
    
}

void printPreOrder(TreeNode* temp)
{
    if(temp == NULL)
        return;
    else
    {
        cout<<temp->data << " ";
        printPreOrder(temp->left);
        printPreOrder(temp->right);
    }
    
}

void printInOrder(TreeNode* temp)
{
    if(temp == NULL)
        return;
    else
        {
            printInOrder(temp->left);
            cout<<temp->data <<" ";
            printInOrder(temp->right);
        }
}

void printPostOrder(TreeNode* temp)
{
    if(temp == NULL)
        return;
    else
    {
      printPostOrder(temp->left);
      printPostOrder(temp->right);
      cout<<temp->data <<" ";
    }
}

TreeNode* search(int num)
{
 TreeNode* temp = root;
 if(temp == NULL) 
    return NULL;
 else
    {
        while(temp != NULL)
        {
            if(num == temp->data)
                    return temp;
            else if(num < temp->data)
                    temp = temp->left;
            else
                temp = temp->right;     
        }
    return NULL;
    }
 }

 TreeNode* minValueNode(TreeNode* ptr)
    {
        TreeNode* temp = ptr;
        while(temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }

TreeNode* deleteNode(TreeNode* ptr,int num)
    {
        if(ptr == NULL)
            return NULL;
        else if(num < ptr->data)
            ptr->left = deleteNode(ptr->left, num);
        else if(num > ptr->data)
            ptr->right = deleteNode(ptr->right, num);
        else
            {
                if(ptr->left == NULL)
                    {
                        TreeNode* temp = ptr->right;
                        delete ptr;
                        return temp;
                    }
                else if(ptr->right == NULL)
                    {
                        TreeNode* temp = ptr->left;
                        delete ptr;
                        return temp;
                    }
                else
                    {
                        TreeNode* temp = minValueNode(ptr->right);
                        ptr->data = temp->data;
                        ptr->right = deleteNode(ptr->right, temp->data);
                    }
            }
            return ptr;
    }


};

int main()
{
    BST bst;
    int option;
    do
{
        cout<<endl;
        cout<<"1. Press 1 to insert nodes into the BST.          2. Press 2 to search for a particular node." <<endl; 
        cout<<"3. Press 3 to delete nodes in the BST.            4. Press 4 to print the nodes in the BST." <<endl;
        cout<<"5. Press 5 to clear the screen.                   6. Press 0 to Exit." <<endl;                                    
        cout<<"Enter here: ";
        cin>>option;
        int num, numd;
    TreeNode* ptr = new TreeNode();
    TreeNode* ptr2 = new TreeNode();
    switch(option)
  {
    case 0:
    break;

    case 1:
    bst.insertTnode();
    break;

    case 2:
    cout<< "Enter the value of the node you want to find: ";
    cin>>num;
    ptr = bst.search(num);
    if(ptr == NULL)
        cout<<"Node not found!" <<endl;
    else
        cout<<"Node found."<<endl;
    break;

    case 3:
    cout<<"Enter the value of the node you want to delete: ";
    cin>>numd;
    ptr2 = bst.search(numd);
    if(ptr2 != NULL)
        {
            bst.deleteNode(bst.root, numd);
            cout<<"Node deleted."<<endl;
        }
    else
        {
            cout<<"Node not found" <<endl;
        }
    break;

    case 4:
    cout<<"Pre-Order: ";
    bst.printPreOrder(bst.root);
    cout<<endl;
    cout<<"In-Order: ";
    bst.printInOrder(bst.root);
    cout<<endl;
    cout<<"Post-Order: ";
    bst.printPostOrder(bst.root);
    cout<<endl;
    break;

    case 5:
    system("cls");
    break;
  }
}
    while(option != 0);
    

return 0;
}
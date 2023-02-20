#include <iostream>
#include <string>
#include <Queue>
#include <cassert>
using namespace std;
struct node
{
    int item;
    node *left;
    node *right;
};
class Tree
{
public:
    Tree()
    {
        root = NULL;
    };
    bool IsEmpty()
    {
        return (root == NULL);
    }
    void insert(int item) // inserting data to the tree
    {
        node *curr;     // pointer to traverse
        node *tailcurr; // pointer behind the curr
        node *newnode;  // pointer to create a new node
        newnode = new node;
        if (newnode != NULL)
        {
            newnode->item = item;
            newnode->left = NULL;
            newnode->right = NULL;
            if (root == NULL)
            {
                root = newnode;
            }
            else
            {
                curr = root;
                while (curr != NULL)
                {
                    tailcurr = curr;
                    if (curr->item == item)
                    {
                        cout << "The insert item is already in the list -- ";
                        cout << "duplicates are not allowed." << endl;
                        return;
                    }
                    else if (curr->item > item)
                    {
                        curr = curr->left;
                    }
                    else
                    {
                        curr = curr->right;
                    }
                }
                if (tailcurr->item > item)
                {
                    tailcurr->left = newnode;
                }
                else
                {
                    tailcurr->right = newnode;
                }
            }
        }
    }
    void remove(int item) // removing data from tree
    {
        node *curr;     // pointer to traverse the tree
        node *tailcurr; // pointer behind current

        if (root == NULL)
        {
            cout << "Cannot delete from the empty tree." << endl;
            return;
        }
        if (root->item == item)
        {
            deleteFromTree(root);
            return;
        }
        // if you get here, then the item to be deleted is not the root
        tailcurr = root;

        if (root->item > item)
            curr = root->left;
        else
            curr = root->right;

        // search for the item to be deleted.
        while (curr != NULL)
        {
            if (curr->item == item)
                break;
            else
            {
                tailcurr = curr;
                if (curr->item > item)
                    curr = curr->left;
                else
                    curr = curr->right;
            }
        } // once the while is done, current points to either NULL or to the node to be deleted

        if (curr == NULL)
            cout << "The delete item is not in the tree." << endl;
        else if (tailcurr->item > item)
            deleteFromTree(tailcurr->left);
        else
            deleteFromTree(tailcurr->right);
    }
    bool search(int item) // search the itwm is in the tree or not
    {
        node *curr = root;

        while (curr != NULL)
        {
            if (curr->item == item)
                return true;
            else if (curr->item > item)
                curr = curr->left;
            else
                curr = curr->right;
        }
        return false;
    }
    void LevelOrderTraversal()
    {
        LevelOrder(root);
    }
    void PreOrderTraversal()
    {
        preOrder(root);
    }
    void InOrderTraversal()
    {
        inOrder(root);
    }
    void PostOrderTraversal()
    {
        postOrder(root);
    }

private:
    node *root;
    void LevelOrder(node *root)
    {
        if (root == NULL)
            return;
        queue<node *> Q;
        Q.push(root);
        while (!Q.empty())
        {
            node *cur = Q.front();
            cout << cur->item << " ";
            if (cur->left != NULL)
                Q.push(cur->left);
            if (cur->right != NULL)
                Q.push(cur->right);
            Q.pop();
        }
    }
    void preOrder(node *root)
    {
        while (root != NULL)
        {
            cout << root->item << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
        cout << endl;
    }
    void inOrder(node *root)
    {
        while (root != NULL)
        {
            inOrder(root->left);
            cout << root->item << " ";
            inOrder(root->right);
        }
    }
    void postOrder(node *root)
    {
        while (root != NULL)
        {
            inOrder(root->left);
            inOrder(root->right);
            cout << root->item << " ";
        }
    }
    void clear(node *ptr)
    {
        node *cur = ptr;
    }
    void deleteFromTree(node *&ptr)
    {
        node *curr;     // pointer to traverse
        node *tailcurr; // pointer behind the curr
        node *temp;     // pointer to delete a new node

        if (ptr->left == NULL && ptr->right == NULL)
        {
            delete ptr;
            ptr = NULL;
        }
        else if (ptr->left == NULL)
        {
            temp = ptr;
            ptr = ptr->right;
            delete temp;
        }
        else if (ptr->right == NULL)
        {
            temp = ptr;
            ptr = ptr->left;
            delete temp;
        }
        else
        {
            curr = ptr->left;
            tailcurr = NULL;
            while (curr->right != NULL)
            {
                tailcurr = curr;
                curr = curr->right;
            } // end while
            ptr->item = curr->item;
            if (tailcurr == NULL) // current did not move;
                                  // current == p->left; adjust p
                ptr->left = curr->left;
            else
                tailcurr->right = curr->left;
            delete curr;
        } // end else
    }     // end deleteFromTree
};
int main()
{
    Tree x;
    x.insert(10);
    x.insert(5);
    x.insert(20);
    x.insert(7);
    x.insert(3);
    x.insert(25);
    x.insert(23);
    x.PreOrderTraversal();
    // x.InOrderTraversal();
    // x.PostOrderTraversal();
    // x.remove(23);
    // x.search(5);
    // x.PreOrderTraversal();
    return 0;
}

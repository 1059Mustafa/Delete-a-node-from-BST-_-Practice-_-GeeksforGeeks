// Return the root of the modified BST after deleting the node with value X
Node *deleteNode(Node *root,  int x)
{
   if (root == NULL) 
    return NULL;

    if (x > root->data) 
    {
        root->right = deleteNode(root->right, x);
    }
    else if (x < root->data) 
    {
        root->left = deleteNode(root->left, x);
    }
    else 
    {
        if (!root->right) 
        {
            Node* temp = root->left;
            delete root; return temp;
        }
        else if (!root->left) 
        {
            Node* temp = root->right;
            delete root; return temp;
        }
        else 
        {
            Node *parent, *child;
            parent = child = root->left;
    
            int count = 0;
            while (child->right)
            {
                parent = child;
                child = child->right;
                count++;
            }
    
            root->data = child->data;
    
            if (count == 0) 
            {
                root->left = deleteNode(root->left, parent->data);
            }
            else 
            {
                parent->right = child->left;
                delete child;
            }
        }
    }
    return root;
}

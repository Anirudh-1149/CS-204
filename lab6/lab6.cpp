#include<bits/stdc++.h> 
using namespace std; 
int maxi[2];
struct Node{
	int key;  
	int amount;
    Node *left;  
    Node *right;  
    int height;
};

int max(int p, int q)  
{  
    return (p > q)? p : q;  
}  

int height(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return N->height;  
}

Node* newNode(int key,int amount)  
{  
    Node* node = new Node(); 
    node->key = key;  
    node->amount = amount;
    if(amount>maxi[0])
    {
        maxi[0] = amount;
        maxi[1] = key;
    }
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1;
    return(node);  
}  

Node *rightRotate(Node *y)  
{  
    Node *x = y->left;  
    Node *p = x->right;    
    x->right = y;  
    y->left = p; 
    y->height = max(height(y->left), height(y->right)) + 1;  
    x->height = max(height(x->left), height(x->right)) + 1;  
    return x;  
}  

Node *leftRotate(Node *x)  
{  
    Node *y = x->right;  
    Node *p = y->left;    
    y->left = x;  
    x->right = p;  
    x->height = max(height(x->left), height(x->right)) + 1;  
    y->height = max(height(y->left), height(y->right)) + 1;   
    return y;  
}  

int Isbalanced(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return height(N->left) - height(N->right);  
}  

Node* insert(Node* node, int key,int amount)  
{  
    if (node == NULL)  
        return(newNode(key,amount));  
  
    if (key < node->key)  
        node->left = insert(node->left, key,amount);  
    else if (key > node->key)  
        node->right = insert(node->right, key,amount);  
    else if(key == node->key){
        node->amount+=amount;
        if(node->amount > maxi[0]){
            maxi[0] = node->amount;
            maxi[1] = node->key;
        }
    }

    node->height = 1 + max(height(node->left),  
                        height(node->right));  
  
    int bal = Isbalanced(node);  
  
    if (bal > 1 && key < node->left->key)  
        return rightRotate(node);  
  
    if (bal < -1 && key > node->right->key)  
        return leftRotate(node);  
    if (bal> 1 && key > node->left->key)  
    {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
    if (bal < -1 && key < node->right->key)  
    {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
    return node;  
}  

int main()
{
	Node*ptr = NULL;
	int n;
	cin>>n;
    int T;
    cin>>T;
	while(T--){
		int opp;
		cin>>opp;
		if(opp==1)
		{
			int key,amount;
			cin>>key>>amount;
			ptr = insert(ptr,key,amount);
		}
	
    else
        if(maxi[0] == 0)
            cout<<"No data available"<<"\n";
        else
            cout<<maxi[1]<<"\n";
    }
	return 0;
}

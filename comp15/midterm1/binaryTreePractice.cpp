#include<iostream>
using namespace std; 

struct Node{
    Node* right;
    Node* left;
    int data;
};

 int main()
{
    Node* tree = build123();

 }

Node* build123()
{

    Node* temp = newNode( 2 );

    temp->left = nowNode( 3 );
    temp->right = newNode( 1 );
    
    return temp;
}

Node* newNode( int data )
{
    Node* temp = new Node;
}

int size( Node* node )
{
    if( node == NULL ){
	return 0;
    }

    else{
	return size(node->left) + size(node->right) + 1;
    }
}

int maxDepth(Node* node)
{
    if( node == NULL ){
	return 0;
    }

    else
    {
	if( maxDepth(node->left) > maxDepth(node->right) )
	{
	    return maxDepth(node->left) + 1 ;
	}
	if( size(node->right) > size(node->left) )
	{
	    return maxDepth(node->right) + 1 ;
	}
    }
}   


    
 
  
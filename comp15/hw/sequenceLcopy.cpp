typedef char ElementType;
#include "sequenceL.h"

sequence::sequence()
{
    head = NULL;
}

sequence::sequence( ElementType x )
{
    Node* nodeX = new Node;
    nodeX->value = x;
    nodeX->next = NULL;
    head = nodeX;
}

int sequence::size()
{
    Node* temp;
    temp = head;
    int length;
    
    for( int i = 0; temp != NULL; i++){
	temp = temp->next;
	length++;
    }
    
    return length;
}

bool sequence::isEmpty()
{
    if( head == NULL ){
	return true;
    }
    
    else{
	return false;
    }
    
}

void sequence::concatenate( sequence* sequenceAdded )
{
    cerr << "before assignment " << endl;
    
    Node* temp1;
    Node* temp2;
    temp1 = head;
    temp2 = sequenceAdded;
    
    
    cerr << "start concatenate " << endl;
    
    if ( sequenceAdded == NULL )
    {
	return;
    }
    
    while( temp1->next != NULL )
    {
	temp1 = temp1->next;
    }
    
    for( int i = 0; temp2->next != NULL ; i++ )
    {
	temp1->next = new Node;
	temp1->next->value = temp2->value;
	temp2 = temp2->next;
	temp1 = temp1->next;
    }
    
    
    cerr << " end concatenate " << endl;
    
    
    
    
}

ElementType sequence::first()
{
    return head->value;
}


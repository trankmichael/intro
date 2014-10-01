#include "ll.h"
#include "node.h"
#include <iostream>

using namespace std;

LL::LL()
{
	head = NULL;
}
	
LL::LL(int *arr, int size)
{
	head = NULL;
	for (int i = 0; i < size; i++) {
		insert(arr[i]);
	}
}

LL::~LL()
{
	Node* temp = head;
	while (temp != NULL) {
		temp = temp->next;
		delete head;
		head = head->next;
	} 
}

LL::LL(const LL &to_copy)
{
        if (to_copy.head != NULL) {
                Node *temp = to_copy.head;
                Node *copied = new Node;
                copied->value = temp->value;
                copied->next = NULL;
                head = copied;
                temp = temp->next;
                while (temp != NULL) {
                        copied->next = new Node;
                        copied = copied->next;
                        copied->value = temp->value;
                        copied->next = NULL;
                        temp = temp->next;
                }
        }
}

void LL::insert(int x)
{
	Node* insert = new Node;
	insert->value = x;
	insert->next = NULL;

	if (head == NULL) {
		head = insert;
		return;
	}

	if (x < head->value) {
		insert->next = head;
		head = insert;
		return;
	}
	else
	{	
		Node* temp = head;
		Node* temp2 = head->next;
		while (temp2 != NULL && temp2->value < x) {
			temp2 = temp2->next;
			temp = temp->next;
		}
		insert->next = temp2;
		temp->next = insert;
	}
}

void LL::print()
{
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

void LL::merge(LL to_merge)
{
    Node* temp1 = head;
    Node* temp2 = to_merge.head;
    Node* temp3;

    if( temp1 == NULL ){
	head = new Node;
	temp1 = head;
    	while( temp2 != NULL ){
		temp1->next = new NOde;
		temp1->value = temp2->value;
		temp2 = temp2->next;
    	}
	return;
    }
    else if( temp2 == NULL ){
	return;
    }
    while( temp1 != NULL )
    {
	while( temp2 != NULL )
	{
	    if(( temp2->value <= temp1-> value ) && ( temp1 == head ))
	    {
		head = new NODE;
		head->value = temp2->value;
		head->next = temp1;
		temp2 = temp2->next;
	    }
	    if(( temp2->value >= temp1->value ) && (temp1->next == NULL ))
	    {
		temp1->next = new Node;
		temp1->next->value = temp2->value;
		temp1->next->next = NULL;
		temp2 = temp2->next;
	    }
	    if(( temp2->value >= temp1->value ) && (temp2->value < 
						    temp1->next->value)){
	        temp3 = new Node;
	   	temp3->next = temp1->next;
	    	temp3->value = temp2->value;
		temp2 = temp2->next
	    }
	    temp1 = temp1->next;
	}
	return;
	    
    }

}

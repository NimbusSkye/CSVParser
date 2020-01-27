// Yufeng Wang 260855204

#include <stdlib.h>
#include <stdio.h>

// Create struct for Node
struct NODE {
       int number;	
       float balance;
       struct NODE *next;
};

// Create head of the linked list
struct NODE *head = NULL;

void addNode (int account, float amount) {
        struct NODE *new = (struct NODE *)malloc(sizeof(struct NODE));
        if (new == NULL) {
                puts("Fatal error. Now exiting.");
                exit(2);
        }
        new->number=account;
        new->balance=amount;
        // Add the new node, otherwise initialize the head and make it point to the new node
        if (head != NULL) {
                new->next=head->next;
                head->next = new;
        }
        else {
                head = (struct NODE *)malloc(sizeof(struct NODE));
                head->next=new;
        }
        return;
        // Return pointer to the new node
}


// Function that updates the List 
void findUpdate (int account, float amount) {
	// Check if the list exists
	if (head == NULL) {
		addNode(account, amount);
		return;
	}
	struct NODE *temp = head;
	// Protect the head pointer by making a copy of it
	while (temp->number != account) {
		if (temp->next==NULL) {
			addNode(account , amount);
			return;
		}
		temp=temp->next;
	}
	// Iterate through the list until a matching account is found or if the end is reached
	temp->balance = amount;
	return;
}

// Function that prints the List in a pretty way
void prettyPrint ( ) { 
	// Create temporally var for the current information
	struct NODE *nodeC = head->next; 
	int accountC;
	float balanceC;
	// loop that goes until end of list
	while (nodeC != NULL) {
		// set temporally variables to the balance and accounr
		accountC = nodeC->number;
		balanceC = nodeC->balance;
		// Print the information 
		printf("%s%d%s%.2f\n","ACCOUNT ID: ",accountC,"  BALANCE: $ ",balanceC);
		// Go to next NODE
		nodeC = nodeC -> next; 
	}

}

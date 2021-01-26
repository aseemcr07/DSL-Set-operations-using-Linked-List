#include<iostream>
using namespace std;

class node{
    public:
        int rollnum;
        node* next;

        node(int r){
            rollnum = r;
            next = NULL;
        }
};

void insertAtTail(node* &head, int roll){

    node* n = new node(roll);

    if(head == NULL){
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;

}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->rollnum<<", ";
        temp = temp->next;
    }
}

int totalCount(node* head){

    int count = 0;

    node* temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

bool isPresent(node* head, int data){
    node* t = head;
    while(t != NULL){
        if(t->rollnum == data){
            return 1;
        }
        t = t->next;
    }
    return 0;
}

node* getUnion(node* head1, node* head2){
    node* result = NULL;
    node* t1 = head1;
    node* t2 = head2;

    while(t1 != NULL){
        insertAtTail(result, t1->rollnum);
        t1 = t1->next;
    } 

    while(t2 != NULL){
        if(!isPresent(result, t2->rollnum)){
            insertAtTail(result, t2->rollnum);
        }
        t2 = t2->next;
    }

    return result;
}

node* getIntersection(node* head1, node* head2){
    node* result = NULL;
    node* t1 = head1;

    while(t1 != NULL){
        if(isPresent(head2, t1->rollnum)){
            insertAtTail(result, t1->rollnum);
        }
        t1 = t1->next;
    }

    return result;
}

node* eitherNotBoth(node* head1, node* head2){
    node* result = NULL;
    node* t1 = head1;

    while(t1 != NULL){
        if(!isPresent(head2, t1->rollnum)){
            insertAtTail(result, t1->rollnum);
        }
        t1 = t1->next;
    }

    return result;
}

int main(){
    node* headA = NULL;
    node* headB = NULL;
    node* headUniversal = NULL;
    node* AorB = NULL;
    node* AandB = NULL;
    node* AnorB = NULL;
    node* AorBnotAndB = NULL;

    int rollnum, numA, numB, numUniversal;

    cout<<"Enter total number of students in class: ";
    cin>>numUniversal;
    for(int i=0; i<numUniversal; i++){
        cout<<"Enter roll number of student: ";
        cin>>rollnum;
        insertAtTail(headUniversal, rollnum);
    }
    cout<<"Total students: ";
    display(headUniversal);

    cout<<"\nEnter number of students of set A (Vanilla): ";
    cin>>numA;

    for(int i=0; i<numA; i++){
        cout<<"Enter roll number of student: ";
        cin>>rollnum;
        insertAtTail(headA, rollnum);
    } 
    cout<<"Set A: ";
    display(headA);

    cout<<"\nEnter number of students of set B (Butterscotch): ";
    cin>>numB;

    for(int i=0; i<numB; i++){
        cout<<"Enter roll number of student: ";
        cin>>rollnum;
        insertAtTail(headB, rollnum);
    } 
    cout<<"Set B: ";
    display(headB);

    AorB = getUnion(headA, headB);
    AandB = getIntersection(headA, headB);
    AorBnotAndB = eitherNotBoth(AorB, AandB);
    AnorB = eitherNotBoth(headUniversal, AorB);
    int n = totalCount(AnorB);

    int flag = 1;
    int ch;

    while(flag){
        cout<<"\n----- MENU ------\n";
        cout<<"1. Set of students who like both vanilla and butterscotch\n";
        cout<<"2. Set of students who like either vanilla or butterscotch but not both\n";
        cout<<"3. Number of students who like neither vanilla nor butterscotch\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice (1/2/3/4): "; 
        cin>>ch;

        switch(ch){
            case 1: cout<<"Set of students who like both: ";
                    display(AandB);
                    cout<<endl;
                    break;

            case 2: cout<<"Set of students who like either vanilla or butterscotch but not both: ";
                    display(AorBnotAndB);
                    cout<<endl;
                    break;

            case 3: cout<<"Number of students who like neither vanilla nor butterscotch: "<<n<<endl;
                    break;

            case 4: cout<<"Exited!\n";
                    flag = 0;
                    break;

            default:    cout<<"Incorrect choice entered!\n";
                        break;
                    
        }
    }

    return 0;
}

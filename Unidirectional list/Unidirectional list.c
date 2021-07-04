//Matveev Igor

#include <stdio.h>
#include <stdlib.h>
typedef struct _node {
    int a;
    struct _node *next;
} node;


node *create_list (void){
    node *head, *list1, *list2;
    head = NULL;
    int IN1 = 0, IN = 1, i = 1;                 //IN1 - first number that user input in list, IN - other numbers that user input in list, i - counter elements.
    printf ("element #%d:", i);
    scanf("%d", &IN1);
    if (IN1){                                   //Check that list not empty
        head = (node*)malloc(sizeof(node));     //Create first list's element
        if (head == NULL){
            printf ("head - fall\n");
            return NULL;
        };
        (head -> a) = IN1;                      //First element filling
        list1 = head;                           //Next element
        while (IN){                             //list filling process
            i++;                                //Element's counter
            printf ("element #%d:", i);
            scanf ("%d", &IN);                  //Scan number
            if(!IN) {                           //Check that it is not end of list
                (list1 -> next) = NULL;
                return head;
            }
            list2 = (node*)malloc(sizeof(node));//Create i list's element
            if (list2 == NULL) {
                printf ("List2 - fall");
                return NULL;
            }
            (list2 -> a) = IN;                  //i element filling
            (list1 -> next) = list2;            //Next i+1 element
            list1 = list2;                      //Refresh pointer
        }
   }
   else head = NULL;
return head;
}

void print_list (node *head){
    node *list1, *list2;                            //Pointers
    int i = 1;                                      //Counter
    printf ("\nList:\n");
    if (head != NULL){                              //Check that list not empty
        list1 = (head);
        while ((list1)!= NULL){;                    //While next element on list not NULL
            printf ("#%d:   %d\n", i, (list1 -> a));//Display list's element
            list2 = (list1->next);                  //Refresh pointer
            list1 = list2;                          //Refresh pointer
            i++;                                    //Refresh counter
        }
    }
    else printf ("Empty\n");
};

void delete_list (node *head){
    node *list1, *list2;                        //Pointers
    int i = 1;                                  //Counter
    if (head != NULL){                          //Check that list not empty
        list1 = (head -> next);                 //Refresh pointer on second element
        free(head);                             //Delete first element
        while (list1 != NULL){                  //While next element on list not NULL
            list2 = (list1 -> next);            //Refresh pointer on next element
            free (list1);                       //Delete element
            list1 = list2;                      //Refresh pointer on next element
            i++;                                //Refresh counter
        }
    }
    else i=0;
    printf ("\nList with %d element (s) was deleted.\n", i);
};

int main (void) {
    node *head;
    head = create_list ();
    print_list(head);
    delete_list (head);
    return 0;
}

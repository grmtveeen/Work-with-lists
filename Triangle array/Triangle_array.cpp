#include<iostream>
#include<fstream>
using namespace std;

#define len 9

class MASS {
public:
    int stroka;
    int all_stroks;
    int *mass;
    MASS *next;
};

void write (int i, int j, int x, MASS *golova){ //Function for writing (i,j) element
    if(golova!=0){
        if ((i<=(golova->all_stroks)) && (i>=j)){
            MASS *n, *c;
            int k=1;
            c=golova;
            while (i>k++){
                n=c->next;
                c=n;
            }k=1;
            c->mass[j]=x;
        }
        else cout << "You can't go out MASS, element " << i << " " << j << " not found." <<endl;
    }
}

void zeros (MASS *golova){ //Function for initialisation array to zeros
    if(golova!=0){
        MASS *n, *c;
        int j=1, i=1;
        c=golova;
        while (c){
            while (j<=(c->stroka)) {
                write (i, j++, 0, golova);
            }
            ++i, j=1;
            n=c->next;
            c=n;
        }
    }
}

MASS *create (int lim=10){//Function for creating an array of the desired length (lim)
    MASS *golova, *n, *c;
    if(lim>0){
        golova = new MASS;
        int r=1;
        golova -> stroka = 1;
        golova -> next=0;
        golova -> mass = new int;
        golova -> all_stroks = lim;
        c=golova;
        while (lim>=++r){
            n = new MASS;
            n->mass = new int[r];
            n->stroka=r;
            c->next = n;
            c = n;
            c->next=0;
        };
    zeros (golova);
    }
    else golova = 0;
    return golova;
}

void read (int i, int j, MASS *golova){ //Function for reading (i,j) element
    if(golova!=0){
        if ((i<=(golova->all_stroks)) && (i>=j) && golova!=0){
            MASS *n, *c;
            int k=1;
            c=golova;
            while (i>k++){
                n=c->next;
                c=n;
            }k=1;
            cout << "Element " << '(' << i << ',' << j << ')' << ' ' << c->mass[j] << endl;
        }
        else cout << "You can't go out MASS, element " << i << " " << j << " not found." <<endl;
    }
}

void write_all (MASS *golova){ //Function for writing all elements in array to: element = i*10 + j
    if(golova!=0){
        MASS *n, *c;
        int j=1;
        c=golova;
        while (c){
            while ((c->stroka)>=j){
                c->mass[j]=(c->stroka)*10+(j);
                j++;
            }j=1;
            n=c->next;
            c=n;
        }
    }
}

void read_all (MASS *golova) { //Function for cout all elements in array
    if(golova!=0){
        MASS *n, *c;
        int j=1;
        c=golova;
        while (c){
            while ((c->stroka)>=j){
                cout << c->mass[j++] << " ";
            }j=1;
            n=c->next;
            c=n;
            cout << endl;
        }
    }
}

void _delete (MASS *golova){ //Function for deleting array
    if (golova!=0){
        MASS *n, *c;
        c=golova;
            while (!c){
                n=c->next;
                delete c;
                delete n->mass;
                c=n;
            };
        }
}

int main (void){
    MASS *A;
    A = create(len);
    write_all(A);
    write (5,4,1000,A);
    read (8,4,A);
    read_all (A);
    _delete (A);
    return 0;
}

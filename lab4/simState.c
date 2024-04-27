#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
/*
State machine:
A A F
B D C
C H A
D A B
E C H
F G E
G E D
H B G

Starting state is: C
*/

//for every state in the machine
typedef struct {//typedef gives an existing datatype a "nickname"
    char letter;
    char zero;
    char one;
}state;
//whole statemachine
typedef struct {
    state states[8];
    char current;
}statemachine;

//initializing whole statemachine into predefined states
void initializeSM(statemachine *sm){
    //state A
    state stateA={'A', 'A', 'F'};
    sm->states[0]=stateA;
    //state B
    state stateB={'B', 'D', 'C'};
    sm->states[1]=stateB;
    //state C
    state stateC={'C', 'H', 'A'};
    sm->states[2]=stateC;
    //state D
    state stateD={'D', 'A', 'B'};
    sm->states[3]=stateD;
    //state E
    state stateE={'E', 'C', 'H'};
    sm->states[4]=stateE;
    //state F
    state stateF={'F', 'G', 'E'};
    sm->states[5]=stateF;
    //state G
    state stateG={'G', 'E', 'D'};
    sm->states[6]=stateG;
    //state H
    state stateH={'H', 'B', 'G'};
    sm->states[7]=stateH;
    //sets the current state to 'C'
    sm->current='C';
}
/*METHODS: printCurrentState, change, print, garbage, delete1, delete2*/
//zero input
void zero(statemachine *sm){
    //gets index of the current state
    int currentstate=sm->current-'A';//A has a ASCII value of 65, B has a value of 66 and so on

    //gets next state for zero input
    char nextstate=sm->states[currentstate].zero;
    sm->current=nextstate;//updates current state

    //prints out current state
    printf("%c\n", nextstate);
}

//one input
void one(statemachine *sm){
    //gets index of the current state
    int currentstate=sm->current-'A';//A has a ASCII value of 65, B has a value of 66 and so on

    //gets index of the current state
    char nextstate = sm->states[currentstate].one;
    sm->current = nextstate;//updates current state

    //prints out current state
    printf("%c\n", nextstate);
}

//print the current state of the state machine including the start state
void printCurrentState(statemachine *sm)
{
    fprintf(stderr, "Current state: %c\n", sm->current);
}

//change method that changes the next state of the current state either by 0 or 1 e.g. say current state is B and we do c 0 C, then when input is 0 B changes state to C instead of what it was previously
void change(statemachine *sm, char input, char state){
    int currentstate=sm->current-'A';//current state's index
    if (input=='0'){
        sm->states[currentstate].zero=state; //sets the current state's new "0 next state"
    }
    else if (input=='1'){
        sm->states[currentstate].one=state; //sets the current state's new "1 next state"
    }
}

//print method that prints out the whole state machine
void print(statemachine *sm){
    for (int i=0;i<8;i++){

        if (sm->states[i].letter!=' '){//avoids the deleted ones that i set as ' '
        fprintf(stderr, "%c %c %c\n", sm->states[i].letter, sm->states[i].zero, sm->states[i].one);//prints out the state from A to H
        }

        if (sm->states[i].zero==sm->states[i+1].zero && sm->states[i].one==sm->states[i+1].one){
            i++; //skip printing the next state if it is the same as the current state
        }
    }
}

//garbage method that shows unreachable states
void garbage(statemachine *sm){
    int reachable[8]={0};//array of reachable states
    int stack[8]={0};//array as stack
    int top=0;//set the top of the stack to 0
    stack[top++]=sm->current-'A';//add the index of the current state to the stack

    while (top > 0) {
        int current=stack[--top]; //pops top element

        if (!reachable[current]) {//if current state is not already reachable
            reachable[current]=1; // set the current state as reachable (1)

            //pushes any reachable "next states" to the stack
            if (sm->states[current].zero!=' ') {
                stack[top++]=sm->states[current].zero-'A';
            }
            if (sm->states[current].one!=' ') {
                stack[top++]=sm->states[current].one-'A';
            }
        }
    }

    int hasGarbage=0;
    //loops through state machine
    for (int i=0;i<8;i++) {
        //if state isnt reachable it gets printed out
        if (!reachable[i] && sm->states[i].letter!=' ') {//if its unreachable and not null/' '
            hasGarbage=1;
            fprintf(stderr, "Garbage: %c\n", sm->states[i].letter);
        }
    }
    //if all states are reachable then prints no garbage
    if (!hasGarbage) {
        fprintf(stderr, "No Garbage.\n");
    }
}

//delete method which deletes the entire state for a null input
void delete1(statemachine *sm, char *state)
{
    int reachable[8]={0};//array of reachable states
    int stack[8]={0};//array as stack
    int top=0;//set the top of the stack to 0
    stack[top++]=sm->current-'A';//add the index of the current state to the stack

    while (top > 0) {
        int current=stack[--top];//pops top element

        if (!reachable[current]) {//if current state is not already reachable
            reachable[current]=1;//set the current state as reachable (1)

            //pushes any reachable "next states" to the stack
            if (sm->states[current].zero!=' ') {
                stack[top++]=sm->states[current].zero-'A';
            }
            if (sm->states[current].one!=' ') {
                stack[top++]=sm->states[current].one-'A';
            }
        }
    }

    //if d is alone or null input
    if (state==NULL){

        int deleted=0;
        for (int i=0;i<8;i++){
            if (!reachable[i] && sm->states[i].letter!=' ') {
                deleted=1;
                fprintf(stderr, "Deleted: %c\n", sm->states[i].letter);//prints deleted state

                // deletes the garbage state by setting each index to a blank character
                sm->states[i].letter=' ';
                sm->states[i].zero=' ';
                sm->states[i].one=' ';
            }
        }
        // if all states are reachable then prints not deleted
        if (!deleted) {
            fprintf(stderr, "no states deleted\n");
        }
    }


}

//delete method which deletes the entire state for a state input
void delete2(statemachine *sm, char *state)
{
    int reachable[8]={0};//array of reachable states
    int stack[8]={0};//array as stack
    int top=0;//set the top of the stack to 0
    stack[top++]=sm->current-'A';//add the index of the current state to the stack

    while (top>0) {
        int current=stack[--top]; //pops top element

        if (!reachable[current]) {//if current state is not already reachable
            reachable[current]=1; // set the current state as reachable (1)

            //pushes any reachable "next states" to the stack
            if (sm->states[current].zero!=' ') {
                stack[top++]=sm->states[current].zero-'A';
            }
            if (sm->states[current].one!=' ') {
                stack[top++]=sm->states[current].one-'A';
            }
        }
    }

    // Check if the inputted state is valid
    int index=state[0]-'A'; // Convert the state character to an integer
    if (index<0||index>7)
    {
        fprintf(stderr,"Not deleted.\n");
        return;
    }

    // If the inputted state is unreachable, delete it
    if (!reachable[index])
    {
        printf("Deleted.\n"); //prints that the state is deleted
        //setting each to an empty space
        sm->states[index].letter=' ';
        sm->states[index].zero=' ';
        sm->states[index].one=' ';
    }
    else
    {
        fprintf(stderr, "Not deleted.\n"); // Print that the state is not deleted
    }
}


int main(int argc, char * argv[])
{
    statemachine sm;
    initializeSM(&sm);//initializes sm
    printCurrentState(&sm);//prints current state
    char input, cArg1, cArg2, bArg;
    bool loop=true;

    while (loop)
    {
        scanf("%c", &input);
        switch (input)
        {
        case '0'://zero state
            zero(&sm);
            break;
        case '1'://one state
            one(&sm);
            break;
        case 'c'://change
            scanf(" %c %c", &cArg1, &cArg2);
            change(&sm, cArg1, cArg2);
            break;
        case 'p'://print out whole sm
            print(&sm);
            break;
        case 'g'://garbage
            garbage(&sm);
            break;
        case 'b'://deletes specific state, idk how to fix this and this is the closest ive gotten
            scanf(" %c", &bArg);
            delete2(&sm, &bArg);
            break;
        case 'd'://deletes everything that is unreachable
            delete1 (&sm, NULL);
        default:
            break;
        }
    }
    exit(0);
}


/*
 * This file contains the representation for a single node in the 2x2x2 cube graph
 */
struct node {
	//state representation  goes here
	int perm[8];
	int oren[8];
};

//perm -> array containing numbers from 1-8 representing the position of each piece
//perm[0]->piece at position 1,pern[1]-> piece at position 2 etc
//oren -> orientation-> clockwise 1 ,anti clockwise 2, solved 0
//
//solved state is
//perm={1,2,3,4,5,6,7,8}
//oren={0,0,0,0,0,0,0,0}
//
//ULB->1,URB->2,URF->3,UFL->4
//DLB->5,DRB->6,DRF->7,DFL->8

//For move operations,we use indices 
//ULB->0,URB->1,URF->2,UFL->3
//DLB->4,DRB->5,DRF->6,DFL->7

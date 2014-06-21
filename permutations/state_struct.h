/*
 * This file contains the representation for a single node in the 2x2x2 cube graph
 */
struct node {
	//state representation  goes here
	int perm[7];
	int oren[7];
};

/*perm -> array containing numbers from 1-7 representing the position of each piece
*perm[0]->piece at position 1,pern[1]-> piece at position 2 etc
*oren -> orientation-> clockwise 1 ,anti clockwise 2, solved 0
*
*solved state is
*perm={1,2,3,4,5,6,7}
*oren={0,0,0,0,0,0,0,0}
*
*ULB->1,URB->2,URF->3,UFL->4
*DRB->5,DRF->6,DFL->7

*For move operations,we use indices 
*ULB->0,URB->1,URF->2,UFL->3
* DRB->4,DRF->5,DFL->6
*/

//NOTE: Piece in position DLB is considered solved at start (cube can always be rotated to an orientation
// to force this)
//This greatly reduces state space

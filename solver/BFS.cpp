/*
 * This is the actual solving program
 */

#include<algorithm>
#include<queue>
#include<iostream>
//an all encapsulating bits/stdc++.h would probably be simpler to add

using namespace std;

//adding local includes
#include"../permutations/state_struct.h"
#include"../permutations/piece_op.cpp"
#include"../permutations/move_U.cpp"
#include"../permutations/move_R.cpp"
#include"../permutations/move_F.cpp"


#include"permToNumberMapper.cpp"

enum moves{
	U=0,
	U2=1,
	Ui=2,
	R=3,
	R2=4,
	Ri=5,
	F=6,
	F2=7,
	Fi=8,
};

//DLB is forced solved so cube is solvable in this <R,F,U> subgroup

//These make previous move checking convinient reducing branching factor
// Eg R R2 is redundant


int solve(node state){
}

int main(){
	// bool visited[][]
	return 0;
}

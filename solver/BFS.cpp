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
	Fi=8
};

//DLB is forced solved so cube is solvable in this <R,F,U> subgroup

//These make previous move checking convenient reducing branching factor
// Eg R R2 is redundant

bool isSolved(node& n){
	if(node_to_num_oren(n)==0 && node_to_num_perm(n)==0){
		return true;
	}
	return false;
}

int main(){
	bool visited[6000][1000]; //only 5040x3^6 is actually needed
	moves prev[6000][1000];

	for(int i=0;i<6000;++i){
		for(int j=0;j<1000;++j){
			visited[i][j] = false;
		}
	}

	int initperm[7],intioren[7];

	cout<<"Enter initial permutation\n";

	for(int i=0;i<7;++i){
		cin<<initperm[i];
	}

	cout<<"Enter initial orientation\n";

	for(int i=0;i<7;++i){
		cin<<initoren[i];
	}


	node n1,n2;
	n1.perm = initperm;
	n1.oren = initoreo;

	int initstate[] = {node_to_num_oren(n1),node_to_num_perm(n1)};

	int stateoren,stateperm;

	queue<node> bfsqueue;
	bfsqueue.push(n1);
	while(!q.empty()){
		n1=q.front();q.pop();
		if(isSolved(n))break;

		stateoren = node_to_num_oren(n1);
		stateperm = node_to_num_perm(n1);
		visited[stateperm][stateoren]=true;

		//add all unvisited neighbours
		//TODO Add redundancy check (R R2 etc)
		n2 =move_R(n1);
		stateoren = node_to_num_oren(n2);
		stateperm = node_to_num_perm(n2);
		if(!visited[stateperm][stateoren]){
			visited[stateperm][stateoren]=true;
			q.push(n2);
			prev[stateperm][stateoren] = moves.R;
		}
		//etc
	}
	//print the solution here
	
	return 0;
}

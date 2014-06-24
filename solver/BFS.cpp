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

moves int_to_move(int i){
	switch(i){
		case 0:return U;break;
		case 1:return U2;break;
		case 2:return Ui;break;
		case 3:return R;break;
		case 4:return R2;break;
		case 5:return Ri;break;
		case 6:return F;break;
		case 7:return F2;break;
		case 8:return Fi;break;
	}
}
//DLB is forced solved so cube is solvable in this <R,F,U> subgroup

//These make previous move checking convenient reducing branching factor
// Eg R R2 is redundant

bool isSolved(node& n){
	if(node_to_num_oren(n)==0 && node_to_num_perm(n)==0){
		return true;
	}
	return false;
}

bool visited[6000][2300]; //only 5040x3^6 is actually needed
moves prev[6000][2300];
//global declarations to avoid segfaults due to memory allocation

int main(){


	for(int i=0;i<6000;++i){
		for(int j=0;j<2300;++j){
			visited[i][j] = false;
		}
	}

	int initperm[7],initoren[7];

	cout<<"Enter initial permutation\n";

	for(int i=0;i<7;++i){
		cin>>initperm[i];
	}

	cout<<"Enter initial orientation\n";

	for(int i=0;i<7;++i){
		cin>>initoren[i];
	}


	node n1,n2;
	for(int i=0;i<7;++i){
		n1.perm[i] = initperm[i];
		n1.oren[i] = initoren[i];	
	}
	

	int initstate[] = {node_to_num_oren(n1),node_to_num_perm(n1)};

	int stateoren,stateperm;

	queue<node> q;
	q.push(n1);
	while(!q.empty()){
		n1=q.front();q.pop();
		stateoren = node_to_num_oren(n1);
		stateperm = node_to_num_perm(n1);
		visited[stateperm][stateoren]=true;
		if(isSolved(n1))break;


		//add all unvisited neighbours
		//TODO Add redundancy check (R R2 etc)

		//R R2 R'
		n2 = move_R(n1);
		stateoren = node_to_num_oren(n2);
		stateperm = node_to_num_perm(n2);
		if(!visited[stateperm][stateoren]){
			visited[stateperm][stateoren]=true;
			q.push(n2);
			prev[stateperm][stateoren] = R;
		}
		n2 = move_R(n2);
		stateoren = node_to_num_oren(n2);
		stateperm = node_to_num_perm(n2);
		if(!visited[stateperm][stateoren]){
			visited[stateperm][stateoren]=true;
			q.push(n2);
			prev[stateperm][stateoren] = R2;
		}
		n2 =move_R(n2);
		stateoren = node_to_num_oren(n2);
		stateperm = node_to_num_perm(n2);
		if(!visited[stateperm][stateoren]){
			visited[stateperm][stateoren]=true;
			q.push(n2);
			prev[stateperm][stateoren] = Ri;
		}

		//U U2 U'
		n2 =move_U(n1);
		stateoren = node_to_num_oren(n2);
		stateperm = node_to_num_perm(n2);
		if(!visited[stateperm][stateoren]){
			q.push(n2);
			visited[stateperm][stateoren]=true;
			prev[stateperm][stateoren] = U;
		}
		n2 =move_U(n2);
		stateoren = node_to_num_oren(n2);
		stateperm = node_to_num_perm(n2);
		if(!visited[stateperm][stateoren]){
			q.push(n2);
			visited[stateperm][stateoren]=true;
			prev[stateperm][stateoren] = U2;
		}
		n2 =move_U(n2);
		stateoren = node_to_num_oren(n2);
		stateperm = node_to_num_perm(n2);
		if(!visited[stateperm][stateoren]){
			q.push(n2);
			visited[stateperm][stateoren]=true;
			prev[stateperm][stateoren] = Ui;
		}

		//F, F2, F'
		n2 =move_F(n1);
		stateoren = node_to_num_oren(n2);
		stateperm = node_to_num_perm(n2);
		if(!visited[stateperm][stateoren]){
			q.push(n2);
			visited[stateperm][stateoren]=true;
			prev[stateperm][stateoren] = F;
		}
		n2 =move_F(n2);
		stateoren = node_to_num_oren(n2);
		stateperm = node_to_num_perm(n2);
		if(!visited[stateperm][stateoren]){
			q.push(n2);
			visited[stateperm][stateoren]=true;
			prev[stateperm][stateoren] = F2;
		}
		n2 =move_F(n2);
		stateoren = node_to_num_oren(n2);
		stateperm = node_to_num_perm(n2);
		if(!visited[stateperm][stateoren]){
			q.push(n2);
			visited[stateperm][stateoren]=true;
			prev[stateperm][stateoren] = Fi;
		}
		//Highly inefficiently done
	}
	//trace the prev through inverses to solved
	//print the solution here
		int zz=0, aru[20];
	while(!(node_to_num_oren(n1)==initstate[0])||!(node_to_num_perm(n1)==initstate[1]))
	{
		aru[zz]=prev[node_to_num_perm(n1)][node_to_num_oren(n1)];
		zz++;
		switch(prev[node_to_num_perm(n1)][node_to_num_oren(n1)])
		{
			case 0:
			n1=move_U(move_U(move_U(n1)));
			break;
			case 1:
			n1=move_U(move_U(n1));
			break;
			case 2:
			n1=move_U(n1);
			break;
			case 3:
			n1=move_R(move_R(move_R(n1)));
			break;
			case 4:
			n1=move_R(move_R(n1));
			break;
			case 5:
			n1=move_R(n1);
			break;
			case 6:
			n1=move_F(move_F(move_F(n1)));
			break;
			case 7:
			n1=move_F(move_F(n1));
			break;
			case 8:
			n1=move_F(n1);
			break;
		}
	}

	for(int i=zz-1; i>=0; i--)
	{
		switch(aru[i])
		{
			case 0:
			cout<<"U ";
			break;
			case 1:
			cout<<"U2 ";
			break;
			case 2:
			cout<<"U\' ";
			break;
			case 3:
			cout<<"R ";
			break;
			case 4:
			cout<<"R2 ";
			break;
			case 5:
			cout<<"R\' ";
			break;
			case 6:
			cout<<"F ";
			break;
			case 7:
			cout<<"F2 ";
			break;
			case 8:
			cout<<"F\' ";
			break;
		}
	}
	return 0;
}

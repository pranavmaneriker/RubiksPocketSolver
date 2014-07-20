/*
 * Take a permutation node as input and conver it to a number 
 * The number should lie between 0 to (no of states of 2x2x2-1) 
 * This would make the BFS implementation simpler
 *
 * Read up on the factoradic number system to know how this is done
 * also, combinatorial number system
 * If you come up with your own implementation, that's cool too 
 */

//overshooting optimal by a lot but state space is small enough for that

int node_to_num_oren(node cur){
	int orennum=0;
	int p=1;
	for(int i=0;i<7;++i){
		orennum+=cur.oren[i]*p;
		p*=3;
	}
	//orennum = base 10 representation of orientation
	//orennum belongs to 0-3^6
	return orennum;
}

int node_to_num_perm(node cur){
	//using lehmer code+factoradic system for encoding permutation
	//can be done in O(nlog(n)), this implementation is O(n^2)

	int permnum=0;
	int inv,fact=1;
	for(int i=0;i<7;++i){
		inv=0;
		for(int j=i;j>=0;--j){
			if(cur.perm[i]<cur.perm[j])inv++;
		}
		permnum+=fact*inv;
		fact*=(i+1);
	}
	return permnum;

	//permnum belongs 0-7!-1
}

//now fully optimised

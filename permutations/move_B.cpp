//function that changes the permutation as a B move would

void move_B(node& cur){
	//apply B to cur
	cycle(cur.perm,0,1,5,4);
	cycle(cur.oren,0,1,5,4);
	rotcw(cur.oren,0);
	rotcw(cur.oren,5);
	rotccw(cur.oren,1);
	rotcw(cur.oren,4);
}


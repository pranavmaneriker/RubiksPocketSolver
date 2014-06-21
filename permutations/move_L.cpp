//function that changes the permutation as a L move would

void move_L(node cur){
	//apply L to cur
	cycle(cur.perm,0,3,7,4);
	cycle(cur.oren,0,3,7,4);
	rotcw(cur.oren,3);
	rotcw(cur.oren,4);
	rotccw(cur.oren,0);
	rotcw(cur.oren,7);
}

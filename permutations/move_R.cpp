//function that changes the permutation as a R move would

void move_R(node& cur){
	//apply R to cur
	cycle(cur.perm,2,1,5,6);
	cycle(cur.oren,2,1,5,6);
	rotcw(cur.oren,1);
	rotcw(cur.oren,6);
	rotccw(cur.oren,2);
	rotcw(cur.oren,5);
}

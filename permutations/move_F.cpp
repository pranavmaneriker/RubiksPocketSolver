//function that changes the permutation as a F move would

void move_F(node& cur){
	//apply F to cur
	cycle(cur.perm,3,2,5,6);
	cycle(cur.oren,3,2,5,6);
	rotcw(cur.oren,2);
	rotcw(cur.oren,6);
	rotccw(cur.oren,3);
	rotcw(cur.oren,5);
}

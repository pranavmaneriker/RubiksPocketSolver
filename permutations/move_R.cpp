//function that changes the permutation as a R move would

node move_R(node cur){
	//apply R to cur
	cycle(cur.perm,2,1,4,5);
	cycle(cur.oren,2,1,4,5);
	rotcw(cur.oren,1);
	rotcw(cur.oren,5);
	rotccw(cur.oren,2);
	rotcw(cur.oren,4);
	return cur
}

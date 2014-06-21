//function that changes the permutation as a D move would

void move_D(node cur){
	//apply D to cur
	//D does not affect orientation except cycling the pieces
	cycle(cur.perm,4,5,6,7);
	cycle(cur.oren,4,5,6,7);
}

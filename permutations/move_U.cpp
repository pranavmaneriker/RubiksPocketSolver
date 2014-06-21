//function that changes the permutation as a U move would

void move_U(node& cur){
	//apply U to cur
	//No oreinetation changes, only cycles
	cycle(cur.perm,0,1,2,3);
	cycle(cur.oren,0,1,2,3);
}

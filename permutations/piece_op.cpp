//cycles elements in array
void cycle( int arr[], int i1,int i2,int i3,int i4){
	int t=arr[i4];
	arr[i4]=arr[i3];
	arr[i3]=arr[i2];
	arr[i2]=arr[i1];
	arr[i1]=t;
}

//rotate clockwise
void rotcw(int arr[], int i){	
	arr[i]=(arr[i]+1)%3;
}

//rotate counter clockwise
void rotccw(int arr[] , int i){
	arr[i]=(arr[i]+2)%3;
}

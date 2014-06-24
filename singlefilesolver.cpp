#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;

struct node {
	int perm[7];
	int oren[7];
};

void cycle(int arr[], int i1,int i2,int i3,int i4)
{
	int t=arr[i4];
	arr[i4]=arr[i3];
	arr[i3]=arr[i2];
	arr[i2]=arr[i1];
	arr[i1]=t;
}

void rotcw(int arr[], int i)
{	
	arr[i]=(arr[i]+1)%3;
}

void rotccw(int arr[] , int i)
{
	arr[i]=(arr[i]+2)%3;
}

int node_to_num_oren(node cur)
{
	int orennum=0, ans[20], p=1;
	for(int i=0;i<7;++i)
	{
		orennum+=cur.oren[i]*p;
		p*=3;
	}
	return orennum;
}

int node_to_num_perm(node cur)
{	
	int permnum=0, inv, fact=1;
	for(int i=0;i<7;++i)
	{
		inv=0;
		for(int j=i;j>=0;--j)
		if(cur.perm[i]<cur.perm[j])inv++;
		permnum=permnum+fact*inv;
		fact=fact*(i+1);
	}
	return permnum;
}

node move_U(node cur)
{
	cycle(cur.perm,0,1,2,3);
	cycle(cur.oren,0,1,2,3);
	return cur;
}

node move_R(node cur)
{
	cycle(cur.perm,2,1,4,5);
	cycle(cur.oren,2,1,4,5);
	rotcw(cur.oren,1);
	rotcw(cur.oren,5);
	rotccw(cur.oren,2);
	rotccw(cur.oren,4);
	return cur;
}

node move_F(node cur)
{
	cycle(cur.perm,3,2,5,6);
	cycle(cur.oren,3,2,5,6);
	rotcw(cur.oren,2);
	rotcw(cur.oren,6);
	rotccw(cur.oren,3);
	rotccw(cur.oren,5);
	return cur;
}

enum moves
{
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

bool isSolved(node& n)
{
	if(node_to_num_oren(n)==0 && node_to_num_perm(n)==0)
	return true;
	return false;
}

bool visited[6000][2300];
moves pre[6000][2300];

int main()
{
	for(int i=0;i<6000;++i)
	for(int j=0;j<2300;++j)
	visited[i][j] = false;

	int initperm[7],initoren[7];

	for(int i=0;i<7;++i)
	cin>>initperm[i];
	for(int i=0;i<7;++i)
	cin>>initoren[i];

	node n1,n2;
	for(int i=0;i<7;++i)
	{
		n1.perm[i] = initperm[i];
		n1.oren[i] = initoren[i];	
	}

	int initstate[2] = {node_to_num_oren(n1),node_to_num_perm(n1)}, stateoren,stateperm;
	queue<node> q;
	q.push(n1);
	
	while(!q.empty())
	{
		stateoren = node_to_num_oren(n1);
		stateperm = node_to_num_perm(n1);
		visited[stateperm][stateoren]=true;
		n1=q.front();
		q.pop();
		
		if(isSolved(n1))
		break;

		n2 = move_R(n1);
		stateoren = node_to_num_oren(n2);
		stateperm = node_to_num_perm(n2);
		if(!visited[stateperm][stateoren])
		{	
			visited[stateperm][stateoren]=true;
			q.push(n2);
			pre[stateperm][stateoren] = R;
		}
		n2 = move_R(n2);
		stateoren = node_to_num_oren(n2);
		stateperm = node_to_num_perm(n2);
		if(!visited[stateperm][stateoren])
		{
			visited[stateperm][stateoren]=true;
			q.push(n2);
			pre[stateperm][stateoren] = R2;
		}
		n2 =move_R(n2);
		stateoren = node_to_num_oren(n2);
		stateperm = node_to_num_perm(n2);
		if(!visited[stateperm][stateoren])
		{
			visited[stateperm][stateoren]=true;
			q.push(n2);
			pre[stateperm][stateoren] = Ri;
		}

		n2 =move_U(n1);
		stateoren = node_to_num_oren(n2);
		stateperm = node_to_num_perm(n2);
		if(!visited[stateperm][stateoren])
		{	
			visited[stateperm][stateoren]=true;
			q.push(n2);
			pre[stateperm][stateoren] = U;
		}
		n2 =move_U(n2);
		stateoren = node_to_num_oren(n2);
		stateperm = node_to_num_perm(n2);
		if(!visited[stateperm][stateoren])
		{
			visited[stateperm][stateoren]=true;
			q.push(n2);
			pre[stateperm][stateoren] = U2;
		}
		n2 =move_U(n2);
		stateoren = node_to_num_oren(n2);
		stateperm = node_to_num_perm(n2);
		if(!visited[stateperm][stateoren])
		{
		visited[stateperm][stateoren]=true;
			q.push(n2);
			pre[stateperm][stateoren] = Ui;
		}

		n2 =move_F(n1);
		stateoren = node_to_num_oren(n2);
		stateperm = node_to_num_perm(n2);
		if(!visited[stateperm][stateoren])
		{
			visited[stateperm][stateoren]=true;
			q.push(n2);
			pre[stateperm][stateoren] = F;
		}
		n2 =move_F(n2);
		stateoren = node_to_num_oren(n2);
		stateperm = node_to_num_perm(n2);
		if(!visited[stateperm][stateoren])
		{	
			visited[stateperm][stateoren]=true;
			q.push(n2);
			pre[stateperm][stateoren] = F2;
		}
		n2 =move_F(n2);
		stateoren = node_to_num_oren(n2);
		stateperm = node_to_num_perm(n2);
		if(!visited[stateperm][stateoren])
		{
			visited[stateperm][stateoren]=true;
			q.push(n2);
			pre[stateperm][stateoren] = Fi;
		}
	}
	
	int zz=0, aru[20];
	while(!(node_to_num_oren(n1)==initstate[0])||!(node_to_num_perm(n1)==initstate[1]))
	{
		aru[zz]=pre[node_to_num_perm(n1)][node_to_num_oren(n1)];
		zz++;
		switch(pre[node_to_num_perm(n1)][node_to_num_oren(n1)])
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

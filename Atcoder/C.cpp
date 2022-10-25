#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> solve(int N, int M, int K, vector<pair<int,int>> Positions)
{
	set<int> A,B;
	for(auto pos:Positions)
	{
		A.insert(pos.first);
		B.insert(pos.second);
	}
	
	map<int,int> mpx,mpy;
	int new_pos=0;
	for(auto index:A)
	{
		mpx[index]=new_pos++;
	}
	new_pos=0;
	for(auto index:B)
	{
		mpy[index]=new_pos++;
	}
	
	vector<vector<char>> ans(N,vector<char> (M,'*'));
	for(auto pos:Positions)
	{
		ans[mpx[pos.first]][mpy[pos.second]]='#';
	}
	return ans;
}

int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	vector<pair<int,int>> Positions(K);
	for(int i = 0; i < K; i++)
	{
		cin >> Positions[i].first >> Positions[i].second;
	}
    vector<vector<char>> ans = solve(N, M, K, Positions);
    for(int i = 0; i < N; i++)
    {
    	for(int j = 0; j < M; j++)
    	{
    		cout << ans[i][j];
    	}
    	cout<<endl;
    }
    return 0;
}
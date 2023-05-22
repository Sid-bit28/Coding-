
#include <iostream>
#include <map>
using namespace std;

int parent[1000];
int ranking[1000];

int ans=0;
//Find function
int Find(int v) {
    if (v == parent[v]){
        return v;
    }
    parent[v]=Find(parent[v]);
    return parent[v];
}

//Union function
void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if (a != b) {
        if (ranking[a] < ranking[b]){
            parent[a]=b;
        }else{
        parent[b] = a;
        }
        if (ranking[a] == ranking[b])
            ranking[a]++;
    }
}

/*function that returns whether the string can be converted or not.*/
bool convertible(string s1, string s2)
{
    map<char, char> mp;
    for (int i = 0; i < s1.size(); i++) {
        if (mp.find(s1[i]) == mp.end()) { 
            mp[s1[i]] = s2[i];/*if character is not present in map then insert it into the map*/
        }
        else {
            if (mp[s1[i]] != s2[i])
                return false;//character does not map to a unique character 
        }
    }
    for (auto it : mp) {
        if (it.first == it.second)/* if element is mapped to itself move to next element in map*/
            continue;
        else {
            if (Find(it.first) == Find(it.second))/*Parent of key and value are equal so cycle exist*/
                ans++;
            else
            	ans++;
                Union(it.first, it.second);
        }
    }
    return true;
}
 
/*initialize parent array and rank array for union and find algorithm.*/
void initialize()
{
    for (int i = 0; i < 1000; i++) {
        parent[i] = i;
        ranking[i]=0;
    }
}

int main(){
	int tt;
	cin>>tt;
	while(tt--) {
		initialize();
		string s,t;
		cin>>s>>t;
		if(convertible(s,t)) {
			cout<<ans<<endl;
		}else cout<<"-1"<<endl;
	}
}

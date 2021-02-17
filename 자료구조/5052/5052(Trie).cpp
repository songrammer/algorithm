#include <bits/stdc++.h>
using namespace std;

struct Node{
	bool valid;
	int child[10];
	Node(){
		for(int i=0; i<10; i++) child[i] = -1;
		valid = 0;
	}
};

vector<Node> trie;
bool flag = 0;

void insert(string &s, int idx, int node){
	if(idx == s.size()){
		trie[node].valid = 1;
		return;
	}
	int now = s[idx] - '0';
	if(trie[node].valid) flag = 1;
	if(idx == s.size()-1 && trie[node].child[now] != -1) flag = 1;
	if(trie[node].child[now] == -1){
		trie[node].child[now] = trie.size();
		trie.push_back(Node());
	}
	insert(s, idx+1, trie[node].child[now]);
}

void init(){
	trie.clear();
	trie.push_back(Node());
	flag = 0;
}

void solve(){
	init();
	int n; cin >> n;
	for(int i=0; i<n; i++){
		string s; cin >> s; insert(s, 0, 0);
	}
	if(flag) cout << "NO\n";
	else cout << "YES\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
}
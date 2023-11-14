// #include <iostream>
// #include <vector>
// #include <cstdlib>
// #include <cstring>
// #include <cmath>
// #include <algorithm>
// #include <ctime>
// #include <queue>
// using namespace std;
// struct Edge { int u, v, z; };
// vector <Edge> edge, ans;
// const int MAXN = 1e5+10;
// const int MAPSIZE = 50;
// const int RAMDOMNESS = 65536;
// int f[MAXN],mp[MAPSIZE][MAPSIZE];
// int getf(int x)
// { 
// 	return x==f[x] ? x : (f[x]=getf(f[x])); 
// }
// bool merge(int x, int y)
// {
// 	x=getf(x), y=getf(y);
// 	if (x != y) {
// 		f[x] = y;
// 		return true;
// 	}
// 	return false;
// }
// bool genWallCmp(const Edge &i, const Edge &j) 
// { 
// 	return i.z < j.z; 
// }
// void genWall()
// {
// 	srand(time(NULL));
// 	int numX = MAPSIZE, numY = MAPSIZE;
// 	for (int i = 1 ; i < numX; i++ ) {
// 		for (int j = 1 ; j < numY; j++ ) {
// 			f[i*numY+j] = i*numY+j;
// 			if (i) edge.push_back({i*numY+j, (i-1)*numY+j, abs(rand())%RAMDOMNESS});
// 			if (j) edge.push_back({i*numY+j, i*numY+(j-1), abs(rand())%RAMDOMNESS});
// //			cout << i*numY+j << "-------" << (i-1)*numY+j << endl;
// 		}
// 	}
// 	sort(edge.begin(), edge.end(), genWallCmp);
// 	for (auto i: edge) {
// 		if (merge(i.u, i.v)) 
// 			ans.push_back(i);
// 	}
		
// 	for (auto p: ans)
// 	{
// 		int i1 = p.u/numY, j1 = p.u%numY;
// 		int i2 = p.v/numY, j2 = p.v%numY;
// 		cout << p.u - p.v << endl;
// 		cout << i1 << "----" << j1  << "******" << i2 << "===========" << j2 << endl;
// 		if (i1 == i2) {
// 			for (int i = j2 ; i < j1 ; ++i ) {
// 				mp[i1][i] = 1;
// 			}
// 		} else {
// 			for (int i = i2 ; i < i1 ; ++i ) {
// 				mp[i][j1] = 1;
// 			}
// 		}
// 	}
// 	for (int i = 0 ; i < numX ; ++i ) {
// 		for (int j = 0 ; j < numY ; ++j ) {
// 			cout << mp[i][j];
// 		}
// 		cout << endl;
// 	}
// }

// typedef struct ce{
// 	int x, y;
// 	double d;
// }ce;
// ce start,endd;
// vector<ce> path;

// bool cmp(ce x, ce y){
// 	return x.d < y.d;
// }

// double get_d(int x, int y)
// {
// 	return abs(endd.x-x) + abs(endd.y - y);
// }


// void A_star(ce start, ce endd)
// {
// 	int vis[MAPSIZE][MAPSIZE];
// 	memset(vis, 0, sizeof(vis));
// 	priority_queue<ce> q;
// 	q.push(start);
// 	while(q.size()){
// 		ce now = q.top(); q.pop();
// 		if (vis[now.x][now.y]) continue;
// 		vis[now.x][now.y] = 1;
// 		// 未完待续.....
// 	}
// }


// void get_path()
// {
// 	cin>>start.x>>start.y>>endd.x>>endd.y;
// 	A_star(start, endd);
// 	// output path;
// }
// // int main ()
// // {
// // 	genWall();
// // 	return 0;
// // }

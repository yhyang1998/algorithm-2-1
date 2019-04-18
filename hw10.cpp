#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;

int n, m;
int now[maxn], maze[maxn];

//某一格能不能走到只需要看他的能不能從他的左邊或上面走到即可
void path(int row){
	if(row == 0){		//第一列的值會跟原本的一樣
		for(int j = 0; j < m; j++){
			if(!now[j])	break;		//如果有一個為0後面都會是0 因為走不到了(第一行只看左邊的)
			else	maze[j] = now[j];
		}
	}else{
		for(int j = 0; j < m; j++){
			if(now[j] == 1){
				if((now[j-1] == 0) && (maze[j] == 0))		now[j] = 0;
				else	now[j] = 1;
			}else now[j] = 0;
		}
		for(int j = 0; j < m; j++){
			maze[j] = now[j];
			//cout << maze[j] << " ";
		}
	}
	//cout << endl;
	return;
}

int main(){
	memset(now, 0, sizeof(now));
	memset(maze, 0, sizeof(maze));
	cin >> n >> m;

	for(int row = 0; row < n; row++){
		for(int j = 0; j < m; j++){
			char c;
			cin >> c;
			if(c == 'x')	now[j] = 0;
			else	now[j] = 1;
			//cout << now[j] << " ";
		}
		//cout << endl;
		path(row);
	}

	if(maze[m-1])	cout << "YES\n";
	else cout << "NO\n";
	return 0;
}

#include <cstdio>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 105;

string mat[MAXN];
bool bio[MAXN][MAXN];
int n, m;

void fillMatrix (int x, int y, int s){
  --x; --y;
  if (x < 0 || x+s > n || y < 0 || y+s > m){
    printf("0\nDio kvadrata izvan zgrada!\n");
    exit(0);
  }

  for (int i = x; i < x + s; ++i)
    for (int j = y; j < y + s; ++j)
      bio[i][j] = 1;
}

int main (int num, char **arg){
  ifstream in, off, out;

  in.open(arg[1]);
  off.open(arg[2]);
  out.open(arg[3]);

  string input, output, cOutput;
  in >> n >> m;
  for (int i = 0; i < n; ++i)
    in >> mat[i];

  getline(out, cOutput);
  int r, s, sz;
  sscanf(cOutput.c_str(), "%d%d%d", &r, &s, &sz);
  fillMatrix(r, s, sz);

  getline(out, cOutput);
  sscanf(cOutput.c_str(), "%d%d%d", &r, &s, &sz);
  fillMatrix(r, s, sz);
  
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j){
      int field = (mat[i][j] == 'x');
      if (field != bio[i][j]){
	printf("0\nPogresno rjesenje!\n");
	return 0;
      }
    }

  printf("1\nTocno rjesenje!\n");
  return 0;
}

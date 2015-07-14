#include <cstdio>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main (int num, char **arg){
  ifstream in, off, out;

  in.open(arg[1]);
  off.open(arg[2]);
  out.open(arg[3]);

  string input, output, cOutput;
  int n;
  in >> n;
  int a[n], b[n];

  for (int i = 0; i < n; ++i)
    in >> a[i];

  getline(off, output);
  for (int i = 0; i < n; ++i){
    if (out.eof()){
      printf("0\nNedovoljno podataka na izlazu.\n");
      return 0;
    }

    getline(out, cOutput);
    sscanf(cOutput.c_str(), "%d", &b[i]);
  }

  for (int i = 0; i < n; ++i)
    if (b[i] + b[(i-1+n)%n] + b[(i+1)%n] != a[i]){
      printf("0\nIspis ne zadovaljava uvjet!\n");
      return 0;
    }
  

  printf("1\nTocno rjesenje!\n");
  return 0;
}

#include <cstdio>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <string> genDecomposition (string s){
  string tmp;
  vector <string> V;
  for (auto x: s)
    if (x == ' '){ V.push_back(tmp); tmp.clear(); }
    else tmp += x;

  if (tmp.size()) V.push_back(tmp);
  //dopusit cu space na kraju reda.
  return V;
}

string join (vector <string> &V){
  string ret;
  for (auto x: V)
    ret += x;
  return ret;
}

bool anadrom (string &S){
  int cnt[26] = {0};
  for (auto x: S) cnt[x - 'a']++;
  int odd = 0;
  for (int i = 0; i < 26; ++i)
    odd += cnt[i]%2;
  if (odd > 1) return 0;
  return 1;
}

int main (int num, char **arg){
  ifstream in, off, out;

  in.open(arg[1]);
  off.open(arg[2]);
  out.open(arg[3]);

  string input, output, cOutput;
  in >> input;
  getline(off, output);
  getline(out, cOutput);

  auto A = genDecomposition(output);
  auto B = genDecomposition(cOutput);
  
  if (A.size() != B.size()){
    if (A.size() < B.size()) printf("Postoji rastav s manjim brojem rijeci!\n");
    if (A.size() > B.size()) printf("Ne postoji takav rastav rijeci!\n");
    return 0;
  }

  if (input != join(B)){
    printf("Spajavanjem svih rijeci ne dobiva se ulazna rijec!\n");
    return 0;
  }

  for (auto x: B)
    if (!anadrom(x)){
      printf("Postoji rijec koja nije anadrom!\n");
      return 0;
    }

  printf("Tocno rjesenje!\n");
  return 0;
}

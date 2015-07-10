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
  
  int a, b;
  sscanf(output.c_str(), "%d", &a);
  sscanf(cOutput.c_str(), "%d", &b);

  if (a != b){
    printf("Minimalan broj pritisaka tipke nije ispravan!\n");
    return 0;
  }

  off >> output;
  out >> cOutput;

  for (auto x: cOutput)
    if (!isupper(x) || !isalpha(x)) {
      printf("Postoji znak koji nije veliko slovo %c!\n", x);
      return 0;
    }

  cOutput = "A" + cOutput;
  int dist = 0;
  for (int i = 0; i+1 < cOutput.length(); ++i){
    dist += min((cOutput[i+1] - cOutput[i] + 26)%26, (cOutput[i] - cOutput[i+1] + 26)%26);
  }

  dist += (int)cOutput.length() - 1;

  if (dist != b){
    printf("Broj pritisaka tipaka nije jednak onom ispisanom.\n");
    return 0;
  }

  printf("Tocno rjesenje!\n");
  return 0;
}

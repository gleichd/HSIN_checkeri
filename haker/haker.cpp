#include <cstdio>

#include <algorithm>

#include <cstring>

#include <vector>

#include <set>

using namespace std;

// arg[1] = test primjer
// arg[2] = sluzbeno rjesenje
// arg[3] = natjecateljevo rjesenje

const int MAXN = 1 << 17;
const int MAXBUFF = 500;

char test_case[MAXBUFF], solution[MAXBUFF], competitor[MAXBUFF];

char str[MAXN];
char buff[MAXN];

int p, m, n, k;

void read_testcase() {
  FILE *test = fopen(test_case, "r");
  int q;

  fscanf(test, "%d%d%d", &p, &m, &n);
  fscanf(test, "%s", str);
  fscanf(test, "%d", &k);
}

set<long long> S;
set<int> P;

int cmp() {
  for (int i = 0; str[i] || buff[i]; ++i) {
    if (!str[i]) return 0;
    if (!buff[i]) return 1;
    if (str[i] != buff[i]) return str[i] > buff[i];
  }

  return 0;
}

long long get_hash(int baza, int mod) {
  long long hash = 0;

  for (int i = 0; buff[i] >= 'a' && buff[i] <= 'z'; ++i) {
    hash = hash * baza + buff[i] - 'a' + 1;

    if (mod != 0) hash %= mod;
  }

  return hash;
}

int main(int num, char **arg) {
  strcpy(test_case, arg[1]);
  strcpy(solution, arg[2]);
  strcpy(competitor, arg[3]);

  read_testcase();

  int x;
  fscanf(fopen(solution, "r"), "%d", &x);

  FILE *comp = fopen(competitor, "r");

  if (x == 0) {
    char buff[50];

    fscanf(comp, "%s", buff);

    if (strcmp(buff, "NEMOGUCE") == 0)
      printf("1\nOk. Točno rješenje!\n");

    else
      printf("0\nPogrešno rješenje!\n");

    return 0;
  }

  while (fgets(buff, MAXN, comp) == buff) {
    if (strlen(buff) == 1) continue;

    if (cmp()) {
      printf(
          "0\nPogrešno rješenje. String je leksikografski manji od onog u "
          "ulazu!\n");
      return 0;
    }

    // strlen-1 zbog new linea

    if (strlen(buff) - 1 != n) {
      printf("0\nPogrešno rješenje. String je duljine različite od N!\n");
      return 0;
    }

    long long hh = get_hash(3137, 0);

    if (S.count(hh) == 1) {
      printf("0\nPogrešno rješenje. Isti string je ispisan dvaput!\n");
      return 0;
    }

    S.insert(hh);
    P.insert(get_hash(p, m));
  }

  if (S.size() != k) {
    printf("0\nPogrešno rješenje, nije ispisano točno k stringova!\n");
    return 0;
  }

  if (P.size() > 1) {
    printf("0\nSvi stringovi nemaju isti hash!\n");
    return 0;
  }

  printf("1\nOk. Točno rješenje!\n");

  return 0;
}

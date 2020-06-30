#include <stdio.h>

int n;
int k;
int A[100000];

unsigned int p(x) {
    int i;
    int worked_person_num = 1;
    int tmp_work = 0;
    for (i = 0; i < n; i++) {
        if (A[i] > x) {
            return 0;
        }
        if (work + A[i] > x) {
            worked_person_num++;
            tmp_work = A[i];
        }
        else {
            tmp_work += A[i];
        }
    }
    if (worked_person_num <= k) return 1;
    return 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);

  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000000;

  while (ub - lb > 1) {
      int mid = (ub + lb) / 2;
      if (p(mid)) {
          ub = mid;
      }
      else {
          lb = mid;
      }
  }
  printf("%d", ub);

  return 0;
}

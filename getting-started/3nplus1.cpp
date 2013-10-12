#include <iostream>
#include <assert.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

long cycle_length(int);
long cycle_length_acc(int, long);
long max_cycle(int, int);

long cycle_length(int n) {
  return cycle_length_acc(n, 1);
}

long cycle_length_acc(int n, long acc) {
  if(n == 1) return acc;
  else if(n % 2 == 1) return cycle_length_acc(3 * n + 1, acc + 1);
  else return cycle_length_acc(n / 2, acc + 1);
}

long max_cycle(int i, int j) {
  // It can be the case that i > j, here it is taken care of
  int l = MIN(i,j);
  int h = MAX(i,j);

  long tmp, max = 0;
  for(long n = l; n <= h; n++) {
    tmp = cycle_length(n);
    if(tmp > max) max = tmp;
  }
  return max;
}

void test() {
  assert ( 20 == max_cycle(  1,   10));
  assert (125 == max_cycle(100,  200));
  assert ( 89 == max_cycle(201,  210));
  assert (174 == max_cycle(900, 1000));
}

int main() {
  int i, j;
  long max; 
  
  #ifndef JUDGE_ONLINE 
  test();
  #endif

  while(std::cin >> i >> j) {
    max = max_cycle(i, j);
    std::cout << i << " " << j << " " << max << std::endl;
  }

  return 0;
}

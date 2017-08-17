#include<iostream>

using namespace std;

bool NeedSwap(char* p_begin, char* p_end) {
  for (char* p = p_begin; p < p_end; p++) {
    if (*p == *p_end) {
      return false;
    }
  }
  return true;
}

void Permutation(char* p_str, char* p_begin, int& i_round) {
  if (*p_begin == '\0') {
    cout<<"one permutation:"<<p_str<<" round:"<<i_round++<<endl;
  }
  
  for (char* p_cur = p_begin; *p_cur != '\0'; p_cur++) {
    if (!NeedSwap(p_begin, p_cur)) {
      continue;
    }

    swap(*p_begin, *p_cur);
    Permutation(p_str, p_begin + 1, i_round);
    swap(*p_begin, *p_cur);
  }
}

int main() {
  int round = 1;
  char str[] = "abcdefgggg";
  Permutation(str, str, round);
  return 0;
}

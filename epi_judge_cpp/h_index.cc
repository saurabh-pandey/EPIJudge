#include <algorithm> 
#include <vector>

#include "test_framework/generic_test.h"

using std::vector;


int HIndex(vector<int> citations) {
  int hIndex {0};
  std::sort(citations.begin(), citations.end(), std::greater<>());
  for (auto const & c : citations) {
    if (hIndex + 1 > c) {
      break;
    }
    ++hIndex;
  }
  return hIndex;
}


int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"citations"};
  return GenericTestMain(args, "h_index.cc", "h_index.tsv", &HIndex,
                         DefaultComparator{}, param_names);
}

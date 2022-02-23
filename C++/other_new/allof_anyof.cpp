#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
  vector<int> nums{3, 5, 8, 9, 10};
  bool noneB = none_of(nums.cbegin(), nums.cend(), [](int i){if(i < 0) {
      return true;
  }
      else {
          return false;
      }
  });
  
  bool allB = all_of(nums.cbegin(), nums.cend(), [](int i) {
      if(i > 2) {
          return true;
      } else {
          return false;
      }
  });
  
  bool anyB = any_of(nums.cbegin(), nums.cend(), [](int i) {
      if(i > 11) {
          return true;
      } else {
          return false;
      }
  });
  
  cout<<boolalpha;
  cout<<"None of the nums is negative: "<<noneB<<endl;
  cout<<"All of the nums is larger than 2: "<<allB<<endl;
  cout<<"There is no num  larger than 11: "<<(!anyB)<<endl;
  
  return 0;
}

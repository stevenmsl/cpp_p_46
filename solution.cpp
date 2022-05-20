#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace sol46;
using namespace std;

/*takeaways
  - everyone takes turns to be the first in the permutation
    while composing the permutation recursively
*/

void Solution::_permute(vector<int> &num, vector<int> &picked,
                        vector<int> &permutation, vector<vector<int>> &result)
{
  /* completed constructing the permutation */
  if (permutation.size() == num.size())
  {
    result.push_back(permutation);
    return;
  }

  /* assemble the permutation from left to right
     - everyone takes turns to be the first in the
       permutation
  */

  for (auto i = 0; i < num.size(); i++)
  {
    if (picked[i])
      continue;
    permutation.push_back(num[i]), picked[i] = 1;
    _permute(num, picked, permutation, result);
    /* restore the state
       - to start a new permutation
    */
    picked[i] = 0, permutation.pop_back();
  }
}

vector<vector<int>> Solution::permute(vector<int> &num)
{
  auto picked = vector<int>(num.size(), 0);
  auto p = vector<int>();
  auto result = vector<vector<int>>();

  _permute(num, picked, p, result);

  return result;
}
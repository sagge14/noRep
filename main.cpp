#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main()
{
    cout << "---No repetition---" << endl;

    vector<int> v = {1,2,3,3,4,5,4,5,6,6,8,8,9,10,11,12,12,1,2,4,5,3,2};

    for(auto e:v)
        cout << e << " ";
    cout << endl;

   auto myLamb = [] (const vector<int>& v)
   {
       unordered_set<int> n;
       vector<int> r;
       for_each(v.begin(),v.end(),[&n](auto e){n.insert(e);});
       for_each(n.begin(),n.end(),[&r](auto e){r.push_back(e);});
       return make_unique<vector<int>>(r);
   };

   unique_ptr<vector<int>> ptrVec = myLamb(v);

   for(auto e:*ptrVec)
       cout << e << " ";
   cout << endl;

    cout << "---Bye, bye!---" << endl;
}
#include<iostream>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#define maxn 1000
using namespace std;



int main()
{

    ///1. 初始化
  multimap<int, string> mapStudent;
  multimap<int, string>::iterator iter, beg, end;
    
  ///2. 新增元素
  ///multimap不支援下標操作
  mapStudent.insert(pair<int, string>(0, "student_one"));
  mapStudent.insert(pair<int, string>(0, "student_one_copy"));///一對多
  mapStudent.insert(pair<int, string>(1, "student_two"));
  mapStudent.insert(pair<int, string>(5, "Fear Kubrick"));
  mapStudent.insert(pair<int, string>(2, "Akemi Homura"));
  mapStudent.insert(pair<int, string>(-1, "Eren Jaeger"));
  mapStudent.insert(pair<int, string>(99, "lin"));
  cout << mapStudent.size() << endl;
  cout << endl;
    
  ///3. 遍歷
//   for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
//     cout << iter->first << " " << iter->second << endl;
//   cout << endl;
    
  ///4. 單鍵查詢與範圍查詢
  ///單鍵查詢
//   int count = mapStudent.count(0);
//   iter = mapStudent.find(1);
//   for (int i = 0; i < count; i++, iter++)
//     cout << iter->first << " " << iter->second << endl;
//   cout << endl;
  //從key 找 value
//  iter  = mapStudent.find(99);
//   if (iter != mapStudent.end())
//   {
//      std::cout << (*iter).second << std::endl;
//   }

//   ///範圍查詢
//   beg = mapStudent.lower_bound(1);/// >=1
//   end = mapStudent.upper_bound(5);/// <=5
//   for (; beg != end; beg++)
//     cout << beg->first << " " << beg->second << endl;
//   cout << endl;
    
//   ///5. 刪除
  iter = mapStudent.find(1);
  mapStudent.erase(iter);
  cout << mapStudent.size() << endl;
  for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
    cout << iter->first << " " << iter->second << endl;
  cout << endl;
    
//   ///6. 判空與清空
//   if (!mapStudent.empty()){
//     mapStudent.clear();
// }
    
    return 0;
}
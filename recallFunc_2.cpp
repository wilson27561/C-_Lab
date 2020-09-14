
#include <iostream>
using namespace std;
#include <iostream>
#include <stack>
#include <list>
#include <queue>

int getAdd(int a,int b){
    return a+b;
}

int getMiuns(int c,int d){
   
   int  e = getAdd(c,d);

    return e;
}

int main()
{
    //构建 queue 容器适配器
    std::deque<int> values{ 1,2,3 };
    std::queue<int> my_queue(values);//{1,2,3}
    //查看 my_queue 存储元素的个数
    cout << "size of my_queue: " << my_queue.size() << endl;
    //访问 my_queue 中的元素
    while (!my_queue.empty())
    {
        cout << my_queue.front() << endl;
        //访问过的元素出队列
        my_queue.pop();
    }
     
}
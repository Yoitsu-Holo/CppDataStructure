#include <bits/stdc++.h>
using namespace std;

class Liner
{
    int *head; //表头，用于存储这个线性表的表头
    int size;  //线性表的有效元素数量

public:
    //构造函数，用于新建这个线性表的时候初始化这个线性表的某一些东西
    Liner() : head(new int[100]), size(0) {}

    //在pos位置插入val这个值
    bool Insert(int val, int pos)
    {
        if (pos > size || pos < 0) //如果不在可操作范围内
            return false;          //返回操作失败

        for (int i = size; i > pos; i--) //利用for循环移动元素，注意是由后向前
            head[i] = head[i - 1];       //移动这些元素

        head[pos] = val; //将val这个值放在pos位置
        size++;          //有效元素数量加一
        return true;     //返回操作成功
    }

    //删除一个位置的元素
    bool Delete(int pos)
    {
        if (pos >= size || pos < 0) //这两句和insert同理
            return false;

        for (int i = pos; i < size - 1; i++) //由pos位置开始，将后面的元素往前挪
            head[i] = head[i + 1];

        size--;      //有效元素减一
        return true; //返回操作成功
    }

    //查找一个值出现的位置
    int Find(int val)
    {
        for (int i = 0; i < size; i++) //从前往后扫一次
            if (head[i] == val)        //如果当前位置的值等于了目标，直接返回位置即可
                return i;
        return -1; //如果扫完了都没找到，直接返回-1，因为-1这个位置根本不存在
    }

    //统计一个值出现了多少次
    int Count(int val)
    {
        int cnt = 0;                   //拿一个变量存一下目前出现了多少次，当然，要赋初值0
        for (int i = 0; i < size; i++) //和find几乎同理
            if (head[i] == val)
                cnt++;
        return cnt; //返回这个统计次数的变量值即可
    }

    //获取一个位置的元素值
    int Get(int pos)
    {
        if (pos >= size || pos < 0) //和insert，delete同理
            return 0;
        return head[pos]; //数组咋用，这就咋用
    }

    int Size() { return size; } //直接返回size这个变量

    bool Empty() { return size == 0; } // size为0，那这个线性表自然就是空的嘛

    void Clear() { size = 0; } //直接重置size，简单粗暴
};

int main()
{
    //实例代码
    Liner liner;
    for (int i = 0; i < 10; i++)
        liner.Insert(5 + i, i);
    liner.Insert(10, 5);
    liner.Delete(7);

    printf("%d ", liner.Count(100));
    return 0;
}
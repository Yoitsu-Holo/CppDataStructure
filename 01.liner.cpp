#include <bits/stdc++.h>
using namespace std;

class Liner
{
    int *head; //��ͷ�����ڴ洢������Ա�ı�ͷ
    int size;  //���Ա����ЧԪ������

public:
    //���캯���������½�������Ա��ʱ���ʼ��������Ա��ĳһЩ����
    Liner() : head(new int[100]), size(0) {}

    //��posλ�ò���val���ֵ
    bool Insert(int val, int pos)
    {
        if (pos > size || pos < 0) //������ڿɲ�����Χ��
            return false;          //���ز���ʧ��

        for (int i = size; i > pos; i--) //����forѭ���ƶ�Ԫ�أ�ע�����ɺ���ǰ
            head[i] = head[i - 1];       //�ƶ���ЩԪ��

        head[pos] = val; //��val���ֵ����posλ��
        size++;          //��ЧԪ��������һ
        return true;     //���ز����ɹ�
    }

    //ɾ��һ��λ�õ�Ԫ��
    bool Delete(int pos)
    {
        if (pos >= size || pos < 0) //�������insertͬ��
            return false;

        for (int i = pos; i < size - 1; i++) //��posλ�ÿ�ʼ���������Ԫ����ǰŲ
            head[i] = head[i + 1];

        size--;      //��ЧԪ�ؼ�һ
        return true; //���ز����ɹ�
    }

    //����һ��ֵ���ֵ�λ��
    int Find(int val)
    {
        for (int i = 0; i < size; i++) //��ǰ����ɨһ��
            if (head[i] == val)        //�����ǰλ�õ�ֵ������Ŀ�ֱ꣬�ӷ���λ�ü���
                return i;
        return -1; //���ɨ���˶�û�ҵ���ֱ�ӷ���-1����Ϊ-1���λ�ø���������
    }

    //ͳ��һ��ֵ�����˶��ٴ�
    int Count(int val)
    {
        int cnt = 0;                   //��һ��������һ��Ŀǰ�����˶��ٴΣ���Ȼ��Ҫ����ֵ0
        for (int i = 0; i < size; i++) //��find����ͬ��
            if (head[i] == val)
                cnt++;
        return cnt; //�������ͳ�ƴ����ı���ֵ����
    }

    //��ȡһ��λ�õ�Ԫ��ֵ
    int Get(int pos)
    {
        if (pos >= size || pos < 0) //��insert��deleteͬ��
            return 0;
        return head[pos]; //����զ�ã����զ��
    }

    int Size() { return size; } //ֱ�ӷ���size�������

    bool Empty() { return size == 0; } // sizeΪ0����������Ա���Ȼ���ǿյ���

    void Clear() { size = 0; } //ֱ������size���򵥴ֱ�
};

int main()
{
    //ʵ������
    Liner liner;
    for (int i = 0; i < 10; i++)
        liner.Insert(5 + i, i);
    liner.Insert(10, 5);
    liner.Delete(7);

    printf("%d ", liner.Count(100));
    return 0;
}
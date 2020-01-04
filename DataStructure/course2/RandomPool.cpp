#include <iostream>
#include <map>
#include <random>

using namespace std;

/*
RandomPool
insert(key): 将key加入结构，做到不重复加入
delete(key): 移除结构中的key
getRandom(): 等概率返回一个key

要求：
Insert, delete, getRandom操作复杂度 O(1)
*/

class RandomPool
{
public:
    void insertKey(string);
    void deleteKey(string);
    string getRandomKey();

    RandomPool()
    {
        size = 0;
        keyIndex.clear();
        indexKey.clear();
    }

private:
    int size;
    map<string, int> keyIndex;
    map<int, string> indexKey;
    default_random_engine generator;
};

void RandomPool::insertKey(string s)
{
    if (this->keyIndex.find(s) == this->keyIndex.end())
    {
        keyIndex.insert(pair<string, int>(s, size));
        indexKey.insert(pair<int, string>(size, s));
        this->size++;

        cout << "after insertion, size: " << this->size << endl;
    }
}

void RandomPool::deleteKey(string s)
{
    if (this->keyIndex.find(s) != this->keyIndex.end())
    {
        int index = this->keyIndex[s];               // 保留的index,防止洞的出现
        string key = this->indexKey[this->size - 1]; //  最后一个key

        this->keyIndex[key] = index;
        this->indexKey[index] = key;
        this->keyIndex.erase(s);
        this->indexKey.erase(this->size - 1);

        this->size--;
        cout << "after deletion, size: " << this->size << endl;
    }
}

string RandomPool::getRandomKey()
{
    uniform_int_distribution<int> distribution(0, size - 1);
    int index = distribution(this->generator);
    cout << "selection index: " << index << endl;
    return this->indexKey[index];
}

int main(int argc, char **argv)
{
    RandomPool rp;
    rp.insertKey("abc");
    rp.insertKey("bcd");
    rp.insertKey("dfc");
    rp.insertKey("erd");

    rp.insertKey("erd");
    rp.insertKey("dfc");

    cout << "get Random one: " << rp.getRandomKey() << endl;
    cout << "get Random one: " << rp.getRandomKey() << endl;
    cout << "get Random one: " << rp.getRandomKey() << endl;
    cout << "get Random one: " << rp.getRandomKey() << endl;

    rp.deleteKey("abc");
    rp.deleteKey("erd");
    rp.deleteKey("bcd");

    rp.deleteKey("abc");
    rp.deleteKey("erd");

    return 0;
}
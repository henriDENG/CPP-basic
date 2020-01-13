
class Arraylist
{
private:
    int maxsize;
    int listsize;
    int fence;
    char* listArray;
public:
    Arraylist();
    Arraylist(const Arraylist &);
    ~Arraylist();
    void Add(const char ch);
    void Copy(const char* Array);
    bool Remove(int pos, char *it);
    void Combination(const Arraylist &b);//如果不是传引用，会自动调用拷贝构造函数，将指针复制，指向同一片内存区域
    void Clear();
    char*Getlist();
    char Getvalue(int pos);
    void show();
};

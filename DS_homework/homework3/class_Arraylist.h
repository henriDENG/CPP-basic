
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
    void Combination(const Arraylist &b);//������Ǵ����ã����Զ����ÿ������캯������ָ�븴�ƣ�ָ��ͬһƬ�ڴ�����
    void Clear();
    char*Getlist();
    char Getvalue(int pos);
    void show();
};

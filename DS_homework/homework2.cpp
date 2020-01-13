#include <iostream>
#include <cstring>

using namespace std;

//声明
class bigInteger
{
private:
    int data[500];
    int length;
public:
    bigInteger()
    {
        length = 1;
        memset(data, 0, sizeof(data));//内存赋值函数，初始化
    }
    bigInteger(const char*);
    ~bigInteger();

    bigInteger& operator=(const bigInteger &); //前面的&表示引用
    bigInteger operator+(const bigInteger &) const;
    bigInteger operator-(const bigInteger &) const;
    bigInteger operator*(const bigInteger &) const;
    void show();
};

//构造函数
bigInteger::bigInteger(const char* NUM)
{
    memset(data, 0, sizeof(data));//初始化！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
    length=strlen(NUM);
    //cout<<"length of input: "<<length<<endl;
    for (int i=0;i<length;i++){
        data[i]=NUM[length-1-i]-'0';
    }
}
//析构函数
bigInteger::~bigInteger()
{

}
//方法
bigInteger& bigInteger::operator=(const bigInteger &num)
{
    length=num.length;
    for (int i=0; i<=length+1; i++) {
        data[i]=num.data[i];
    }//多两位，一位存最高位，一位存符号

    return *this;
}

bigInteger bigInteger::operator+(const bigInteger &num) const
{
    bigInteger sum;
    int l1=length;
    int l2=num.length;
    int len;
    if (l1>=l2) len=l1;
    else len=l2;
    sum.length = len;

    int temp=0;
    for (int i=0;i<=len;i++){
        if (data[i]+num.data[i]+temp < 10){
            sum.data[i] = data[i]+num.data[i]+temp;
            temp=0;
        }
        else if (data[i]+num.data[i]+temp >= 10){
            sum.data[i]= data[i]+num.data[i]+temp-10;
            temp=1;
        }
    }

    return sum;
}
bigInteger bigInteger::operator-(const bigInteger &num) const
{
    bigInteger abstraction;
    int l1=length;
    int l2=num.length;
    int l;
    int flag=0;//为0表示正，为1表示负
    int k=0;

    //cout<<"l1: "<<l1<<" l2: "<<l2<<endl;
    //cout<<"num1[length-1]: "<<data[length-1]<<endl;
    //cout<<"num2[length-1]: "<<num.data[length-1]<<endl;

    if (l1 > l2)  flag=0;
    else if (l1 == l2){
        for (int i=length-1;i>=0;i--){
            if(data[i]== num.data[i])
                continue;
            else if(data[i]> num.data[i]){
                flag=0;
                break;
            }
            else{
                flag=1;
                break;
            }
        }
    }
    else if (l1 < l2) flag=1;
    //cout<<"flag: "<<flag<<endl;

    if (l1>=l2) l=l1;
    else l=l2;

    int var=0;
    if (flag == 0){
        for (int j=0;j<l;j++){
            if (data[j]-num.data[j]-var >= 0){
                abstraction.data[j]= data[j]-num.data[j]-var;
                var=0;
            }
            if (data[j]-num.data[j]-var < 0){
                abstraction.data[j] = data[j]-num.data[j]-var +10;
                var = 1;
            }
        }
    }
    else if(flag ==1){
            for (int j=0;j<l;j++){
                if(num.data[j]-data[j]-var >= 0){
                    abstraction.data[j]= num.data[j]-data[j]-var;
                    var=0;
                }
            if (num.data[j]-data[j]-var < 0){
                abstraction.data[j] = num.data[j]-data[j]-var +10;
                var = 1;
            }
        }
    }

    k=l-1;
    while( abstraction.data[k] == 0 && k>= 0){
            k--;
    }
    //cout<<"k: "<<k<<endl;
    if (k == -1) flag=1;

    abstraction.length=k+1;  //!!!!!!!

    int l_flag = abstraction.length + 1;
    if (flag == 1) abstraction.data[l_flag]= flag;

    return abstraction;
}

bigInteger bigInteger::operator*(const bigInteger &num) const
{
    bigInteger produit;
    int l1= length;
    int l2= num.length;
    produit.length=l1+l2-1;//!!!!!!!

    for (int i=0;i<l1;i++){
        for (int j=0;j<l2;j++){
            produit.data[i+j] += data[i]*num.data[j];
        }
    }

    for (int k=0;k<l1+l2-1;k++){
        if (produit.data[k]>10){
            produit.data[k+1]+=produit.data[k]/10;
            produit.data[k]%=10;
        }
    }

    return produit;
}

void bigInteger::show()
{
    int i=0;
    int j=0;
    //cout<<"flag: "<<data[length+1]<<endl;
    //cout<<"length: "<<length<<endl;
    //cout<<"data[length+1]: "<<data[length+1]<<endl;

    if (data[length+1] == 1){
        if (length != 0){
            cout<<"-";
            for (int i=length-1;i>=0;i--){
                cout<<data[i];
            }
            cout<<endl;
        }
        else cout<<"0"<<endl;
    }
    else{

        if ( data[length] != 0){
            for (j=length;j>=0;j--){
            cout<<data[j];
            }
            cout<<endl;
        }
        else if(data[length] == 0 &&data[length-1] != 0){
            for(j=length-1;j>=0;j--){
                cout<<data[j];
            }
            cout<<endl;
        }
        else if(data[length]== 0 && data[length-1]==0){
            cout<<"0"<<endl;
        }
    }
}

int main(void)
{
    int i, n;
    char op;
    char num1[500] = {0};
    char num2[500] = {0};

    while (cin >> num1>>op>>num2)
    {
        bigInteger a(num1), b(num2), c;
        //a.show();
        //b.show();
        switch (op){

            case '+':
                c = a + b;
                break;
            case '-':
                c = a - b;
                break;
            case '*':
                c = a * b;
                break;
        }
        c.show();
        memset(num1, 0, sizeof(num1));
        memset(num2, 0, sizeof(num2));
    }

    return 0;
}

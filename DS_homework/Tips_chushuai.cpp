//先将语言标准调到C++11/C++14/C++17

#include <iostream> //基于控制台的输入/输出类型：istream, ostream, iostream
#include <iomanip> //基于控制台的输入/输出类型：带参数的流操纵符
#include <fstream> //基于文件的输入/输出类型：ifstream, ofstream, fstream
#include <sstream> //基于字符串的输入/输出类型：istringstream, ostringstream, stringsteam
#include <string>
#include <cmath>
#include <time.h> //设定当前系统时间为随机数种子 srand(time(NULL))
#include <cstdlib> //生成随机数
#include <cstring> /* 主要函数
					* 复制strcpy, strncpy; 拼接strcat, strncat （注意字符数组足够长）
					* 比较strcmp, strncmp, 字符串长度strlen
					* 查找字符（首次）strchr, （末次）strrchr, 查找字符串（首次）strstr
					*/
#include <cassert> /* 提供assert函数，判断参数合法性，非法（参数为假/0）则报错并终止程序
					*/
using namespace std;

//内联函数
inline int square(int x) { return x * x; } //内联函数，编译时替换square(i)为i * i

//重载函数
int sum(int a1, int a2) { return a1 + a2; }
int sum(int a1, int a2, int a3) { return a1 + a2 + a3; } /* 重载函数，多个函数共用同一函数名
														  * 当多个函数同时匹配时将报错
														  */

//函数模板
template <class T>
T max(T a, T b) { return a > b ? a : b; } /* 函数模板，可以解决任意类型的两个值求最大值
										   * 多个形参类型写为 <class T1, class T2, ...> 例如：
										   * template <class T1, class T2, class T3>
										   * T3 calc(T1 x, T2 y) { return x + y; }
										   * calc<int, char, char>(5, 'a'); 输出为'f'
										   * calc<int, char, int>(5, 'a'); 输出为102
										   */

template <class Type1, class Type2>
auto cal(Type1 alpha, Type2 beta)->decltype(alpha + beta)
{ return alpha + beta; } //尾置返回类型，auto表示编译器自动推导，真正的类型为decltype(alpha + beta)

//引用
int i, &j = i; /* j是i的别名，i与j共用同一内存单元,引用和被引用变量之间的绑定是永久的
				* 引用的应用还可以用于数组改写中，例如：
				* int arr[5] = { 1, 2, 3, 4, 5 };
				* for (int k : arr) cin >> k; 并不能改变arr各项，因为数据输入给k而不是数组arr
				* 正确写法是 for (int &k : arr) cin >> k; 其中k是arr的别名
				*/

void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
} /* 传引用调用
   * 常量的引用传递通常代替值传递（const int &a 代替 int a），特别是在传递的参数占用空间较大时
   * 函数的返回同样可以定义回返回引用，例如：
   * int arr[5] = { 1, 2, 3, 4, 5 };
   * int &index(int j) { return arr[j]; }
   * index(2) = 25; 等价于 arr[2] = 25;
   * 同理cout << index(2); 等价于 cout << arr[2];
   */

//指针
//动态二维数组无法直接实现，应由动态一维数组间接实现
//多维数组由多维指针实现
double(*p1)(int); /* 定义一个指向有一个整型参数、返回值为double型的函数指针
				   * 指向函数的指针主要用于 ①作为另一个函数的参数 ②实现菜单选择
				   * ①例如：
				   * template <class T>
				   * void sort(T a[], int size, bool(*f)(T, T)); 是通用冒泡排序的声明
				   * ②例如：
				   * void(*func[5])() = { NULL, add, erase, modify, search };
				   * int select;
				   * cin >> select;
				   * if (select == 0) return 0;
				   * if (select > 4) cout << "input error\n"; else func[select]();
				   * 其中各个函数形式均为：函数名+()，例如add(), erase()
				   */

//Lambda表达式
//Lambda表达式形式：[捕获列表](参数表)->返回类型{函数体}
auto h = [](int x, int y) {return x + y; }; /* Lambda表达式可以赋值给一个函数指针
											 * 要注意区别 auto h = [x](int y) { return x + y; };
											 * 其中可以用&x代替x表示以引用方式捕获，结果相应可能有所改变
											 * Lambda表达式最重要的用途是作为函数的参数
											 */



//类（DoubleArray类完整版）
class DoubleArray {
	friend ostream &operator<<(ostream &os, const DoubleArray &obj);
	friend istream &operator>>(istream &is, DoubleArray &obj);
	friend bool operator==(const DoubleArray &obj1, const DoubleArray &obj2);
	//友元包含友元函数、友元类和友元成员函数，但由于友元破坏了类的封装，因此要慎用友元

private:
	int low = 0; //类的初始化，也可以写成：int low { 0 };
	int high;
	double *storage;
	static int accu; //静态数据成员，所有此类对象的静态数据成员都共享同一内存

public:
	static void SetAccu(int newAccu) { accu = newAccu; }; /* 静态成员函数的操作将影响类的所有对象
														   * 只用在声明时加static，而不用在类外定义时加
														   * 静态成员函数只能访问静态数据成员或其他静态成员函数
														   * 因此一般用来改变静态数据成员，比如初始化
														   * 调用方式为“类名::静态成员函数名()”
														   * 例如：DoubleArray::SetAccu(8);
														   */

	//构造函数根据size为数组分配空间
	DoubleArray(int size);

	//构造函数根据low和high为数组分配空间
	DoubleArray(int lh, int rh); //构造函数的名字必须与类名完全相同，且不允许有返回值

	//复制构造函数
	DoubleArray(const DoubleArray &arr); /* 如果希望编译器仍提供默认构造函数：
										  * DoubleArray(const DoubleArray &) = default
										  * 如果希望禁用这个功能：
										  * DoubleArray(const DoubleArray &) = delete
										  */

	//委托构造函数
	DoubleArray(int lh, double a[], int size);

	//移位赋值运算符重载函数
	DoubleArray &operator=(DoubleArray &&a); /* 移动赋值，使左边对象直接接管右边临时对象的资源，提高时空效率
											  * 移动赋值适合右值是临时对象的场合
											  * &&是右引用，是C++11的扩展
											  */


	//下标运算符重载函数
	double &operator[] (int index); //作为左值
	const double &operator[] (int index) const; //作为右值

	//去数组的一部分形成一个新的数组
	DoubleArray operator() (int start, int end, int lh); /* 此函数虽然声明和定义均无问题
														  * 但运行时会出现问题，跟编译器有部分关系
														  */

	//析构函数
	~DoubleArray() { if (storage) delete[] storage; } //析构函数的命名为“~类名”
};

ostream &operator<<(ostream &os, const DoubleArray &obj)
{
	os << "数组内容为：\n";
	for (int i = obj.low; i <= obj.high; i++) os << obj[i] << '\t';
	os << endl;
	return os;
}

istream &operator>>(istream &is, DoubleArray &obj)
{
	cout << "请输入数组元素[" << obj.low << ', ' << obj.high << "]:\n";
	for (int i = obj.low; i <= obj.high; i++)is >> obj[i];
	return is;
}

bool operator==(const DoubleArray &obj1, const DoubleArray &obj2)
{
	if (obj1.low != obj2.low || obj1.high != obj2.high) return false;
	for (int i = obj1.low; i <= obj1.high; i++)
		if (obj1[i] != obj2[i])return false;
	return true;
}

int DoubleArray::accu = 6; //即使对象不存在，也将会被修改为6，相当于初始化

DoubleArray::DoubleArray(int size) {
	high = size - 1;
	storage = new double[size];
}

DoubleArray::DoubleArray(int lh, int rh) :low(lh), high(rh) /* 构造函数初始化列表，位于函数头和函数体之间
															 * 常量成员的初值只能在初始化列表中完成
															 */
{
	storage = new double[high - low + 1];
}

DoubleArray::DoubleArray(const DoubleArray &arr) /* 由于默认复制构造函数将会使两个数组指向同一块内存
												  * 因此需要设计自己的复制构造函数
												  */
{
	low = arr.low;
	high = arr.high;
	storage = new double[high - low + 1];
	for (int i = 0; i < high - low + 1; i++) storage[i] = arr.storage[i];
}

DoubleArray::DoubleArray(int lh, double a[], int size) :DoubleArray(lh, lh + size - 1) {
	for (int i = 0; i < size; i++) storage[i] = a[i];
}

DoubleArray &DoubleArray::operator=(DoubleArray &&a)
{
	if (this == &a) return *this;
	delete[] storage;
	low = a.low;
	high = a.high;
	storage = a.storage;
	a.storage = nullptr;
	return *this;
}

double &DoubleArray::operator[](int index)
{
	assert(index >= low && index <= high);
	return storage[index - low];
}

const double &DoubleArray::operator[](int index) const
{
	assert(index >= low && index <= high);
	return storage[index - low];
}

DoubleArray DoubleArray::operator() (int start, int end, int lh)
{
	assert(start <= end && start >= low && end <= high);
	DoubleArray tmp(lh, lh + end - start);
	for (int i = 0; i <= end - start + 1; i++)
		tmp.storage[i] = storage[start + i - low];
	return tmp;
}



//运算符重载（Rational类完整版）
class Rational {
	friend ostream &operator<<(ostream &os, const Rational &obj); //<<输出运算符重载
	friend istream &operator>>(istream &in, Rational &obj); //>>输入运算符重载
	friend Rational operator+(const Rational &r1, const Rational &r2); //+运算符重载
	friend Rational operator*(const Rational &r1, const Rational &r2); //*运算符重载
	friend bool operator<(const Rational &r1, const Rational &r2); //<运算符重载
	friend bool operator==(const Rational &r1, const Rational &r2); //==运算符重载
	/* 大部分运算符都可以重载成成员函数或全局函数
	 * 但赋值运算符（=）、下标运算符（[]）、函数调用运算符（()）和成员访问运算符（->）必须重载成成员函数
	 * 因为这些运算符的第一个运算对象必须是相应类的对象
	 * 例如：operator+是重载成员函数时，2+r等价于2.operator+(r)，但2是整形，因此非法
	 * 但当operator+是全局函数时，执行2+r时，形参与实参不同会进行自动类型转换，调用Rational构造函数
	 * 生成num = 1, dem去默认值1的临时对象，并作为operator+的第一个参数，因此此时表达式合法
	 * 建议其他具有赋值意义的运算符重载成成员函数
	 */

private:
	int num;
	int den;
	void ReductFraction();

public:
	Rational(int n = 0, int d = 1) { num = n; den = d; ReductFraction(); }
	Rational &operator++();
	Rational operator++(int x);
	Rational &operator--();
	Rational operator--(int x); /* C++规定后缀运算符重载函数接受一个额外int（无用的）形式的参数
								 * 前缀++和--是引用返回，后缀++和--是值返回，这跟它们的实现方式有关
								 */
	operator double() const { return (double(num) / (den)); } /* 类类型到其他类型的转换
															   * 定义格式为：
															   * operator 目标类型名() const
															   * {
															   *	...
															   *	return (结果为目标类型的表达式);
															   * }
															   * 类型转换函数不指定返回类型
															   * 类型转换函数可以避免各类运算符重载、减少代码
															   */
	void display() const { cout << num << '/' << den; } /* 若将某个对象定义为常量对象，该对象只能调用常量成员函数
														 * 常量成员函数的声明是在函数头后加保留字const
														 * 应同时在函数声明和定义两处同时加const
														 * 任何不修改数据成员的函数都应该声明为const类型
														 */
};

ostream &operator<<(ostream &os, const Rational &obj) //输出重载函数
{
	os << obj.num << '/' << obj.den;
	return os;
}

istream &operator>>(istream &in, Rational &obj) //输入重载函数
{
	in >> obj.num >> obj.den;
	obj.ReductFraction();
	return in;
}

Rational operator+(const Rational &r1, const Rational &r2) //+重载
{
	Rational tmp;
	tmp.num = r1.den * r2.num + r1.num * r2.den;
	tmp.den = r1.den * r2.den;
	tmp.ReductFraction();
	return tmp;
}

Rational operator*(const Rational &r1, const Rational &r2) //*重载
{
	Rational tmp;
	tmp.num = r1.num * r2.num;
	tmp.den = r1.den * r2.den;
	tmp.ReductFraction();
	return tmp;
}

bool operator<(const Rational &r1, const Rational &r2) //<重载
{
	return r1.num * r2.den < r1.den * r2.num;
}

bool operator==(const Rational &r1, const Rational &r2) //==重载
{
	return r1.num == r2.num && r1.den == r2.den;
}

Rational &Rational::operator++() //前缀++
{
	num += den;
	return *this;
}

Rational Rational::operator++(int x) //后缀++
{
	Rational tmp = *this;
	num += den;
	return tmp;
}

Rational &Rational::operator--() //前缀--
{
	num -= den;
	return *this;
}

Rational Rational::operator--(int x) //后缀--
{
	Rational tmp = *this;
	num -= den;
	return tmp;
}

void Rational::ReductFraction() //化简有理数
{
	int tmp = (num > den) ? den : num;
	for (; tmp > 1; tmp--)
		if (num % tmp == 0 && den % tmp == 0) { num /= tmp; den /= tmp; break; }
}



//继承
class Base
{
protected:
	int x;
public:
	Base(int x0 = 0) { x = x0; }
	void display() const { cout << "x = " << x << endl; }
	virtual int area() const { return 0; }; /* 虚函数
											 * 若写成virtual int area() const = 0;
											 * 表示纯虚函数，指在基类中没有定义，要求在派生类中定义自己的版本
											 * 抽象类：包含纯虚函数且并未得到完全实现的类
											 * 无法定义抽象类的对象，但可以定义指向抽象类的指针，作用为指向派生类
											 */
	virtual ~Base() = default; /* 虚析构函数（这个函数在Base类和Derived类里并不必要，只是为了介绍虚析构函数）
								* 构造函数不能是虚函数，但析构函数可以、而且最好是
								*/
};

class Derived :public Base
{
protected:
	int y;
public:
	Derived(int x0 = 0, int y0 = 0) :Base(x0) { y = y0; }
	void display() const { Base::display(); cout << "y = " << y << endl; } //重定义基类的函数
	virtual int area() const { return x * y; } //重定义虚函数时，虽然virtual可写可不写，但最好写
	virtual ~Derived() = default;
	/* 注意：派生类不能继承基类的构造函数、赋值运算，但可以调用基类的赋值运算符重载函数
	 * 派生类也可以作为基类
	 */
};
/* 继承方式分别public，private（默认），protected
 * protected成员不可以被全局函数或其他类的成员函数访问，但能被派生类的成员函数和友元函数访问
 * public继承（通常）：public->public，protected->protected，private->不可访问
 * protected继承：public->protected，protected->protected，private->不可访问
 * private继承：private->private，protected->private，private->不可访问
 *
 * 面向对象的程序设计中，多态性有两种实现方式：编译时的多态性和运行时的多态性
 * 编译时的多态性：重载函数，运算符重载...
 * 运行时的多态性：虚函数，基类指针志向不同的派生类...
 */



//类模板（Array类完整版）
template <class T>
class Array
{
private:
	int low;
	int high;
	T *storage;
public:
	//根据low和high为数组分配空间
	Array(int lh = 0, int rh = 0) :low(lh), high(rh) { storage = new T[high - low + 1]; }

	//复制构造函数
	Array(const Array &arr);

	//赋值运算符重载函数
	Array &operator=(const Array &a);

	//下标运算符重载函数
	T &operator[](int index);

	//析构函数
	~Array() { if (storage) delete[]storage; }
};

//复制构造函数
template <class T>
Array<T>::Array(const Array<T> &arr)
{
	low = arr.low;
	high = arr.high;
	storage = new T[high - low + 1];
	for (int i = 0; i < high - low + 1; i++)storage[i] = arr.storage[i];
}

//赋值运算符重载函数
template <class T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this == &other) return *this;
	delete[] storage;
	low = other.low;
	high = other.high;
	storage = new T[high - low + 1];
	for (int i = 0; i <= high - low; i++)storage[i] = other.storage[i];
	return *this;
}

//下标运算符重载函数
template <class T>
T &Array<T>::operator[](int index)
{
	if (index<low || index>high) { cout << "下标越界"; exit(-1); }
	return storage[index - low];
}



int main()
{
	Derived D(1, 2);
	Base B;
	B = D;
	cout << "D = (1, 2); B = D; B.display()语句的执行结果：";
	B.display();
	cout << endl;
	/* 派生类可以隐式向基类转换，但基类不能隐式向派生类转换
	 * 基类指针指向派生类对象只能解释基类的成员，而不能解释派生类新增的成员
	 * 虚函数可以解决上述问题：当基类指针指向不同的派生类对象时，会调用不同的函数
	 */

	//内置类型到类类型的转换（隐式）
	Rational r = 2;
	cout << "r = 2语句的执行结果：" << endl << "r = " << r << endl << endl;
	/* 编译器自动执行了从内置类型到类类型的隐式转换
	 * 只要某个类A有一个单个参数的构造函数(或者支持单个参数的构造函数)，C++就会执行参数类型到A类型对象的隐式转换
	 * 如果不希望编译器执行这种隐式转换，应在相应的构造函数前加上explicit
	 * 除非有明显需要隐式转换的理由，单个参数的构造函数应该被设为explicit
	 * 注意：r = 1 / 3语句的执行结果将是r = 0 / 1，因为1 / 3被转化为int类型再传递给r的构造函数
	 * 如果希望Rational类能接受double类，应添加新的重载函数并相应地改写ReductFraction()函数
	 */

	//移动赋值的具体用法
	Rational r0(-5, 3);
	r = r + r0;
	cout << "r = r + (-5/3)语句的执行结果：" << endl << "r = " << r << endl << endl;

	//类类型到其他类型的转换
	double d = r;
	cout << "double d = r语句的执行结果：" << endl << "d = " << d << endl << endl;
	/* 尽管定义的Rational没有重载减法运算符，但可以执行r = r - 1.5或r = r - r0
	 * 因为在执行这类操作时，C++会将有理数r转换成double型的数据，执行double型的减法
	 * 因此利用类型转换函数可以有效避免各类运算符重载，以达到减少代码的目的
	 * 但是，类型转换函数可能导致程序出现二义性，例如5.5 + r，有两种解释方式，只能报错
	 * 如果写成explicit operator double() const { return (double(num) / (den)); }
	 * 那么double d = r将导致编译错误，但double x = double(r)合法
	 */

	Array<double> array(20, 25);
	for (int i = 20; i <= 25; i++) array[i] = 0.1*i;
	cout << "类模板的演示：Array<double>的情况" << endl;
	for (int i = 20; i <= 25; i++) cout << array[i] << '\t';
	cout << endl << endl;
	/* 函数模板的实例化通常由编译器自动完成
	 * 但类模板需要用户明确指出模板形式参数的值
	 */

	char str[14] = "Hello, world!";
	cout << "cout << str的输出是字符串的内容：" << str << endl;
	cout << "cout << (void*)str的输出是str的地址：" << (void*)str << endl << endl;
	//C++的标准输出会将指针以十六进制方式输出，但有一个特例：如果指针指向字符串，将会输出字符串，除非强制类型转换(void*)

	cout.put('E').put('x').put('p').put('\n');
	cout << "输出str字符串前9位：";
	cout.write(str, 9);
	cout << endl << endl;
	//put函数的返回值是当前对象的引用，因此可以连续调用put函数

	/* get和getline成员函数进行字符串的输入
	 * get()从标准输入流对象cin读入一个字符
	 * get(char)将输入流下一个字符存入参数中
	 * get(const char*, int, char)三个参数分别为字符数组、数组规模和表示输入结束的结束符（getline同理）
	 * 注意cin.get(str, 120, '.')和getline(str, 120, '.')的区别：
	 * 若输入"abcdef."，str均保存字符串"abcdef"，但前者'.'仍保留在缓冲区，后者则将'.'从缓冲区删除
	 *
	 * read函数实现无格式的输入，读入指定个数字节的字符，如遇EOF则提前结束；读取个数可由cin.gcount()函数得到
	 */

	int num = 64;
	cout << "octal: " << oct << num << endl << "hex: " << hex << num << endl;
	cout << "decimal: " << dec << num << endl << endl;

	for (int i = 0; i <= 6; i++) {
		cout.precision(i);
		cout << "precision " << i << ": " << right << setw(10) << d << endl;
	}

	return 0;
}

#include <iostream>
#include <fstream>    //这个头文件是必须要有的
using namespace std;
int main()
{	//我们首先在这个程序所在的文件夹下新建了一个名为data.txt的文件，并在里面写入 1,2 ,注意要在英文状态下输入
	int a, b; char c;     //设置三个变量分别对应上面的两个数字1,2和一个字符“,”
	ifstream fin("data.txt");   //读取文件
	if (!fin)              // 如果读取失败，打印fail
	{
		cerr << "fail" << endl;
		return -1;
	}
	fin >> a >> c >> b;   //读取的东西写入给变量
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	fin.close();       //关闭文件
	a++; b++;
	cout << "change a = " << a << endl;
	cout << "change b = " << b << endl;
	ofstream fout("data2.txt");     //创建一个data.txt的文件
	fout << a << "," << b << endl;	//将变量的值写入文件
	fout.close();                  //关闭文件
	return 0;
}


#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//C语言文件操作

//什么是文件
//文件名
//文件缓冲区
//文件指针
//文件的打开和关闭
//文件的顺序读取
//文件的随机读取
//文件结束的判定




//什么是文件

//磁盘上的文件是文件
//但是在程序设计中，我们一般谈的文件有两种：程序文件和数据文件

//程序文件
//包括源程序文件（后缀为.C）
//      目标文件（windows环境后缀为.obj）
//    可执行程序（windows环境后缀为.exe）

//数据文件
//文件的内容不一定是程序，而是程序运行时读写的数据，比如程序运行需要从中读取数据的文件，或者
//输出内容的文件

//这次讨论的是数据文件，不讨论程序文件

//以前各章所处理数据的输入都是以终端为对象的，即从终端的键盘输入数据，运行结果显示到显示器上
//其实有时候我们会把信息输出到磁盘上，当需要的时候再从磁盘上把数据读取到内存中使用，这里处理
//的就是磁盘上文件


//文件名

//一个文件要有唯一的文件标识，以便用户识别和引用。
//文件名包含三部分：文件路径 + 文件名主干 + 文件后缀

//例如：C:\code\test.txt
//为了方便起见，文件标识常被称为  文件名


//文件类型

//根据数据的组织形式，数据文件被称为 文本文件 或者 二进制文件
//数据在内存中以二进制的形式存储，如果不加转换的输出到外存，就是二进制文件

//如果要求在外存上以ASCLL码的形式存储，则需要在存储前转换。以ASCLL字符的形式存储的文件就是
//文本文件

//一个数据在内存中是怎么存储的呢？
//字符一律以ASCLL形式存储，数值型数据既可以用ASCLL形式存储，也可以用二进制形式存储

//如有整数10000，如果以ASCLL码的形式输出到磁盘上，则磁盘中占用5个字节（每个字符一个字节），
//而二进制形式输出，则在磁盘上只占4个字节



//内存中的存储形式： 10000（十进制）的二进制存储

//00000000 00000000 00100111 00010000
//存储将分成两种形式：

//ASCLL形式
//00110001 00110000 00110000 00110000 00110000
//   49       48        48       48       48

//以二进制形式
//00000000 00000000 00100111 00010000

//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("text.txt", "wb");
//	fwrite(&a, 4, 1, pf);//二进制的形式写道文件中
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//fwrite (Writes data to a stream.)

//size_t fwrite( const void *buffer, size_t size, size_t count, FILE *stream );

//fclose (Closes a stream (fclose) or closes all open streams (_fcloseall).)

//int fclose( FILE *stream );


//文件缓冲区

//ANSIC标准采用“缓冲文件系统”处理的数据文件的，所谓缓冲文件系统是指系统自动地在内存中为程序
//中每一个正在使用的文件开辟一块“文件缓冲区”。从内存向磁盘输出的数据会先送到内存中的缓冲区
//填装缓冲区后才一起送到磁盘上。如果从磁盘向计算机读入数据，则从磁盘文件中读取数据输入到内存
//缓冲区（充满缓冲区），然后再从缓冲区逐个地将数据送到程序数据区（程序变量等）。缓冲区的大小
//根据C编译系统决定的

//PDF中含有图片


//文件指针

//缓冲文件系统中，关键的概念是“文件类型指针”，简称“文件指针”

//每个被使用的文件都在内存中开辟了一个相当的文件信息区，用来存放文件的相关信息（如文件的名字，
//文件状态及文件当前的位置等）。这些信息是保存在一个结构体变量中的。该结构体类型是有结构体的
//系统声明的，取名FILE

//结构体为：
//struct _iobuf
//{
//    char* _ptr;
//    int   _cnt;
//    char* _base;
//    int   _flag;
//    int   _file;
//    int   _charbuf;
//    int   _bufsiz;
//    char* _tmpfname;
//};
//typedef struct _iobuf FILE;

//上面这里面的都是描述维护的文件

//不同的C编译器的FILE类型包含的内容不完全相同，但是大同小异。
//每当打开一个文件的时候，系统会根据文件的情况自动创建一个FILE结构的变量，并填充其中的信息，
//使用者不必关心细节。

//一般都是通过一个FILE的指针来维护这个FILE结构的变量，这样使用起来更加方便。
//下面我们可以创建一个FILE* 的指针变量:

//FILE* pf;//文件指针变量

//定义pf是一个指向FILE类型数据的指针变量。可以使pf指向某个文件的文件信息区（是一个结构体变量）。
//通过该文件信息区中的信息就能够访问该文件。也就是说，通过文件指针变量能够找到与它关联的文件。



//文件的打开和关闭

//文件在读写之前应该先打开文件，在使用结束之后应该关闭文件

//在编写程序的时候，再打开文件的同时，都会返回一个FILE*的指针变量指向该文件，也相当于建立了
//指针和文件的关系

//ANSIC规定使用fopen函数来打开文件，fclose来关闭文件

//int main()
//{
//	//打开文件test.txt
//	//这是相对路径
//	fopen("test.txt", "r");
//
//	// ..表示上一级路径
//	// . 表示当前路径
//	//fopen("../");
//
//
//
//	//绝对路径是：
//	//E:\VS2019编译器存储代码\test 2021-9-9   C language file operation
//	fopen("E:\VS2019编译器存储代码\test 2021-9-9   C language file operation\test.txt", "r");
//	return 0;
//}


//#include <errno.h>
//int main()
//{ 
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL);
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//打开文件
//	//读文件
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//打开文件的方式：
// 文件使用方式                      含 义                          如果指定文件不存在
//  "r"  （只读）   为了输入数据，打开一个已经存在的文本文件            出错
//  "w"  （只写）   为了输出数据，打开一个文本文件                      建立一个新的文件
//  "a"  （追加）   向文本文件尾添加数据                                出错 
//  "rb" （只读）   为了输入数据，打开一个二进制文件                    出错
//  "wb" （只写）   为了输出数据，打开一个二进制文件                    建立一个新的文件
//  "ab" （追加）   向一个二进制文件尾添加数据                          出错
//  "r+" （读写）   为了读和写，打开一个文本文件                        出错
//  "w+" （读写）   为了读和写，新建一个新的文件                        建立一个新的文件
//  "a+" （读写）   打开一个文件，在文件尾进行读写                      建立一个新的文件
//  "rb+"（读写）   为了读和写打开一个二进制文件                        出错
//  "wb+"（读写）   为了读和写，新建一个新的二进制文件                  建立一个新的文件
//  "ab+"（读写）   打开一个二进制文件，在文件尾进行读和写              建立一个新的文件


////写文件
//#include <errno.h>
//int main()
//{
//	FILE* pfWrite = fopen("test.txt", "w");
//	if (pfWrite == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//写文件
//	fputc('T', pfWrite);
//	fputc('o', pfWrite);
//	fputc('n', pfWrite);
//	fputc('g', pfWrite);
//
//
//	//关闭文件
//	fclose(pfWrite);
//	pfWrite = NULL;
//	return 0;
//}


////读文件
//#include <errno.h>
//int main()
//{
//	FILE* pfRead = fopen("test.txt", "r");
//	if (pfRead == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//读文件
//	printf("%c", fgetc(pfRead));//T
//	printf("%c", fgetc(pfRead));//o
//	printf("%c", fgetc(pfRead));//n
//	printf("%c", fgetc(pfRead));//g
//
//
//	//关闭文件
//	fclose(pfRead);
//	pfRead = NULL;
//	return 0;
//}



//从键盘输入
//输出到屏幕
//键盘&屏幕都是外部设备

//键盘 - 标准输入设备
//屏幕 - 标准输出设备
//是一个程序默认打开的两个流设备


//这是三个打开流

//stdin     -  标准输入 
//stdout    -  标准输出
//stderr


//文件的顺序读写

//      功能                  函数名                适用于
//   字符输入函数             fgetc               所有输入流
//   字符输出函数             fputc               所有输出流
//   文本行输入函数           fgets               所有输入流
//   文本行输出函数           fputs               所有输出流
//   格式化输入函数           fscanf              所有输入流
//   格式化输出函数           fprintf             所有输出流
//   二进制输入               fread                  文件
//   二进制输出               fwrite                 文件


//以上函数都可以在MSDN中找到

//#include <errno.h>
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//读文件
//	int ch = fgetc(pf);
//	printf("%c", ch);
//	
//	ch = fgetc(pf);
//	printf("%c", ch);
//
//	ch = fgetc(pf);
//	printf("%c", ch);
//
//	ch = fgetc(pf);
//	printf("%c", ch);//输出一次只输出一个字符
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//上面是fgetc


//int main()
//{
//	char buf[1024] = { 0 };
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//读文件
//	fgets(buf, 1024, pf);//打印出来之后，会加一行换行，所以这个函数自带换行功能
//	//printf("%s", buf);
//	puts(buf);//这个函数也自带换行功能
//
//	fgets(buf, 1024, pf);//打印出来之后，会加一行换行，所以这个函数自带换行功能
//    //printf("%s", buf);
//	puts(buf);//这个函数也自带换行功能
//	
//    //这个打两遍，就会输出两遍
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//上面是fgets


//int main()
//{
//	char buf[1024] = { 0 };
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//写文件
//	fputs("hello", pf);
//	fputs("world", pf);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}//这时，打开这个文件的路径下面，找到test文件，就会发现上面是helloworld



//int main()
//{
//	//从键盘读取一行文本文件
//	char buf[1024] = { 0 };
//	//fgets(buf, 1024, stdin);//从标准输入流读取
//	//fputs(buf, stdout);//输出到标准输入流
//
//	gets(buf);
//	puts(buf);//这个还是会自动换行
//	return 0;
//}


//用一个结构体来表示一下

//#include <errno.h>
//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct S s = { 100,3.14f,"shaanxi" };//这里3.14f，加上f就是float 类型的，不加f，就默认为double类型的
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//格式化的形式写文件
//	//fprintf(pf, "%d %f %s", s.n, s.score, s.arr);
//	fscanf(pf, "%d %f %s", &(s.n), &(s.score), &(s.arr));
//	printf("%d %f %s", s.n, s.score, s.arr);
//	
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct S s = { 0 };
//
//	fscanf(stdin, "%d %f %s", &(s.n), &(s.score), &(s.arr));
//	fprintf(stdout,"%d %f %s", s.n, s.score, s.arr);
//
//
//	return 0;
//}

//对比一组函数

//   scanf/fscanf/sscanf
//   printf/fprintf/sprintf

//scanf和printf 是针对标准输入流/标准输出流的 格式化输入/输出语句
//fscnaf和fprintf 是针对所有输入流/所有输出流的 格式化输入/输出语句
//sscanf和sprintf  
//  sscanf 是从字符串中读取格式化的数据
//  sprintf 是把格式化数据输出成（存储到）字符串

//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct S s = { 100,3.14f,"abcdef" };
//	struct S tmp = { 0 };
//	char buf[1024] = { 0 };
//	//把格式化的数据转换成字符串存储到buf
//	sprintf(buf, "%d %f %s", s.n, s.score, s.arr);
//	//printf("%s\n", buf);
//	//从buf中读取格式化的数据到tmp中
//	sscanf(buf, "%d %f %s", &(tmp.n), &(tmp.score), &(tmp.arr));
//	printf("%d %f %s", tmp.n, tmp.score, tmp.arr);
//	return 0;
//}


//二进制输入和二进制输出
//fread         fwrite


//这是二进制写代码

//struct S
//{
//	char name[20];
//	int age;
//	double score;
//};
//int main()
//{
//	struct S s = { "张三",20,55.6 };
//	FILE* pf = fopen("test.txt", "wb");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//二进制的形式写代码
//	fwrite(&s, sizeof(struct S), 1, pf);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}//打开文档之后，就会发现只有张三是以字符型存储，所以是可以看懂的，其他的是看不懂的
////存储的文档是这个：张三                   吞烫烫K@
////这个张三是二进制代码存储，和字符存储是一样的，所以张三汉字是没问题的



////这是二进制读代码

//struct S
//{
//	char name[20];
//	int age;
//	double score;
//};
//int main()
//{
//	//struct S s = { "张三",20,55.6 };
//	struct S tmp = { 0 };
//	FILE* pf = fopen("test.txt", "rb");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//二进制的形式读代码
//	fread(&tmp, sizeof(struct S), 1, pf);
//	printf("%s %d %lf\n", tmp.name, tmp.age, tmp.score);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}



//fwrite (Writes data to a stream.) //写文件到流

//size_t fwrite( const void *buffer, size_t size, size_t count, FILE *stream );

//fread (Reads data from a stream.) //从流读文件

//size_t fread( void *buffer, size_t size, size_t count, FILE *stream );

//会发现这两个函数的类型是一样的，参数是一样的
//唯一的区别就是const加的位置不一样



//文件的随机读写

//fseek    //定位文件指针函数
//根据文件指针的位置和偏移量来定位文件指针

//fseek (Moves the file pointer to a specified location.)//移动到指定位置

//int fseek( FILE *stream, long offset, int origin );
//这里offset 是偏移量，origin是文件当前的位置
 
//偏移量为正数的时候，是向后移动，当偏移量为负数的时候，向前移动 

//这里第三个参数是有三个选择值

//SEEK_CUR         //文件指针的当前位置
//Current position of file pointer

//SEEK_END         //文件的末尾位置
//End of file

//SEEK_SET         //文件起始的位置
//Beginning of file


////假设文件放的是：a b c d e f
//
//#include <errno.h>
//int main()
//{
//	FILE* pf = fopen("test.txt","r");
//	if (pf == NULL)
//	{
//		strerror(errno);
//		return 0;
//	}
//	//1.定位文件指针
//	//fseek(pf, 2, SEEK_CUR);
//	fseek(pf, -2, SEEK_END);//这个位置值放在了f的后面，从f后面的位置上开始向前数
//	//注意：要后面什么都没有，空格也算
//	//2.读取文件
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	//3.关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}





//ftell (Gets the current position of a file pointer.)
//返回文件指针相对与起始位置的偏移量,也就是返回的是数字
//long ftell( FILE *stream );

//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//int pos = ftell(pf);
//	//printf("%d\n", pos);//打印出来的是0
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//	rewind(pf);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//	//这会打印出来两个a
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//rewind (Repositions the file pointer to the beginning of a file.) - 将文件指针重新定位到文件的开头。

//void rewind( FILE *stream );



//文件结束判定

//被错误使用的feof

//牢记：在文件读取的过程中，不能用feof函数的返回值直接用来判断文件的是否结束
//而是应用于当文件读取结束的时候，判断是读取失败结束，还是遇到文件尾结束


//下一行的EOF会放在文件的末尾，当结束标志
//1、文本文件读取是否结束，判断返回值是否为EOF(fgetc)，或者NULL（fgets）
  //例如：
    //fgetc判断是否为EOF
    //fgets判断返回值是否为NULL
//2、二进制文件的读取结束判断，判断返回值时候小于实际要读的个数
  //例如：
    //fread判断返回值是否小于实际要读的个数


////EOF - end of file - 文件结束标志
//int main()
//{
//    FILE* pf = fopen("test.txt", "r");
//    if (pf == NULL)
//    {
//        return 0;
//    }
//    int ch = fgetc(pf);
//    printf("%d\n", ch);//-1
//    //当文本文件里面什么都没有的时候，就会输出-1
//
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}
//
////feof() - 这个说明文件里面是没有东西的，没有可读取的信息，就会放一个EOF在里面，EOF
////的返回值为-1；转到定义之后，就可发现定义的值为-1


int main()
{
    int c;
    FILE* pf = fopen("test,txt", "r");
    if (!pf)
    {
        perror("File opening failed");//这个函数是先输出括号里面的当成前缀，然后在加错误原因
        //File opening failed: No such file or directory
        return 0;
    }
    //fgetc 当读取失败的时候或者遇到文件结束的时候，都会返回EOF
    
    //这里是读文件
    while ((c = fgetc(pf)) != EOF)//标准C I/O读取文件循环
    {
        putchar(c);
    }
    //判断是什么原因结束的
    if (ferror(pf))
    {
        puts("I/O error when reading");
    }
    else if (feof(pf))
    {
        puts("End of file reached successfully");
    }
    fclose(pf);
    pf = NULL;
    return 0;
}
//用上面perror这个错误函数写更加直观，明确
//strerror - 是将错误码对应的错误信息的字符串地址返回
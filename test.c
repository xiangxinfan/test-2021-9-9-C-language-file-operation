#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//C�����ļ�����

//ʲô���ļ�
//�ļ���
//�ļ�������
//�ļ�ָ��
//�ļ��Ĵ򿪺͹ر�
//�ļ���˳���ȡ
//�ļ��������ȡ
//�ļ��������ж�




//ʲô���ļ�

//�����ϵ��ļ����ļ�
//�����ڳ�������У�����һ��̸���ļ������֣������ļ��������ļ�

//�����ļ�
//����Դ�����ļ�����׺Ϊ.C��
//      Ŀ���ļ���windows������׺Ϊ.obj��
//    ��ִ�г���windows������׺Ϊ.exe��

//�����ļ�
//�ļ������ݲ�һ���ǳ��򣬶��ǳ�������ʱ��д�����ݣ��������������Ҫ���ж�ȡ���ݵ��ļ�������
//������ݵ��ļ�

//������۵��������ļ��������۳����ļ�

//��ǰ�������������ݵ����붼�����ն�Ϊ����ģ������ն˵ļ����������ݣ����н����ʾ����ʾ����
//��ʵ��ʱ�����ǻ����Ϣ����������ϣ�����Ҫ��ʱ���ٴӴ����ϰ����ݶ�ȡ���ڴ���ʹ�ã����ﴦ��
//�ľ��Ǵ������ļ�


//�ļ���

//һ���ļ�Ҫ��Ψһ���ļ���ʶ���Ա��û�ʶ������á�
//�ļ������������֣��ļ�·�� + �ļ������� + �ļ���׺

//���磺C:\code\test.txt
//Ϊ�˷���������ļ���ʶ������Ϊ  �ļ���


//�ļ�����

//�������ݵ���֯��ʽ�������ļ�����Ϊ �ı��ļ� ���� �������ļ�
//�������ڴ����Զ����Ƶ���ʽ�洢���������ת�����������棬���Ƕ������ļ�

//���Ҫ�����������ASCLL�����ʽ�洢������Ҫ�ڴ洢ǰת������ASCLL�ַ�����ʽ�洢���ļ�����
//�ı��ļ�

//һ���������ڴ�������ô�洢���أ�
//�ַ�һ����ASCLL��ʽ�洢����ֵ�����ݼȿ�����ASCLL��ʽ�洢��Ҳ�����ö�������ʽ�洢

//��������10000�������ASCLL�����ʽ����������ϣ��������ռ��5���ֽڣ�ÿ���ַ�һ���ֽڣ���
//����������ʽ��������ڴ�����ֻռ4���ֽ�



//�ڴ��еĴ洢��ʽ�� 10000��ʮ���ƣ��Ķ����ƴ洢

//00000000 00000000 00100111 00010000
//�洢���ֳ�������ʽ��

//ASCLL��ʽ
//00110001 00110000 00110000 00110000 00110000
//   49       48        48       48       48

//�Զ�������ʽ
//00000000 00000000 00100111 00010000

//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("text.txt", "wb");
//	fwrite(&a, 4, 1, pf);//�����Ƶ���ʽд���ļ���
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//fwrite (Writes data to a stream.)

//size_t fwrite( const void *buffer, size_t size, size_t count, FILE *stream );

//fclose (Closes a stream (fclose) or closes all open streams (_fcloseall).)

//int fclose( FILE *stream );


//�ļ�������

//ANSIC��׼���á������ļ�ϵͳ������������ļ��ģ���ν�����ļ�ϵͳ��ָϵͳ�Զ������ڴ���Ϊ����
//��ÿһ������ʹ�õ��ļ�����һ�顰�ļ��������������ڴ��������������ݻ����͵��ڴ��еĻ�����
//��װ���������һ���͵������ϡ�����Ӵ����������������ݣ���Ӵ����ļ��ж�ȡ�������뵽�ڴ�
//����������������������Ȼ���ٴӻ���������ؽ������͵���������������������ȣ����������Ĵ�С
//����C����ϵͳ������

//PDF�к���ͼƬ


//�ļ�ָ��

//�����ļ�ϵͳ�У��ؼ��ĸ����ǡ��ļ�����ָ�롱����ơ��ļ�ָ�롱

//ÿ����ʹ�õ��ļ������ڴ��п�����һ���൱���ļ���Ϣ������������ļ��������Ϣ�����ļ������֣�
//�ļ�״̬���ļ���ǰ��λ�õȣ�����Щ��Ϣ�Ǳ�����һ���ṹ������еġ��ýṹ���������нṹ���
//ϵͳ�����ģ�ȡ��FILE

//�ṹ��Ϊ��
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

//����������Ķ�������ά�����ļ�

//��ͬ��C��������FILE���Ͱ��������ݲ���ȫ��ͬ�����Ǵ�ͬС�졣
//ÿ����һ���ļ���ʱ��ϵͳ������ļ�������Զ�����һ��FILE�ṹ�ı�������������е���Ϣ��
//ʹ���߲��ع���ϸ�ڡ�

//һ�㶼��ͨ��һ��FILE��ָ����ά�����FILE�ṹ�ı���������ʹ���������ӷ��㡣
//�������ǿ��Դ���һ��FILE* ��ָ�����:

//FILE* pf;//�ļ�ָ�����

//����pf��һ��ָ��FILE�������ݵ�ָ�����������ʹpfָ��ĳ���ļ����ļ���Ϣ������һ���ṹ���������
//ͨ�����ļ���Ϣ���е���Ϣ���ܹ����ʸ��ļ���Ҳ����˵��ͨ���ļ�ָ������ܹ��ҵ������������ļ���



//�ļ��Ĵ򿪺͹ر�

//�ļ��ڶ�д֮ǰӦ���ȴ��ļ�����ʹ�ý���֮��Ӧ�ùر��ļ�

//�ڱ�д�����ʱ���ٴ��ļ���ͬʱ�����᷵��һ��FILE*��ָ�����ָ����ļ���Ҳ�൱�ڽ�����
//ָ����ļ��Ĺ�ϵ

//ANSIC�涨ʹ��fopen���������ļ���fclose���ر��ļ�

//int main()
//{
//	//���ļ�test.txt
//	//�������·��
//	fopen("test.txt", "r");
//
//	// ..��ʾ��һ��·��
//	// . ��ʾ��ǰ·��
//	//fopen("../");
//
//
//
//	//����·���ǣ�
//	//E:\VS2019�������洢����\test 2021-9-9   C language file operation
//	fopen("E:\VS2019�������洢����\test 2021-9-9   C language file operation\test.txt", "r");
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
//	//���ļ�
//	//���ļ�
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//���ļ��ķ�ʽ��
// �ļ�ʹ�÷�ʽ                      �� ��                          ���ָ���ļ�������
//  "r"  ��ֻ����   Ϊ���������ݣ���һ���Ѿ����ڵ��ı��ļ�            ����
//  "w"  ��ֻд��   Ϊ��������ݣ���һ���ı��ļ�                      ����һ���µ��ļ�
//  "a"  ��׷�ӣ�   ���ı��ļ�β�������                                ���� 
//  "rb" ��ֻ����   Ϊ���������ݣ���һ���������ļ�                    ����
//  "wb" ��ֻд��   Ϊ��������ݣ���һ���������ļ�                    ����һ���µ��ļ�
//  "ab" ��׷�ӣ�   ��һ���������ļ�β�������                          ����
//  "r+" ����д��   Ϊ�˶���д����һ���ı��ļ�                        ����
//  "w+" ����д��   Ϊ�˶���д���½�һ���µ��ļ�                        ����һ���µ��ļ�
//  "a+" ����д��   ��һ���ļ������ļ�β���ж�д                      ����һ���µ��ļ�
//  "rb+"����д��   Ϊ�˶���д��һ���������ļ�                        ����
//  "wb+"����д��   Ϊ�˶���д���½�һ���µĶ������ļ�                  ����һ���µ��ļ�
//  "ab+"����д��   ��һ���������ļ������ļ�β���ж���д              ����һ���µ��ļ�


////д�ļ�
//#include <errno.h>
//int main()
//{
//	FILE* pfWrite = fopen("test.txt", "w");
//	if (pfWrite == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//д�ļ�
//	fputc('T', pfWrite);
//	fputc('o', pfWrite);
//	fputc('n', pfWrite);
//	fputc('g', pfWrite);
//
//
//	//�ر��ļ�
//	fclose(pfWrite);
//	pfWrite = NULL;
//	return 0;
//}


////���ļ�
//#include <errno.h>
//int main()
//{
//	FILE* pfRead = fopen("test.txt", "r");
//	if (pfRead == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//���ļ�
//	printf("%c", fgetc(pfRead));//T
//	printf("%c", fgetc(pfRead));//o
//	printf("%c", fgetc(pfRead));//n
//	printf("%c", fgetc(pfRead));//g
//
//
//	//�ر��ļ�
//	fclose(pfRead);
//	pfRead = NULL;
//	return 0;
//}



//�Ӽ�������
//�������Ļ
//����&��Ļ�����ⲿ�豸

//���� - ��׼�����豸
//��Ļ - ��׼����豸
//��һ������Ĭ�ϴ򿪵��������豸


//������������

//stdin     -  ��׼���� 
//stdout    -  ��׼���
//stderr


//�ļ���˳���д

//      ����                  ������                ������
//   �ַ����뺯��             fgetc               ����������
//   �ַ��������             fputc               ���������
//   �ı������뺯��           fgets               ����������
//   �ı����������           fputs               ���������
//   ��ʽ�����뺯��           fscanf              ����������
//   ��ʽ���������           fprintf             ���������
//   ����������               fread                  �ļ�
//   ���������               fwrite                 �ļ�


//���Ϻ�����������MSDN���ҵ�

//#include <errno.h>
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//���ļ�
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
//	printf("%c", ch);//���һ��ֻ���һ���ַ�
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//������fgetc


//int main()
//{
//	char buf[1024] = { 0 };
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//���ļ�
//	fgets(buf, 1024, pf);//��ӡ����֮�󣬻��һ�л��У�������������Դ����й���
//	//printf("%s", buf);
//	puts(buf);//�������Ҳ�Դ����й���
//
//	fgets(buf, 1024, pf);//��ӡ����֮�󣬻��һ�л��У�������������Դ����й���
//    //printf("%s", buf);
//	puts(buf);//�������Ҳ�Դ����й���
//	
//    //��������飬�ͻ��������
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//������fgets


//int main()
//{
//	char buf[1024] = { 0 };
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//д�ļ�
//	fputs("hello", pf);
//	fputs("world", pf);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}//��ʱ��������ļ���·�����棬�ҵ�test�ļ����ͻᷢ��������helloworld



//int main()
//{
//	//�Ӽ��̶�ȡһ���ı��ļ�
//	char buf[1024] = { 0 };
//	//fgets(buf, 1024, stdin);//�ӱ�׼��������ȡ
//	//fputs(buf, stdout);//�������׼������
//
//	gets(buf);
//	puts(buf);//������ǻ��Զ�����
//	return 0;
//}


//��һ���ṹ������ʾһ��

//#include <errno.h>
//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct S s = { 100,3.14f,"shaanxi" };//����3.14f������f����float ���͵ģ�����f����Ĭ��Ϊdouble���͵�
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//��ʽ������ʽд�ļ�
//	//fprintf(pf, "%d %f %s", s.n, s.score, s.arr);
//	fscanf(pf, "%d %f %s", &(s.n), &(s.score), &(s.arr));
//	printf("%d %f %s", s.n, s.score, s.arr);
//	
//
//	//�ر��ļ�
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

//�Ա�һ�麯��

//   scanf/fscanf/sscanf
//   printf/fprintf/sprintf

//scanf��printf ����Ա�׼������/��׼������� ��ʽ������/������
//fscnaf��fprintf ���������������/����������� ��ʽ������/������
//sscanf��sprintf  
//  sscanf �Ǵ��ַ����ж�ȡ��ʽ��������
//  sprintf �ǰѸ�ʽ����������ɣ��洢�����ַ���

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
//	//�Ѹ�ʽ��������ת�����ַ����洢��buf
//	sprintf(buf, "%d %f %s", s.n, s.score, s.arr);
//	//printf("%s\n", buf);
//	//��buf�ж�ȡ��ʽ�������ݵ�tmp��
//	sscanf(buf, "%d %f %s", &(tmp.n), &(tmp.score), &(tmp.arr));
//	printf("%d %f %s", tmp.n, tmp.score, tmp.arr);
//	return 0;
//}


//����������Ͷ��������
//fread         fwrite


//���Ƕ�����д����

//struct S
//{
//	char name[20];
//	int age;
//	double score;
//};
//int main()
//{
//	struct S s = { "����",20,55.6 };
//	FILE* pf = fopen("test.txt", "wb");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//�����Ƶ���ʽд����
//	fwrite(&s, sizeof(struct S), 1, pf);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}//���ĵ�֮�󣬾ͻᷢ��ֻ�����������ַ��ʹ洢�������ǿ��Կ����ģ��������ǿ�������
////�洢���ĵ������������                   ������K@
////��������Ƕ����ƴ���洢�����ַ��洢��һ���ģ���������������û�����



////���Ƕ����ƶ�����

//struct S
//{
//	char name[20];
//	int age;
//	double score;
//};
//int main()
//{
//	//struct S s = { "����",20,55.6 };
//	struct S tmp = { 0 };
//	FILE* pf = fopen("test.txt", "rb");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//�����Ƶ���ʽ������
//	fread(&tmp, sizeof(struct S), 1, pf);
//	printf("%s %d %lf\n", tmp.name, tmp.age, tmp.score);
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}



//fwrite (Writes data to a stream.) //д�ļ�����

//size_t fwrite( const void *buffer, size_t size, size_t count, FILE *stream );

//fread (Reads data from a stream.) //�������ļ�

//size_t fread( void *buffer, size_t size, size_t count, FILE *stream );

//�ᷢ��������������������һ���ģ�������һ����
//Ψһ���������const�ӵ�λ�ò�һ��



//�ļ��������д

//fseek    //��λ�ļ�ָ�뺯��
//�����ļ�ָ���λ�ú�ƫ��������λ�ļ�ָ��

//fseek (Moves the file pointer to a specified location.)//�ƶ���ָ��λ��

//int fseek( FILE *stream, long offset, int origin );
//����offset ��ƫ������origin���ļ���ǰ��λ��
 
//ƫ����Ϊ������ʱ��������ƶ�����ƫ����Ϊ������ʱ����ǰ�ƶ� 

//���������������������ѡ��ֵ

//SEEK_CUR         //�ļ�ָ��ĵ�ǰλ��
//Current position of file pointer

//SEEK_END         //�ļ���ĩβλ��
//End of file

//SEEK_SET         //�ļ���ʼ��λ��
//Beginning of file


////�����ļ��ŵ��ǣ�a b c d e f
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
//	//1.��λ�ļ�ָ��
//	//fseek(pf, 2, SEEK_CUR);
//	fseek(pf, -2, SEEK_END);//���λ��ֵ������f�ĺ��棬��f�����λ���Ͽ�ʼ��ǰ��
//	//ע�⣺Ҫ����ʲô��û�У��ո�Ҳ��
//	//2.��ȡ�ļ�
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	//3.�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}





//ftell (Gets the current position of a file pointer.)
//�����ļ�ָ���������ʼλ�õ�ƫ����,Ҳ���Ƿ��ص�������
//long ftell( FILE *stream );

//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//int pos = ftell(pf);
//	//printf("%d\n", pos);//��ӡ��������0
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//	rewind(pf);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//	//����ӡ��������a
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//rewind (Repositions the file pointer to the beginning of a file.) - ���ļ�ָ�����¶�λ���ļ��Ŀ�ͷ��

//void rewind( FILE *stream );



//�ļ������ж�

//������ʹ�õ�feof

//�μǣ����ļ���ȡ�Ĺ����У�������feof�����ķ���ֱֵ�������ж��ļ����Ƿ����
//����Ӧ���ڵ��ļ���ȡ������ʱ���ж��Ƕ�ȡʧ�ܽ��������������ļ�β����


//��һ�е�EOF������ļ���ĩβ����������־
//1���ı��ļ���ȡ�Ƿ�������жϷ���ֵ�Ƿ�ΪEOF(fgetc)������NULL��fgets��
  //���磺
    //fgetc�ж��Ƿ�ΪEOF
    //fgets�жϷ���ֵ�Ƿ�ΪNULL
//2���������ļ��Ķ�ȡ�����жϣ��жϷ���ֵʱ��С��ʵ��Ҫ���ĸ���
  //���磺
    //fread�жϷ���ֵ�Ƿ�С��ʵ��Ҫ���ĸ���


////EOF - end of file - �ļ�������־
//int main()
//{
//    FILE* pf = fopen("test.txt", "r");
//    if (pf == NULL)
//    {
//        return 0;
//    }
//    int ch = fgetc(pf);
//    printf("%d\n", ch);//-1
//    //���ı��ļ�����ʲô��û�е�ʱ�򣬾ͻ����-1
//
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}
//
////feof() - ���˵���ļ�������û�ж����ģ�û�пɶ�ȡ����Ϣ���ͻ��һ��EOF�����棬EOF
////�ķ���ֵΪ-1��ת������֮�󣬾Ϳɷ��ֶ����ֵΪ-1


int main()
{
    int c;
    FILE* pf = fopen("test,txt", "r");
    if (!pf)
    {
        perror("File opening failed");//����������������������ĵ���ǰ׺��Ȼ���ڼӴ���ԭ��
        //File opening failed: No such file or directory
        return 0;
    }
    //fgetc ����ȡʧ�ܵ�ʱ����������ļ�������ʱ�򣬶��᷵��EOF
    
    //�����Ƕ��ļ�
    while ((c = fgetc(pf)) != EOF)//��׼C I/O��ȡ�ļ�ѭ��
    {
        putchar(c);
    }
    //�ж���ʲôԭ�������
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
//������perror���������д����ֱ�ۣ���ȷ
//strerror - �ǽ��������Ӧ�Ĵ�����Ϣ���ַ�����ַ����
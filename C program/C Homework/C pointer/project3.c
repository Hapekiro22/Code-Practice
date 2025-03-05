//实现字符串拼接
#include <stdio.h>
#include <stdlib.h>

extern char *p;    // 外部指针的引用性声明，p指向连接后的串

int main( int argc, char *argv[])
{
  /**********  Begin  **********/
  int sumlen = 0,lenn=0;
  int i;
  for(i=0;i<argc;i++)
  {
      for(int j=0;*(*(argv+i)+j)!='\0';j++)
      {
          sumlen++;                         //计算字符串总长度
      }
  }
  p = (char*)malloc(sumlen*sizeof(char));   //分配内存
  
  for(i=0;i<argc;i++)
  {
      for(int j=0;*(*(argv+i)+j)!='\0';j++)
      {
          *(p+lenn) = *(*(argv+i)+j);       //将字符串拼接到p指向的位置
          lenn++;                           //记录当前指针位置
      }
  }

  return 0;
}
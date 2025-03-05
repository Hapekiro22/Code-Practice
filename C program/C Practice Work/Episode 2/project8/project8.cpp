
#include<stdio.h>

int main()
{
    char c;
    int string = 0,chars = 0,row = 0;
    int check = 1<<7, i = 0, mark = 0;


    while((c = getchar())!=EOF)
    {
         if(c&check)                                           //检查汉字高位字节，其高字节首位为1 ？？ 
         {
              if(!(i%1))  {                                     //VSC中汉字是三个字节
                  string++;
                  chars++;
                  mark = 0;                                      
              }
              i++;
         }                                                   
         else
         {
             if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))             
             {
                 chars++;                                     //碰到字母的时候给第一个空格做标记
                 mark = 1;

             }
             if(((c==' ')||(c=='\n')||(c=='\t'))&&mark)
             {
                 string++;                                    //碰到空格后消除这种标记
                 mark = 0;                                    
             }
         }
         if(c=='\n') row++;
    }

    printf("The String is %d\n",string);
    printf("The Chars is %d\n",chars);
    printf("The row is %d",row);

    return 0;

}

//构造一个n个元素的字典并实现快速对照
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 20
#define LENGTHS 50000

typedef struct dictionaryPages
{
    long long nums;
    char *words;
    char indexc;
    struct dictionaryPages *next;
}dictionaryPages;

void LinkDicSeries(dictionaryPages **index);
void LinkXSeries(dictionaryPages *index, char x,char *word,long long num);    //index是x的索引指针
long long SearchWord(dictionaryPages *index, char *word);
void PrintDictionary(dictionaryPages **index);
char *TurnNumToWord(long long num);

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    //生成字典索引
    dictionaryPages **index = (dictionaryPages**)malloc(26*sizeof(dictionaryPages*));
    int i;
    for(i = 0;i < 26;i++)
    {
        *(index + i) = (dictionaryPages *)malloc(sizeof(dictionaryPages));
        (*(index + i)) -> nums = -1;
        (*(index + i)) -> words = '\0';             
        (*(index + i)) -> indexc = 'a' + i;
        (*(index + i)) -> next = NULL;
    }
    //存放具体内容
    for(i = 0;i < n;i++)
    {
        char *word = (char *)malloc(LENGTH*sizeof(char));
        long long num;
        scanf("%s %lld",word,&num);
        char x = *word;
        LinkXSeries(*(index + x - 'a'),x,word,num);
    }
    //生成完整字典
    LinkDicSeries(index);
    //PrintDictionary(index);                       //测试字典是否生成正确
    getchar();
    //录入待翻译语句
    char **sentences  = (char **)malloc(m*sizeof(char *));
    for(i = 0;i < m;i++)
        sentences[i] = (char *)malloc(LENGTHS*sizeof(char));
    for(i = 0;i < m;i++)
    {
        char c;
        int flag = 0,j = 0;
        while((c = getchar())!='\n')
        {
            flag = (c == '{'? 1: 0);
            if(!flag)
                sentences[i][j++] = c;
            else
            {
                char *word = (char *)malloc(LENGTH*sizeof(char));
                char *temp = word; 
                char c1;
                while((c1 = getchar())!='}')
                {
                    *temp = c1;
                    temp++;
                }
                *temp = '\0'; 
                //printf("The untranslated word is %s\n",word);
                char x = *word;
                long long num = SearchWord(*(index + x - 'a'),word);
                char *numword = TurnNumToWord(num);
                int k;
                for(k = 0;k < strlen(numword);k++)
                    sentences[i][j++] = numword[k];
                flag = 0;
                free(word);
            }
        }
    }

	FILE *file = fopen("test.txt","w");
    for(i = 0;i < m;i++)
    {
    	int j;
        for(j = 0;j < strlen(sentences[i]);j++)
        	fputc(sentences[i][j],file);
        fputc('\n',file);
    }
    fclose(file);
    
    int ll;
    scanf("%d",&ll);

    free(index);
    return 0;
}

void LinkDicSeries(dictionaryPages **index)
{
    const int length = 26;
    int i;
    for(i = 0;i < length-1;i++)
    {    
        dictionaryPages *p = *index;
        while(p->next != NULL)
            p = p->next;            // 先将各序列头指针移到尾指针
        p->next = *(index + i + 1);
    }
    return;
}

void LinkXSeries(dictionaryPages *index, char x,char *word,long long num)
{
    dictionaryPages *p = index;
    while(p -> next != NULL)
        p = p -> next;              //移动到尾指针，添加新元素 
    p -> next = (dictionaryPages *)malloc(sizeof(dictionaryPages));
    p = p -> next;
    p -> nums = num;
    p -> words = (char *)malloc(LENGTH*sizeof(char));
    strcpy(p -> words,word);
    p -> indexc = x;
    p ->next = NULL;
    return;
}


long long SearchWord(dictionaryPages *index, char *word)
{
    dictionaryPages *p = index -> next;
    //printf("The word to be checked is %s\n",word);
    //printf("The index letter is %c\n",p -> indexc);
    while(p -> indexc == *word)
    {
        //printf("Now checking %s\n",p -> words);
        if(!strcmp(p -> words,word))
        {
            //printf("%d",p -> nums);
            return p -> nums;
        }
        p = p->next;
    }
    //printf("error");
}

void PrintDictionary(dictionaryPages **index)
{
    const int length = 26;
    dictionaryPages *p = *index;
    int i;
    for(i = 0;i < length;i++)
    {
        while(p != NULL)
        {
            printf("%c:%s-->%d\n",p -> indexc,p -> words,p -> nums);
            p = p -> next;
        }
    }
    return;
}

char *TurnNumToWord(long long num)
{
    char *word = (char *)malloc(LENGTH*sizeof(char));
    int i = 0;
    while(num)
    {
        word[i++] = num%10 + '0';
        num /= 10;
    }
    int j;
    for(j = 0;j < i/2;j++)
    {
        char temp = word[j];
        word[j] = word[i-j-1];
        word[i-j-1] = temp;
    }
    word[i] = '\0';
    return word;
}


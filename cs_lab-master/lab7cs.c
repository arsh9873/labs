#include <string.h>
#include <stdio.h>
void counter(char *p)
{
int character=0,space=0,line=0,tab=0;
while((*p)!='\0')
        {
        if((*p)!=' ' || (*p)!='\t')
        {character++;
        }
        if((*p)==' ')
                {
                space++;
                }
        if((*p)=='.')
                {
                line++;
                }
        if((*p)=='\t')
                {
                tab++;
                }
        p++;        
        }
printf("\nnumber of characters:%d,spaces:%d,lines:%d and tabs:%d",character,space,line,tab);
}
int len(char*p)
{
int lenght=0;
while((*p)!='\0')
    {
    lenght++;
    }
return lenght;
}

void counter_2(char *s)
{
int vowel_count=0;
while((*s)!='\0')
{
    if ( (*s) == 'a' || (*s) == 'e' || (*s) == 'i' || (*s) == 'o' || (*s) == 'u' || (*s) == 'A' || (*s) == 'E' || (*s) == 'I' || (*s) == 'O' || (*s) == 'U')
    {
    vowel_count++;
    }
    s++;
}
printf("\nnumber of vowels:%d",vowel_count);
}


int main()
{
        char str[100];
printf("enter your peice of text");
printf("\n");
fgets(str,sizeof(str),stdin);
printf("\n*********");
counter(str);
counter_2(str);
return 0;
}

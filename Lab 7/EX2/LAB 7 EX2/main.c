#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int isPalindrome(char *s, int l);
int i=0;
int count=0;
char *alpha(char *s);
int main()
{    char buf[100];

      printf("Enter a sequence:\n");
      fgets(buf,100,stdin);

    isPalindrome(alpha(buf), strlen(alpha(buf)));
    return 0;
}

char *alpha(char *s){

char *str=malloc((strlen(s)+1)*sizeof(char));
int i,j=0;

for(int i=0;i<strlen(s);i++){
    if(isalpha(s[i])!=0){
       str[j]=tolower(s[i]);
       j++;
    }
}
str[j]='\0';
return str;
}


int isPalindrome(char *s, int l){

   if(s[i]!=s[l-i-1])
    {printf("The sequence is not palindrom");
      return; }

   count++;
   if(count==l/2)
    {printf("The sequence is palindrom");
      return; }

    i++;
    isPalindrome(s,l);

}




//EX F
/*int l=1;
void triangle(int n);
int main()
{ int m;
    printf("Enter a number:\n");
    scanf("%d",&m);

    triangle(m);
    return 0;
}
void triangle(int n){
int i;
if(l==n){
    for(i=0;i<l;i++)
        printf("%d",l);
    printf("\n");
    return;
}

for(i=0;i<l;i++)
        printf("%d",l);
    printf("\n");

    l++;
    triangle(n);

}*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX_PRODUCTIONS 10

int n;
char a[MAX_PRODUCTIONS][10];

void first(char ch);
void follow(char ch);

int main(){
    int x;
    char ch;
    
    printf("Enter the number of productions: ");
    scanf("%d",&n);
    
    printf("Enter the productions: ");
    for(int i=0;i<n;i++){
        scanf("%s",a[i]);
    }
    getchar();
    
    do {
        printf("Enter the element to find first and follow: ");
        scanf(" %c", &ch); // Space added before %c to consume newline
        printf("First(%c)= {", ch);
        first(ch);
        printf("}");
        printf("\nFollow(%c)= {", ch);
        follow(ch);
        printf("}");
        printf("\nDo you want to continue?(0/1)");
        scanf("%d", &x);
        getchar();
    } while(x == 1);
    
    return 0;
}

void first(char ch){
    int i;
    if(islower(ch) || ch == '#'){
        printf("%c, ", ch);
        return;
    } else {
        for(i = 0; i < n; i++){
            if(a[i][0] == ch){
                if(islower(a[i][2]) || a[i][2] == '#'){
                    printf("%c, ", a[i][2]);
                } else {
                    first(a[i][2]);
                }
            }
        }
    }
}

void follow(char ch){
    int i, j;
    if(a[0][0] == ch){
        printf("$");
    }
    for(i = 0; i < n; i++){
        for(j = 2; j < strlen(a[i]); j++){
            if(a[i][j] == ch){
                if(a[i][j+1] != '\0'){
                    first(a[i][j+1]);
                } else if(a[i][0] != ch){
                    follow(a[i][0]);
                }
            }
        }
    }
}

# include <stdio.h>
# include <iostream>
int main(){
    char c;
    int q=1;
    while((c=getchar()) !=EOF){
        if(c=='"') {
            printf("%s",q?"``":"''");
            q=!q;
        }
        else printf("%c",c);
    }
    return 0;
}
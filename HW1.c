#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sort(int n,char str[]){
    int i,m;
    char c;
    for(m=n;m>=2;m--){
        for(i=0;i<m-1;i++){
            if(str[i]>str[i+1]){
                c=str[i],str[i]=str[i+1],str[i+1]=c;
            }
        }
    }
}

void Worth(int n,char str1[],int str2[]){
    int i;
    for(i=0;i<n;i++){
        if(str1[i]=='j'||str1[i]=='k'||str1[i]=='q'||str1[i]=='x'||str1[i]=='z') str2[i]=3;
        else if(str1[i]=='c'||str1[i]=='f'||str1[i]=='h'||str1[i]=='l'||str1[i]=='m'||str1[i]=='p'||str1[i]=='v'||str1[i]=='w'||str1[i]=='y') str2[i]=2;
        else str2[i]=1;
    }
}

int main(){
    char moji[20],word[20],wordarray[20],highestword[20],fileName[]="dictionary.txt";
    int i,j,k,l,m=0,n,num,count,score,highest=0,worth[20];
    FILE *myFile;

    printf("文字数を入力：");
    scanf("%d",&n);
    //文字を入力
    for(i=0;i<n;i++){
        printf("moji[%d]=",i);
        scanf("%*c%c",&moji[i]);
    }
    moji[i]='\0';
    
    //文字をソート
    sort(n,moji);

    //文字に点の情報を加える
    Worth(n,moji,worth);
    
    //dictionaryファイルを開く
    myFile=fopen(fileName,"r");
    while(fscanf(myFile,"%s",word)!=EOF){
        num=0;//numはwordの文字数
        while(word[num]!='\0'){
            num++;
        }
        strcpy(wordarray,word);//wordをソートするためwordarrayにコピー
        sort(num,wordarray);//wordをソートしたものがwordarrayに
        l=0,count=0,score=0;
        for(i=0;i<num;i++){
            for(j=l;j<n;j++){
                if(wordarray[i]==moji[j]){
                    score+=worth[j];
                    l=j+1;
                    count++;
                    break;
                }
            }
            if(j==n) break;
        }
        if(count==num){
            //スコア計算
            score=(score+1)*(score+1);
            if(highest<score){
                highest=score;
                strcpy(highestword,word);
            }
        }
    }
    fclose(myFile);
    printf("%d点：%s\n",highest,highestword);
    system("pause");
}
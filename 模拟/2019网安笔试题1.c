#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char PASSWORD_FILE[20] = "password.bat";
const char BASE[60] = "0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int indexOf(char c){
    if(c >= 'a' && c <= 'z') return c - 'a' + 1;
    else if(c >= 'A' && c <= 'Z') return c - 'A' + 27;
    else return 0;
}

void *Encrypt(char *dest,char data[],int n){
    for(int i = 0;i < n;i ++){
        int index = indexOf(data[i]);
        dest[i] = index ? BASE[index * 3 % 52 ? index * 3 % 52 : 52] : data[i];
    }
}

int login(){
    char password[25];
    FILE *file = fopen(PASSWORD_FILE,"r");
    fscanf(file,"%20s",password);
    while(1){
        printf("请输入密码:");
        char input[25],encrypt[25];
        scanf("%20s",input);
        Encrypt(encrypt,input,strlen(input));
        if(!strcmp(password,encrypt)){
            printf("登陆成功！\n");
            return 1;
        }else{
            printf("您输入的密码有误，请重新输入！\n");
        }
    }
    fclose(file);
    return 0;
}

void update(){
    char password[25];
    FILE *file = fopen(PASSWORD_FILE,"r");
    fscanf(file,"%20s",password);
    int tryn = 0;
    while(tryn++ < 3){
        printf("请输入原密码，再输入新的密码:");
        char input[25],encrypt[25],newpwd[25],newencrypt[25] = {0};
        scanf("%20s",input);
        Encrypt(encrypt,input,strlen(input));
        if(!strcmp(password,encrypt)){
            scanf("%20s",newpwd);
            Encrypt(newencrypt,newpwd,strlen(newpwd));
            FILE *wfile = fopen(PASSWORD_FILE,"w");
            fprintf(wfile,"%s",newencrypt);
            fclose(wfile);
            printf("修改密码成功！\n");
            break;
        }else{
            printf("您输入的密码有误，请重新输入！\n");
        }
    }
    fclose(file);
}

int main(){
    while(1){
        printf("请输入命令代码:\n(1)登陆\n(2)修改密码\n(3)退出\n");
        int input;
        scanf("%d",&input);
        if(input == 1){
            if(login()) return 1;
        }else if(input == 2){
            update();
        }else if(input == 3){
            exit(0);
        }else{
            printf("您输入的命令代码有误，请重新输入！\n");
        }
    }
}
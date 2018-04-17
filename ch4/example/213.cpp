/**
 * 1.readchar处理读入时可能会遇到编码文本由多行组成的问题，因此用这种方法一直读到不为换行字符为止；
 * 2.readint用来读取确定位数后的编码文本；
 * 3.readcode主要是将编码文本对应到code[len][value]数组当中。读到EOF表示文件读取完毕；读到换行符表示当前编码本读取完毕。
 ** /
/**/
#include <stdio.h>
#include <string.h>

/*一直读取到非换行符为止*/
int readchar(){
    for(;;){
        int ch = getchar();
        if(ch != '\n' && ch != '\r')
            return ch;
    }
}

/*读取c位的字符并求出其对应的值*/ 
int readint(int c){
    int v = 0;
    while(c--) {
        v = v * 2 + readchar() - '0';
    }
    return v;
}

/*将初始字符对应到相应的位置，code[length][value]*/
int code[8][1<<8];
int readcodes(){
    memset(code, 0, sizeof(code));  //清空数组
    code[1][0] = readchar();
    for(int len = 2; len <= 7; len++) {
        for(int i = 0; i < (1 << len) - 1; i++) {
            int ch = getchar();
            if(ch == EOF) return 0; //读到EOF表示没有编码数据
            if(ch == '\n' || ch == '\r') return 1;  //读到换行表示编码数据录入结束
            code[len][i] = ch;
        }
    }
    return 1;
}

int main(int argc, char const *argv[]) 
{
    while(readcodes()){
        for(;;){
            int len = readint(3);
            if(len == 0)    break;
            for(;;) {
                int v = readint(len);
                if(v == (1 << len) - 1) break;
                putchar(code[len][v]);
            }
        }
        putchar('\n');
    }
    return 0;
}
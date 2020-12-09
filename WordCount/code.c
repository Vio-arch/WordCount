#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]){
	int i,cnt = 0, countword = 0;
	char ch, filename[80];
	FILE *fp;
	fp = fopen(argv[2],"r");
	if(strcmp(argv[1],"-c") == 0 || strcmp(argv[1],"-C") == 0){
		while(!feof(fp)){
			ch = getc(fp);
			printf("%c",ch);
			cnt ++;
		}
		printf("字符数：%d\n",--cnt);
	}
	else if(strcmp(argv[1],"-w") == 0 || strcmp(argv[1],"-W") == 0){
		cnt = 0;
		while(!feof(fp)){
			ch = getc(fp);
			//读到回车就结束循环输出答案 
			if(ch == '\n'){    
				break;
			}else if(ch != ' '){ //不为空格且满足下面条件的就为一个单词
				if(ch >= 'a' && ch <= 'z' || ch>='A' && ch <= 'Z' || ch >= '0' && ch <= '9'){
					printf("%c",ch);
					countword++;   //用首字母统计单词个数
					cnt++;   //cnt是为了统计字母长度
				}
				while(!feof(fp)){
					ch = getc(fp);
					printf("%c",ch);
					if(ch == ' ' || ch == '\n'){ //读到空格或者回车说明这个字母结束了
						break;
					}
					cnt++;
				}
				//循环结束后字母长度大于1的countword加1,等于1的已经统计过了
				//之所以统计cnt是为了防止读一个字母以后立刻读入了空格或者回车造成重复相加
				if(cnt > 1){
					if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9')
						countword++;
				}
				if(ch == '\n'){
					break;//这个break和上面的第二个break联系在一起跳出整个循环； 
				}
			} 
		}
		printf("单词数：%d\n",countword);
	}
	return 0;
}
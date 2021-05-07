#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void Count(char* filename, char a[]) {//本方法用于记录字符数和单词数的个数
	FILE* f;//指向相关文件
	int charCount = 0;//字符数
	int wordCount = 0;//单词数
	int i;
	char buffer[500];//缓冲
	char c;
	int bufferLen;//文件中所有单元总长度
	int isLastBlank = 0;
	while (fgets(buffer, 500, f) != NULL) {
		int a = 0;
		bufferLen = strlen(buffer);
		for (i = 0; i < bufferLen; i++) {
			c = buffer[i];
			if (a == 0) {
				if (c == ' ' || c == '\t' || c == ',') {
					if (c != ',') {
						charCount++;
					}
					continue;
				}
				else {
					charCount++;
					wordCount++;
					a = 1;
				}
			}
			else {
				if (c == ' ' || c == '\t' || c == ',') {
					if (c != ',') {
						charCount++;
					}
					if (isLastBlank == 0) {
						wordCount++;
					}
					isLastBlank = 1;
				}
				else if (c != ',') {
					charCount++;
					isLastBlank = 0;
				}
			}
		}
	}
	fclose(f);
	if (strcmp(a, "-c") == 0) {
		printf("字符数：%d\n", charCount);
	}
	if (strcmp(a, "-w") == 0) {
		printf("单词数：%d\n", wordCount);
	}
}
int main(int argc, char* argv[]) {//argv[] 读取的是命令行输入的字符串
	char* filename = argv[2];
	Count(filename, argv[1]);
}

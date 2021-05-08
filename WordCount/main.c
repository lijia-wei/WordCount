#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *getCharNum(char *filename);   //统计文本文件字符个数 
int *getWordNum(char *filename);   //统计文本文件单词个数 
//C:\Users\14364\Desktop\input.txt

int main(int argc, char *argv[]) {
	//统计input.txt中的字符数 "-c" ;统计input.txt中的单词数 "-w";
	char *parameter = argv[1];
	char *input_file_name = argv[2]; 
	int CharNum;               //字符数
	int WordNum;      		   //单词数
	if(strcmp(parameter, "-c") == 0){
		printf("%d", getCharNum(input_file_name));
	}else if(strcmp(parameter, "-w") == 0){
		printf("%d", getWordNum(input_file_name));
	}else{
		printf("Error!/n");
	}
	return 0;
}

int *getCharNum(char *filename){
	FILE *fp;    //指向文件的指针 
	char sentence[1003];
	int sentenceLen;
	int charNum = 0;
	fp = fopen(filename, "r");
	if(fp == NULL){		
		perror("文件打开错误！");
		return NULL;
	}
	fgets(sentence, 1000, fp);
	sentenceLen = strlen(sentence);	
	return sentenceLen;
}

int *getWordNum(char *filename){
	FILE *fp;    //指向文件的指针 
	char sentence[1003];
	int sentenceLen;   
	char c;            //文本中的字符 
	int flag = 0;      //标记上一个字符是否为空格 
	int wordNum = 0;   //单词数 
	int i;
	fp = fopen(filename, "r");
	if(fp == NULL){		
		perror("文件打开错误！");
		return NULL;
	}
	fgets(sentence, 1000, fp);
	sentenceLen = strlen(sentence);
	for(i = 0; i<sentenceLen; i++){
		
		c = sentence[i];
		if(c == ' ' || c == '\t'){
			if(flag == 0){
				wordNum++;
				flag = 1;
			} 
		}else{
			flag = 0;
		}
	}
	return wordNum;
}

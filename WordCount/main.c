#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *getCharNum(char *filename);   //ͳ���ı��ļ��ַ����� 
int *getWordNum(char *filename);   //ͳ���ı��ļ����ʸ��� 
//C:\Users\14364\Desktop\input.txt

int main(int argc, char *argv[]) {
	//ͳ��input.txt�е��ַ��� "-c" ;ͳ��input.txt�еĵ����� "-w";
	char *parameter = argv[1];
	char *input_file_name = argv[2]; 
	int CharNum;               //�ַ���
	int WordNum;      		   //������
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
	FILE *fp;    //ָ���ļ���ָ�� 
	char sentence[1003];
	int sentenceLen;
	int charNum = 0;
	fp = fopen(filename, "r");
	if(fp == NULL){		
		perror("�ļ��򿪴���");
		return NULL;
	}
	fgets(sentence, 1000, fp);
	sentenceLen = strlen(sentence);	
	return sentenceLen;
}

int *getWordNum(char *filename){
	FILE *fp;    //ָ���ļ���ָ�� 
	char sentence[1003];
	int sentenceLen;   
	char c;            //�ı��е��ַ� 
	int flag = 0;      //�����һ���ַ��Ƿ�Ϊ�ո� 
	int wordNum = 0;   //������ 
	int i;
	fp = fopen(filename, "r");
	if(fp == NULL){		
		perror("�ļ��򿪴���");
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

#ifndef HUFFMAN
#define HUFFMAN

#include <stdio.h>

#define GetBit(dat,i) ((dat&(0x0001<<i))?1:0)
#define SetBit(dat,i) ((dat)|=(0x0001<<(i)))
#define ClearBit(dat,i) ((dat)&=(~(0x0001<<(i))))

typedef struct HUFFMAN_TABLE {
    unsigned char alpha;    // 记录当前字母是什么
    int freq;    // 记录当前字母频率
    int leftChild;    // 代表是否为左孩子
    int rightChild;    // 代表是否有右孩子
    unsigned char flag;    // 代表是否被访问过
    char *huffmancode;    // 记录当前字母的编码内容
}HUFFMAN_TABLE;

typedef struct FREQ {
    unsigned char alpha;    // 记录当前字母是什么
    int freq;    // 记录当前字母频率
}FREQ;

// UI/UI_Main.c
void UI_Entrance(void);
void UI_ShowMenu(void);

// Build/BuildHuffman.c
HUFFMAN_TABLE *Build_InitHuffTree(FREQ *freq, int alphaaccount);
HUFFMAN_TABLE *Build_CreateHuffTree(FREQ *freq, int alphaaccount);
void Build_MakeHuffmanCode(HUFFMAN_TABLE *Huf,int root, int codeIndex, char *code);

// Handle/Handle_Huff
int Handle_GetHuffStringLen(HUFFMAN_TABLE *Huf, int alphaaccount);
void Handle_ShowHuffTree(HUFFMAN_TABLE*Huf, int alphaaccount);

// Handle/Handle_Freq
int Handle_GetFreq(FILE *fp, FREQ **freq, int *alphaIndex);
int Handle_SelectMinFreq(HUFFMAN_TABLE *Huf, int account);

// Handle/Handle_Enci
void Handle_CodeFile(HUFFMAN_TABLE *Huf, int *alphaHuffindex, char *sourceFilename, char *enciName);
void Handle_DecodeFile(HUFFMAN_TABLE*Huf, char* enciName, int alphaaccount);
void Handle_CompareFile(char *File1, char *File2);

// Handle/Handle_Comp
int Handle_CodingString(HUFFMAN_TABLE *Huf, int alphaaccount,FREQ *freq, int *alphaIndex, char *sourceFilename, char *enciName);
void Handle_DecodingString(HUFFMAN_TABLE*Huf, char* enciName, char* sourceFileName, int alphaaccount, int bit);

#endif

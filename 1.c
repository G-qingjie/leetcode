#include <stdio.h>

// 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
// 此问题已解决。

int lengthOfLongestSubstring(char * s){
    char *p = s;    //dizeng
    char *start = s;    //qidian 
    int max_len = 0;
    char *array[256] = {};

    while(p!=NULL && *p!='\0') {
        
        if (array[*p] && *array[*p] == *p) {
            if (start <= array[*p]) {
                start = array[*p]+1;
            }
        }
        array[*p] = p;
        p++;
        max_len = max_len>(p-start)?max_len:(p-start);
        printf(" $ max_len:%d start:%c|%p p:%c|%p\n", max_len, *start, start, *(p-1), p-1);
    }
    printf("1 max_len:%d\n", max_len);
    max_len = max_len?max_len:(p-start);
    return max_len;
}

int main(int argc, char **argv)
{
    
    printf("max:%d \n", lengthOfLongestSubstring(argv[1]));
    return 0;
}
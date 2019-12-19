#include <cstdio>
#include <algorithm>
#include <cstring>

void copy(char *dest,char *source,int len){
	for(int i = 0;i < len;i ++){
		dest[i] = source[i];
	}
	dest[len] = '\0';
}

void preOrder(char *inOrder,char *postOrder){
	int len = strlen(postOrder);
	char root = postOrder[len - 1];
	printf("%c",root);
	int index = std::find(inOrder,inOrder + strlen(inOrder) - 1,root) - inOrder;
	char inOrder1[10],inOrder2[10],postOrder1[10],postOrder2[10];
	copy(inOrder1,inOrder,index);
	copy(inOrder2,inOrder + index + 1,len - index - 1);
	copy(postOrder1,postOrder,index);
	copy(postOrder2,postOrder + index,len - index - 1);
	if(index != 0)
		preOrder(inOrder1,postOrder1);
	if(index != len - 1)
		preOrder(inOrder2,postOrder2);
}

int main(){
	char inOrder[10],postOrder[10];
	scanf("%s%s",inOrder,postOrder);
	preOrder(inOrder,postOrder);
}

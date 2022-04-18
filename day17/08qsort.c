/*
 qsort练习
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int chinese;
	int english;
	int math;
} rank;
int comp(const void *p_num1, const void *p_num2){
    const rank *p_rank1 = (const rank*)p_num1;
	const rank *p_rank2 = (const rank*)p_num2;
	if ((p_rank1->chinese + p_rank1->english + p_rank1->math) > (p_rank2->chinese + p_rank2->english + p_rank2->math)){
	    return 1;
	}
    else if ((p_rank1->chinese + p_rank1->english + p_rank1->math) < (p_rank2->chinese + p_rank2->english + p_rank2->math)){
	    return -1;
	}
	else {
	    return 0;
	}
}
int main(){
   rank ranks[5] = {{72, 83, 61},{49, 98, 77}, 
                    {27, 53, 90},{16, 44, 86}, 
                    {38, 62, 100}};
   int pos = 0;
   qsort(ranks, 5, sizeof(rank), comp);
   for(pos = 0;pos <= 4;pos++){
      printf("%3d %3d %3d %3d\n", ranks[pos].chinese, ranks[pos].english, ranks[pos].math, ranks[pos].chinese + ranks[pos].english + ranks[pos].math);
   }
   return 0;
}

#include <stdio.h>
#include <pthread.h>

char* data[5];//最多存5个人名,这里是在BSS段，主函数执行之前会清零,是空指针不是野指针
int size = 0;//人数，数组下标
void* task(void* p){
  data[size] = p;
  sleep(1);
  size++;
} 
int main(){
  data[size] = "liubei";
  size++;
  pthread_t id1,id2;
  pthread_create(&id1,0,task,(void*)"guanyu");
  pthread_create(&id2,0,task,(void*)"zhangfei");
  pthread_join(id1,0);
  pthread_join(id2,0);
  int i;
  for(i=0;i<size;i++){
	 printf("%p\n",data[i]);
     printf("%s\n",data[i]);
  }
}

/*
 data[size] 这种写法其实并不复杂，它是数组的常见用法。让我们一步步理解它：
 
 数组的概念：data 是一个数组，定义为 char* data[5];。这意味着 data 数组最多可以存储 5 个元素，每个元素的类型是 char*，即一个字符串的指针。这种数组可以存储多个字符串的指针。
 
 下标访问：数组的下标从 0 开始，比如 data[0] 代表第一个元素，data[1] 代表第二个元素，依此类推。data[size] 表示访问 data 数组中第 size 个位置的元素。
 
 使用 data[size] = p; 的含义：当我们写 data[size] = p; 时，我们将指针 p 赋值给 data 数组的第 size 个位置。这通常是用来动态添加数据到数组的某个位置。这里假设 p 是一个 char* 类型（即一个字符串），比如表示一个人的名字。那么 data[size] = p; 就是将这个名字指针存储到数组中的特定位置，以便以后使用。
 
 为什么要这样写：这种写法简洁明了，可以在数组中按位置存储每个人的名字指针。例如，如果当前有 3 个人的名字存储在 data 中，那么 size 会是 3。下一次调用时，可以将 data[3] = p;，表示将第 4 个人的名字存储到数组中。
 */

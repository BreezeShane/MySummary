# 关于我这周在科协学习的那点事
## 2020/11/08
***
这周我又是深入研究了C语言，但是没想到被卡住了......
C语言的动态存储管理机制我始终没能理解这个东西有什么必要去使用。当时想着，既然书上写了，就肯定有它的必要性，所以就先囫囵吞枣了。
在学习了解过后，我初步掌握了四个函数的用法~（可能也就四种？！）~：malloc、calloc、realloc、free。这四个函数具体用法如下：
1. `void* malloc(size_t n);`
2. `void* calloc(size_t n, size_t size);`
3. `void* ralloc(void *p, size_t n);`
4. `free(p);`

**注：一、malloc函数本身不会针对动态存储区内的堆做处理。二、size_t是标准库里的一个类型~（其实我也不太懂）~，可以满足任何针对储存块的大小的需要。三、使用C语言动态存储管理机制时应该充分考虑程序的安全性问题，一定不要忘记未分配成功时的处理，应该像下面的代码这样写：**
```
if (p == NULL)
{
    //此处填写未分配成功后的处理！
}
else
{
    //此处填写分配成功后的后续处理！
}
```
**到后期就应该明白，野指针有时候是个危险的东西，通常我们都是第一时间清除野指针的。因为访问野指针会造成非法访问从而导致程序崩溃，对系统产生害处！**

除了学习动态存储管理机制外，其实我也学了命令行参数及其处理。

但是说实在话，还真不知道这个有什么用处，至少我知道为什么dev创建项目的时候总是喜欢用以下代码生成main.c
```
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
    return 0;
}
```
*也许，我一开始就用记事本编程的话，就能明白命令行参数是什么用处。*
***
以下内容是我和工具箱探讨过的问题：

*~首先我要丢一波人~*
```
#include <stdio.h>
#include <stdlib.h>

int main() {
 int n;
 scanf("%d",&n);
 double *scores = NULL;
 scores = (double *)malloc(n * sizeof(double));
 // scores = (double *)calloc (n, sizeof (double);
 /// 此句和上句实现效果都一样
 if (scores == NULL)
 {
     return EOF;
 }
 double *serocs = NULL;
 serocs = (double *)realloc(scores,(2*n)*sizeof(double));
 if (serocs == NULL)
 {
     return EOF;
 }
 else
 {
     for (int i = 0; i < n; i++) {
         scanf("%d", (serocs + i));
     }
     for (int a = 0; a < (2 * n); a++) {
         printf("%3d", *(serocs + a));
     }
     free(scores);
     free(serocs);
 }
 return 0;
}
```
后来工具箱跟我说你输入的是5个，扩大到10个，输入的就应该是10个，输出的也得是十个......没等他说完，我就猛地发现：
```
    for (int i = 0; i < n; i++) {
         scanf("%d", (serocs + i));
     }
```
我当场~石化~！......事实上应该把n改写成(2 * n)才对！

后来我跟他讨论了一下数组定义问题。

为什么用dev有时候会报错说什么数组不能动态定义，有时候又可以？！这就很诡异...后来我该用Clion之后，动态定义数组居然可以通过？！当时我就觉得很不科学。我和学长都认为，严格的IDE在这种情况下是会报错的~（具体原因什么的我也不懂）~。虽然说使用动态存储机制也多少有风险，但可能总比动态定义数组要好一些。
***
以下是我和hxd讨论后得到的好东西~

[malloc函数——一个低调的C语言学习者宝藏](https://zhuanlan.zhihu.com/p/197918331)

但是讲真，后面的我真的看不懂啊......**我太菜了......ToT**

最后吐槽一下：现在也不知道怎么的，随便搜个某某知识盲区，就总能看到链表、二叉树等等的数据结构内容，怎么回事啊？

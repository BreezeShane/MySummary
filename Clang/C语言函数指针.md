# C语言函数指针
## 2020/11/13
***
我只能说还是我太菜了，现在搞C语言指针真的过得越来越艰难（ToT）
这个函数指针真的就很骚......虽然我确确实实知道它是好东西，但是一是我不会用，二是它真的好抽象......
```
typedef int (*FUNP)(int, int);
void trans_int(int *begin, int *end, int *second, int (*fp)(int));

typedef double (*MFP)(double);
void trans_double (double *begin, double *end, MFP fp);

void trans_int(int *begin, int *end, int *second, int (*fp)(int))
{
    for(;begin<end;++begin)
        *begin = fp(*begin);
}
void trans_double (double *begin, double *end, MFP fp)
{
    for(;begin<end;++begin)
        *begin = fp(*begin);
}
int * mismatch_int (int *begin, int *end, int *second, FUNP fp)
{
    for(;begin<end;++begin,++second)
    {
        if (fp(*begin, *second) == 0) break;
    }
    return *begin;
}
```
写这个也没什么目的，就是单纯地想先记下来慢慢理解，然后再慢慢消化，说不定哪天我真的参悟了这个鬼东西~
等以后明白了就写一下自己的理解吧！
***
## 五分钟后的更新
这鬼东西我好像懂了，又好像没懂？指针这玩意它就玄学？！
当时看到这行代码`if (fp(*begin, *second) == 0) break;`时我就懵了，这fp是什么东西啊？？？然后我还上下求索，好个找fp的定义，把它的祖宗们都找出来，然而并没有发现什么特别的。直到最后，我才反应过来，我傻了......这fp不就是要我去定义的吗？？？就是要我去自定匹配方式的啊！！！行，懂了，反正再加上这个代码段就好啦！
```
int fp (int ,int );
//前面不要忘了声明哦！

int fp (int a, int b)
{
    if (a == b) return 1;
    else return 0;
}
```
总之这个不过就是函数指针的实际应用，没有什么太难哒~
安全上岸~~~
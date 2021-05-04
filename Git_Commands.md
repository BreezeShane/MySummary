# **Git Commands**
***

**2020/11/08**

最近小伙伴们好像都在为git指令发愁啊，讲真，刚开始确实用不惯。嘛，用的时间长了，git指令还是很好的东西~   ~（我不可能告诉你我是DOS系统的情怀党）~

于是我就写这个帮助文档，一来我能日后有需要再去复习，二来也可以给小伙伴们提供参考~

## Git 前期准备该怎么做？

首先，第一次使用git的时候，操作稍稍麻烦一些，但做完之后，就是一劳永逸的事啦！

1. 按下Super键+R，打开运行对话框，输入powershell，点击运行。
2. 首先要选择你的存储目录（以后的文件都要放在这里的~如果换文件夹需要重新做）
3. 选择好你的目录后，在powershell里输入`cd (你的文件路径)`
4. 输入`git init`进行初始化
5. /* 可以输入`ls`来查看当前目录下所有文件，如果想查看被隐藏的文件需要输入`ls -s` */
6. 输入`git remote add (Your repository's name) (Your repository's Url)`//通常Your repository's Url就是在你的GitHub上打开你的repository后的链接地址**还要再加上 .git**
7. 连接成功后，由于你第一次使用，需要先登录，则要执行以下两行指令：
   ```
   git config --global user.name "(Your User name)"
   git config --global user.email "***********@***"
   ```
8. 然后就可以创建你的readme文件啦，需要输入`echo "All you wanna say" > readme.md`
9. 接着输入`git status`
10. 看到返回给你的红字之后，输入`git add --all`
11. 再次输入`git status`
12. 你会发现原来红色的字都绿了......
13. **注意中间会弹出一个对话框，让你输入你的GitHub用户名及密码，输入完毕登录以后，就可以了。**
14. 每次上传之前都要养成良好的记录习惯~输入`git commit -m "All you wanna say"`
15. 这时候再输入`git push --set-upstream (Your repository's name) master`
16. 当然上面的master也可以换成别的分支。另外应该知道，这里的(Your repository's name)是你在本地命名的仓库名，与GitHub上的仓库名没有必然联系。
17. 最后，你会发现上传成功，那么你赶快去刷新你的GitHub吧！

## Git repository名字忘记了怎么办？

你很有可能建立了多个仓库，仓库名太多容易记不过来，有时候又容易忘记，该怎么办啊？别急，山人自有妙计：

输入`git remote -v`

这时候你会发现，你的所有的repository名字以及它对应的Url都出现啦！

**Git上传时不小心使用git add --all把本不希望添加的文件上传了，但还好没有提交也没做commit，那么这时候你该怎么办？**

可以输入`git rm --cached (filename)`
如果不行，试试这个`git rm -f --cached (filename)`

Git 上传文件被拒绝该怎么办？

## 输入`git pull --rebase (Your repository's name) master`然后再push一下就好啦！

## Git 需要走代理怎么办？

```shell
# git config --global http.proxy http://127.0.0.1:1080
# git config --global https.proxy https://127.0.0.1:1080
# 如果你像上面那样设置过代理的话需要执行这两行指令：
git config --global --unset http.proxy
git config --global --unset https.proxy

# 1086 改为自己的 socks5 监听端口
git config --global http.https://github.com.proxy socks5://127.0.0.1:1086
git config --global https.https://github.com.proxy socks5://127.0.0.1:1086
# 1080 改为自己的 http 监听端口
git config --global http.https://github.com.proxy https://127.0.0.1:1080
git config --global https.https://github.com.proxy https://127.0.0.1:1080
```

## Manjaro 每次上传总是需要输入用户名和密码的解决方案

目前看到的解决方案是进入到项目目录里添加本地凭证即可。执行：

```
git config --global credential.helper store
# 这个指令会在用户路径下生成.gitconfig文件并指添加相应的配置内容。
# 用户路径是指windows: C:/Users/username、mac os x: /Users/username和linux: /home/username
git pull
```

然后你只需要再输入一次用户名和密码就可以生效了！

***
后面再遇到问题的时候我还会继续更新~
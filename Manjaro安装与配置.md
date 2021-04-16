# Manjaro Linux

## 2021/1/20

终于考完试了！在大学第一个寒假到来之际，我决定入坑Linux系统，并花了很长时间挑选系统（深度选择困难患者），终于，我选择了Manjaro Linux，希望它~不会让人失望~！

### **1.Windows10+Manjaro Linux深度指北**

#### 前期安装

「温馨提示」如果打算是用grub的话请提前先准备好一个额外的分区用于存放Manjaro系统，另外必须要准备的是一个能用的USB！！！
首先，在Manjaro官网上选择一个系统版本下载，一定要谨慎选择！一定要谨慎选择！一定要谨慎选择！选择很重要！选择很重要！选择很重要！
除非你知道你在干啥，强烈建议选择Manjaro KDE版本！（Xfce4版本过于原始以至于使用门槛很高，甚至不调整的话很多功能会很鸡肋）
在官网下载好iso镜像文件后，另外下载安装rufus（U深度真的很烂。。。），然后将iso镜像写入USB里。
写入完毕就重启电脑，在开机过冲中按F12进入UEFI启动选项界面，选择你的USB。
进入USB的系统后再双击Install Manjaro即可进行安装。
安装好以后就可以进入Manjaro系统了。

#### 初期准备

使用初期我们需要先配置一下，按Alt+Space，输入Konsole启动终端，再输入`sudo pacman-mirrors -i -c China -m rank`更新镜像排名。
接着输入`sudo pacman -Syy`和`sudo pacman -Syu`。
另外，我们先安装好一个编辑器——Vim，输入`sudo pacman -S vim`
输入`sudo vim /etc/pacman.conf`进入编辑界面，按I键进入编辑模式，再将下面的文本加入到该文件中：

```
[archlinuxcn]
SigLevel = Optional TrustedOnly
Server = https://mirrors.ustc.edu.cn/archlinuxcn/$arch
```

按下Esc键后输入`:wq`即可保存并退出，回到Konsole。（如果一开始你没有敲sudo，而是直接输入`vim /etc/pacman.conf`，那么保存并退出操作会提示没有权限，这时可以输入`%! sudo tee % > /dev/null`用来实现。）
然后输入`sudo pacman -Syy && sudo pacman -S archlinuxcn-keyring`
我们再来安装yay这个强大的包管理工具
`sudo pacman -S yay`

另外，需要安装binutils，base-devel这两个包才能正常运行安装程序，否则会出现ERROR: Cannot find the strip binary required for object file stripping.等源代码出错的问题。

`sudo pacman -S binutils base-devel`

### **2.Manjaro中期配置**

#### 输入法安装

我们开始安装输入法了，依次输入：

```shell
sudo pacman -S fcitx-googlepinyin
sudo pacman -S fcitx-im
sudo pacman -S fcitx-configtool
```

然后我们需要编辑配置文件，输入`sudo vim ~/.xprofile`
写入以下的代码：

```
export GTK_IM_MODULE=fcitx
export QT_IM_MODULE=fcitx
export XMODIFIERS="@im=fcitx"
```

重启一下电脑就可以开始使用中文输入法了！

#### 音乐平台安装

作为一个狂热的音乐爱好者，听音乐的事怎么能少了呢？
`sudo pacman -S netease-cloud-music`

#### Markdown编辑器安装

如果你经常使用markdown来写文档的话，安装这个！

`sudo pacman -S typora`

#### 办公软件安装

Linux下可没有Windows的Office一件套，不过还好我们有WPS！

```shell
yay -S wps-office
yay -S wps-office-mui-zh-cn
yay -S ttf-wps-fonts
```

#### **科学上网安装与配置**

想要科学上网，就用[金坷垃](jinkela.red)！

`sudo pacman -S v2ray qv2ray`

先打开qv2ray并点新建，然后复制节点链接粘贴到qv2ray里就可以了！(什么？你没氪金？那打扰了！)

### **3.Manjaro深度使用**

#### VS Code安装

安装VS Code的话，首先要到官网[VS Code官网](https://code.visualstudio.com/docs?dv=linux64)进行下载

下载后在Konsole里先cd到压缩包所在目录，然后执行`tar -jxcv code-stable-code_1.7.2-1479766213_amd64.tar.gz`

解压好以后就可以运行code文件开始写bug了！！！

#### 切换系统的等待时间更改

经常错过5秒然后无奈进入自己并不想进的系统又只能重启吗？不妨让它再稍微等等！

Konsole下输入`sudo vim /etc/default/grub`,再修改TIMEOUT那一行的数据既可了，想改多久改多久！

别忘了最后还需要执行这个：`sudo update-grub`

#### 添加程序到开始菜单

你有想添加到开始菜单的程序却不知怎么办吗？

在Konsole输入`sudo vim /usr/share/applications/<app_name>.desktop`（其中<app_name>是你要指定的应用程序）创建这个配置文件。

然后把下面这个模板输入进去，再填一下空就可以了！

```
[Desktop Entry]
Version=
Type=Application
Name=
Icon=
Exec="" %f
Comment=
Categories=
Terminal=false
StartupWMClass=
```

下面是VS Code的样例

```
[Desktop Entry]
Version=1.0
Type=Application
Name=VS Code
Icon=/home/breezeshane/VSCode-linux-x64/resources/app/resources/linux/code.png
Exec="/home/breezeshane/VSCode-linux-x64/code" %f
Comment=Visual Studio Code
Categories=Development;IDE;
Terminal=false
StartupWMClass=vs-code
```

#### PyCharm安装

Python Developer必备的神器！输入‘yay -S pycharm-professional'即可安装IDE PyCharm

光有PyCharm还不行，我们还需要有Python解释器，我选择Anaconda！不过不要以为yay能找到正确的anaconda，其实它下载来的anaconda是windows平台下才能用的，我们只能去[官网](https://www.anaconda.com/products/individual)下载。选Linux版本！选Linux版本！选Linux版本！

下载后把脚本文件放在你想放的位置（我有点懒，就直接放在/home/brezeshane/下了），然后进入Konsole输入`bash Anaconda3-2020.11-Linux-x86_64.sh`（后面的脚本文件名以下载的为准！）接着一路enter就行。

```
Do you wish the installer to initialize Anaconda3
by running conda init? [yes|no]
```

如果看到这段话，推荐输入yes。

然后进入最后一步，在Konsole输入`vim ~/.bashrc`，在文本末尾添加`export PATH="/home/<USER_NAME>/anaconda3/bin:$PATH"`（其中<USER_NAME>是你的Linux系统用户名），再保存退出。别忘了在Konsole这里输入`source ~/.bashrc`

一切大功告成，不信，试试输入`conda list`

顺便提一下，如果输入`python`会看到这个

```
Python 3.8.5 (default, Sep  4 2020, 07:30:14) 
[GCC 7.3.0] :: Anaconda, Inc. on linux
Type "help", "copyright", "credits" or "license" for more information.
>>>
```

因为Manjaro系统是不自带Python环境的！

#### Clion安装

由于JetBrains的个性，C语言IDE的运行环境也要有JDK支持，且版本不低于11。。。

在Konsole端输入`sudo pacman -S clion clion-cmake make clion-lldb clion-jre`即可安装Clion以及一些必备的依赖。

### Windows 10 / Manjaro下的Anaconda配置

依次输入下列语句，无特殊说明外，一个字——等！

```shell
conda update --all
conda create --name ANYNAMEYOULIKE python=3.8
```

接着你面临二选一的抉择：

法一：

```shell
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/menpo
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/bioconda
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/msys2
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/conda-forge
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/pytorch/
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main/
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free/
```

法二：

打开`~/.condarc`文件，修改为以下内容

> 【注】 Windows下的文件路径是C:\Users\USERNAME\\.condarc

```
channels:
  - https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/menpo
  - https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/bioconda
  - https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/msys2
  - https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/conda-forge
  - https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/pytorch/
  - https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main/
  - https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free/
show_channel_urls: true
```

保存退出然后继续......

```shell
conda install pip
```

pip我们在这里换一下源，首先要创建目录`~/.pip/pip.conf`并输入以下内容：

> 【注】 Windows下的文件路径是C:\Users\USERNAME\pip\pip.ini

```
[global]
timeout = 6000
index-url = http://mirrors.aliyun.com/pypi/simple/
trusted-host = mirrors.aliyun.com
```

这样我们就单独更换好pip源了！

```shell
conda activate ANYNAMEYOULIKE
pip install opencv-python
pip install tensorflow-gpu
pip install torch
pip install torchvision
pip install keras
pip install scikit-learn
```

当然你使用conda install也没什么问题，只是我写这个帮助文档的时候正好清华源不稳定，因此用不了清华源。

接着我们确认一下tensorflow和pytorch都安装成功了：

### tensorflow测试代码

```python
import tensorflow as tf
mnist = tf.keras.datasets.mnist

(x_train, y_train), (x_test, y_test) = mnist.load_data()
x_train, x_test = x_train / 255.0, x_test / 255.0
model = tf.keras.models.Sequential([
  tf.keras.layers.Flatten(input_shape=(28, 28)),
  tf.keras.layers.Dense(128, activation='relu'),
  tf.keras.layers.Dropout(0.2),
  tf.keras.layers.Dense(10, activation='softmax')
])

model.compile(optimizer='adam',
              loss='sparse_categorical_crossentropy',
              metrics=['accuracy'])
model.fit(x_train, y_train, epochs=5)

model.evaluate(x_test,  y_test, verbose=2)
```

得到如下结果即为正常：

```
Epoch 1/5
1875/1875 [==============================] - 3s 2ms/step - loss: 0.2962 - accuracy: 0.9155
Epoch 2/5
1875/1875 [==============================] - 3s 2ms/step - loss: 0.1420 - accuracy: 0.9581
Epoch 3/5
1875/1875 [==============================] - 3s 2ms/step - loss: 0.1064 - accuracy: 0.9672
Epoch 4/5
1875/1875 [==============================] - 3s 2ms/step - loss: 0.0885 - accuracy: 0.9730
Epoch 5/5
1875/1875 [==============================] - 3s 2ms/step - loss: 0.0749 - accuracy: 0.9765
313/313 - 0s - loss: 0.0748 - accuracy: 0.9778

[0.07484959065914154, 0.9778000116348267]
```

### pytorch测试代码

```python
import torch    # 如正常则静默
a = torch.Tensor([1.])    # 如正常则静默
a.cuda()    # 如正常则返回"tensor([ 1.], device='cuda:0')"
from torch.backends import cudnn # 如正常则静默
cudnn.is_acceptable(a.cuda())    # 如正常则返回 "True"
```

### Jupyter NoteBook安装与配置

1. 首先需要运行指令：`pip install jupyter`

2. 然后需要配置目录信息，执行`jupyter notebook--generate-config`

3. 然后需要打开该目录下的文件：/home/USERNAME/.jupyter/jupyter_notebook_config.py
4. 在该文件中查找c.NotebookApp.notebook_dir的关键字，把该行第一个字符‘#‘去掉，再接着指定你以后要存放文件的目录
5. 然后为了能在Jupyter NoteBook下使用pytorch，需要先执行下面这些指令

```shell
conda activate ANYNAMEYOULIKE	//这个是要激活你的包含pytorch的虚拟环境
conda install ipython
conda install jupyter
conda install nb_conda
```

6. 到此为止，你可以在Konsole下输入`jupyter notebook`来运行了。

   附：如果发现import torch仍然出问题，显示kernel error，则需要先关闭jupyter notebook和Konsole再执行下面这个语句

   `python -m ipykernel install --user  -i http://pypi.douban.com/simple --trusted-host=pypi.douban.com`

   然后再重新启动Jupyter NoteBook。

### 开机挂载NTFS硬盘

前期准备：请安装ntfs-3g这个包，`sudo pacman -S ntfs-3g`

首先在Konsole输入`sudo fdisk -l`指令查看列表，找到你要挂载的硬盘，再找设备一列下的那个你要找的硬盘分区

然后输入`ls -l /dev/disk/by-uuid/`来查看你的目标分区的UUID并记录下来

```shell
cd /home/用户名
mkdir ANYNAMEYOULIKE
sudo vim /etc/fstab
```

「温馨提示」在这里你一定要保证修改正确，否则容易导致开不了机。。。虽然到时候你还可以启动其他系统修改一下这个配置文件就可以解决，但是会很麻烦的啊。。。

并在末尾新添加一行：

```
UUID=你查到的UUID	/home/用户名/ANYNAMEYOULIKE ntfs defaults 0 0
```

保存后reboot一下就可以了！

另外可以输入`df -h`来查看挂载情况。

#### **XDM安装**

XDM的[下载链接](https://subhra74.github.io/xdm/)

下载好这个文件后就开始安装，首先要找到刚下载的压缩包，这里我的压缩包文件名为`xdm-setup-7.2.11.tar.xz`，它的子压缩包是`xdm-setup-7.2.11.tar`

在Konsole下输入如下指令

```shell
cd ~/data				//进入所在的目录
xz -d xdm-setup-7.2.11.tar.xz && tar -xvf xdm-setup-7.2.11.tar
sudo su
cd /home/USERNAME/data
chmod +x install.sh && bash install.sh
```

这样就可以安装完成了。不过要注意的是，这个程序是没有快捷方式的，所以要搜索才能找到。

如果要卸载，运行如下指令即可

```shell
bash /opt/xdman/uninstall.sh
```

权限不够的话请在首处加`sudo`，如果还不行，那就先`sudo su`再尝试

运行XDM后要在如下菜单里做好配置

```
[Tools]–[Languages]											//设定语言
[Tools]–[Network optimization]–[High speed]–[OK]			//选择高速模式
[Tools]–[Options]–[Browser monitoring]–[View settings]		//选择安装浏览器监视插件
[Tools]–[Options]											//可调整下载路径、线程数和代理设置
```

### 解决Windows 10和Manjaro存在时间差的问题

一般修改Manjaro的时间设置，输入指令`sudo timedatectl set-local-rtc true`即可。

### Manjaro sudo 免密问题

首先修改/etc/sudoers，并清除`%sudo ALL=(ALL) ALL`前的“#”，然后进入root模式再修改`/etc/sudoers.d/10-installer`，在其中的`%wheel ALL=(ALL) ALL`下面添加

```shell
USERNAME ALL=(ALL) NOPASSWD: ALL
%USERNAME ALL=(ALL) NOPASSWD: ALL
```

### JupyterLab安装指北

你可以使用pip安装：`pip install jupyterlab`

你也可以使用conda安装：`conda install -c conda-forge jupyterlab`

接着为了JupyterLab的完整性，我们安装一下Node.js和npm，`sudo pacman -S nodejs npm`

装好以后，就可以直接运行了：`jupyter lab`

### Manjaro-JupyterLab配置

如果希望修改工作区路径，那么你需要做如下的做法：`jupyter lab --generate-config`, 然后需要复制一下terminal输出的路径信息，接着你再打开该目录下的jupyter_lab_config.py文件，查找notebook_dir关键字，然后在单引号里设定你的目标路径即可。

如果希望添加密码，需要做：

```shell
ipython
from notebook.auth import passwd
passwd()
```

接着你就设定你的密码即可，然后复制一下terminal输出的乱码，再次打开刚才的jupyter_lab_config.py文件，

```python
c.ServerApp.allow_root = True
c.ServerApp.open_browser = False
c.ServerApp.password = '刚才复制的乱码粘贴到这里来'
```

重启一下jupyter lab就可以了！

如果想安装插件的话，我们需要运行以下指令：

```shell
jupyter labextension install @jupyterlab/toc
# 用于安装生成目录的插件
jupyter labextension list
# 用于查看已安装的插件
```

然后我们需要进入JupyterLab，点击 Settings --> Advanced Settings Editor ，将Extension Manager 里的enabled**（位于User Overrides选项卡里） **的 false 改成 true，如果想设置主题的话，可以点击Setting --> Jupyter Lab Theme。

>  此处的参考博客为：[手把手教你配置JupyterLab 环境](https://www.163.com/dy/article/FVLE7H1Q0519EA27.html) [Jupyter Lab 简单配置](https://blog.csdn.net/weixin_41571493/article/details/88830458) 
>
> **「注」：这两篇博客都是基于Windows平台的，与本文使用的系统有所区别。**

### Manjaro系统备份与还原

>本部分参考了两篇博客：[利用tar备份linux系统详解](https://blog.csdn.net/xiongyangg/article/details/23693803) [安装Manjaro之后首先要做的是...](https://zhuanlan.zhihu.com/p/90634218) [Ubuntu学习笔记之BackupYourSystem使用tar命令](https://blog.csdn.net/mmh19891113/article/details/81698453)
>
>虽然最后一篇是Ubuntu的，但是直到我看到这里才发现，斜杠是要放在exclude后面的……

经过他们的详细讲解，我写了两个shell脚本，用于系统备份与还原。源码如下：

**备份**

```shell
sudo tar -cvpjf /home/breeze_shane/LinuxBackup/Manjaro-Backup.tar.bz2 --exclude=/proc --exclude=/tmp --exclude=/sys --exclude=/lost+found --exclude=/media --exclude=/home/YOUR_USER_NAME/YOU_DISK /
# /前面的路径是你要设定好的压缩包路径的位置
# 最后一个如果你不希望备份整个home文件的话就只写/home就可以了
# 「注意」最后的斜杠是和前面的压缩包配成一套的，但不要放在一起，会导致exclude失效的，所以要放在最后。就这个问题折磨了我一下午(ToT)
```

「注」：备份之前需要先执行`sudo su`来获取权限以免因无法读取而备份失败

**还原**

```shell
sudo tar -xvpzf /home/breeze_shane/LinuxBackup/Manjaro-Backup.tar.bz2 -C / # -C前面的路径是自定义的，就是你原来压缩好的包的路径
cd /
mkdir proc
mkdir lost+found
mkdir sys
mkdir tmp
mkdir media
```

「注」：还原之前请先格式化目标分区

**上面是很多人都在使用的备份方式，反倒是我这里就不知道为什么运行不起来了，四下求助才知道，有更为稳妥的办法就是先把系统盘挂载到指定目录下然后再备份那个目录下的文件，会回避很多卡死、broken pipe报错等问题。于是我执行了以下的代码并重新完善了shell：** 

> 另外，我了解到了pigz，意外的比tar好用（其实pigz就相当于tar的多进程版），可能，tar真的不如猪了。。。。

```shell
sudo mount /dev/nvme0n1p5 /mnt
# 第一个路径是你的块设备，这个信息你可以去dolphin那里右键你的系统盘查看属性就可以获得到的。 第二个路径是你要挂载到的目录。
```

**新备份**

```shell
sudo tar --use-compress-program=pigz -g snapshot -cvpf /home/breeze_shane/Mydata/LinuxBackup/ManjaroBackup.tgz --exclude={'/mnt/proc','/mnt/tmp','/mnt/sys','/mnt/lost+found','/mnt/media','/mnt/home/breeze_shane/Mydata','/mnt/home/breeze_shane/.cache'} /mnt # 这一整行就是这么长。。。
sudo tar --use-compress-program=pigz -g snapshot -cvpf /home/breeze_shane/Mydata/LinuxBackup/ManjaroBackupDev.tgz /dev
sudo tar --use-compress-program=pigz -g snapshot -cvpf /home/breeze_shane/Mydata/LinuxBackup/ManjaroBackupRun.tgz /run
# 之所以分开包是因为我发现第一次打包并不能把dev和run文件夹下的文件打包进去,要注意的是第三个指令会报错，但是我去查看了一下，没有压缩进来的是socket文件（套接字文件），是服务器与客户端的缓存，pigz会忽略也是因为这一点，因此我认为这不影响正常备份。
# 「注」这里使用了增量备份的方案，tar会生成snapshot时间戳文件，以便用于校验文件是否发生改变。第一次使用不会报错影响备份。
```



> 参考博客：[Linux mount 命令](https://www.cnblogs.com/sparkdev/p/9015312.html) [zstd安装_Arch Linux 系统迁移](https://blog.csdn.net/weixin_35363322/article/details/112042405) 
>
> 另外我还发现了[rsync 用法教程](https://www.ruanyifeng.com/blog/2020/08/rsync.html)，就是一直没能成功。。。
>
> 如果不确定自己究竟要备份哪些的话，不妨看看[Linux系统各种目录的作用](https://zhuanlan.zhihu.com/p/30617845) 

**新还原**

```shell
sudo tar --use-compress-program=pigz -xvpf /home/breeze_shane/Mydata/LinuxBackup/ManjaroBackup.tgz -C /
sudo tar --use-compress-program=pigz -xvpf /home/breeze_shane/Mydata/LinuxBackup/ManjaroBackupDev.tgz -C /
sudo tar --use-compress-program=pigz -xvpf /home/breeze_shane/Mydata/LinuxBackup/ManjaroBackupRun.tgz -C /
cd /
mkdir proc
mkdir lost+found
mkdir sys
mkdir tmp
mkdir media
# -C前面的路径是压缩包的位置，而后面的路径则是你要解压到的路径
```

> 参考博客：[pigz打包、解压](https://www.jianshu.com/p/b3ca4e0a9bff) [多线程压缩工具pigz使用](https://www.jianshu.com/p/455ffef0a3c8) [[Linux下Rsync和Tar增量备份梳理](https://www.cnblogs.com/kevingrace/p/6601088.html)] [Linux使用 tar命令-g参数进行增量+差异备份、还原文件](https://www.shuzhiduo.com/A/A7zgwAmnz4/) 

### Manjaro定时服务

> 参考：[crontab 定时任务](https://linuxtools-rst.readthedocs.io/zh_CN/latest/tool/crontab.html) 

要想使用自动定时服务，我们需要cronie软件，执行`sudo pacman -S cronie`即可安装，在使用之前我们需要执行下面这两条语句：

```shell
sudo systemctl enable cronie.service
sudo systemctl start cronie.service
```

然后我们需要输入`crontab -e`进入编辑时间计划的界面

我们要记下crontab特有的语法：***分 时  日 月 周***，指令格式是这样：

```
* *  * * * "这里写下你要执行的指令"
```



### Manjaro Nvidia Driver驱动安装

> 参考博客：[在 Manjaro 上手动安装官网的 NVIDIA 显卡驱动](https://yeyaowei.github.io/2019/01/16/install-nvidia-driver-manually/) 

安装Nvidia驱动之前，请先了解自己的Manjaro系统内核版本，输入`uname -r`即可查看。这里我返回的是`5.9.16-1-MANJARO`，记住你的版本号，接下来我们安装一下头文件：`sudo pacman -S linux59-headers`，如果不确定自己应该装什么，可以先搜索一下：`sudo pacman -Ss linux-headers`，查看详细信息之后，我相信你能自己选出正确合适的版本！

接着上[官网](https://www.nvidia.cn/Download/index.aspx?lang=cn)去下载驱动，选择好你的显卡型号，系统我们选择Linux 64-bit，然后下载来的文件要存在你的英文目录下（以免如果后面出意外而不能输入中文），这里我是直接存放在`/home/USERNAME/`这里了。

然后需要安装一下工具，执行：`sudo pacman -S base-devel dkms`

为了我们能正常使用Nvidia驱动，我们需要禁用原来的Nouveau驱动，我们需要编辑`/etc/default/grub`，在其中把`GRUB_CMDLINE_LINUX` 开头的那一行改为 `GRUB_CMDLINE_LINUX="nouveau.modeset=0"`，保存之后更新一下grub：`sudo update-grub`

然后需要重启一下，执行`sudo reboot`

> 「注」在文中博主提到：重启之后，由于没有显卡驱动的支持，可能会卡在 BIOS Logo 界面或者是黑屏。这个时候你需要按下 ALT + CTRL + F2 进入到 TTY 文本模式。
>
> 然而我并没遇到这个问题，直接登录进入系统了，没什么问题的。

接着执行下面的指令：

```shell
chmod +777 NVIDIA-Linux-x86_64-410.93.run
# 后面的文件和你的文件名保持一致。
sudo ./NVIDIA-Linux-x86_64-410.93.run
# 路径和你之前下载的驱动文件的位置保持一致。
sudo reboot
# 最后需要重启一下电脑
inxi -G
#执行这一条，你就可以看到你的显卡驱动是nvidia了，这就说明你的系统成功安装了nvidia驱动，恭喜你！
nvidia-smi
# 执行这一条你会看到如下的输出信息，这时候你可以完全确信，驱动成功安装了！
```

```
Wed Mar 31 22:23:11 2021       
+-----------------------------------------------------------------------------+
| NVIDIA-SMI 460.67       Driver Version: 460.67       CUDA Version: 11.2     |
|-------------------------------+----------------------+----------------------+
| GPU  Name        Persistence-M| Bus-Id        Disp.A | Volatile Uncorr. ECC |
| Fan  Temp  Perf  Pwr:Usage/Cap|         Memory-Usage | GPU-Util  Compute M. |
|                               |                      |               MIG M. |
|===============================+======================+======================|
|   0  GeForce MX350       Off  | 00000000:06:00.0 Off |                  N/A |
| N/A   44C    P0    N/A /  N/A |      0MiB /  2002MiB |      0%      Default |
|                               |                      |                  N/A |
+-------------------------------+----------------------+----------------------+
                                                                               
+-----------------------------------------------------------------------------+
| Processes:                                                                  |
|  GPU   GI   CI        PID   Type   Process name                  GPU Memory |
|        ID   ID                                                   Usage      |
|=============================================================================|
|  No running processes found                                                 |
+-----------------------------------------------------------------------------+
```

### Manjaro Cuda & Cudnn安装指南

首先在相应官网下载好你的cuda和cudnn，一定要注意版本问题，去tensorflow官网查一下看看他们能支持哪个版本。下载好之后存放到你的指定目录（路径后面要用）。

输入`sudo pacman -U PATH/cuda-11.0.3-1-x86_64.pkg.tar.zst`这里我选的是cuda 11.0，PATH是你存放cuda的路径。

>  「注」：如果系统提示系统文件已存在或者提示存在文件冲突，那么你只需要删掉那些就可以了

安装好以后，我们执行一下`sudo ark`来给Ark赋予root权限，它会弹出Ark应用窗口，我们就在那个窗口内打开你的cudnn压缩包，然后将该压缩包下的cuda文件夹（其实总共也就这一个大文件夹）解压缩到/usr/local/这里，然后用vim编辑一下~/.bashrc，在最后一行输入：

```
export LD_LIBRARY_PATH=/usr/local/cuda/lib64:$LD_LIBRARY_PATH
```

退出后输入`source ~/.bashrc`就可以了，为了确定他们能正常运作，我们接下来测试一下：

```shell
conda activate ANYNAMEYOULIKE
python
```

```python
import torch
torch.cuda.is_available()
# 这里会返回True
import tensorflow as tf
import tensorflow as tf
tf.__version__
tf.test.is_gpu_available()
# 这里会返回True
```

以上，cuda和cudnn的安装就到此结束了！

### Zsh找不到Anaconda的问题

这样的情况一般应该是没用Anaconda初始化过Zsh，应该执行一下

```shell
～/anaconda3/bin/conda init zsh
```

然后你再编辑一下～/.zshrc并添加入anaconda的环境变量即可。

```shell
export PATH="/home/<USER_NAME>/anaconda3/bin:$PATH"
```

「注」：其实这个解决方法可以通用到fish、powershell、tcsh、xonsh等等。
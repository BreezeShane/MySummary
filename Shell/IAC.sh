#!/bin/bash

# Variables
USER=$1
REPO=$2
ENVNAME=$3

if [ $1 == "help" ]; then
	echo -e "To use the shell script, type in this format:\n\t \"source IAC.sh <USERNAME> <REPONAME> <ENVNAME>\"\nParameter Introduction:\n\t<USERNAME>: The parameter should be the name of your GitHub account. The default value is \"BreezeShane\"\n\t<REPONAME>: The parameter should be the name of your GitHub Repository you want to download. The default value is \"Unsupervised-Learning\".\n\t<ENVNAME>: The parameter should be the name of your new anaconda virtual environment. The default value is \"OEDL\"\nIf you type \"source IAC.sh help\" and then the help documentation will be displayed.\n";
	exit 0;
fi

# Download source file.
echo "Welcome to use Auto Installer!"
echo "Which kind of Anaconda3 would you like?"
echo "1. 64-Bit (x86) Installer (581 MB)"
echo "2. 64-Bit (AWS Graviton2 / ARM64) Installer (488 M)"
echo "3. 64-Bit (Power8 and Power9) Installer (255 MB)"
echo "4. 64-bit (Linux on IBM Z & LinuxONE) Installer (242 M)"

read TYPEID;
if [ $TYPEID -eq 1 ]; then
	TYPE="x86_64";
elif [ $TYPEID -eq 2 ]; then
	TYPE="aarch64";
elif [ $TYPEID -eq 3 ]; then
	TYPE="ppc64le";
elif [ $TYPEID -eq 4 ]; then
	TYPE="s390x";
else
	echo -e "Invalid type id.";
	exit 1;
fi

if [ ! -f "./Anaconda3-2021.11-Linux-${TYPE}.sh" ]; then
	wget https://repo.anaconda.com/archive/Anaconda3-2021.11-Linux-${TYPE}.sh
	echo "Anaconda Shell Installer Download Success!"
else
	echo "Anaconda Shell Installer File exists!"
fi

# Auto-Install anaconda3.
echo "Installing Anaconda3......"
{
	echo ${KEYCODE_ENTER};
	echo "yes";
	echo ${KEYCODE_ENTER};
} | sh ./Anaconda3-2021.11-Linux-${TYPE}.sh 1>./Anaconda.log 2>&1
echo "Anaconda3 now is installed!"

# Initialize anaconda.
/root/anaconda3/bin/conda init bash
. ~/.bashrc

# Create the virtual environment.
{ echo "y"; } | conda create -n ${ENVNAME:="OEDL"} python=3.8

# Activate the environment.
conda activate ${ENVNAME}

# conda change channels
conda config --add channels https://mirrors.ustc.edu.cn/anaconda/pkgs/main/
conda config --add channels https://mirrors.ustc.edu.cn/anaconda/pkgs/free/
conda config --add channels https://mirrors.ustc.edu.cn/anaconda/cloud/conda-forge/
conda config --add channels https://mirrors.ustc.edu.cn/anaconda/cloud/msys2/
conda config --add channels https://mirrors.ustc.edu.cn/anaconda/cloud/bioconda/
conda config --add channels https://mirrors.ustc.edu.cn/anaconda/cloud/menpo/
conda config --set show_channel_urls yes
# cat /root/.condarc

# pip change channels
pip config set global.index-url http://mirrors.aliyun.com/pypi/simple/
pip config set install.trusted-host mirrors.aliyun.com
# cat /root/.config/pip/pip.conf

# Download the repo.
# git clone https://hub.fastgit.org/BreezeShane/Unsupervised-Learning.git
git clone https://hub.fastgit.org/${USER:="BreezeShane"}/${REPO:="Unsupervised-Learning"}.git
# cd ${REPO}

# Install requirements.
pip install -r "${REPO}/requirements.txt"

# Run visdom server.
python -m visdom.server &

# Run the demo.
python Generative\ Adversaria\ Networks.py
import numpy as np
import os
import cv2 as cv
import random
import matplotlib.pyplot as plt
from NeuralNetwork import NeuralNetwork
from tqdm import tqdm


Weights = np.load("weights.npz")
inputnode = 30000
hidenode = 100
outputnode = 4
new = NeuralNetwork(inputnode, hidenode, outputnode)
Times = 1
state = 1

def train():
    # 开始训练神经网络
    for e in range(Times):
        for imagefile in tqdm(Train_images):
            inputs = (np.asfarray(imagefile[1:]) / 255.0 * 0.99) + 0.01
            targets = np.zeros(outputnode) + 0.01
            targets[int(imagefile[0]) - 1] = 0.98
            new.train(inputs, targets)


def query():
    # #进行测试,输入测试集
    Weights = np.load("weights.npz")
    if state == 1:
        new.who = Weights['arr_1']
        new.wih = Weights['arr_0']
    Rightnum = 0
    for Trecord in tqdm(Test_images):
        Tinputs = (np.asfarray(Trecord[1:]) / 255.0 * 0.99) + 0.01
        outputs = new.test(Tinputs)
        rightlabel = int(Trecord[0])
        label = int(np.argmax(outputs)) + 1
        if label == rightlabel:
            Rightnum += 1
    rate = Rightnum / len(Test_images)
    print(f"学习率为{new.lr} , 准确率为{rate}")
    if state == 0:
        if rate > Weights['arr_2']:
            np.savez("weights.npz", new.wih, new.who, rate)
        elif rate < Weights['arr_2']:
            new.who = Weights['arr_1']
            new.wih = Weights['arr_0']


def realtest():
    print("请输入图片的路径【注：支持批量检测哟~】：")
    Real_Test_images_path = input()
    for i in os.listdir(Real_Test_images_path):
        img = cv.imread(os.path.join(Real_Test_images_path, i))
        Resizedimg = cv.resize(img, (100, 100), interpolation=cv.INTER_AREA)
        Inputimg = Resizedimg.reshape(1, -1)[0]
        inputs = (np.asfarray(Inputimg[0:]) / 255.0 * 0.99) + 0.01
        outputs = new.test(inputs)
        label = int(np.argmax(outputs)) + 1
        plt.imshow(img)
        if label == 1:
            print("我知道了, 这是其它垃圾")
        elif label == 2:
            print("我知道了, 这是厨余垃圾")
        elif label == 3:
            print("我知道了, 这是可回收垃圾")
        else:
            print("我知道了, 这是有害垃圾")
        plt.show()


def result():
    for index in range(0, 4):
        Terminput = new.investigate(index)
        Realpic = Terminput.reshape((300, 100))
        plt.imshow(Realpic)
        plt.axis('off')
        plt.show()


# 加载训练集
Train_images = []
img_path = 'D:\\MyOwnProjects\\Python\\TestPython - NEWControlUI\\Litter_training\\'
for i in tqdm(os.listdir(img_path)):
    Allimg = os.listdir(os.path.join(img_path, i))
    Randimg = random.sample(Allimg, len(Allimg))
    for item in Randimg:
        img = cv.imread(os.path.join(img_path, i, item))
        last_two_pic = cv.resize(img, (100, 100), interpolation=cv.INTER_AREA)
        finalpic = np.hstack((np.array(i), last_two_pic.reshape(1, -1)[0]))
        Train_images.append(finalpic)
Test_images = []
Test_images_path = 'D:\\MyOwnProjects\\Python\\TestPython - NEWControlUI\\Litter_tesing'
for i in tqdm(os.listdir(img_path)):
    Allimg = os.listdir(os.path.join(Test_images_path, i))
    Randimg = random.sample(Allimg, len(Allimg))
    for item in Randimg:
        img = cv.imread(os.path.join(Test_images_path, i, item))
        last_two_pic = cv.resize(img, (100, 100), interpolation=cv.INTER_AREA)
        finalpic = np.hstack((np.array(i), last_two_pic.reshape(1, -1)[0]))
        Test_images.append(finalpic)
print("欢迎来找人工智障玩耍！今天你心情如何呀？\n过的好不好？吃得饱穿得暖吗？")
print("==================================")
print("||\t\t\t1.Train！\t\t\t||\n||\t\t\t2.Query~\t\t\t||\n||\t\t\t3.Real Test!\t\t||\n||\t\t\t4.Exit!\t\t\t\t||")
print("==================================")
print("人工智障已准备就绪，请指示！")
while True:
    x = input()
    if x == '1':
        train()
        state = 0
        print("报告！训练已经结束，是否立即验证？（Y/N）")
        y = input()
        if y == 'Y' or y == 'y':
            query()
        else:
            print("是否希望我不记录此次学习记录？（Y/N）")
            y = input()
            if y == 'Y' or y == 'y':
                state = 1
    elif x == '2':
        query()
    elif x == '3':
        realtest()
    elif x == '4':
        print("既然你要走的话，那我们有缘江湖再见啦！")
        break
    elif x == 'What have you learnt?':
        result()
        print("报告，这些就是我学习到的东西！")
    else:
        print("骚瑞~~~我这个智障没明白您的意思~~")
    print("人工智障已完成任务，请指示！")

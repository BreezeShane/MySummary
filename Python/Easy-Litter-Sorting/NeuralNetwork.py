import scipy.special as ssp
import numpy as np


class NeuralNetwork:  # 神经网络框架
    def __init__(self, inputnode, hidennode, outputnode):
        self.inodes = inputnode
        self.hnodes = hidennode
        self.onodes = outputnode
        # 以上是设置神经网络节点的前期准备
        self.wih = np.random.normal(0.0, pow(self.hnodes, -0.5), (self.hnodes, self.inodes))
        self.who = np.random.normal(0.0, pow(self.hnodes, -0.5), (self.onodes, self.hnodes))
        # 初始化权重数组为训练的前期准备做好铺垫，并采取较优的初始值（隐藏节点数）^（-0.5)作为标准差
        # self.lr = 0.000310557090
        self.lr = 0.0003105570
        # 设定初始的学习率
        self.actfun = lambda x: ssp.expit(x)
        # 定义激活函数，也许后期这个可以换成其它更好的激活函数，比如tanh(x)
        # ，但可能涉及到其它多处修改，就暂且先不动。
        self.inverse_actfun = lambda x: ssp.logit(x)
        # 反向查询必用的函数——激活函数的反函数

    def train(self, inputlist, targetlist):  # 此处开始定义神经网咯的训练过程
        inputs = np.array(inputlist, ndmin=2).T
        targets = np.array(targetlist, ndmin=2).T
        hideninputs = np.dot(self.wih, inputs)
        hidenoutputs = self.actfun(hideninputs)
        # 这两行表示输入层加权后输入给输入层的激活函数，并将结果作为隐藏层的输入。
        finalinputs = np.dot(self.who, hidenoutputs)
        finaloutputs = self.actfun(finalinputs)
        # 这两行表示隐藏层加权后输入给输出层的激活函数，并将结果作为最终输出

        # 重核来了，以下是反向传播
        oerror = targets - finaloutputs
        herror = np.dot(self.who.T, oerror)
        # 更新权重
        self.who += self.lr * np.dot((oerror * finaloutputs * (1 - finaloutputs)), np.transpose(hidenoutputs))
        self.wih += self.lr * np.dot((herror * hidenoutputs * (1 - hidenoutputs)), np.transpose(inputs))

    def test(self, inputlist):  # 从此处开始定义测试过程
        inputs = np.array(inputlist, ndmin=2).T
        hiddeninputs = np.dot(self.wih, inputs)
        hiddenoutputs = self.actfun(hiddeninputs)
        finalinputs = np.dot(self.who, hiddenoutputs)
        finaloutputs = self.actfun(finalinputs)
        return finaloutputs

    def investigate(self, label):
        targetlist = np.zeros(4) + 0.01
        targetlist[label] = 0.99
        finaloutput = np.array(targetlist, ndmin=2).T
        finalinput = self.inverse_actfun(finaloutput)
        hiddenoutput = np.dot(self.who.T, finalinput)
        hiddenoutput -= np.min(hiddenoutput)
        hiddenoutput /= np.max(hiddenoutput)
        hiddenoutput *= 0.98
        hiddenoutput += 0.01
        hiddeninput = self.inverse_actfun(hiddenoutput)
        inputs = np.dot(self.wih.T, hiddeninput)
        inputs -= np.min(inputs)
        inputs /= np.max(inputs)
        inputs *= 0.98
        inputs += 0.01
        return inputs

# 触发器
## 一、RS触发器

### 1、与非门RS触发器及其示意图

![与非门RS触发器](https://hoanmeirin.oss-cn-beijing.aliyuncs.com/ysyx/RS_9de2a775.png)


### 2、或非门RS触发器及其示意图

![或非门RS](https://hoanmeirin.oss-cn-beijing.aliyuncs.com/ysyx/%E6%88%96%E9%9D%9E%E9%97%A8RS_589fbf9d.png)

同  与非门RS触发器  对称
输入有效电平相反

### 3、消抖开关

利用 1 1 保持原状态实现

## 二、同步触发器


### 1、改良RS（增强抗干扰能力）
- 利用时钟电平CP
#### 同步与非RS为例

![同步（与非）RS](https://hoanmeirin.oss-cn-beijing.aliyuncs.com/ysyx/%E5%90%8C%E6%AD%A5RS_651777ea.png)
注：同步（或非）RS的G<sub>3</sub>和G<sub>4</sub>是与门  不是与非门



前一时刻 S=R=CP=1 输出同时为1的禁止状态
当前时刻 S=R=1 CP=0 不定状态，此时相当于CP作为S、R作为输入


### 2、同步D触发器
（改良RS<sup>2</sup>优化掉了约束条件（S R不会是相同状态），但牺牲了元件数量并且输出依旧会多次变化，锁存受限（空翻））

- 在 S R 之间加入非门，且S=D（反正只要使输入变少就行了）
- 输入端只有一个 D 且同步触发器输出与 D 同（CP=1时，Q=D）

## 三、边沿触发器

解决空翻现象
只在CP上升沿或下降沿时接受输入信号

### 1、边沿D触发器

#### | 下降沿边沿D触发器（改良RS<sup>3</sup>）（实际是改良RS<sup>2</sup>+改良RS<sup>2</sup>）

两个CP输入端间增加一个非门，使（主同步D触发器的）输入端为CP，中间（从同步D触发器的）输入端为¬CP
效果：延时至下降沿

#### || 上升沿边沿D触发器

效果：延时至上升沿

### 2、边沿JK触发器（改良RS<sup>4</sup>）（端口扩展）

- 基于边沿D触发器的循环电路
- 由上额外实现了翻转功能（J=K=1）

#### | 下降沿边沿JK触发器例图

![JK](https://hoanmeirin.oss-cn-beijing.aliyuncs.com/ysyx/JK_e271589d.png)

#### || 上升沿边沿JK触发器

### 3、T触发器

- 只有保持和翻转功能
- 基于边沿D触发器的循环电路
Q<sup>n+1</sup> = D = T⊕Q<sup>n</sup>


### 4、T’触发器

- T = 1（Q<sup>n+1</sup> = D = ¬Q<sup>n</sup>）
- 可作为二分频器（CP频率的一半）


## 四、触发器转换

- 转换逻辑（对原有输入处理）

| 特性方程方法
|| 驱动图转卡诺图法

# 主从触发器（脉冲触发器）

见FF2
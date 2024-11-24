<strong>由于此前已经学过，本文仅写一下比较重要和容易忘记的东西</strong>

# 预定义的变量

| 变量名		| 含义 			| 		默认值     |
| :---:			|    :----:   	|         :---: |
|	CC			|C 语言编译器的名称	|		cc		|
|RM|删除文件程序的名称|rm -f|
|CFLAGS|C 语言编译器的编译选项|无|
|VPATH|文件搜索|希腊奶

# 常见自动变量

|变量	|含 义|
|:---:|:---:|
$*	|表示目标文件的名称，不包含目标文件的扩展名
$+	|表示所有的依赖文件，这些依赖文件之间以空格分开，按照出现的先后为顺序，其中可能 包含重复的依赖文件
$<	|表示依赖项中第一个依赖文件的名称
$?	|依赖项中，所有比目标文件时间戳晚的依赖文件，依赖文件之间以空格分开
$@	|表示目标文件的名称，包含文件扩展名
$^	|依赖项中，所有不重复的依赖文件，这些文件之间以空格分开

# 一些符号和关键字及其功能

|符号|关键字|作用|
|:---:|:---:|:---:|
%| |通配符
| |vpath|文件搜索
||.PHONY|显式声明伪目标
-||取消错误
@||输出取消
||export|可被下级获取的变量
||unexport|不可被下级获取的变量
||define...endef|打包命令
||ifeq...else...endif|条件判断
||ifneq|略
||ifdef|略
||ifndef|略

# 操作符

|操作符|功能
|:---:|:---:
:=|定义时只使用当前存在的变量
?=|定义但不修改已定义
$(var:a=b)/$(foo:%.o=%.c)|尾替换
...\$($(x))...|叠叠乐获取名称
+=|追加

![](https://hoanmeirin.oss-cn-beijing.aliyuncs.com/ysyx/RSUV1F31~GQ9GE\)\(%60MJL1N0.jpg)
![](https://hoanmeirin.oss-cn-beijing.aliyuncs.com/ysyx/44662281_p0_52077f16.jpg)
![](https://hoanmeirin.oss-cn-beijing.aliyuncs.com/56190014_p0.png)
![](https://hoanmeirin.oss-cn-beijing.aliyuncs.com/ysyx/26b60dfa513d269772e50a6e13fbb2fb4316d8ad.jpg)
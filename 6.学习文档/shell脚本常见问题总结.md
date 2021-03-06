# shell脚本常见问题总结

**1) 如何向脚本传递参数 ?**

`./script argument`  `bash script argument`

**2) 如何在脚本中使用参数 ?**

第一个参数 : `$1`，第二个参数 :` $2`，第n个参数：`$n`

**3) 如何计算传递进来的参数个数 ?**

`$#`

**4) 如何在脚本中获取脚本名称 ?**

`$0`：

**5) 如何检查之前的命令是否运行成功 ?**

`$?`成功则返回0否则返回其他值

**6) 如何获取文件的最后一行 ?**

`tail -1 file—name`获取从后往前第n行：`tail -n file-name`

**7) 如何获取文件的第一行 ?**

`head -1 file-name`获取从前往后第n行：`head -n file-name`

**8) 如何获取一个文件每一行的第三个元素 ?**

`awk '{print $3}' 'filenames'` 获取每一行第n个元素`awk '{print $n}' 'filenames'`注意只能用在#!/bin/awk中

**9) 假如文件中每行第一个元素是 FIND，如何获取第二个元素**

`awk'{ if ($1 == "FIND") print $2}'`

**10) 如何调试 bash 脚本**

将 `-xv` 参数加到 `#!/bin/bash` 后

例子：

`#!/bin/bash –xv`

**11) 举例如何写一个函数 ?**

```shell
function name {
    
}
name() {

}
function name() {
    
}
```



**12) 如何向连接两个字符串 ?**

例：

```shell
string1="Just for "
string2="fun"
string3=${string1}${string2}
echo $string3
```

输出`Just for fun`

**13) 如何进行两个整数相加 ?**

```shell
a=1
b=2
let c=$a+$b
(( d=a+b ));
echo $c
echo $d
echo $(($a+$b))
echo $[$a+$b]
expr $a+$b
echo $a+$b | e
```



**14) 如何检查文件系统中是否存在某个文件 ?**

```shell
if [ -f ~/file-way/file-name ] #判断文件系统中是否存在某个文件
if [ -d ~/file-way/file-name ] #判断目录是否存在
if [ -e ~/file-way/file-name ] #判断是否存在
if [ -r ~/file-way/file-name ] #判断是否可读
if [ -x ~/file-way/file-name ] #判断是否可执行
```



**15) 写出 shell 脚本中常用语法 ?**

**if判断：**

```shell
if [ test ]
then 
	#statements
fi

if [[ condition ]]; then
	#statements
fi

if [[ condition ]]; then
	#statements
	else
		#statements
fi

if [[ condition ]]; then 
	#statementts
elif [[ condition ]]; then
	#statements
elif [[ condition ]]; then
	#statements
	else
	#statements
fi
```



**for 循环 :**

```shell
for word in `ls`; do
done
```



**while 循环 :**

```shell
while [[ condition ]]; do
	#statements
done
```

**until 循环 :**

```shell
until [[ condition ]]; do
	#statements
done
```



**流程控制CASE：**

```shell
case word in
	pattern)
		::
esac
```



**16) 每个脚本开始的 #!/bin/sh 或 #!/bin/bash 表示什么意思 ?**

这一行说明要使用的 `shell`。`#!/bin/bash` 表示脚本使用 `/bin/bash`。对于 python 脚本，就是

​                         `#!/usr/bin/python`。

**17) 如何获取文本文件的第 10 行 ?**

`head -10 file|tail -1`

**18)chomd作用？**

`chmod a+x file`给予文件可执行权限

**19) 数组操作**

`declare -a a` `name[subscript]=value` `name=(value1 value2 ...)`创建数组

输出数组内容:

​         `${arry[*]}` `${arry[@]}` 

确定数组元素个数:

​        `${#arry[@]}`

数组追加:

​         `arry+=(a b c)`

数组排序：

​          `sort`

删除数组与元素：

​          `unset`

**20) 命令 “export” 有什么用 ?**

使变量在子 `shell` 中可用。

**21) 如何在后台运行脚本 ?**

在脚本后面添加 `“&”`。

**22) "chmod 500 script" 做什么 ?**

使脚本所有者拥有可执行权限。

**23) ">" 做什么 ?**

重定向输出流到文件或另一个流。 `>>`是追加不覆盖的重定向

**24) & 和 && 有什么区别**

- `&` - 希望脚本在后台运行的时候使用它
- `&&` - 当前一个脚本成功完成才执行后面的命令/脚本的时候使用它

**25) 什么时候要在 [ condition ] 之前使用 “if” ?**

当条件满足时需要运行多条命令的时候。例：

```shell
if [ condition ] && [ condition ]
then 
fi
```

**26) ";"  表示什么？**

`command1;command2`顺序执行命令

**27) bash shell 脚本中哪个符号用于注释 ?**

`#`

**28) 命令: echo ${new:-variable} 的输出是什么**

`variable`

**29) ' 和 " 引号有什么区别 ?**

- `'` - 当我们不希望把变量转换为值的时候使用它。
- `"` - 会计算所有变量的值并用值代替。

**30) 如何在脚本文件中重定向标准输出和标准错误流到 log.txt 文件 ?**

在脚本文件中添加 `"exec >log.txt 2>&1"` 命令。

**31) 如何只用 echo 命令获取字符串变量的一部分 ?**

``` shell
echo ${variable:x:y} #x是起始位置，y是截取的长度。本句句意为从左侧第x位开始截取y位
```

**32) 如果给定字符串 variable="User:123:321:/home/dir"，如何只用 echo 命令获取 home_dir ?**

`echo ${variable#*:*:*:}`输出变量从#后内容后从前向后开始输出

或

`echo ${variable##*:}`输出变量从##后内容不重复的那个开始从前向后输出

**33) 如何从上面的字符串中获取 “User” ?**

`echo ${variable%:*:*:*}`输出变量从%后内容从开始从后向前输出

或

`echo ${variable%%:*}`输出变量从%%后内容从不重复的那个开始从后向前输出

**34) 如何使用 awk 列出 UID 小于 100 的用户 ?**

`awk -F: '$3<100' /etc/passwd`

**35)5**36) 如何在 bash shell 中更改标准的域分隔符为 ":" ?**

`IFS=":"`

**37) 如何获取变量长度 ?**

`${#variable}`

**38) 如何打印变量的最后 5 个字符 ?**

`echo ${variable: -5}`注意程序报红但不是错误

**39) `${variable:-10} `和 `${variable: -10}` 有什么区别?**

- `${variable:-10}` - 如果之前没有给 variable 赋值则输出 10；如果有赋值则输出该变量
- `${variable: -10}` - 输出 variable 的最后 10 个字符

**40) 如何只用 echo 命令替换字符串的一部分 ?**

`echo ${variable//pattern/replacement}`

**41) 哪个命令将命令替换为大写 ?**

`tr '[:lower:]' '[:upper:]'`

**42) 如何计算本地用户数目 ?**

`wc -l /etc/passwd|cut -d" " -f1 或者 cat /etc/passwd|wc -l`

**43) 不用 wc 命令如何计算字符串中的单词数目 ?**

```shell
set ${string}
echo $#
```

**44) export**

设置或显示环境变量, export可新增，修改或删除环境变量，供后续执行的程序使用。export的效力仅及于该次登录操作

export PATH=”$PATH:/home/user/bin” 增加 
export -p 显示shell赋予程序的环境变量

**45) 如何列出第二个字母是 a 或 b 的文件 ?**

`ls -d [ab]*`

**46) 如何将整数 a 加到 b 并赋值给 c ?**

`c=$((a+b))`

或

`c=`expr $a + $b``

或

`c=`echo "$a+$b"|bc

**47) 如何去除字符串中的所有空格 ?**

`echo $string|tr -d " "`

**48) 重写这个命令，将输出变量转换为复数: item="car"; echo "I like $item" ?**

`item="car"; echo "I like ${item}s"`

**49) 写出输出数字 0 到 100 中 3 的倍数(0 3 6 9 …)的命令 ?**

`for i in {0..100..3}; do echo $i; done`

或

`for (( i=0; i<=100; i=i+3 )); do echo "Welcome $i times"; done`

**50) 如何打印传递给脚本的所有参数 ?**

`echo $*`

或

`echo $@`

**51) `[ $a == $b ]` 和` [ $a -eq $b ]` 有什么区别**

- `[ $a == $b ]` - 用于字符串比较
- `[ $a -eq $b ]` - 用于数字比较

其他可以用man手册命令`man test`查看

**52) = 和 == 有什么区别**

- `=` - 用于为变量赋值
- `==` - 用于字符串比较

**53) 写出测试 $a 是否大于 12 的命令 ?**

`[ $a -gt 12 ]`

**54) 写出测试 $b 是否小于等于 12 的命令 ?**

`[ $b -le 12 ]`

**55) 如何检查字符串是否以字母 "abc" 开头 ?**

`[[ $string == abc* ]]`

**56) `[[ $string == abc* ]]` 和 `[[ $string == "abc*" ]] `有什么区别**

- `[[ $string == abc* ]]` - 检查字符串是否以字母 abc 开头
- `[[ $string == "abc" ]]` - 检查字符串是否完全等于 abc

**57) 如何列出以 ab 或 xy 开头的用户名 ?**

`egrep "^ab|^xy" /etc/passwd|cut -d: -f1`

**58) bash 中 $! 表示什么意思 ?**

后台最近执行命令的 PID.

**59) $? 表示什么意思 ?**

上一个命令是否执行成功

**60) 如何输出当前 shell 的 PID ?**

`echo $$`

**61) 如何获取传递给脚本的参数数目 ?**

`echo $#`

**62)`$\*` 与`$@`有什么区别**

- `$*` - 以一个字符串形式输出所有传递到脚本的参数
- `$@` - 以 $IFS 为分隔符列出所有传递到脚本中的参数

**63) 如何在 bash 中定义数组 ?**

`array=("Hi" "my" "name" "is")`

**64) 如何打印数组的第一个元素 ?**

`echo ${array[0]}`

**65) 如何打印数组的所有元素 ?**

`echo ${array[@]}`

**66) 如何输出所有数组索引 ?**

`echo ${!array[@]}`

**67) 如何移除数组中索引为 2 的元素 ?**

`unset array[2]`

**68) 如何在数组中添加 id 为 333 的元素 ?**

`array[333]="New_element"`

**69) shell 脚本如何获取输入的值 ?**

a) 通过参数

`./script param1 param2`

b) 通过 `read` 命令

`read -p "Destination backup Server : " desthost`

 **70)关于cut和tr**

`cut -d "word" -f num` 截取以word为分割的第num个字符串

`tr "word1" "word2"` 字符串中的Word1替换为Word2

**71)cat正向连续读 tac反向连续读nl输出行号显示文件more一页一页显示文件内容head只看头几行tail只看后几行**

**72)按行输出文件**

`sed -n 'a,bp' file`输出从a到b行

**73)关于文件权限**

`chmod option file`给文件赋予权限

其中t是除创建者外其他用户不能删除

s是临时赋予root权限

**74)关于用户组**

`groupadd name` 创建一个用户组

`groups name`查看用户所有组

`chgrp name name` 将文件加入用户组，或将用户组加入文件

**75)关于命令替换**

`alias name=“order”可以将命令替换为名为name的命令执行`

写在`~/.bashrc`中`source ~/.bashrc`后可用

**76)关于`awk`的使用**

ａｗｋ是一种样式扫描和处理语言，常用于对数据的处理


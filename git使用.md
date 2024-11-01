# git使用
## 放入/更新
- mkdir \<gitlib filename>
创建git仓库<br>
- cd \<gitlib link>
切换至仓库路径
- git init
将其变成真仓库
- mv \<file>
将文件放入仓库
- git add \<filename> ...
将其从工作区添加到暂存区
- git commot -m "write the change"
将暂存区文件提交

## 穿越
- git status
获取仓库状态
- git diff
对比当前文件与仓库中上一次提交（最新）的文件
- git log
获取提交日志
### git reset
- option<br>
--hard 回退到一个版本的已提交状态<br>
--soft 回退到一个版本的未提交状态<br>
--mixed 回退到一个版本的已添加但未提交状态<br>

- id<br>
commit id
版本号<br>
HEAD~\<number>
回退几版<br>

### git reflog
记录了git命令历史

## 撤销修改
- git checkout -- \<filename>
把文件的工作区修改撤销<br>
- git reset HEAD \<filename>
把暂存区的修改撤销<br>

## 文件删除
- git rm \<filename>










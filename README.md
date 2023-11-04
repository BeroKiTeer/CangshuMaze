# CangshuMaze
A simple 3d maze game by OpenGL 



## 使用Git将本地代码推到远程仓库

1. 进入项目文件夹，右键“Git Bash Here”，通过命令 git init 把这个目录变成git可以管理的仓库。

   ```bash
   git init
   ```

2. 把文件添加到版本库中，使用命令 git add .添加到暂存区里面去，不要忘记后面的小数点“.”，意为添加文件夹下的所有文件

   ```bash
   git add .
   ```

3. 用命令 git commit告诉Git，把文件提交到仓库。引号内为提交说明(可以写提交时间)

   ```bash
   git commit -m 'first commit'  
   ```

4. 关联到远程库

   ```bash
   git remote add origin git@github.com:BeroKiTeer/CangshuMaze.git
   ```

5. 获取远程库与本地同步合并

   ```bash
   git pull --rebase origin master
   ```

6. 把本地库的内容推送到远程，使用 git push命令，实际上是把当前分支master推送到远程

   ```bash
   git push -u origin master
   ```

## Makefile编译

1. 打开终端
2. 输入命令`mingw32-make`
3. 直接运行CangshuMaze.exe

# CangshuMaze
A simple 3d maze game by OpenGL 

## 相机

在测试立方体下按1第一人称，按3第三人称

W S A D分别表示X坐标+-, Y坐标+-，Q E分别表示Z轴--，Z轴++

鼠标按住左键后拖动可改变相机角度，滚轮放大或缩小

## 世界坐标系

红表示X轴，绿表示Y轴，蓝表示Z轴

由于OpenGL使用笛卡尔坐标系(右手坐标系)，相机在此进行了特殊转换

但是Z轴无法变化，如果是升高只能Z--,也就是我们使用Z轴的负半轴作为我们常用的正半轴

## transform help document

重要！基本变化会修改点集信息，重新绘制时应将重新置位原本的点集信息，已经建立好的模型的点集类型应当为常量类型

已经实现的方法，具体样式详见本目录下的main.cpp和data.h，替换原本的main.cpp即可见

#### 平移

`void translate(VP &v, double l, double m, double n);`

- VP: 3D点集
- l： x轴的平移
- m：y轴的平移
- n: z轴的平移

translateX，translateY，translateZ都是指的单独的X,Y,Z轴的平移

```cpp
translate(CurbPoint, 1.0, 1.0, 1.0); //沿着x,y,z轴分别进行进行平移
```

#### 缩放

`void scaleXYZ(VP &v, double a, double e, double i);`

- VP: 3D点集
- l： a轴的缩放
- m：e轴的缩放
- n: i轴的缩放
- scaleEntirety是整体变换(s越大，图形越大)
- scaleX， scaleY, scaleZ指的都是单独的X,Y,Z轴的缩放

```cpp
scaleXYZ(CurbPoint,1.5,1.5,1.5); //沿着x,y,z轴分别进行缩放1.5倍
```

#### 旋转

`void rotateDXYZ(VP &v, double angle1, double angle2, double angle3);`

- VP: 3D点集
- l： x轴的旋转角度
- m：y轴的旋转角度
- n: z轴的旋转角度

同理rotateDX，rotateDY，rotateDZ和上面解释一样分别表示X, Y, Z

```cpp
rotateDX(CurbPoint,30); //沿着x轴旋转30度
```

#### 俯视图

`VP2 TTop(const VP &v);`

俯视投影，输入的是3D点集，输出的是2D点集

！点集的数量不变，点之间的连接关系不变

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

## 二次提交

### 自动同步

1. 将本地库与远程仓库同步

   ```bash
   git pull
   ```

2. 把本地库的内容推送到远程

   ```bash
   git push
   ```

### 手动解决本地与远程仓库的冲突

1. 把文件添加到版本库中，使用命令 git add .添加到暂存区里面去，不要忘记后面的小数点“.”，意为添加文件夹下的所有文件

   ```bash
   git add .
   ```

2. 用命令 git commit告诉Git，把文件提交到仓库。引号内为提交说明(可以写提交时间)

   ```bash
   git commit -m 'other commit'  
   ```

3. 将本地库与远程仓库同步

   ```bash
   git pull
   ```

4. 使用VScode的版本管理工具手动进行文件同步

5. 重新提交

   ```bash
   git add .
   git commit -m 'merged commit'  
   ```

6. 上传远程仓库

   ```bash
   git push -u origin master
   ```

## 

## Makefile编译

1. 打开终端
2. 输入命令`mingw32-make`
3. 直接运行CangshuMaze.exe

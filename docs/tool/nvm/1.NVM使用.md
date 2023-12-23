## 介绍

Node Version Manager 的缩写，是一个用于在单个计算机上管理和切换多个 Node.js 版本的工具。使用 nvm，您可以轻松地安装、卸载和更改所需的 Node.js 版本，而不必手动更改系统环境变量。

## 安装

1、文件下载路径: [release](https://github.com/coreybutler/nvm-windows/releases)

2、国内源配置：nvm安装路径下 `settings.txt` 文件增加

```txt
node_mirror: https://npm.taobao.org/mirrors/node/

npm_mirror: https://npm.taobao.org/mirrors/npm/
```

3、安装node

```cmd
nvm install node版本号  // 安装对应版本的node
nvm list                 // 用于查看已安装的node版本列表
nvm use node版本号     // 切换到对应版本的nodejs
 
 
如：
nvm install 16.13.1  // 安装16.13.1版本的nodejs
nvm use 16.13.1   // 使用16.13.1版本的nodejs
```

4、环境变量配置：

安装nvm时会自动生成：`NVM_HOME` 和 `NVM_SYMLINK` ,并添加到 Path 中，所以无需特殊处理。

以我的电脑举例：

```txt
NVM_HOME : C:\environment\nvm

NVM_SYMLINK : C:\environment\nodejs
```

## 语法

`nvm list`：查看当前本机使用 nvm 已安装的nodejs的版本列表

`nvm arch`：查看当前本机是 32 bit 还是 64 bit

`nvm install node@版本号`：安装指定版本的 nodejs

`nvm install latest`：安装最新版本的 nodejs

`nvm install 14.15.1`：安装 14.15.1 版本的 nodejs

`nvm uninstall node@版本号`：卸载指定版本的 nodejs

`nvm uninstall 14.15.1`：卸载 14.15.1 版本的 nodejs

`nvm use node@版本号`：使用指定版本的 nodejs(该版本是已经安装过后的)

`nvm use 14.15.1`：使用已安装的 14.15.1 版本的 nodejs

`nvm root`：查看本机安装的 nvm 的安装目录地址

使用管理员身份打开cmd，然后使用 `nvm use 14.15.1`使用指定版本的`node`

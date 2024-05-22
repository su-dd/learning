![](img/network/20240201164815.png)
## 各层作用及协议

|分层|作用|协议|
|---|---|---|
|物理层|通过媒介传输比特，确定机械及电气规范（比特 Bit）|RJ45、CLOCK、IEEE802.3（中继器，集线器）|
|数据链路层|将比特组装成帧和点到点的传递（帧 Frame）|PPP、FR、HDLC、VLAN、MAC（网桥，交换机）|
|网络层|负责数据包从源到宿的传递和网际互连（包 Packet）|IP、ICMP、ARP、RARP、OSPF、IPX、RIP、IGRP（路由器）|
|运输层|提供端到端的可靠报文传递和错误恢复（ 段Segment）|TCP、UDP、SPX|
|会话层|建立、管理和终止会话（会话协议数据单元 SPDU）|NFS、SQL、NETBIOS、RPC|
|表示层|对数据进行翻译、加密和压缩（表示协议数据单元 PPDU）|JPEG、MPEG、ASII|
|应用层|允许访问OSI环境的手段（应用协议数据单元 APDU）|FTP、DNS、Telnet、SMTP、HTTP、WWW、NFS|

## 物理层

- 传输数据的单位：比特
- 数据传输系统：源系统（源点、发送器） --> 传输系统 --> 目的系统（接收器、终点）

通道：

- 单向通道（单工通道）：只有一个方向通信，没有反方向交互，如广播
- 双向交替通信（半双工通信）：通信双方都可发消息，但不能同时发送或接收
- 双向同时通信（全双工通信）：通信双方可以同时发送和接收信息

通道复用技术：

- 频分复用（FDM，Frequency Division Multiplexing）：不同用户在不同频带，所用用户在同样时间占用不同带宽资源
- 时分复用（TDM，Time Division Multiplexing）：不同用户在同一时间段的不同时间片，所有用户在不同时间占用同样的频带宽度
- 波分复用（WDM，Wavelength Division Multiplexing）：光的频分复用
- 码分复用（CDM，Code Division Multiplexing）：不同用户使用不同的码，可以在同样时间使用同样频带通信

## 数据链路层

主要信道：

- 点对点信道
- 广播信道

### 点对点信道

- 数据单元：帧

三个基本问题：

- 封装成帧：把网络层的 IP 数据报封装成帧，`SOH - 数据部分 - EOT`
- 透明传输：不管数据部分什么字符，都能传输出去；可以通过字节填充方法解决（冲突字符前加转义字符）
- 差错检测：降低误码率（BER，Bit Error Rate），广泛使用循环冗余检测（CRC，Cyclic Redundancy Check）

点对点协议（Point-to-Point Protocol）：

- 点对点协议（Point-to-Point Protocol）：用户计算机和 ISP 通信时所使用的协议

### 广播信道

广播通信：

- 硬件地址（物理地址、MAC 地址）
- 单播（unicast）帧（一对一）：收到的帧的 MAC 地址与本站的硬件地址相同
- 广播（broadcast）帧（一对全体）：发送给本局域网上所有站点的帧
- 多播（multicast）帧（一对多）：发送给本局域网上一部分站点的帧

## 网络层

- IP（Internet Protocol，网际协议）是为计算机网络相互连接进行通信而设计的协议。
- ARP（Address Resolution Protocol，地址解析协议）
- ICMP（Internet Control Message Protocol，网际控制报文协议）
- IGMP（Internet Group Management Protocol，网际组管理协议）

### IP 网际协议

IP 地址分类：

> IP 地址 ::= {<网络号>,<主机号>}

| IP 地址类别 | 网络号 | 网络范围 | 主机号 | IP 地址范围 |
| ---- | ---- | ---- | ---- | ---- |
| A 类 | 8bit，第一位固定为 0 | 0 —— 127 | 24bit | 1.0.0.0 —— 127.255.255.255 |
| B 类 | 16bit，前两位固定为 10 | 128.0 —— 191.255 | 16bit | 128.0.0.0 —— 191.255.255.255 |
| C 类 | 24bit，前三位固定为 110 | 192.0.0 —— 223.255.255 | 8bit | 192.0.0.0 —— 223.255.255.255 |
| D 类 | 前四位固定为 1110，后面为多播地址 |  |  |  |
| E 类 | 前五位固定为 11110，后面保留为今后所用 |  |  |  |

IP 数据报格式：

![](img/network/20240201164958.png)
#### 子网掩码

子网掩码(subnet masking)的功能是告知主机或路由设备，地址的哪一部分是网络号，包括子网的网络号部分，哪一部分是主机号部分。

子网掩码使用与IP地址相同的编址格式，即4个8位组的32位长格式。

在子网掩码中，网络部分和子网络部分对应的位全为“1”，主机部分对应的位全为“0”

通过将子网掩码与IP地址进行“与”操作,可提供所给定的IP地址所属的网络号(包括子网络号)

> 172.31.128.255/18

**使用子网掩码的IP：**

>  IP地址 ::= {<网络号>， <子网号>， <主机号>}

**默认子网掩码：**

![](img/20240301110608.png)


#### 常见IP相关计算

##### 网络号

公式：**将IP地址的主机部分的二进制位全部填上0**，再将得到的二进制数转换为十进制数就可以得到网络号。

```txt
ip:        10101100.00011111.10000000.11111111  
子网掩码:   11111111.11111111.11000000.00000000
----------------------------------------------------
网络号:     10101100.00011111.10000000.00000000   ip从右向左1填为0，个数为掩码中的0　
网络号点分法表示: 172.31.128.0   
```

##### 广播地址

公式：**将IP地址的主机部分的二进制位全部填上1**，再将得到的二进制数转换为十进制数就可以得到广播地址。

```txt
ip:        10101100.00011111.10000000.11111111
子网掩码:   11111111.11111111.11000000.00000000
----------------------------------------------------
广播地址:   10101100.00011111.10111111.11111111   ip从右向左0填为1，个数为掩码中的0
广播地址点分法表示: 172.31.191.255
```

##### 可用IP地址范围

公式：网络号+1 ~ 广播地址-1

##### 主机号

公式：用**IP地址**的二进制和（**子网掩码**的二进制的**反码**）进行“**&**”运算，得到的结果就是主机号

```txt
ip:            10101100.00011111.10000000.11111111  
子网掩码取反:   00000000.00000000.00111111.11111111
----------------------------------------------------
主机号:        00000000.00000000.00000000.11111111   &　
主机号点分法表示: 0.0.0.255 
```

#### 特殊IP

##### 0.0.0.0

本机地址，`0.0.0.0`是不能被`ping`通的，即未指定地址。

在服务器中，`0.0.0.0`并不是一个真实的的**IP地址**，它表示本机中所有的**IPV4地址**。服务器不指定在哪个网卡上监听时，也使用0.0.0.0,这个时候监听本机中所有**IP**的端口。

##### 255.255.255.255

当前子网的广播地址，即当前子网的所有主机

##### 127.0.0.1

凡是以`127`开头的**IP地址**，都是**回环地址（Loop back address）**，其所在的回环接口一般被理解为虚拟网卡，并不是真正的路由器接口。

所谓的回环地址，通俗的讲，就是我们在主机上发送给`127`开头的**IP地址**的数据包会被发送的主机自己接收，根本传不出去，外部设备也无法通过回环地址访问到本机。

最后127.0.0.1属于{127,}集合中的一个，而所有网络号为127的地址都被称之为回环地址，所以回环地址！=127.0.0.1,它们是包含关系，即回环地址包含127.0.0.1

##### localhost

本机域名，在大多数系统中，localhost被指向了IPV4的127.0.0.1和IPV6的::1。

```text
127.0.0.1    localhost
​
::1          localhost
```

##### 私有地址

IP地址3种主要类型里，各保留了3个区域作为私有区域，其地址范围如下:
- A类：10.0.0.0/8 （10.0.0.1-10.255.255.255） 1个A类地址
- B类： 172.16.0.0/12（172.16.0.1-172.31.255.255）16个B类
- C类：192.168.0.0/16（192.168.0.1-192.168.255.255） 256个C类




### ICMP 网际控制报文协议

ICMP 报文格式：

![](img/network/20240201165019.png)
应用：

- PING（Packet InterNet Groper，分组网间探测）测试两个主机之间的连通性
- TTL（Time To Live，生存时间）该字段指定 IP 包被路由器丢弃之前允许通过的最大网段数量

## 运输层

协议：

- TCP（Transmission Control Protocol，传输控制协议）
- UDP（User Datagram Protocol，用户数据报协议）

端口：

不同的应用程序，使用的端口号不同

|应用程序|FTP|TELNET|SMTP|DNS|TFTP|HTTP|HTTPS|SNMP|
|---|---|---|---|---|---|---|---|---|
|端口号|21|23|25|53|69|80|443|161|

### TCP

TCP（Transmission Control Protocol，传输控制协议）是一种面向连接的、可靠的、基于字节流的传输层通信协议，其传输的单位是报文段。

特征：
- 面向连接
- 只能点对点（一对一）通信
- 可靠交互
- 全双工通信
- 面向字节流

TCP 如何保证可靠传输：

- 确认和超时重传
- 数据合理分片和排序
- 流量控制
- 拥塞控制
- 数据校验

TCP 报文结构：

![](img/network/20240228163659.png)
TCP 首部：

![](img/network/20240228163711.png)TCP：状态控制码（Code，Control Flag），占 6 比特，含义如下：

- URG：紧急比特（urgent），当 `URG＝1` 时，表明紧急指针字段有效，代表该封包为紧急封包。它告诉系统此报文段中有紧急数据，应尽快传送(相当于高优先级的数据)， 且上图中的 Urgent Pointer 字段也会被启用。
- ACK：确认比特（Acknowledge）。只有当 `ACK＝1` 时确认号字段才有效，代表这个封包为确认封包。当 `ACK＝0` 时，确认号无效。
- PSH：（Push function）若为 1 时，代表要求对方立即传送缓冲区内的其他对应封包，而无需等缓冲满了才送。
- RST：复位比特(Reset)，当 `RST＝1` 时，表明 TCP 连接中出现严重差错（如由于主机崩溃或其他原因），必须释放连接，然后再重新建立运输连接。
- SYN：同步比特(Synchronous)，SYN 置为 1，就表示这是一个连接请求或连接接受报文，通常带有 SYN 标志的封包表示『主动』要连接到对方的意思。
- FIN：终止比特(Final)，用来释放一个连接。当 `FIN＝1` 时，表明此报文段的发送端的数据已发送完毕，并要求释放运输连接。
### UDP

UDP（User Datagram Protocol，用户数据报协议）是 OSI（Open System Interconnection 开放式系统互联） 参考模型中一种无连接的传输层协议，提供面向事务的简单不可靠信息传送服务，其传输的单位是用户数据报。

特征：

- 无连接
- 尽最大努力交付
- 面向报文
- 没有拥塞控制
- 支持一对一、一对多、多对一、多对多的交互通信
- 首部开销小

UDP 报文结构：

![](img/network/20240228163913.png)

UDP 首部：

![](img/network/20240228163923.png)


### TCP vs UDP

|  | TCP | UDP |
| ---- | ---- | ---- |
| 首部大小 | 首部开销20字节 | 首部开销8字节 |
| 连接 | 面向连接 | 无连接 |
| 可靠性 | 提供可靠的服务：<br>通过 TCP 连接传送的数据：<br>无差错、不丢失、不重复、按序到达 | 尽最大努力交付：<br>即不保证可靠交付 |
| 逻辑通信信道 | 全双工的可靠信道 | 不可靠信道 |
| 通信方式 | 点到点 | 支持一对一，一对多，多对一和多对多 |
| 数据方式 | 面向字节流（可能出现黏包问题），实际上是 TCP 把数据看成一连串无结构的字节流 | 面向报文的（不会出现黏包问题） |
| 拥塞控制 | 有 | 无，网络出现拥塞不会使源主机的发送速率降低（对实时应用很有用，如 IP 电话，实时视频会议等） |

### TCP黏包问题

TCP 是一个基于字节流的传输服务（UDP 基于报文的），“流” 意味着 TCP 所传输的数据是没有边界的。所以可能会出现两个数据包黏在一起的情况。

**解决方案：**

- 发送定长包。如果每个消息的大小都是一样的，那么在接收对等方只要累计接收数据，直到数据等于一个定长的数值就将它作为一个消息。
- 包头加上包体长度。包头是定长的 4 个字节，说明了包体的长度。接收对等方先接收包头长度，依据包头长度来接收包体。
- 在数据包之间设置边界，如添加特殊符号 `\r\n` 标记。FTP 协议正是这么做的。但问题在于如果数据正文中也含有 `\r\n`，则会误判为消息的边界。
- 使用更加复杂的应用层协议。

### TCP浏览控制

流量控制（flow control）就是让发送方的发送速率不要太快，要让接收方来得及接收。

**方法：** 利用可变窗口进行流量控制

![](img/network/20240228165028.png)


### TCP拥塞控制

拥塞控制就是防止过多的数据注入到网络中，这样可以使网络中的路由器或链路不致过载。

**方法：**

- 慢开始( slow-start )
- 拥塞避免( congestion avoidance )
- 快重传( fast retransmit )
- 快恢复( fast recovery )

**拥塞控制图：**


![](img/network/20240228165546.png)

![](img/network/20240228165424.png)
cwnd：Congestion Window，拥塞窗口
ssthresh：Slow Start Threshold，慢启动阈值；一般设置为当前窗口值的一般

慢开始：从1开始
快恢复：按指数增长，做回复，直到ssthresh
拥塞避免：达到ssthresh后，按线性增长；直到超时，或者收到ack；
快重传：

![](img/network/20240228165532.png)

### TCP三次握手

![](img/network/20240228172943.png)

- 1. 客户端发送 SYN 给服务器，说明客户端请求建立连接；
- 2. 服务端收到客户端发的 SYN，并回复 SYN+ACK 给客户端（同意建立连接）；
- 3. 客户端收到服务端的 SYN+ACK 后，回复 ACK 给服务端（表示客户端收到了服务端发的同意报文）；
- 4. 服务端收到客户端的 ACK，连接已建立，可以数据传输。

#### 为什么要进行三次握手？

因为双方都需要确认对方收到了自己发送的序列号，确认过程最少要进行三次通信。

### TCP四次挥手

![](img/network/20240228173125.png)
- 1. 客户端发送 FIN 给服务器，说明客户端不必发送数据给服务器了（请求释放从客户端到服务器的连接）；
- 2. 服务器接收到客户端发的 FIN，并回复 ACK 给客户端（同意释放从客户端到服务器的连接）；
- 3. 客户端收到服务端回复的 ACK，此时从客户端到服务器的连接已释放（但服务端到客户端的连接还未释放，并且客户端还可以接收数据）；
- 4. 服务端继续发送之前没发完的数据给客户端；
- 5. 服务端发送 FIN+ACK 给客户端，说明服务端发送完了数据（请求释放从服务端到客户端的连接，就算没收到客户端的回复，过段时间也会自动释放）；
- 6. 客户端收到服务端的 FIN+ACK，并回复 ACK 给服务端（同意释放从服务端到客户端的连接）；
- 7. 服务端收到客户端的 ACK 后，释放从服务端到客户端的连接。

##### 为什么要进行四次挥手？

**TCP 为什么要进行四次挥手？ / 为什么 TCP 建立连接需要三次，而释放连接则需要四次？**

因为 TCP 是全双工模式，客户端请求关闭连接后，客户端向服务端的连接关闭（一二次挥手），服务端继续传输之前没传完的数据给客户端（数据传输），服务端向客户端的连接关闭（三四次挥手）。所以 TCP 释放连接时服务器的 ACK 和 FIN 是分开发送的（中间隔着数据传输），而 TCP 建立连接时服务器的 ACK 和 SYN 是一起发送的（第二次握手），所以 TCP 建立连接需要三次，而释放连接则需要四次。

**为什么 TCP 连接时可以 ACK 和 SYN 一起发送，而释放时则 ACK 和 FIN 分开发送呢？（ACK 和 FIN 分开是指第二次和第三次挥手）**

因为客户端请求释放时，服务器可能还有数据需要传输给客户端，因此服务端要先响应客户端 FIN 请求（服务端发送 ACK），然后数据传输，传输完成后，服务端再提出 FIN 请求（服务端发送 FIN）；而连接时则没有中间的数据传输，因此连接时可以 ACK 和 SYN 一起发送。

**为什么客户端释放最后需要 TIME-WAIT 等待 2MSL 呢？**

- 1. 为了保证客户端发送的最后一个 ACK 报文能够到达服务端。若未成功到达，则服务端超时重传 FIN+ACK 报文段，客户端再重传 ACK，并重新计时。
- 2. 防止已失效的连接请求报文段出现在本连接中。TIME-WAIT 持续 2MSL (Maximum Segment Lifetime，最大报文段生存时间) 可使本连接持续的时间内所产生的所有报文段都从网络中消失，这样可使下次连接中不会出现旧的连接报文段。

### TCP 有限状态机

![](img/network/20240228173911.png)

**TCP的11种状态：**
- **CLOSED**：初始时没有任何连接的状态。
- **LISTEN**：服务器监听来自客户端的连接请求(SYN包)。
- **SYN_SENT**：客户端socket执行CONNECT连接，发送SYN包，之后等待来自服务器的SYN ACK包(服务器的连接请求和对客户端连接请求的确认)。
- **SYN_RCVD**：服务端收到客户端的SYN包并发送服务端SYN ACK包，之后等待客户端对连接请求的确认(ACK包)。
- **ESTABLISH**：表示连接建立。客户端发送了最后一个ACK包后进入此状态，服务端接收到ACK包后进入此状态。
- **FIN_WAIT_1**：终止连接的一方（通常是客户机）发送了FIN包后进入此状态，之后等待对方FIN包。
- **CLOSE_WAIT**：（假设服务器）接收到客户机FIN包之后等待关闭的阶段。在接收到对方的FIN包之后，自然是需要立即回复ACK包的，表示已经知道断开请求。但是本方是否立即断开连接（发送FIN包）取决于是否还有数据需要发送给客户端，若还有数据要发送，则在发送FIN包之前均为此状态。
- **FIN_WAIT_2**：客户端接收到服务器的ACK包，但并没有立即接收到服务端的FIN包，进入FIN_WAIT_2状态。此时是半连接状态，即有一方要求关闭连接，等待另一方关闭。
- **LAST_ACK**：服务端发动最后的FIN包，等待最后的客户端ACK包。
- **CLOSING**：当主动关闭方处于FIN_WAIT_1时，被动关闭方的 FIN 先于之前的自己发送的 ACK 到达，主动关闭方就直接FIN_WAIT_1 -> CLOSING，（其实就相当于同时关闭)，然后迟来的 ACK 到达时，主动关闭方就从CLOSING -> TIME_WAIT。
- **TIME_WAIT**：客户端收到服务端的FIN包，并立即发出ACK包做最后的确认，在此之后的2MSL(两倍的最长报文段寿命)时间称为TIME_WAIT状态。

## 应用层

#### DNS

- DNS（Domain Name System，域名系统）是互联网的一项服务。它作为将域名和 IP 地址相互映射的一个分布式数据库，能够使人更方便地访问互联网。DNS 使用 TCP 和 UDP 端口 53。当前，对于每一级域名长度的限制是 63 个字符，域名总长度则不能超过 253 个字符。

域名：

- `域名 ::= {<三级域名>.<二级域名>.<顶级域名>}`，如：`blog.huihut.com`

#### FTP

- FTP（File Transfer Protocol，文件传输协议）是用于在网络上进行文件传输的一套标准协议，使用客户/服务器模式，使用 TCP 数据报，提供交互式访问，双向传输。
- TFTP（Trivial File Transfer Protocol，简单文件传输协议）一个小且易实现的文件传输协议，也使用客户-服务器方式，使用UDP数据报，只支持文件传输而不支持交互，没有列目录，不能对用户进行身份鉴定

#### TELNET

- TELNET （telnet protoco，远程登陆协议）是 TCP/IP 协议族中的一员，是 Internet 远程登陆服务的标准协议和主要方式。它为用户提供了在本地计算机上完成远程主机工作的能力。
    
- HTTP（HyperText Transfer Protocol，超文本传输协议）是用于从 WWW（World Wide Web，万维网）服务器传输超文本到本地浏览器的传送协议。
    
- SMTP（Simple Mail Transfer Protocol，简单邮件传输协议）是一组用于由源地址到目的地址传送邮件的规则，由它来控制信件的中转方式。SMTP 协议属于 TCP/IP 协议簇，它帮助每台计算机在发送或中转信件时找到下一个目的地。
    
- Socket 建立网络通信连接至少要一对端口号（Socket）。Socket 本质是编程接口（API），对 TCP/IP 的封装，TCP/IP 也要提供可供程序员做网络开发所用的接口，这就是 Socket 编程接口。

#### WWW

- WWW（World Wide Web，环球信息网，万维网）是一个由许多互相链接的超文本组成的系统，通过互联网访问
#### URL

- URL（Uniform Resource Locator，统一资源定位符）是因特网上标准的资源的地址（Address）

标准格式：

- `协议类型:[//服务器地址[:端口号]][/资源层级UNIX文件路径]文件名[?查询][#片段ID]`

完整格式：

- `协议类型:[//[访问资源需要的凭证信息@]服务器地址[:端口号]][/资源层级UNIX文件路径]文件名[?查询][#片段ID]`

> 其中【访问凭证信息@；:端口号；?查询；#片段ID】都属于选填项  
> 如：`https://github.com/huihut/interview#cc`

#### HTTP

HTTP（HyperText Transfer Protocol，超文本传输协议）是一种用于分布式、协作式和超媒体信息系统的应用层协议。HTTP 是万维网的数据通信的基础。

请求方法

|方法|意义|
|---|---|
|OPTIONS|请求一些选项信息，允许客户端查看服务器的性能|
|GET|请求指定的页面信息，并返回实体主体|
|HEAD|类似于 get 请求，只不过返回的响应中没有具体的内容，用于获取报头|
|POST|向指定资源提交数据进行处理请求（例如提交表单或者上传文件）。数据被包含在请求体中。POST请求可能会导致新的资源的建立和/或已有资源的修改|
|PUT|从客户端向服务器传送的数据取代指定的文档的内容|
|DELETE|请求服务器删除指定的页面|
|TRACE|回显服务器收到的请求，主要用于测试或诊断|

状态码（Status-Code）

- 1xx：表示通知信息，如请求收到了或正在进行处理
    - 100 Continue：继续，客户端应继续其请求
    - 101 Switching Protocols 切换协议。服务器根据客户端的请求切换协议。只能切换到更高级的协议，例如，切换到 HTTP 的新版本协议
- 2xx：表示成功，如接收或知道了
    - 200 OK: 请求成功
- 3xx：表示重定向，如要完成请求还必须采取进一步的行动
    - 301 Moved Permanently: 永久移动。请求的资源已被永久的移动到新 URL，返回信息会包括新的 URL，浏览器会自动定向到新 URL。今后任何新的请求都应使用新的 URL 代替
- 4xx：表示客户的差错，如请求中有错误的语法或不能完成
    - 400 Bad Request: 客户端请求的语法错误，服务器无法理解
    - 401 Unauthorized: 请求要求用户的身份认证
    - 403 Forbidden: 服务器理解请求客户端的请求，但是拒绝执行此请求（权限不够）
    - 404 Not Found: 服务器无法根据客户端的请求找到资源（网页）。通过此代码，网站设计人员可设置 “您所请求的资源无法找到” 的个性页面
    - 408 Request Timeout: 服务器等待客户端发送的请求时间过长，超时
- 5xx：表示服务器的差错，如服务器失效无法完成请求
    - 500 Internal Server Error: 服务器内部错误，无法完成请求
    - 503 Service Unavailable: 由于超载或系统维护，服务器暂时的无法处理客户端的请求。延时的长度可包含在服务器的 Retry-After 头信息中
    - 504 Gateway Timeout: 充当网关或代理的服务器，未及时从远端服务器获取请求

## 主机字节序

### 主机字节序（CPU 字节序）

#### 概念

主机字节序又叫 CPU 字节序，其不是由操作系统决定的，而是由 CPU 指令集架构决定的。主机字节序分为两种：

- 大端字节序（Big Endian）：高序字节存储在低位地址，低序字节存储在高位地址
- 小端字节序（Little Endian）：高序字节存储在高位地址，低序字节存储在低位地址

#### 存储方式

32 位整数 0x12345678 是从起始位置为 0x00 的地址开始存放，则：

![](img/network/20240229103244.png)

大端小端图片

![](img/network/20240229103300.png)

#### 判断大端小端

判断大端小端

可以这样判断自己 CPU 字节序是大端还是小端：

```cpp
#include <iostream>
using namespace std;

int main()
{
    int i = 0x12345678;

    if (*((char*)&i) == 0x12)
        cout << "大端" << endl;
    else    
        cout << "小端" << endl;

    return 0;
}
```

#### 各架构处理器的字节序

- x86（Intel、AMD）、MOS Technology 6502、Z80、VAX、PDP-11 等处理器为小端序；
- Motorola 6800、Motorola 68000、PowerPC 970、System/370、SPARC（除 V9 外）等处理器为大端序；
- ARM（默认小端序）、PowerPC（除 PowerPC 970 外）、DEC Alpha、SPARC V9、MIPS、PA-RISC 及 IA64 的字节序是可配置的。

### 网络字节序

网络字节顺序是 TCP/IP 中规定好的一种数据表示格式，它与具体的 CPU 类型、操作系统等无关，从而可以保证数据在不同主机之间传输时能够被正确解释。

网络字节顺序采用：大端（Big Endian）排列方式。

## Socket编程

### 网络中进程之间如何通信

本地的进程间通信（IPC）有很多种方式，但可以总结为下面4类：

- 消息传递（管道、FIFO、消息队列）
- 同步（互斥量、条件变量、读写锁、文件和写记录锁、信号量）
- 共享内存（匿名的和具名的）
- 远程过程调用（Solaris门和Sun RPC）

但这些都不是本文的主题！我们要讨论的是网络中进程之间如何通信？首要解决的问题是如何唯一标识一个进程，否则通信无从谈起！在本地可以通过进程PID来唯一标识一个进程，但是在网络中这是行不通的。其实TCP/IP协议族已经帮我们解决了这个问题，网络层的“**ip地址**”可以唯一标识网络中的主机，而传输层的“**协议+端口**”可以唯一标识主机中的应用程序（进程）。这样利用**三元组（ip地址，协议，端口）** 就可以标识网络的进程了，网络中的进程通信就可以利用这个标志与其它进程进行交互。

使用TCP/IP协议的应用程序通常采用应用编程接口：UNIX  BSD的套接字（socket）和UNIX System V的TLI（已经被淘汰），来实现网络进程之间的通信。就目前而言，几乎所有的应用程序都是采用socket，而现在又是网络时代，网络中进程通信是无处不在，这就是我为什么说“一切皆socket”。

### 什么是Socket

socket是在应用层和传输层之间的一个抽象层，它把TCP/IP层复杂的操作抽象为几个简单的接口供应用层调用已实现进程在网络中通信。

![](img/network/20240229145316.png)

socket起源于Unix，而Unix/Linux基本哲学之一就是 **“一切皆文件”** ，都可以用“**打开open** –> **读写write/read** –> **关闭close**”模式来操作。我的理解就是Socket就是该模式的一个实现，socket即是一种特殊的文件，一些socket函数就是对其进行的操作（读/写IO、打开、关闭）

### Socket函数罗列

| 作用 | 声明 |
| ---- | ---- |
| 分配Socket | int socket(int domain, int type, int protocol); |
| 关闭socket | int close(int fd); |
| 给 Socket 指定本地地址 | int bind(int sockfd, const struct sockaddr \*addr, socklen_t addrlen); |
| 准备接受连接请求 | int listen(int sockfd, int backlog);<br> |
| 接受指定 Socket 的连接请求 | int accept(int sockfd, struct sockaddr \*addr, socklen_t \*addrlen); |
| 建立连接 | int connect(int sockfd, const struct sockaddr \*addr, socklen_t addrlen); |
| recvmsg()/sendmsg()函数是最通用的I/O函数，实际上可以把上面的其它函数都替换成这两个函数 | read()/write()<br>recv()/send()<br>readv()/writev()<br>recvmsg()/sendmsg()<br>recvfrom()/sendto() |

### socket

分配Socket

```cpp
#include <sys/types.h>
#include <sys/socket.h>
int socket(int domain, int type, int protocol);
```

socket0函数分配一个 Socket 句柄，用于指定特定网络下、使用特定的协议和数据传送方式进行通信。Socket 接口是不仅仅局限于 TCP/IP 的，但是由于 TCPIP 的广泛使用，它们几乎被完全等同起来了。

Socket 句柄分配以后，如果要开始 TCP 通信，还需要建立连接。根据需要，可以主动地建立连接(通过 connect0) 和被动地等待对方建立连接 (通过 listen())，在连接建立后才能使用读写操作通过网络连接进行数据交换。

#### 返回值

正常执行时，返回 Socket 描述符:否则，返回-1，错误状态在全局变量 errno 中。

#### 参数说明

**domain** 选择通信中使用的协议族，也就是网络的类型 :

- AF_UNIX    (UNIX 内部协议)
- AF_INET    (ARPA Internet 协议，也就是 TCP/IP 协议族)
- AF_ISO     (ISO 协议)
- AF_NS      (Xerox Network Systems 协议)
- AF_IMPLINK (IMP "host at IMp" link layer)

**type** 指定数据传送的方式：

- SOCK_STREAM: 保证顺序的、可靠传送的双向字节数据流，最为常用，也是 TCP 连接所使用的方式
- SOCK_DGRAM: 无连接的、不保证可靠的、固定长度(通常很小) 的消息传送
- SOCK_SEQPACKET: 顺序的、可靠的双向固定长度的数据包传送，只用于 AF NS 类型的网络中
- SOCK_RAW:原始的数据传送,适用于系统内部专用的网终协议和接口,和SOCK_RDM样，只能由超级用户使用
- SOCK_RDM: 可靠的数据报传送，未实现

**protocol** 指定通信中使用的协议：

在给定 Socket 的协议族和传送类型之后,一般情况下所使用的协议也就固定下来，如下表所示，此时 protocol 参数可使用缺省值’0’；

但如果还有多个协议供选择，则必须使用 protocol 参数来标识。

| 协议族 (仅考虑 IP协议) | 传送类型 | protocol 参数常量<br>(/usr/include/linux/in.h ) | 协议类型 |
| ---- | ---- | ---- | ---- |
| AF_INET | SOCK_STREAM<br>SOCK_DGRAM<br>SOCK_RAW<br>SOCK_RAW | IPPROTO_TCP<br>IPPROTO_UDP<br>IPPROTO_ICMP<br>IPRROTO_RAW | TCP<br>UDP<br>ICMP<br>(raw) |

### close

关闭 Socket

```cpp
#include <unistd.h>
int close(int fd);
```

Socket 和文件描述符的关闭操作都是使用这个函数。

#### 返回值

正常时返回 0，-1 表示出错

#### 参数说明

- fd ：Socket 描述符。

### bind

给 Socket 指定本地地址

```cpp
#include <sys/types.h>
#include <sys/socket.h>
int bind(int sockfd, struct sockaddr *my_addr, int addrlen);
```

bind 函数给已经打开的 Socket 指定本地地址。这个函数的使用有以下两种情况:

一、如果此 Socket 是面向连接的，而且此 Socket 在连接建立过程中处于被动的地位，即，己方程序使用 listen 函数等待对方建立连接，对方用 connect 函数来向此 Socket 建立连接，这种情况下，必须用 bind 给此 Socket 设定本地地址。在已方使用 listen 函数时，除指定 Socket描述符之外，该 Socket 必须已经用 bind 函数设定好了本地地址(包括 IP 地址和端口号)，这样,系统在收到建立连接的网络请求时,才能根据请求的目的地址,识别是通向哪个 Socket 的连接，从而己方才能用此 Socket 接收到发给此 Socket 地址的数据包。不指定 Socket 的本地地址，就无法将此 Socket 用于连接建立和数据接收。

二、如果此 Socket 用于无连接的情形，同样也要求给该 Socket 设定本地地址，这样，以后
系统从网络中接收到数据后，才知道该送给哪个 Socket 及其相对应的进程。

#### 返回值

正常时返回 0，否则返回:1，同时 errno 是系统错误码

#### 参数说明

- **sockfd**  ：Socket 描述符
- **addrlen** ：my_addr 结构的长度
- **my_addr** ：用于侦听连接请求的本地地址

**struct sockaddr** 是一个通用型的结构，不仅包含TCP/IP 协议的情况，同时也是为了适合于其它网络，如 AF NS。

由于它的这种通用性，它只是定义了一个一般意义上的存储空间，/usr/include/linux/socket.h 中所示:
```cpp
struct sockaddr
{
   unsigned short sa_family;/* address family, AF xxx */
   char           sa_data[14]; /* 14 bytes of protocol address */
};
```

当使用 TCP/IP 协议(即: Intermet 协议) 时，可用如下的 struct 等价地代替 struct sockaddr
(/usr/include/linux/in.h ):

```cpp
struct sockaddr_in
{
    unsigned short int sin_family; /* Address family.  */
    in_port_t sin_port;     /* Port number.  */
    struct in_addr sin_addr;    /* Internet address.  */
    /* Pad to size of `struct sockaddr'.  */
    unsigned char sin_zero[sizeof (struct sockaddr)
            - sizeof (unsigned short int)
            - sizeof (in_port_t)
            - sizeof (struct in_addr)];
};
```

在 Socket 程序中，等待建立连接一方的准备过程请参见编程实例，以及 listen0、accept0的
说明。

### listen

准备接受连接请求

```cpp
#include <sys/socket.h>
int listen(int s,int backlog);
```

在用 bind()给一个 socket 设定本地地址之后，就可以将这个 socket 用于接受连接请求，即 listen()。调用 listen()之后，系统将给此 socket 配备一个连接请求的队列，暂存系统接收到的、申请向此 Socket 建立连接的请求，等待用户程序用 accept()正式接受该请求。队列长度，就由 backlog 参数指定。如下面的简图所示:

![](img/network/17091945731419.png)

如果短时间内向己方建立连接的请求过多，已方来不及处理，那么排在 backlog 之后的请求将被系统拒绝。因此，backlog 参数实际上规定了已方程序能够容许的连接建立处理速度。

至于己方程序使用此 Socket(及其指定的本地地址) 实际建立连接的个数，由己方程序调用accept()的次数来决定，参见 accept()的说明。

#### 返回值

正常时返回 0: 否则返回-1，同时 errno 是系统错误码

#### 参数说明

 - s       ：Socket 描述符
 - backlog ：连接请求暂存队列长度

### non_blocking

非阻塞，windows和linux创建Socket时，默认都是阻塞的（bloking）

可以通过 Unix 文件操作函数来设置的

```cpp
#include <unistd.h>
#include <fcntl.h>
fcntl(socket， F_SETFL， O_NONBLOCK):
```

### accept

接受指定 Socket 的连接请求

```cpp
#include <sys/types.h>
#include <sys/socket.h>
int accept(int s, struct sockaddr *addr, int *addrlen);
```

在调用 listen()之后，系统就在 Socket 的连接请求暂存队列里存放每一个向该 Socket(及其本地地址) 建立的连接请求。

accept()函数的作用就是，从该暂存队列中取出一个连接请求，用该 Socket的数据，创建一个新的 Socket: Socket_New，并为它分配一个文件描述符。

Socket_New 即标识了此次建立的连接，可被已方用来向连接的另一方发送和接收数据(write/read，send/recv)。同时，原 Socket 仍然保持打开状态不变，继续用于等待网络连接请求。

如果该 Socket 的暂存队列中没有待处理的连接请求，根据 Socket 的特征选项(是否non_blocking),

accept()函数将选择两种方式: 

- 如果该 Socket 不是 non_blocking 型的，accept()将一直等待，直到收到一个连接请求后才返回:
- 如果该 Socket 是 non_blocking 型的，那么accept()将立即返回，但如果没有连接请求，只返回错误信息，不创建新的 Socket New。

accept()返回后，如果创建了新的 Socket_New 来标识新建立的连接，那么参数 addr 指定的结构里面将会有对方的地址信息，addrlen 是地址信息的长度。

关于 accept()的进一步信息，如: 如何检测某 Socket 有无待处理的连接请求、如何在使用 accept()接受连接请求之前先获取连接对方的地址、如何根据获取的对方地址信息拒绝该连接请求等，请参阅 Linux manual，此处不再累述。

#### 返回值

如果正常创建了一个新的连接，那么返回非负的整数: 即新连接的 Socket 描述符

> 注意，用于等待连接请求的原 Socket 保持打开状态不变，可用于接收新的连接请求

否则，返回-1，errno 是系统错误码
#### 参数说明

- s      ：Socket 描述符
- addr   ：accept()接受连接后，在 addr 指向的结构中存放对方的地址信息。如果是 AF_INET Socket,该地址信息就是对方的 IP地址和端口号
- addrlen：在调用 accept()之前，\*addrlen 必须被设置为 addr 数据结构的合法长度。在 accept()返回之后，\*addrlen 中是对方地址信息的长度

### connect

建立连接

```cpp
#include <sys/types.h>
#include <sys/socket.h>
int connect(int sockfd, struct sockaddr *serv addr, int addrlen );
```

前面提到的函数，如 bind、listen、connect 等，都是用于被动地等待对方建立连接时需要使用的，而 connect()函数，则是主动地向对方建立连接时使用的。connect0使用一个事先打开的 Socket，和目的方(即通信对方，或称服务器一方) 地址信息，向对方发出连接建立请求。一个完整的 Socket 通信发起过程可简单地图示为:

![](img/network/17091956805846.png)
如果是 SOCK_STREAM 型的 Socket，通常只用 connect()建立一个正常的连接。但如果是SOCK_DGRAM 型的 Socket，connect)函数并不象上图中那样向目的方发出连接建立请求而只是简单地用给出的地址设置该 Socket 的目的地址，以后该 Socket 的无连接数据报就发往该目的地址。因此，对于 SOCK DGRAM 型的 Socket，可以多次调用 connect()来改变该Socket 的目的地址。

#### 返回值

连接正常建立时返回 0；否则，返回-1，系统错误码在 errno 中

#### 参数说明

- sockfd      ：Socket 描述符
- serv_addr   ：通信目的方的地址
- addrlen     ：目的地址长度


### send/recv

用 Socket 发送和接收数据

```cpp
#include <sys/types.h>
#include <sys/socket.h>
int send(int s,const void *msg, int len,unsigned int flags);
int sendto(int s, const void *msg, int len,unsigned int flags, const struct sockaddr *to, int tolen);

int recv(int s,void *buf, int len, unsigned int flags);
int recvfrom(int s, void *buf, int len, unsigned int flags, struct sockaddr *from, int
*fromlen);
```

在连接建立完成后，通信双方就可以使用以上这些函数来进行数据的发送和接收操作。

其中: 
- send 和 recv 用于连接建立以后的发送和接收: 
- sendto 和 recvfrom 用于非连接的协议

对于非 non_blocking 型的 Socket，send 将等待数据发送完后才返回;
对于 non_blocking 型的 Socket，send 将立即返回，用户程序需要用 select()函数决定网络发送是否结束

类似地对于非 non_blocking 型的 Socket，若系统没有收到任何数据，recv 将等待接收数据到达后才返回；
对于 non_blocking 型的 Socket，recv 将立即返回，并返回错误信息或者接收到的数据字节数

sendto 和 recvfrom 因为是非连接型的发送和接收，必须在参数中给出目的地址或者存放源地址的空间

#### 返回值

send/sendto 返回实际发送的数据字节数，或者-1，表示出错

recv/recvfrom 返回实际接收到的数据字节数，或者-1，表示出错

#### 参数说明

- s             ： Socket 描述符
- msg,buf       ：存放接收或者发送数据的存储空间;
- len           ：接收或者发送数据的字节数:
- flags         ： 通常设为 0，详细说明请参见 Linux Manual
- to,from       ：sendto 和 recvfrom 所使用的，目的方地址和存放源地址的空间:
- tolen,fromlen ：目的地址和源地址空间大小。

### read/write

用系统文件操作进行 Socket 通信

```cpp
#include <unistd.h>
ssize_t read(int fd, void *buf, size_t count),
ssize_t write(int fd, const void *buf, size_t count):
```

在连接建立完成后，对于连接建立过程中被动的一方，在accept()正常返回后，它返回个新的Socket，并且为该 Socket 分配了一个文件描述符；对于连接请求发起方，connect()正常返回后，相应的 Socket 中也包含有已分配的文件描述符。

因此，可以使用标准的 Unix文件读写函数 read()/write()来进行 Socket 通信。要注意的是，由于网络数据和磁盘文件不一样，不是已经准备好的

因此，每次读写操作不一定能传送完指定长度的数据，需要由程序反复进行剩余部分的传送。

另外，文件描述符是较底层的文件操作参数，不同于 C 语言中常用的 FILE\*。FILE\*是使用 fread/fwrite 函数来进行读写操作的。

#### 返回值

正常时，返回所读写的字节数(注意，可能小于 count 参数指定的数目)；

否则，返回-1，errno 是系统错误码。

#### 参数说明

- fd      ：文件或者 Socket 描述符
- buf     ：数据缓冲区
- count   ：数据字节数

### 数据格式转换

```cpp
#include <netinet/in.h>
unsigned long int htonl(unsigned long int hostlong);
unsigned short int htons(unsigned short int hostshort);
unsigned long int ntohl(unsigned long int netlong);
unsigned short int ntohs(unsigned short int netshort);
```

- htons--"Host to Network Short"
- htonl--"Host to Network Long"
- ntohs--"Network to Host Short"
- ntohl--"Network to Host Long"

> h表示"host" ，n表示"network"，s 表示"short"，l表示 "long"

数据格式转换函数提供和硬件平台无关的、主机数据字节顺序和网络字节顺序之间的转换。由于各种平台 CPU 结构的不同，在不同的硬件平台下，主机的字节顺序有两种情况:

- Intel80x86 和 SUN Sparc CPU 的低位在前格式 (小端)
- Motorola CPU (68000、PowerPC) 等的高位在前格式（大端）

网络数据交换要求网络中所有的 int 型数据都有统一的字节顺序:高位在前格式，因此在 Socket 函数库中提供了以上统一的字节顺序转换函数。

在 Socket 程序中使用的地址数据，如端口号等，都必须遵循这样统一的字节顺序。

因此，在 bind()函数、connect()函数等涉及 struct sockaddr_in 地址数据的场合，都需要以上转换函数，以加强源程序的可移植性。


### 主机名字/地址数据查询

为配合 DNS 的使用，尽量方便 Intermet 主机名字的记忆，避免使用烦琐的数字式IP 地
址，Socket 函数库提供了方便的主机名字查询函数。

#### struct hostent

struct hostent 是一个关于主机地址信息的数据结构，其中包含从 DNS 服务器得到的比较全面的主机信息。

gethostbyname()和 gethostbyaddr())都返回这样的数据结构。

实际使用时,可用此结构中的地址信息来设置 bind() 和 connect() 函数参数中的 struct sockaddr_in 中的地址，以支持 DNS 名字的使用

```cpp
#include <netdb.h>
struct hostent {
    char *h_name;       /* official name of host */
    char **h_aliases;   /* alias list */
    int h_addrtype;     /* host address type */
    int h_length;       /* length ofaddress */
    char **h_addr_list; /* list ofaddresses from name server */
};

#define h_addr h_addr_list[(0)]  /* address, for backward compatibility */
```
这其中最常用的是 h_addr，即主机的缺省地址(因为该主机名字可能对应多个地址)。

#### gethostbyname

```cpp
#include <netdb.h>
struct hostent *gethostbyname(char *name):
```

根据 DNS 名字，查找主机地址信息。name 可以是 DNS 名字，如wwwustc.edu.cn”，也可以是 IP 地址串:”202.38.64.2”

#### gethostbyaddr

```cpp
#include <netdb.h>
struct hostent *gethostbyaddr(char *addr; int len, int type);
```

根据IP地址查找主机地址信息。addr 是整数格式的IP地址指针，

如：unsigned char addr\[4\]= {202，38，64，2}

在 Internet 协议中，len 必须为 4，type 必须为 AF_INET。

要注意的是:如果只知道主机的 IP 地址，而且 DNS 服务器中没有登记该主机，用gethostbyname 总能得到适当的主机地址信息，它只需要简单地将 ASCⅡ形式的 地址转换为二进制格式。但如果使用 gethostbyaddr，却得不到所需要的地址信息，因为此函数完全依靠 DNS 服务器进行 IP 到DNS 名字的转换，不作其它的处理。

### Demo代码

[learning/src/network/socket at main · su-dd/learning (github.com)](https://github.com/su-dd/learning/tree/main/src/network/socket)

**参考：**

[GitHub - huihut/interview.](https://github.com/huihut/interview?tab=readme-ov-file#computer-network)

[Linux Socket编程（不限Linux） - 吴秦 - 博客园 (cnblogs.com)](https://www.cnblogs.com/skynet/archive/2010/12/12/1903949.html)

[网络编程socket基本API详解 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/362983198)

[IP地址计算---子网掩码确定和子网划分等详解 (附常见相关习题)_子网掩码计算例题和讲解-CSDN博客](https://blog.csdn.net/qq_41207757/article/details/107839099)
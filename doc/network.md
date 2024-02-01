![](img/network/Pasted%20image%2020240201164815.png)
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
- `IP 地址 ::= {<网络号>,<主机号>}`

|IP 地址类别|网络号|网络范围|主机号|IP 地址范围|
|---|---|---|---|---|
|A 类|8bit，第一位固定为 0|0 —— 127|24bit|1.0.0.0 —— 127.255.255.255|
|B 类|16bit，前两位固定为 10|128.0 —— 191.255|16bit|128.0.0.0 —— 191.255.255.255|
|C 类|24bit，前三位固定为 110|192.0.0 —— 223.255.255|8bit|192.0.0.0 —— 223.255.255.255|
|D 类|前四位固定为 1110，后面为多播地址||||
|E 类|前五位固定为 11110，后面保留为今后所用|||

IP 数据报格式：

![](img/network/Pasted%20image%2020240201164958.png)


### ICMP 网际控制报文协议

ICMP 报文格式：

![](img/network/Pasted%20image%2020240201165019.png)
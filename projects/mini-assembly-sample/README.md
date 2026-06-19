# Mini 智能装配线样机 — 项目模板

概述
- 目标：提供一个可立刻克隆的 GitHub 项目模板，包含 STM32 固件骨架、PLC 伪代码、HMI 示例页面与 BOM，便于你按周计划快速落地“自动送料 + 视觉检测 + 伺服对位”样机。

目录
- `firmware/`：STM32 固件示例（`main.c`、`pid.c`、`comms.c`、`Makefile`）。
- `plc/`：PLC 伪代码与梯形逻辑说明 (`plc_logic.md`)。
- `hmi/`：HMI 示例页面（`index.html`）与界面资源。
- `bom.md`：低成本硬件清单与采购建议。
- `README.md`：本文件。

如何使用
1. 克隆此目录到你的本地仓库：`git clone ...`（或直接将 `projects/mini-assembly-sample` 复制到你的仓库）。
2. 在 `firmware/` 中打开 `main.c`，根据你的开发板（STM32F103/F4/Nucleo）调整启动与外设配置。
3. 使用提供的 PLC 伪代码作为 PLC 程序参考（梯形图工具或厂商 IDE 中实现）。
4. 启动 `hmi/index.html`（本地打开或放到轻量 Web 服务），和设备联调。

建议流程
- 第1周：完成 `firmware` 的 UART/Encoder/PWM 骨架，能回传状态。 
- 第2周：实现基础 PID 闭环与简单运动命令。
- 第3周：用 PLC 实现上料逻辑并完成 PLC↔固件的串口/Modbus 协议。
- 第4周：集成 HMI 并完成演示视频。

反馈与扩展
- 我可以根据你使用的具体开发板（型号）把 `Makefile` 与外设初始化模板调整为可直接编译运行。

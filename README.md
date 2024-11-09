# TxCommander
TxCommander allows easy control over the Terminal Ready (DTR) and Request To Send (RTS) pins

## Usage
Rename the UARTcommander.exe to e.g. txcmd.exe and add it to PATH

Syntax `txcmd <port> <function>`

Example `txcmd COM4 1` set's DTR logic true.

> [!NOTE]
> This will result in latching to GND due to active low

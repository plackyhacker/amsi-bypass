# Anti-malware scanning interface (AMSI) Patching
Another AMSI bypass, this one is written in C.

![Demo Video](https://github.com/plackyhacker/amsi-bypass/blob/main/demo.gif "Demo")

**Compilation**

```
C:\> compile.bat
```

**Usage**

```powershell
PS C:\> tasklist | FINDSTR /i powershell
powershell.exe                8308 Console                    4     78,340 K

PS C:\> amsi_bypass.exe 8308
```

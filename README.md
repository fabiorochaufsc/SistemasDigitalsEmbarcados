

-------
<p align="center">
    <a href="#git">Uso do Git</a> &bull;
    <a href="#vídeos">Vídeos</a> &bull;
    <a href="#software">Software</a> &bull;
    <a href="#configurações">Configurações</a>&bull;
    <a href="#bibliografia">Bibliografia</a>&bull;
    <a href="#links">Links</a>
</p>





-------

## Git

### Instalar o git
> <span style="color:blue">sudo apt-get install git</span>
 

### Clonar o repositorio no seu computador

> mkdir Codigos-SDE <br/>
> cd Codigos-SDE<br/>
> git clone https://github.com/fabiorochaufsc/SistemasDigitalsEmbarcados<br/>
> cd SistemasDigitalsEmbarcados

### Baixar as novas atualizações do repositorio para o seu PC
>  git pull


---

![Software]

## Software
### Softwares utilizados na disciplina
  

---
![configuracao]
## Configurações

Para a programação será utilizado o adaptador USB-SERIAL. Quando ele dispositivo é conectado ele será reconhecido como um dispositivo USB e o seu driver carregado pelo Linux.

Para descobrir o nome do dispositivo, use **dmesg** para ver as últimas mensagens do sistema. Tipicamente o nome será
**/dev/ttyUSB0**

### Se você estiver utilizando uma máquina virtual

Verifique se a máquina HOST liberou o dispositivo para a máquina emulada. Além disso, no virtualbox existe a necessidade de instalação de um pacote (extension pack) para usar os dispositivos USB.

---
![Referencias]
## Bibliografia




|                                       Bibliografia Básica                                                                              |
|----------------------------------------------------------------------------------------------------------------------------------------|
|Jonathan W. Valvano, Introduction to Embedded Systems: Interfacing to the Freescale 9S12, CL Engineering, 2009                          |
|Jonathan W Valvano, Embedded Systems: Introduction to the Arm® Cortex(TM)-M3, CreateSpace, 2012, ISBN-10: 1477508996.                   |
|Patrick R. Schaumont, A Practical Introduction to Hardware/Software Codesign, Springer, 2010, ISBN-10: 1441959998.                      |


|                                               Bibliografia Complementar                                                                          |
|--------------------------------------------------------------------------------------------------------------------------------------------------|
|Christopher Hallinan, Embedded Linux Primer: A Practical Real-World Approach, Prentice Hall, 2010 ISBN-10: 0137017839                             |
|Daniel W. Lewis, Fundamentals of Embedded Software with the ARM Cortex-M3, Prentice Hall, 1a Edição, 2012, ISBN-10: 0132916541.                   |
|Ronald Sass, Andrew G. Schmidt, Embedded Systems Design with Platform FPGAs: Principles and Practices, Morgan Kaufmann, 2010, ISBN-10: 0123743338.| 
|Rahul Dubey, Introduction to Embedded System Design Using Field Programmable Gate Arrays, Springer, 2010, ISBN-10: 1849968152.                    |
|Mr Shibu K V, Introduction to Embedded Systems, TATA McGraw Hill, ISBN-10: 0070678790, 2009.                                                      |

---
![Links](https://github.com/fabiorochaufsc/fabiorochaufsc.github.io/blob/master/web/referencias.png)
## Links

[What Happened on Mars?](http://www.cs.cmu.edu/afs/cs/user/raj/www/mars.html) <br/>
[Aplicações interessantes de sistemas embarcados - Automação residencial](https://www.youtube.com/watch?v=-itZq0x9E94)<br/>
[Bootloader](https://tribotecnologica.wordpress.com/tag/bootloader/)

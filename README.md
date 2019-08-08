# Battery
### by Yiming Liu(<joelliu@hust.edu.cn>)
______

## Introduction
`battery` is a tiny programme as a practice. It is on the purpose to 
check out battery statues, especially battery percentage. So far I have 
only written the skeleton of this programme, and the up-to-date features 
are listed below.  

	* -p		battery percentage
	* -c 		charging status
	* -t		time to empty/full(not finished)
	* -h		show a help message

## Build & Dependencies
A Makefile file is to be added soon. So far, this programme can be compiled 
manually using `gcc` or other C Compilers. Meanwhile, `pkg-config` is recommended 
as it automatically search for libs needed. 
To compile, lib `glib` and `upower-glib` are required. 
At last, the command to compile this may look like: 
> CC -c `pkg-config --cflags glib-2.0 upower-glib` main.c battery.c  
> CC main.o battery.o -o battery -lglib-2.0 -lupower-glib

## Further Target
I plan to add more features into `battery`. Features may include: 
**time estimation**, **battery type**(which would tell you the brand and 
other details about your battery), etc.  
It needs to be pointed out that, as I have only tested this programme on 
my own machine, I cannot guarantee the stability of the programme. Bugs may 
occur and this programme may not fit in all kind of machines. 

## Conclusion
I will keep on developing this programme, and try my best to fix any potential 
errors and bugs. Bug reports would be welcomed. Advice of improvements would also 
be appreciated.

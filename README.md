# BatteryInfo
### by Yiming Liu(<798021909@qq.com>)
______

## Introduction
`battery` is a tiny programme as a practice. It is on the purpose to 
check out battery statues, especially battery percentage. So far I have 
only written the skeleton of this programme, and  features are listed below.  

	* -p		battery percentage
	* -c 		charging status
	* -t		time to empty/full(not finished)
	* -h		show a help message

## Build & Dependencies
A Makefile is present, to build the target file and install programme 
on your machine, run 
> make
> make install
**NOTICE** root permission is required to run `make install`. On the other 
hand, you can change INSTALL_DIR in Makefile into a user-specific directory
to avoid root permission.  

## BUGS 
This programme doesn't work on some machines due to unknown reasons. I tested 
it on my another DELL laptop but it didn't work properly. Though it is rather 
an old one. 

## Conclusion
I will keep on developing this programme, and try my best to fix any potential 
errors and bugs. Bug reports would be welcomed. Advice of improvements would also 
be appreciated.

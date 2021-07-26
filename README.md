# SysCallMusic
Pipe syscall interrups through aplay to get some weird sounds

## To Run:  

`make run`

## 1
> `./read_intr | grep intr | cut -d' ' -f2-37 | ./syshear | aplay -r 2000`

## 2
> `./read_intr | grep intr | cut -d' ' -f2-37 | ./syshear | aplay -r 2000`

> `./read_intr | grep intr | cut -d' ' -f2-37 | ./syshear | aplay -r 5050`

> `./read_intr | grep intr | cut -d' ' -f2-37 | ./syshear | ./drum 52000 | aplay -r 16 | ./drum 80000`
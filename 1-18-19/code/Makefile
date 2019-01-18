all: typedef macro bit_ops pointers sys_calls

typedef: typedef.c
	gcc -w -o typedef typedef.c

macro: macro.c
	gcc -w -o macro macro.c

bit_ops: bit_ops.c
	gcc -w -o bit_ops bit_ops.c

pointers: pointers.c pointers.h run_pointers.c
	gcc -w -o pointers pointers.c run_pointers.c

sys_calls: sys_calls.c
	gcc -w -o sys_calls sys_calls.c

clean:
	rm typedef macro bit_ops pointers sys_calls

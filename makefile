make:
	gcc shell.c -o shell -lreadline -lpthread
	gcc cat.c -o cat
	gcc ls.c -o ls
	gcc rm.c -o rm
	gcc date.c -o date

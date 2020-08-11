objects=obj/main.o obj/control.o obj/menuview.o obj/userlink.o\
obj/userlottery.o obj/issuelink.o obj/usercancel.o obj/award.o obj/game.o\
obj/user.o obj/admin.o obj/nottery.o

bin/a.out:$(objects)
	gcc -Iinclude $(objects) -o bin/a.out -Wall
obj/main.o:src/main.c
	gcc -Iinclude -c src/main.c -o obj/main.o -Wall
obj/control.o:src/control.c include/control.h
	gcc -Iinclude -c src/control.c -o obj/control.o -Wall
obj/menuview.o:src/menuview.c include/menuview.h
	gcc -Iinclude -c src/menuview.c -o obj/menuview.o -Wall
obj/userlink.o:src/userlink.c include/userlink.h
	gcc -Iinclude -c src/userlink.c -o obj/userlink.o -Wall
obj/userlottery.o:src/userlottery.c include/userlottery.h
	gcc -Iinclude -c src/userlottery.c -o obj/userlottery.o -Wall
obj/issuelink.o:src/issuelink.c include/issuelink.h
	gcc -Iinclude -c src/issuelink.c -o obj/issuelink.o -Wall
obj/usercancel.o:src/usercancel.c include/usercancel.h
	gcc -Iinclude -c src/usercancel.c -o obj/usercancel.o -Wall
obj/award.o:src/award.c include/award.h
	gcc -Iinclude -c src/award.c -o obj/award.o -Wall
obj/game.o:src/game.c include/game.h
	gcc -Iinclude -c src/game.c -o obj/game.o -Wall
obj/user.o:src/user.c include/user.h
	gcc -Iinclude -c src/user.c -o obj/user.o -Wall
obj/admin.o:src/admin.c include/admin.h
	gcc -Iinclude -c src/admin.c -o obj/admin.o -Wall
obj/nottery.o:src/nottery.c include/nottery.h
	gcc -Iinclude -c src/nottery.c -o obj/nottery.o -Wall
clean:
	rm -f $(objects) ./bin/a.out


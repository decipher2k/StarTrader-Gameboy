REM Automatically generated from Makefile
mkdir obj
..\..\..\bin\lcc   -c -o obj\main.o src\main.c
..\..\..\bin\lcc   -c -o obj\starmap_main.o src\starmap_main.c
..\..\..\bin\lcc   -c -o obj\StarmapTiles.o res\StarmapTiles.c
..\..\..\bin\lcc   -c -o obj\Starmap.o res\Starmap.c

..\..\..\bin\lcc   -o obj\Example.gb obj\main.o obj\starmap_main.o obj\Starmap.o obj\StarmapTiles.o
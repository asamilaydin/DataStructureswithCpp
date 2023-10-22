calistir: bagla
	.\bin\a.exe

bagla: derle
	g++ .\lib\Dugum.o .\lib\SatirlarListesi.o .\lib\YoneticiListesi.o .\lib\main.o -o .\bin\a.exe

derle:
	g++ -c .\src\YoneticiListesi.cpp -o .\lib\YoneticiListesi.o -I .\include
	g++ -c .\src\SatirlarListesi.cpp -o .\lib\SatirlarListesi.o -I .\include
	g++ -c .\src\Dugum.cpp -o .\lib\Dugum.o -I .\include
	g++ -c .\src\main.cpp -o .\lib\main.o -I .\include
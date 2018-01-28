extern int c;
extern unsigned char cursorLocation;

void cursorLocationMap(){
	switch(c){
		case 1 	: cursorLocation=0x80; break;
		case 2 	: cursorLocation=0x81; break;
		case 3 	: cursorLocation=0x82; break;
		case 4 	: cursorLocation=0x83; break;
		case 5 	: cursorLocation=0x84; break;
		case 6 	: cursorLocation=0x85; break;
		case 7 	: cursorLocation=0x86; break;
		case 8 	: cursorLocation=0x87; break;
		case 9 	: cursorLocation=0x88; break;
		case 10 : cursorLocation=0x89; break;
		case 11 : cursorLocation=0x8A; break;
		case 12 : cursorLocation=0x8B; break;
		case 13 : cursorLocation=0x8C; break;
		case 14 : cursorLocation=0x8D; break;
		case 15 : cursorLocation=0x8E; break;
		case 16 : cursorLocation=0x8F; break;
	}
}
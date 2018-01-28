//Mapping each keypad label to a custom character for displaying purposes
char keypadMap(char k){
	switch (k) {
		case 'A' : return '+';
		case 'B' : return '-';
		case 'C' : return 'c';
		case 'D' : return '/';
		case '#' : return '=';
		default :  return k;
	}
}

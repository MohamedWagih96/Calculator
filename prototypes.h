void keypad_init(void);
void PortF_Init(void);
void PortF_Output(uint32_t data);
unsigned char keypad_getkey(void);
char keypadMap(char k);
void reset();
void displayEquation(char d);
void appendDigit(char d);
void operation(char k);
void equal();
void del();
void cursorLocationMap();
void moveCursor(char direction);
uint32_t PortF_Input(void);
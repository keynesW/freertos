
void delay( int );
int ad=1;
int px = 1;
int main(void){
int i= 0;
	while (1){
	
		i=~i;
		ad=~ad;
		delay(5000);
	
	}
return 0;
}

void delay(int a){
		a--;
}


void SVCHandler(void){

	px = ~px;
	
}

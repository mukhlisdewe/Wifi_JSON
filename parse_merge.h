/*
* Parse Library written in C++ (Arduino)
* by Muhammad Shofuwan Anwar
*/

#define DATA_STR(x) data_flock[x]
#define WAIT_DATA_UNTIL(x) data = Serial.readStringUntil(x)
#define MAX 10

static String data = "";
static String data_flock[MAX];

static void clear_str(void){
    for(int x=0; x<MAX; x++)
        data_flock[x] = "";
}

static void parse_string(){
    int counter = 0;
    String temp = "";

    if(data[data.length()-2] != ';')
        data = data + ';';

    for(int x=0; x<data.length(); x++){
        if(data[x] == ';'){
            data_flock[counter] = temp;
            temp = "";
            counter++;
        }else
            temp = temp + data[x];
    }
}

static int get_data_total(){
    int total = 0;

    for(int x=0; x<MAX; x++){
        if(data_flock[x] != "")
            total++;
    }

    return total;
}

/*void ADC_Init(unsigned char mux){
    ADCSRA |= (1<<ADEN);
    ADMUX = (1<<mux);
    ADMUX |= (1<<REFS0) | (1<<REFS1);
    ADCSRA |= (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2);
}

int ADC_Read(unsigned char mux){
    ADC_Init(mux);

    ADCSRA |= (1<<ADSC);
    while((ADCSRA & (1<<ADSC)));
    return ADCW;
}*/

#include <msp430g2553.h>
#include "cc1101_config.h"


cc1101_pkt packet_to_send, packet_to_receive ;

void uart_rx(){
	return ;
}

void init_packets(){
	int i ;	
	packet_to_send.dst_addr = 0 ;
	packet_to_send.pkt_length = 10 ;
	for(i = 0 ; i < 10 ; i ++){
		packet_to_send.pkt_data[i] = 'a' + i ;
	}

	packet_to_receive.dst_addr = 0 ;
	packet_to_receive.pkt_length = 0 ;
}

int main(){
	uchar dummy, index;	
	WDTCTL = WDTPW + WDTHOLD ;
	BCSCTL1 = CALBC1_16MHZ ;
	DCOCTL = CALDCO_16MHZ ;
	setup_cc1101_spi();	
	setup_cc1101(cc1101_cfg, 22);
	init_packets();
	while(1){
		__delay_cycles(100000);	
		send_packet(&packet_to_send);
	}
}

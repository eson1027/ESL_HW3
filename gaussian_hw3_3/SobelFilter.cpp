#include <cmath>
#ifndef NATIVE_SYSTEMC
#include "stratus_hls.h"
#endif

#include "SobelFilter.h"

SobelFilter::SobelFilter( sc_module_name n ): sc_module( n )
{
#ifndef NATIVE_SYSTEMC
	HLS_FLATTEN_ARRAY(buffer_gray);
#endif
	SC_THREAD( do_filter );
	sensitive << i_clk.pos();
	dont_initialize();
	reset_signal_is(i_rst, false);

#ifndef NATIVE_SYSTEMC
	i_rgb.clk_rst(i_clk, i_rst);
	o_result.clk_rst(i_clk, i_rst);
#endif
	// for(int i=0;i<BUFFER_SIZE;i++){
	// 	buffer_gray[i]=0;
	// }
}

SobelFilter::~SobelFilter() {}


void SobelFilter::do_filter() {

	{
#ifndef NATIVE_SYSTEMC
		HLS_DEFINE_PROTOCOL("main_reset");
		i_rgb.reset();
		o_result.reset();
#endif
		wait();
	}
  for(int i=0;i<BUFFER_SIZE;i++){
    HLS_UNROLL_LOOP( ON, "" );
	 	buffer_gray[i]=0;
 }
//  buffer_gray[0]=0;
//  buffer_gray[1]=0;
//  buffer_gray[2]=0;
//  buffer_gray[3]=0;
//	buffer_gray[4]=0;
//	buffer_gray[5]=0;
//	buffer_gray[6]=0;
//	buffer_gray[7]=0;
//	buffer_gray[8]=0;
//	buffer_gray[9]=0;
//	buffer_gray[10]=0;
//	buffer_gray[11]=0;
//	buffer_gray[12]=0;
//	buffer_gray[13]=0;
//	buffer_gray[14]=0;
//	buffer_gray[15]=0;
//	buffer_gray[16]=0;
//	buffer_gray[17]=0;
//	buffer_gray[18]=0;
//	buffer_gray[19]=0;
//	buffer_gray[20]=0;
//	buffer_gray[21]=0;
//	buffer_gray[22]=0;
//	buffer_gray[23]=0;
//	buffer_gray[24]=0;
	while (true) {
		HLS_PIPELINE_LOOP(HARD_STALL,29,"");
    HLS_CONSTRAIN_LATENCY(0, HLS_ACHIEVABLE,"1");
		


		//for (sc_dt::sc_uint<3> v = 0; v<MASK_Y; ++v) {
		//for (sc_dt::sc_uint<3> u = 0; u<MASK_X; ++u) {
		//HLS_CONSTRAIN_LATENCY(0, 1, "lat01");
		//val[0] += buffer_gray[(5*v+u)] * mask[0][u][v];
   
     //HLS_PIPELINE_LOOP( HARD_STALL, 10, "MAIN_LOOP" );
sc_dt::sc_uint<17> val= buffer_gray[0 ] * 1 + buffer_gray[1 ] * 4  + buffer_gray[2 ] * 7  + buffer_gray[3 ] * 4  + buffer_gray[4 ] * 1 + 
                  			buffer_gray[5 ] * 4 + buffer_gray[6 ] * 16 + buffer_gray[7 ] * 26 + buffer_gray[8 ] * 16 + buffer_gray[9 ] * 4 +  
                  			buffer_gray[10] * 7 + buffer_gray[11] * 26 + buffer_gray[12] * 41 + buffer_gray[13] * 26 + buffer_gray[14] * 7 + 
                  			buffer_gray[15] * 4 + buffer_gray[16] * 16 + buffer_gray[17] * 26 + buffer_gray[18] * 16 + buffer_gray[19] * 4 +
                  			buffer_gray[20] * 1 + buffer_gray[21] * 4  + buffer_gray[22] * 7  + buffer_gray[23] * 4  + buffer_gray[24] * 1;
                      
		//cout << "val: " << val[0] <<"= ";
		//  printf("val: %d=",val[0]);
		// for(uint_fast16_t i=0;i<25;i++){
		//	printf("%d ",buffer_gray[i]);
		// cout << buffer_gray[i] << " ";
		//  }
		// cout << endl;
		//   printf("\n");  



		//val[0] = buffer_gray[0]         + (buffer_gray[1 ] << 2)  + (buffer_gray[2 ] << 2) + (buffer_gray[3 ] << 2) + buffer_gray[4] + 
		//         (buffer_gray[5 ] << 2) + (buffer_gray[6 ] << 4)  + (buffer_gray[7 ] << 4) + (buffer_gray[8 ] << 4) + (buffer_gray[9] << 2) +  
		//         (buffer_gray[10] << 2) + (buffer_gray[11] << 4)  + (buffer_gray[12] << 5) + (buffer_gray[13] << 4) + (buffer_gray[14] << 2) + 
		//         (buffer_gray[15] << 2) + (buffer_gray[16] << 4)  + (buffer_gray[17] << 4) + (buffer_gray[18] << 4) + (buffer_gray[19] << 2) +
		//         buffer_gray[20]        + (buffer_gray[21] << 2)  + (buffer_gray[22] << 2) + (buffer_gray[23] << 2) + buffer_gray[24] + 
		//         (buffer_gray[2] + buffer_gray[10] + buffer_gray[22] + buffer_gray[14] + buffer_gray[2]<< 1 + buffer_gray[10]<< 1 + buffer_gray[22]<< 1 + buffer_gray[14]<< 1) + 
		//         (buffer_gray[7] << 3 + buffer_gray[7] << 1 + buffer_gray[11] << 3 + buffer_gray[11] << 1 + buffer_gray[13] << 3 + buffer_gray[13] << 1 + buffer_gray[17] << 3 + buffer_gray[17] << 1) +
		//         (buffer_gray[12] << 3) + buffer_gray[12];         


		//sc_dt::sc_uint<17> total = 0;
		//total += val[0];

for(uint_fast16_t i=24 ; i >= 5 ; i--){
    HLS_UNROLL_LOOP( ON, "" );
    buffer_gray[i]=buffer_gray[i-5];
}

		/*buffer_gray[24]=buffer_gray[19];
		buffer_gray[23]=buffer_gray[18];
		buffer_gray[22]=buffer_gray[17];
		buffer_gray[21]=buffer_gray[16];
		buffer_gray[20]=buffer_gray[15];
		buffer_gray[19]=buffer_gray[14];
		buffer_gray[18]=buffer_gray[13];
		buffer_gray[17]=buffer_gray[12];
		buffer_gray[16]=buffer_gray[11];
		buffer_gray[15]=buffer_gray[10];
		buffer_gray[14]=buffer_gray[ 9];
		buffer_gray[13]=buffer_gray[ 8];
		buffer_gray[12]=buffer_gray[ 7];
		buffer_gray[11]=buffer_gray[ 6];
		buffer_gray[10]=buffer_gray[ 5];
		buffer_gray[ 9]=buffer_gray[ 4];
		buffer_gray[ 8]=buffer_gray[ 3];
		buffer_gray[ 7]=buffer_gray[ 2];
		buffer_gray[ 6]=buffer_gray[ 1];
		buffer_gray[ 5]=buffer_gray[ 0];*/
		for(uint_fast16_t i=0 ; i < 5 ; i++){
       //HLS_UNROLL_LOOP( ON, "" );
			sc_dt::sc_uint<8> R,G,B;
#ifndef NATIVE_SYSTEMC
			{
				HLS_DEFINE_PROTOCOL("input");
				R = i_rgb.get();
				wait();
				G = i_rgb.get();
				wait();
				B = i_rgb.get();
				wait();
			}
#else
			R = i_rgb.read();
			wait();
			G = i_rgb.read();
			wait();
			B = i_rgb.read();
			wait();
#endif
			//printf("%d %d %d\n",R,G,B);
			//cout  << R << " " << G << " " << B <<endl;
			buffer_gray[i] = (R + G + B)/3;
		}


#ifndef NATIVE_SYSTEMC
		{
			HLS_DEFINE_PROTOCOL("output");
			o_result.put(val);
			wait();
		}
#else
		o_result.write(total);
		wait();
#endif

	}
	}

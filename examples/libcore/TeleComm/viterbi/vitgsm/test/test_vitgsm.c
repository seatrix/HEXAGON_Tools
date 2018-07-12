/***************************************************************************
* Copyright (c) Date: Mon Nov 24 16:26:03 CST 2008 QUALCOMM INCORPORATED 
* All Rights Reserved 
* Modified by QUALCOMM INCORPORATED on Mon Nov 24 16:26:03 CST 2008 
****************************************************************************/ 


#include <stdio.h>
#include "hexagon_sim_timer.h"

#include "typedef.h"
#include "vitgsm.h"


UWord16 Expected_output[12] = {
  0x4f2e, 0xcda6, 0xc1a6, 0xf044, 0x4898, 0xc324,
  0x9106, 0x3274, 0x8c12, 0x6ec7, 0x3bb7, 0x99
};


Word8 input[2*N] =
	{ 6,1,-8,-8,-3,2,-7,7,-6,6,-6,-6,3,-2,-8,-4,
	  -1,6,5,-5,-2,5,3,-5,5,-7,-2,3,-4,-6,-6,5,
	  4,7,6,3,3,-7,2,-5,-8,-7,-6,-8,-8,3,-6,-6,
	  7,-4,-7,3,6,4,-4,4,-3,0,1,-7,-8,-8,5,-6,
	  7,-7,5,4,-5,2,-3,6,-2,-8,-7,-7,-7,5,-2,-3,
	  3,-5,-3,1,-6,-5,2,4,-3,-1,4,7,-2,-5,-3,3,
	  6,-6,-2,-8,-6,-8,-8,3,2,5,-7,-6,7,7,1,-3,
	  7,0,-2,-8,-7,-5,0,3,-6,-1,-7,7,-4,2,2,-6,
	  3,-2,4,7,6,1,0,5,-3,3,4,-3,-6,-5,-4,-6,
	  -3,7,7,3,-5,-4,3,1,2,-5,0,1,2,0,-5,5,
	  2,5,-7,-6,1,7,4,-8,4,6,0,6,-7,3,0,3,
	  2,7,1,-1,2,0,-6,-4,-6,6,-8,-4,-7,-2,-5,0,
	  5,-1,3,2,-7,0,-5,4,-6,-4,5,7,-1,-5,3,4,
	  -5,-7,2,-5,0,1,-8,-6,5,5,5,-7,1,2,7,7,
	  -8,1,6,7,0,6,-2,1,-8,-8,5,-6,1,-1,-6,6,
	  2,4,-2,-4,-1,1,1,5,6,5,3,-6,5,-7,-6,-5,
	  2,4,7,7,7,-5,3,4,3,1,-6,3,0,1,-8,-6,
	  -5,-3,5,1,-6,-7,-1,7,1,-3,-1,-8,0,2,3,3,
	  -1,5,-8,7,5,-3,6,-1,4,5,4,6,1,1,-3,3,
	  5,-1,3,2,-7,0,4,-7,-2,2,-4,-4,-7,6,-5,5,
	  0,6,-2,6,2,-1,-4,0,-6,-6,-1,4,-7,3,7,6,
	  -3,4,0,-3,-6,6,-8,-8,-6,7,7,-3,-2,7,4,5,
	  -2,-4,-4,7,6,1,0,5,5,-5,0,-4,-8,-6,-4,-6,
	  -6,5,7,4,-4,-1,-5,-7,6,3 };

int main()
{ 
   UWord16 output[12];
   int i;
   long long start_time;

   start_time = hexagon_sim_read_pcycles();

   vitgsm(input, output);

   printf("Cycles-Count: %d\n", (int)(hexagon_sim_read_pcycles()-start_time));

   for (i=0; i<12; i++) {
      if (output[i] != Expected_output[i]) {
          printf("## FAILED !!\n");
	  return 1;
      }
   }

   printf("*** PASS!\n");
   return 0;
}

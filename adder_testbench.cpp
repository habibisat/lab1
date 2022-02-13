// Verilator generated library/class.
#include "VOneBitAdder.h"

// Verilator libraries.
//#include "verilated.h"
#include "verilated_vcd_c.h" 

// C++ libraries.
#include <stdlib.h>
#include <iostream>

using dut_type = VOneBitAdder;
uint32_t global_time = 0;

void advance_sim(dut_type* top, VerilatedVcdC* trace)
{
	trace->dump(global_time);
	top->eval();
	++global_time; 
}


int main()
{
	srand(1234);  
	int expected_sum;
 	int expected_carry_out;
    	int sum;
 	int carry_out;
	bool sum_success;
	bool carry_out_success;
	int passed = 0;
	int failed = 0;
	int i = 0;

	dut_type* top = new dut_type;
    Verilated::traceEverOn(true);
    VerilatedVcdC* trace = new VerilatedVcdC;
    top->trace(trace, 99);
    trace->open("OneBitAdder.vcd");
	
	while(i<1000)
	{
	
		int x = rand()%2;
		int y = rand()%2;
		int carry_in = rand()%2;

		// Feed data to top.
		top->x = x & 1;
		top->y = y & 1;
		top->carry_in = carry_in & 1;

		// Model the behavior of the top.
		expected_sum = ((!x)&(!y)&(carry_in)) | ((!x)&(y)&(!carry_in)) | ((x)&(!y)&(!carry_in)) | ((x)&(y)&(carry_in));
		expected_carry_out = (x&carry_in) | (y&carry_in) | (x&y);
				
		// Simulate/evaluate/progress time.
		advance_sim(top, trace);	
		top->eval();
		
		// Compare results.
		sum = ((int)top->sum) & 1;
		carry_out = ((int)top->carry_out) & 1;

		sum_success = (sum == expected_sum);
		carry_out_success = (carry_out == expected_carry_out);

		if (sum_success && carry_out_success)
		{
		  //std::cout << "Test passed!" << std::endl;
		  passed++;
		}

		else
		{
		  //std::cout << "Test failed :(" << std::endl;
		  std::cout << i << std::endl;
		  failed++;
		}
		i++;
		
	}

	trace->close();

	std::cout << "\nPassed amount of tests:" << std::endl;
	std::cout << passed << std::endl;	
	std::cout << "\nFailed amount of tests:" << std::endl;
	std::cout << failed << std::endl;	

    // Value generator.

	return 0;
}

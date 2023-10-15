import "DPI-C" function int py_func(int x, int num_f);
module tb_top;
  initial begin
    int result;
    result = py_func(1 , 1); // "POW_TWO"
    $display("inside SV result POW_TWO(1) = %0d \n", result); // "POW_TWO"
    result = py_func(2 , 0 );
    $display("inside SV result ADD(2) = %0d \n", result); // "ADD"
    result = py_func(3 , 1 );
    $display("inside SV result POW_TWO(3) = %0d \n", result); // "POW_TWO"
    result = py_func(100, 0 );
    $display("inside SV result ADD(100) = %0d \n", result); // "ADD"
  end
endmodule